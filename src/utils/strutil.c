/*
 * Software Development Kit for Fisilink
 * @file: strutil.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>         // for AF_INET
#include <arpa/inet.h>     // for inet_pton

/** key is format as "key=digital" */
int getAssignExpValue(char *str, char *key) {
    int      ret = -1;
    if (strstr( str, key ) != NULL) {
        ret = strtoul(str + strlen( key ) + 1, NULL, 0);
    }
    return ret;
}


int searchStrList(char *key, char *list[]) {
    int index  = -1;
    uint8_t i = 0;
    for( i = 0; *(list + i) != NULL; i++ ) {
        if (strncmp(key, *(list + i), strlen(key)) == 0) {
            index = i;
            break;
        }
    }
    return index;
}

/*
** strip all space of orgStr tail and header
*/
char *strip( char *orgStr ) {
    register char *s, *t;
    
    for( s = orgStr; isspace( *s ); s++ ) {
    }
    if( *s == 0 )
        return s;

    t = s + strlen( s ) - 1;
    while( t > s && isspace( *t ) ) {
        t--;
    }

    *++t = '\0';
    return s;
}

void dataSerialize( char *str, void *data, int len ) {
    char *ptr = (char *)data;
    int i = 0;
    for ( i = 0; i < len; i++ ) {
        sprintf( str + i * 3, "%02x ", *(ptr + i) & 0xff );
    }
}

void dataReserialize( uint8_t *data, int nByte, char *strv[] ) {
    int i = 0;
    for ( i = 0; i < nByte; i++ ) {
     //   sscanf( *(strv + i), "%02x", (int *)(data + i) );
        *(data + i) = strtoul( *(strv + i), NULL, 16 );
    }
}

/*
** the first \w character in reverse direction ignoring spaces at tail
** return pointer to non space character ignoring spaces at tail
*/
const char *strrchw( const char *src ) {
    register const char *t = src + strlen( src ) - 1;
    // bypss space at tail
    while(  t > src && isspace( *t ) ) {
        t--;
    }
    // get first space
    while( t > src && !isspace( *t ) ) {
        t--;
    }
    return t == src ? t : t++;
}
/*
** return the first positon of charater which is not c in reverse direction
*/
uint32_t strrnmth( char *src, char c ) {
    assert( src != NULL);
    uint32_t pos = strlen( src ) - 1;
    while( *(src + pos) == c ) {
        pos--;
    }
    return pos;
}

/*
** return the first position of charater which is not c
*/
uint32_t strnmth( char *src, char c ) {
    uint32_t pos = 0;
    while( *(src + pos) != '\0' && *(src + pos) == c ) {
        pos++;
    }
    return pos;
}

int split( char *src, const char *delim, char *dest[] ) {
    char *pNext;
    int count = -3;
    if( src == NULL || strlen(src) == 0 ) {
        return -1;
    }
    if( delim == NULL || strlen( delim ) == 0 ) {
        return -2;
    }
   
    char *saveptr;
    pNext = strtok_r( src, delim, &saveptr );
    count = 0;
    while( pNext != NULL ) {
        *dest++ = pNext;
        count++;
        pNext = strtok_r( NULL, delim, &saveptr );
    }
    return count;
}

/** in is formatted as "0,0,0,0,0,0|1,1,1,1,1|2,2,2,2,2 */
uint32_t string2jason( char *out, char *in, char *colNames[] ) {
    assert( out != NULL );
    assert( in  != NULL );
    assert( colNames != NULL );
    // beging 
    // split line
    sprintf( out, "[ " );
    char *sets[64];
    int   setNum = split( in, "|", sets );
    uint32_t i, j;
    char *fields[64];
    int fldNum, len;
    char buffer[128];
    for (i = 0; i < setNum; i++) {
        // split fields
        strcat( out, "{ " );
        fldNum = split( *(sets + i), ", ", fields );
        for (j = 0; j < fldNum; j++) {
            sprintf( buffer, "\"%s\" : \"%s\", ", *(colNames + j), *(fields + j) );
            strcat( out, buffer );
        }
        // replace last comma
        len = strlen( out );
        *(out + len - 2) = ' ';
        strcat( out, "}, " );
    }
    // replace last comma
    len = strlen( out );
    *(out + len - 2) = ' ';

    // ending
    strcat( out, "]" );
    return strlen( out );
}

/*
** func:replace newStr to oldStr in orgStr 
*/
char *strrpc(char *str, char *oldstr, char *newstr) {
    char tmpStr [1024] = {0};
    unsigned int i = 0;
    for(i = 0; i < strlen(str); i++) {
        if(!strncmp(str + i, oldstr, strlen(oldstr))) {
            strcat(tmpStr,newstr);
            i += strlen(oldstr) - 1;
        }else {
            strncat(tmpStr, str + i, 1);
        }
    } 
    strcpy(str, tmpStr);
    return str;
}

int macStr2Hex( uint8_t *hex, char *mac ) {
    int ret         = 0;
    char *tmpPtr[6] = {0};
    char *tmpBuf = strdup( mac );
    assert( tmpBuf != NULL );
    int num         = split( tmpBuf, ":", tmpPtr );
    if (num != 6) {
        ret = -1;
    } else {
        uint8_t i = 0;
        for (i = 0; i < 6; i++) {
            *(hex + i) = strtoul( tmpPtr[i], NULL, 16 );
            if (errno == ERANGE) {
                ret = -2;
                break;
            }
        }
    }
    free( tmpBuf );
    return ret;
}

int ipStr2Numeric( uint8_t *hex, char *ipStr ) {
    int  isIpv4     = 1;
    uint32_t domain = AF_INET;
    if (strchr( ipStr, ':' ) != NULL) {
        domain      = AF_INET6;
        isIpv4      = 0;
    }
    int ipTrans = inet_pton( domain, ipStr, hex );
    if (ipTrans <= 0) {
        isIpv4 = -1;
    }
    return isIpv4;
}

#include <regex.h>
uint32_t regexChk( const char *expression, const char *pattern ) {
    regex_t regex;
    regmatch_t match[16];
    char err[128];
    int ret  = 0 ;

    ret = regcomp( &regex, pattern, REG_EXTENDED | REG_ICASE | REG_NOSUB );
    if ( ret ) {
        regerror( ret, &regex, err, sizeof( err ) );
        printf( "Error: %s pattern %s\r\n", err, pattern );
    } else { 
        ret = regexec( &regex, expression, 16, match, 0 );
        if ( ret ) {
            regerror( ret, &regex, err, sizeof( err ) );
            printf( "Error: %s, using %s match %s\r\n", err, pattern, expression );
        }
    }
    regfree( &regex );
    return ret;
}

uint32_t addOneCompletion(char *list[], char *curStr, char *key) {
    uint32_t count = 0;
    if (key == NULL) {
        *list = strdup( curStr );
        count++;
    } else if (strncmp( curStr, key, strlen( key ) ) == 0 ) {
        *list = strdup( curStr + strlen(key) );
        count++;
    }
    return count;
}


