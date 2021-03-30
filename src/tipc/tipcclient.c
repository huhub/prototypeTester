/**
 * Software Development Kit for Fisilink
 * @file: rpcutil.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>  // htonl
#include <linux/tipc.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sdklog.h>
#include <const.h>

static void waiting4Server(__u32 name_type, __u32 name_instance, uint32_t wait) {
    struct sockaddr_tipc topsrv;
    struct tipc_subscr subscr;
    struct tipc_event event;

    int sd = socket(AF_TIPC, SOCK_SEQPACKET, 0);
    if(sd < 0) {
        servLogError("CLIENT gets new socket failed. with %s\r\n", strerror(errno));
        exit(1);
    }

    memset(&topsrv, 0, sizeof(topsrv));
    topsrv.family                  = AF_TIPC;
    topsrv.addrtype                = TIPC_ADDR_NAME;
    topsrv.addr.name.name.type     = TIPC_TOP_SRV;
    topsrv.addr.name.name.instance = TIPC_TOP_SRV;

    /* Connect to topology server */
    if (0 > connect(sd, (struct sockaddr *)&topsrv, sizeof(topsrv))) {
        servLogError("Client failed to connect to topology server, with %s\r\n", strerror(errno));
        exit(1);
    }

    subscr.seq.type  = htonl(name_type);
    subscr.seq.lower = htonl(name_instance);
    subscr.seq.upper = htonl(name_instance);
    subscr.timeout   = htonl(wait);
    subscr.filter    = htonl(TIPC_SUB_SERVICE);

    if (send(sd, &subscr, sizeof(subscr), 0) != sizeof(subscr)) {
        servLogError("Client failed to send subscription, with %s\r\n", strerror(errno));
        exit(1);
    }
    /* Now wait for the subscription to fire */
    if (recv(sd, &event, sizeof(event), 0) != sizeof(event)) {
        servLogError("Client failed to receive event, with %s\r\n", strerror(errno));
        exit(1);
    }
    if (event.event != htonl(TIPC_PUBLISHED)) {
        servLogError("Client server {%u,%u} not published within %d [s]\r\n",
               name_type, name_instance, wait/1000);
        exit(1);
    }

    close(sd);
}

int rpcSendPkt(char *pkt, char *port, unsigned long long *ts) {
    if(pkt == NULL || strlen(pkt) <= 8) {
        return -1;
    }

    int uiRet = -1;
    waiting4Server(CM_PORT_NAME_TYPE, CM_PORT_NAME_INST, 10000);
    int stSocket = socket(AF_TIPC, SOCK_RDM, 0);
    struct sockaddr_tipc servAddr;
    servAddr.family                  = AF_TIPC;
    servAddr.addrtype                = TIPC_ADDR_NAME;
    servAddr.addr.name.name.type     = PKT_NAME_TYPE;
    servAddr.addr.name.name.instance = PKT_NAME_INST;
    servAddr.addr.name.domain        = 0;

    unsigned char buffer[MAX_PKT_LEN];
    sprintf(buffer, "%s_%s_%llx", pkt, port, *ts);
    uiRet = sendto(stSocket, (void*)buffer, strlen(buffer), 0, (struct sockaddr*)&servAddr, sizeof(servAddr));
    if(uiRet < 0) {
        servLogError("PKT sendto failed, with %s\r\n", strerror(errno));
    }

    close(stSocket);
    return uiRet;
}

int rpcSendCli(char *cli, const uint32_t size, void *result) {
    if(cli == NULL) {
        return -1;
    }
    int uiRet = 0;
    waiting4Server(SDK_PORT_NAME_TYPE, SDK_PORT_NAME_INST, 10000);
    int stSocket = socket(AF_TIPC, SOCK_RDM, 0);
    struct sockaddr_tipc servAddr;
    servAddr.family                  = AF_TIPC;
    servAddr.addrtype                = TIPC_ADDR_NAME;
    servAddr.addr.name.name.type     = CLI_NAME_TYPE;
    servAddr.addr.name.name.instance = CLI_NAME_INST;
    servAddr.addr.name.domain        = 0;
    uiRet = sendto(stSocket, (void*)cli, size, 0, (struct sockaddr*)&servAddr, sizeof(servAddr));
    if(uiRet < 0) {
        servLogError("CMD sendto failed, %s\r\n", strerror(errno));
        goto sock_error;
    }
    uiRet = recv(stSocket, (char *)result, MAX_RESP_LEN, 0);
    if(uiRet < 0) {
        servLogError("%s, send to client return %d\r\n", cli, uiRet);
        goto sock_error;
    } else {
        if (strncasecmp((char *)result, "ERROR:", 6) == 0) {
            servLogError("Command %s, return %s\r\n", cli, (char *)result);
            uiRet = -1;
        }
    }
sock_error:
    close(stSocket);
    return uiRet;
}
