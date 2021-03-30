/*
 * cmodel for Pishon
 * @file: HeaderAdjust
 * @description: auto generage
 * @note: Copyright (C) 2021-03-29 12:40:57.361786
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <ppinfo.h>
#include <ppenum.h>
#include <mem/HeaderAdjustOpr.h>
#include <mem/HeaderAdjust.h>

void HeaderAdjust(tPktInfo *PI, uint8_t *glPktHdr, uint16_t  pktLength, uint8_t  channelId, uint8_t  hwDiscard ) {

	tCtlCommon CtlCommonTmp = {0};
	tCtlCommon *CtlCommon = &CtlCommonTmp;
	readCtlCommon("CtlCommon", 0, CtlCommon, 0);
	tCtlHdrAdjLog CtlHdrAdjLogTmp = {0};
	tCtlHdrAdjLog *CtlHdrAdjLog = &CtlHdrAdjLogTmp;
	readCtlHdrAdjLog("CtlHdrAdjLog", 0, CtlHdrAdjLog, 0);
	tDsRegChnlAttr DsRegChnlAttrValTmp = {0};
	tDsRegChnlAttr *DsRegChnlAttrVal = &DsRegChnlAttrValTmp;

    PI->opCode        = OP_CODE_BCAST;               // 32
    PI->discard       = hwDiscard;
    PI->pktLength     = pktLength;
    rpcRdMem("DsRegChnlAttr", channelId, DsRegChnlAttrVal);
    PI->srcPort       = DsRegChnlAttrVal->portId;
	PI->bypassPp      = DsRegChnlAttrVal->bypassPp;
	PI->destMap       = DsRegChnlAttrVal->destMap;
	PI->dot1qType     = DsRegChnlAttrVal->dot1qType;
    PI->hasInnerHdr   = ((PI->srcPort == CtlCommon->cpuPortNo) && CtlCommon->cpuHdrEn);
    if( PI->hasInnerHdr ) {
                // parser from_cpu_header
        PI->bypassPp     = GET_BITS(glPktHdr[0], 7, 7);
        PI->opCode       = GET_BITS(glPktHdr[0], 4, 6);
        PI->vlanId       = ((uint64_t) GET_BITS(glPktHdr[0], 0, 3)<<8) + ( glPktHdr[1]);
        PI->srcPort      = glPktHdr[2];
        PI->destMap      = ((uint64_t)glPktHdr[3]<<8) + ( glPktHdr[4]);
        PI->prior        = GET_BITS(glPktHdr[5], 3, 7);
        PI->isTsn        = GET_BITS(glPktHdr[5], 2, 2);
        PI->lrnDisable   = GET_BITS(glPktHdr[5], 1, 1);
        PI->forbidEdit   = GET_BITS(glPktHdr[5], 0, 0);
        PI->ts           = ((uint64_t)glPktHdr[8]<<56) + ((uint64_t)glPktHdr[9]<<48) + ((uint64_t)glPktHdr[10]<<40) + ((uint64_t)glPktHdr[11]<<32) + ((uint64_t)glPktHdr[12]<<24) + ((uint64_t)glPktHdr[13]<<16) + ((uint64_t)glPktHdr[14]<<8) + ( glPktHdr[15]); 
        PI->criticalPkt  = 1;
		PI->psrOffset   += 8;
    }
    // adjust header for inner header and crc
    PI->hdrLength = (PI->pktLength <= 64) ? PI->pktLength - 4/*strip CRC*/ : 64;
    if (PI->hdrLength < PI->psrOffset) {
        PI->discard         = 1;
        SET_BITS(PI->discardBmp, 1, 1, (1));
    }
    PI->pktType     = PROTO_TYPE_ETH;   // for first time parser
    CtlHdrAdjLog->isTsn     = PI->isTsn;
    CtlHdrAdjLog->discard     = PI->discard;
    CtlHdrAdjLog->srcPort     = PI->srcPort;
    //CtlHdrAdjLog.pktLenLog     = PI.pktLenLog;
}
