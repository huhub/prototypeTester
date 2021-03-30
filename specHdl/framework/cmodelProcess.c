/*
 * Software Development Kit for Fisilink
 * @file: cmodelProcess.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <linux/tipc.h>
#include <linux/tipc_config.h>
#include <linux/tipc.h>
#include <pthread.h>

#include <rpc/rpcconst.h>
#include <common/util.h>
#include <common/const.h>
#include <common/strutil.h>

#include <ingress.h>
#include <cmodelUtil.h>
#include <cTrafficManage.h>

static unsigned int sInPktSequence = 0;
uint8_t glPkt[MAX_PKT_LEN] = {0};
static uint16_t sHashSeqSeed = 0xffff;
void resetHashSeqence() {
    sHashSeqSeed             = 0xffff;
}

static uint16_t sFlowSeqSeed  = 0xffff;
void resetAclLogSeq() {
    sFlowSeqSeed              = 0xffff;
}

static uint8_t debug = 0;

void setDebug() {
    debug = 1;
}

void unSetDebug() {
    debug = 0;
}

uint8_t useDebug() {
    return debug;
}

static int cmodelProcess(unsigned char *pkt, char *device, unsigned long long timestamp) {
    if (strncmp( device, "resetSequence", 13 ) == 0 ) {
        sInPktSequence  = 0;
        resetHashSeqence();
        resetAclLogSeq();
    } else {
        int srcPort     = 0;
        int userId      = 0;
        int ret = sscanf( device, "vport%d-%d", &userId, &srcPort );
        if (ret == 2) {
            tMsgWrInfo  msWrInfo = {0};
            unsigned int len    = transText2Hex(glPkt, pkt);
            msWrInfo.pktLength    = len + 4;  // +4: length include crc
            msWrInfo.channelId  = srcPort;
            printf("++++++++++++++ srcPort: %x, pktLength: %x\n", srcPort, msWrInfo.pktLength);
        #if CFG_DUMP == 1
            saveCosimPkt( glPkt, len, IN_PKT, srcPort );
        #endif
            
            tMsgIgr2Adm  msIgr2Adm = {0};
            uint8_t pktHdr[256];
            memcpy(pktHdr, glPkt, 256);
            ingressProc(pktHdr, &msWrInfo, &msIgr2Adm, timestamp, sInPktSequence );
            AdmissionControl( &msIgr2Adm, timestamp, 0, 100);
            sInPktSequence++;
        } else {
            printf("Warning: unknonw device %s, sscanf %d\n", device, ret );
        }
    }
    return 0;
}

static void *ppService(void *ptr) {
    //for TIPC server init
    int uiRet, stSocket, nRecv;
    struct sockaddr_tipc servAddr;
    struct sockaddr_tipc clientAddr;
    socklen_t addrlen = sizeof(clientAddr);

    servAddr.family                  = AF_TIPC;
    servAddr.addrtype                = TIPC_ADDR_NAMESEQ;
    servAddr.addr.nameseq.type       = CM_PORT_NAME_TYPE;
    servAddr.addr.nameseq.lower      = CM_PORT_NAME_INST;
    servAddr.addr.nameseq.upper      = CM_PORT_NAME_INST;
    servAddr.scope                   = TIPC_ZONE_SCOPE;
    //end of TIPC server init
    stSocket = socket(AF_TIPC, SOCK_RDM, 0);
    if (-1 == stSocket) {
        perror("PP Server socket");
        return NULL;
    }

    uiRet = bind(stSocket, (struct sockaddr *)&servAddr, sizeof(servAddr));
    if (0 != uiRet) {
        perror( "Server bind" );
        return NULL;
    }

    void *recvMsg = malloc(MAX_PKT_LEN);
    assert( recvMsg != NULL );
    int ret, nSeg;
    char *splitList[4]  = {NULL};
    // recieve messages from socket forever
    while (1) {
        nRecv = recvfrom(stSocket, recvMsg, MAX_PKT_LEN, 0, (struct sockaddr *)&clientAddr, &addrlen);
        nRecv  = 1;
        if (nRecv <= 0) {
            perror( "PP Server unexpected message" );
            continue;
        }
        nSeg    = split( recvMsg, "_", splitList );
        cmodelProcess( *(splitList + 0), *(splitList + 1), strtoull( *(splitList + 2), NULL, 16) );
        memset( recvMsg, 0, MAX_PKT_LEN );
    }
    free( recvMsg );
    close( stSocket );
    return NULL;
}

void initPktProc() {
    pthread_t pid = createDaemonThread( ppService, NULL );
    if ( pid < 0) {
        printf( "FATAL: create PktProc daemon service failed.\n" );
    }
    //pid = createDaemonThread( agingService, NULL );
    //if (pid < 0) {
    //    printf( "FATAL: create Aging daemon service failed.\n" );
    //}
}
