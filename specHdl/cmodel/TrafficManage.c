/*
 * cmodel for Pishon
 * @file: TrafficManage
 * @description: auto generage
 * @note: Copyright (C) 2021-03-29 12:40:57.528103
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
#include <mem/TrafficManageOpr.h>
#include <mem/TrafficManage.h>

static int getEnqueueIpv(uint8_t port, uint8_t MsgAdmInfo) {
	uint8_t tmpClock0 = 0;
	uint8_t tmpPrior = 0;
	uint8_t tmpState = 0;
	uint8_t tmpClock1 = 0;

	tCtlCommon CtlCommonTmp = {0};
	tCtlCommon *CtlCommon = &CtlCommonTmp;
	readCtlCommon("CtlCommon", 0, CtlCommon, 0);
	tCtlEnqCfg CtlEnqCfgTmp = {0};
	tCtlEnqCfg *CtlEnqCfg = &CtlEnqCfgTmp;
	readCtlEnqCfg("CtlEnqCfg", 0, CtlEnqCfg, 0);
	tDsMemTsnGate DsMemTsnGateValTmp = {0};
	tDsMemTsnGate *DsMemTsnGateVal = &DsMemTsnGateValTmp;
	tCtlPtpTimerEn CtlPtpTimerEnTmp = {0};
	tCtlPtpTimerEn *CtlPtpTimerEn = &CtlPtpTimerEnTmp;
	readCtlPtpTimerEn("CtlPtpTimerEn", 0, CtlPtpTimerEn, 0);
	tDsRegPtpTimer DsRegPtpTimer1ValTmp = {0};
	tDsRegPtpTimer *DsRegPtpTimer1Val = &DsRegPtpTimer1ValTmp;
	tDsRegPtpTimer DsRegPtpTimer0ValTmp = {0};
	tDsRegPtpTimer *DsRegPtpTimer0Val = &DsRegPtpTimer0ValTmp;

    tmpPrior                 = 0;
    tmpState                      = TSN_GATE_CLOSE;
    if (port == CtlCommon->cpuPortNo) {         // cpu port do not care about tsn
        tmpState                  = TSN_GATE_OPEN;
        tmpPrior             = GET_BITS(MsgAdmInfo->cpuPrior, 3, 5);
    } else {                        // Line ports
        if (( GET_BITS(CtlEnqCfg->tsnEn, 0, 31) & (1 << port)) && MsgAdmInfo->isTsn) {
            tmpState              = TSN_GATE_CLOSE;
            if ( GET_BITS(CtlPtpTimerEn->enable, MsgAdmInfo->tsnCycleSel, MsgAdmInfo->tsnCycleSel) && GET_BITS(CtlPtpTimerEn->enable, MsgAdmInfo->tsnCycleSel+1, MsgAdmInfo->tsnCycleSel+1)) {
                rpcRdMem("DsMemTsnGate", GET_BITS(MsgAdmInfo->tsnGateId, 0, 10), DsMemTsnGateVal);
                rpcRdMem("DsRegPtpTimer", MsgAdmInfo->tsnCycleSel, DsRegPtpTimer0Val);
                rpcRdMem("DsRegPtpTimer", MsgAdmInfo->tsnCycleSel+1, DsRegPtpTimer1Val);
                tmpClock0         = DsRegPtpTimer0Val->value;       // read current clock value
                tmpClock1         = DsRegPtpTimer1Val->value;       // read current clock value
                if ((CtlEnqCfg->gateOnly && DsMemTsnGateVal->state0) || (tmpClock0 && DsMemTsnGateVal->state0)) {              // Active high
                    tmpPrior = DsMemTsnGateVal->ipv0;
                    tmpState      = TSN_GATE_OPEN;
                } else if ((CtlEnqCfg->gateOnly && DsMemTsnGateVal->state1) || (tmpClock1 && DsMemTsnGateVal->state1)) {
                    tmpPrior = DsMemTsnGateVal->ipv1;
                    tmpState      = TSN_GATE_OPEN;
                }
            }
        } else if (( GET_BITS(CtlEnqCfg->tsnEn, 0, 31) & (1 << port)) && !MsgAdmInfo->isTsn) {      // all packet is treated as normal
            tmpState              = TSN_GATE_OPEN;
            tmpPrior         = CtlEnqCfg->ipv{ GET_BITS(MsgAdmInfo->prior, 3, 5) }[2:0];
        } else {                                               // TSN disable
            tmpState              = TSN_GATE_OPEN;
            tmpPrior         = GET_BITS(MsgAdmInfo->prior, 3, 5);
        }
    }
    return ((uint64_t) GET_BITS(tmpPrior, 0, 2)<<8) + ( tmpState);
}
static void Egress(uint8_t tMsgAdmInfo *msg, uint8_t uint8_t *packet) {


    tPktInfo *EPI = (tPktInfo *)calloc(sizeof(tPktInfo), 1);
    PacketEdit( EPI, packet, msg );
    //ASIC: push MsgAdmInfo0 into LogiRepBuf;
    if( !EPI->discard ) {
        int pktLen = EPI->pktLength;
        if ( 0 != (EPI->lenAdjust & (1 << 5)) ) {
            pktLen -= EPI->lenAdjust & 0x1f;    
        } else {
            pktLen += EPI->lenAdjust;        
        }
        if (EPI->destPort == CPU_PORT && EPI->egrExcp == 1) {
            pktLen = 64;
        }
        if (EPI->tsOpEn) {
            saveRxPacket( packet, pktLen-4, EPI->destPort);  // -4: save packet without crc
        #if CFG_DUMP == 1
            saveCosimPkt(packet + 16, pktLen-4-16, OUT_PKT, EPI->destPort);
        #endif
        } else {
            saveRxPacket( packet, pktLen-4, EPI->destPort);  // -4: save packet without crc
        #if CFG_DUMP == 1
            saveCosimPkt( packet, pktLen-4, OUT_PKT, EPI->destPort );
        #endif
        }
    } else {
    #if CFG_DUMP == 1
        createEmptyCosimPkt( OUT_PKT );
    #endif
    }
    free(EPI);
    EPI = NULL;
}
void AdmissionControl(tPktInfo *PI, uint64_t  ts, uint16_t  hdrBufPtr, uint16_t  tailBufPtr) {
	uint8_t tmpDestPort = 0;
	uint8_t tmpPriorIdx = 0;
	uint8_t tmpExcpType = 0;
	uint8_t tmpFwdExtBmp = 0;
	uint8_t tmpQid = 0;
	uint8_t tmpIdx = 0;
	uint8_t tmpEnqInfo = 0;
	uint8_t tmpFwdBmp = 0;
	uint8_t tmpRandom = 0;

	tCtlRepExtPort CtlRepExtPortTmp = {0};
	tCtlRepExtPort *CtlRepExtPort = &CtlRepExtPortTmp;
	readCtlRepExtPort("CtlRepExtPort", 0, CtlRepExtPort, 0);
	tCtlCommon CtlCommonTmp = {0};
	tCtlCommon *CtlCommon = &CtlCommonTmp;
	readCtlCommon("CtlCommon", 0, CtlCommon, 0);
	tDsRegCpuPktPrior DsRegCpuPktPriorValTmp = {0};
	tDsRegCpuPktPrior *DsRegCpuPktPriorVal = &DsRegCpuPktPriorValTmp;
	tCtlEnqCfg CtlEnqCfgTmp = {0};
	tCtlEnqCfg *CtlEnqCfg = &CtlEnqCfgTmp;
	readCtlEnqCfg("CtlEnqCfg", 0, CtlEnqCfg, 0);
	tCtlAdmLog CtlAdmLogTmp = {0};
	tCtlAdmLog *CtlAdmLog = &CtlAdmLogTmp;
	readCtlAdmLog("CtlAdmLog", 0, CtlAdmLog, 0);
	tDsRegQueueDrop DsRegQueueDropValTmp = {0};
	tDsRegQueueDrop *DsRegQueueDropVal = &DsRegQueueDropValTmp;

    //ASIC: tmpMsIgrInfo       = get tMsIgr2Adm info from Ingress;
    //ASIC: tMsgIgr2Adm tmpMsgIgr2Adm = Side-band info from Ingress;
    //MsgAdmInfo.fwdBitmap[7:0] = MsgIgr2Adm.fwdBitmap[7:0];
    //MsgAdmInfo.fwdBitmapW1[5:0] = MsgIgr2Adm.fwdBitmapW1[5:0];
    //MsgAdmInfo.pktLength[13:0] = MsgIgr2Adm.pktLength[13:0];
    //MsgAdmInfo.nexthopIdx[5:0] = MsgIgr2Adm.nexthopIdx[5:0];
    //MsgAdmInfo.firstDecideToCpu = MsgIgr2Adm.firstDecideToCpu;
    //MsgAdmInfo.criticalPacket = MsgIgr2Adm.criticalPacket;
    //MsgAdmInfo.forceDest = MsgIgr2Adm.forceDest;
    //MsgAdmInfo.forbidEdit = MsgIgr2Adm.forbidEdit;
    //MsgAdmInfo.removeVlanTag = MsgIgr2Adm.removeVlanTag;
    //MsgAdmInfo.replaceCos = MsgIgr2Adm.replaceCos;
    //MsgAdmInfo.replaceDscp = MsgIgr2Adm.replaceDscp;
    //MsgAdmInfo.excpType[2:0] = MsgIgr2Adm.excpType[2:0];
    //MsgAdmInfo.cpuPktType[3:0] = MsgIgr2Adm.cpuPktType[3:0];
    //MsgAdmInfo.opCode[2:0] = MsgIgr2Adm.opCode[2:0];
    //MsgAdmInfo.stpId[4:0] = MsgIgr2Adm.stpId[4:0];
    //MsgAdmInfo.vlanId[11:0] = MsgIgr2Adm.vlanId[11:0];
    //MsgAdmInfo.srcPort[2:0] = MsgIgr2Adm.srcPort[2:0];
    //MsgAdmInfo.prior[5:0] = MsgIgr2Adm.prior[5:0];
    //MsgAdmInfo.routingEn = MsgIgr2Adm.routingEn;
    //MsgAdmInfo.l3Offset[5:0] = MsgIgr2Adm.l3Offset[5:0];
    //MsgAdmInfo.l4Offset[6:0] = MsgIgr2Adm.l4Offset[6:0];
    //MsgAdmInfo.l3Type[3:0] = MsgIgr2Adm.l3Type[3:0];
    //MsgAdmInfo.l4Type[3:0] = MsgIgr2Adm.l4Type[3:0];
    //MsgAdmInfo.hasInnerHdr = MsgIgr2Adm.hasInnerHdr;
    //MsgAdmInfo.isTsn = MsgIgr2Adm.isTsn;
    //MsgAdmInfo.tsnGateId[4:0] = MsgIgr2Adm.tsnGateId[4:0];
    //MsgAdmInfo.tsnCycleSel[2:0] = MsgIgr2Adm.tsnCycleSel[2:0];
    //MsgAdmInfo.addRtag = MsgIgr2Adm.addRtag;
    //MsgAdmInfo.rtagSeq[15:0] = MsgIgr2Adm.rtagSeq[15:0];
    //MsgAdmInfo.stagValid = MsgIgr2Adm.stagValid;
    //MsgAdmInfo.ctagValid = MsgIgr2Adm.ctagValid;
    //MsgAdmInfo.ptpValid = MsgIgr2Adm.ptpValid;
    //MsgAdmInfo.ethTypeLen[3:0] = MsgIgr2Adm.ethTypeLen[3:0];
    //MsgAdmInfo.cpuPrior[5:0]    = 0;
    //MsgAdmInfo.extendFlag       = 0;
    //MsgAdmInfo.extendIdx[2:0]   = 0;
    //MsgAdmInfo.ingressTs[63:0] = ts;
    //MsgAdmInfo.hdrBufPtr[12:0] = hdrBufPtr;
    //MsgAdmInfo.tailBufPtr[12:0] = tailBufPtr;
    tmpFwdBmp = MsgIgr2Adm->fwdBitmap;
    int i;
    //ASIC: Physical Replication
    for (i = 0; i < 8; i++ ) {
        if( GET_BITS(tmpFwdBmp, i, i) & GET_BITS(CtlEnqCfg->enqEnBmp, i, i) ) {
            SET_BITS(MsgAdmInfo->destPort, 0, 4, (i));
            if( i == CtlCommon->cpuPortNo ) {
                tmpExcpType = 0x10 + GET_BITS(MsgAdmInfo->excpType, 0, 4);
                tmpPriorIdx  = ( GET_BITS(MsgAdmInfo->cpuPktType, 0, 3) != CPU_PKT_NONE) ? MsgAdmInfo->cpuPktType : tmpExcpType;
                rpcRdMem("DsRegCpuPktPrior", tmpPriorIdx, DsRegCpuPktPriorVal);
                SET_BITS(MsgAdmInfo->cpuPrior, 0, 5, ( GET_BITS(DsRegCpuPktPriorVal->prior, 0, 5)));
            }
            tmpEnqInfo = getEnqueueIpv(i, MsgAdmInfo);
            SET_BITS(CtlAdmLog->enqIpv, 0, 2, ( GET_BITS(tmpEnqInfo, 1, 3)));
            CtlAdmLog->gateState        = GET_BITS(tmpEnqInfo, 0, 0);
            if ( GET_BITS(tmpEnqInfo, 0, 0) == TSN_GATE_CLOSE) {
                SET_BITS(MsgAdmInfo->fwdBitmap, i, i, (0));
 GET_BITS(CtlAdmLog->gateCloseCnt, 0, 31) += 1;
            }
            tmpQid = ((uint64_t)i<<3) + ( GET_BITS(tmpEnqInfo, 1, 3) );
            rpcRdMem("DsRegQueueDrop", i, DsRegQueueDropVal);
            if ( GET_BITS(DsRegQueueDropVal->tailDropSet, tmpQid, tmpQid)) {
                SET_BITS(MsgAdmInfo->fwdBitmap, i, i, (0));
 GET_BITS(CtlAdmLog->tailDropCnt, 0, 31) += 1;
            } else if ( GET_BITS(DsRegQueueDropVal->wredSet, tmpQid, tmpQid)) {
                tmpRandom   = funcRandom(0, 1);
                SET_BITS(MsgAdmInfo->fwdBitmap, i, i, (tmpRandom));
                if (tmpRandom == 0) {
 GET_BITS(CtlAdmLog->wredCnt, 0, 31) += 1;
                }
            }
            if ( GET_BITS(MsgAdmInfo->fwdBitmap, i, i)) {
                uint8_t tmpPacket[2048] = {0}; 
                memcpy(tmpPacket, glPkt, MsgAdmInfo->pktLength);
                Egress( MsgAdmInfo, tmpPacket);
                //ASIC:  Push MsgAdmInfo into TM queue according tmpQid[7:0];
            }
        }
    }
    // Logical Replication
    tmpFwdExtBmp = MsgIgr2Adm->fwdBitmapW1;
    for (i = 0; i < 6; i++) {
        if( GET_BITS(tmpFwdExtBmp, i, i) ) {
            MsgAdmInfo0 = MsgAdmInfo;
            tmpIdx = i;
            tmpDestPort = CtlRepExtPort->destPort{ GET_BITS(tmpIdx, 0, 2:0]-2}[2);
            MsgAdmInfo0->destPort = tmpDestPort;
            SET_BITS(MsgAdmInfo0->extendIdx, 0, 2, (i));
            MsgAdmInfo0->extendFlag      = 1;
            tmpEnqInfo = getEnqueueIpv(i, MsgAdmInfo);
            tmpQid = ((uint64_t)i<<3) + ( GET_BITS(tmpEnqInfo, 1, 3) );
            uint8_t tmpPacket[2048] = {0}; 
            memcpy(tmpPacket, glPkt, MsgAdmInfo->pktLength);
            Egress(MsgAdmInfo0, tmpPacket);
        }
    }
}
//ASIC: tMsgAdmInfo tmpMsgAdmInfo = Get AdmCntlInfo if it is valid.;
//ASIC: void PacketReplicate(uint8_t MsgAdmInfo) {


//ASIC:     for (i = 0; i <  8; i++ ) {
//ASIC:         if( MsgAdmInfo.fwdBitmap[i:i] ) {
//ASIC:             tmpDestPort[4:0] = i;
//ASIC:             tmpEnqInfo[3:0] = getEnqueueIpv(i, MsgAdmInfo);
//ASIC:             tmpQid[7:0]           = { tmpDestPort, tmpEnqInfo[3:1] };
//ASIC:         //Change channelId[3:3] = CtlEnqCfg.tsnEn ? MsgAdmInfo.isTsn : 1;
//ASIC:         }
//ASIC:     } // end of for
//ASIC: }
