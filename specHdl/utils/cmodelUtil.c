/*
 * Software Development Kit for Fisilink
 * @file: cmodelUtil.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <stdint.h>
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ppinfo.h>

#define RESERVE_LEN 100

void printArr(uint8_t *arr, uint16_t len) {
    for (int j = 0, cnt = 0; j < len; j++) {
        printf("%02x ", arr[j]);
        cnt++;
        if (cnt % 10 == 0) printf("\n");
    }
    printf("\n-------------------\n");
}

int compareArr(uint8_t *buf, int num, void *key) {
    uint8_t *val = (uint8_t *)malloc(num);
    uint8_t size = 0;
    uint8_t ret = 0;
    memcpy(val, key, num);
    int i = 0;
    for (i = 0; i < num; i++) {
        if (val[i] != buf[num-i-1]) 
            break;
        size = i;
    }
    if (size == num-1) 
        ret = 1;
    free(val);
    return ret;
}

void headerEdit(uint8_t *pkt, uint8_t *head, uint8_t *context, uint8_t num, uint16_t pktlen) {
    // arr context is big ending, arr head is little ending;
    uint8_t i;
    uint8_t start = 0;
    uint8_t offset = RESERVE_LEN;
    for (i = 0; i < num; i++) {
        uint8_t length = *(context + i) & 0x1f;
        uint8_t valid = *(context + i) & 0x80;
        if (*(context + i) & 0x80) {
            memcpy(pkt + (offset - length), head + start, length); 
            //printf("%x--%x start:%x  %02x %02x %02x %02x\n", i, length, start, head[start], head[start+1], head[start+2], head[start+3]);
            offset -= length;
        }
        start += length;
    }
    uint8_t *tmpPkt = (uint8_t *)malloc(pktlen + RESERVE_LEN - offset);
    memcpy(tmpPkt, pkt+offset, pktlen + RESERVE_LEN - offset);
    memset(pkt, 0, pktlen + RESERVE_LEN - offset);
    memcpy(pkt, tmpPkt, pktlen + RESERVE_LEN - offset);
    //for (i = 0; i < pktlen; i++) {
    //    *(pkt+i) = *(pkt+i+offset);
    //}
    free(tmpPkt);
}

uint8_t Hash1(uint8_t *key) {
    return 0;
}

void reversalArr(uint8_t *value, uint32_t length) {
    uint8_t *reversalValue = (uint8_t *)malloc(length);
    int i = 0;
    for (i = 0; i < length; i++) {
        *(reversalValue+length-i-1) = *(value+i); 
    }
    memcpy(value, reversalValue, length);
    free(reversalValue);
}

void assignArr(uint8_t *tmpArr, uint8_t *key, const uint32_t keySize) {
    int i, j;
    uint8_t length = 11 * (1 << keySize);
    uint8_t *reversalValue = (uint8_t *)malloc(length*sizeof(uint8_t));
    for (i = 0; i < length; i++) {
        *(reversalValue+length-i-1) = *(key+i); 
    }
    memcpy(key, reversalValue, length);
    free(reversalValue);

    for (i = 0; i < (1 << keySize); i++) {
        for (j = 0; j < 11; j++) {
            *(tmpArr+12*i+j) = *(key+11*i+j); 
        }
    }
}

int genHostRouteKey(uint8_t *key, uint32_t *ip, uint8_t isV6) {
    *(key + 0)   = isV6;
    *(key + 1)   = *(ip + 0) >> 24;
    *(key + 2)   = *(ip + 0) >> 16;
    *(key + 3)   = *(ip + 0) >> 8;
    *(key + 4)   = *(ip + 0);
    *(key + 5)   = *(ip + 1) >> 24;
    *(key + 6)   = *(ip + 1) >> 16;
    *(key + 7)   = *(ip + 1) >> 8;
    *(key + 8)   = *(ip + 1);
    *(key + 9)   = *(ip + 2) >> 24;
    *(key + 10)   = *(ip + 2) >> 16;
    *(key + 11)   = *(ip + 2) >> 8;
    *(key + 12)   = *(ip + 2);
    *(key + 13)   = *(ip + 3) >> 24;
    *(key + 14)   = *(ip + 3) >> 16;
    *(key + 15)   = *(ip + 3) >> 8;
    *(key + 16)   = *(ip + 3);
    return 0;
}

uint8_t uint8AryCmp( uint8_t *a, uint8_t *b, uint32_t len ) {
    int8_t ret    = 0;
    int      i    = 0;
    for ( i = 0; i < len; i++ ) {
        ret = *(a + i) - *(b + i);
        if ( ret != 0 ) {
            break;
        }
    }
    return ret;
}

int macPiMemCmp( uint8_t *macAry, uint16_t macHi, uint32_t macLo ) {
    uint8_t tmp[6] = {0};
    *(tmp + 0)     = macHi >> 8;
    *(tmp + 1)     = macHi;
    *(tmp + 2)     = (macLo >> 24) & 0xff;
    *(tmp + 3)     = (macLo >> 16) & 0xff;
    *(tmp + 4)     = (macLo >> 8) & 0xff;
    *(tmp + 5)     = (macLo) & 0xff;
    return uint8AryCmp( macAry, tmp, 6 );
}

int uint32AryCmp( uint32_t *a, uint32_t *b, uint32_t len ) {
    int ret    =  0;
    int i      =  0;
    for ( i = 0; i < len; i++ ) {
        ret = *(a + i) - *(b + i);
        if ( ret != 0 ) {
            break;
        }
    }
    return ret;
}

uint32_t funcRandom( uint32_t min, uint32_t max ) {
    srand( (unsigned)time( NULL ) );
    return (rand() & max) + min;
}
uint16_t sequenceGen( uint16_t seed ) {
    uint16_t ret = ((seed >>  10) & 0x1) ^ ((seed >>  12) & 0x1) ^ ((seed >>  13) & 0x1) ^ ((seed >>  15) & 0x1) ;
    return ((seed & 0x7fff) << 1) + (ret & 0x1);
}


void DelayCycle (uint32_t value) {
    usleep((value << 3) / 1000);
}

static uint8_t ascii2Hex( uint8_t ascii ) {
    uint8_t ret = 0;
    if ( ascii >= 'a' && ascii <= 'z' ) {
        ret = ascii - 'a' + 10 ;
    } else if ( ascii >= 'A' && ascii <= 'Z' ) {
        ret = ascii - 'A' + 10 ;
    } else if ( ascii >= '0' && ascii <= '9' ) { 
        ret = ascii - '0';
    }
    return ret;
}

uint32_t transText2Hex( unsigned char *dest, char *src ) {
    assert( src != NULL );
    uint32_t len    = 0;
    uint32_t orgLen = strlen( src );    
    int i = 0;
    uint8_t hi, lo;
    for( i = 0, len = 0; i < orgLen; i += 2, len++ ) {
        hi = ascii2Hex( (uint8_t)*(src + i) );
        lo = ascii2Hex( (uint8_t)*(src + i + 1) );
    
        *(dest + len)  = (hi << 4) + lo;     
    }
    return len;
}

uint8_t getWdwValue( void *data, const uint32_t idx, const uint8_t wdw ) {
    assert( wdw <= 8);
    uint8_t *ptr     = ( uint8_t *)data;
    uint8_t loIdx    = (idx * wdw) / 8;
    uint8_t loOffset = (idx * wdw) % 8;
    uint8_t hiIdx    = ((idx + 1) * wdw) / 8;
    uint8_t hiOffset = ((idx + 1) * wdw) % 8;
    uint8_t ret      = 0;
    if( loIdx == hiIdx ) {                      // In the same octet
        ret          = *(ptr + loIdx) ;
    } else {                                      // In different octets
        uint8_t lsb  = *(ptr + loIdx) >> loOffset;
        uint8_t msb  = *(ptr + hiIdx) & ((1 << hiOffset) - 1);
        ret          = (msb << (8 - loOffset)) + lsb; 
    }
    return ret & ((1 << wdw) - 1);
}

