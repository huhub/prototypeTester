
process PacketEdit(PI, glPktNew, MsgAdmInfo) {
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

    if( PI.destPort == CtlCommon.cpuPortNo ) {
        PI.forbidEdit    |= CtlEgrCpu.forbidEdit;
        PI.addCpuHdr      = CtlEgrCpu.needCpuHdr && PI.firstDecideToCpu;
        PI.forceDest      = 1;
        PI.opCode[2:0]    = OP_CODE_UCAST;
        PI.routingEn      = 0;
    }
    if( PI.extendFlag ) {
        PI.opCode    = OP_CODE_UCAST;
        PI.l2IngSpanPkt = PI.extendIdx != 1;
        PI.l2EgrSpanPkt = PI.extendIdx == 1;
        PI.forceDest    = 1;
        PI.forbidEdit  |= CtlEgrExt.extForbidEdit[ PI.extendIdx:PI.extendIdx ];
        PI.addCpuHdr   |= CtlEgrExt.extNeedCpuHdr[ PI.extendIdx:PI.extendIdx ];
        PI.validRemoteSpan   = CtlEgrExt.extRemoteSpan[ PI.extendIdx:PI.extendIdx ];
    }
    if( PI.opCode == OP_CODE_MCAST && PI.nexthopIdx[5:5] && PI.routingEn ) {
        tmpL3McIdx[11:0] = {PI.destPort, PI.nexthopIdx[7:1]};
        DsMemL3McastVal   = DsMemL3Mcast[ tmpL3McIdx ];
        tmpNexthopIdx[5:0] = DsMemL3McastVal.nexthopIdx{PI.nexthopIdx[0:0]}[5:0];
        PI.nexthopIdx[5:0] = (1 << 5) + tmpNexthopIdx;
    }

    /** 1 Egress STP status check */
    if( !PI.forceDest && (PI.destPort != CtlCommon.cpuPortNo) ) {
        tmpStpIdx[7:0] = (PI.destPort << 5) + PI.stpId[4:0];
        tmpSubIdx[4:0]  = tmpStpIdx[3:0] << 1;
        DsMemDestStpStateVal = DsMemDestStpState[tmpStpIdx[7:4]];
        tmpStpState[1:0]= DsMemDestStpStateVal.stpState[tmpSubIdx+1:tmpSubIdx];
        PI.discard = ( (tmpStpState != STP_FWD) && (tmpStpState != STP_BLK) && !PI.routingEn );
    }
    PI.egrStpChkFail = PI.discard;

    /** 2 collect edit information */
    tmpCpuTsOp[1:0]       = PTP_OP_ONE_STEP;
    if( PI.hasInnerHdr ) {
        tmpCpuTsOp        = glPktNew[7][7:7];
        PI.tsOffset[6:0] = glPktNew[7][6:0];
        PI.updatePtpChksum  = glPktNew[2][6:6];
    }
    // layer 2 offset
    tmpL2Offset[4:0]      = (PI.hasInnerHdr << 3);
    tmpVlanOffset[4:0]    = tmpL2Offset[4:0] + 12;

    // get l2Hdr info
    PI.parserOffset[6:0] = 0;
	if (PI.hasInnerHdr) {
 		glPktTmpFromInnerHdr[0:7] = glPktNew[PI.parserOffset : PI.parserOffset+7];
		tmpFromInnerHdrBuf0[63:0] = {glPktTmpFromInnerHdr[0], glPktTmpFromInnerHdr[1], glPktTmpFromInnerHdr[2], glPktTmpFromInnerHdr[3], glPktTmpFromInnerHdr[4], glPktTmpFromInnerHdr[5], glPktTmpFromInnerHdr[6], glPktTmpFromInnerHdr[7]};
		PI.parserOffset += 8;
		PI.validFromInnerHdr = 1;
	}
	glPktTmpMacDa[0:5] =  glPktNew[PI.parserOffset : PI.parserOffset+5];
	PI.parserOffset += 6;
	tmpMacDaBuf0[47:0] = {glPktTmpMacDa[0], glPktTmpMacDa[1], glPktTmpMacDa[2], glPktTmpMacDa[3], glPktTmpMacDa[4], glPktTmpMacDa[5]};
	glPktTmpMacSa[0:5] =  glPktNew[PI.parserOffset : PI.parserOffset+5];
	PI.parserOffset += 6;
	tmpMacSaBuf0[47:0] = {glPktTmpMacSa[0], glPktTmpMacSa[1], glPktTmpMacSa[2], glPktTmpMacSa[3], glPktTmpMacSa[4], glPktTmpMacSa[5]};
	glPktTmpTpid[0:1] = glPktNew[PI.parserOffset : PI.parserOffset+1];
	PI.tpid[15:0] = {glPktTmpTpid[0], glPktTmpTpid[1]};
	if (PI.tpid == 16'h88a8) {
 		glPktTmpSVlan[0:3] = glPktNew[PI.parserOffset : PI.parserOffset+3];
		tmpSVlanBuf0[31:0] = {glPktTmpSVlan[0], glPktTmpSVlan[1], glPktTmpSVlan[2], glPktTmpSVlan[3]};
		PI.parserOffset += 4;
		PI.validSVlan = 1;
	}
	glPktTmpTpid[0:1] = glPktNew[PI.parserOffset : PI.parserOffset+1];
	PI.tpid[15:0] = {glPktTmpTpid[0], glPktTmpTpid[1]};
	if (PI.tpid == 16'h8100) {
 		glPktTmpCVlan[0:3] = glPktNew[PI.parserOffset : PI.parserOffset+3];
		tmpCVlanBuf0[31:0] = {glPktTmpCVlan[0], glPktTmpCVlan[1], glPktTmpCVlan[2], glPktTmpCVlan[3]};
		PI.parserOffset += 4;
		PI.validCVlan = 1;
	}
	glPktTmpTpid[0:1] = glPktNew[PI.parserOffset : PI.parserOffset+1];
	PI.tpid[15:0] = {glPktTmpTpid[0], glPktTmpTpid[1]};
	if (PI.tpid == 16'hf1c1 || PI.tpid == 16'h88fb || PI.tpid == 16'h892f) {
 		glPktTmpRtag[0:5] = glPktNew[PI.parserOffset : PI.parserOffset+5];
		tmpRtagBuf0[47:0] = {glPktTmpRtag[0], glPktTmpRtag[1], glPktTmpRtag[2], glPktTmpRtag[3], glPktTmpRtag[4], glPktTmpRtag[5]};
		PI.parserOffset += 6;
		PI.validRtag = 1;
	}


    // retrieve dest port
    tmpL3Match            = 0;
    if( !PI.forbidEdit && PI.routingEn ) {
        DsMemNexthopVal  = DsMemNexthop[ PI.nexthopIdx[5:0] ];
        tmpL3Match       = PI.vlanId[11:0] == DsMemNexthopVal.vlanId[11:0];
        PI.vlanId        = DsMemNexthopVal.vlanId;
    }
    DsMemDestPortVal     = DsMemDestPort[ PI.destPort ];
    DsMemDestVlanVal     = DsMemDestVlan[ PI.vlanId ];
    PI.ptpEn             = DsMemDestPortVal.ptpEn;   

    // Egress security check
    tmpExcpSubIdx         = 0;
    if( tmpL3Match && DsMemDestVlanVal.l3IfCheck ) {
        PI.egrExcp          = 1;
        tmpNewExcpType[2:0]  = EXCP_L3IFMATCH;     // 6
        tmpExcpSubIdx        = 1;
    } 
    if( PI.routingEn && DsMemDestVlanVal.mtuCheck 
      && ((PI.pktLength[13:0] - PI.l3Offset ) > DsMemDestVlanVal.mtuSize[13:0]) ) {
        PI.egrExcp      = 1;
        tmpNewExcpType  = EXCP_MTUCHECKFAILED;         // 5
        tmpExcpSubIdx   = 0;
    }
    if( PI.egrExcp && !PI.l2EgrSpanPkt ) {
        PI.destPort     = CtlEgrExcpDestPort.destPort{tmpNewExcpType}[4:0];
        PI.forbidEdit   = 1;
        PI.addCpuHdr    = CtlEgrExcpDestPort.excpAddCpuHdr[ tmpNewExcpType : tmpNewExcpType ];
        PI.excpType     = tmpNewExcpType;
        // egr exception statistic
        tmpIdx[3:0]          = {PI.destPort, tmpExcpSubIdx[0:0]};
        DsMemEgrExcpStatsVal                = DsMemEgrExcpStats[ tmpIdx ];
        DsMemEgrExcpStatsVal.pktCnt[15:0]  += 1;
        DsMemEgrExcpStatsVal.byteCnt[31:0] += PI.pktLength;
        DsMemEgrExcpStats[ tmpIdx ]         = DsMemEgrExcpStatsVal;
    }
    PI.removeVlanTag = !PI.forbidEdit && PI.removeVlanTag;
    PI.addVlanTag    = !PI.forbidEdit 
                 && (DsMemDestPortVal.specifyOutVid || ((DsMemDestPortVal.dot1qType[1:0] != 0) 
                 && !DsMemDestVlanVal.untagPortBmp[ PI.destPort[2:0] : PI.destPort[2:0] ]) );
    PI.addRtag       = PI.addRtag & !PI.forbidEdit;    
    // adjust length
    tmpMinusLen[5:0]  = (!PI.l2IngSpanPkt && PI.hasInnerHdr) ? 8 : 0;
    tmpMinusLen      +=  PI.removeVlanTag << 2 ;
    tmpAddLen[5:0]    = PI.addCpuHdr << 4;        
    tmpAddLen        += PI.addVlanTag << 2;
    tmpAddLen        += PI.validRemoteSpan << 2;
    tmpAddLen        += PI.addRtag ? 6 : 0;
    
    if( tmpMinusLen > tmpAddLen ) {
        PI.lenAdjust[5:0]  = 6'h20/**set sign bit*/ + (tmpMinusLen - tmpAddLen);
    } else {
        PI.lenAdjust  = tmpAddLen - tmpMinusLen;
    }
    tmpPktLength[13:0]      = PI.pktLength - tmpMinusLen + tmpAddLen;

    // collect Edit information
    PI.replaceCos     = !PI.forbidEdit && (PI.replaceCos || DsMemDestPortVal.replaceCos);
    PI.replaceDscp    = !PI.forbidEdit && (PI.replaceDscp || DsMemDestPortVal.replaceDscp);
    DsRegEgrPriorMapVal   = DsRegEgrPriorMap[ PI.prior[5:0] ];

    /**3. UpMep Lookupa */
    // EgrOamProc(DsMemDestPortVal, DsMemDestVlanVal, PI);

    /**4. Layer 3 Header Edit*/
    if( !PI.forbidEdit ) {
        glPktTmpL3Hdr[0:39] = glPktNew[PI.l3Offset[5:0] : PI.l3Offset + 39];
        // IPv4 checksum
        if( PI.l3Type[3:0] == L3_TYPE_IPV4 ) {
            // TTL
            tmpNewIpChksum[15:0]      = (glPktTmpL3Hdr[10] << 8) + glPktTmpL3Hdr[11];
            if( PI.routingEn ) {
                glPktNew[PI.l3Offset+8] = glPktTmpL3Hdr[8] - 1;
                tmpNewIpChksum = incrUpdChksum16( tmpNewIpChksum, {glPktTmpL3Hdr[8], glPktTmpL3Hdr[9]}, {glPktNew[PI.l3Offset+8], glPktTmpL3Hdr[9]} );
            }
            // DSCP
            if( PI.replaceDscp ) {
                glPktNew[PI.l3Offset+1][7:2] = DsRegEgrPriorMapVal.dscp[5:0];
                tmpNewIpChksum = incrUpdChksum16( tmpNewIpChksum, {glPktTmpL3Hdr[0], glPktTmpL3Hdr[1]}, {glPktTmpL3Hdr[0], glPktNew[PI.l3Offset+1]} );
            }
            // update checksum
            {glPktNew[PI.l3Offset+10], glPktNew[PI.l3Offset+11]} = tmpNewIpChksum;
        } else if( PI.l3Type == L3_TYPE_IPV6) {
            // TTL
            if( PI.routingEn ) {
                glPktNew[PI.l3Offset+7] = glPktTmpL3Hdr[7] - 1;
            }
            // DSCP
            if( PI.replaceDscp ) {
                glPktNew[PI.l3Offset][3:0]   = DsRegEgrPriorMapVal.dscp[5:2];
                glPktNew[PI.l3Offset+1][7:6] = DsRegEgrPriorMapVal.dscp[1:0];
            }
        }
        // Layer 4 
        glPktTmpL4Hdr[0:19] = glPktNew[PI.l4Offset[6:0] : PI.l4Offset + 19];
        PI.udpChksum[15:0] = (PI.l4Type[3:0] == L4_TYPE_UDP) ?  {glPktTmpL4Hdr[6], glPktTmpL4Hdr[7]} : 0;
        // NAT edit info
        if( PI.routingEn && (PI.opCode == OP_CODE_NAT) && (PI.l3Type == L3_TYPE_IPV4) && 
            ((PI.l4Type == L4_TYPE_UDP) || (PI.l4Type == L4_TYPE_TCP)) ) {

            tmpOldIpSa[31:0]    = {glPktTmpL3Hdr[12], glPktTmpL3Hdr[13], glPktTmpL3Hdr[14], glPktTmpL3Hdr[15]};
            // update Source IP Address
            {glPktNew[PI.l3Offset+12], glPktNew[PI.l3Offset+13], glPktNew[PI.l3Offset+14], glPktNew[PI.l3Offset+15]}  = DsMemNexthopVal.ipSa[31:0]; 
            // update IP checksum as Source IP address update
            tmpUdpChecksum[15:0] = incrUpdChksum32( tmpNewIpChksum, tmpOldIpSa, DsMemNexthopVal.ipSa[31:0] );
            {glPktNew[PI.l3Offset+10], glPktNew[PI.l3Offset+11]} = tmpUdpChecksum;

            // TCP/UDP checksum
            if (PI.l4Type == L4_TYPE_UDP) {
                tmpL4Chksum[15:0] = {glPktTmpL4Hdr[6], glPktTmpL4Hdr[7]};
            } else if (PI.l4Type == L4_TYPE_TCP) {
                tmpL4Chksum[15:0] = {glPktTmpL4Hdr[16], glPktTmpL4Hdr[17]};
            }
                
            // for IP source address update
            tmpL4Chksum1[15:0]  = incrUpdChksum32( tmpL4Chksum, tmpOldIpSa[31:0], DsMemNexthopVal.ipSa[31:0] );
            // for Layer 4 source port update
            {glPktNew[PI.l4Offset+0], glPktNew[PI.l4Offset+1]}= DsMemNexthopVal.l4SrcPort[15:0];
            tmpL4FinalChksum[15:0] = incrUpdChksum16( tmpL4Chksum1, {glPktTmpL4Hdr[0], glPktTmpL4Hdr[1]}, DsMemNexthopVal.l4SrcPort );

            if( PI.l4Type == L4_TYPE_TCP ) {
                {glPktNew[PI.l4Offset+16], glPktNew[PI.l4Offset+17]}  = tmpL4FinalChksum;
            } else if( PI.l4Type == L4_TYPE_UDP ) {
                {glPktNew[PI.l4Offset+6], glPktNew[PI.l4Offset+7]}    = tmpL4FinalChksum;
            }
        }
    }
    // PTP Edit
    if( PI.ptpValid ) {
        tmpPtpOffset[6:0] = PI.l3Type == L3_TYPE_PTP ? PI.l3Offset : 
                            PI.l4Type == L4_TYPE_UDP ? PI.l4Offset + 8 : 0;
        PI.cfOffset[6:0] = tmpPtpOffset + 8;
        if (PI.hasInnerHdr) { 
            PI.cfOffset = PI.cfOffset - 8; 
        }
        glPktTmpPtpHdr[0:33] = glPktNew[tmpPtpOffset : tmpPtpOffset+33]
        PI.cf[63:0]      = {glPktTmpPtpHdr[8], glPktTmpPtpHdr[9], glPktTmpPtpHdr[10], glPktTmpPtpHdr[11], glPktTmpPtpHdr[12], glPktTmpPtpHdr[13], glPktTmpPtpHdr[14], glPktTmpPtpHdr[15]};
        PI.ptpType[3:0]  = glPktTmpPtpHdr[0][3:0];
        PI.tsOp[1:0]     = glPktTmpPtpHdr[6][1:1] == 1 ? PTP_OP_TWO_STEP : tmpCpuTsOp;
        // Sync and Follow_up shall send to master port
        if( PI.ptpEn && DsMemDestPortVal.ptpPortType[1:0] != PTP_PORT_MASTER  && 
            (PI.ptpType == PTP_MSG_SYNC || PI.ptpType == PTP_MSG_FOLLOW_UP) ) {
            PI.discard   = PI.discard | 1;
            PI.ptpPortTypeChkFail    =  1;
        }
        if( PI.l4Type == L4_TYPE_UDP && PI.l3Type == L3_TYPE_IPV4 && CtlEgrEdit.v4PtpUdpChksumSet0 ) {    // UDP checksum is 0
            glPktNew[tmpPtpOffset+6]        = 0;
            glPktNew[tmpPtpOffset+7]        = 0;
        }
    }

    /** Add TSN RTAG */
    if( PI.addRtag ) {
        tmpRtagBuf0[47:0] = { CtlEgrEdit.rtagTpid[15:0], CtlEgrEdit.rtagContent[15:0], PI.rtagSeq[15:0] };
    }

    /** Edit VLAN */
    glPktTmpOtag[0:0] = glPktNew[tmpL2Offset+14 : tmpL2Offset+14];
    tmpOldCos[2:0] = PI.removeVlanTag ? glPktTmpOtag[0][7:5] : DsRegEgrPriorMapVal.cos[2:0];
    tmpCos[2:0]   = PI.replaceCos ? DsRegEgrPriorMapVal.cos[2:0] : tmpOldCos[2:0];
    tmpTpid[15:0] = DsMemDestPortVal.dot1qType[1:1] ? CtlEgrDot1qTpid.tpidOut[15:0] : 16'h8100;
    if( PI.addVlanTag ) {
        tmpPad[0:0] = 0;
        if( DsMemDestPortVal.specifyOutVid ) {
            tmpNewVlanBuf[31:0]    = {tmpTpid[15:0], tmpCos[2:0], tmpPad[0:0], DsMemDestPortVal.specifiedVlanId[11:0]};       
        } else {
            tmpNewVlanBuf[31:0]    = {tmpTpid[15:0], tmpCos[2:0], tmpPad[0:0], PI.vlanId[11:0]};
        }
        if (PI.stagValid) {
            tmpSVlanBuf0 = tmpNewVlanBuf;
        } else if (PI.ctagValid) {
            tmpSVlanBuf0 = tmpNewVlanBuf;
        } else {
            tmpCVlanBuf0 = tmpNewVlanBuf;
        }
    }

    /** Edit CPU Header */
    if( PI.addCpuHdr ) {
        if( PI.pktLength > CtlEgrCpu.maxLength[13:0] ) {
            PI.truncateCpuPkt        = 1;
            tmpPktLength             = CtlEgrCpu.maxLength[13:0];
            PI.pktLength             = tmpPktLength - 16 /** to_cpu_header_length */;
        }
        tmpPktType[0:0]              = PI.cpuPktType!=CPU_PKT_NONE;
        PI.pktType[0:0]              = tmpPktType;
        tmpExcpType[0:0]             = PI.excpType!=EXCP_NONE;
        PI.pktType[1:1]              = tmpExcpType;
        PI.pktType[2:2]              = PI.ptpValid;
        PI.subType[3:0]              = PI.ptpValid ? PI.ptpType : 0;
        PI.pldOffset[6:0] = PI.l4Type != L4_TYPE_NONE ? PI.l4Offset : PI.l3Type != L3_TYPE_NONE ? PI.l3Offset : 0;
        tmpToCpuHdrBuf0[127:120]     = {PI.pktType[3:0], PI.subType[3:0]};
        tmpToCpuHdrBuf0[119:96]      = {PI.vlanId[11:0], PI.pldOffset[6:0], PI.srcPort[4:0]};
        tmpToCpuHdrBuf0[95:80]       = {0, PI.excpType[2:0], PI.cpuPktType[3:0], PI.prior[5:0], PI.version[1:0]};
        tmpToCpuHdrBuf0[79:64]       = {tmpPktLength[13:0], 0[1:0]};
        tmpToCpuHdrBuf0[63:0]        = PI.ingressTs[63:0];
    }

    /** Assemble Packet */
    if( PI.hasInnerHdr && !PI.l2IngSpanPkt ) {      //Remove 8 bytes of CPU header
        PI.removeInnerHdr     = 1;
    }
    PI.updateMacSa = !PI.forbidEdit && (PI.routingEn || (PI.ptpValid && CtlEgrEdit.ptpUpdMacSaEn && PI.ptpEn));
    PI.updateMacDa = !PI.forbidEdit && PI.routingEn;

    if( PI.updateMacDa ) {      // Layer 2 edit info
        tmpMacDaBuf0[47:0] = {DsMemNexthopVal.macDaHi[15:0], DsMemNexthopVal.macDa[31:0]};
        tmpIdx[1:0]       = DsMemNexthopVal.routerMacIdx[1:0];
        tmpNewMacSaLo[31:0] = CtlRouterPktMac.routerMac{tmpIdx[1:0]}[31:0];
        tmpNewMacSaHi[15:0] = CtlRouterPktMac.routerMacHi{tmpIdx[1:0]}[15:0];
        tmpMacSaBuf0[47:0] = {tmpNewMacSaHi[15:0], tmpNewMacSaLo[31:0]};
    } 
    if( PI.ptpValid && CtlEgrEdit.ptpUpdMacSaEn && PI.ptpEn ) {
        tmpNewMacSaLo[31:0] = CtlEgrEdit.ptpMacAddr[31:0];
        tmpNewMacSaHi[15:0] = CtlEgrEdit.ptpMacAddrHi[15:0];
        tmpMacSaBuf0[47:0] = {tmpNewMacSaHi[15:0], tmpNewMacSaLo[31:0]};
    }
    if( PI.validRemoteSpan ) {
        tmpRtagStart += 4;
        tmpCos[2:0] = CtlRemoteSpan.cosValid ? CtlRemoteSpan.cos[2:0] : tmpCos[2:0];
        tmpRspanBuf0[31:0] = {CtlRemoteSpan.tpid[15:0], tmpCos[2:0], tmpPad[0:0], CtlRemoteSpan.vlanId[11:0]};
    }
    
    /** Ptp process sideband info */
    PI.tsOpEn         = 0;
    PI.updatePtpChksum = (PI.l4Type == L4_TYPE_UDP && (!CtlEgrEdit.v4PtpUdpChksumSet0 || CtlEgrEdit.updV6PtpUdpChksum)) || PI.updPtpChksum;
    if (PI.ptpValid && PI.ptpEn && 
        ( ((PI.ptpType == PTP_MSG_PDELAY_RESP) && (PI.tsOp == PTP_OP_ONE_STEP)) || 
          ((CtlEgrEdit.ptpDevType == PTP_DEV_TC_P2P || CtlEgrEdit.ptpDevType == PTP_DEV_TC_E2E) && (PI.tsOp == PTP_OP_ONE_STEP) && (PI.ptpType == PTP_MSG_SYNC)) || 
          ((CtlEgrEdit.ptpDevType == PTP_DEV_TC_E2E) && (PI.ptpType == PTP_MSG_DELAY_REQ)) || 
          ((CtlEgrEdit.cfMissedType[15:0] & (1 << PI.ptpType)) != 0 ) 
        )
       ) {        // Update Correction Field 
        PI.tsOpEn              = 1;
        if (PI.ptpType == PTP_MSG_SYNC && PI.tsOp == PTP_OP_ONE_STEP && CtlEgrEdit.ptpDevType == PTP_DEV_TC_P2P) {
            DsMemEgrSrcPortVal = DsMemEgrSrcPort[ PI.srcPort ];
			tmpCfNs[47:0] = PI.cf[63:16] + DsMemEgrSrcPortVal.pDelay[31:0];  // Propagation delay is added
            PI.latestPtpCf[63:0] = {tmpCfNs[47:0], PI.cf[15:0]};             // assambly Fractional NS
            PI.latestPtpChksum[15:0] = incrUpdChksum64(PI.udpChksum, PI.latestPtpCf, PI.cf);
        } else {
            PI.latestPtpCf     = PI.cf;
            PI.latestPtpChksum = PI.udpChksum;
        }
        // Ingress 2-bit second and 30-bit nano-second is needed for time rewind judgement
        PI.tsOpType[1:0] = 3;
        if ((PI.ptpType == PTP_MSG_PDELAY_RESP) && (PI.tsOp == PTP_OP_ONE_STEP)) {   // one step pdelay_req+T2 -> cpu, cpu send pdelay_resp and put 64-bit ns T2 in cf, mac calculate T3-T2
            PI.tsOpType[1:0] = 0;
        }
        // Update UDP checksum which is at {PI.cfOffset - 10, PI.cfOffset - 9} and correctionField which is at PI.cfOffset.
        PI.updPtpCf     = 1;
    } else if (PI.ptpValid && PI.ptpEn && ((CtlEgrEdit.ptpDevType == PTP_DEV_BC || CtlEgrEdit.ptpDevType == PTP_DEV_OC) && 
                (PI.ptpType == PTP_MSG_SYNC) && (PI.tsOp == PTP_OP_ONE_STEP)) || 
               ((CtlEgrEdit.tsMissedType[15:0] & (1 << PI.ptpType)) != 0)
              ) {      // Update Timestamp
        PI.tsOpEn             = 1;
        PI.tsOpType = 1;
        PI.ts = 0;
        PI.latestPtpCf = 0;
        // Current time second value is needed, mac will fill the nano-second
        // Update UDP checksum if needed which is at {PI.tsOffset - 36, PI.tsOffset - 35} and insert Timestamp.
        PI.updPtpTs     = 1;
    } else if (PI.ptpValid && PI.ptpEn && 
               ( ((PI.ptpType == PTP_MSG_SYNC) && (PI.tsOp == PTP_OP_TWO_STEP)) || (PI.ptpType == PTP_MSG_PDELAY_REQ) ||
                 ((PI.ptpType == PTP_MSG_DELAY_REQ) && (CtlEgrEdit.ptpDevType == PTP_DEV_BC || CtlEgrEdit.ptpDevType == PTP_DEV_OC)) ||
                 ((PI.ptpType == PTP_MSG_PDELAY_RESP) && (PI.tsOp == PTP_OP_TWO_STEP)) 
               ) 
              ) {      // raise interrupt 
        PI.tsOpEn             = 1;
        // Current time second value is needed, mac will fill the nano-second
        PI.tsOpType = 2;
        PI.reserve[5:0] = 6'h20;
        PI.ts = 0;     
        PI.intrPtpTs    = 1;
    }
    
    tmpTsHeaderBuf0[127:120] = {PI.tsOpType[1:0], PI.reserve[5:0]};
    tmpTsHeaderBuf0[119:112] = {PI.updatePtpChksum[0:0], PI.cfOffset[6:0]};
    tmpTsHeaderBuf0[111:96]  = PI.latestPtpChksum[15:0];
    tmpTsHeaderBuf0[95:32]   = PI.latestPtpCf[63:0];
    tmpTsHeaderBuf0[31:0]    = PI.ts[31:0];

    PI.validInnerVlan = (PI.ctagValid && PI.stagValid) || (PI.ctagValid && !PI.stagValid && !PI.removeVlanTag) || (!PI.ctagValid && !PI.stagValid && PI.addVlanTag);
    PI.validOuterVlan = (PI.stagValid && !PI.removeVlanTag) || (PI.stagValid && PI.removeVlanTag && PI.addVlanTag) || (!PI.stagValid && PI.ctagValid && PI.addVlanTag);
    	tmpFldLenBuf[71:64] = PI.validRtag || PI.addRtag ? 134 : 6;
	tmpContentBuf[559:512] = tmpRtagBuf0[47:0];

	tmpFldLenBuf[63:56] = PI.validInnerVlan ? 132 : 4;
	tmpContentBuf[511:480] = tmpCVlanBuf0[31:0];

	tmpFldLenBuf[55:48] = PI.validOuterVlan ? 132 : 4;
	tmpContentBuf[479:448] = tmpSVlanBuf0[31:0];

	tmpFldLenBuf[47:40] = PI.validRemoteSpan ? 132 : 4;
	tmpContentBuf[447:416] = tmpRspanBuf0[31:0];

	tmpFldLenBuf[39:32] = 134;
	tmpContentBuf[415:368] = tmpMacSaBuf0[47:0];

	tmpFldLenBuf[31:24] = 134;
	tmpContentBuf[367:320] = tmpMacDaBuf0[47:0];

	tmpFldLenBuf[23:16] = PI.hasInnerHdr&&!PI.removeInnerHdr ? 136 : 8;
	tmpContentBuf[319:256] = tmpFromInnerHdrBuf0[63:0];

	tmpFldLenBuf[15:8] = PI.addCpuHdr ? 144 : 16;
	tmpContentBuf[255:128] = tmpToCpuHdrBuf0[127:0];

	tmpFldLenBuf[7:0] = PI.tsOpEn ? 144 : 16;
	tmpContentBuf[127:0] = tmpTsHeaderBuf0[127:0];

	//strip all old header
	glPktNew = glPktNew + PI.l3Offset;
	HeaderEdit( glPktNew, tmpFldLenBuf, tmpContentBuf );


    /** Deliver Packet to destination port */
    if( PI.discard ) {
        // discard packet;
    } else if( PI.tsOpEn ) {
        tmpTsUpdSignal   = 1;          // This signal shall deliever to MAC
        tmpEgrExcpSignal = PI.egrExcp;
        PI.pktLength    += 16;
        // Deliver glPktNew to PI.destPort[2:0] with glChanneId[5:0], tmpTsUpdSignal and tmpEgrExcpSignal.
    }
    CtlEgrLog.vlanId[11:0] = PI.vlanId[11:0];
    CtlEgrLog.excpType[2:0] = PI.excpType[2:0];
    CtlEgrLog.opCode[2:0] = PI.opCode[2:0];
    CtlEgrLog.egrDiscard = PI.egrDiscard;
    CtlEgrLog.routedPkt = PI.routedPkt;
    CtlEgrLog.removeCpuHdr = PI.removeCpuHdr;
    CtlEgrLog.addCpuHdr = PI.addCpuHdr;
    CtlEgrLog.updateMacDa = PI.updateMacDa;
    CtlEgrLog.updateMacSa = PI.updateMacSa;
    CtlEgrLog.removeVlanTag = PI.removeVlanTag;
    CtlEgrLog.addVlanTag = PI.addVlanTag;
    CtlEgrLog.remoteSpan = PI.remoteSpan;
    CtlEgrLog.addRtag = PI.addRtag;
    CtlEgrLog.replaceCos = PI.replaceCos;
    CtlEgrLog.replaceDscp = PI.replaceDscp;
    CtlEgrLog.egrStpChkFail = PI.egrStpChkFail;
    CtlEgrLog.ptpPortTypeChkFail = PI.ptpPortTypeChkFail;
    CtlEgrLog.ptpType[15:0] = PI.ptpType[15:0];
    CtlEgrLog.updPtpTs = PI.updPtpTs;
    CtlEgrLog.updPtpCf = PI.updPtpCf;
    CtlEgrLog.intrPtpTs = PI.intrPtpTs;
    CtlEgrLog.xconErr = PI.xconErr;
    CtlEgrLog.truncateCpuPkt = PI.truncateCpuPkt;
}

static function EgrOamProc(DsMemDestPortVal, DsMemDestVlanVal, PI) {
    if (!PI.forceDest && !PI.egrExcp) {
        tmpDiscard[0:0] = CtlEgrOam.oamObeyDiscard[PI.destPort:PI.destPort];
        if (!tmpDiscard && (PI.l3Type == L3_TYPE_ETH_OAM)
            && DsMemDestPortVal.portEthOamEn && DsMemDestVlanVal.vlanEthOamEn) {
            tmpNeedLookup[0:0] = 1;
        }

        if (tmpNeedLookup) {
            tmpKeyBuf[23:0] = {0, PI.destPort[2:0], PI.vlanId[11:0]};
            tmpHashIdx[7:0] = Hash1(tmpKeyBuf);
            DsMemEgrOamKeyVal = DsMemEgrOamKey[tmpHashIdx];

    
            tmpCfgKey[23:0] = DsMemEgrOamKeyVal.key0;
            if (DsMemEgrOamKeyVal.valid[0:0] && (tmpCfgKey == tmpKeyBuf)) {
                tmpUpMepIdx[9:0] = (tmpHashIdx[7:0] << 2) + 0;
                tmpHit[0:0] = 1;
            }
    
            tmpCfgKey[23:0] = DsMemEgrOamKeyVal.key1;
            if (DsMemEgrOamKeyVal.valid[1:1] && (tmpCfgKey == tmpKeyBuf)) {
                tmpUpMepIdx[9:0] = (tmpHashIdx[7:0] << 2) + 1;
                tmpHit[0:0] = 1;
            }
    
            tmpCfgKey[23:0] = DsMemEgrOamKeyVal.key2;
            if (DsMemEgrOamKeyVal.valid[2:2] && (tmpCfgKey == tmpKeyBuf)) {
                tmpUpMepIdx[9:0] = (tmpHashIdx[7:0] << 2) + 2;
                tmpHit[0:0] = 1;
            }
    
            tmpCfgKey[23:0] = DsMemEgrOamKeyVal.key3;
            if (DsMemEgrOamKeyVal.valid[3:3] && (tmpCfgKey == tmpKeyBuf)) {
                tmpUpMepIdx[9:0] = (tmpHashIdx[7:0] << 2) + 3;
                tmpHit[0:0] = 1;
            }
    

            tmpOamValid[0:0] = 0;
            if (tmpHit) {
                tmpOamValid = 1;
                DsMemEgrOamSessionVal = DsMemEgrOamSession[tmpUpMepIdx];
            } else {
                //Not found, just do normal forwarding.
            }

            if (tmpOamValid) {

                tmpMelBit[7:0] = DsMemEgrOamSessionVal.mdlBmp;
                tmpMelGreater[0:0] = 0;

                tmpJ = 0;
                tmpK = 0;
    
            if (tmpMelBit[0:0]) {
                tmpJ++;
                if (PI.cfmMdl == 0) {
                    tmpMdlHit[0:0] = 1;
                } else if (PI.cfmMdl > 0) {
                    tmpK++;
                }
            }
    
            if (tmpMelBit[1:1]) {
                tmpJ++;
                if (PI.cfmMdl == 1) {
                    tmpMdlHit[0:0] = 1;
                } else if (PI.cfmMdl > 1) {
                    tmpK++;
                }
            }
    
            if (tmpMelBit[2:2]) {
                tmpJ++;
                if (PI.cfmMdl == 2) {
                    tmpMdlHit[0:0] = 1;
                } else if (PI.cfmMdl > 2) {
                    tmpK++;
                }
            }
    
            if (tmpMelBit[3:3]) {
                tmpJ++;
                if (PI.cfmMdl == 3) {
                    tmpMdlHit[0:0] = 1;
                } else if (PI.cfmMdl > 3) {
                    tmpK++;
                }
            }
    
            if (tmpMelBit[4:4]) {
                tmpJ++;
                if (PI.cfmMdl == 4) {
                    tmpMdlHit[0:0] = 1;
                } else if (PI.cfmMdl > 4) {
                    tmpK++;
                }
            }
    
            if (tmpMelBit[5:5]) {
                tmpJ++;
                if (PI.cfmMdl == 5) {
                    tmpMdlHit[0:0] = 1;
                } else if (PI.cfmMdl > 5) {
                    tmpK++;
                }
            }
    
            if (tmpMelBit[6:6]) {
                tmpJ++;
                if (PI.cfmMdl == 6) {
                    tmpMdlHit[0:0] = 1;
                } else if (PI.cfmMdl > 6) {
                    tmpK++;
                }
            }
    
            if (tmpMelBit[7:7]) {
                tmpJ++;
                if (PI.cfmMdl == 7) {
                    tmpMdlHit[0:0] = 1;
                } else if (PI.cfmMdl > 7) {
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
                     PI.discard = 1;
                     PI.xconErr = 1;
                }

                if (tmpCcmTerminated) {
                    tmpMepPtr[12:0] = DsMemEgrOamSessionVal.mepBasePtr[12:0] + PI.cfmMdl;
                    PI.oamEgrIdxValid = 1;
                }
            }

            if (PI.oamEgrIdxValid) {
                DsMemEgrMepPtrVal = DsMemEgrMepPtr[ tmpMepPtr ];
                PI.oamIdx[10:0] = DsMemEgrMepPtrVal.oamIdx[10:0];
            }
        }
    }
}

    
