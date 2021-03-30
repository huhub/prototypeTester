/*
 * cmodel for Pishon
 * @file: PacketProcess
 * @description: auto generage
 * @note: Copyright (C) 2021-03-29 12:40:57.461013
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
#include <mem/PacketProcessOpr.h>
#include <mem/PacketProcess.h>

void PacketProcess(tPktInfo *PI) {
	uint8_t tmpStormCtlPkt = 0;
	uint8_t tmpStormCtlPtr = 0;
	uint8_t tmpMacDaDiscard = 0;
	uint8_t tmpEthPr = 0;
	uint8_t tmpStormCtlEn = 0;
	uint16_t tmpSrcMap = 0;
	uint8_t tmpSrcPortIdx = 0;
	uint8_t tmpExceed = 0;
	uint8_t tmpBpduDrop = 0;
	uint8_t tmpNeedLearn = 0;
	uint16_t tmpLagMap = 0;
	uint8_t tmpLagPort = 0;

	tDsMemStorm DsMemStormValTmp = {0};
	tDsMemStorm *DsMemStormVal = &DsMemStormValTmp;
	tCtlPpGapConfig CtlPpGapConfigTmp = {0};
	tCtlPpGapConfig *CtlPpGapConfig = &CtlPpGapConfigTmp;
	readCtlPpGapConfig("CtlPpGapConfig", 0, CtlPpGapConfig, 0);
	tDsRegPortLearnCtrl DsRegPortLearnCtrlValTmp = {0};
	tDsRegPortLearnCtrl *DsRegPortLearnCtrlVal = &DsRegPortLearnCtrlValTmp;
	tDsMemRoute DsMemRouteValTmp = {0};
	tDsMemRoute *DsMemRouteVal = &DsMemRouteValTmp;
	tCtlPktProcLog CtlPktProcLogTmp = {0};
	tCtlPktProcLog *CtlPktProcLog = &CtlPktProcLogTmp;
	readCtlPktProcLog("CtlPktProcLog", 0, CtlPktProcLog, 0);
	tDsRegPortLearnNum DsRegPortLearnNumValTmp = {0};
	tDsRegPortLearnNum *DsRegPortLearnNumVal = &DsRegPortLearnNumValTmp;
	tCtlStormCntl CtlStormCntlTmp = {0};
	tCtlStormCntl *CtlStormCntl = &CtlStormCntlTmp;
	readCtlStormCntl("CtlStormCntl", 0, CtlStormCntl, 0);
	tDsMemStormCtrl DsMemStormCtrlValTmp = {0};
	tDsMemStormCtrl *DsMemStormCtrlVal = &DsMemStormCtrlValTmp;
	tCtlMacLearn CtlMacLearnTmp = {0};
	tCtlMacLearn *CtlMacLearn = &CtlMacLearnTmp;
	readCtlMacLearn("CtlMacLearn", 0, CtlMacLearn, 0);
	tDsMemTsnHandle DsMemMacTsnValTmp = {0};
	tDsMemTsnHandle *DsMemMacTsnVal = &DsMemMacTsnValTmp;
	tDsMemMac DsMemMacValTmp = {0};
	tDsMemMac *DsMemMacVal = &DsMemMacValTmp;
	tDsMemTsnHandle DsMemRouteTsnValTmp = {0};
	tDsMemTsnHandle *DsMemRouteTsnVal = &DsMemRouteTsnValTmp;

    PI->gapValue       = CtlPpGapConfig->gapValue{PI->srcPort};
    /** Routing Process */
    if (PI->routingEn && !PI->bypassPp && (PI->hostRouteLeftHit || PI->hostRouteRightHit)) {
        rpcRdMem("DsMemHostRoute", PI->ipRouteIdx, DsMemRouteVal);
        rpcRdMem("DsMemHostTsn", PI->ipRouteIdx, DsMemRouteTsnVal);
        PI->isTsn       = (PI->isTsn || DsMemRouteTsnVal->isTsn) && PI->tsnEn;
        PI->tsnHandle   = DsMemRouteTsnVal->tsnHandle;
        SET_BITS(PI->isTsn, 1, 1, (PI->isTsn));
        PI->tsnHandle = PI->tsnHandle;
        PI->destMap = DsMemRouteVal->destMap;
        PI->nexthopIdx = DsMemRouteVal->nexthopIdx;
        PI->flowPolicePtr = DsMemRouteVal->flowPolicePtr;
        PI->flowPoliceValid = DsMemRouteVal->flowPoliceValid;
        PI->flowStatsValid = DsMemRouteVal->flowStatsValid; 
        PI->flowStatsPtr = DsMemRouteVal->flowStatsPtr < 191 ? DsMemRouteVal->flowStatsPtr : 191; 
        PI->opCode = GET_BITS(PI->nexthopIdx, 5, 5) ? OP_CODE_MCAST : OP_CODE_UCAST;
        PI->igrFlowSpan = DsMemRouteVal->mirrorEn;
        PI->discard = PI->discard | DsMemRouteVal->discard;
        PI->routeDiscard = DsMemRouteVal->discard;
        if (DsMemRouteVal->copyToCpu ) {
            PI->copyToCpu        = 1;
            PI->cpuPktType  = CPU_PKT_ROUTELKP;
        }
        if (DsMemRouteVal->nat ) {
            PI->opCode      = OP_CODE_NAT;
        }
        if (PI->ipOptions || PI->otherHeader || (PI->ttl <= 1) ) {
            PI->discard               = PI->discard | 1;
            PI->exception             = 1;
            PI->routeExcpDiscard = 1;
            PI->excpType    = EXCP_ROUTE;
        }
    }
    /** Bridging Process */
    PI->bridgeProcess = !PI->bypassPp && !PI->routingEn;
    PI->destMacKnown  = PI->macDaLValid || PI->macDaRValid;
    tmpLagMap = 0x400 + PI->linkAggId;
    tmpLagPort = ((uint64_t)1<<8) + ( PI->linkAggId);
    if (PI->bridgeProcess && PI->destMacKnown) {
        rpcRdMem("DsMemMac", PI->macDaIdx, DsMemMacVal);
        PI->entryPend = DsMemMacVal->pending;
        if (!PI->entryPend) {
            rpcRdMem("DsMemMacTsn", PI->macDaIdx, DsMemMacTsnVal);
            PI->isTsn     = (PI->isTsn || DsMemMacTsnVal->isTsn) && PI->tsnEn;
            PI->tsnHandle = DsMemMacTsnVal->tsnHandle;
            SET_BITS(PI->isTsn, 2, 2, (PI->isTsn));
            PI->tsnHandle = PI->tsnHandle;
            PI->flowPolicePtr  = DsMemMacVal->flowPolicePtr;
            PI->flowPoliceValid= DsMemMacVal->flowPoliceValid;
            PI->flowStatsValid= DsMemMacVal->flowStatsValid; 
            PI->flowStatsPtr  = DsMemMacVal->flowStatsPtr < 191 ? DsMemMacVal->flowStatsPtr : 191; 
            PI->destMap       = DsMemMacVal->destMap;
            PI->opCode        = DsMemMacVal->isMcast ? OP_CODE_MCAST : OP_CODE_UCAST;
            PI->igrFlowSpan   = DsMemMacVal->mirrorEn;
            tmpSrcMap= PI->isLinkAggMbr ? tmpLagMap : PI->srcPort;
            if (PI->l2SrcMatchDiscard && (tmpSrcMap == DsMemMacVal->destMap) && !DsMemMacVal->isMcast ) {
                PI->discard                = PI->discard | 1;
                PI->l2UcastSrcMatchDiscard = 1;
            }
            PI->discard = PI->discard | DsMemMacVal->dstDiscard;
            tmpMacDaDiscard = DsMemMacVal->dstDiscard;
            if (DsMemMacVal->copyToCpu ) {
                PI->copyToCpu              = 1;
                PI->cpuPktType        = CPU_PKT_MACDALKP;
            }
        }
    }
    /** For custome specified forwarding */
    if (PI->cuMacHit) {
        DsMemCustomFdbVal = DsMemCustomFdb[ PI->cuMacIdx }
    } else if (PI->cuMacPcpHit) {
        DsMemCustomFdbVal = DsMemCustomFdb[ PI->cuMacPcpIdx }
    } else if (PI->cuIpDscpHit) {
        DsMemCustomFdbVal = DsMemCustomFdb[ PI->cuIpDscpIdx }
    } else if (PI->cuIpSportHit) {
        DsMemCustomFdbVal = DsMemCustomFdb[ PI->cuIpSportIdx }
    } else if (PI->cuIpDportHit) {
        DsMemCustomFdbVal = DsMemCustomFdb[ PI->cuIpDportIdx }
    } 
    if ((PI->cuMacHit || PI->cuMacPcpHit || PI->cuIpDscpHit || PI->cuIpSportHit || PI->cuIpDscpHit) &&
        !PI->bypassPp) {
        PI->isTsn          = DsMemCustomFdbVal->isTsn;
        PI->tsnHandle      = DsMemCustomFdbVal->tsnHandle;
        PI->flowPolicePtr  = DsMemCustomFdbVal->flowPolicePtr;
        PI->flowPoliceValid= DsMemCustomFdbVal->flowPoliceValid;
        PI->flowStatsValid = DsMemCustomFdbVal->flowStatsValid; 
        PI->flowStatsPtr   = DsMemCustomFdbVal->flowStatsPtr < 191 ? DsMemCustomFdbVal->flowStatsPtr : 191; 
        PI->destMap        = DsMemCustomFdbVal->destMap;
        PI->opCode         = DsMemCustomFdbVal->isMcast ? OP_CODE_MCAST : OP_CODE_UCAST;
        PI->igrFlowSpan    = DsMemCustomFdbVal->mirrorEn;
        if (PI->srcPort != DsMemCustomFdbVal) {
            PI->discard    = 1;
        }
        if (PI->srcPort == PI->destMap) {
            PI->discard    = 1;
        }
    }
    if (PI->bridgeProcess) {
        tmpBpduDrop       = PI->isBpdu && (PI->bpduDrop || (PI->stpState == STP_DISCARD));
        if ((tmpBpduDrop) || (!PI->isBpdu && (PI->stpState != STP_FWD)) ) {
            PI->discard    = PI->discard | 1;
            PI->igrStpCheckDiscard = 1;
        }
        if (PI->isBpdu && !tmpBpduDrop ) {
            PI->copyToCpu  = 1;
            PI->discard    = PI->discard | 1;
            PI->cpuPktType = CPU_PKT_BPDU;
        }
    }
    tmpEthPr = findPrByType( PROTO_TYPE_ETH );
    if (PI->bridgeProcess && CtlStormCntl->enable) {
        tmpStormCtlPkt            = 1;
        tmpStormCtlEn             = 0;
        if ( GET_BITS(tmpEthPr->qualifier, 0, 0) ) {        // bcast mac
            tmpStormCtlPtr = ((uint64_t)2<<8) + ( PI->logicalPort);
        } else if ( GET_BITS(tmpEthPr->qualifier, 1, 1) ) {   // mcast mac
            tmpStormCtlPtr   = ((uint64_t)1<<8) + ( PI->logicalPort);
        } else if (!PI->macDaLValid && !PI->macDaRValid) {
            tmpStormCtlPtr   = ((uint64_t)0<<8) + ( PI->logicalPort);
        } else { 
            tmpStormCtlPkt        =0; 
        }
        if (tmpStormCtlPkt ) {
            rpcRdMem("DsMemStormCtrl", tmpStormCtlPtr, DsMemStormCtrlVal);
            rpcRdMem("DsMemStorm", tmpStormCtlPtr, DsMemStormVal);
            tmpStormCtlEn         = DsMemStormCtrlVal->stormCtrlEn & !PI->discard;
        }
        if (tmpStormCtlEn && !PI->fromRemoteSpan ) {
            if (DsMemStormVal->runningCounter >= DsMemStormCtrlVal->threshold ) {
                PI->stormDrop      = 1;
                PI->discard        = PI->discard | 1;
            } else {
                if (DsMemStormCtrlVal->usePktCount ) {
                    DsMemStormVal->runningCounter = DsMemStormVal->runningCounter + 1;
                } else {
                    DsMemStormVal->runningCounter = DsMemStormVal->runningCounter + PI->pktLength + PI->gapValue;
                }
                rpcSetMem( "DsMemStorm", tmpStormCtlPtr , DsMemStormVal, sizeof(tDsMemStorm) );
            }
        }
    }
    /** Learning Prerequisites */
    if (!PI->discard && !PI->lrnDisable && (PI->stpState != STP_DISCARD) ) {
        tmpSrcPortIdx = PI->isLinkAggMbr ? tmpLagPort : PI->srcPort;
        PI->srcMap = PI->isLinkAggMbr ? tmpLagMap : PI->srcPort;
        MsgLearnInfo->macSa = PI->macSa;
        MsgLearnInfo->macSaHi = PI->macSaHi;
        MsgLearnInfo->fid = PI->fid;
        MsgLearnInfo->lrnType = PI->lrnType;
        MsgLearnInfo->learnIdx = PI->learnIdx;
        MsgLearnInfo->srcPortIdx = PI->srcPortIdx;
        MsgLearnInfo->srcMap = PI->srcMap;
        // violation check
        tmpNeedLearn             = 1;
        rpcRdMem("DsRegPortLearnCtrl", tmpSrcPortIdx, DsRegPortLearnCtrlVal);
        PI->lrnPortLockDiscard    = DsRegPortLearnCtrlVal->lock;
        if (DsRegPortLearnCtrlVal->lock ) {
            PI->discard           = PI->discard | 1;
            tmpNeedLearn         = 0;
            if (DsRegPortLearnCtrlVal->violationToCpu ) {
                PI->exception     = PI->exception | 1;
                PI->excpType      = EXCP_LOCKVIOLATION;
            }
        }
        rpcRdMem("DsRegPortLearnNum", tmpSrcPortIdx, DsRegPortLearnNumVal);
        tmpExceed  = DsRegPortLearnNumVal->learntMacNum >= DsRegPortLearnCtrlVal->maxMacNum;
        PI->lrnNumExceedDiscard = DsRegPortLearnCtrlVal->macNumLimitEn && tmpExceed;
        if (PI->lrnNumExceedDiscard ) {
            PI->discard          |= DsRegPortLearnCtrlVal->lrnNumExceedDiscard;
            tmpNeedLearn         = 0;
            if (DsRegPortLearnCtrlVal->violationToCpu ) {
                PI->exception     = PI->exception | 1;
                PI->excpType      = EXCP_MACNUMLIMITVIOLATION;
            }
        }
        // add to learn fifo 
        PI->cpuFifoFullNum = CtlPktProcLog->cpuFifoFullNum;
        PI->hwFifoFullNum  = CtlPktProcLog->hwFifoFullNum;
        if (tmpNeedLearn && CtlMacLearn->cpuLearnEn ) {
            // Push learnInfo into CpuLearnFifo;
            CtlMacLearn->cpuLearnNum  += 1;
            CtlMacLearn->cpuFifoDepth += 1;
            if (CtlMacLearn->cpuFifoDepth > CtlMacLearn->cpuLrnNumThrd ) {
                PI->cpuFifoFullNum += 1;
            }
        } else if (tmpNeedLearn && !CtlMacLearn->cpuLearnEn ) {
            // Push learnInfo into HwLearnFifo;
            CtlMacLearn->hwLearnNum  += 1;
            CtlMacLearn->hwFifoDepth += 1;
            if (CtlMacLearn->hwFifoDepth > CtlMacLearn->hwLrnNumThrd ) {
                PI->hwFifoFullNum += 1;
            } else {
                FdbLearning( MsgLearnInfo );
            }
        }
    }
    CtlPktProcLog->cpuFifoFullNum = PI->cpuFifoFullNum;
    CtlPktProcLog->hwFifoFullNum = PI->hwFifoFullNum;
    CtlPktProcLog->aclQosLogEn = PI->aclQosLogEn;
    CtlPktProcLog->aclDiscard = PI->aclDiscard;
    CtlPktProcLog->routeDiscard = PI->routeDiscard;
    CtlPktProcLog->routeExcpDiscard = PI->routeExcpDiscard;
    CtlPktProcLog->routeProcess = PI->routeProcess;
    CtlPktProcLog->bridgeProcess = PI->bridgeProcess;
    CtlPktProcLog->destMacKnown = PI->destMacKnown;
    CtlPktProcLog->l2UcastSrcMatchDiscard = PI->l2UcastSrcMatchDiscard;
    CtlPktProcLog->macDaDiscard = PI->macDaDiscard;
    CtlPktProcLog->igrStpCheckDiscard = PI->igrStpCheckDiscard;
    CtlPktProcLog->stormDrop = PI->stormDrop;
    CtlPktProcLog->lrnPortLockDiscard = PI->lrnPortLockDiscard;
    CtlPktProcLog->lrnNumExceedDiscard = PI->lrnNumExceedDiscard;
    CtlPktProcLog->isTsn = PI->isTsn;
    CtlPktProcLog->tsnHandle = PI->tsnHandle;
    CtlPktProcLog->igrFlowSpan = PI->igrFlowSpan;
    CtlPktProcLog->entryPend = PI->entryPend;
}
void StormCtrlUpdate(uint8_t ) {
	uint8_t tmpStormPtr = 0;

	tDsMemStorm DsMemStormValTmp = {0};
	tDsMemStorm *DsMemStormVal = &DsMemStormValTmp;
	tCtlStormCntl CtlStormCntlTmp = {0};
	tCtlStormCntl *CtlStormCntl = &CtlStormCntlTmp;
	readCtlStormCntl("CtlStormCntl", 0, CtlStormCntl, 0);
	tDsMemStormCtrl DsMemStormCtrlValTmp = {0};
	tDsMemStormCtrl *DsMemStormCtrlVal = &DsMemStormCtrlValTmp;

    while ( CtlStormCntl->enable ) {
        tmpStormPtr  = CtlStormCntl->stormCurPtr;
        rpcRdMem("DsMemStormCtrl", tmpStormPtr, DsMemStormCtrlVal);
        rpcRdMem("DsMemStorm", tmpStormPtr, DsMemStormVal);
        if (DsMemStormVal->runningCounter >= DsMemStormCtrlVal->threshold ) {
            DsMemStormVal->runningCounter -= DsMemStormCtrlVal->threshold;
        } else {
            DsMemStormVal->runningCounter = 0;
        }
        rpcSetMem( "DsMemStorm", tmpStormPtr , DsMemStormVal, sizeof(tDsMemStorm) );
        DelayCycle( CtlStormCntl->stormInterval );
        // update pointer
        CtlStormCntl->stormCurPtr = tmpStormPtr + 1;
        if (CtlStormCntl->stormCurPtr >= CtlStormCntl->stormMaxPtr) {
            CtlStormCntl->stormCurPtr = CtlStormCntl->stormMinPtr;
			DelayCycle( CtlStormCntl->stormFinalDelay );
            // update round
            CtlStormCntl->stormCurRound   = (CtlStormCntl->stormCurRound + 1) >= CtlStormCntl->stormUpdRound ? 0 : CtlStormCntl->stormCurRound + 1;
        }
    }
}
