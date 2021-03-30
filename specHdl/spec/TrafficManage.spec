
static int getEnqueueIpv( port, MsgAdmInfo ) {
    tmpPrior[2:0]                 = 0;
    tmpState                      = TSN_GATE_CLOSE;
    
    if (port == CtlCommon.cpuPortNo) {         // cpu port do not care about tsn
        tmpState                  = TSN_GATE_OPEN;
        tmpPrior[2:0]             = MsgAdmInfo.cpuPrior[5:3];
    } else {                        // Line ports
        if ((CtlEnqCfg.tsnEn[31:0] & (1 << port)) && MsgAdmInfo.isTsn) {
            tmpState              = TSN_GATE_CLOSE;
            if (CtlPtpTimerEn.enable[MsgAdmInfo.tsnCycleSel : MsgAdmInfo.tsnCycleSel] && CtlPtpTimerEn.enable[MsgAdmInfo.tsnCycleSel+1 : MsgAdmInfo.tsnCycleSel+1]) {
                DsMemTsnGateVal   = DsMemTsnGate[ MsgAdmInfo.tsnGateId[10:0] ];
                DsRegPtpTimer0Val = DsRegPtpTimer[ MsgAdmInfo.tsnCycleSel ];
                DsRegPtpTimer1Val = DsRegPtpTimer[ MsgAdmInfo.tsnCycleSel+1 ];
                tmpClock0         = DsRegPtpTimer0Val.value;       // read current clock value
                tmpClock1         = DsRegPtpTimer1Val.value;       // read current clock value
                if ((CtlEnqCfg.gateOnly && DsMemTsnGateVal.state0) || (tmpClock0 && DsMemTsnGateVal.state0)) {              // Active high
                    tmpPrior[2:0] = DsMemTsnGateVal.ipv0;
                    tmpState      = TSN_GATE_OPEN;
                } else if ((CtlEnqCfg.gateOnly && DsMemTsnGateVal.state1) || (tmpClock1 && DsMemTsnGateVal.state1)) {
                    tmpPrior[2:0] = DsMemTsnGateVal.ipv1;
                    tmpState      = TSN_GATE_OPEN;
                }
            }
        } else if ((CtlEnqCfg.tsnEn[31:0] & (1 << port)) && !MsgAdmInfo.isTsn) {      // all packet is treated as normal
            tmpState              = TSN_GATE_OPEN;
            tmpPrior[2:0]         = CtlEnqCfg.ipv{ MsgAdmInfo.prior[5:3] }[2:0];
        } else {                                               // TSN disable
            tmpState              = TSN_GATE_OPEN;
            tmpPrior[2:0]         = MsgAdmInfo.prior[5:3];
        }
    }
    return {tmpPrior[2:0], tmpState};
}

static void Egress(tMsgAdmInfo *msg, uint8_t *packet) {
    tPktInfo *EPI = (tPktInfo *)calloc(sizeof(tPktInfo), 1);
    PacketEdit( EPI, packet, msg );
    //ASIC: push MsgAdmInfo0 into LogiRepBuf;
    if( !EPI.discard ) {
        int pktLen = EPI.pktLength;
        if ( 0 != (EPI.lenAdjust & (1 << 5)) ) {
            pktLen -= EPI.lenAdjust & 0x1f;    
        } else {
            pktLen += EPI.lenAdjust;        
        }
        if (EPI.destPort == CPU_PORT && EPI.egrExcp == 1) {
            pktLen = 64;
        }
        if (EPI.tsOpEn) {
            saveRxPacket( packet, pktLen-4, EPI.destPort);  // -4: save packet without crc
        #if CFG_DUMP == 1
            saveCosimPkt(packet + 16, pktLen-4-16, OUT_PKT, EPI.destPort);
        #endif
        } else {
            saveRxPacket( packet, pktLen-4, EPI.destPort);  // -4: save packet without crc
        #if CFG_DUMP == 1
            saveCosimPkt( packet, pktLen-4, OUT_PKT, EPI.destPort );
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

function AdmissionControl(PI, ts[63:0], hdrBufPtr[12:0], tailBufPtr[12:0]) {
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

    tmpFwdBmp[7:0] = MsgIgr2Adm.fwdBitmap;
    int i;
    //ASIC: Physical Replication
    for (i = 0; i < 8; i++ ) {
        if( tmpFwdBmp[i:i] & CtlEnqCfg.enqEnBmp[i:i] ) {
            MsgAdmInfo.destPort[4:0]      = i;
            if( i == CtlCommon.cpuPortNo ) {
                tmpExcpType[4:0] = 5'h10 + MsgAdmInfo.excpType[4:0];
                tmpPriorIdx[4:0]  = (MsgAdmInfo.cpuPktType[3:0] != CPU_PKT_NONE) ? MsgAdmInfo.cpuPktType : tmpExcpType;
                DsRegCpuPktPriorVal = DsRegCpuPktPrior[ tmpPriorIdx ];
                MsgAdmInfo.cpuPrior[5:0] = DsRegCpuPktPriorVal.prior[5:0];
            }
            tmpEnqInfo[3:0] = getEnqueueIpv(i, MsgAdmInfo);
            CtlAdmLog.enqIpv[2:0]      = tmpEnqInfo[3:1];
            CtlAdmLog.gateState        = tmpEnqInfo[0:0];
            if (tmpEnqInfo[0:0] == TSN_GATE_CLOSE) {
                MsgAdmInfo.fwdBitmap[i : i]        = 0;
                CtlAdmLog.gateCloseCnt[31:0] += 1;
            }
            tmpQid[7:0] = { i, tmpEnqInfo[3:1] };
            DsRegQueueDropVal = DsRegQueueDrop[ i ];
            if (DsRegQueueDropVal.tailDropSet[tmpQid : tmpQid]) {
                MsgAdmInfo.fwdBitmap[i : i]  = 0;
                CtlAdmLog.tailDropCnt[31:0] += 1;
            } else if (DsRegQueueDropVal.wredSet[tmpQid : tmpQid]) {
                tmpRandom[0:0]   = funcRandom(0, 1);
                MsgAdmInfo.fwdBitmap[i : i]  = tmpRandom;
                if (tmpRandom == 0) {
                    CtlAdmLog.wredCnt[31:0] += 1;
                }
            }
            if (MsgAdmInfo.fwdBitmap[i:i]) {
                uint8_t tmpPacket[2048] = {0}; 
                memcpy(tmpPacket, glPkt, MsgAdmInfo.pktLength);
                Egress( MsgAdmInfo, tmpPacket);
                //ASIC:  Push MsgAdmInfo into TM queue according tmpQid[7:0];
            }
        }
    }
    // Logical Replication
    tmpFwdExtBmp[5:0] = MsgIgr2Adm.fwdBitmapW1;
    for (i = 0; i < 6; i++) {
        if( tmpFwdExtBmp[i : i] ) {
            MsgAdmInfo0 = MsgAdmInfo;
            tmpIdx[2:0] = i;
            tmpDestPort[2:0] = CtlRepExtPort.destPort{tmpIdx[2:0]-2}[2:0];
            MsgAdmInfo0.destPort = tmpDestPort;
            MsgAdmInfo0.extendIdx[2:0]  = i;
            MsgAdmInfo0.extendFlag      = 1;
            tmpEnqInfo[3:0] = getEnqueueIpv(i, MsgAdmInfo);
            tmpQid[7:0] = { i, tmpEnqInfo[3:1] };
            uint8_t tmpPacket[2048] = {0}; 
            memcpy(tmpPacket, glPkt, MsgAdmInfo.pktLength);
            Egress(MsgAdmInfo0, tmpPacket);
        }
    }
}

//ASIC: tMsgAdmInfo tmpMsgAdmInfo = Get AdmCntlInfo if it is valid.;
//ASIC: function PacketReplicate(MsgAdmInfo) {
//ASIC:     for (i = 0; i <  8; i++ ) {
//ASIC:         if( MsgAdmInfo.fwdBitmap[i:i] ) {
//ASIC:             tmpDestPort[4:0] = i;
//ASIC:             tmpEnqInfo[3:0] = getEnqueueIpv(i, MsgAdmInfo);
//ASIC:             tmpQid[7:0]           = { tmpDestPort, tmpEnqInfo[3:1] };
//ASIC:         //Change channelId[3:3] = CtlEnqCfg.tsnEn ? MsgAdmInfo.isTsn : 1;
//ASIC:         }
//ASIC:     } // end of for
//ASIC: }
    
