/*
 * Software Development Kit for Fisilink
 * @file: fileutil.h
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __FILE_UTIL_H
#define __FILE_UTIL_H

/************************************************
** function: getSdkFileAbsPath
**      Get <fileName> absolute path stored in  <path>
**      return 0 successfully else positive number
************************************************/
unsigned int getSdkFileAbsPath( unsigned char *path, unsigned char *fileName ) ;

/************************************************
** function: getCasePath
**      Get current case path stored in casePath according fileRelativePath
**      return 0 successfully else negative
************************************************/
int getCasePath( char *casePath );

/************************************************
** function: createFolder
**      Create a rx_pkt folder in the dirPath.
**      return  0 always
************************************************/
int createFolder( char *dirPath ) ;


/************************************************
** function: readConfigFile
**      read $name file which is separated by $dilimiter each line with $columns fields.
**      read each line to $data using $func
**      return  0 if successful else -1
************************************************/
int readConfigFile( char *name, char *delimiter, uint8_t columns, void *data, void (*func) ( void *data, char *argv[] ) ) ;

/************************************************
** function: writeFile
**      write $content to $fileName as $mode, $fileName is a absoluted path
**      return 1 if successfully else 0
************************************************/
int writeFile( char *fileName, const char *mode, char *content ) ;

/** Generate empty file of fileName, with format description as fromatAs */
int emptyFile( char *fileName, char *formatAs ) ;

/************************************************
** function: writeSdkFile
**      write $content to $fileName as $mode, $fileName is a relative path to SDK
**      return 1 if successfully else 0
************************************************/
int writeSdkFile( char *fileName, const char *mode, char *content ) ;

/************************************************
** function: getDirFileNum
**      Get the number of file prefixed by prefix under path
**      return 0 or positive if get the number of prefix named file successfully else negative
************************************************/
int getDirFileNum( char *path, char *prefix ) ;

/************************************************
** function: isDir
**      it is used to judge the filename is a directory or not
**      return 1 if the filename is a directory name else 0
************************************************/
int isDir( const char *filename) ;

/** Get file name under directory indicated by src for completion */
uint32_t getDirFileCompletions(char *list[], char *src) ;
#endif
