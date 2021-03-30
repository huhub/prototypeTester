
    
function Redundancy(PI) {
    if( PI.isTsn ) {
        DsMemHandle2StreamIdVal = DsMemHandle2StreamId[ PI.tsnHandle ];
        PI.tsnStreamId = DsMemHandle2StreamIdVal.streamId;
        CtlRcvyLog.tsnStreamId[0:0] = PI.tsnStreamId;
    }
    if( !PI.discard && PI.isTsn ) {
        individualRecovery(PI);
    }
    if( !PI.discard && PI.isTsn ) {
        mergeRecovery(PI);
    }
    CtlRcvyLog.rtagSeq[0:0]   = PI.rtagSeq;
}
#if 0
// Latent Error Test does not implement because  multiplier is needed and the period is 2s default. 
void latentErrorTest () {
    int diff = CurBaseDifference - ((DsMemStreamRcvyCnt.flowPassedPkts[0:0] *
               (DsMemStreamRcvyCfg.redundancyPaths[3:0] - 1)) - DsMemStreamRcvyCnt.flowDiscardPkts);
    if (DsMemStreamRcvyCfg.redundancyPaths[3:0] > 1 && // There are multiple paths
    frerSeqRcvyLatentErrorPeriod > 0 ) { // LE detection is turned on
        if (diff < 0)
            diff = - diff;
        if (diff > frerSeqRcvyLatentErrorDifference) {
            SIGNAL_LATENT_ERROR;
        }
    }
}
// The CurBaseDifference needed by Latent Error Test is calculated per 30s default.
void latentErrorReset () {
    CurBaseDifference = (DsMemStreamRcvyCnt.flowPassedPkts[0:0] *
                        (DsMemStreamRcvyCfg.redundancyPaths[3:0] - 1)) - DsMemStreamRcvyCnt.flowDiscardPkts;

    DsMemStreamRcvySeq.latentErrorResetCnt[0:0] +=  1;
}
#endif 
static function individualRecovery(PI) {
    DsMemIndvRcvyCfgVal  = DsMemIndvRcvyCfg[ PI.tsnHandle ];
    DsMemIndvRcvySeqVal  = DsMemIndvRcvySeq[ PI.tsnHandle ];
    DsMemIndvRcvyCntVal  = DsMemIndvRcvyCnt[ PI.tsnHandle ];
	tmpDiscardLog[3:0]   = 4'h0;
	tmpSeqDeltaLog[15:0] = 16'h0;
	
    if( DsMemIndvRcvyCfgVal.frerRcvyAlg == RCVY_VECTOR ) {
        vectorRecoveryAlgorithm(DsMemIndvRcvyCfgVal, DsMemIndvRcvySeqVal, DsMemIndvRcvyCntVal, tmpDiscardLog, tmpSeqDeltaLog, PI);
    } else if( DsMemIndvRcvyCfgVal.frerRcvyAlg == RCVY_MATCH ) {
        matchRecoveryAlgorithm(DsMemIndvRcvyCfgVal, DsMemIndvRcvySeqVal, DsMemIndvRcvyCntVal, tmpDiscardLog, tmpSeqDeltaLog, PI);
    }
    DsMemIndvRcvySeq[ PI.tsnHandle ] = DsMemIndvRcvySeqVal;
    DsMemIndvRcvyCnt[ PI.tsnHandle ] = DsMemIndvRcvyCntVal;
    CtlRcvyLog.discardIndv[0:0]  = tmpDiscardLog;
    CtlRcvyLog.seqDeltaIndv[0:0] = tmpSeqDeltaLog;
}

static function mergeRecovery(PI) {
    DsMemStreamRcvyCfgVal = DsMemStreamRcvyCfg[ PI.tsnStreamId ];
    DsMemStreamRcvySeqVal = DsMemStreamRcvySeq[ PI.tsnStreamId ];
    DsMemStreamRcvyCntVal = DsMemStreamRcvyCnt[ PI.tsnStreamId ];
	tmpDiscardLog[3:0]    = 4'h0;
	tmpSeqDeltaLog[15:0]  = 16'h0;

    if( DsMemStreamRcvyCfgVal.frerRcvyAlg == RCVY_VECTOR ) {
        vectorRecoveryAlgorithm(DsMemStreamRcvyCfgVal, DsMemStreamRcvySeqVal, DsMemStreamRcvyCntVal, tmpDiscardLog, tmpSeqDeltaLog, PI);
    } else if( DsMemStreamRcvyCfgVal.frerRcvyAlg == RCVY_MATCH ) {
        matchRecoveryAlgorithm(DsMemStreamRcvyCfgVal, DsMemStreamRcvySeqVal, DsMemStreamRcvyCntVal, tmpDiscardLog, tmpSeqDeltaLog, PI);
    }
    DsMemStreamRcvySeq[ PI.tsnStreamId ] = DsMemStreamRcvySeqVal;
    DsMemStreamRcvyCnt[ PI.tsnStreamId ] = DsMemStreamRcvyCntVal;
    CtlRcvyLog.discardMerg[0:0] = tmpDiscardLog;
    CtlRcvyLog.seqDeltaMerg[0:0] = tmpSeqDeltaLog;
}

static function matchRecoveryAlgorithm(DsMemRcvyCfg, DsMemRcvySeq, DsMemRcvyCnt, discardLog, deltaLog, PI) {
    if( !PI.rtagValid ) {
        DsMemRcvyCnt.flowTaglessPkts[0:0]     += 1;
        DsMemRcvyCnt.flowPassedPkts[0:0]      += 1;
        DsMemRcvyCnt.portPassedPkts[0:0]      += 1;
    } else { 
        tmpDelta[15:0] = (PI.rtagSeq - DsMemRcvySeq.rcvySeq) & 16'hFFFF;
        deltaLog[15:0]                      = tmpDelta[15:0];
        if( DsMemRcvySeq.takeAny[0:0] ) {
            DsMemRcvySeq.takeAny[0:0]                = 0;
            DsMemRcvySeq.rcvySeq[0:0]                = PI.rtagSeq;
            DsMemRcvyCnt.flowPassedPkts[0:0]  += 1;
            DsMemRcvyCnt.portPassedPkts[0:0]  += 1;
            DsMemRcvySeq.remainTicks[0:0]      = DsMemRcvyCfg.resetTicks[0:0];
        } else if( tmpDelta == 0 ) {          // History
            DsMemRcvyCnt.flowDiscardPkts[0:0] += 1;
            DsMemRcvyCnt.portDiscardPkts[0:0] += 1;
            PI.discard                      = PI.discard | 1'h1;
            discardLog[0:0]         = 1'h1;
            if( DsMemRcvyCfg.illegalPktReset[0:0] ) {
                DsMemRcvySeq.remainTicks[0:0]        = DsMemRcvyCfg.resetTicks[0:0];
            }
        } else {
            if( tmpDelta != 1 ) {
                DsMemRcvyCnt.flowOutOrderCnt[0:0]   += 1;
            }
            DsMemRcvySeq.rcvySeq[0:0]                = PI.rtagSeq;
            DsMemRcvyCnt.flowPassedPkts[0:0]  += 1;
            DsMemRcvyCnt.portPassedPkts[0:0]  += 1;
            DsMemRcvySeq.remainTicks[0:0]      = DsMemRcvyCfg.resetTicks[0:0];
        }   
    }
}

static function vectorRecoveryAlgorithm(DsMemRcvyCfg, DsMemRcvySeq, DsMemRcvyCnt, discardLog, deltaLog, PI) {
    if( !PI.rtagValid ) {
        DsMemRcvyCnt.flowTaglessPkts[0:0]     += 1;
        if( DsMemRcvyCfg.frerAcceptNoSeq[0:0] ) {
            DsMemRcvyCnt.flowPassedPkts[0:0]  += 1;
            DsMemRcvyCnt.portPassedPkts[0:0]  += 1;
            DsMemRcvySeq.remainTicks[0:0]      = DsMemRcvyCfg.resetTicks[0:0];
        } else {
            DsMemRcvyCnt.flowDiscardPkts[0:0] += 1;
            DsMemRcvyCnt.portDiscardPkts[0:0] += 1;
            PI.discard                      = PI.discard | 1'h1;
            discardLog[1:1]         = 1'h1;
        }
    } else {
        tmpDelta[15:0] = (PI.rtagSeq - DsMemRcvySeq.rcvySeq) & 16'hFFFF;
        tmpIsHistory   = PI.rtagSeq == DsMemRcvySeq.rcvySeq[0:0] || (tmpDelta & 16'h8000) != 0;
        if( (tmpDelta & 16'h8000) != 0 ) {
            tmpDelta   = 16'hFFFF - tmpDelta + 1;
        }
        deltaLog[15:0]                       = tmpDelta[15:0];
        if( DsMemRcvySeq.takeAny[0:0] ) {
            DsMemRcvySeq.takeAny[0:0]                 = 0;
            DsMemRcvySeq.rcvySeq[0:0]                 = PI.rtagSeq;
            DsMemRcvySeq.seqHistory[0:0]        = 32'h1;
            DsMemRcvyCnt.flowPassedPkts[0:0]   += 1;
            DsMemRcvyCnt.portPassedPkts[0:0]   += 1;
            DsMemRcvySeq.remainTicks[0:0]       = DsMemRcvyCfg.resetTicks[0:0];
        } else if( tmpDelta > DsMemRcvyCfg.historyLen[0:0] ) {      // Out-of-range
            DsMemRcvyCnt.flowRoguePkts[0:0]    += 1;
            DsMemRcvyCnt.portDiscardPkts[0:0]  += 1;
            PI.discard                       = PI.discard | 1'h1;
            discardLog[2:2]          = 1'h1;
            if( DsMemRcvyCfg.illegalPktReset[0:0] ) {
                DsMemRcvySeq.remainTicks[0:0]         = DsMemRcvyCfg.resetTicks[0:0];
            }
        } else if( tmpIsHistory ) {                             // History sequence number
            if( (DsMemRcvySeq.seqHistory[0:0] & (1 << tmpDelta)) == 0 ) { // Has not received
                DsMemRcvySeq.seqHistory[0:0]            |= (1 << tmpDelta);
                DsMemRcvyCnt.flowOutOrderCnt[0:0] += 1;
                DsMemRcvyCnt.flowPassedPkts[0:0]  += 1;
                DsMemRcvyCnt.portPassedPkts[0:0]  += 1;
                DsMemRcvySeq.remainTicks[0:0]      = DsMemRcvyCfg.resetTicks[0:0];
            } else {
                DsMemRcvyCnt.flowDiscardPkts[0:0]       += 1;
                DsMemRcvyCnt.portDiscardPkts[0:0]       += 1;
                PI.discard                      = PI.discard | 1'h1;
                discardLog[3:3]         = 1'h1;
                if( DsMemRcvyCfg.illegalPktReset[0:0] ) {
                    DsMemRcvySeq.remainTicks[0:0]        = DsMemRcvyCfg.resetTicks[0:0];
                }
            }
        } else {
            if( tmpDelta != 1 ) {
                DsMemRcvyCnt.flowOutOrderCnt[0:0]       += 1;
            }
            DsMemRcvySeq.rcvySeq[0:0]                    = PI.rtagSeq;
            DsMemRcvySeq.seqHistory[0:0][0:0]                 = (DsMemRcvySeq.seqHistory[0:0][0:0] << tmpDelta) | 16'h1;
            DsMemRcvyCnt.flowPassedPkts[0:0]      += 1;
            DsMemRcvyCnt.portPassedPkts[0:0]      += 1;
            DsMemRcvySeq.remainTicks[0:0]          = DsMemRcvyCfg.resetTicks[0:0];
        }
    }
}

static function sequenceRecoveryReset(DsMemRcvyCfg, DsMemRcvySeq) {
    if( DsMemRcvyCfg.frerRcvyAlg[0:0]  == RCVY_VECTOR ) {
        DsMemRcvySeq.seqHistory[0:0]  = 0;
        DsMemRcvySeq.rcvySeq[0:0]     = 16'hFFFF;
    }
    DsMemRcvySeq.rcvyResetCnt[0:0]   += 1;
    DsMemRcvySeq.takeAny[0:0]               = 1;
}

process RcvyIndvResetTimer() {
    tmpIndex[12:0]      = 0;
    tmpCycleCnt[31:0]   = 0;
    while( CtlRcvy.indvSeqResetEn[0:0] ) {
        tmpCycleCnt ++;
        if( tmpCycleCnt >= CtlRcvy.indvDelayPerEntry[0:0] ) {
            tmpCycleCnt = 0;
            DsMemIndvRcvyCfgVal     = DsMemIndvRcvyCfg[ tmpIndex ];
            DsMemIndvRcvySeqVal     = DsMemIndvRcvySeq[ tmpIndex ];
            if( !DsMemIndvRcvySeqVal.takeAny ) {
                if( DsMemIndvRcvySeqVal.remainTicks > CtlRcvy.indvMinusCycle[0:0] ) {
                    DsMemIndvRcvySeqVal.remainTicks  -= CtlRcvy.indvMinusCycle[0:0];
                } else {
                    DsMemIndvRcvySeqVal.remainTicks   = 0;
                    sequenceRecoveryReset(DsMemIndvRcvyCfgVal, DsMemIndvRcvySeqVal);
                }
                // Write DsMemIndvRcvySeqVal back;
                DsMemIndvRcvySeq[ tmpIndex ] = DsMemIndvRcvySeqVal;
            }
            tmpIndex ++;
        }
    }
}

process RcvyMergeResetTimer() {
    tmpIndex[10:0]      = 0;
    tmpCycleCnt[31:0]   = 0;
    while( CtlRcvy.mergeSeqResetEn[0:0] ) {
        tmpCycleCnt ++;
        if( tmpCycleCnt >= CtlRcvy.mergeDelayPerEntry[0:0] ) {
            tmpCycleCnt = 0;
            DsMemStreamRcvyCfgVal   = DsMemStreamRcvyCfg[ tmpIndex ];
            DsMemStreamRcvySeqVal   = DsMemStreamRcvySeq[ tmpIndex ];
            if( !DsMemStreamRcvySeqVal.takeAny ) {
                if( DsMemStreamRcvySeqVal.remainTicks > CtlRcvy.mergeMinusCycle[0:0] ) {
                    DsMemStreamRcvySeqVal.remainTicks  -= CtlRcvy.mergeMinusCycle[0:0];
                } else {
                    DsMemStreamRcvySeqVal.remainTicks   = 0;
                    sequenceRecoveryReset(DsMemStreamRcvyCfgVal, DsMemStreamRcvySeqVal);
                }
                // Write DsMemStreamRcvySeqVal back;
                DsMemStreamRcvySeq[ tmpIndex ] = DsMemStreamRcvySeqVal;
            }
            tmpIndex ++;
        }
    }
}
    
    