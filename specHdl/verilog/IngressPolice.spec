
function IngressPolice(PI, glPktHdr, PR) {
    tmpColor[1:0]     = PI.prior;
    tmpMarkDrop       = 0;
    PI.newColor       = PI.prior;

    tmpCpuPktPoEn     = ((CtlCpuPolice.policeEn[0:0] & (1 << PI.cpuPktType)) != 0) && PI.copyToCpu && !PI.fromRemoteSpan;
    tmpExcpType[4:0] = 5'h10 + PI.excpType;
    tmpExcpPktPoEn    = ((CtlCpuPolice.policeEn[0:0] & (1 << tmpExcpType)) != 0) && PI.exception && !PI.fromRemoteSpan;
    PI.portPoPtr      = PI.logicalPort;
    PI.portPoEn       = PI.portPoliceEn && !tmpCpuPktPoEn && !tmpExcpPktPoEn;
    tmpAddLen         = 0;

    if( PI.flowPoliceValid ) {
        PI.flowPoPtr= PI.flowPolicePtr;
        PI.flowPoEn       = 1;
    
    } else if( PI.isTsn ) {
        DsMemTsnPoliceVal = DsMemTsnPolice[ PI.tsnHandle ];
        PI.flowPoPtr      = DsMemTsnPoliceVal.policeIndex;
        PI.flowPoEn       = 1;
        if (DsMemTsnPoliceVal.chkSDUen) {
            PI.discard    = PI.discard | (DsMemTsnPoliceVal.maxSDU < PI.pktLength);
        }
		PI.chkSDUfailed = DsMemTsnPoliceVal.chkSDUen && PI.discard;
    
    } else if( tmpCpuPktPoEn || tmpExcpPktPoEn ) {
        PI.flowPoEn       = 1;
        tmpTypeIdx[4:0]   = tmpCpuPktPoEn ? PI.cpuPktType : tmpExcpType;
        tmpIndex[7:0]     = {PI.srcPort, tmpTypeIdx[4:0]};
        DsMemCpuPolicePtrMapVal = DsMemCpuPolicePtrMap[ tmpIndex ];
        PI.flowPoPtr      = DsMemCpuPolicePtrMapVal.policePtr + CtlCpuPolice.policePtrBase[0:0];
        tmpAddLen         = 8;
    }
    tmpPktLen       = PI.pktLength + PI.gapValue + tmpAddLen;
    // Police Operation
    tmpPolicingEn = (!PI.discard || tmpCpuPktPoEn || tmpExcpPktPoEn) && !PI.criticalPacket && (PI.portPoEn || PI.flowPoEn) ; 
    if( tmpPolicingEn && CtlPolice.flowPoliceFirst[0:0] ) {
        tmpPoResult[2:0] = FlowPolicingOpr( tmpPktLen, tmpColor, PI.flowPoEn, PI.flowPoPtr );
        tmpMarkDrop0[0:0] = tmpPoResult[2:2];
        tmpNewColor0[1:0] = tmpPoResult[1:0];
        tmpPoEn1       = ( CtlPolice.sequentialPolicing[0:0] && tmpMarkDrop0 ) ? 0 :  PI.portPoEn;
        tmpColor1[1:0] = ( CtlPolice.sequentialPolicing && PI.flowPoEn ) ? tmpNewColor0 : tmpColor;
        tmpPoResult[2:0] = PortPolicingOpr( tmpPktLen, tmpColor1, tmpPoEn1, PI.portPoPtr );
        tmpMarkDrop1[0:0] = tmpPoResult[2:2];
        tmpNewColor1[1:0] = tmpPoResult[1:0];

        tmpMarkDrop                 = tmpMarkDrop0 | tmpMarkDrop1;
        if( CtlPolice.sequentialPolicing[0:0] ) {
            if( tmpPoEn1 ) {
                PI.newColor    = tmpNewColor1;
            } else {
                PI.newColor    = tmpNewColor0;
            }
        } else {
            if( PI.flowPoEn && tmpPoEn1 ) {
                PI.newColor    = (tmpNewColor0 < tmpNewColor1) ? tmpNewColor0 : tmpNewColor1;
            } else if( tmpPoEn1 ) {
                PI.newColor    = tmpNewColor1;
            } else {
                PI.newColor    = tmpNewColor0;
            }
        }
    } else if( tmpPolicingEn && !CtlPolice.flowPoliceFirst[0:0] ) {
        tmpPoResult[2:0] = PortPolicingOpr( tmpPktLen, tmpColor, PI.portPoEn, PI.portPoPtr);
        tmpMarkDrop0[0:0] = tmpPoResult[2:2];
        tmpNewColor0[1:0] = tmpPoResult[1:0];
        tmpPoEn1  = ( CtlPolice.sequentialPolicing[0:0] && tmpMarkDrop0 ) ? 0 : PI.flowPoEn;
        tmpColor1[1:0] = ( CtlPolice.sequentialPolicing && PI.portPoEn ) ? tmpNewColor0 : tmpColor;
        tmpPoResult[2:0] = FlowPolicingOpr( tmpPktLen, tmpColor1, tmpPoEn1, PI.flowPoPtr);
        tmpMarkDrop1[0:0] = tmpPoResult[2:2];
        tmpNewColor1[1:0] = tmpPoResult[1:0];

        tmpMarkDrop                 = tmpMarkDrop0 | tmpMarkDrop1;
        if( CtlPolice.sequentialPolicing[0:0] ) {
            if( tmpPoEn1 ) {
                PI.newColor    = tmpNewColor1;
            } else {
                PI.newColor    = tmpNewColor0;
            }
        } else {
            if( PI.portPoEn && tmpPoEn1 ) {
                PI.newColor    = (tmpNewColor0 < tmpNewColor1) ? tmpNewColor0 : tmpNewColor1;
            } else if( tmpPoEn1 ) {
                PI.newColor    = tmpNewColor1;
            } else {
                PI.newColor    = tmpNewColor0;
            }
        }
    }
    // Classify result
    if( tmpMarkDrop ) {
        CtlPoliceLog.policeDrop[0:0] = 1;
        PI.discard               = PI.discard | 1;
        if( tmpCpuPktPoEn || tmpExcpPktPoEn ) {
            PI.copyToCpu         = PI.copyToCpu & 0;
            PI.exception         = PI.exception & 0;
        }
    }
    PI.prior    = {PI.prior[5:2], PI.newColor};
	PI.dropPktCnt = CtlPoliceLog.dropPktCnt[0:0] + tmpMarkDrop;
    CtlPoliceLog.portPoEn[0:0] = PI.portPoEn;
    CtlPoliceLog.flowPoEn[0:0] = PI.flowPoEn;
    CtlPoliceLog.portPoPtr[4:0] = PI.portPoPtr[4:0];
    CtlPoliceLog.flowPoPtr[5:0] = PI.flowPoPtr[5:0];
    CtlPoliceLog.policeDrop[0:0] = PI.policeDrop;
    CtlPoliceLog.chkSDUfailed[0:0] = PI.chkSDUfailed;
    CtlPoliceLog.newColor[1:0] = PI.newColor[1:0];
    CtlPoliceLog.dropPktCnt[31:0] = PI.dropPktCnt[31:0];
}

static int FlowPolicingOpr( pktLen, color[1:0], flowPoEn, flowPoPtr ) {
    tmpDrop                     =  0;
    tmpColor[1:0]               =  color[1:0];
    if( flowPoEn ) {
        DsMemFlowPoliceVal      = DsMemFlowPolice[ flowPoPtr ];
        DsMemFlowPoliceCfgVal  = DsMemFlowPoliceCfg[ flowPoPtr ];
        tmpPoResult[2:0] = PoliceMetering( pktLen, color, DsMemFlowPoliceVal, DsMemFlowPoliceCfgVal );
        DsMemFlowPolice[ flowPoPtr ] = DsMemFlowPoliceVal;
        tmpDrop = tmpPoResult[2:2];
        tmpColor[1:0] = tmpPoResult[1:0];
        tmpColorStatsEn = CtlPolice.flowStatsEn{tmpColor[1:0]-1}[0:0];
        if(  tmpColorStatsEn ) {
            tmpFlowStatsBase = CtlPolice.flowStatsBase{ tmpColor[1:0]-1 }; 
            tmpStatPtr = tmpFlowStatsBase + flowPoPtr;
            DsMemColorStatsVal = DsMemFlowColorStats[ tmpStatPtr ];
            DsMemColorStatsVal.pktCnt[31:0]  += 1;
            tmpByteCnt[63:0] = {DsMemColorStatsVal.byteCntHi, DsMemColorStatsVal.byteCntLo[31:0]};
            tmpByteCnt += pktLen;
            DsMemColorStatsVal.byteCntHi = tmpByteCnt >> 32;
            DsMemColorStatsVal.byteCntLo[31:0] = tmpByteCnt;
            DsMemFlowColorStats[ tmpStatPtr ] = DsMemColorStatsVal;
        }
        if( DsMemFlowPoliceCfgVal.dropYellow && tmpColor == COLOR_YELLOW ) 
            tmpDrop             = 1;
        if( DsMemFlowPoliceCfgVal.markAllRed ) 
            tmpColor            = COLOR_RED;
    }
    return {tmpDrop, tmpColor[1:0]};
}

static int PortPolicingOpr( pktLen, color[1:0], portPoEn, portPoPtr ) {
    tmpDrop         =  0;
    tmpColor[1:0]   =  color[1:0];
    if( portPoEn ) {
        DsMemPortPoliceVal      = DsMemPortPolice[ portPoPtr ];
        DsMemPortPoliceCfgVal     = DsMemPortPoliceCfg[ portPoPtr ];
        tmpPoResult[2:0] = PoliceMetering( pktLen, color, DsMemPortPoliceVal, DsMemPortPoliceCfgVal );
        DsMemPortPolice[ portPoPtr ] = DsMemPortPoliceVal;
        tmpDrop = tmpPoResult[2:2]; 
        tmpColor[1:0] = tmpPoResult[1:0]; 
        tmpColorStatsEn = CtlPolice.portStatsEn{tmpColor[1:0]-1}[0:0];
        if(  tmpColorStatsEn ) {
            tmpPortStatsBase = CtlPolice.portStatsBase{ tmpColor[1:0]-1 };
            tmpPortStatPtr = tmpPortStatsBase + portPoPtr;
            DsMemColorStatsVal = DsMemPortColorStats[ tmpPortStatPtr ];
            DsMemColorStatsVal.pktCnt[31:0]  += 1;
            tmpByteCnt[63:0] = {DsMemColorStatsVal.byteCntHi, DsMemColorStatsVal.byteCntLo[31:0]};
            tmpByteCnt += pktLen;
            DsMemColorStatsVal.byteCntHi = tmpByteCnt >> 32;
            DsMemColorStatsVal.byteCntLo[31:0] = tmpByteCnt;
            DsMemPortColorStats[ tmpPortStatPtr ] = DsMemColorStatsVal;
        }
        if( DsMemPortPoliceCfgVal.dropYellow && tmpColor == COLOR_YELLOW ) 
            tmpDrop              = 1;
        if( DsMemPortPoliceCfgVal.markAllRed ) 
            tmpColor             = COLOR_RED;
    }
    return {tmpDrop, tmpColor[1:0]};
}


static int PoliceMetering(pktLen, color[1:0], DsMemPolice, DsMemPoliceCfg ) {
    tmpColor[1:0]     = color[1:0];
    tmpLength[16:0]   = pktLen << 3;            // used as bit
    tmpIsGreen        = tmpColor[1:0] == COLOR_GREEN;    // 3 
    tmpIsYellow       = tmpColor[1:0] == COLOR_YELLOW;   // 2 
    tmpIsRed          = tmpColor[1:0] == COLOR_RED;      // 1 
    tmpValueTc  = DsMemPolice.commitCount[0:0];
    tmpValueTp  = DsMemPolice.peakCount[0:0];
    tmpIsTcMoreLen    = tmpValueTc >= tmpLength;
    tmpIsTpMoreLen    = tmpValueTp >= tmpLength;

    if( DsMemPoliceCfg.srTcmMode[0:0] ) {
        if( DsMemPoliceCfg.colorBlindMode[0:0] ) {
            if( tmpIsTcMoreLen ) {
                tmpColor[1:0]                  = COLOR_GREEN;
                DsMemPolice.commitCount[0:0] = tmpValueTc - tmpLength;
            } else if( tmpIsTpMoreLen ) {
                tmpColor[1:0]                  = COLOR_YELLOW;
                DsMemPolice.peakCount[0:0]   = tmpValueTp - tmpLength;
            } else {
                tmpColor[1:0]                  = COLOR_RED;
            }
        } else {
            if( tmpIsGreen && tmpIsTcMoreLen ) {
                tmpColor[1:0]                  = COLOR_GREEN;
                DsMemPolice.commitCount[0:0] = tmpValueTc - tmpLength;
            } else if( (tmpIsGreen || tmpIsYellow) && tmpIsTpMoreLen ) {
                tmpColor[1:0]                  = COLOR_YELLOW;
                DsMemPolice.peakCount[0:0]   = tmpValueTp - tmpLength;
            } else {
                tmpColor[1:0]                  = COLOR_RED;
            }

        }
    } else {
        if( DsMemPoliceCfg.colorBlindMode[0:0] ) {
            if( !tmpIsTpMoreLen ) {
                tmpColor[1:0]                  = COLOR_RED;
            } else if( !tmpIsTcMoreLen ) {
                tmpColor[1:0]                  = COLOR_YELLOW;
                DsMemPolice.peakCount[0:0]   = tmpValueTp - tmpLength;
            } else {
                tmpColor[1:0]                  = COLOR_GREEN;
                DsMemPolice.commitCount[0:0] = tmpValueTc - tmpLength;
                DsMemPolice.peakCount[0:0]   = tmpValueTp - tmpLength;
            }
        } else {
            if( !tmpIsTpMoreLen || tmpIsRed ) {
                tmpColor[1:0]                  = COLOR_RED;
            } else if( !tmpIsTcMoreLen || tmpIsYellow ) {
                tmpColor[1:0]                  = COLOR_YELLOW;
                DsMemPolice.peakCount[0:0]   = tmpValueTp - tmpLength;
            } else {
                tmpColor[1:0]                  = COLOR_GREEN;
                DsMemPolice.commitCount[0:0] = tmpValueTc - tmpLength;
                DsMemPolice.peakCount[0:0]   = tmpValueTp - tmpLength;
            }

        }
    }
    // Color and drop
    tmpMarkDrop = (tmpColor < DsMemPoliceCfg.colorDropCode[1:0]);
    return {tmpMarkDrop, tmpColor[1:0]};
}

process PortMeterUpdate() {
    while( CtlPolice.updateEn[0:0] ) {
        tmpPortPoPtr      = CtlPolice.portCurPtr[0:0];
        // Police0
        DsMemPortPoliceVal  = DsMemPortPolice[ tmpPortPoPtr ];
        DsMemPortPoliceCfgVal = DsMemPortPoliceCfg[ tmpPortPoPtr ];
        updateMeterEntry(DsMemPortPoliceVal, DsMemPortPoliceCfgVal); 
        DsMemPortPolice[ tmpPortPoPtr ] = DsMemPortPoliceVal;
        DelayCycle( CtlPolice.portUpdateIntv[0:0] );

        // update pointer
        CtlPolice.portCurPtr[0:0] = tmpPortPoPtr + 1;
        if (CtlPolice.portCurPtr[0:0] >= CtlPolice.portMaxPtr[0:0]) {
            CtlPolice.portCurPtr[0:0]  = CtlPolice.portMinPtr[0:0];
			DelayCycle( CtlPolice.portPerRndDelay[0:0] );
            // update round
			CtlPolice.portCurRound[0:0][0:0]  = CtlPolice.portCurRound[0:0][0:0] + 1;
			if (CtlPolice.portCurRound[0:0] >= CtlPolice.portUpdRound[0:0]) {
				DelayCycle( CtlPolice.portFinalDelay[0:0] );
				CtlPolice.portCurRound[0:0] = 0;
			}
        }
    } // end of while
}

process FlowMeterUpdate() {
    while( CtlPolice.updateEn[0:0] ) {
        tmpFlowPoPtr     = CtlPolice.flowCurPtr[0:0];
        // Police0
        DsMemFlowPoliceVal        = DsMemFlowPolice[ tmpFlowPoPtr ];
        DsMemFlowPoliceCfgVal    = DsMemFlowPoliceCfg[ tmpFlowPoPtr ];
        updateMeterEntry(DsMemFlowPoliceVal, DsMemFlowPoliceCfgVal); 
        DsMemFlowPolice[ tmpFlowPoPtr ] = DsMemFlowPoliceVal;
        DelayCycle( CtlPolice.flowUpdateIntv[0:0] );

        // update pointer
        CtlPolice.flowCurPtr[0:0] = tmpFlowPoPtr + 1;
        // update round
        if (CtlPolice.flowCurPtr[0:0] >= CtlPolice.flowMaxPtr[0:0]) {
            CtlPolice.flowCurPtr[0:0]    = CtlPolice.flowMinPtr[0:0];
			DelayCycle( CtlPolice.flowPerRndDelay[0:0] );
			CtlPolice.flowCurRound[0:0][0:0]  = CtlPolice.flowCurRound[0:0][0:0] + 1;
			if (CtlPolice.flowCurRound[0:0] >= CtlPolice.flowUpdRound[0:0]) {
				CtlPolice.flowCurRound[0:0] = 0;
				DelayCycle( CtlPolice.flowFinalDelay[0:0] );
			}
        }
    } // end of while
}

function updateMeterEntry(DsMemPolice, DsMemPoliceCfg) {
    // templately variables
    tmpValueTc        = DsMemPolice.commitCount[0:0];
    tmpValueCbs       = DsMemPoliceCfg.cbsByte[0:0] << 3;  
    tmpValueTp        = DsMemPolice.peakCount[0:0];
    tmpValuePbs       = DsMemPoliceCfg.pbsByte[0:0] << 3;
    // token difference to bucket
    tmpDiffTcCbs      = tmpValueCbs - tmpValueTc;
    tmpDiffTpPbs      = tmpValuePbs - tmpValueTp;
    // process
    if( DsMemPoliceCfg.srTcmMode[0:0] && DsMemPoliceCfg.updateEn[0:0] ) {
        if( DsMemPoliceCfg.cirBps[0:0] < tmpDiffTcCbs ) {
            tmpAddToTc = DsMemPoliceCfg.cirBps[0:0];
            tmpAddToTp = 0;
        } else {
            tmpAddToTc = tmpDiffTcCbs;
            tmpAddToTp = (DsMemPoliceCfg.cirBps[0:0] - tmpAddToTc) < tmpDiffTpPbs 
                             ? (DsMemPoliceCfg.cirBps[0:0] - tmpAddToTc) : tmpDiffTpPbs;
        }   
    } else if ( !DsMemPoliceCfg.srTcmMode[0:0] && DsMemPoliceCfg.updateEn[0:0] ) {
        tmpAddToTc     = ( DsMemPoliceCfg.cirBps[0:0][0:0] < tmpDiffTcCbs) ? DsMemPoliceCfg.cirBps[0:0][0:0] : tmpDiffTcCbs;
        tmpAddToTp     = ( DsMemPoliceCfg.pirBps[0:0][0:0] < tmpDiffTpPbs) ? DsMemPoliceCfg.pirBps[0:0][0:0] : tmpDiffTpPbs;
    }
    DsMemPolice.commitCount[0:0] = tmpValueTc + tmpAddToTc;
    DsMemPolice.peakCount[0:0]   = tmpValueTp + tmpAddToTp;
}
    
    
