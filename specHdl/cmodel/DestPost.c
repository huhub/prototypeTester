/*
 * cmodel for Pishon
 * @file: DestPost
 * @description: auto generage
 * @note: Copyright (C) 2021-03-29 12:40:57.518312
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
#include <mem/DestPostOpr.h>
#include <mem/DestPost.h>

void DestPost(tPktInfo *PI, uint8_t MsgIgr2Adm) {
	uint8_t tmpVlanPortMask = 0;
	uint8_t tmpLagFwdBmp13 = 0;
	uint8_t tmpLagFwdBmp25 = 0;
	uint8_t tmpLagFwdBmp2 = 0;
	uint8_t tmpLagFwdBmp3 = 0;
	uint8_t tmpLagFwdBmp6 = 0;
	uint8_t tmpIndex = 0;
	uint8_t tmpLagFwdBmp31 = 0;
	uint8_t tmpFwdingBmp = 0;
	uint8_t tmpLagFwdBmp27 = 0;
	uint8_t tmpLagFwdBmp28 = 0;
	uint8_t tmpLagFwdBmp9 = 0;
	uint8_t tmpLagDestPort = 0;
	uint8_t tmpLagFwdBmp4 = 0;
	uint8_t tmpSelectIdx = 0;
	uint8_t tmpExcpToCpuFlag = 0;
	uint8_t tmpLagFwdBmp18 = 0;
	uint8_t tmpLagFwdBmp26 = 0;
	uint8_t tmpIsUcastLinkAgg = 0;
	uint8_t tmpLagFwdBmp5 = 0;
	uint8_t tmpCpuPktStatsEn = 0;
	uint8_t tmpFlowStatsValid = 0;
	uint8_t tmpAggPtr = 0;
	uint8_t tmpLagFwdBmp15 = 0;
	uint8_t tmpTypeIdx = 0;
	uint8_t tmpUcastLagFwdBmp = 0;
	uint8_t tmpBitmap = 0;
	uint8_t tmpExcpType = 0;
	uint8_t tmpLagFwdBmp0 = 0;
	uint8_t tmpChnlId = 0;
	uint8_t tmpLagFwdBmp16 = 0;
	uint8_t tmpLagFwdBmp1 = 0;
	uint8_t tmpLagFwdBmp12 = 0;
	uint8_t tmpLagFwdBmp29 = 0;
	uint8_t tmpLagFwdBmp8 = 0;
	uint8_t tmpLagFwdBmp24 = 0;
	uint8_t tmpLagFwdBmp7 = 0;
	uint8_t tmpLagFwdBmp21 = 0;
	uint8_t tmpLagFwdBmp17 = 0;
	uint8_t tmpLagFwdBmp10 = 0;
	uint8_t tmpLagFwdBmp19 = 0;
	uint8_t tmpGid = 0;
	uint8_t tmpDestLinkAggId = 0;
	uint8_t tmpExcpPktStatsEn = 0;
	uint8_t tmpLagFwdBmp22 = 0;
	uint8_t tmpLagFwdBmp20 = 0;
	uint8_t tmpByteCnt = 0;
	uint8_t tmpFlowStatsPtr = 0;
	uint8_t tmpLagFwdBmp30 = 0;
	uint8_t tmpFwdBmp = 0;
	uint8_t tmpLagFwdBmp14 = 0;
	uint8_t tmpLagFwdBmp11 = 0;
	uint8_t tmpLagFwdBmp23 = 0;
	uint64_t tmpByteCnt = 0;

	tDsRegLagGrp DsRegLagGrp6ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp6Val = &DsRegLagGrp6ValTmp;
	tDsRegLagPort DsRegLagPort20ValTmp = {0};
	tDsRegLagPort *DsRegLagPort20Val = &DsRegLagPort20ValTmp;
	tDsRegLagGrp DsRegLagGrp20ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp20Val = &DsRegLagGrp20ValTmp;
	tDsRegLagGrp DsRegLagGrp15ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp15Val = &DsRegLagGrp15ValTmp;
	tCtlFwdLog CtlFwdLogTmp = {0};
	tCtlFwdLog *CtlFwdLog = &CtlFwdLogTmp;
	readCtlFwdLog("CtlFwdLog", 0, CtlFwdLog, 0);
	tDsRegLagGrp DsRegLagGrp23ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp23Val = &DsRegLagGrp23ValTmp;
	tDsRegLagGrp DsRegLagGrp27ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp27Val = &DsRegLagGrp27ValTmp;
	tCtlFwdDest CtlFwdDestTmp = {0};
	tCtlFwdDest *CtlFwdDest = &CtlFwdDestTmp;
	readCtlFwdDest("CtlFwdDest", 0, CtlFwdDest, 0);
	tDsRegLagGrp DsRegLagGrp2ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp2Val = &DsRegLagGrp2ValTmp;
	tDsRegLagGrp DsRegLagGrp16ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp16Val = &DsRegLagGrp16ValTmp;
	tDsRegLagPort DsRegLagPort8ValTmp = {0};
	tDsRegLagPort *DsRegLagPort8Val = &DsRegLagPort8ValTmp;
	tDsRegLagPort DsRegLagPort5ValTmp = {0};
	tDsRegLagPort *DsRegLagPort5Val = &DsRegLagPort5ValTmp;
	tCtlFwdPortIsolate CtlFwdPortIsolateTmp = {0};
	tCtlFwdPortIsolate *CtlFwdPortIsolate = &CtlFwdPortIsolateTmp;
	readCtlFwdPortIsolate("CtlFwdPortIsolate", 0, CtlFwdPortIsolate, 0);
	tDsRegLagGrp DsRegLagGrp25ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp25Val = &DsRegLagGrp25ValTmp;
	tDsRegLagPort DsRegLagPort3ValTmp = {0};
	tDsRegLagPort *DsRegLagPort3Val = &DsRegLagPort3ValTmp;
	tDsRegLagPort DsRegLagPort13ValTmp = {0};
	tDsRegLagPort *DsRegLagPort13Val = &DsRegLagPort13ValTmp;
	tDsMemSrcPortEgressMask DsMemSrcPortEgressMaskValTmp = {0};
	tDsMemSrcPortEgressMask *DsMemSrcPortEgressMaskVal = &DsMemSrcPortEgressMaskValTmp;
	tDsRegLagPort DsRegLagPort7ValTmp = {0};
	tDsRegLagPort *DsRegLagPort7Val = &DsRegLagPort7ValTmp;
	tCtlFwdEgressSpan CtlFwdEgressSpanTmp = {0};
	tCtlFwdEgressSpan *CtlFwdEgressSpan = &CtlFwdEgressSpanTmp;
	readCtlFwdEgressSpan("CtlFwdEgressSpan", 0, CtlFwdEgressSpan, 0);
	tDsRegLagGrp DsRegLagGrp22ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp22Val = &DsRegLagGrp22ValTmp;
	tDsMemMcastPort DsMemMcastPortValTmp = {0};
	tDsMemMcastPort *DsMemMcastPortVal = &DsMemMcastPortValTmp;
	tDsRegLagPort DsRegLagPort17ValTmp = {0};
	tDsRegLagPort *DsRegLagPort17Val = &DsRegLagPort17ValTmp;
	tDsRegLagGrp DsRegLagGrp1ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp1Val = &DsRegLagGrp1ValTmp;
	tDsRegLagPort DsRegLagPort25ValTmp = {0};
	tDsRegLagPort *DsRegLagPort25Val = &DsRegLagPort25ValTmp;
	tDsRegLagGrp DsRegLagGrp19ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp19Val = &DsRegLagGrp19ValTmp;
	tDsRegLagPort DsRegLagPort26ValTmp = {0};
	tDsRegLagPort *DsRegLagPort26Val = &DsRegLagPort26ValTmp;
	tDsRegLagGrp DsRegLagGrp9ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp9Val = &DsRegLagGrp9ValTmp;
	tDsRegLagPort DsRegLagPort4ValTmp = {0};
	tDsRegLagPort *DsRegLagPort4Val = &DsRegLagPort4ValTmp;
	tCtlFwdExcp CtlFwdExcpTmp = {0};
	tCtlFwdExcp *CtlFwdExcp = &CtlFwdExcpTmp;
	readCtlFwdExcp("CtlFwdExcp", 0, CtlFwdExcp, 0);
	tCtlFwdMcast CtlFwdMcastTmp = {0};
	tCtlFwdMcast *CtlFwdMcast = &CtlFwdMcastTmp;
	readCtlFwdMcast("CtlFwdMcast", 0, CtlFwdMcast, 0);
	tDsRegLagPort DsRegLagPort30ValTmp = {0};
	tDsRegLagPort *DsRegLagPort30Val = &DsRegLagPort30ValTmp;
	tDsMemTsnEdit DsMemTsnEditValTmp = {0};
	tDsMemTsnEdit *DsMemTsnEditVal = &DsMemTsnEditValTmp;
	tDsRegLagGrp DsRegLagGrp3ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp3Val = &DsRegLagGrp3ValTmp;
	tDsRegLagPort DsRegLagPort12ValTmp = {0};
	tDsRegLagPort *DsRegLagPort12Val = &DsRegLagPort12ValTmp;
	tCtlCpuStats CtlCpuStatsTmp = {0};
	tCtlCpuStats *CtlCpuStats = &CtlCpuStatsTmp;
	readCtlCpuStats("CtlCpuStats", 0, CtlCpuStats, 0);
	tDsRegLagGrp DsRegLagGrp12ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp12Val = &DsRegLagGrp12ValTmp;
	tDsRegLagGrp DsRegLagGrp11ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp11Val = &DsRegLagGrp11ValTmp;
	tDsRegLagGrp DsRegLagGrp0ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp0Val = &DsRegLagGrp0ValTmp;
	tDsRegLagGrp DsRegLagGrp29ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp29Val = &DsRegLagGrp29ValTmp;
	tDsMemCpuStats DsMemCpuStatsValTmp = {0};
	tDsMemCpuStats *DsMemCpuStatsVal = &DsMemCpuStatsValTmp;
	tDsRegLagPort DsRegLagPort18ValTmp = {0};
	tDsRegLagPort *DsRegLagPort18Val = &DsRegLagPort18ValTmp;
	tDsRegLagGrp DsRegLagGrp18ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp18Val = &DsRegLagGrp18ValTmp;
	tDsRegLagPort DsRegLagPort14ValTmp = {0};
	tDsRegLagPort *DsRegLagPort14Val = &DsRegLagPort14ValTmp;
	tDsRegLagGrp DsRegLagGrp26ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp26Val = &DsRegLagGrp26ValTmp;
	tDsRegLagGrp DsRegLagGrp21ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp21Val = &DsRegLagGrp21ValTmp;
	tDsRegLagGrp DsRegLagGrp4ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp4Val = &DsRegLagGrp4ValTmp;
	tCtlFwdEgressFilter CtlFwdEgressFilterTmp = {0};
	tCtlFwdEgressFilter *CtlFwdEgressFilter = &CtlFwdEgressFilterTmp;
	readCtlFwdEgressFilter("CtlFwdEgressFilter", 0, CtlFwdEgressFilter, 0);
	tDsMemTsnSpec DsMemTsnSpecValTmp = {0};
	tDsMemTsnSpec *DsMemTsnSpecVal = &DsMemTsnSpecValTmp;
	tDsRegLagPort DsRegLagPort1ValTmp = {0};
	tDsRegLagPort *DsRegLagPort1Val = &DsRegLagPort1ValTmp;
	tDsRegLagPort DsRegLagPort29ValTmp = {0};
	tDsRegLagPort *DsRegLagPort29Val = &DsRegLagPort29ValTmp;
	tDsRegLagGrp DsRegLagGrp14ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp14Val = &DsRegLagGrp14ValTmp;
	tDsRegLagPort DsRegLagPort19ValTmp = {0};
	tDsRegLagPort *DsRegLagPort19Val = &DsRegLagPort19ValTmp;
	tCtlCommon CtlCommonTmp = {0};
	tCtlCommon *CtlCommon = &CtlCommonTmp;
	readCtlCommon("CtlCommon", 0, CtlCommon, 0);
	tDsRegLagPort DsRegLagPort0ValTmp = {0};
	tDsRegLagPort *DsRegLagPort0Val = &DsRegLagPort0ValTmp;
	tDsRegLagGrp DsRegLagGrp17ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp17Val = &DsRegLagGrp17ValTmp;
	tDsRegLagPort DsRegLagPort11ValTmp = {0};
	tDsRegLagPort *DsRegLagPort11Val = &DsRegLagPort11ValTmp;
	tDsRegLagPort DsRegLagPort21ValTmp = {0};
	tDsRegLagPort *DsRegLagPort21Val = &DsRegLagPort21ValTmp;
	tDsRegLagPort DsRegLagPort10ValTmp = {0};
	tDsRegLagPort *DsRegLagPort10Val = &DsRegLagPort10ValTmp;
	tDsMemVlanPortMask DsMemVlanPortMaskValTmp = {0};
	tDsMemVlanPortMask *DsMemVlanPortMaskVal = &DsMemVlanPortMaskValTmp;
	tDsRegLagPort DsRegLagPort27ValTmp = {0};
	tDsRegLagPort *DsRegLagPort27Val = &DsRegLagPort27ValTmp;
	tDsRegLagGrp DsRegLagGrp7ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp7Val = &DsRegLagGrp7ValTmp;
	tDsRegLagPort DsRegLagPort22ValTmp = {0};
	tDsRegLagPort *DsRegLagPort22Val = &DsRegLagPort22ValTmp;
	tDsRegLagPort DsRegLagPort24ValTmp = {0};
	tDsRegLagPort *DsRegLagPort24Val = &DsRegLagPort24ValTmp;
	tDsMemTsnSplit DsMemTsnSplitValTmp = {0};
	tDsMemTsnSplit *DsMemTsnSplitVal = &DsMemTsnSplitValTmp;
	tDsRegLagGrp DsRegLagGrp13ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp13Val = &DsRegLagGrp13ValTmp;
	tDsRegLagGrp DsRegLagGrp5ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp5Val = &DsRegLagGrp5ValTmp;
	tDsRegLagPort DsRegLagPort2ValTmp = {0};
	tDsRegLagPort *DsRegLagPort2Val = &DsRegLagPort2ValTmp;
	tDsRegLagPort DsRegLagPort9ValTmp = {0};
	tDsRegLagPort *DsRegLagPort9Val = &DsRegLagPort9ValTmp;
	tDsRegDestPortChnlMap DsRegDestPortChnlMapValTmp = {0};
	tDsRegDestPortChnlMap *DsRegDestPortChnlMapVal = &DsRegDestPortChnlMapValTmp;
	tDsRegLagPort DsRegLagPort15ValTmp = {0};
	tDsRegLagPort *DsRegLagPort15Val = &DsRegLagPort15ValTmp;
	tDsRegLagGrp DsRegLagGrp10ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp10Val = &DsRegLagGrp10ValTmp;
	tCtlFwdUnknownFilter CtlFwdUnknownFilterTmp = {0};
	tCtlFwdUnknownFilter *CtlFwdUnknownFilter = &CtlFwdUnknownFilterTmp;
	readCtlFwdUnknownFilter("CtlFwdUnknownFilter", 0, CtlFwdUnknownFilter, 0);
	tDsRegLagPort DsRegLagPort31ValTmp = {0};
	tDsRegLagPort *DsRegLagPort31Val = &DsRegLagPort31ValTmp;
	tDsRegLagPort DsRegLagPort16ValTmp = {0};
	tDsRegLagPort *DsRegLagPort16Val = &DsRegLagPort16ValTmp;
	tDsRegLagGrp DsRegLagGrp8ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp8Val = &DsRegLagGrp8ValTmp;
	tDsRegLagGrp DsRegLagGrp28ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp28Val = &DsRegLagGrp28ValTmp;
	tDsRegLagGrp DsRegLagGrp24ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp24Val = &DsRegLagGrp24ValTmp;
	tDsRegLagPort DsRegLagPort23ValTmp = {0};
	tDsRegLagPort *DsRegLagPort23Val = &DsRegLagPort23ValTmp;
	tDsRegLagGrp DsRegLagGrp31ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp31Val = &DsRegLagGrp31ValTmp;
	tDsRegLagPort DsRegLagPort6ValTmp = {0};
	tDsRegLagPort *DsRegLagPort6Val = &DsRegLagPort6ValTmp;
	tDsRegLagGrp DsRegLagGrp30ValTmp = {0};
	tDsRegLagGrp *DsRegLagGrp30Val = &DsRegLagGrp30ValTmp;
	tDsRegLagPort DsRegLagPort28ValTmp = {0};
	tDsRegLagPort *DsRegLagPort28Val = &DsRegLagPort28ValTmp;

    // Ingress Vlan Filtering
    rpcRdMem("DsMemVlanPortMask", PI->vlanId, DsMemVlanPortMaskVal);
    if( PI->ingressFilteringEn && ! GET_BITS(DsMemVlanPortMaskVal->portMask, PI->srcPort, PI->srcPort) ) {
        PI->discard              = PI->discard | 1;
        PI->vlanDiscard   = 1;
    }
    // Egress Vlan Filtering
    rpcRdMem("DsMemSrcPortEgressMask", PI->srcPort, DsMemSrcPortEgressMaskVal);
    if( ((PI->vlanId < CtlFwdPortIsolate->vlanId) || CtlFwdPortIsolate->forcePortEgressMask)
        && !PI->routingEn ) {
        PI->fwdBitmap   = DsMemSrcPortEgressMaskVal->portEgressMask;
    } else {
        PI->fwdBitmap   = 0xff;
    }
    PI->egrPortFilted  = PI->fwdBitmap == 0;
    // Intial FwdBitmap
    tmpVlanPortMask = DsMemVlanPortMaskVal->portMask | (~CtlFwdEgressFilter->egrFilteringEn);
    if( (PI->opCode != OP_CODE_MCAST) && !PI->routingEn ) {
        PI->fwdBitmap = PI->fwdBitmap & tmpVlanPortMask;
    }
    PI->egrVlanFilted = PI->fwdBitmap == 0;
    // Get tmpFwdingBmp
    tmpFwdingBmp       = 0;
    if( PI->opCode == OP_CODE_UCAST || PI->opCode == OP_CODE_NAT ) {
        if( GET_BITS(PI->destMap, 10, 10) == 1 ) {             // Dest is LAG
            tmpIsUcastLinkAgg      = 1;
            tmpDestLinkAggId  = PI->destMap;
            tmpFwdingBmp     = 0;
        } else {
            tmpFwdingBmp     = 1 << PI->destMap;
        }
    } else if( PI->opCode == OP_CODE_MCAST ) {
        tmpGid          = PI->destMap;
        rpcRdMem("DsMemMcastPort", tmpGid, DsMemMcastPortVal);
        tmpFwdingBmp         = DsMemMcastPortVal->portMask;
        if( DsMemMcastPortVal->applyVlanMask ) {
            tmpFwdingBmp     = ( (~CtlFwdMcast->mcFilteringEn | tmpVlanPortMask) & tmpFwdingBmp );
        }
        if( CtlFwdMcast->mcastExcludeSrc ) 
 GET_BITS(tmpFwdingBmp, PI->srcPort, PI->srcPort) = 0;
        // For TSN split stream, the process table shall config as MCAST
        if( PI->isTsn ) {
            rpcRdMem("DsMemTsnSplit", PI->tsnStreamId, DsMemTsnSplitVal);
            tmpFwdingBmp     = DsMemTsnSplitVal->destBmp;
        }
    } else {    // Broadcast
        tmpFwdingBmp         = 0xff;
    }
        tmpLagFwdBmp0      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 0, DsRegLagGrp0Val);
        if ( ((tmpLagFwdBmp0 & DsRegLagGrp0Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (0 == tmpDestLinkAggId)) ) && DsRegLagGrp0Val->linkNumber > 0 ) {
            tmpLagFwdBmp0 &= (~DsRegLagGrp0Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp0Val->linkNumber;
            tmpAggPtr = ((uint64_t)0<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort0Val);
            tmpLagDestPort = DsRegLagPort0Val->destPort;
 GET_BITS(tmpLagFwdBmp0, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (0 == PI->linkAggId) && DsRegLagGrp0Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp0 &= ~DsRegLagGrp0Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (0 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp0;
        }
        tmpFwdBmp &= tmpLagFwdBmp0;
        tmpLagFwdBmp1      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 1, DsRegLagGrp1Val);
        if ( ((tmpLagFwdBmp1 & DsRegLagGrp1Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (1 == tmpDestLinkAggId)) ) && DsRegLagGrp1Val->linkNumber > 0 ) {
            tmpLagFwdBmp1 &= (~DsRegLagGrp1Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp1Val->linkNumber;
            tmpAggPtr = ((uint64_t)1<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort1Val);
            tmpLagDestPort = DsRegLagPort1Val->destPort;
 GET_BITS(tmpLagFwdBmp1, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (1 == PI->linkAggId) && DsRegLagGrp1Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp1 &= ~DsRegLagGrp1Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (1 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp1;
        }
        tmpFwdBmp &= tmpLagFwdBmp1;
        tmpLagFwdBmp2      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 2, DsRegLagGrp2Val);
        if ( ((tmpLagFwdBmp2 & DsRegLagGrp2Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (2 == tmpDestLinkAggId)) ) && DsRegLagGrp2Val->linkNumber > 0 ) {
            tmpLagFwdBmp2 &= (~DsRegLagGrp2Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp2Val->linkNumber;
            tmpAggPtr = ((uint64_t)2<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort2Val);
            tmpLagDestPort = DsRegLagPort2Val->destPort;
 GET_BITS(tmpLagFwdBmp2, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (2 == PI->linkAggId) && DsRegLagGrp2Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp2 &= ~DsRegLagGrp2Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (2 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp2;
        }
        tmpFwdBmp &= tmpLagFwdBmp2;
        tmpLagFwdBmp3      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 3, DsRegLagGrp3Val);
        if ( ((tmpLagFwdBmp3 & DsRegLagGrp3Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (3 == tmpDestLinkAggId)) ) && DsRegLagGrp3Val->linkNumber > 0 ) {
            tmpLagFwdBmp3 &= (~DsRegLagGrp3Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp3Val->linkNumber;
            tmpAggPtr = ((uint64_t)3<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort3Val);
            tmpLagDestPort = DsRegLagPort3Val->destPort;
 GET_BITS(tmpLagFwdBmp3, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (3 == PI->linkAggId) && DsRegLagGrp3Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp3 &= ~DsRegLagGrp3Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (3 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp3;
        }
        tmpFwdBmp &= tmpLagFwdBmp3;
        tmpLagFwdBmp4      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 4, DsRegLagGrp4Val);
        if ( ((tmpLagFwdBmp4 & DsRegLagGrp4Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (4 == tmpDestLinkAggId)) ) && DsRegLagGrp4Val->linkNumber > 0 ) {
            tmpLagFwdBmp4 &= (~DsRegLagGrp4Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp4Val->linkNumber;
            tmpAggPtr = ((uint64_t)4<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort4Val);
            tmpLagDestPort = DsRegLagPort4Val->destPort;
 GET_BITS(tmpLagFwdBmp4, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (4 == PI->linkAggId) && DsRegLagGrp4Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp4 &= ~DsRegLagGrp4Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (4 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp4;
        }
        tmpFwdBmp &= tmpLagFwdBmp4;
        tmpLagFwdBmp5      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 5, DsRegLagGrp5Val);
        if ( ((tmpLagFwdBmp5 & DsRegLagGrp5Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (5 == tmpDestLinkAggId)) ) && DsRegLagGrp5Val->linkNumber > 0 ) {
            tmpLagFwdBmp5 &= (~DsRegLagGrp5Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp5Val->linkNumber;
            tmpAggPtr = ((uint64_t)5<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort5Val);
            tmpLagDestPort = DsRegLagPort5Val->destPort;
 GET_BITS(tmpLagFwdBmp5, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (5 == PI->linkAggId) && DsRegLagGrp5Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp5 &= ~DsRegLagGrp5Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (5 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp5;
        }
        tmpFwdBmp &= tmpLagFwdBmp5;
        tmpLagFwdBmp6      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 6, DsRegLagGrp6Val);
        if ( ((tmpLagFwdBmp6 & DsRegLagGrp6Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (6 == tmpDestLinkAggId)) ) && DsRegLagGrp6Val->linkNumber > 0 ) {
            tmpLagFwdBmp6 &= (~DsRegLagGrp6Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp6Val->linkNumber;
            tmpAggPtr = ((uint64_t)6<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort6Val);
            tmpLagDestPort = DsRegLagPort6Val->destPort;
 GET_BITS(tmpLagFwdBmp6, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (6 == PI->linkAggId) && DsRegLagGrp6Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp6 &= ~DsRegLagGrp6Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (6 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp6;
        }
        tmpFwdBmp &= tmpLagFwdBmp6;
        tmpLagFwdBmp7      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 7, DsRegLagGrp7Val);
        if ( ((tmpLagFwdBmp7 & DsRegLagGrp7Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (7 == tmpDestLinkAggId)) ) && DsRegLagGrp7Val->linkNumber > 0 ) {
            tmpLagFwdBmp7 &= (~DsRegLagGrp7Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp7Val->linkNumber;
            tmpAggPtr = ((uint64_t)7<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort7Val);
            tmpLagDestPort = DsRegLagPort7Val->destPort;
 GET_BITS(tmpLagFwdBmp7, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (7 == PI->linkAggId) && DsRegLagGrp7Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp7 &= ~DsRegLagGrp7Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (7 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp7;
        }
        tmpFwdBmp &= tmpLagFwdBmp7;
        tmpLagFwdBmp8      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 8, DsRegLagGrp8Val);
        if ( ((tmpLagFwdBmp8 & DsRegLagGrp8Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (8 == tmpDestLinkAggId)) ) && DsRegLagGrp8Val->linkNumber > 0 ) {
            tmpLagFwdBmp8 &= (~DsRegLagGrp8Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp8Val->linkNumber;
            tmpAggPtr = ((uint64_t)8<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort8Val);
            tmpLagDestPort = DsRegLagPort8Val->destPort;
 GET_BITS(tmpLagFwdBmp8, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (8 == PI->linkAggId) && DsRegLagGrp8Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp8 &= ~DsRegLagGrp8Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (8 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp8;
        }
        tmpFwdBmp &= tmpLagFwdBmp8;
        tmpLagFwdBmp9      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 9, DsRegLagGrp9Val);
        if ( ((tmpLagFwdBmp9 & DsRegLagGrp9Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (9 == tmpDestLinkAggId)) ) && DsRegLagGrp9Val->linkNumber > 0 ) {
            tmpLagFwdBmp9 &= (~DsRegLagGrp9Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp9Val->linkNumber;
            tmpAggPtr = ((uint64_t)9<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort9Val);
            tmpLagDestPort = DsRegLagPort9Val->destPort;
 GET_BITS(tmpLagFwdBmp9, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (9 == PI->linkAggId) && DsRegLagGrp9Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp9 &= ~DsRegLagGrp9Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (9 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp9;
        }
        tmpFwdBmp &= tmpLagFwdBmp9;
        tmpLagFwdBmp10      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 10, DsRegLagGrp10Val);
        if ( ((tmpLagFwdBmp10 & DsRegLagGrp10Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (10 == tmpDestLinkAggId)) ) && DsRegLagGrp10Val->linkNumber > 0 ) {
            tmpLagFwdBmp10 &= (~DsRegLagGrp10Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp10Val->linkNumber;
            tmpAggPtr = ((uint64_t)10<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort10Val);
            tmpLagDestPort = DsRegLagPort10Val->destPort;
 GET_BITS(tmpLagFwdBmp10, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (10 == PI->linkAggId) && DsRegLagGrp10Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp10 &= ~DsRegLagGrp10Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (10 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp10;
        }
        tmpFwdBmp &= tmpLagFwdBmp10;
        tmpLagFwdBmp11      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 11, DsRegLagGrp11Val);
        if ( ((tmpLagFwdBmp11 & DsRegLagGrp11Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (11 == tmpDestLinkAggId)) ) && DsRegLagGrp11Val->linkNumber > 0 ) {
            tmpLagFwdBmp11 &= (~DsRegLagGrp11Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp11Val->linkNumber;
            tmpAggPtr = ((uint64_t)11<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort11Val);
            tmpLagDestPort = DsRegLagPort11Val->destPort;
 GET_BITS(tmpLagFwdBmp11, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (11 == PI->linkAggId) && DsRegLagGrp11Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp11 &= ~DsRegLagGrp11Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (11 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp11;
        }
        tmpFwdBmp &= tmpLagFwdBmp11;
        tmpLagFwdBmp12      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 12, DsRegLagGrp12Val);
        if ( ((tmpLagFwdBmp12 & DsRegLagGrp12Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (12 == tmpDestLinkAggId)) ) && DsRegLagGrp12Val->linkNumber > 0 ) {
            tmpLagFwdBmp12 &= (~DsRegLagGrp12Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp12Val->linkNumber;
            tmpAggPtr = ((uint64_t)12<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort12Val);
            tmpLagDestPort = DsRegLagPort12Val->destPort;
 GET_BITS(tmpLagFwdBmp12, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (12 == PI->linkAggId) && DsRegLagGrp12Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp12 &= ~DsRegLagGrp12Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (12 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp12;
        }
        tmpFwdBmp &= tmpLagFwdBmp12;
        tmpLagFwdBmp13      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 13, DsRegLagGrp13Val);
        if ( ((tmpLagFwdBmp13 & DsRegLagGrp13Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (13 == tmpDestLinkAggId)) ) && DsRegLagGrp13Val->linkNumber > 0 ) {
            tmpLagFwdBmp13 &= (~DsRegLagGrp13Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp13Val->linkNumber;
            tmpAggPtr = ((uint64_t)13<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort13Val);
            tmpLagDestPort = DsRegLagPort13Val->destPort;
 GET_BITS(tmpLagFwdBmp13, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (13 == PI->linkAggId) && DsRegLagGrp13Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp13 &= ~DsRegLagGrp13Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (13 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp13;
        }
        tmpFwdBmp &= tmpLagFwdBmp13;
        tmpLagFwdBmp14      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 14, DsRegLagGrp14Val);
        if ( ((tmpLagFwdBmp14 & DsRegLagGrp14Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (14 == tmpDestLinkAggId)) ) && DsRegLagGrp14Val->linkNumber > 0 ) {
            tmpLagFwdBmp14 &= (~DsRegLagGrp14Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp14Val->linkNumber;
            tmpAggPtr = ((uint64_t)14<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort14Val);
            tmpLagDestPort = DsRegLagPort14Val->destPort;
 GET_BITS(tmpLagFwdBmp14, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (14 == PI->linkAggId) && DsRegLagGrp14Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp14 &= ~DsRegLagGrp14Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (14 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp14;
        }
        tmpFwdBmp &= tmpLagFwdBmp14;
        tmpLagFwdBmp15      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 15, DsRegLagGrp15Val);
        if ( ((tmpLagFwdBmp15 & DsRegLagGrp15Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (15 == tmpDestLinkAggId)) ) && DsRegLagGrp15Val->linkNumber > 0 ) {
            tmpLagFwdBmp15 &= (~DsRegLagGrp15Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp15Val->linkNumber;
            tmpAggPtr = ((uint64_t)15<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort15Val);
            tmpLagDestPort = DsRegLagPort15Val->destPort;
 GET_BITS(tmpLagFwdBmp15, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (15 == PI->linkAggId) && DsRegLagGrp15Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp15 &= ~DsRegLagGrp15Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (15 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp15;
        }
        tmpFwdBmp &= tmpLagFwdBmp15;
        tmpLagFwdBmp16      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 16, DsRegLagGrp16Val);
        if ( ((tmpLagFwdBmp16 & DsRegLagGrp16Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (16 == tmpDestLinkAggId)) ) && DsRegLagGrp16Val->linkNumber > 0 ) {
            tmpLagFwdBmp16 &= (~DsRegLagGrp16Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp16Val->linkNumber;
            tmpAggPtr = ((uint64_t)16<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort16Val);
            tmpLagDestPort = DsRegLagPort16Val->destPort;
 GET_BITS(tmpLagFwdBmp16, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (16 == PI->linkAggId) && DsRegLagGrp16Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp16 &= ~DsRegLagGrp16Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (16 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp16;
        }
        tmpFwdBmp &= tmpLagFwdBmp16;
        tmpLagFwdBmp17      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 17, DsRegLagGrp17Val);
        if ( ((tmpLagFwdBmp17 & DsRegLagGrp17Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (17 == tmpDestLinkAggId)) ) && DsRegLagGrp17Val->linkNumber > 0 ) {
            tmpLagFwdBmp17 &= (~DsRegLagGrp17Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp17Val->linkNumber;
            tmpAggPtr = ((uint64_t)17<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort17Val);
            tmpLagDestPort = DsRegLagPort17Val->destPort;
 GET_BITS(tmpLagFwdBmp17, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (17 == PI->linkAggId) && DsRegLagGrp17Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp17 &= ~DsRegLagGrp17Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (17 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp17;
        }
        tmpFwdBmp &= tmpLagFwdBmp17;
        tmpLagFwdBmp18      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 18, DsRegLagGrp18Val);
        if ( ((tmpLagFwdBmp18 & DsRegLagGrp18Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (18 == tmpDestLinkAggId)) ) && DsRegLagGrp18Val->linkNumber > 0 ) {
            tmpLagFwdBmp18 &= (~DsRegLagGrp18Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp18Val->linkNumber;
            tmpAggPtr = ((uint64_t)18<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort18Val);
            tmpLagDestPort = DsRegLagPort18Val->destPort;
 GET_BITS(tmpLagFwdBmp18, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (18 == PI->linkAggId) && DsRegLagGrp18Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp18 &= ~DsRegLagGrp18Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (18 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp18;
        }
        tmpFwdBmp &= tmpLagFwdBmp18;
        tmpLagFwdBmp19      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 19, DsRegLagGrp19Val);
        if ( ((tmpLagFwdBmp19 & DsRegLagGrp19Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (19 == tmpDestLinkAggId)) ) && DsRegLagGrp19Val->linkNumber > 0 ) {
            tmpLagFwdBmp19 &= (~DsRegLagGrp19Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp19Val->linkNumber;
            tmpAggPtr = ((uint64_t)19<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort19Val);
            tmpLagDestPort = DsRegLagPort19Val->destPort;
 GET_BITS(tmpLagFwdBmp19, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (19 == PI->linkAggId) && DsRegLagGrp19Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp19 &= ~DsRegLagGrp19Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (19 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp19;
        }
        tmpFwdBmp &= tmpLagFwdBmp19;
        tmpLagFwdBmp20      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 20, DsRegLagGrp20Val);
        if ( ((tmpLagFwdBmp20 & DsRegLagGrp20Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (20 == tmpDestLinkAggId)) ) && DsRegLagGrp20Val->linkNumber > 0 ) {
            tmpLagFwdBmp20 &= (~DsRegLagGrp20Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp20Val->linkNumber;
            tmpAggPtr = ((uint64_t)20<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort20Val);
            tmpLagDestPort = DsRegLagPort20Val->destPort;
 GET_BITS(tmpLagFwdBmp20, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (20 == PI->linkAggId) && DsRegLagGrp20Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp20 &= ~DsRegLagGrp20Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (20 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp20;
        }
        tmpFwdBmp &= tmpLagFwdBmp20;
        tmpLagFwdBmp21      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 21, DsRegLagGrp21Val);
        if ( ((tmpLagFwdBmp21 & DsRegLagGrp21Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (21 == tmpDestLinkAggId)) ) && DsRegLagGrp21Val->linkNumber > 0 ) {
            tmpLagFwdBmp21 &= (~DsRegLagGrp21Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp21Val->linkNumber;
            tmpAggPtr = ((uint64_t)21<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort21Val);
            tmpLagDestPort = DsRegLagPort21Val->destPort;
 GET_BITS(tmpLagFwdBmp21, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (21 == PI->linkAggId) && DsRegLagGrp21Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp21 &= ~DsRegLagGrp21Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (21 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp21;
        }
        tmpFwdBmp &= tmpLagFwdBmp21;
        tmpLagFwdBmp22      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 22, DsRegLagGrp22Val);
        if ( ((tmpLagFwdBmp22 & DsRegLagGrp22Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (22 == tmpDestLinkAggId)) ) && DsRegLagGrp22Val->linkNumber > 0 ) {
            tmpLagFwdBmp22 &= (~DsRegLagGrp22Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp22Val->linkNumber;
            tmpAggPtr = ((uint64_t)22<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort22Val);
            tmpLagDestPort = DsRegLagPort22Val->destPort;
 GET_BITS(tmpLagFwdBmp22, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (22 == PI->linkAggId) && DsRegLagGrp22Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp22 &= ~DsRegLagGrp22Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (22 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp22;
        }
        tmpFwdBmp &= tmpLagFwdBmp22;
        tmpLagFwdBmp23      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 23, DsRegLagGrp23Val);
        if ( ((tmpLagFwdBmp23 & DsRegLagGrp23Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (23 == tmpDestLinkAggId)) ) && DsRegLagGrp23Val->linkNumber > 0 ) {
            tmpLagFwdBmp23 &= (~DsRegLagGrp23Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp23Val->linkNumber;
            tmpAggPtr = ((uint64_t)23<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort23Val);
            tmpLagDestPort = DsRegLagPort23Val->destPort;
 GET_BITS(tmpLagFwdBmp23, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (23 == PI->linkAggId) && DsRegLagGrp23Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp23 &= ~DsRegLagGrp23Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (23 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp23;
        }
        tmpFwdBmp &= tmpLagFwdBmp23;
        tmpLagFwdBmp24      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 24, DsRegLagGrp24Val);
        if ( ((tmpLagFwdBmp24 & DsRegLagGrp24Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (24 == tmpDestLinkAggId)) ) && DsRegLagGrp24Val->linkNumber > 0 ) {
            tmpLagFwdBmp24 &= (~DsRegLagGrp24Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp24Val->linkNumber;
            tmpAggPtr = ((uint64_t)24<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort24Val);
            tmpLagDestPort = DsRegLagPort24Val->destPort;
 GET_BITS(tmpLagFwdBmp24, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (24 == PI->linkAggId) && DsRegLagGrp24Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp24 &= ~DsRegLagGrp24Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (24 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp24;
        }
        tmpFwdBmp &= tmpLagFwdBmp24;
        tmpLagFwdBmp25      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 25, DsRegLagGrp25Val);
        if ( ((tmpLagFwdBmp25 & DsRegLagGrp25Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (25 == tmpDestLinkAggId)) ) && DsRegLagGrp25Val->linkNumber > 0 ) {
            tmpLagFwdBmp25 &= (~DsRegLagGrp25Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp25Val->linkNumber;
            tmpAggPtr = ((uint64_t)25<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort25Val);
            tmpLagDestPort = DsRegLagPort25Val->destPort;
 GET_BITS(tmpLagFwdBmp25, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (25 == PI->linkAggId) && DsRegLagGrp25Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp25 &= ~DsRegLagGrp25Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (25 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp25;
        }
        tmpFwdBmp &= tmpLagFwdBmp25;
        tmpLagFwdBmp26      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 26, DsRegLagGrp26Val);
        if ( ((tmpLagFwdBmp26 & DsRegLagGrp26Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (26 == tmpDestLinkAggId)) ) && DsRegLagGrp26Val->linkNumber > 0 ) {
            tmpLagFwdBmp26 &= (~DsRegLagGrp26Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp26Val->linkNumber;
            tmpAggPtr = ((uint64_t)26<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort26Val);
            tmpLagDestPort = DsRegLagPort26Val->destPort;
 GET_BITS(tmpLagFwdBmp26, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (26 == PI->linkAggId) && DsRegLagGrp26Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp26 &= ~DsRegLagGrp26Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (26 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp26;
        }
        tmpFwdBmp &= tmpLagFwdBmp26;
        tmpLagFwdBmp27      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 27, DsRegLagGrp27Val);
        if ( ((tmpLagFwdBmp27 & DsRegLagGrp27Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (27 == tmpDestLinkAggId)) ) && DsRegLagGrp27Val->linkNumber > 0 ) {
            tmpLagFwdBmp27 &= (~DsRegLagGrp27Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp27Val->linkNumber;
            tmpAggPtr = ((uint64_t)27<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort27Val);
            tmpLagDestPort = DsRegLagPort27Val->destPort;
 GET_BITS(tmpLagFwdBmp27, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (27 == PI->linkAggId) && DsRegLagGrp27Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp27 &= ~DsRegLagGrp27Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (27 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp27;
        }
        tmpFwdBmp &= tmpLagFwdBmp27;
        tmpLagFwdBmp28      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 28, DsRegLagGrp28Val);
        if ( ((tmpLagFwdBmp28 & DsRegLagGrp28Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (28 == tmpDestLinkAggId)) ) && DsRegLagGrp28Val->linkNumber > 0 ) {
            tmpLagFwdBmp28 &= (~DsRegLagGrp28Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp28Val->linkNumber;
            tmpAggPtr = ((uint64_t)28<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort28Val);
            tmpLagDestPort = DsRegLagPort28Val->destPort;
 GET_BITS(tmpLagFwdBmp28, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (28 == PI->linkAggId) && DsRegLagGrp28Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp28 &= ~DsRegLagGrp28Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (28 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp28;
        }
        tmpFwdBmp &= tmpLagFwdBmp28;
        tmpLagFwdBmp29      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 29, DsRegLagGrp29Val);
        if ( ((tmpLagFwdBmp29 & DsRegLagGrp29Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (29 == tmpDestLinkAggId)) ) && DsRegLagGrp29Val->linkNumber > 0 ) {
            tmpLagFwdBmp29 &= (~DsRegLagGrp29Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp29Val->linkNumber;
            tmpAggPtr = ((uint64_t)29<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort29Val);
            tmpLagDestPort = DsRegLagPort29Val->destPort;
 GET_BITS(tmpLagFwdBmp29, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (29 == PI->linkAggId) && DsRegLagGrp29Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp29 &= ~DsRegLagGrp29Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (29 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp29;
        }
        tmpFwdBmp &= tmpLagFwdBmp29;
        tmpLagFwdBmp30      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 30, DsRegLagGrp30Val);
        if ( ((tmpLagFwdBmp30 & DsRegLagGrp30Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (30 == tmpDestLinkAggId)) ) && DsRegLagGrp30Val->linkNumber > 0 ) {
            tmpLagFwdBmp30 &= (~DsRegLagGrp30Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp30Val->linkNumber;
            tmpAggPtr = ((uint64_t)30<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort30Val);
            tmpLagDestPort = DsRegLagPort30Val->destPort;
            tmpLagFwdBmp30 |= (1 << tmpLagDestPort);
        }
        if ( PI->isLinkAggMbr && (30 == PI->linkAggId) && DsRegLagGrp30Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp30 &= ~DsRegLagGrp30Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (30 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp30;
        }
        tmpFwdBmp &= tmpLagFwdBmp30;
        tmpLagFwdBmp31      = tmpFwdingBmp;
        rpcRdMem("DsRegLagGrp", 31, DsRegLagGrp31Val);
        if ( ((tmpLagFwdBmp31 & DsRegLagGrp31Val->memberBitmap) != 0 || 
        (tmpIsUcastLinkAgg && (31 == tmpDestLinkAggId)) ) && DsRegLagGrp31Val->linkNumber > 0 ) {
            tmpLagFwdBmp31 &= (~DsRegLagGrp31Val->memberBitmap);
            tmpSelectIdx = PI->linkAggHash % DsRegLagGrp31Val->linkNumber;
            tmpAggPtr = ((uint64_t)31<<8) + ( tmpSelectIdx);
            rpcRdMem("DsRegLagPort", tmpAggPtr, DsRegLagPort31Val);
            tmpLagDestPort = DsRegLagPort31Val->destPort;
 GET_BITS(tmpLagFwdBmp31, tmpLagDestPort, tmpLagDestPort) = 1;
        }
        if ( PI->isLinkAggMbr && (31 == PI->linkAggId) && DsRegLagGrp31Val->srcMatchDiscard &&
        !PI->routingEn && !PI->forceDest ) {
            tmpLagFwdBmp31 &= ~DsRegLagGrp31Val->memberBitmap;
        }
        if ( tmpIsUcastLinkAgg && (31 == tmpDestLinkAggId)) {
            tmpUcastLagFwdBmp     = tmpLagFwdBmp31;
        }
        tmpFwdBmp &= tmpLagFwdBmp31;
    if ( !tmpIsUcastLinkAgg ) {
        tmpFwdingBmp &= tmpFwdBmp;
    } else {
        tmpFwdingBmp  = tmpUcastLagFwdBmp;
    }
    PI->lagFilted  = tmpFwdingBmp == 0;
    // Discard and force destination
    if( PI->forceDest ) {
        PI->fwdBitmap   = tmpFwdingBmp;
    } else {
        if( PI->discard && !PI->fromRemoteSpan ) {
            PI->fwdBitmap = 0;
        } else {
            PI->fwdBitmap = PI->fwdBitmap & tmpFwdingBmp;
        }
    }
    PI->destLostInCfg = PI->fwdBitmap == 0;
    // Unknown egress Filtering
    if( (PI->opCode == OP_CODE_BCAST) && !PI->routingEn ) {
        if( PI->isBcastMac ) {
            PI->fwdBitmap = PI->fwdBitmap & (~CtlFwdUnknownFilter->bcastFilter);
        } else if( PI->isMcastMac ) {
            PI->fwdBitmap = PI->fwdBitmap & (~CtlFwdUnknownFilter->unknownMcastFilter);
            PI->mcastFlood = 1;
        } else {
            PI->fwdBitmap = PI->fwdBitmap & (~CtlFwdUnknownFilter->unknownUcastFilter);
            PI->ucastFlood = 1;
        }
    }
    // To CPU packet
    tmpExcpToCpuFlag    = PI->exception && (CtlFwdExcp->excepToCpu & (1 << PI->excpType));
    if( (tmpExcpToCpuFlag || PI->copyToCpu) && !PI->fromRemoteSpan ) {
        SET_BITS(PI->fwdBitmap, CtlCommon->cpuPortNo, CtlCommon->cpuPortNo, (1));
        PI->criticalPacket          = 1;
        PI->firstDecideToCpu          = 1;
    }
    PI->ptpValid = PI->isPtp && PI->ptpEn;
    if(PI->ptpValid && PI->srcPort != CtlCommon->cpuPortNo && PI->srcPort != 6 ) {
        if( (CtlFwdDest->redirPtpType & (1 << PI->ptpType)) != 0 ) {
            PI->fwdBitmap     = 0;
            PI->redirPtp      = 1;
        }
        if((CtlFwdDest->ptpSnifferType & (1 << PI->ptpType)) != 0) {
            SET_BITS(PI->fwdBitmap, CtlCommon->cpuPortNo, CtlCommon->cpuPortNo, (1));
            PI->criticalPacket    = 1;
            PI->firstDecideToCpu  = 1;
            PI->ptp2Cpu           = 1;
        }
    } 
    // SPAN bitmap
    SET_BITS(PI->fwdBitmapW1, 0, 0, (PI->ingressL2SpanEn));
    SET_BITS(PI->fwdBitmapW1, 1, 1, ((PI->fwdBitmap & CtlFwdEgressSpan->l2EgrSpanEn) != 0));
    SET_BITS(PI->fwdBitmapW1, 2, 2, (PI->l3SpanEn));
    SET_BITS(PI->fwdBitmapW1, 3, 3, (PI->aclQosLogEn));
    SET_BITS(PI->fwdBitmapW1, 4, 4, (PI->igrFlowSpan));
    // Event logger and Stats
    tmpCpuPktStatsEn  = GET_BITS(CtlCpuStats->statsEn, PI->cpuPktType, PI->cpuPktType) && PI->copyToCpu && !PI->fromRemoteSpan;
    tmpExcpType = 0x10 + PI->excpType;
    tmpExcpPktStatsEn = GET_BITS(CtlCpuStats->statsEn, tmpExcpType, tmpExcpType) && PI->exception && !PI->fromRemoteSpan;
    tmpFlowStatsPtr     = PI->flowStatsPtr;
    tmpFlowStatsValid         = PI->flowStatsValid;
    if( !PI->flowStatsValid && (tmpCpuPktStatsEn || tmpExcpPktStatsEn) ) {
        tmpTypeIdx = tmpCpuPktStatsEn ? ((uint64_t)0<<8) + ( PI->cpuPktType) : tmpExcpType;
        tmpIndex = ((uint64_t)PI->srcPort<<5) + ( GET_BITS(tmpTypeIdx, 0, 4));
        rpcRdMem("DsMemCpuStats", tmpIndex, DsMemCpuStatsVal);
        DsMemCpuStatsVal->pktCnt += 1;
        tmpByteCnt = ((uint64_t)DsMemCpuStatsVal->byteCntHi<<8) + ( DsMemCpuStatsVal->byteCnt);
        tmpByteCnt += PI->pktLength;
        DsMemCpuStatsVal->byteCnt = tmpByteCnt;
        DsMemCpuStatsVal->byteCntHi = tmpByteCnt >> 32;
        rpcSetMem( "DsMemCpuStats", tmpIndex , DsMemCpuStatsVal, sizeof(tDsMemCpuStats) );
    }
    // Remap destPort to channel ID
    tmpBitmap           = 0;
        if( GET_BITS(PI->fwdBitmap, 0, 0) ) {
            rpcRdMem("DsRegDestPortChnlMap", 0, DsRegDestPortChnlMapVal);
            tmpChnlId = DsRegDestPortChnlMapVal->channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
        if( GET_BITS(PI->fwdBitmap, 1, 1) ) {
            rpcRdMem("DsRegDestPortChnlMap", 1, DsRegDestPortChnlMapVal);
            tmpChnlId = DsRegDestPortChnlMapVal->channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
        if( GET_BITS(PI->fwdBitmap, 2, 2) ) {
            rpcRdMem("DsRegDestPortChnlMap", 2, DsRegDestPortChnlMapVal);
            tmpChnlId = DsRegDestPortChnlMapVal->channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
        if( GET_BITS(PI->fwdBitmap, 3, 3) ) {
            rpcRdMem("DsRegDestPortChnlMap", 3, DsRegDestPortChnlMapVal);
            tmpChnlId = DsRegDestPortChnlMapVal->channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
        if( GET_BITS(PI->fwdBitmap, 4, 4) ) {
            rpcRdMem("DsRegDestPortChnlMap", 4, DsRegDestPortChnlMapVal);
            tmpChnlId = DsRegDestPortChnlMapVal->channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
        if( GET_BITS(PI->fwdBitmap, 5, 5) ) {
            rpcRdMem("DsRegDestPortChnlMap", 5, DsRegDestPortChnlMapVal);
            tmpChnlId = DsRegDestPortChnlMapVal->channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
        if( GET_BITS(PI->fwdBitmap, 6, 6) ) {
            rpcRdMem("DsRegDestPortChnlMap", 6, DsRegDestPortChnlMapVal);
            tmpChnlId = DsRegDestPortChnlMapVal->channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
        if( GET_BITS(PI->fwdBitmap, 7, 7) ) {
            rpcRdMem("DsRegDestPortChnlMap", 7, DsRegDestPortChnlMapVal);
            tmpChnlId = DsRegDestPortChnlMapVal->channelId;
            tmpBitmap |= (1 << tmpChnlId);
        }
    PI->fwdBitmap        = tmpBitmap & 0xff;
    if( PI->isTsn ) {
        rpcRdMem("DsMemTsnSpec", PI->tsnStreamId, DsMemTsnSpecVal);
        PI->tsnGateId           = DsMemTsnSpecVal->gateId;
        PI->tsnCycleSel         = DsMemTsnSpecVal->cycleSel;
        PI->tsnPrior       = DsMemTsnSpecVal->prior;
        rpcRdMem("DsMemTsnEdit", PI->tsnStreamId, DsMemTsnEditVal);
        PI->addRtag             = !PI->forbidEdit && !PI->rtagValid && DsMemTsnSpecVal->addRtag;
        if (PI->addRtag) {   
            PI->rtagSeq   = DsMemTsnEditVal->genSeqNum;
            DsMemTsnEditVal->genSeqNum  += 1;
            rpcSetMem( "DsMemTsnEdit", PI->tsnStreamId , DsMemTsnEditVal, sizeof(tDsMemTsnEdit) );
        }
    }
    PI->prior  = PI->isTsn ? PI->tsnPrior : PI->prior;
    CtlFwdLog->fwdBitmap = PI->fwdBitmap;
    CtlFwdLog->fwdBitmapW1 = PI->fwdBitmapW1;
    CtlFwdLog->vlanDiscard = PI->vlanDiscard;
    CtlFwdLog->mcastFlood = PI->mcastFlood;
    CtlFwdLog->destMap = PI->destMap;
    CtlFwdLog->opCode = PI->opCode;
    CtlFwdLog->ucastFlood = PI->ucastFlood;
    CtlFwdLog->criticalPacket = PI->criticalPacket;
    CtlFwdLog->forbidEdit = PI->forbidEdit;
    CtlFwdLog->redirPtp = PI->redirPtp;
    CtlFwdLog->egrPortFilted = PI->egrPortFilted;
    CtlFwdLog->egrVlanFilted = PI->egrVlanFilted;
    CtlFwdLog->lagFilted = PI->lagFilted;
    CtlFwdLog->ptpValid = PI->ptpValid;
    CtlFwdLog->ptp2Cpu = PI->ptp2Cpu;
    CtlFwdLog->addRtag = PI->addRtag;
    CtlFwdLog->tsnGateId = PI->tsnGateId;
    CtlFwdLog->tsnCycle = PI->tsnCycle;
    CtlFwdLog->cpuPktType = PI->cpuPktType;
    CtlFwdLog->destLostInCfg = PI->destLostInCfg;
    // Generate MsIgr2Adm
    //MsgIgr2Adm.fwdBitmap[7:0] = PI.fwdBitmap[7:0];
    //MsgIgr2Adm.fwdBitmapW1[5:0] = PI.fwdBitmapW1[5:0];
    //MsgIgr2Adm.pktLength[13:0] = PI.pktLength[13:0];
    //MsgIgr2Adm.nexthopIdx[5:0] = PI.nexthopIdx[5:0];
    //MsgIgr2Adm.firstDecideToCpu = PI.firstDecideToCpu;
    //MsgIgr2Adm.criticalPacket = PI.criticalPacket;
    //MsgIgr2Adm.forceDest = PI.forceDest;
    //MsgIgr2Adm.forbidEdit = PI.forbidEdit;
    //MsgIgr2Adm.removeVlanTag = PI.removeVlanTag;
    //MsgIgr2Adm.replaceCos = PI.replaceCos;
    //MsgIgr2Adm.replaceDscp = PI.replaceDscp;
    //MsgIgr2Adm.excpType[2:0] = PI.excpType[2:0];
    //MsgIgr2Adm.cpuPktType[3:0] = PI.cpuPktType[3:0];
    //MsgIgr2Adm.opCode[2:0] = PI.opCode[2:0];
    //MsgIgr2Adm.stpId[4:0] = PI.stpId[4:0];
    //MsgIgr2Adm.vlanId[11:0] = PI.vlanId[11:0];
    //MsgIgr2Adm.srcPort[2:0] = PI.srcPort[2:0];
    //MsgIgr2Adm.prior[5:0] = PI.prior[5:0];
    //MsgIgr2Adm.routingEn = PI.routingEn;
    //MsgIgr2Adm.l3Offset[5:0] = PI.l3Offset[5:0];
    //MsgIgr2Adm.l4Offset[6:0] = PI.l4Offset[6:0];
    //MsgIgr2Adm.l3Type[3:0] = PI.l3Type[3:0];
    //MsgIgr2Adm.l4Type[3:0] = PI.l4Type[3:0];
    //MsgIgr2Adm.hasInnerHdr = PI.hasInnerHdr;
    //MsgIgr2Adm.isTsn = PI.isTsn;
    //MsgIgr2Adm.tsnGateId[4:0] = PI.tsnGateId[4:0];
    //MsgIgr2Adm.tsnCycleSel[2:0] = PI.tsnCycleSel[2:0];
    //MsgIgr2Adm.addRtag = PI.addRtag;
    //MsgIgr2Adm.rtagSeq[15:0] = PI.rtagSeq[15:0];
    //MsgIgr2Adm.stagValid = PI.stagValid;
    //MsgIgr2Adm.ctagValid = PI.ctagValid;
    //MsgIgr2Adm.ptpValid = PI.ptpValid;
    //MsgIgr2Adm.ethTypeLen[3:0] = PI.ethTypeLen[3:0];
}
