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
#include <simulator.h>

static unsigned int sInPktSequence = 0;

static void *pktService(void *ptr) {
    //for TIPC server init
    int uiRet, stSocket, nRecv;
    struct sockaddr_tipc servAddr;
    struct sockaddr_tipc clientAddr;
    socklen_t addrlen = sizeof(clientAddr);

    servAddr.family                  = AF_TIPC;
    servAddr.addrtype                = TIPC_ADDR_NAMESEQ;
    servAddr.addr.nameseq.type       = PKT_NAME_TYPE;
    servAddr.addr.nameseq.lower      = PKT_NAME_INST;
    servAddr.addr.nameseq.upper      = PKT_NAME_INST;
    servAddr.scope                   = TIPC_ZONE_SCOPE;
    //end of TIPC server init
    stSocket = socket(AF_TIPC, SOCK_RDM, 0);
    if (-1 == stSocket) {
        perror("PP Server socket");
        return NULL;
    }

    uiRet = bind(stSocket, (struct sockaddr *)&servAddr, sizeof(servAddr));
    if (0 != uiRet) {
        perror("Server bind");
        return NULL;
    }

    void *recvMsg = malloc(MAX_PKT_LEN);
    assert(recvMsg != NULL);
    int ret, nSeg;
    char *splitList[4]  = {NULL};
    // recieve messages from socket forever
    while (1) {
        nRecv = recvfrom(stSocket, recvMsg, MAX_PKT_LEN, 0, (struct sockaddr *)&clientAddr, &addrlen);
        if (nRecv <= 0) {
            perror("PP Server unexpected message");
            continue;
        }
        nSeg    = split(recvMsg, "_", splitList);
        cmodelProcess(*(splitList + 0), *(splitList + 1), strtoull(*(splitList + 2), NULL, 16));
        memset(recvMsg, 0, MAX_PKT_LEN);
    }
    free(recvMsg);
    close(stSocket);
    return NULL;
}

void initPktProc() {
    pthread_t pid = createDaemonThread(pktService, NULL);
    if ( pid < 0) {
        printf("FATAL: create PktProc daemon service failed.\n");
    }
}
