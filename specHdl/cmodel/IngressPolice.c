/*
 * cmodel for Pishon
 * @file: IngressPolice
 * @description: auto generage
 * @note: Copyright (C) 2021-03-29 12:40:57.477212
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
#include <mem/IngressPoliceOpr.h>
#include <mem/IngressPolice.h>

void IngressPolice(tPktInfo *PI, uint8_t *glPktHdr, uint8_t PR) {
	uint8_t tmpTypeIdx = 0;
	uint8_t tmpNewColor0 = 0;
	uint8_t tmpExcpType = 0;
	uint8_t tmpPktLen = 0;
	uint8_t tmpMarkDrop0 = 0;
	uint8_t tmpPoResult = 0;
	uint8_t tmpMarkDrop = 0;
	uint8_t tmpExcpPktPoEn = 0;
	uint8_t tmpColor = 0;
	uint8_t tmpColor1 = 0;
	uint8_t tmpMarkDrop1 = 0;
	uint8_t tmpCpuPktPoEn = 0;
	uint8_t tmpNewColor1 = 0;
	uint8_t tmpPolicingEn = 0;
	uint8_t tmpAddLen = 0;
	uint8_t tmpIndex = 0;
	uint8_t tmpPoEn1 = 0;

	tCtlPoliceLog CtlPoliceLogTmp = {0};
	tCtlPoliceLog *CtlPoliceLog = &CtlPoliceLogTmp;
	readCtlPoliceLog("CtlPoliceLog", 0, CtlPoliceLog, 0);
	tCtlPolice CtlPoliceTmp = {0};
	tCtlPolice *CtlPolice = &CtlPoliceTmp;
	readCtlPolice("CtlPolice", 0, CtlPolice, 0);
	tDsMemCpuPolicePtrMap DsMemCpuPolicePtrMapValTmp = {0};
	tDsMemCpuPolicePtrMap *DsMemCpuPolicePtrMapVal = &DsMemCpuPolicePtrMapValTmp;
	tCtlCpuPolice CtlCpuPoliceTmp = {0};
	tCtlCpuPolice *CtlCpuPolice = &CtlCpuPoliceTmp;
	readCtlCpuPolice("CtlCpuPolice", 0, CtlCpuPolice, 0);
	tDsMemTsnPolice DsMemTsnPoliceValTmp = {0};
	tDsMemTsnPolice *DsMemTsnPoliceVal = &DsMemTsnPoliceValTmp;

    tmpColor     = PI->prior;
    tmpMarkDrop       = 0;
    PI->newColor       = PI->prior;
    tmpCpuPktPoEn     = ((CtlCpuPolice->policeEn & (1 << PI->cpuPktType)) != 0) && PI->copyToCpu && !PI->fromRemoteSpan;
    tmpExcpType = 0x10 + PI->excpType;
    tmpExcpPktPoEn    = ((CtlCpuPolice->policeEn & (1 << tmpExcpType)) != 0) && PI->exception && !PI->fromRemoteSpan;
    PI->portPoPtr      = PI->logicalPort;
    PI->portPoEn       = PI->portPoliceEn && !tmpCpuPktPoEn && !tmpExcpPktPoEn;
    tmpAddLen         = 0;
    if( PI->flowPoliceValid ) {
        PI->flowPoPtr= PI->flowPolicePtr;
        PI->flowPoEn       = 1;
    } else if( PI->isTsn ) {
        rpcRdMem("DsMemTsnPolice", PI->tsnHandle, DsMemTsnPoliceVal);
        PI->flowPoPtr      = DsMemTsnPoliceVal->policeIndex;
        PI->flowPoEn       = 1;
        if (DsMemTsnPoliceVal->chkSDUen) {
            PI->discard    = PI->discard | (DsMemTsnPoliceVal->maxSDU < PI->pktLength);
        }
		PI->chkSDUfailed = DsMemTsnPoliceVal->chkSDUen && PI->discard;
    } else if( tmpCpuPktPoEn || tmpExcpPktPoEn ) {
        PI->flowPoEn       = 1;
        tmpTypeIdx   = tmpCpuPktPoEn ? PI->cpuPktType : tmpExcpType;
        tmpIndex     = ((uint64_t)PI->srcPort<<5) + ( GET_BITS(tmpTypeIdx, 0, 4));
        rpcRdMem("DsMemCpuPolicePtrMap", tmpIndex, DsMemCpuPolicePtrMapVal);
        PI->flowPoPtr      = DsMemCpuPolicePtrMapVal->policePtr + CtlCpuPolice->policePtrBase;
        tmpAddLen         = 8;
    }
    tmpPktLen       = PI->pktLength + PI->gapValue + tmpAddLen;
    // Police Operation
    tmpPolicingEn = (!PI->discard || tmpCpuPktPoEn || tmpExcpPktPoEn) && !PI->criticalPacket && (PI->portPoEn || PI->flowPoEn) ; 
    if( tmpPolicingEn && CtlPolice->flowPoliceFirst ) {
        tmpPoResult = FlowPolicingOpr( tmpPktLen, tmpColor, PI->flowPoEn, PI->flowPoPtr );
        tmpMarkDrop0 = GET_BITS(tmpPoResult, 2, 2);
        tmpNewColor0 = GET_BITS(tmpPoResult, 0, 1);
        tmpPoEn1       = ( CtlPolice->sequentialPolicing && tmpMarkDrop0 ) ? 0 :  PI->portPoEn;
        tmpColor1 = ( CtlPolice->sequentialPolicing && PI->flowPoEn ) ? tmpNewColor0 : tmpColor;
        tmpPoResult = PortPolicingOpr( tmpPktLen, tmpColor1, tmpPoEn1, PI->portPoPtr );
        tmpMarkDrop1 = GET_BITS(tmpPoResult, 2, 2);
        tmpNewColor1 = GET_BITS(tmpPoResult, 0, 1);
        tmpMarkDrop                 = tmpMarkDrop0 | tmpMarkDrop1;
        if( CtlPolice->sequentialPolicing ) {
            if( tmpPoEn1 ) {
                PI->newColor    = tmpNewColor1;
            } else {
                PI->newColor    = tmpNewColor0;
            }
        } else {
            if( PI->flowPoEn && tmpPoEn1 ) {
                PI->newColor    = (tmpNewColor0 < tmpNewColor1) ? tmpNewColor0 : tmpNewColor1;
            } else if( tmpPoEn1 ) {
                PI->newColor    = tmpNewColor1;
            } else {
                PI->newColor    = tmpNewColor0;
            }
        }
    } else if( tmpPolicingEn && !CtlPolice->flowPoliceFirst ) {
        tmpPoResult = PortPolicingOpr( tmpPktLen, tmpColor, PI->portPoEn, PI->portPoPtr);
        tmpMarkDrop0 = GET_BITS(tmpPoResult, 2, 2);
        tmpNewColor0 = GET_BITS(tmpPoResult, 0, 1);
        tmpPoEn1  = ( CtlPolice->sequentialPolicing && tmpMarkDrop0 ) ? 0 : PI->flowPoEn;
        tmpColor1 = ( CtlPolice->sequentialPolicing && PI->portPoEn ) ? tmpNewColor0 : tmpColor;
        tmpPoResult = FlowPolicingOpr( tmpPktLen, tmpColor1, tmpPoEn1, PI->flowPoPtr);
        tmpMarkDrop1 = GET_BITS(tmpPoResult, 2, 2);
        tmpNewColor1 = GET_BITS(tmpPoResult, 0, 1);
        tmpMarkDrop                 = tmpMarkDrop0 | tmpMarkDrop1;
        if( CtlPolice->sequentialPolicing ) {
            if( tmpPoEn1 ) {
                PI->newColor    = tmpNewColor1;
            } else {
                PI->newColor    = tmpNewColor0;
            }
        } else {
            if( PI->portPoEn && tmpPoEn1 ) {
                PI->newColor    = (tmpNewColor0 < tmpNewColor1) ? tmpNewColor0 : tmpNewColor1;
            } else if( tmpPoEn1 ) {
                PI->newColor    = tmpNewColor1;
            } else {
                PI->newColor    = tmpNewColor0;
            }
        }
    }
    // Classify result
    if( tmpMarkDrop ) {
        CtlPoliceLog->policeDrop = 1;
        PI->discard               = PI->discard | 1;
        if( tmpCpuPktPoEn || tmpExcpPktPoEn ) {
            PI->copyToCpu         = PI->copyToCpu & 0;
            PI->exception         = PI->exception & 0;
        }
    }
    PI->prior    = ((uint64_t) GET_BITS(PI->prior, 2, 5)<<8) + ( PI->newColor);
	PI->dropPktCnt = CtlPoliceLog->dropPktCnt + tmpMarkDrop;
    CtlPoliceLog->portPoEn = PI->portPoEn;
    CtlPoliceLog->flowPoEn = PI->flowPoEn;
    CtlPoliceLog->portPoPtr = PI->portPoPtr;
    CtlPoliceLog->flowPoPtr = PI->flowPoPtr;
    CtlPoliceLog->policeDrop = PI->policeDrop;
    CtlPoliceLog->chkSDUfailed = PI->chkSDUfailed;
    CtlPoliceLog->newColor = PI->newColor;
    CtlPoliceLog->dropPktCnt = PI->dropPktCnt;
}
static int FlowPolicingOpr(uint8_t pktLen, uint8_t  color, uint8_t flowPoEn, uint8_t flowPoPtr) {
	uint8_t tmpByteCnt = 0;
	uint8_t tmpPoResult = 0;
	uint8_t tmpColorStatsEn = 0;
	uint8_t tmpColor = 0;
	uint8_t tmpFlowStatsBase = 0;
	uint8_t tmpDrop = 0;
	uint8_t tmpStatPtr = 0;
	uint64_t tmpByteCnt = 0;

	tDsMemPolice DsMemFlowPoliceValTmp = {0};
	tDsMemPolice *DsMemFlowPoliceVal = &DsMemFlowPoliceValTmp;
	tDsMemPoliceCfg DsMemFlowPoliceCfgValTmp = {0};
	tDsMemPoliceCfg *DsMemFlowPoliceCfgVal = &DsMemFlowPoliceCfgValTmp;
	tDsMemColorStats DsMemColorStatsValTmp = {0};
	tDsMemColorStats *DsMemColorStatsVal = &DsMemColorStatsValTmp;
	tCtlPolice CtlPoliceTmp = {0};
	tCtlPolice *CtlPolice = &CtlPoliceTmp;
	readCtlPolice("CtlPolice", 0, CtlPolice, 0);

    tmpDrop                     =  0;
    tmpColor               = GET_BITS(color, 0, 1);
    if( flowPoEn ) {
        rpcRdMem("DsMemFlowPolice", flowPoPtr, DsMemFlowPoliceVal);
        rpcRdMem("DsMemFlowPoliceCfg", flowPoPtr, DsMemFlowPoliceCfgVal);
        tmpPoResult = PoliceMetering( pktLen, color, DsMemFlowPoliceVal, DsMemFlowPoliceCfgVal );
        rpcSetMem( "DsMemFlowPolice", flowPoPtr , DsMemFlowPoliceVal, sizeof(tDsMemPolice) );
        tmpDrop = GET_BITS(tmpPoResult, 2, 2);
        tmpColor = GET_BITS(tmpPoResult, 0, 1);
        tmpColorStatsEn = CtlPolice->flowStatsEn{ GET_BITS(tmpColor, 0, 1:0]-1}[0);
        if(  tmpColorStatsEn ) {
            tmpFlowStatsBase = CtlPolice->flowStatsBase{ GET_BITS(tmpColor, 0, 1)-1 }; 
            tmpStatPtr = tmpFlowStatsBase + flowPoPtr;
            rpcRdMem("DsMemFlowColorStats", tmpStatPtr, DsMemColorStatsVal);
            DsMemColorStatsVal->pktCnt  += 1;
            tmpByteCnt = ((uint64_t)DsMemColorStatsVal->byteCntHi<<8) + ( DsMemColorStatsVal->byteCntLo);
            tmpByteCnt += pktLen;
            DsMemColorStatsVal->byteCntHi = tmpByteCnt >> 32;
            DsMemColorStatsVal->byteCntLo = tmpByteCnt;
            rpcSetMem( "DsMemFlowColorStats", tmpStatPtr , DsMemColorStatsVal, sizeof(tDsMemColorStats) );
        }
        if( DsMemFlowPoliceCfgVal->dropYellow && tmpColor == COLOR_YELLOW ) 
            tmpDrop             = 1;
        if( DsMemFlowPoliceCfgVal->markAllRed ) 
            tmpColor            = COLOR_RED;
    }
    return ((uint64_t)tmpDrop<<2) + ( GET_BITS(tmpColor, 0, 1));
}
static int PortPolicingOpr(uint8_t pktLen, uint8_t  color, uint8_t portPoEn, uint8_t portPoPtr) {
	uint8_t tmpByteCnt = 0;
	uint8_t tmpPoResult = 0;
	uint8_t tmpPortStatsBase = 0;
	uint8_t tmpColorStatsEn = 0;
	uint8_t tmpColor = 0;
	uint8_t tmpPortStatPtr = 0;
	uint8_t tmpDrop = 0;
	uint64_t tmpByteCnt = 0;

	tDsMemColorStats DsMemColorStatsValTmp = {0};
	tDsMemColorStats *DsMemColorStatsVal = &DsMemColorStatsValTmp;
	tDsMemPoliceCfg DsMemPortPoliceCfgValTmp = {0};
	tDsMemPoliceCfg *DsMemPortPoliceCfgVal = &DsMemPortPoliceCfgValTmp;
	tDsMemPolice DsMemPortPoliceValTmp = {0};
	tDsMemPolice *DsMemPortPoliceVal = &DsMemPortPoliceValTmp;
	tCtlPolice CtlPoliceTmp = {0};
	tCtlPolice *CtlPolice = &CtlPoliceTmp;
	readCtlPolice("CtlPolice", 0, CtlPolice, 0);

    tmpDrop         =  0;
    tmpColor   = GET_BITS(color, 0, 1);
    if( portPoEn ) {
        rpcRdMem("DsMemPortPolice", portPoPtr, DsMemPortPoliceVal);
        rpcRdMem("DsMemPortPoliceCfg", portPoPtr, DsMemPortPoliceCfgVal);
        tmpPoResult = PoliceMetering( pktLen, color, DsMemPortPoliceVal, DsMemPortPoliceCfgVal );
        rpcSetMem( "DsMemPortPolice", portPoPtr , DsMemPortPoliceVal, sizeof(tDsMemPolice) );
        tmpDrop = GET_BITS(tmpPoResult, 2, 2); 
        tmpColor = GET_BITS(tmpPoResult, 0, 1); 
        tmpColorStatsEn = CtlPolice->portStatsEn{ GET_BITS(tmpColor, 0, 1:0]-1}[0);
        if(  tmpColorStatsEn ) {
            tmpPortStatsBase = CtlPolice->portStatsBase{ GET_BITS(tmpColor, 0, 1)-1 };
            tmpPortStatPtr = tmpPortStatsBase + portPoPtr;
            rpcRdMem("DsMemPortColorStats", tmpPortStatPtr, DsMemColorStatsVal);
            DsMemColorStatsVal->pktCnt  += 1;
            tmpByteCnt = ((uint64_t)DsMemColorStatsVal->byteCntHi<<8) + ( DsMemColorStatsVal->byteCntLo);
            tmpByteCnt += pktLen;
            DsMemColorStatsVal->byteCntHi = tmpByteCnt >> 32;
            DsMemColorStatsVal->byteCntLo = tmpByteCnt;
            rpcSetMem( "DsMemPortColorStats", tmpPortStatPtr , DsMemColorStatsVal, sizeof(tDsMemColorStats) );
        }
        if( DsMemPortPoliceCfgVal->dropYellow && tmpColor == COLOR_YELLOW ) 
            tmpDrop              = 1;
        if( DsMemPortPoliceCfgVal->markAllRed ) 
            tmpColor             = COLOR_RED;
    }
    return ((uint64_t)tmpDrop<<2) + ( GET_BITS(tmpColor, 0, 1));
}
static int PoliceMetering(uint8_t pktLen, uint8_t  color, uint8_t DsMemPolice, uint8_t DsMemPoliceCfg) {
	uint8_t tmpIsGreen = 0;
	uint8_t tmpIsTpMoreLen = 0;
	uint8_t tmpIsYellow = 0;
	uint8_t tmpMarkDrop = 0;
	uint8_t tmpColor = 0;
	uint8_t tmpValueTp = 0;
	uint8_t tmpIsTcMoreLen = 0;
	uint8_t tmpValueTc = 0;
	uint8_t tmpIsRed = 0;
	uint32_t tmpLength = 0;


    tmpColor     = GET_BITS(color, 0, 1);
    tmpLength   = pktLen << 3;            // used as bit
    tmpIsGreen        = GET_BITS(tmpColor, 0, 1) == COLOR_GREEN;    // 3 
    tmpIsYellow       = GET_BITS(tmpColor, 0, 1) == COLOR_YELLOW;   // 2 
    tmpIsRed          = GET_BITS(tmpColor, 0, 1) == COLOR_RED;      // 1 
    tmpValueTc  = DsMemPolice->commitCount;
    tmpValueTp  = DsMemPolice->peakCount;
    tmpIsTcMoreLen    = tmpValueTc >= tmpLength;
    tmpIsTpMoreLen    = tmpValueTp >= tmpLength;
    if( DsMemPoliceCfg->srTcmMode ) {
        if( DsMemPoliceCfg->colorBlindMode ) {
            if( tmpIsTcMoreLen ) {
                tmpColor                  = COLOR_GREEN;
                DsMemPolice->commitCount = tmpValueTc - tmpLength;
            } else if( tmpIsTpMoreLen ) {
                tmpColor                  = COLOR_YELLOW;
                DsMemPolice->peakCount   = tmpValueTp - tmpLength;
            } else {
                tmpColor                  = COLOR_RED;
            }
        } else {
            if( tmpIsGreen && tmpIsTcMoreLen ) {
                tmpColor                  = COLOR_GREEN;
                DsMemPolice->commitCount = tmpValueTc - tmpLength;
            } else if( (tmpIsGreen || tmpIsYellow) && tmpIsTpMoreLen ) {
                tmpColor                  = COLOR_YELLOW;
                DsMemPolice->peakCount   = tmpValueTp - tmpLength;
            } else {
                tmpColor                  = COLOR_RED;
            }
        }
    } else {
        if( DsMemPoliceCfg->colorBlindMode ) {
            if( !tmpIsTpMoreLen ) {
                tmpColor                  = COLOR_RED;
            } else if( !tmpIsTcMoreLen ) {
                tmpColor                  = COLOR_YELLOW;
                DsMemPolice->peakCount   = tmpValueTp - tmpLength;
            } else {
                tmpColor                  = COLOR_GREEN;
                DsMemPolice->commitCount = tmpValueTc - tmpLength;
                DsMemPolice->peakCount   = tmpValueTp - tmpLength;
            }
        } else {
            if( !tmpIsTpMoreLen || tmpIsRed ) {
                tmpColor                  = COLOR_RED;
            } else if( !tmpIsTcMoreLen || tmpIsYellow ) {
                tmpColor                  = COLOR_YELLOW;
                DsMemPolice->peakCount   = tmpValueTp - tmpLength;
            } else {
                tmpColor                  = COLOR_GREEN;
                DsMemPolice->commitCount = tmpValueTc - tmpLength;
                DsMemPolice->peakCount   = tmpValueTp - tmpLength;
            }
        }
    }
    // Color and drop
    tmpMarkDrop = (tmpColor < GET_BITS(DsMemPoliceCfg->colorDropCode, 0, 1));
    return ((uint64_t)tmpMarkDrop<<2) + ( GET_BITS(tmpColor, 0, 1));
}
void PortMeterUpdate(uint8_t ) {
	uint8_t tmpPortPoPtr = 0;

	tDsMemPoliceCfg DsMemPortPoliceCfgValTmp = {0};
	tDsMemPoliceCfg *DsMemPortPoliceCfgVal = &DsMemPortPoliceCfgValTmp;
	tDsMemPolice DsMemPortPoliceValTmp = {0};
	tDsMemPolice *DsMemPortPoliceVal = &DsMemPortPoliceValTmp;
	tCtlPolice CtlPoliceTmp = {0};
	tCtlPolice *CtlPolice = &CtlPoliceTmp;
	readCtlPolice("CtlPolice", 0, CtlPolice, 0);

    while( CtlPolice->updateEn ) {
        tmpPortPoPtr      = CtlPolice->portCurPtr;
        // Police0
        rpcRdMem("DsMemPortPolice", tmpPortPoPtr, DsMemPortPoliceVal);
        rpcRdMem("DsMemPortPoliceCfg", tmpPortPoPtr, DsMemPortPoliceCfgVal);
        updateMeterEntry(DsMemPortPoliceVal, DsMemPortPoliceCfgVal); 
        rpcSetMem( "DsMemPortPolice", tmpPortPoPtr , DsMemPortPoliceVal, sizeof(tDsMemPolice) );
        DelayCycle( CtlPolice->portUpdateIntv );
        // update pointer
        CtlPolice->portCurPtr = tmpPortPoPtr + 1;
        if (CtlPolice->portCurPtr >= CtlPolice->portMaxPtr) {
            CtlPolice->portCurPtr  = CtlPolice->portMinPtr;
			DelayCycle( CtlPolice->portPerRndDelay );
            // update round
			CtlPolice->portCurRound  = CtlPolice->portCurRound + 1;
			if (CtlPolice->portCurRound >= CtlPolice->portUpdRound) {
				DelayCycle( CtlPolice->portFinalDelay );
				CtlPolice->portCurRound = 0;
			}
        }
    } // end of while
}
void FlowMeterUpdate(uint8_t ) {
	uint8_t tmpFlowPoPtr = 0;

	tDsMemPolice DsMemFlowPoliceValTmp = {0};
	tDsMemPolice *DsMemFlowPoliceVal = &DsMemFlowPoliceValTmp;
	tDsMemPoliceCfg DsMemFlowPoliceCfgValTmp = {0};
	tDsMemPoliceCfg *DsMemFlowPoliceCfgVal = &DsMemFlowPoliceCfgValTmp;
	tCtlPolice CtlPoliceTmp = {0};
	tCtlPolice *CtlPolice = &CtlPoliceTmp;
	readCtlPolice("CtlPolice", 0, CtlPolice, 0);

    while( CtlPolice->updateEn ) {
        tmpFlowPoPtr     = CtlPolice->flowCurPtr;
        // Police0
        rpcRdMem("DsMemFlowPolice", tmpFlowPoPtr, DsMemFlowPoliceVal);
        rpcRdMem("DsMemFlowPoliceCfg", tmpFlowPoPtr, DsMemFlowPoliceCfgVal);
        updateMeterEntry(DsMemFlowPoliceVal, DsMemFlowPoliceCfgVal); 
        rpcSetMem( "DsMemFlowPolice", tmpFlowPoPtr , DsMemFlowPoliceVal, sizeof(tDsMemPolice) );
        DelayCycle( CtlPolice->flowUpdateIntv );
        // update pointer
        CtlPolice->flowCurPtr = tmpFlowPoPtr + 1;
        // update round
        if (CtlPolice->flowCurPtr >= CtlPolice->flowMaxPtr) {
            CtlPolice->flowCurPtr    = CtlPolice->flowMinPtr;
			DelayCycle( CtlPolice->flowPerRndDelay );
			CtlPolice->flowCurRound  = CtlPolice->flowCurRound + 1;
			if (CtlPolice->flowCurRound >= CtlPolice->flowUpdRound) {
				CtlPolice->flowCurRound = 0;
				DelayCycle( CtlPolice->flowFinalDelay );
			}
        }
    } // end of while
}
void updateMeterEntry(uint8_t DsMemPolice, uint8_t DsMemPoliceCfg) {
	uint8_t tmpDiffTcCbs = 0;
	uint8_t tmpAddToTc = 0;
	uint8_t tmpAddToTp = 0;
	uint8_t tmpDiffTpPbs = 0;
	uint8_t tmpValueTp = 0;
	uint8_t tmpValueTc = 0;
	uint8_t tmpValueCbs = 0;
	uint8_t tmpValuePbs = 0;


    // templately variables
    tmpValueTc        = DsMemPolice->commitCount;
    tmpValueCbs       = DsMemPoliceCfg->cbsByte << 3;  
    tmpValueTp        = DsMemPolice->peakCount;
    tmpValuePbs       = DsMemPoliceCfg->pbsByte << 3;
    // token difference to bucket
    tmpDiffTcCbs      = tmpValueCbs - tmpValueTc;
    tmpDiffTpPbs      = tmpValuePbs - tmpValueTp;
    // process
    if( DsMemPoliceCfg->srTcmMode && DsMemPoliceCfg->updateEn ) {
        if( DsMemPoliceCfg->cirBps < tmpDiffTcCbs ) {
            tmpAddToTc = DsMemPoliceCfg->cirBps;
            tmpAddToTp = 0;
        } else {
            tmpAddToTc = tmpDiffTcCbs;
            tmpAddToTp = (DsMemPoliceCfg->cirBps - tmpAddToTc) < tmpDiffTpPbs 
                             ? (DsMemPoliceCfg->cirBps - tmpAddToTc) : tmpDiffTpPbs;
        }   
    } else if ( !DsMemPoliceCfg->srTcmMode && DsMemPoliceCfg->updateEn ) {
        tmpAddToTc     = ( DsMemPoliceCfg->cirBps < tmpDiffTcCbs) ? DsMemPoliceCfg->cirBps : tmpDiffTcCbs;
        tmpAddToTp     = ( DsMemPoliceCfg->pirBps < tmpDiffTpPbs) ? DsMemPoliceCfg->pirBps : tmpDiffTpPbs;
    }
    DsMemPolice->commitCount = tmpValueTc + tmpAddToTc;
    DsMemPolice->peakCount   = tmpValueTp + tmpAddToTp;
}
