/*
 * Software Development Kit for Fisilink
 * @file: serv.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <linux/tipc.h>
#include <linux/tipc_config.h>
#include <pthread.h>

#include <sdklog.h>
#include <const.h>

static int executeCli(char *cli, void *retVal) {
    servLogDebug("CMD: [%s]\r\n", cli);
    register int idx = 0;
    while(isspace(cli[idx])) {
        idx++;
    }
    char *argv[MAX_SEG_FLDS] = {NULL};
    int argc = split((cli+idx), " ,", argv);
    int ret = 0;
    // search command
    const tCmd *command = findCmd(argv[0]);
    if(command) {
        // get command the first parameter
        ret = (*(command->func))(argv, argc, retVal);
    }
    return ret;
}

static void *cliService(void *ptr) {
    //for TIPC server init
    int uiRet, stSocket;
    struct sockaddr_tipc servAddr;
    struct sockaddr_tipc clientAddr;
    socklen_t addrlen = sizeof(clientAddr);

    servAddr.family                  = AF_TIPC;
    servAddr.addrtype                = TIPC_ADDR_NAMESEQ;
    servAddr.addr.nameseq.type       = CLI_NAME_TYPE;
    servAddr.addr.nameseq.lower      = CLI_NAME_INST;
    servAddr.addr.nameseq.upper      = CLI_NAME_INST;
    servAddr.scope                   = TIPC_ZONE_SCOPE;
    //end of TIPC server init

    stSocket = socket(AF_TIPC, SOCK_RDM, 0);
    if (-1 == stSocket) {
        servLogError("SDK Server socket, with %s\r\n", strerror(errno));
        return NULL;
    }
    uiRet = bind(stSocket, (struct sockaddr *)&servAddr, sizeof(servAddr));
    if (0 != uiRet) {
        servLogError("Server bind, with %s\r\n", strerror(errno));
        goto sock_error;
    }

    void *recvMsg = malloc(TIPC_MSG_SIZE);
    assert(recvMsg != NULL);
    void *respBuf = malloc(MAX_RESP_LEN);
    assert(respBuf != NULL);
    int ret, nRecv, tmp;
    
    while (1) {
        nRecv = recvfrom(stSocket, recvMsg, TIPC_MSG_SIZE, 0, (struct sockaddr *)&clientAddr, &addrlen);
        if (nRecv <= 0) {
            servLogError("Server unexpected message, with %s\r\n", strerror(errno));
            continue;
        }
        ret = executeCli(recvMsg, respBuf);
        if (ret <= 0) {      // if execute command failed, the response is the reason
            servLogWarn(" %s executes failed, return %d, with %s.\r\n", (char *)recvMsg, ret, (char *)respBuf);
            ret = strlen(respBuf);
        }
        memset(recvMsg, 0, TIPC_MSG_SIZE);
        
        tmp = sendto(stSocket, respBuf, ret, 0, (struct sockaddr *)&clientAddr, addrlen);
        if (0 > tmp) {
            servLogError("Server sendto, with %s\r\n", strerror(errno));
        }
        memset(respBuf, 0, MAX_RESP_LEN);
    }
    free(recvMsg);
    free(respBuf);
sock_error:
    close(stSocket);
    return NULL;
}

void startupCliService() {
    pthread_t pid = createDaemonThread(cliService, NULL);    
    if (pid < 0) {
        servLogError("FATAL: create SDK daemon service failed.\r\n");
    }
}
