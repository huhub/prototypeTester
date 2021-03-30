/*
 * Software Development Kit for Fisilink
 * @file: util.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>

uint32_t genMacKey(uint8_t *key, uint32_t *mac, uint16_t vlan) {
    *(key + 0)  = vlan >> 8;
    *(key + 1)  = vlan;
    *(key + 2)  = *(mac + 0) & 0xff;
    *(key + 3)  = *(mac + 1) & 0xff;
    *(key + 4)  = *(mac + 2) & 0xff;
    *(key + 5)  = *(mac + 3) & 0xff;
    *(key + 6)  = *(mac + 4) & 0xff;
    *(key + 7)  = *(mac + 5) & 0xff;
    return 0;
}

#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
uint32_t getWinSize() {
    struct winsize ws;
    if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
        return 120;
    } else { 
        return ws.ws_col;
    }
}

void printPacket( uint8_t *pkt, uint32_t len ) {
    int i = 0;
    for ( i = 0; i < len; i++ ) {
        if ( i > 0 && i % 16 == 0 ) printf( "\r\n" );
        printf( "%02x ", *(pkt + i) & 0xff );
    }
    printf( "\r\n" );
}

long int createDaemonThread( void *(*func)(void *), void *arg ) {
    pthread_attr_t attr;
    pthread_t      tid = 0;
    // bring up thread
    long int ret       = 0;
    if (pthread_attr_init(&attr) != 0) {
        perror( "PTHREAD_CREATE: pthread_attr_init" );
        ret     = -1;
    } else {
        if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) != 0) {
            perror( "PTHREAD_CREATE: : pthread_attr_setdetachstate" );
            ret = -2;
        }
    }
    if (ret == 0) {
        if (pthread_create(&tid, &attr, func, arg) != 0) {
            perror( "PTHREAD_CREATE: : pthread_create" );
            ret  = -3;
        }
    }
    return ret == 0 ? tid : ret;
}

int32_t asciiStr2Hex( uint8_t *hexStr, uint8_t *ascii ) {
    uint32_t inLen = 0;
    int32_t  ret = 0;

    inLen = strlen(ascii);
    uint8_t *strPkt = ascii;
    if ((inLen & 0x1) != 0) {       // Odd nibble
        ret = -1;
    } else {
        uint32_t length = 0;
        uint32_t x = 0;
        uint8_t  convert[3];
        /* dynamically allocate the return buffer */
        while ( *strPkt ) {
            /* -- check for hex digit */
            if (! isxdigit(*strPkt)) {
                ret = -2;
                break;
            } else {
                /* -- convert in pairs */
                if ( x % 2 ) {
                    convert[1] = *strPkt;
                    convert[2] = 0;
                    *(hexStr + length) = (unsigned char)strtol( convert, 0, 16 );
                    length++;
                } else {
                    convert[0] = *strPkt;
                }  
                /* -- next byte */
                x++;
                strPkt++; 
            }
        }
        if ((x & 0x1) != 0) {
            ret = -3;
        } else {
            ret = length;
        }
    }
    return ret;
}
