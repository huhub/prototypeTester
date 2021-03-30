/*
 * cmodel for Pishon
 * @file: PacketEdit
 * @description: auto generage
 * @note: Copyright (C) 2021-03-29 12:40:57.594585
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
#include <mem/PacketEditOpr.h>
#include <mem/PacketEdit.h>

void PacketEdit(tPktInfo *PI, uint8_t *glPktNew, uint8_t MsgAdmInfo) {
	uint8_t tmpEgrExcpSignal = 0;
	uint32_t tmpOldIpSa = 0;
	uint32_t tmpFldLenBuf = 0;
	uint64_t tmpToCpuHdrBuf0 = 0;
	uint32_t tmpSVlanBuf0 = 0;
	uint32_t tmpRspanBuf0 = 0;
	uint64_t tmpFldLenBuf = 0;
	uint8_t tmpNewIpChksum = 0;
	uint16_t tmpL4Chksum = 0;
	uint64_t tmpCfNs = 0;
	uint8_t tmpPad = 0;
	uint16_t tmpPktLength = 0;
	uint16_t tmpL3McIdx = 0;
	uint8_t tmpAddLen = 0;
	uint16_t tmpFldLenBuf = 0;
	uint32_t tmpCVlanBuf0 = 0;
	uintNone_t tmpToCpuHdrBuf0 = 0;
	uint32_t tmpNewMacSaLo = 0;
	uint8_t tmpMinusLen = 0;
	uintNone_t tmpFldLenBuf = 0;
	uint64_t tmpFromInnerHdrBuf0 = 0;
	uint8_t tmpIdx = 0;
	uint16_t tmpNewMacSaHi = 0;
	uint8_t tmpNewExcpType = 0;
	uint8_t tmpSubIdx = 0;
	uint8_t tmpCos = 0;
	uint16_t tmpNewIpChksum = 0;
	uint8_t tmpOldCos = 0;
	uint16_t tmpL4FinalChksum = 0;
	uint8_t tmpExcpType = 0;
	uint64_t tmpRtagBuf0 = 0;
	uint8_t tmpStpIdx = 0;
	uint8_t tmpPktType = 0;
	uint8_t tmpRtagStart = 0;
	uint8_t tmpNexthopIdx = 0;
	uint8_t tmpVlanOffset = 0;
	uint64_t tmpMacSaBuf0 = 0;
	uint8_t tmpPktLength = 0;
	uint8_t tmpCVlanBuf0 = 0;
	uint16_t tmpTpid = 0;
	uint32_t tmpNewVlanBuf = 0;
	uint8_t tmpSVlanBuf0 = 0;
	uint8_t tmpL3Match = 0;
	uint8_t tmpFldLenBuf = 0;
	uint16_t tmpL4Chksum1 = 0;
	uintNone_t tmpContentBuf = 0;
	uint8_t tmpExcpSubIdx = 0;
	uint8_t tmpCpuTsOp = 0;
	uint32_t tmpTsHeaderBuf0 = 0;
	uint8_t tmpL2Offset = 0;
	uint8_t tmpPtpOffset = 0;
	uintNone_t tmpTsHeaderBuf0 = 0;
	uint8_t tmpStpState = 0;
	uint64_t tmpMacDaBuf0 = 0;
	uint16_t tmpUdpChecksum = 0;
	uint8_t tmpTsUpdSignal = 0;

	tDsMemEgrExcpStats DsMemEgrExcpStatsValTmp = {0};
	tDsMemEgrExcpStats *DsMemEgrExcpStatsVal = &DsMemEgrExcpStatsValTmp;
	tCtlEgrExcpDestPort CtlEgrExcpDestPortTmp = {0};
	tCtlEgrExcpDestPort *CtlEgrExcpDestPort = &CtlEgrExcpDestPortTmp;
	readCtlEgrExcpDestPort("CtlEgrExcpDestPort", 0, CtlEgrExcpDestPort, 0);
	tDsMemDestVlan DsMemDestVlanValTmp = {0};
	tDsMemDestVlan *DsMemDestVlanVal = &DsMemDestVlanValTmp;
	tDsMemDestStpState DsMemDestStpStateValTmp = {0};
	tDsMemDestStpState *DsMemDestStpStateVal = &DsMemDestStpStateValTmp;
	tDsMemEgrSrcPort DsMemEgrSrcPortValTmp = {0};
	tDsMemEgrSrcPort *DsMemEgrSrcPortVal = &DsMemEgrSrcPortValTmp;
	tCtlCommon CtlCommonTmp = {0};
	tCtlCommon *CtlCommon = &CtlCommonTmp;
	readCtlCommon("CtlCommon", 0, CtlCommon, 0);
	tCtlEgrExt CtlEgrExtTmp = {0};
	tCtlEgrExt *CtlEgrExt = &CtlEgrExtTmp;
	readCtlEgrExt("CtlEgrExt", 0, CtlEgrExt, 0);
	tDsMemDestPort DsMemDestPortValTmp = {0};
	tDsMemDestPort *DsMemDestPortVal = &DsMemDestPortValTmp;
	tCtlEgrLog CtlEgrLogTmp = {0};
	tCtlEgrLog *CtlEgrLog = &CtlEgrLogTmp;
	readCtlEgrLog("CtlEgrLog", 0, CtlEgrLog, 0);
	tCtlEgrDot1qTpid CtlEgrDot1qTpidTmp = {0};
	tCtlEgrDot1qTpid *CtlEgrDot1qTpid = &CtlEgrDot1qTpidTmp;
	readCtlEgrDot1qTpid("CtlEgrDot1qTpid", 0, CtlEgrDot1qTpid, 0);
	tCtlEgrEdit CtlEgrEditTmp = {0};
	tCtlEgrEdit *CtlEgrEdit = &CtlEgrEditTmp;
	readCtlEgrEdit("CtlEgrEdit", 0, CtlEgrEdit, 0);
	tCtlRouterPktMac CtlRouterPktMacTmp = {0};
	tCtlRouterPktMac *CtlRouterPktMac = &CtlRouterPktMacTmp;
	readCtlRouterPktMac("CtlRouterPktMac", 0, CtlRouterPktMac, 0);
	tCtlEgrCpu CtlEgrCpuTmp = {0};
	tCtlEgrCpu *CtlEgrCpu = &CtlEgrCpuTmp;
	readCtlEgrCpu("CtlEgrCpu", 0, CtlEgrCpu, 0);
	tDsMemL3Mcast DsMemL3McastValTmp = {0};
	tDsMemL3Mcast *DsMemL3McastVal = &DsMemL3McastValTmp;
	tCtlRemoteSpan CtlRemoteSpanTmp = {0};
	tCtlRemoteSpan *CtlRemoteSpan = &CtlRemoteSpanTmp;
	readCtlRemoteSpan("CtlRemoteSpan", 0, CtlRemoteSpan, 0);
	tDsMemNexthop DsMemNexthopValTmp = {0};
	tDsMemNexthop *DsMemNexthopVal = &DsMemNexthopValTmp;
	tDsRegEgrPriorMap DsRegEgrPriorMapValTmp = {0};
	tDsRegEgrPriorMap *DsRegEgrPriorMapVal = &DsRegEgrPriorMapValTmp;

    // tMsQueInfo MsgAdmInfo = Pop info from TM dequeue;
    // glPktNew = Packet readed from Packet Memory according MsgAdmInfo;
    /** 0 get MsDeqInfo from TM */
    // tPktInfo PI = {0};
    //PI.ingressTs[63:0] = MsgAdmInfo.ingressTs[63:0];
    //PI.hdrBufPtr[12:0] = MsgAdmInfo.hdrBufPtr[12:0];
    //PI.tailBufPtr[12:0] = MsgAdmInfo.tailBufPtr[12:0];
    //PI.fwdBitmap[7:0] = MsgAdmInfo.fwdBitmap[7:0];
    //PI.fwdBitmapW1[5:0] = MsgAdmInfo.fwdBitmapW1[5:0];
    //PI.pktLength[13:0] = MsgAdmInfo.pktLength[13:0];
    //PI.nexthopIdx[5:0] = MsgAdmInfo.nexthopIdx[5:0];
    //PI.firstDecideToCpu = MsgAdmInfo.firstDecideToCpu;
    //PI.criticalPacket = MsgAdmInfo.criticalPacket;
    //PI.forceDest = MsgAdmInfo.forceDest;
    //PI.forbidEdit = MsgAdmInfo.forbidEdit;
    //PI.removeVlanTag = MsgAdmInfo.removeVlanTag;
    //PI.replaceCos = MsgAdmInfo.replaceCos;
    //PI.replaceDscp = MsgAdmInfo.replaceDscp;
    //PI.excpType[2:0] = MsgAdmInfo.excpType[2:0];
    //PI.cpuPktType[3:0] = MsgAdmInfo.cpuPktType[3:0];
    //PI.opCode[2:0] = MsgAdmInfo.opCode[2:0];
    //PI.stpId[4:0] = MsgAdmInfo.stpId[4:0];
    //PI.vlanId[11:0] = MsgAdmInfo.vlanId[11:0];
    //PI.srcPort[2:0] = MsgAdmInfo.srcPort[2:0];
    //PI.destPort[2:0] = MsgAdmInfo.destPort[2:0];
    //PI.prior[5:0] = MsgAdmInfo.prior[5:0];
    //PI.cpuPrior[5:0] = MsgAdmInfo.cpuPrior[5:0];
    //PI.routingEn = MsgAdmInfo.routingEn;
    //PI.ethTypeLen[3:0] = MsgAdmInfo.ethTypeLen[3:0];
    //PI.l3Offset[5:0] = MsgAdmInfo.l3Offset[5:0];
    //PI.l4Offset[6:0] = MsgAdmInfo.l4Offset[6:0];
    //PI.l3Type[3:0] = MsgAdmInfo.l3Type[3:0];
    //PI.l4Type[3:0] = MsgAdmInfo.l4Type[3:0];
    //PI.hasInnerHdr = MsgAdmInfo.hasInnerHdr;
    //PI.isTsn = MsgAdmInfo.isTsn;
    //PI.tsnGateId[4:0] = MsgAdmInfo.tsnGateId[4:0];
    //PI.tsnCycleSel[2:0] = MsgAdmInfo.tsnCycleSel[2:0];
    //PI.addRtag = MsgAdmInfo.addRtag;
    //PI.rtagSeq[15:0] = MsgAdmInfo.rtagSeq[15:0];
    //PI.stagValid = MsgAdmInfo.stagValid;
    //PI.ctagValid = MsgAdmInfo.ctagValid;
    //PI.ptpValid = MsgAdmInfo.ptpValid;
    //PI.extendFlag = MsgAdmInfo.extendFlag;
    //PI.extendIdx[2:0] = MsgAdmInfo.extendIdx[2:0];
    //PI.prior[5:0] = (PI.destPort[2:0] == CtlCommon.cpuPortNo) ? PI.cpuPrior[5:0] : PI.prior[5:0];
    //PI.tsOp[1:0]     = 0;
    //PI.updatePtpChksum  = 0;
    //PI.egrExcp       = 0;
    if( PI->destPort == CtlCommon->cpuPortNo ) {
        PI->forbidEdit    |= CtlEgrCpu->forbidEdit;
        PI->addCpuHdr      = CtlEgrCpu->needCpuHdr && PI->firstDecideToCpu;
        PI->forceDest      = 1;
        SET_BITS(PI->opCode, 0, 2, (OP_CODE_UCAST));
        PI->routingEn      = 0;
    }
    if( PI->extendFlag ) {
        PI->opCode    = OP_CODE_UCAST;
        PI->l2IngSpanPkt = PI->extendIdx != 1;
        PI->l2EgrSpanPkt = PI->extendIdx == 1;
        PI->forceDest    = 1;
        PI->forbidEdit  |= GET_BITS(CtlEgrExt->extForbidEdit, PI->extendIdx, PI->extendIdx);
        PI->addCpuHdr   |= GET_BITS(CtlEgrExt->extNeedCpuHdr, PI->extendIdx, PI->extendIdx);
        PI->validRemoteSpan   = GET_BITS(CtlEgrExt->extRemoteSpan, PI->extendIdx, PI->extendIdx);
    }
    if( PI->opCode == OP_CODE_MCAST && GET_BITS(PI->nexthopIdx, 5, 5) && PI->routingEn ) {
        tmpL3McIdx = ((uint64_t)PI->destPort<<7) + ( GET_BITS(PI->nexthopIdx, 1, 7));
        rpcRdMem("DsMemL3Mcast", tmpL3McIdx, DsMemL3McastVal);
        tmpNexthopIdx = DsMemL3McastVal->nexthopIdx{ GET_BITS(PI->nexthopIdx, 0, 0:0]}[5);
        SET_BITS(PI->nexthopIdx, 0, 5, ((1 << 5) + tmpNexthopIdx));
    }
    /** 1 Egress STP status check */
    if( !PI->forceDest && (PI->destPort != CtlCommon->cpuPortNo) ) {
        tmpStpIdx = (PI->destPort << 5) + GET_BITS(PI->stpId, 0, 4);
        tmpSubIdx  = GET_BITS(tmpStpIdx, 0, 3) << 1;
        rpcRdMem("DsMemDestStpState", GET_BITS(tmpStpIdx, 4, 7), DsMemDestStpStateVal);
        tmpStpState= GET_BITS(DsMemDestStpStateVal->stpState, tmpSubIdx, tmpSubIdx+1);
        PI->discard = ( (tmpStpState != STP_FWD) && (tmpStpState != STP_BLK) && !PI->routingEn );
    }
    PI->egrStpChkFail = PI->discard;
    /** 2 collect edit information */
    tmpCpuTsOp       = PTP_OP_ONE_STEP;
    if( PI->hasInnerHdr ) {
        tmpCpuTsOp        = GET_BITS(glPktNew[7], 7, 7);
        SET_BITS(PI->tsOffset, 0, 6, ( GET_BITS(glPktNew[7], 0, 6)));
        PI->updatePtpChksum  = GET_BITS(glPktNew[2], 6, 6);
    }
    // layer 2 offset
    tmpL2Offset      = (PI->hasInnerHdr << 3);
    tmpVlanOffset    = GET_BITS(tmpL2Offset, 0, 4) + 12;
    // get l2Hdr info
    SET_BITS(PI->parserOffset, 0, 6, (0));
	if (PI->hasInnerHdr) {
 		uint8_t glPktTmpFromInnerHdr[8] = {0};
 		memcpy(glPktTmpFromInnerHdr, glPktNew+PI->parserOffset, 8);
		tmpFromInnerHdrBuf0 = ((uint64_t)glPktTmpFromInnerHdr[0]<<56) + ((uint64_t)glPktTmpFromInnerHdr[1]<<48) + ((uint64_t)glPktTmpFromInnerHdr[2]<<40) + ((uint64_t)glPktTmpFromInnerHdr[3]<<32) + ((uint64_t)glPktTmpFromInnerHdr[4]<<24) + ((uint64_t)glPktTmpFromInnerHdr[5]<<16) + ((uint64_t)glPktTmpFromInnerHdr[6]<<8) + ( glPktTmpFromInnerHdr[7]);
		PI->parserOffset += 8;
		PI->validFromInnerHdr = 1;
	}
	uint8_t glPktTmpMacDa[6] = {0};
	memcpy(glPktTmpMacDa, glPktNew+PI->parserOffset, 6);
	PI->parserOffset += 6;
	tmpMacDaBuf0 = ((uint64_t)glPktTmpMacDa[0]<<40) + ((uint64_t)glPktTmpMacDa[1]<<32) + ((uint64_t)glPktTmpMacDa[2]<<24) + ((uint64_t)glPktTmpMacDa[3]<<16) + ((uint64_t)glPktTmpMacDa[4]<<8) + ( glPktTmpMacDa[5]);
	uint8_t glPktTmpMacSa[6] = {0};
	memcpy(glPktTmpMacSa, glPktNew+PI->parserOffset, 6);
	PI->parserOffset += 6;
	tmpMacSaBuf0 = ((uint64_t)glPktTmpMacSa[0]<<40) + ((uint64_t)glPktTmpMacSa[1]<<32) + ((uint64_t)glPktTmpMacSa[2]<<24) + ((uint64_t)glPktTmpMacSa[3]<<16) + ((uint64_t)glPktTmpMacSa[4]<<8) + ( glPktTmpMacSa[5]);
	uint8_t glPktTmpTpid[2] = {0};
	memcpy(glPktTmpTpid, glPktNew+PI->parserOffset, 2);
	SET_BITS(PI->tpid, 0, 15, (((uint64_t)glPktTmpTpid[0]<<8) + ( glPktTmpTpid[1])));
	if (PI->tpid == 0x88a8) {
 		uint8_t glPktTmpSVlan[4] = {0};
 		memcpy(glPktTmpSVlan, glPktNew+PI->parserOffset, 4);
		tmpSVlanBuf0 = ((uint64_t)glPktTmpSVlan[0]<<24) + ((uint64_t)glPktTmpSVlan[1]<<16) + ((uint64_t)glPktTmpSVlan[2]<<8) + ( glPktTmpSVlan[3]);
		PI->parserOffset += 4;
		PI->validSVlan = 1;
	}
	uint8_t glPktTmpTpid[2] = {0};
	memcpy(glPktTmpTpid, glPktNew+PI->parserOffset, 2);
	SET_BITS(PI->tpid, 0, 15, (((uint64_t)glPktTmpTpid[0]<<8) + ( glPktTmpTpid[1])));
	if (PI->tpid == 0x8100) {
 		uint8_t glPktTmpCVlan[4] = {0};
 		memcpy(glPktTmpCVlan, glPktNew+PI->parserOffset, 4);
		tmpCVlanBuf0 = ((uint64_t)glPktTmpCVlan[0]<<24) + ((uint64_t)glPktTmpCVlan[1]<<16) + ((uint64_t)glPktTmpCVlan[2]<<8) + ( glPktTmpCVlan[3]);
		PI->parserOffset += 4;
		PI->validCVlan = 1;
	}
	uint8_t glPktTmpTpid[2] = {0};
	memcpy(glPktTmpTpid, glPktNew+PI->parserOffset, 2);
	SET_BITS(PI->tpid, 0, 15, (((uint64_t)glPktTmpTpid[0]<<8) + ( glPktTmpTpid[1])));
	if (PI->tpid == 0xf1c1 || PI->tpid == 0x88fb || PI->tpid == 0x892f) {
 		uint8_t glPktTmpRtag[6] = {0};
 		memcpy(glPktTmpRtag, glPktNew+PI->parserOffset, 6);
		tmpRtagBuf0 = ((uint64_t)glPktTmpRtag[0]<<40) + ((uint64_t)glPktTmpRtag[1]<<32) + ((uint64_t)glPktTmpRtag[2]<<24) + ((uint64_t)glPktTmpRtag[3]<<16) + ((uint64_t)glPktTmpRtag[4]<<8) + ( glPktTmpRtag[5]);
		PI->parserOffset += 6;
		PI->validRtag = 1;
	}
    // retrieve dest port
    tmpL3Match            = 0;
    if( !PI->forbidEdit && PI->routingEn ) {
        rpcRdMem("DsMemNexthop", GET_BITS(PI->nexthopIdx, 0, 5), DsMemNexthopVal);
        tmpL3Match       = GET_BITS(PI->vlanId, 0, 11) == GET_BITS(DsMemNexthopVal->vlanId, 0, 11);
        PI->vlanId        = DsMemNexthopVal->vlanId;
    }
    rpcRdMem("DsMemDestPort", PI->destPort, DsMemDestPortVal);
    rpcRdMem("DsMemDestVlan", PI->vlanId, DsMemDestVlanVal);
    PI->ptpEn             = DsMemDestPortVal->ptpEn;   
    // Egress security check
    tmpExcpSubIdx         = 0;
    if( tmpL3Match && DsMemDestVlanVal->l3IfCheck ) {
        PI->egrExcp          = 1;
        tmpNewExcpType  = EXCP_L3IFMATCH;     // 6
        tmpExcpSubIdx        = 1;
    } 
    if( PI->routingEn && DsMemDestVlanVal->mtuCheck 
      && (( GET_BITS(PI->pktLength, 0, 13) - PI->l3Offset ) > GET_BITS(DsMemDestVlanVal->mtuSize, 0, 13)) ) {
        PI->egrExcp      = 1;
        tmpNewExcpType  = EXCP_MTUCHECKFAILED;         // 5
        tmpExcpSubIdx   = 0;
    }
    if( PI->egrExcp && !PI->l2EgrSpanPkt ) {
        PI->destPort     = CtlEgrExcpDestPort->destPort{tmpNewExcpType}[4:0];
        PI->forbidEdit   = 1;
        PI->addCpuHdr    = GET_BITS(CtlEgrExcpDestPort->excpAddCpuHdr, tmpNewExcpType, tmpNewExcpType);
        PI->excpType     = tmpNewExcpType;
        // egr exception statistic
        tmpIdx          = ((uint64_t)PI->destPort<<1) + ( GET_BITS(tmpExcpSubIdx, 0, 0));
        rpcRdMem("DsMemEgrExcpStats", tmpIdx, DsMemEgrExcpStatsVal);
 GET_BITS(DsMemEgrExcpStatsVal->pktCnt, 0, 15)  += 1;
 GET_BITS(DsMemEgrExcpStatsVal->byteCnt, 0, 31) += PI->pktLength;
        rpcSetMem( "DsMemEgrExcpStats", tmpIdx , DsMemEgrExcpStatsVal, sizeof(tDsMemEgrExcpStats) );
    }
    PI->removeVlanTag = !PI->forbidEdit && PI->removeVlanTag;
    PI->addVlanTag    = !PI->forbidEdit 
                 && (DsMemDestPortVal->specifyOutVid || (( GET_BITS(DsMemDestPortVal->dot1qType, 0, 1) != 0) 
                 && ! GET_BITS(DsMemDestVlanVal->untagPortBmp, GET_BITS(PI->destPort, 0, 2), GET_BITS(PI->destPort, 0, 2))) );
    PI->addRtag       = PI->addRtag & !PI->forbidEdit;    
    // adjust length
    tmpMinusLen  = (!PI->l2IngSpanPkt && PI->hasInnerHdr) ? 8 : 0;
    tmpMinusLen      +=  PI->removeVlanTag << 2 ;
    tmpAddLen    = PI->addCpuHdr << 4;        
    tmpAddLen        += PI->addVlanTag << 2;
    tmpAddLen        += PI->validRemoteSpan << 2;
    tmpAddLen        += PI->addRtag ? 6 : 0;
    if( tmpMinusLen > tmpAddLen ) {
        SET_BITS(PI->lenAdjust, 0, 5, (0x20/**set sign bit*/ + (tmpMinusLen - tmpAddLen)));
    } else {
        PI->lenAdjust  = tmpAddLen - tmpMinusLen;
    }
    tmpPktLength      = PI->pktLength - tmpMinusLen + tmpAddLen;
    // collect Edit information
    PI->replaceCos     = !PI->forbidEdit && (PI->replaceCos || DsMemDestPortVal->replaceCos);
    PI->replaceDscp    = !PI->forbidEdit && (PI->replaceDscp || DsMemDestPortVal->replaceDscp);
    rpcRdMem("DsRegEgrPriorMap", GET_BITS(PI->prior, 0, 5), DsRegEgrPriorMapVal);
    /**3-> UpMep Lookupa */
    // EgrOamProc(DsMemDestPortVal, DsMemDestVlanVal, PI);
    /**4-> Layer 3 Header Edit*/
    if( !PI->forbidEdit ) {
        uint8_t glPktTmpL3Hdr[40] = {0};
        memcpy(glPktTmpL3Hdr, glPktNew+ GET_BITS(PI->l3Offset, 0, 5), 40);
        // IPv4 checksum
        if( GET_BITS(PI->l3Type, 0, 3) == L3_TYPE_IPV4 ) {
            // TTL
            tmpNewIpChksum      = (glPktTmpL3Hdr[10] << 8) + glPktTmpL3Hdr[11];
            if( PI->routingEn ) {
                glPktNew[PI->l3Offset+8] = glPktTmpL3Hdr[8] - 1;
                tmpNewIpChksum = incrUpdChksum16( tmpNewIpChksum, ((uint64_t)glPktTmpL3Hdr[8]<<8) + ( glPktTmpL3Hdr[9]), ((uint64_t)glPktNew[PI->l3Offset+8]<<8) + ( glPktTmpL3Hdr[9]) );
            }
            // DSCP
            if( PI->replaceDscp ) {
                SET_BITS(glPktNew[PI->l3Offset+1], 2, 7, ( GET_BITS(DsRegEgrPriorMapVal->dscp, 0, 5)));
                tmpNewIpChksum = incrUpdChksum16( tmpNewIpChksum, ((uint64_t)glPktTmpL3Hdr[0]<<8) + ( glPktTmpL3Hdr[1]), ((uint64_t)glPktTmpL3Hdr[0]<<8) + ( glPktNew[PI->l3Offset+1]) );
            }
            // update checksum
            ((uint64_t)glPktNew[PI->l3Offset+10]<<8) + ( glPktNew[PI->l3Offset+11]) = tmpNewIpChksum;
        } else if( PI->l3Type == L3_TYPE_IPV6) {
            // TTL
            if( PI->routingEn ) {
                glPktNew[PI->l3Offset+7] = glPktTmpL3Hdr[7] - 1;
            }
            // DSCP
            if( PI->replaceDscp ) {
                SET_BITS(glPktNew[PI->l3Offset], 0, 3, ( GET_BITS(DsRegEgrPriorMapVal->dscp, 2, 5)));
                SET_BITS(glPktNew[PI->l3Offset+1], 6, 7, ( GET_BITS(DsRegEgrPriorMapVal->dscp, 0, 1)));
            }
        }
        // Layer 4 
        uint8_t glPktTmpL4Hdr[20] = {0};
        memcpy(glPktTmpL4Hdr, glPktNew+ GET_BITS(PI->l4Offset, 0, 6), 20);
        SET_BITS(PI->udpChksum, 0, 15, (( GET_BITS(PI->l4Type, 0, 3) == L4_TYPE_UDP) ?  ((uint64_t)glPktTmpL4Hdr[6]<<8) + ( glPktTmpL4Hdr[7]) : 0));
        // NAT edit info
        if( PI->routingEn && (PI->opCode == OP_CODE_NAT) && (PI->l3Type == L3_TYPE_IPV4) && 
            ((PI->l4Type == L4_TYPE_UDP) || (PI->l4Type == L4_TYPE_TCP)) ) {
            tmpOldIpSa    = ((uint64_t)glPktTmpL3Hdr[12]<<24) + ((uint64_t)glPktTmpL3Hdr[13]<<16) + ((uint64_t)glPktTmpL3Hdr[14]<<8) + ( glPktTmpL3Hdr[15]);
            // update Source IP Address
            ((uint64_t)glPktNew[PI->l3Offset+12]<<24) + ((uint64_t)glPktNew[PI->l3Offset+13]<<16) + ((uint64_t)glPktNew[PI->l3Offset+14]<<8) + ( glPktNew[PI->l3Offset+15])  = GET_BITS(DsMemNexthopVal->ipSa, 0, 31); 
            // update IP checksum as Source IP address update
            tmpUdpChecksum = incrUpdChksum32( tmpNewIpChksum, tmpOldIpSa, GET_BITS(DsMemNexthopVal->ipSa, 0, 31) );
            ((uint64_t)glPktNew[PI->l3Offset+10]<<8) + ( glPktNew[PI->l3Offset+11]) = tmpUdpChecksum;
            // TCP/UDP checksum
            if (PI->l4Type == L4_TYPE_UDP) {
                tmpL4Chksum = ((uint64_t)glPktTmpL4Hdr[6]<<8) + ( glPktTmpL4Hdr[7]);
            } else if (PI->l4Type == L4_TYPE_TCP) {
                tmpL4Chksum = ((uint64_t)glPktTmpL4Hdr[16]<<8) + ( glPktTmpL4Hdr[17]);
            }
            // for IP source address update
            tmpL4Chksum1  = incrUpdChksum32( tmpL4Chksum, GET_BITS(tmpOldIpSa, 0, 31), GET_BITS(DsMemNexthopVal->ipSa, 0, 31) );
            // for Layer 4 source port update
            ((uint64_t)glPktNew[PI->l4Offset+0]<<8) + ( glPktNew[PI->l4Offset+1])= GET_BITS(DsMemNexthopVal->l4SrcPort, 0, 15);
            tmpL4FinalChksum = incrUpdChksum16( tmpL4Chksum1, ((uint64_t)glPktTmpL4Hdr[0]<<8) + ( glPktTmpL4Hdr[1]), DsMemNexthopVal->l4SrcPort );
            if( PI->l4Type == L4_TYPE_TCP ) {
                ((uint64_t)glPktNew[PI->l4Offset+16]<<8) + ( glPktNew[PI->l4Offset+17])  = tmpL4FinalChksum;
            } else if( PI->l4Type == L4_TYPE_UDP ) {
                ((uint64_t)glPktNew[PI->l4Offset+6]<<8) + ( glPktNew[PI->l4Offset+7])    = tmpL4FinalChksum;
            }
        }
    }
    // PTP Edit
    if( PI->ptpValid ) {
        tmpPtpOffset = PI->l3Type == L3_TYPE_PTP ? PI->l3Offset : 
                            PI->l4Type == L4_TYPE_UDP ? PI->l4Offset + 8 : 0;
        SET_BITS(PI->cfOffset, 0, 6, (tmpPtpOffset + 8));
        if (PI->hasInnerHdr) { 
            PI->cfOffset = PI->cfOffset - 8; 
        }
        uint8_t glPktTmpPtpHdr[34] = {0};
        memcpy(glPktTmpPtpHdr, glPktNew+tmpPtpOffset, 34);
        SET_BITS(PI->cf, 0, 63, (((uint64_t)glPktTmpPtpHdr[8]<<56) + ((uint64_t)glPktTmpPtpHdr[9]<<48) + ((uint64_t)glPktTmpPtpHdr[10]<<40) + ((uint64_t)glPktTmpPtpHdr[11]<<32) + ((uint64_t)glPktTmpPtpHdr[12]<<24) + ((uint64_t)glPktTmpPtpHdr[13]<<16) + ((uint64_t)glPktTmpPtpHdr[14]<<8) + ( glPktTmpPtpHdr[15])));
        SET_BITS(PI->ptpType, 0, 3, ( GET_BITS(glPktTmpPtpHdr[0], 0, 3)));
        SET_BITS(PI->tsOp, 0, 1, ( GET_BITS(glPktTmpPtpHdr[6], 1, 1) == 1 ? PTP_OP_TWO_STEP : tmpCpuTsOp));
        // Sync and Follow_up shall send to master port
        if( PI->ptpEn && GET_BITS(DsMemDestPortVal->ptpPortType, 0, 1) != PTP_PORT_MASTER  && 
            (PI->ptpType == PTP_MSG_SYNC || PI->ptpType == PTP_MSG_FOLLOW_UP) ) {
            PI->discard   = PI->discard | 1;
            PI->ptpPortTypeChkFail    =  1;
        }
        if( PI->l4Type == L4_TYPE_UDP && PI->l3Type == L3_TYPE_IPV4 && CtlEgrEdit->v4PtpUdpChksumSet0 ) {    // UDP checksum is 0
            glPktNew[tmpPtpOffset+6]        = 0;
            glPktNew[tmpPtpOffset+7]        = 0;
        }
    }
    /** Add TSN RTAG */
    if( PI->addRtag ) {
        tmpRtagBuf0 = ((uint64_t) GET_BITS(CtlEgrEdit->rtagTpid, 0, 15)<<32) + ((uint64_t) GET_BITS(CtlEgrEdit->rtagContent, 0, 15)<<16) + ( GET_BITS(PI->rtagSeq, 0, 15) );
    }
    /** Edit VLAN */
    uint8_t glPktTmpOtag[1] = {0};
    memcpy(glPktTmpOtag, glPktNew+tmpL2Offset+14, 1);
    tmpOldCos = PI->removeVlanTag ? GET_BITS(glPktTmpOtag[0], DsRegEgrPriorMapVal->cos[2:0, 7:5]);
    tmpCos   = PI->replaceCos ? GET_BITS(DsRegEgrPriorMapVal->cos, tmpOldCos[2:0, 2:0]);
    tmpTpid = GET_BITS(DsMemDestPortVal->dot1qType, 1, 1) ? GET_BITS(CtlEgrDot1qTpid->tpidOut, 0, 15) : 0x8100;
    if( PI->addVlanTag ) {
        tmpPad = 0;
        if( DsMemDestPortVal->specifyOutVid ) {
            tmpNewVlanBuf    = ((uint64_t) GET_BITS(tmpTpid, 0, 15)<<16) + ((uint64_t) GET_BITS(tmpCos, 0, 2)<<13) + ((uint64_t) GET_BITS(tmpPad, 0, 0)<<12) + ( GET_BITS(DsMemDestPortVal->specifiedVlanId, 0, 11));       
        } else {
            tmpNewVlanBuf    = ((uint64_t) GET_BITS(tmpTpid, 0, 15)<<16) + ((uint64_t) GET_BITS(tmpCos, 0, 2)<<13) + ((uint64_t) GET_BITS(tmpPad, 0, 0)<<12) + ( GET_BITS(PI->vlanId, 0, 11));
        }
        if (PI->stagValid) {
            tmpSVlanBuf0 = tmpNewVlanBuf;
        } else if (PI->ctagValid) {
            tmpSVlanBuf0 = tmpNewVlanBuf;
        } else {
            tmpCVlanBuf0 = tmpNewVlanBuf;
        }
    }
    /** Edit CPU Header */
    if( PI->addCpuHdr ) {
        if( PI->pktLength > GET_BITS(CtlEgrCpu->maxLength, 0, 13) ) {
            PI->truncateCpuPkt        = 1;
            tmpPktLength             = GET_BITS(CtlEgrCpu->maxLength, 0, 13);
            PI->pktLength             = tmpPktLength - 16 /** to_cpu_header_length */;
        }
        tmpPktType              = PI->cpuPktType!=CPU_PKT_NONE;
        SET_BITS(PI->pktType, 0, 0, (tmpPktType));
        tmpExcpType             = PI->excpType!=EXCP_NONE;
        SET_BITS(PI->pktType, 1, 1, (tmpExcpType));
        SET_BITS(PI->pktType, 2, 2, (PI->ptpValid));
        SET_BITS(PI->subType, 0, 3, (PI->ptpValid ? PI->ptpType : 0));
        SET_BITS(PI->pldOffset, 0, 6, (PI->l4Type != L4_TYPE_NONE ? PI->l4Offset : PI->l3Type != L3_TYPE_NONE ? PI->l3Offset : 0));
        tmpToCpuHdrBuf0     = ((uint64_t) GET_BITS(PI->pktType, 0, 3)<<4) + ( GET_BITS(PI->subType, 0, 3));
        SET_BITS(tmpToCpuHdrBuf0, 96, 119, (((uint64_t) GET_BITS(PI->vlanId, 0, 11)<<12) + ((uint64_t) GET_BITS(PI->pldOffset, 0, 6)<<5) + ( GET_BITS(PI->srcPort, 0, 4))));
        SET_BITS(tmpToCpuHdrBuf0, 80, 95, (((uint64_t)0<<15) + ((uint64_t) GET_BITS(PI->excpType, 0, 2)<<12) + ((uint64_t) GET_BITS(PI->cpuPktType, 0, 3)<<8) + ((uint64_t) GET_BITS(PI->prior, 0, 5)<<2) + ( GET_BITS(PI->version, 0, 1))));
        SET_BITS(tmpToCpuHdrBuf0, 64, 79, (((uint64_t) GET_BITS(tmpPktLength, 0, 13)<<2) + ( GET_BITS(0, 0, 1))));
        SET_BITS(tmpToCpuHdrBuf0, 0, 63, ( GET_BITS(PI->ingressTs, 0, 63)));
    }
    /** Assemble Packet */
    if( PI->hasInnerHdr && !PI->l2IngSpanPkt ) {      //Remove 8 bytes of CPU header
        PI->removeInnerHdr     = 1;
    }
    PI->updateMacSa = !PI->forbidEdit && (PI->routingEn || (PI->ptpValid && CtlEgrEdit->ptpUpdMacSaEn && PI->ptpEn));
    PI->updateMacDa = !PI->forbidEdit && PI->routingEn;
    if( PI->updateMacDa ) {      // Layer 2 edit info
        tmpMacDaBuf0 = ((uint64_t) GET_BITS(DsMemNexthopVal->macDaHi, 0, 15)<<32) + ( GET_BITS(DsMemNexthopVal->macDa, 0, 31));
        SET_BITS(tmpIdx, 0, 1, ( GET_BITS(DsMemNexthopVal->routerMacIdx, 0, 1)));
        tmpNewMacSaLo = CtlRouterPktMac->routerMac{ GET_BITS(tmpIdx, 0, 1:0]}[31);
        tmpNewMacSaHi = CtlRouterPktMac->routerMacHi{ GET_BITS(tmpIdx, 0, 1:0]}[15);
        tmpMacSaBuf0 = ((uint64_t) GET_BITS(tmpNewMacSaHi, 0, 15)<<32) + ( GET_BITS(tmpNewMacSaLo, 0, 31));
    } 
    if( PI->ptpValid && CtlEgrEdit->ptpUpdMacSaEn && PI->ptpEn ) {
        tmpNewMacSaLo = GET_BITS(CtlEgrEdit->ptpMacAddr, 0, 31);
        tmpNewMacSaHi = GET_BITS(CtlEgrEdit->ptpMacAddrHi, 0, 15);
        tmpMacSaBuf0 = ((uint64_t) GET_BITS(tmpNewMacSaHi, 0, 15)<<32) + ( GET_BITS(tmpNewMacSaLo, 0, 31));
    }
    if( PI->validRemoteSpan ) {
        tmpRtagStart += 4;
        tmpCos = CtlRemoteSpan->cosValid ? GET_BITS(CtlRemoteSpan->cos, tmpCos[2:0, 2:0]);
        tmpRspanBuf0 = ((uint64_t) GET_BITS(CtlRemoteSpan->tpid, 0, 15)<<16) + ((uint64_t) GET_BITS(tmpCos, 0, 2)<<13) + ((uint64_t) GET_BITS(tmpPad, 0, 0)<<12) + ( GET_BITS(CtlRemoteSpan->vlanId, 0, 11));
    }
    /** Ptp process sideband info */
    PI->tsOpEn         = 0;
    PI->updatePtpChksum = (PI->l4Type == L4_TYPE_UDP && (!CtlEgrEdit->v4PtpUdpChksumSet0 || CtlEgrEdit->updV6PtpUdpChksum)) || PI->updPtpChksum;
    if (PI->ptpValid && PI->ptpEn && 
        ( ((PI->ptpType == PTP_MSG_PDELAY_RESP) && (PI->tsOp == PTP_OP_ONE_STEP)) || 
          ((CtlEgrEdit->ptpDevType == PTP_DEV_TC_P2P || CtlEgrEdit->ptpDevType == PTP_DEV_TC_E2E) && (PI->tsOp == PTP_OP_ONE_STEP) && (PI->ptpType == PTP_MSG_SYNC)) || 
          ((CtlEgrEdit->ptpDevType == PTP_DEV_TC_E2E) && (PI->ptpType == PTP_MSG_DELAY_REQ)) || 
          (( GET_BITS(CtlEgrEdit->cfMissedType, 0, 15) & (1 << PI->ptpType)) != 0 ) 
        )
       ) {        // Update Correction Field 
        PI->tsOpEn              = 1;
        if (PI->ptpType == PTP_MSG_SYNC && PI->tsOp == PTP_OP_ONE_STEP && CtlEgrEdit->ptpDevType == PTP_DEV_TC_P2P) {
            rpcRdMem("DsMemEgrSrcPort", PI->srcPort, DsMemEgrSrcPortVal);
			tmpCfNs = GET_BITS(PI->cf, 16, 63) + GET_BITS(DsMemEgrSrcPortVal->pDelay, 0, 31);  // Propagation delay is added
            SET_BITS(PI->latestPtpCf, 0, 63, (((uint64_t) GET_BITS(tmpCfNs, 0, 47)<<16) + ( GET_BITS(PI->cf, 0, 15))));
            SET_BITS(PI->latestPtpChksum, 0, 15, (incrUpdChksum64(PI->udpChksum, PI->latestPtpCf, PI->cf)));
        } else {
            PI->latestPtpCf     = PI->cf;
            PI->latestPtpChksum = PI->udpChksum;
        }
        // Ingress 2-bit second and 30-bit nano-second is needed for time rewind judgement
        SET_BITS(PI->tsOpType, 0, 1, (3));
        if ((PI->ptpType == PTP_MSG_PDELAY_RESP) && (PI->tsOp == PTP_OP_ONE_STEP)) {   // one step pdelay_req+T2 -> cpu, cpu send pdelay_resp and put 64-bit ns T2 in cf, mac calculate T3-T2
            SET_BITS(PI->tsOpType, 0, 1, (0));
        }
        // Update UDP checksum which is at {PI.cfOffset - 10, PI.cfOffset - 9} and correctionField which is at PI.cfOffset.
        PI->updPtpCf     = 1;
    } else if (PI->ptpValid && PI->ptpEn && ((CtlEgrEdit->ptpDevType == PTP_DEV_BC || CtlEgrEdit->ptpDevType == PTP_DEV_OC) && 
                (PI->ptpType == PTP_MSG_SYNC) && (PI->tsOp == PTP_OP_ONE_STEP)) || 
               (( GET_BITS(CtlEgrEdit->tsMissedType, 0, 15) & (1 << PI->ptpType)) != 0)
              ) {      // Update Timestamp
        PI->tsOpEn             = 1;
        PI->tsOpType = 1;
        PI->ts = 0;
        PI->latestPtpCf = 0;
        // Current time second value is needed, mac will fill the nano-second
        // Update UDP checksum if needed which is at {PI.tsOffset - 36, PI.tsOffset - 35} and insert Timestamp.
        PI->updPtpTs     = 1;
    } else if (PI->ptpValid && PI->ptpEn && 
               ( ((PI->ptpType == PTP_MSG_SYNC) && (PI->tsOp == PTP_OP_TWO_STEP)) || (PI->ptpType == PTP_MSG_PDELAY_REQ) ||
                 ((PI->ptpType == PTP_MSG_DELAY_REQ) && (CtlEgrEdit->ptpDevType == PTP_DEV_BC || CtlEgrEdit->ptpDevType == PTP_DEV_OC)) ||
                 ((PI->ptpType == PTP_MSG_PDELAY_RESP) && (PI->tsOp == PTP_OP_TWO_STEP)) 
               ) 
              ) {      // raise interrupt 
        PI->tsOpEn             = 1;
        // Current time second value is needed, mac will fill the nano-second
        PI->tsOpType = 2;
        SET_BITS(PI->reserve, 0, 5, (0x20));
        PI->ts = 0;     
        PI->intrPtpTs    = 1;
    }
    tmpTsHeaderBuf0 = ((uint64_t) GET_BITS(PI->tsOpType, 0, 1)<<6) + ( GET_BITS(PI->reserve, 0, 5));
    SET_BITS(tmpTsHeaderBuf0, 112, 119, (((uint64_t) GET_BITS(PI->updatePtpChksum, 0, 0)<<7) + ( GET_BITS(PI->cfOffset, 0, 6))));
    SET_BITS(tmpTsHeaderBuf0, 96, 111, ( GET_BITS(PI->latestPtpChksum, 0, 15)));
    SET_BITS(tmpTsHeaderBuf0, 32, 95, ( GET_BITS(PI->latestPtpCf, 0, 63)));
    SET_BITS(tmpTsHeaderBuf0, 0, 31, ( GET_BITS(PI->ts, 0, 31)));
    PI->validInnerVlan = (PI->ctagValid && PI->stagValid) || (PI->ctagValid && !PI->stagValid && !PI->removeVlanTag) || (!PI->ctagValid && !PI->stagValid && PI->addVlanTag);
    PI->validOuterVlan = (PI->stagValid && !PI->removeVlanTag) || (PI->stagValid && PI->removeVlanTag && PI->addVlanTag) || (!PI->stagValid && PI->ctagValid && PI->addVlanTag);
    	SET_BITS(tmpFldLenBuf, 64, 71, (PI->validRtag || PI->addRtag ? 134 : 6));
	SET_BITS(tmpContentBuf, 512, 559, ( GET_BITS(tmpRtagBuf0, 0, 47)));
	SET_BITS(tmpFldLenBuf, 56, 63, (PI->validInnerVlan ? 132 : 4));
	tmpContentBuf = GET_BITS(tmpCVlanBuf0, 0, 31);
	SET_BITS(tmpFldLenBuf, 48, 55, (PI->validOuterVlan ? 132 : 4));
	SET_BITS(tmpContentBuf, 448, 479, ( GET_BITS(tmpSVlanBuf0, 0, 31)));
	tmpFldLenBuf = PI->validRemoteSpan ? 132 : 4;
	SET_BITS(tmpContentBuf, 416, 447, ( GET_BITS(tmpRspanBuf0, 0, 31)));
	SET_BITS(tmpFldLenBuf, 32, 39, (134));
	SET_BITS(tmpContentBuf, 368, 415, ( GET_BITS(tmpMacSaBuf0, 0, 47)));
	SET_BITS(tmpFldLenBuf, 24, 31, (134));
	SET_BITS(tmpContentBuf, 320, 367, ( GET_BITS(tmpMacDaBuf0, 0, 47)));
	SET_BITS(tmpFldLenBuf, 16, 23, (PI->hasInnerHdr&&!PI->removeInnerHdr ? 136 : 8));
	SET_BITS(tmpContentBuf, 256, 319, ( GET_BITS(tmpFromInnerHdrBuf0, 0, 63)));
	SET_BITS(tmpFldLenBuf, 8, 15, (PI->addCpuHdr ? 144 : 16));
	SET_BITS(tmpContentBuf, 128, 255, ( GET_BITS(tmpToCpuHdrBuf0, 0, 127)));
	SET_BITS(tmpFldLenBuf, 0, 7, (PI->tsOpEn ? 144 : 16));
	SET_BITS(tmpContentBuf, 0, 127, ( GET_BITS(tmpTsHeaderBuf0, 0, 127)));
	//strip all old header
	glPktNew = glPktNew + PI->l3Offset;
	HeaderEdit( glPktNew, tmpFldLenBuf, tmpContentBuf );
    /** Deliver Packet to destination port */
    if( PI->discard ) {
        // discard packet;
    } else if( PI->tsOpEn ) {
        tmpTsUpdSignal   = 1;          // This signal shall deliever to MAC
        tmpEgrExcpSignal = PI->egrExcp;
        PI->pktLength    += 16;
        // Deliver glPktNew to PI.destPort[2:0] with glChanneId[5:0], tmpTsUpdSignal and tmpEgrExcpSignal.
    }
    SET_BITS(CtlEgrLog->vlanId, 0, 11, ( GET_BITS(PI->vlanId, 0, 11)));
    SET_BITS(CtlEgrLog->excpType, 0, 2, ( GET_BITS(PI->excpType, 0, 2)));
    SET_BITS(CtlEgrLog->opCode, 0, 2, ( GET_BITS(PI->opCode, 0, 2)));
    CtlEgrLog->egrDiscard = PI->egrDiscard;
    CtlEgrLog->routedPkt = PI->routedPkt;
    CtlEgrLog->removeCpuHdr = PI->removeCpuHdr;
    CtlEgrLog->addCpuHdr = PI->addCpuHdr;
    CtlEgrLog->updateMacDa = PI->updateMacDa;
    CtlEgrLog->updateMacSa = PI->updateMacSa;
    CtlEgrLog->removeVlanTag = PI->removeVlanTag;
    CtlEgrLog->addVlanTag = PI->addVlanTag;
    CtlEgrLog->remoteSpan = PI->remoteSpan;
    CtlEgrLog->addRtag = PI->addRtag;
    CtlEgrLog->replaceCos = PI->replaceCos;
    CtlEgrLog->replaceDscp = PI->replaceDscp;
    CtlEgrLog->egrStpChkFail = PI->egrStpChkFail;
    CtlEgrLog->ptpPortTypeChkFail = PI->ptpPortTypeChkFail;
    SET_BITS(CtlEgrLog->ptpType, 0, 15, ( GET_BITS(PI->ptpType, 0, 15)));
    CtlEgrLog->updPtpTs = PI->updPtpTs;
    CtlEgrLog->updPtpCf = PI->updPtpCf;
    CtlEgrLog->intrPtpTs = PI->intrPtpTs;
    CtlEgrLog->xconErr = PI->xconErr;
    CtlEgrLog->truncateCpuPkt = PI->truncateCpuPkt;
}
static void EgrOamProc(uint8_t DsMemDestPortVal, uint8_t DsMemDestVlanVal, tPktInfo *PI) {
	uint8_t tmpNeedLookup = 0;
	uint8_t tmpHashIdx = 0;
	uint16_t tmpUpMepIdx = 0;
	uint16_t tmpMepPtr = 0;
	uint8_t tmpK = 0;
	uint32_t tmpCfgKey = 0;
	uint8_t tmpOamValid = 0;
	uint8_t tmpMelBit = 0;
	uint8_t tmpMdlHit = 0;
	uint8_t tmpCcmTerminated = 0;
	uint8_t tmpMelGreater = 0;
	uint8_t tmpDiscard = 0;
	uint8_t tmpJ = 0;
	uint8_t tmpHit = 0;
	uint32_t tmpKeyBuf = 0;

	tCtlEgrOam CtlEgrOamTmp = {0};
	tCtlEgrOam *CtlEgrOam = &CtlEgrOamTmp;
	readCtlEgrOam("CtlEgrOam", 0, CtlEgrOam, 0);
	tDsMemEgrOamKey DsMemEgrOamKeyValTmp = {0};
	tDsMemEgrOamKey *DsMemEgrOamKeyVal = &DsMemEgrOamKeyValTmp;
	tDsMemEgrMepPtr DsMemEgrMepPtrValTmp = {0};
	tDsMemEgrMepPtr *DsMemEgrMepPtrVal = &DsMemEgrMepPtrValTmp;
	tDsMemEgrOamSession DsMemEgrOamSessionValTmp = {0};
	tDsMemEgrOamSession *DsMemEgrOamSessionVal = &DsMemEgrOamSessionValTmp;

    if (!PI->forceDest && !PI->egrExcp) {
        tmpDiscard = GET_BITS(CtlEgrOam->oamObeyDiscard, PI->destPort, PI->destPort);
        if (!tmpDiscard && (PI->l3Type == L3_TYPE_ETH_OAM)
            && DsMemDestPortVal->portEthOamEn && DsMemDestVlanVal->vlanEthOamEn) {
            tmpNeedLookup = 1;
        }
        if (tmpNeedLookup) {
            tmpKeyBuf = ((uint64_t)0<<15) + ((uint64_t) GET_BITS(PI->destPort, 0, 2)<<12) + ( GET_BITS(PI->vlanId, 0, 11));
            tmpHashIdx = Hash1(tmpKeyBuf);
            rpcRdMem("DsMemEgrOamKey", tmpHashIdx, DsMemEgrOamKeyVal);
            tmpCfgKey = DsMemEgrOamKeyVal->key0;
            if ( GET_BITS(DsMemEgrOamKeyVal->valid, 0, 0) && (tmpCfgKey == tmpKeyBuf)) {
                tmpUpMepIdx = ( GET_BITS(tmpHashIdx, 0, 7) << 2) + 0;
                tmpHit = 1;
            }
            tmpCfgKey = DsMemEgrOamKeyVal->key1;
            if ( GET_BITS(DsMemEgrOamKeyVal->valid, 1, 1) && (tmpCfgKey == tmpKeyBuf)) {
                tmpUpMepIdx = ( GET_BITS(tmpHashIdx, 0, 7) << 2) + 1;
                tmpHit = 1;
            }
            tmpCfgKey = DsMemEgrOamKeyVal->key2;
            if ( GET_BITS(DsMemEgrOamKeyVal->valid, 2, 2) && (tmpCfgKey == tmpKeyBuf)) {
                tmpUpMepIdx = ( GET_BITS(tmpHashIdx, 0, 7) << 2) + 2;
                tmpHit = 1;
            }
            tmpCfgKey = DsMemEgrOamKeyVal->key3;
            if ( GET_BITS(DsMemEgrOamKeyVal->valid, 3, 3) && (tmpCfgKey == tmpKeyBuf)) {
                tmpUpMepIdx = ( GET_BITS(tmpHashIdx, 0, 7) << 2) + 3;
                tmpHit = 1;
            }
            tmpOamValid = 0;
            if (tmpHit) {
                tmpOamValid = 1;
                rpcRdMem("DsMemEgrOamSession", tmpUpMepIdx, DsMemEgrOamSessionVal);
            } else {
                //Not found, just do normal forwarding.
            }
            if (tmpOamValid) {
                tmpMelBit = DsMemEgrOamSessionVal->mdlBmp;
                tmpMelGreater = 0;
                tmpJ = 0;
                tmpK = 0;
            if ( GET_BITS(tmpMelBit, 0, 0)) {
                tmpJ++;
                if (PI->cfmMdl == 0) {
                    tmpMdlHit = 1;
                } else if (PI->cfmMdl > 0) {
                    tmpK++;
                }
            }
            if ( GET_BITS(tmpMelBit, 1, 1)) {
                tmpJ++;
                if (PI->cfmMdl == 1) {
                    tmpMdlHit = 1;
                } else if (PI->cfmMdl > 1) {
                    tmpK++;
                }
            }
            if ( GET_BITS(tmpMelBit, 2, 2)) {
                tmpJ++;
                if (PI->cfmMdl == 2) {
                    tmpMdlHit = 1;
                } else if (PI->cfmMdl > 2) {
                    tmpK++;
                }
            }
            if ( GET_BITS(tmpMelBit, 3, 3)) {
                tmpJ++;
                if (PI->cfmMdl == 3) {
                    tmpMdlHit = 1;
                } else if (PI->cfmMdl > 3) {
                    tmpK++;
                }
            }
            if ( GET_BITS(tmpMelBit, 4, 4)) {
                tmpJ++;
                if (PI->cfmMdl == 4) {
                    tmpMdlHit = 1;
                } else if (PI->cfmMdl > 4) {
                    tmpK++;
                }
            }
            if ( GET_BITS(tmpMelBit, 5, 5)) {
                tmpJ++;
                if (PI->cfmMdl == 5) {
                    tmpMdlHit = 1;
                } else if (PI->cfmMdl > 5) {
                    tmpK++;
                }
            }
            if ( GET_BITS(tmpMelBit, 6, 6)) {
                tmpJ++;
                if (PI->cfmMdl == 6) {
                    tmpMdlHit = 1;
                } else if (PI->cfmMdl > 6) {
                    tmpK++;
                }
            }
            if ( GET_BITS(tmpMelBit, 7, 7)) {
                tmpJ++;
                if (PI->cfmMdl == 7) {
                    tmpMdlHit = 1;
                } else if (PI->cfmMdl > 7) {
                    tmpK++;
                }
            }
                if (tmpJ == tmpK) {
                     tmpMelGreater = 1;
                }
                if ((tmpMelBit == 0) ||  tmpMelGreater) {
                     // normalForward = 1;
                } else if (tmpMdlHit) {
                     tmpCcmTerminated = 1;
                } else {
                     PI->discard = 1;
                     PI->xconErr = 1;
                }
                if (tmpCcmTerminated) {
                    tmpMepPtr = GET_BITS(DsMemEgrOamSessionVal->mepBasePtr, 0, 12) + PI->cfmMdl;
                    PI->oamEgrIdxValid = 1;
                }
            }
            if (PI->oamEgrIdxValid) {
                rpcRdMem("DsMemEgrMepPtr", tmpMepPtr, DsMemEgrMepPtrVal);
                SET_BITS(PI->oamIdx, 0, 10, ( GET_BITS(DsMemEgrMepPtrVal->oamIdx, 0, 10)));
            }
        }
    }
}
