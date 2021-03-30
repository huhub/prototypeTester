
function PacketProcess(PI) {
    PI.gapValue       = CtlPpGapConfig.gapValue{PI.srcPort};

    /** Routing Process */
    if (PI.routingEn && !PI.bypassPp && (PI.hostRouteLeftHit || PI.hostRouteRightHit)) {
        DsMemRouteVal = DsMemHostRoute[PI.ipRouteIdx];
    
        DsMemRouteTsnVal = DsMemHostTsn[PI.ipRouteIdx];
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
    tmpLagMap[10:0] = 11'h400 + PI.linkAggId;
    tmpLagPort[4:0] = {1, PI.linkAggId};
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
            tmpSrcMap[10:0]= PI.isLinkAggMbr ? tmpLagMap : PI.srcPort;
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
        if ((tmpBpduDrop) || (!PI.isBpdu && (PI.stpState != STP_FWD)) ) {
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
    if (PI.bridgeProcess && CtlStormCntl.enable) {
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
        MsgLearnInfo.macSa = PI.macSa;
        MsgLearnInfo.macSaHi = PI.macSaHi;
        MsgLearnInfo.fid = PI.fid;
        MsgLearnInfo.lrnType = PI.lrnType;
        MsgLearnInfo.learnIdx = PI.learnIdx;
        MsgLearnInfo.srcPortIdx = PI.srcPortIdx;
        MsgLearnInfo.srcMap = PI.srcMap;
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
        tmpExceed  = DsRegPortLearnNumVal.learntMacNum >= DsRegPortLearnCtrlVal.maxMacNum;
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
        PI.cpuFifoFullNum = CtlPktProcLog.cpuFifoFullNum;
        PI.hwFifoFullNum  = CtlPktProcLog.hwFifoFullNum;
        if (tmpNeedLearn && CtlMacLearn.cpuLearnEn ) {
            // Push learnInfo into CpuLearnFifo;
            CtlMacLearn.cpuLearnNum  += 1;
            CtlMacLearn.cpuFifoDepth += 1;
            if (CtlMacLearn.cpuFifoDepth > CtlMacLearn.cpuLrnNumThrd ) {
                PI.cpuFifoFullNum += 1;
            }
        } else if (tmpNeedLearn && !CtlMacLearn.cpuLearnEn ) {
            // Push learnInfo into HwLearnFifo;
            CtlMacLearn.hwLearnNum  += 1;
            CtlMacLearn.hwFifoDepth += 1;
            if (CtlMacLearn.hwFifoDepth > CtlMacLearn.hwLrnNumThrd ) {
                PI.hwFifoFullNum += 1;
            } else {
                FdbLearning( MsgLearnInfo );
            }
        }
    }
    CtlPktProcLog.cpuFifoFullNum = PI.cpuFifoFullNum;
    CtlPktProcLog.hwFifoFullNum = PI.hwFifoFullNum;
    CtlPktProcLog.aclQosLogEn = PI.aclQosLogEn;
    CtlPktProcLog.aclDiscard = PI.aclDiscard;
    CtlPktProcLog.routeDiscard = PI.routeDiscard;
    CtlPktProcLog.routeExcpDiscard = PI.routeExcpDiscard;
    CtlPktProcLog.routeProcess = PI.routeProcess;
    CtlPktProcLog.bridgeProcess = PI.bridgeProcess;
    CtlPktProcLog.destMacKnown = PI.destMacKnown;
    CtlPktProcLog.l2UcastSrcMatchDiscard = PI.l2UcastSrcMatchDiscard;
    CtlPktProcLog.macDaDiscard = PI.macDaDiscard;
    CtlPktProcLog.igrStpCheckDiscard = PI.igrStpCheckDiscard;
    CtlPktProcLog.stormDrop = PI.stormDrop;
    CtlPktProcLog.lrnPortLockDiscard = PI.lrnPortLockDiscard;
    CtlPktProcLog.lrnNumExceedDiscard = PI.lrnNumExceedDiscard;
    CtlPktProcLog.isTsn = PI.isTsn;
    CtlPktProcLog.tsnHandle = PI.tsnHandle;
    CtlPktProcLog.igrFlowSpan = PI.igrFlowSpan;
    CtlPktProcLog.entryPend = PI.entryPend;

}

process StormCtrlUpdate() {
    while ( CtlStormCntl.enable ) {
        tmpStormPtr[4:0]  = CtlStormCntl.stormCurPtr;
        DsMemStormCtrlVal = DsMemStormCtrl[ tmpStormPtr ];
        DsMemStormVal     = DsMemStorm[ tmpStormPtr ];
        if (DsMemStormVal.runningCounter >= DsMemStormCtrlVal.threshold ) {
            DsMemStormVal.runningCounter -= DsMemStormCtrlVal.threshold;
        } else {
            DsMemStormVal.runningCounter = 0;
        }
        DsMemStorm[ tmpStormPtr ] = DsMemStormVal;
        DelayCycle( CtlStormCntl.stormInterval );
        // update pointer
        CtlStormCntl.stormCurPtr = tmpStormPtr + 1;
        if (CtlStormCntl.stormCurPtr >= CtlStormCntl.stormMaxPtr) {
            CtlStormCntl.stormCurPtr = CtlStormCntl.stormMinPtr;
			DelayCycle( CtlStormCntl.stormFinalDelay );
            // update round
            CtlStormCntl.stormCurRound   = (CtlStormCntl.stormCurRound + 1) >= CtlStormCntl.stormUpdRound ? 0 : CtlStormCntl.stormCurRound + 1;
        }
    }
}

    
