/*
 * Software Development Kit for Fisilink
 * @file: util.h
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __UTIL_H
#define __UTIL_H

#include <stdint.h>
#include <linux/rbtree.h>

#if defined(container_of)
  #undef container_of
  #define container_of(ptr, type, member) ({            \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})
#else
  #define container_of(ptr, type, member) ({            \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})
#endif

#if defined(offsetof)
  #undef offsetof
  #define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#else 
  #define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

#undef NULL
#if defined(__cplusplus)
  #define NULL 0
#else
  #define NULL ((void *)0)
#endif

/** Calculate round up power 2 value of data */
static inline  unsigned int roundupPow2( unsigned int data ) {
    unsigned int tmp = data;
    tmp--;
    tmp |= tmp >> 1;
    tmp |= tmp >> 2;
    tmp |= tmp >> 4;
    tmp |= tmp >> 8;
    tmp |= tmp >> 16;
    tmp++;
    return tmp;
}

/** Format print len of pkt */
void printPacket( uint8_t *pkt, uint32_t len ) ;

/** get screen width */
uint32_t getWinSize() ;

/** Generate Mac key using mac and vlan for FDB hash function */
uint32_t genMacKey(uint8_t *key, uint32_t *mac, uint16_t vlan);

/** Create Daemon thread which will be release automatically after father thread exit */
long int createDaemonThread( void *(*func)(void *), void *arg ) ;

/** Transfor ASCII to Hex string */
int32_t asciiStr2Hex( uint8_t *hexStr, uint8_t *ascii ) ;

#endif
