/*
 * Software Development Kit for Fisilink
 * @file: strutil.h
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __STR_UTIL_H
#define __STR_UTIL_H

#include <stdint.h>
/**
 function: getAssignExpValue
      get assignment expression value, eg. vlanId=1 which key is vlanId and returen 1 
 return:   corresponding value else -1
*/
int getAssignExpValue(char *str, char *key) ;

/**
 function: inStrList
      Judge the <key> whether in <list>
 return:   -1 if key is not find in list else the position of list
*/
int searchStrList(char *key, char *list[]) ;

/**
 function: split
      split src using separator and store the result in char pointer array dest

*/
int split( char *src, const char *separator, char *dest[] ) ;

/**
 function: macStr2Hex
      Transform colon-separated MAC addres to Hex array
  return : 0 correctly otherwise -1
*/
int macStr2Hex( uint8_t *hex, char *mac ) ;

/**
 function: ipAddrStr2Hex 
      Transform IPv4/6 address to Hex array
  return : 1 indicates is IPv4 address, 0 indicates IPv6 address, -1 indicates ipStr illegal
*/
int ipStr2Numeric( uint8_t *hex, char *ipStr ) ;

/**
 function: regexChk
      Chech the expression using pattern

*/
uint32_t regexChk( const char *expression, const char *pattern ) ;

/**
 function: dataReserialize
      Reserialize the strv charactor array nByte to data 

*/
void dataReserialize( uint8_t *data, int nByte, char *strv[] ) ;


/**
 function: dataSerialize
      Serialize the data with len bytes to charactor saving in str
*/
void dataSerialize( char *str, void *data, int len ) ;

/**
 the first \w character in reverse direction ignoring spaces at tail
 return pointer to non space character ignoring spaces at tail
*/
const char *strrchw( const char *src ) ;

/** return the first positon of charater which is not c in reverse direction */
uint32_t strrnmth( char *src, char c ) ;

/** return the first position of charater which is not c */
uint32_t strnmth( char *src, char c ) ;

/** strip all space of orgStr tail and header */
char *strip( char *orgStr ) ;

/** transfor | separated string to jason format */
uint32_t string2jason( char *out, char *in, char *colNames[] ) ;

/** replace newStr to oldStr in orgStr */
char *strrpc(char *str,char *oldstr,char *newstr);

/** add one completion for cli completion function */
uint32_t addOneCompletion(char *list[], char *curStr, char *key) ;

#endif
