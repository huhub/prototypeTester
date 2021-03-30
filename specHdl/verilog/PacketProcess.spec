
function PacketProcess(PI) {
    PI.gapValue       = CtlPpGapConfig.gapValue[0:0]{PI.srcPort};

    /** Routing Process */
    if (PI.routingEn && !PI.bypassPp && (PI.hostRouteLeftHit || PI.hostRouteRightHit)) {
        DsMemRouteVal = DsMemHostRoute[PI.ipRouteIdx[5:0]];
    
        DsMemRouteTsnVal = DsMemHostTsn[PI.ipRouteIdx[5:0]];
        PI.isTsn       = (PI.isTsn || DsMemRouteTsnVal.isTsn) && PI.tsnEn;
        PI.tsnHandle   = DsMemRouteTsnVal.tsnHandle;
        PI.isTsn[1:1]= PI.isTsn;
        PI.tsnHandle = PI.tsnHandle;
    
        PI.destMap = DsMemRouteVal.destMap;
        PI.nexthopIdx = DsMemRouteVal.nexthopIdx;
        PI.flowPolicePtr = DsMemRouteVal.flowPolicePtr;
        PI.flowPoliceValid = DsMemRouteVal.flowPoliceValid;
        PI.flowStatsValid = DsMemRouteVal.flowStatsValid; 
        PI.flowStatsPtr = DsMemRouteVal.flowStatsPtr < 191 ? DsMemRouteVal.flowStatsPtr : 191; 
        PI.opCode = PI.nexthopIdx[5:5] ? OP_CODE_MCAST : OP_CODE_UCAST;
        PI.igrFlowSpan = DsMemRouteVal.mirrorEn;
        PI.discard = PI.discard | DsMemRouteVal.discard;
        PI.routeDiscard = DsMemRouteVal.discard;
        if (DsMemRouteVal.copyToCpu ) {
            PI.copyToCpu        = 1;
            PI.cpuPktType  = CPU_PKT_ROUTELKP;
        }
        if (DsMemRouteVal.nat ) {
            PI.opCode      = OP_CODE_NAT;
        }
        if (PI.ipOptions || PI.otherHeader || (PI.ttl <= 1) ) {
            PI.discard               = PI.discard | 1;
            PI.exception             = 1;
            PI.routeExcpDiscard = 1;
            PI.excpType    = EXCP_ROUTE;
        }
    }

    /** Bridging Process */
    PI.bridgeProcess = !PI.bypassPp && !PI.routingEn;
    PI.destMacKnown  = PI.macDaLValid || PI.macDaRValid;
    tmpLagMap[10:0] = 11'h400 + PI.linkAggId[4:0];
    tmpLagPort[4:0] = {1, PI.linkAggId[4:0]};
    if (PI.bridgeProcess && PI.destMacKnown) {
        DsMemMacVal = DsMemMac[ PI.macDaIdx ];
        PI.entryPend = DsMemMacVal.pending;
        if (!PI.entryPend) {
    
            DsMemMacTsnVal = DsMemMacTsn[ PI.macDaIdx ];
            PI.isTsn     = (PI.isTsn || DsMemMacTsnVal.isTsn) && PI.tsnEn;
            PI.tsnHandle = DsMemMacTsnVal.tsnHandle;
            PI.isTsn[2:2]= PI.isTsn;
            PI.tsnHandle = PI.tsnHandle;
    
            PI.flowPolicePtr  = DsMemMacVal.flowPolicePtr;
            PI.flowPoliceValid= DsMemMacVal.flowPoliceValid;
            PI.flowStatsValid= DsMemMacVal.flowStatsValid; 
            PI.flowStatsPtr  = DsMemMacVal.flowStatsPtr < 191 ? DsMemMacVal.flowStatsPtr : 191; 
            PI.destMap       = DsMemMacVal.destMap;
            PI.opCode        = DsMemMacVal.isMcast ? OP_CODE_MCAST : OP_CODE_UCAST;
            PI.igrFlowSpan   = DsMemMacVal.mirrorEn;
            tmpSrcMap[10:0]= PI.isLinkAggMbr ? tmpLagMap : PI.srcPort[2:0];
            if (PI.l2SrcMatchDiscard && (tmpSrcMap == DsMemMacVal.destMap) && !DsMemMacVal.isMcast ) {
                PI.discard                = PI.discard | 1;
                PI.l2UcastSrcMatchDiscard = 1;
            }
            PI.discard = PI.discard | DsMemMacVal.dstDiscard;
            tmpMacDaDiscard = DsMemMacVal.dstDiscard;
            if (DsMemMacVal.copyToCpu ) {
                PI.copyToCpu              = 1;
                PI.cpuPktType        = CPU_PKT_MACDALKP;
            }
        }
    }

    /** For custome specified forwarding */
    if (PI.cuMacHit) {
        DsMemCustomFdbVal = DsMemCustomFdb[ PI.cuMacIdx }
    } else if (PI.cuMacPcpHit) {
        DsMemCustomFdbVal = DsMemCustomFdb[ PI.cuMacPcpIdx }
    } else if (PI.cuIpDscpHit) {
        DsMemCustomFdbVal = DsMemCustomFdb[ PI.cuIpDscpIdx }
    } else if (PI.cuIpSportHit) {
        DsMemCustomFdbVal = DsMemCustomFdb[ PI.cuIpSportIdx }
    } else if (PI.cuIpDportHit) {
        DsMemCustomFdbVal = DsMemCustomFdb[ PI.cuIpDportIdx }
    } 
    if ((PI.cuMacHit || PI.cuMacPcpHit || PI.cuIpDscpHit || PI.cuIpSportHit || PI.cuIpDscpHit) &&
        !PI.bypassPp) {
        PI.isTsn          = DsMemCustomFdbVal.isTsn;
        PI.tsnHandle      = DsMemCustomFdbVal.tsnHandle;
        PI.flowPolicePtr  = DsMemCustomFdbVal.flowPolicePtr;
        PI.flowPoliceValid= DsMemCustomFdbVal.flowPoliceValid;
        PI.flowStatsValid = DsMemCustomFdbVal.flowStatsValid; 
        PI.flowStatsPtr   = DsMemCustomFdbVal.flowStatsPtr < 191 ? DsMemCustomFdbVal.flowStatsPtr : 191; 
        PI.destMap        = DsMemCustomFdbVal.destMap;
        PI.opCode         = DsMemCustomFdbVal.isMcast ? OP_CODE_MCAST : OP_CODE_UCAST;
        PI.igrFlowSpan    = DsMemCustomFdbVal.mirrorEn;
        if (PI.srcPort != DsMemCustomFdbVal) {
            PI.discard    = 1;
        }
        if (PI.srcPort == PI.destMap) {
            PI.discard    = 1;
        }
    }
    if (PI.bridgeProcess) {
        tmpBpduDrop       = PI.isBpdu && (PI.bpduDrop || (PI.stpState == STP_DISCARD));
        if ((tmpBpduDrop) || (!PI.isBpdu && (PI.stpState[1:0] != STP_FWD)) ) {
            PI.discard    = PI.discard | 1;
            PI.igrStpCheckDiscard = 1;
        }
        if (PI.isBpdu && !tmpBpduDrop ) {
            PI.copyToCpu  = 1;
            PI.discard    = PI.discard | 1;
            PI.cpuPktType = CPU_PKT_BPDU;
        }
    }

    tmpEthPr = findPrByType( PROTO_TYPE_ETH );
    if (PI.bridgeProcess && CtlStormCntl.enable[0:0]) {
        tmpStormCtlPkt            = 1;
        tmpStormCtlEn             = 0;
        if (tmpEthPr.qualifier[0:0] ) {        // bcast mac
            tmpStormCtlPtr[4:0] = {2, PI.logicalPort};
        } else if (tmpEthPr.qualifier[1:1] ) {   // mcast mac
            tmpStormCtlPtr   = {1, PI.logicalPort};
        } else if (!PI.macDaLValid && !PI.macDaRValid) {
            tmpStormCtlPtr   = {0, PI.logicalPort};
        } else { 
            tmpStormCtlPkt        =0; 
        }
        
        if (tmpStormCtlPkt ) {
            DsMemStormCtrlVal     = DsMemStormCtrl[ tmpStormCtlPtr ];
            DsMemStormVal         = DsMemStorm[ tmpStormCtlPtr ];
            tmpStormCtlEn         = DsMemStormCtrlVal.stormCtrlEn & !PI.discard;
        }
        if (tmpStormCtlEn && !PI.fromRemoteSpan ) {
            if (DsMemStormVal.runningCounter >= DsMemStormCtrlVal.threshold ) {
                PI.stormDrop      = 1;
                PI.discard        = PI.discard | 1;
            } else {
                if (DsMemStormCtrlVal.usePktCount ) {
                    DsMemStormVal.runningCounter = DsMemStormVal.runningCounter + 1;
                } else {
                    DsMemStormVal.runningCounter = DsMemStormVal.runningCounter + PI.pktLength + PI.gapValue;
                }
                DsMemStorm[ tmpStormCtlPtr ] = DsMemStormVal;
            }
        }
    }


    /** Learning Prerequisites */
    if (!PI.discard && !PI.lrnDisable && (PI.stpState != STP_DISCARD) ) {
        tmpSrcPortIdx[4:0] = PI.isLinkAggMbr ? tmpLagPort : PI.srcPort;
        PI.srcMap = PI.isLinkAggMbr ? tmpLagMap : PI.srcPort;
        MsgLearnInfo.macSa[31:0] = PI.macSa[31:0];
        MsgLearnInfo.macSaHi[15:0] = PI.macSaHi[15:0];
        MsgLearnInfo.fid[11:0] = PI.fid[11:0];
        MsgLearnInfo.lrnType[2:0] = PI.lrnType[2:0];
        MsgLearnInfo.learnIdx[6:0] = PI.learnIdx[6:0];
        MsgLearnInfo.srcPortIdx[4:0] = PI.srcPortIdx[4:0];
        MsgLearnInfo.srcMap[10:0] = PI.srcMap[10:0];
        // violation check
        tmpNeedLearn             = 1;
        DsRegPortLearnCtrlVal    = DsRegPortLearnCtrl[ tmpSrcPortIdx ];
        PI.lrnPortLockDiscard    = DsRegPortLearnCtrlVal.lock;
        if (DsRegPortLearnCtrlVal.lock ) {
            PI.discard           = PI.discard | 1;
            tmpNeedLearn         = 0;
            if (DsRegPortLearnCtrlVal.violationToCpu ) {
                PI.exception     = PI.exception | 1;
                PI.excpType      = EXCP_LOCKVIOLATION;
            }
        }
        DsRegPortLearnNumVal     = DsRegPortLearnNum[ tmpSrcPortIdx ];
        tmpExceed  = DsRegPortLearnNumVal.learntMacNum[6:0] >= DsRegPortLearnCtrlVal.maxMacNum[6:0] ;
        PI.lrnNumExceedDiscard = DsRegPortLearnCtrlVal.macNumLimitEn && tmpExceed;
        if (PI.lrnNumExceedDiscard ) {
            PI.discard          |= DsRegPortLearnCtrlVal.lrnNumExceedDiscard;
            tmpNeedLearn         = 0;
            if (DsRegPortLearnCtrlVal.violationToCpu ) {
                PI.exception     = PI.exception | 1;
                PI.excpType      = EXCP_MACNUMLIMITVIOLATION;
            }
        }
        // add to learn fifo 
        PI.cpuFifoFullNum = CtlPktProcLog.cpuFifoFullNum[0:0];
        PI.hwFifoFullNum  = CtlPktProcLog.hwFifoFullNum[0:0];
        if (tmpNeedLearn && CtlMacLearn.cpuLearnEn[0:0] ) {
            // Push learnInfo into CpuLearnFifo;
            CtlMacLearn.cpuLearnNum[0:0]  += 1;
            CtlMacLearn.cpuFifoDepth[0:0] += 1;
            if (CtlMacLearn.cpuFifoDepth[0:0] > CtlMacLearn.cpuLrnNumThrd[0:0] ) {
                PI.cpuFifoFullNum += 1;
            }
        } else if (tmpNeedLearn && !CtlMacLearn.cpuLearnEn[0:0] ) {
            // Push learnInfo into HwLearnFifo;
            CtlMacLearn.hwLearnNum[0:0]  += 1;
            CtlMacLearn.hwFifoDepth[0:0] += 1;
            if (CtlMacLearn.hwFifoDepth[0:0] > CtlMacLearn.hwLrnNumThrd[0:0] ) {
                PI.hwFifoFullNum += 1;
            } else {
                FdbLearning( MsgLearnInfo );
            }
        }
    }
    CtlPktProcLog.cpuFifoFullNum[15:0] = PI.cpuFifoFullNum[15:0];
    CtlPktProcLog.hwFifoFullNum[15:0] = PI.hwFifoFullNum[15:0];
    CtlPktProcLog.aclQosLogEn[0:0] = PI.aclQosLogEn;
    CtlPktProcLog.aclDiscard[0:0] = PI.aclDiscard;
    CtlPktProcLog.routeDiscard[0:0] = PI.routeDiscard;
    CtlPktProcLog.routeExcpDiscard[0:0] = PI.routeExcpDiscard;
    CtlPktProcLog.routeProcess[0:0] = PI.routeProcess;
    CtlPktProcLog.bridgeProcess[0:0] = PI.bridgeProcess;
    CtlPktProcLog.destMacKnown[0:0] = PI.destMacKnown;
    CtlPktProcLog.l2UcastSrcMatchDiscard[0:0] = PI.l2UcastSrcMatchDiscard;
    CtlPktProcLog.macDaDiscard[0:0] = PI.macDaDiscard;
    CtlPktProcLog.igrStpCheckDiscard[0:0] = PI.igrStpCheckDiscard;
    CtlPktProcLog.stormDrop[0:0] = PI.stormDrop;
    CtlPktProcLog.lrnPortLockDiscard[0:0] = PI.lrnPortLockDiscard;
    CtlPktProcLog.lrnNumExceedDiscard[0:0] = PI.lrnNumExceedDiscard;
    CtlPktProcLog.isTsn[2:0] = PI.isTsn[2:0];
    CtlPktProcLog.tsnHandle[4:0] = PI.tsnHandle[4:0];
    CtlPktProcLog.igrFlowSpan[0:0] = PI.igrFlowSpan;
    CtlPktProcLog.entryPend[0:0] = PI.entryPend;

}

process StormCtrlUpdate() {
    while ( CtlStormCntl.enable[0:0] ) {
        tmpStormPtr[4:0]  = CtlStormCntl.stormCurPtr;
        DsMemStormCtrlVal = DsMemStormCtrl[ tmpStormPtr ];
        DsMemStormVal     = DsMemStorm[ tmpStormPtr ];
        if (DsMemStormVal.runningCounter >= DsMemStormCtrlVal.threshold ) {
            DsMemStormVal.runningCounter -= DsMemStormCtrlVal.threshold;
        } else {
            DsMemStormVal.runningCounter = 0;
        }
        DsMemStorm[ tmpStormPtr ] = DsMemStormVal;
        DelayCycle( CtlStormCntl.stormInterval[0:0] );
        // update pointer
        CtlStormCntl.stormCurPtr[0:0] = tmpStormPtr + 1;
        if (CtlStormCntl.stormCurPtr[0:0] >= CtlStormCntl.stormMaxPtr[0:0]) {
            CtlStormCntl.stormCurPtr[0:0] = CtlStormCntl.stormMinPtr[0:0];
			DelayCycle( CtlStormCntl.stormFinalDelay[0:0] );
            // update round
            CtlStormCntl.stormCurRound[0:0][0:0][0:0]   = (CtlStormCntl.stormCurRound[0:0][0:0][0:0] + 1) >= CtlStormCntl.stormUpdRound[0:0] ? 0 : CtlStormCntl.stormCurRound[0:0][0:0][0:0] + 1;
        }
    }
}

    