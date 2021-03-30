/*
 * Software Development Kit for Fisilink
 * @file: fileutil.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <stdio.h>      // fopen
#include <stdlib.h>     // getenv, malloc
#include <unistd.h>     // access
#include <assert.h>
#include <dirent.h>     //opendir readdir
#include <string.h>
#include <errno.h>      // strerror
#include <sys/stat.h>   //createFolder
#include <common/const.h>
#include <common/strutil.h>

unsigned int getSdkFileAbsPath( unsigned char *path, unsigned char *fileName ) {
    unsigned int ret = 0;
    char *pishonPath = getenv("PISHON_PATH");
    if (pishonPath == NULL) {
        assert(getcwd(path, MAX_FULL_NAME) != NULL);
    } else {
        strcpy(path, pishonPath);
    }
    strcat(path, "/");
    strcat(path, fileName);
    return ret;
}

int getCasePath( char *casePath ) {
    int ret         = 0;
    //locate case path log file
    char *caseCfgFilePath = (char *)malloc( MAX_FULL_NAME );
    assert( caseCfgFilePath != NULL );
    getSdkFileAbsPath(caseCfgFilePath, CASEPATHFILE);
    // open file
    FILE *fp = fopen( caseCfgFilePath, "r" );
    if ( fp == NULL ) {
        printf( "Error: fopen %s in getCasePath with %s\r\n", caseCfgFilePath, strerror( errno ) );
        ret    = -2;
    } else {
        fscanf( fp, "%s", casePath );
        fclose( fp );
    }
    free( caseCfgFilePath );
    return ret;
}

int readConfigFile( char *name, char *delimiter, uint8_t columns, void *data, 
                    void (*func) ( void *data, char *argv[] ) ) {
    int ret = 0;
    char path[MAX_FULL_NAME];
    getSdkFileAbsPath( path, name );

    FILE *fp = fopen(path, "a+");
    if (fp != NULL) {
        uint8_t buffer[ MAX_SINGLE_LINE ];
        char spliter[8];
        sprintf( spliter, "%s\r\n", delimiter );
        char    *splitPtr[32];
        int      splitNum = 0;
        uint16_t lineNum = 0;
        // read line by line
        while (fgets( buffer, MAX_SINGLE_LINE, fp ) != NULL) {
            lineNum++;
            if (*buffer == '#' || *buffer == '/' || *buffer == '\n') {
                continue;
            } 
            // parser
            splitNum = split( buffer, spliter, splitPtr );
            if (splitNum != columns) {
                printf( "Read illegal content at line %d of %s, except %d column but %d.\r\n", lineNum, name, columns, splitNum );
            } else {
                func( data, splitPtr );
            }
        }
        fclose( fp );
    } else {
        printf( "Error: fopen %s in readConfigFile with %s.\r\n", name, strerror( errno ) );
        ret = -1;
    }

    return ret;
}

int emptyFile( char *fileName, char *formatAs) {
    char path[MAX_FULL_NAME];
    getSdkFileAbsPath( path, fileName );
    int ret = 0;

    FILE *fp   = fopen( path, "w+" );
    if (fp != NULL) {
        if (formatAs != NULL) {
            ret = fwrite( formatAs, strlen(formatAs), 1, fp );
        }
        fclose( fp );
    } else {
        printf( "Error: fopen %s in emptyFile with %s\r\n", fileName, strerror( errno ) );
        ret = -1;
    }
    return ret;
}
    
int writeFile( char *fileName, const char *mode, char *content ) {
    int ret    = 0;
    FILE *fp   = fopen( fileName, mode );
    if ( fp != NULL ) {
        ret    = fwrite( content, strlen(content), 1, fp );
        if ( ret != 1 ) {
            printf( "Error: write %s to %s.\r\n", content, fileName );
        }
        fclose( fp );
    } else {
        printf( "Error: fopen %s in writeFile with %s\r\n", fileName, strerror( errno ) );
        ret = -1;
    }
    return ret;
}

int writeSdkFile( char *fileName, const char *mode, char *content ) {
    char path[MAX_FULL_NAME];
    getSdkFileAbsPath( path, fileName );
    return writeFile( path, mode, content );
}
    

int createFolder( char *dirPath ) {
    if (access(dirPath, F_OK) != 0) {                            //if there is no rx_pkt folder
        mkdir(dirPath, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);   //make a new rx_pkt folder
    }
    return 0;
}

int getDirFileNum( char *path, char *prefix ) {
    int ret = 0;
    struct dirent *pDirEntry = (struct dirent *)malloc( sizeof(struct dirent) );
    assert( pDirEntry != NULL );
    struct dirent *pDirRslt  = (struct dirent *)malloc( sizeof(struct dirent) );
    assert( pDirRslt != NULL );
    DIR *dir = opendir( path );
    if ( dir  == NULL ) {
        printf( "Error: fopen %s in getDirFileNum with %s\r\n", path, strerror( errno ) );
        ret = -1;
    } else {
        int index = 0;
        while ( 1 ) {
            if (readdir_r(dir, pDirEntry, &pDirRslt ) != 0 ) {
                printf( "Error: fopen %s in getDirFileNum.readdir_r with %s\r\n", 
                        path, strerror( errno ) );
                ret = -4;
                break;
            } 
            if ( pDirRslt == NULL ) {
                break;
            } else if ( pDirRslt->d_name[0] == '.' ) {
                continue;
            } else if (strncmp(prefix, pDirRslt->d_name, strlen(prefix)) == 0) {
                index++;
            }
        }
        ret = index;
    }

    if ( dir != NULL )              { 
        closedir( dir ); 
    }
    if ( pDirEntry != NULL )        { 
        free(pDirEntry); 
    }
    if ( pDirRslt != NULL )         { 
        free(pDirRslt);  
    }
    
    return ret;    
}

int isDir( const char *filename) {
  struct stat finfo;
  return (stat(filename, &finfo) == 0 && S_ISDIR( finfo.st_mode) );
}

uint32_t getDirFileCompletions(char *list[], char *src) {
    // get path
    char *chrKey = src;
    char path[MAX_FULL_NAME] = {0};
    if (src == NULL) {
        path[0] = '.';
    } else {
        // find charecter '/'
        uint8_t keyLen  = strlen(src);
        char *delimiter = strrchr(src, '/');
        if (delimiter != NULL) {             // work/Pish[TAB] to complete work/Pishon/
            strncpy(path, src, delimiter - src);
            if (delimiter - src + 1 == keyLen) {  // work/Pishon/[TAB} to complete all file name under work/Pishon
                chrKey = NULL;
            } else {                        // work/Pish[TAB] to complete all file under work with prefix Pish
                chrKey = delimiter + 1;
            }
        } else {                             // wor[TAB] to complete work/
            path[0] = '.';
        }
    }
    uint32_t len = 0;
    // get all file name under path
    DIR *dirPtr = opendir(path);
    if (dirPtr != NULL) {
        struct dirent *dp = NULL;
        while( (dp = readdir( dirPtr ))!= NULL ) {
            if( dp->d_name[0] == '.' ) {     // file . .. are excluded.
                continue;
            }
            len += addOneCompletion(list + len, dp->d_name, chrKey);
        }
        closedir(dirPtr);
    }
    return len;
}
