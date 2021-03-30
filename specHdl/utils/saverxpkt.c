/*
 * Software Development Kit for Fisilink
 * @file: saverxpkt.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <stdio.h>
#include <stdlib.h>     //getenv
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <log/sdklog.h>
#include <common/fileutil.h>
#include <common/const.h>


/*
** function: saveRxPacketFile
** Save receive packet to file for further process.
** Input args:
**      pkt:        receive packet.
**      casePath:   running case path, use to locate receive packet file.
**      suffix:    receive packet file suffix.
**  return value:
**      0:          complete.
**      1:          failed. Can't open a rx_pkt file to save packet.
*/
static int saveRxPacketFile(char *pkt, int len, char *casePath, char* suffix) {
    //gen rx file name (with rx folder name prefix 'rx_pkt/')
    int ret = 0;
    char *rxFileName = (char *)malloc(MAX_FULL_NAME * sizeof(char));
    assert(rxFileName != NULL);
    memset( rxFileName, 0, MAX_FULL_NAME );
    sprintf( rxFileName, "%srx_pkt/rx_%s", casePath, suffix );

    //save pkt to file
    FILE *rxfp = fopen(rxFileName, "w");
    if (rxfp == NULL) {
        servLogError("fopne in saveRxPacketFile, with %s\r\n", strerror(errno));
        ret = -1;
        goto save_error;
    }
    int i = 0;
    for ( i = 0; i < len; i++ ) {   
        fprintf(rxfp, "%02x", *(pkt + i) & 0xff);
    }
    fprintf(rxfp, "\n");
    fflush( rxfp );
    fclose(rxfp);
save_error:
    free(rxFileName);
    return ret;
}

/////////////////////////////////////////////////
// function: saveRxPacket
// Compare receive packet with expect packet and save receive packet
// Input args:
//      pkt:        receive packet.
//      deviceNum:  port number that received the packet.
//  return value:
//      0:          compare passed, same packets.
//      1:          compare failed, rx packet is different from exp packet.
//      2:          receive unexpected packet.
//      -1:         failed. 
/////////////////////////////////////////////////
int saveRxPacket(char *pkt, int pktLen, int deviceNum) {
    int ret = 0;
    int i = 0, j = 0;
    
    char *casePath = (char *)malloc(MAX_FULL_NAME);
    assert( casePath != NULL );
    memset( casePath, 0, MAX_FULL_NAME );
    if ( getCasePath( casePath ) < 0 ) {
        ret = -1;
        goto save_error;
    }

    //judge index
    char *rxPath = (char *)malloc(MAX_FULL_NAME);
    assert( rxPath != NULL);
    memset( rxPath, 0, MAX_FULL_NAME );
    sprintf( rxPath, "%srx_pkt", casePath );
    
    //Create rx folder
    createFolder(rxPath);

    char prefix[MAX_FILE_NAME] = {0};
    sprintf( prefix, "rx_vport%03d", deviceNum);
    int index = getDirFileNum( rxPath, prefix );
    if ( index < 0 ) {
        ret = -3;
        goto save_error;
    }
    //gen rx and exp file suffix
    char *suffix = (char *)malloc(MAX_FILE_NAME);
    assert( suffix != NULL );
    sprintf(suffix, "vport%03d_%03d", deviceNum, index);   //add zero before index

    //save rx_pkt file
    saveRxPacketFile(pkt, pktLen, casePath, suffix);

save_error:
    if ( suffix != NULL )           { free(suffix);           }
    if ( casePath != NULL )         { free(casePath);         }
    if ( rxPath != NULL )           { free(rxPath);           }
    return ret;
}


