
    
function Redundancy(PI) {
    if( PI.isTsn ) {
        DsMemHandle2StreamIdVal = DsMemHandle2StreamId[ PI.tsnHandle ];
        PI.tsnStreamId = DsMemHandle2StreamIdVal.streamId;
        CtlRcvyLog.tsnStreamId = PI.tsnStreamId;
    }
    if( !PI.discard && PI.isTsn ) {
        individualRecovery(PI);
    }
    if( !PI.discard && PI.isTsn ) {
        mergeRecovery(PI);
    }
    CtlRcvyLog.rtagSeq   = PI.rtagSeq;
}
#if 0
// Latent Error Test does not implement because  multiplier is needed and the period is 2s default. 
void latentErrorTest () {
    int diff = CurBaseDifference - ((DsMemStreamRcvyCnt.flowPassedPkts *
               (DsMemStreamRcvyCfg.redundancyPaths - 1)) - DsMemStreamRcvyCnt.flowDiscardPkts);
    if (DsMemStreamRcvyCfg.redundancyPaths > 1 && // There are multiple paths
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
    CurBaseDifference = (DsMemStreamRcvyCnt.flowPassedPkts *
                        (DsMemStreamRcvyCfg.redundancyPaths - 1)) - DsMemStreamRcvyCnt.flowDiscardPkts;

    DsMemStreamRcvySeq.latentErrorResetCnt +=  1;
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
    CtlRcvyLog.discardIndv  = tmpDiscardLog;
    CtlRcvyLog.seqDeltaIndv = tmpSeqDeltaLog;
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
    CtlRcvyLog.discardMerg = tmpDiscardLog;
    CtlRcvyLog.seqDeltaMerg = tmpSeqDeltaLog;
}

static function matchRecoveryAlgorithm(DsMemRcvyCfg, DsMemRcvySeq, DsMemRcvyCnt, discardLog, deltaLog, PI) {
    if( !PI.rtagValid ) {
        DsMemRcvyCnt.flowTaglessPkts     += 1;
        DsMemRcvyCnt.flowPassedPkts      += 1;
        DsMemRcvyCnt.portPassedPkts      += 1;
    } else { 
        tmpDelta[15:0] = (PI.rtagSeq - DsMemRcvySeq.rcvySeq) & 16'hFFFF;
        deltaLog[15:0]                      = tmpDelta[15:0];
        if( DsMemRcvySeq.takeAny ) {
            DsMemRcvySeq.takeAny                = 0;
            DsMemRcvySeq.rcvySeq                = PI.rtagSeq;
            DsMemRcvyCnt.flowPassedPkts  += 1;
            DsMemRcvyCnt.portPassedPkts  += 1;
            DsMemRcvySeq.remainTicks      = DsMemRcvyCfg.resetTicks;
        } else if( tmpDelta == 0 ) {          // History
            DsMemRcvyCnt.flowDiscardPkts += 1;
            DsMemRcvyCnt.portDiscardPkts += 1;
            PI.discard                      = PI.discard | 1'h1;
            discardLog[0:0]         = 1'h1;
            if( DsMemRcvyCfg.illegalPktReset ) {
                DsMemRcvySeq.remainTicks        = DsMemRcvyCfg.resetTicks;
            }
        } else {
            if( tmpDelta != 1 ) {
                DsMemRcvyCnt.flowOutOrderCnt   += 1;
            }
            DsMemRcvySeq.rcvySeq                = PI.rtagSeq;
            DsMemRcvyCnt.flowPassedPkts  += 1;
            DsMemRcvyCnt.portPassedPkts  += 1;
            DsMemRcvySeq.remainTicks      = DsMemRcvyCfg.resetTicks;
        }   
    }
}

static function vectorRecoveryAlgorithm(DsMemRcvyCfg, DsMemRcvySeq, DsMemRcvyCnt, discardLog, deltaLog, PI) {
    if( !PI.rtagValid ) {
        DsMemRcvyCnt.flowTaglessPkts     += 1;
        if( DsMemRcvyCfg.frerAcceptNoSeq ) {
            DsMemRcvyCnt.flowPassedPkts  += 1;
            DsMemRcvyCnt.portPassedPkts  += 1;
            DsMemRcvySeq.remainTicks      = DsMemRcvyCfg.resetTicks;
        } else {
            DsMemRcvyCnt.flowDiscardPkts += 1;
            DsMemRcvyCnt.portDiscardPkts += 1;
            PI.discard                      = PI.discard | 1'h1;
            discardLog[1:1]         = 1'h1;
        }
    } else {
        tmpDelta[15:0] = (PI.rtagSeq - DsMemRcvySeq.rcvySeq) & 16'hFFFF;
        tmpIsHistory   = PI.rtagSeq == DsMemRcvySeq.rcvySeq || (tmpDelta & 16'h8000) != 0;
        if( (tmpDelta & 16'h8000) != 0 ) {
            tmpDelta   = 16'hFFFF - tmpDelta + 1;
        }
        deltaLog[15:0]                       = tmpDelta[15:0];
        if( DsMemRcvySeq.takeAny ) {
            DsMemRcvySeq.takeAny                 = 0;
            DsMemRcvySeq.rcvySeq                 = PI.rtagSeq;
            DsMemRcvySeq.seqHistory        = 32'h1;
            DsMemRcvyCnt.flowPassedPkts   += 1;
            DsMemRcvyCnt.portPassedPkts   += 1;
            DsMemRcvySeq.remainTicks       = DsMemRcvyCfg.resetTicks;
        } else if( tmpDelta > DsMemRcvyCfg.historyLen ) {      // Out-of-range
            DsMemRcvyCnt.flowRoguePkts    += 1;
            DsMemRcvyCnt.portDiscardPkts  += 1;
            PI.discard                       = PI.discard | 1'h1;
            discardLog[2:2]          = 1'h1;
            if( DsMemRcvyCfg.illegalPktReset ) {
                DsMemRcvySeq.remainTicks         = DsMemRcvyCfg.resetTicks;
            }
        } else if( tmpIsHistory ) {                             // History sequence number
            if( (DsMemRcvySeq.seqHistory & (1 << tmpDelta)) == 0 ) { // Has not received
                DsMemRcvySeq.seqHistory            |= (1 << tmpDelta);
                DsMemRcvyCnt.flowOutOrderCnt += 1;
                DsMemRcvyCnt.flowPassedPkts  += 1;
                DsMemRcvyCnt.portPassedPkts  += 1;
                DsMemRcvySeq.remainTicks      = DsMemRcvyCfg.resetTicks;
            } else {
                DsMemRcvyCnt.flowDiscardPkts       += 1;
                DsMemRcvyCnt.portDiscardPkts       += 1;
                PI.discard                      = PI.discard | 1'h1;
                discardLog[3:3]         = 1'h1;
                if( DsMemRcvyCfg.illegalPktReset ) {
                    DsMemRcvySeq.remainTicks        = DsMemRcvyCfg.resetTicks;
                }
            }
        } else {
            if( tmpDelta != 1 ) {
                DsMemRcvyCnt.flowOutOrderCnt       += 1;
            }
            DsMemRcvySeq.rcvySeq                    = PI.rtagSeq;
            DsMemRcvySeq.seqHistory                 = (DsMemRcvySeq.seqHistory << tmpDelta) | 16'h1;
            DsMemRcvyCnt.flowPassedPkts      += 1;
            DsMemRcvyCnt.portPassedPkts      += 1;
            DsMemRcvySeq.remainTicks          = DsMemRcvyCfg.resetTicks;
        }
    }
}

static function sequenceRecoveryReset(DsMemRcvyCfg, DsMemRcvySeq) {
    if( DsMemRcvyCfg.frerRcvyAlg  == RCVY_VECTOR ) {
        DsMemRcvySeq.seqHistory  = 0;
        DsMemRcvySeq.rcvySeq     = 16'hFFFF;
    }
    DsMemRcvySeq.rcvyResetCnt   += 1;
    DsMemRcvySeq.takeAny               = 1;
}

process RcvyIndvResetTimer() {
    tmpIndex[12:0]      = 0;
    tmpCycleCnt[31:0]   = 0;
    while( CtlRcvy.indvSeqResetEn ) {
        tmpCycleCnt ++;
        if( tmpCycleCnt >= CtlRcvy.indvDelayPerEntry ) {
            tmpCycleCnt = 0;
            DsMemIndvRcvyCfgVal     = DsMemIndvRcvyCfg[ tmpIndex ];
            DsMemIndvRcvySeqVal     = DsMemIndvRcvySeq[ tmpIndex ];
            if( !DsMemIndvRcvySeqVal.takeAny ) {
                if( DsMemIndvRcvySeqVal.remainTicks > CtlRcvy.indvMinusCycle ) {
                    DsMemIndvRcvySeqVal.remainTicks  -= CtlRcvy.indvMinusCycle;
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
    while( CtlRcvy.mergeSeqResetEn ) {
        tmpCycleCnt ++;
        if( tmpCycleCnt >= CtlRcvy.mergeDelayPerEntry ) {
            tmpCycleCnt = 0;
            DsMemStreamRcvyCfgVal   = DsMemStreamRcvyCfg[ tmpIndex ];
            DsMemStreamRcvySeqVal   = DsMemStreamRcvySeq[ tmpIndex ];
            if( !DsMemStreamRcvySeqVal.takeAny ) {
                if( DsMemStreamRcvySeqVal.remainTicks > CtlRcvy.mergeMinusCycle ) {
                    DsMemStreamRcvySeqVal.remainTicks  -= CtlRcvy.mergeMinusCycle;
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
    
    
