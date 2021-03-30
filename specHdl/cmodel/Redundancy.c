/*
 * cmodel for Pishon
 * @file: Redundancy
 * @description: auto generage
 * @note: Copyright (C) 2021-03-29 12:40:57.484248
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
#include <mem/RedundancyOpr.h>
#include <mem/Redundancy.h>

void Redundancy(tPktInfo *PI) {

	tCtlRcvyLog CtlRcvyLogTmp = {0};
	tCtlRcvyLog *CtlRcvyLog = &CtlRcvyLogTmp;
	readCtlRcvyLog("CtlRcvyLog", 0, CtlRcvyLog, 0);
	tDsMemHandle2StreamId DsMemHandle2StreamIdValTmp = {0};
	tDsMemHandle2StreamId *DsMemHandle2StreamIdVal = &DsMemHandle2StreamIdValTmp;

    if( PI->isTsn ) {
        rpcRdMem("DsMemHandle2StreamId", PI->tsnHandle, DsMemHandle2StreamIdVal);
        PI->tsnStreamId = DsMemHandle2StreamIdVal->streamId;
        CtlRcvyLog->tsnStreamId = PI->tsnStreamId;
    }
    if( !PI->discard && PI->isTsn ) {
        individualRecovery(PI);
    }
    if( !PI->discard && PI->isTsn ) {
        mergeRecovery(PI);
    }
    CtlRcvyLog->rtagSeq   = PI->rtagSeq;
}
#if 0
// Latent Error Test does not implement because  multiplier is needed and the period is 2s default. 
void latentErrorTest () {
    int diff = CurBaseDifference - ((DsMemStreamRcvyCnt->flowPassedPkts *
               (DsMemStreamRcvyCfg->redundancyPaths - 1)) - DsMemStreamRcvyCnt->flowDiscardPkts);
    if (DsMemStreamRcvyCfg->redundancyPaths > 1 && // There are multiple paths
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
    CurBaseDifference = (DsMemStreamRcvyCnt->flowPassedPkts *
                        (DsMemStreamRcvyCfg->redundancyPaths - 1)) - DsMemStreamRcvyCnt->flowDiscardPkts;
    DsMemStreamRcvySeq->latentErrorResetCnt +=  1;
}
#endif 
static void individualRecovery(tPktInfo *PI) {
	uint16_t tmpSeqDeltaLog = 0;
	uint8_t tmpDiscardLog = 0;

	tDsMemRcvyCfg DsMemIndvRcvyCfgValTmp = {0};
	tDsMemRcvyCfg *DsMemIndvRcvyCfgVal = &DsMemIndvRcvyCfgValTmp;
	tCtlRcvyLog CtlRcvyLogTmp = {0};
	tCtlRcvyLog *CtlRcvyLog = &CtlRcvyLogTmp;
	readCtlRcvyLog("CtlRcvyLog", 0, CtlRcvyLog, 0);
	tDsMemRcvyCnt DsMemIndvRcvyCntValTmp = {0};
	tDsMemRcvyCnt *DsMemIndvRcvyCntVal = &DsMemIndvRcvyCntValTmp;
	tDsMemRcvySeq DsMemIndvRcvySeqValTmp = {0};
	tDsMemRcvySeq *DsMemIndvRcvySeqVal = &DsMemIndvRcvySeqValTmp;

    rpcRdMem("DsMemIndvRcvyCfg", PI->tsnHandle, DsMemIndvRcvyCfgVal);
    rpcRdMem("DsMemIndvRcvySeq", PI->tsnHandle, DsMemIndvRcvySeqVal);
    rpcRdMem("DsMemIndvRcvyCnt", PI->tsnHandle, DsMemIndvRcvyCntVal);
	tmpDiscardLog   = 0x0;
	tmpSeqDeltaLog = 0x0;
    if( DsMemIndvRcvyCfgVal->frerRcvyAlg == RCVY_VECTOR ) {
        vectorRecoveryAlgorithm(DsMemIndvRcvyCfgVal, DsMemIndvRcvySeqVal, DsMemIndvRcvyCntVal, tmpDiscardLog, tmpSeqDeltaLog, PI);
    } else if( DsMemIndvRcvyCfgVal->frerRcvyAlg == RCVY_MATCH ) {
        matchRecoveryAlgorithm(DsMemIndvRcvyCfgVal, DsMemIndvRcvySeqVal, DsMemIndvRcvyCntVal, tmpDiscardLog, tmpSeqDeltaLog, PI);
    }
    rpcSetMem( "DsMemIndvRcvySeq", PI->tsnHandle , DsMemIndvRcvySeqVal, sizeof(tDsMemRcvySeq) );
    rpcSetMem( "DsMemIndvRcvyCnt", PI->tsnHandle , DsMemIndvRcvyCntVal, sizeof(tDsMemRcvyCnt) );
    CtlRcvyLog->discardIndv  = tmpDiscardLog;
    CtlRcvyLog->seqDeltaIndv = tmpSeqDeltaLog;
}
static void mergeRecovery(tPktInfo *PI) {
	uint16_t tmpSeqDeltaLog = 0;
	uint8_t tmpDiscardLog = 0;

	tDsMemRcvySeq DsMemStreamRcvySeqValTmp = {0};
	tDsMemRcvySeq *DsMemStreamRcvySeqVal = &DsMemStreamRcvySeqValTmp;
	tCtlRcvyLog CtlRcvyLogTmp = {0};
	tCtlRcvyLog *CtlRcvyLog = &CtlRcvyLogTmp;
	readCtlRcvyLog("CtlRcvyLog", 0, CtlRcvyLog, 0);
	tDsMemRcvyCfg DsMemStreamRcvyCfgValTmp = {0};
	tDsMemRcvyCfg *DsMemStreamRcvyCfgVal = &DsMemStreamRcvyCfgValTmp;
	tDsMemRcvyCnt DsMemStreamRcvyCntValTmp = {0};
	tDsMemRcvyCnt *DsMemStreamRcvyCntVal = &DsMemStreamRcvyCntValTmp;

    rpcRdMem("DsMemStreamRcvyCfg", PI->tsnStreamId, DsMemStreamRcvyCfgVal);
    rpcRdMem("DsMemStreamRcvySeq", PI->tsnStreamId, DsMemStreamRcvySeqVal);
    rpcRdMem("DsMemStreamRcvyCnt", PI->tsnStreamId, DsMemStreamRcvyCntVal);
	tmpDiscardLog    = 0x0;
	tmpSeqDeltaLog  = 0x0;
    if( DsMemStreamRcvyCfgVal->frerRcvyAlg == RCVY_VECTOR ) {
        vectorRecoveryAlgorithm(DsMemStreamRcvyCfgVal, DsMemStreamRcvySeqVal, DsMemStreamRcvyCntVal, tmpDiscardLog, tmpSeqDeltaLog, PI);
    } else if( DsMemStreamRcvyCfgVal->frerRcvyAlg == RCVY_MATCH ) {
        matchRecoveryAlgorithm(DsMemStreamRcvyCfgVal, DsMemStreamRcvySeqVal, DsMemStreamRcvyCntVal, tmpDiscardLog, tmpSeqDeltaLog, PI);
    }
    rpcSetMem( "DsMemStreamRcvySeq", PI->tsnStreamId , DsMemStreamRcvySeqVal, sizeof(tDsMemRcvySeq) );
    rpcSetMem( "DsMemStreamRcvyCnt", PI->tsnStreamId , DsMemStreamRcvyCntVal, sizeof(tDsMemRcvyCnt) );
    CtlRcvyLog->discardMerg = tmpDiscardLog;
    CtlRcvyLog->seqDeltaMerg = tmpSeqDeltaLog;
}
static void matchRecoveryAlgorithm(uint8_t DsMemRcvyCfg, uint8_t DsMemRcvySeq, uint8_t DsMemRcvyCnt, uint8_t discardLog, uint8_t deltaLog, tPktInfo *PI) {
	uint16_t tmpDelta = 0;


    if( !PI->rtagValid ) {
        DsMemRcvyCnt->flowTaglessPkts     += 1;
        DsMemRcvyCnt->flowPassedPkts      += 1;
        DsMemRcvyCnt->portPassedPkts      += 1;
    } else { 
        tmpDelta = (PI->rtagSeq - DsMemRcvySeq->rcvySeq) & 0xFFFF;
        SET_BITS(deltaLog, 0, 15, ( GET_BITS(tmpDelta, 0, 15)));
        if( DsMemRcvySeq->takeAny ) {
            DsMemRcvySeq->takeAny                = 0;
            DsMemRcvySeq->rcvySeq                = PI->rtagSeq;
            DsMemRcvyCnt->flowPassedPkts  += 1;
            DsMemRcvyCnt->portPassedPkts  += 1;
            DsMemRcvySeq->remainTicks      = DsMemRcvyCfg->resetTicks;
        } else if( tmpDelta == 0 ) {          // History
            DsMemRcvyCnt->flowDiscardPkts += 1;
            DsMemRcvyCnt->portDiscardPkts += 1;
            PI->discard                      = PI->discard | 0x1;
            SET_BITS(discardLog, 0, 0, (0x1));
            if( DsMemRcvyCfg->illegalPktReset ) {
                DsMemRcvySeq->remainTicks        = DsMemRcvyCfg->resetTicks;
            }
        } else {
            if( tmpDelta != 1 ) {
                DsMemRcvyCnt->flowOutOrderCnt   += 1;
            }
            DsMemRcvySeq->rcvySeq                = PI->rtagSeq;
            DsMemRcvyCnt->flowPassedPkts  += 1;
            DsMemRcvyCnt->portPassedPkts  += 1;
            DsMemRcvySeq->remainTicks      = DsMemRcvyCfg->resetTicks;
        }   
    }
}
static void vectorRecoveryAlgorithm(uint8_t DsMemRcvyCfg, uint8_t DsMemRcvySeq, uint8_t DsMemRcvyCnt, uint8_t discardLog, uint8_t deltaLog, tPktInfo *PI) {
	uint8_t tmpIsHistory = 0;
	uint16_t tmpDelta = 0;
	uint8_t tmpDelta = 0;


    if( !PI->rtagValid ) {
        DsMemRcvyCnt->flowTaglessPkts     += 1;
        if( DsMemRcvyCfg->frerAcceptNoSeq ) {
            DsMemRcvyCnt->flowPassedPkts  += 1;
            DsMemRcvyCnt->portPassedPkts  += 1;
            DsMemRcvySeq->remainTicks      = DsMemRcvyCfg->resetTicks;
        } else {
            DsMemRcvyCnt->flowDiscardPkts += 1;
            DsMemRcvyCnt->portDiscardPkts += 1;
            PI->discard                      = PI->discard | 0x1;
            SET_BITS(discardLog, 1, 1, (0x1));
        }
    } else {
        tmpDelta = (PI->rtagSeq - DsMemRcvySeq->rcvySeq) & 0xFFFF;
        tmpIsHistory   = PI->rtagSeq == DsMemRcvySeq->rcvySeq || (tmpDelta & 0x8000) != 0;
        if( (tmpDelta & 0x8000) != 0 ) {
            tmpDelta   = 0xFFFF - tmpDelta + 1;
        }
        SET_BITS(deltaLog, 0, 15, ( GET_BITS(tmpDelta, 0, 15)));
        if( DsMemRcvySeq->takeAny ) {
            DsMemRcvySeq->takeAny                 = 0;
            DsMemRcvySeq->rcvySeq                 = PI->rtagSeq;
            DsMemRcvySeq->seqHistory        = 0x1;
            DsMemRcvyCnt->flowPassedPkts   += 1;
            DsMemRcvyCnt->portPassedPkts   += 1;
            DsMemRcvySeq->remainTicks       = DsMemRcvyCfg->resetTicks;
        } else if( tmpDelta > DsMemRcvyCfg->historyLen ) {      // Out-of-range
            DsMemRcvyCnt->flowRoguePkts    += 1;
            DsMemRcvyCnt->portDiscardPkts  += 1;
            PI->discard                       = PI->discard | 0x1;
            SET_BITS(discardLog, 2, 2, (0x1));
            if( DsMemRcvyCfg->illegalPktReset ) {
                DsMemRcvySeq->remainTicks         = DsMemRcvyCfg->resetTicks;
            }
        } else if( tmpIsHistory ) {                             // History sequence number
            if( (DsMemRcvySeq->seqHistory & (1 << tmpDelta)) == 0 ) { // Has not received
                DsMemRcvySeq->seqHistory            |= (1 << tmpDelta);
                DsMemRcvyCnt->flowOutOrderCnt += 1;
                DsMemRcvyCnt->flowPassedPkts  += 1;
                DsMemRcvyCnt->portPassedPkts  += 1;
                DsMemRcvySeq->remainTicks      = DsMemRcvyCfg->resetTicks;
            } else {
                DsMemRcvyCnt->flowDiscardPkts       += 1;
                DsMemRcvyCnt->portDiscardPkts       += 1;
                PI->discard                      = PI->discard | 0x1;
                SET_BITS(discardLog, 3, 3, (0x1));
                if( DsMemRcvyCfg->illegalPktReset ) {
                    DsMemRcvySeq->remainTicks        = DsMemRcvyCfg->resetTicks;
                }
            }
        } else {
            if( tmpDelta != 1 ) {
                DsMemRcvyCnt->flowOutOrderCnt       += 1;
            }
            DsMemRcvySeq->rcvySeq                    = PI->rtagSeq;
            DsMemRcvySeq->seqHistory                 = (DsMemRcvySeq->seqHistory << tmpDelta) | 0x1;
            DsMemRcvyCnt->flowPassedPkts      += 1;
            DsMemRcvyCnt->portPassedPkts      += 1;
            DsMemRcvySeq->remainTicks          = DsMemRcvyCfg->resetTicks;
        }
    }
}
static void sequenceRecoveryReset(uint8_t DsMemRcvyCfg, uint8_t DsMemRcvySeq) {


    if( DsMemRcvyCfg->frerRcvyAlg  == RCVY_VECTOR ) {
        DsMemRcvySeq->seqHistory  = 0;
        DsMemRcvySeq->rcvySeq     = 0xFFFF;
    }
    DsMemRcvySeq->rcvyResetCnt   += 1;
    DsMemRcvySeq->takeAny               = 1;
}
void RcvyIndvResetTimer(uint8_t ) {
	uint8_t tmpCycleCnt = 0;
	uint8_t tmpIndex = 0;
	uint16_t tmpIndex = 0;
	uint32_t tmpCycleCnt = 0;

	tDsMemRcvyCfg DsMemIndvRcvyCfgValTmp = {0};
	tDsMemRcvyCfg *DsMemIndvRcvyCfgVal = &DsMemIndvRcvyCfgValTmp;
	tCtlRcvy CtlRcvyTmp = {0};
	tCtlRcvy *CtlRcvy = &CtlRcvyTmp;
	readCtlRcvy("CtlRcvy", 0, CtlRcvy, 0);
	tDsMemRcvySeq DsMemIndvRcvySeqValTmp = {0};
	tDsMemRcvySeq *DsMemIndvRcvySeqVal = &DsMemIndvRcvySeqValTmp;

    tmpIndex      = 0;
    tmpCycleCnt   = 0;
    while( CtlRcvy->indvSeqResetEn ) {
        tmpCycleCnt ++;
        if( tmpCycleCnt >= CtlRcvy->indvDelayPerEntry ) {
            tmpCycleCnt = 0;
            rpcRdMem("DsMemIndvRcvyCfg", tmpIndex, DsMemIndvRcvyCfgVal);
            rpcRdMem("DsMemIndvRcvySeq", tmpIndex, DsMemIndvRcvySeqVal);
            if( !DsMemIndvRcvySeqVal->takeAny ) {
                if( DsMemIndvRcvySeqVal->remainTicks > CtlRcvy->indvMinusCycle ) {
                    DsMemIndvRcvySeqVal->remainTicks  -= CtlRcvy->indvMinusCycle;
                } else {
                    DsMemIndvRcvySeqVal->remainTicks   = 0;
                    sequenceRecoveryReset(DsMemIndvRcvyCfgVal, DsMemIndvRcvySeqVal);
                }
                // Write DsMemIndvRcvySeqVal back;
                rpcSetMem( "DsMemIndvRcvySeq", tmpIndex , DsMemIndvRcvySeqVal, sizeof(tDsMemRcvySeq) );
            }
            tmpIndex ++;
        }
    }
}
void RcvyMergeResetTimer(uint8_t ) {
	uint8_t tmpCycleCnt = 0;
	uint8_t tmpIndex = 0;
	uint16_t tmpIndex = 0;
	uint32_t tmpCycleCnt = 0;

	tDsMemRcvySeq DsMemStreamRcvySeqValTmp = {0};
	tDsMemRcvySeq *DsMemStreamRcvySeqVal = &DsMemStreamRcvySeqValTmp;
	tCtlRcvy CtlRcvyTmp = {0};
	tCtlRcvy *CtlRcvy = &CtlRcvyTmp;
	readCtlRcvy("CtlRcvy", 0, CtlRcvy, 0);
	tDsMemRcvyCfg DsMemStreamRcvyCfgValTmp = {0};
	tDsMemRcvyCfg *DsMemStreamRcvyCfgVal = &DsMemStreamRcvyCfgValTmp;

    SET_BITS(tmpIndex, 0, 10, (0));
    tmpCycleCnt   = 0;
    while( CtlRcvy->mergeSeqResetEn ) {
        tmpCycleCnt ++;
        if( tmpCycleCnt >= CtlRcvy->mergeDelayPerEntry ) {
            tmpCycleCnt = 0;
            rpcRdMem("DsMemStreamRcvyCfg", tmpIndex, DsMemStreamRcvyCfgVal);
            rpcRdMem("DsMemStreamRcvySeq", tmpIndex, DsMemStreamRcvySeqVal);
            if( !DsMemStreamRcvySeqVal->takeAny ) {
                if( DsMemStreamRcvySeqVal->remainTicks > CtlRcvy->mergeMinusCycle ) {
                    DsMemStreamRcvySeqVal->remainTicks  -= CtlRcvy->mergeMinusCycle;
                } else {
                    DsMemStreamRcvySeqVal->remainTicks   = 0;
                    sequenceRecoveryReset(DsMemStreamRcvyCfgVal, DsMemStreamRcvySeqVal);
                }
                // Write DsMemStreamRcvySeqVal back;
                rpcSetMem( "DsMemStreamRcvySeq", tmpIndex , DsMemStreamRcvySeqVal, sizeof(tDsMemRcvySeq) );
            }
            tmpIndex ++;
        }
    }
}
