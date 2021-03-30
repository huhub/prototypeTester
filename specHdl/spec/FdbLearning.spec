
process FdbLearning(MsgLearnInfo) {
    // tMsgLearnInfo tmpMsgLearnInfo = Pop MsgLearnInfo from HwLearnFifo;
    // The frequency is 30K/s
    /** Lookup for FDB learning */
    tmpFdbKeyBuf[63:48] = MsgLearnInfo.fid[11:0];
    tmpFdbKeyBuf[47:32] = MsgLearnInfo.macSaHi[15:0];
    tmpFdbKeyBuf[31:0]  = MsgLearnInfo.macSa[31:0];
    tmpLrnHashLeft[5:0]  = nextCRC8_D64( tmpFdbKeyBuf, sizeof(tmpFdbKeyBuf) ) & 5'h1f; // Initial vlaue is ffffffff
    tmpLrnHashRight[5:0] = 32 + (nextCRC16_D64( tmpFdbKeyBuf, sizeof(tmpFdbKeyBuf) ) & 5'h1f);  // Initial value is ffff
    
    // Left hash
    DsMemMacKeyLeftVal      = DsMemMacKey[ tmpLrnHashLeft ];
    DsMemMacValidLeftVal    = DsMemMacValid[ tmpLrnHashLeft[5:3] ];
    DsMemMacStaticLeftVal   = DsMemMacStatic[ tmpLrnHashLeft[5:3] ];
    DsMemMacAgingLeftVal    = DsMemMacAging[ tmpLrnHashLeft[5:1] ];
    // Right Hash
    DsMemMacKeyRightVal     = DsMemMacKey[ tmpLrnHashRight ];
    DsMemMacValidRightVal   = DsMemMacValid[ tmpLrnHashRight[5:3] ];
    DsMemMacStaticRightVal  = DsMemMacStatic[ tmpLrnHashRight[5:3] ];
    DsMemMacAgingRightVal   = DsMemMacAging[ tmpLrnHashRight[5:1] ];

    tmpAgingFlagLeft[2:0]      = 3;
    tmpAgingFlagRight[2:0]     = 3;
    
        tmpIdxLeft[6:0]       = (tmpLrnHashLeft << 2) + 0;
        tmpIdxRight[6:0]      = (tmpLrnHashRight << 2) + 0;
        // Left check
        if ((DsMemMacValidLeftVal.valid[ tmpIdxLeft[4:0] : tmpIdxLeft[4:0] ] && (DsMemMacKeyLeftVal.vlanId0[11:0] == MsgLearnInfo.fid) && 
            (DsMemMacKeyLeftVal.macAddr0[31:0] == MsgLearnInfo.macSa) && (DsMemMacKeyLeftVal.macAddrHi0[15:0] == MsgLearnInfo.macSaHi) ) && 
            (!DsMemMacStaticLeftVal.isStatic[ tmpIdxLeft[4:0] : tmpIdxLeft[4:0] ])) {
            tmpHashLeftHit                  = 1;
            tmpLeftHitIdx[6:0]   = tmpIdxLeft;
        } else if( !DsMemMacValidLeftVal.valid[ tmpIdxLeft[4:0] : tmpIdxLeft[4:0] ] ) {
            tmpHasLeftEmpth                 = 1;
            tmpLeftEmptyIdx[6:0] = tmpIdxLeft;
        } else if( !DsMemMacStaticLeftVal.isStatic[ tmpIdxLeft[4:0] : tmpIdxLeft[4:0] ] ) {
            tmpAgingLeSub[4:0]           = tmpIdxLeft[3:0] << 1;
            if( (DsMemMacAgingLeftVal.age[tmpAgingLeSub+1:tmpAgingLeSub]) <= tmpAgingFlagLeft ) {
                tmpAgingFlagLeft[1:0]    = DsMemMacAgingLeftVal.age[tmpAgingLeSub+1:tmpAgingLeSub];
                tmpOverWrLeft            = 1;
                tmpOverWrLeftIdx[6:0]          = tmpIdxLeft;
            }
        }
         // Right check
        if( DsMemMacValidRightVal.valid[ tmpIdxRight[4:0] : tmpIdxRight[4:0] ] && (DsMemMacKeyRightVal.vlanId0[11:0] == MsgLearnInfo.fid) && 
           (DsMemMacKeyRightVal.macAddr0[47:0] == MsgLearnInfo.macSa) && (DsMemMacKeyRightVal.macAddrHi0[15:0] == MsgLearnInfo.macSaHi) && 
           (!DsMemMacStaticRightVal.isStatic[ tmpIdxRight[4:0] : tmpIdxRight[4:0] ]) ) {
            tmpHashRightHit                 = 1;
            tmpRightHitIdx[6:0]  = tmpIdxRight;
        } else if( !DsMemMacValidRightVal.valid[ tmpIdxRight[4:0] : tmpIdxRight[4:0] ] ) {
            tmpHasRightEmpty                = 1;
            tmpRightEmptyIdx[6:0]= tmpIdxRight;
        } else if( !DsMemMacStaticRightVal.isStatic[ tmpIdxRight[4:0] : tmpIdxRight[4:0] ] ) {
            tmpAgingRiSub[4:0]           = tmpIdxRight[3:0] << 1;
            if( (DsMemMacAgingRightVal.age[tmpAgingRiSub+1:tmpAgingRiSub]) <= tmpAgingFlagRight ) {
                tmpAgingFlagRight[1:0]   = DsMemMacAgingRightVal.age[tmpAgingRiSub+1:tmpAgingRiSub];
                tmpOverWrRight           = 1;
                tmpOverWrRightIdx[6:0] = tmpIdxRight;
            }
        }
    
        tmpIdxLeft[6:0]       = (tmpLrnHashLeft << 2) + 1;
        tmpIdxRight[6:0]      = (tmpLrnHashRight << 2) + 1;
        // Left check
        if ((DsMemMacValidLeftVal.valid[ tmpIdxLeft[4:0] : tmpIdxLeft[4:0] ] && (DsMemMacKeyLeftVal.vlanId1[11:0] == MsgLearnInfo.fid) && 
            (DsMemMacKeyLeftVal.macAddr1[31:0] == MsgLearnInfo.macSa) && (DsMemMacKeyLeftVal.macAddrHi1[15:0] == MsgLearnInfo.macSaHi) ) && 
            (!DsMemMacStaticLeftVal.isStatic[ tmpIdxLeft[4:0] : tmpIdxLeft[4:0] ])) {
            tmpHashLeftHit                  = 1;
            tmpLeftHitIdx[6:0]   = tmpIdxLeft;
        } else if( !DsMemMacValidLeftVal.valid[ tmpIdxLeft[4:0] : tmpIdxLeft[4:0] ] ) {
            tmpHasLeftEmpth                 = 1;
            tmpLeftEmptyIdx[6:0] = tmpIdxLeft;
        } else if( !DsMemMacStaticLeftVal.isStatic[ tmpIdxLeft[4:0] : tmpIdxLeft[4:0] ] ) {
            tmpAgingLeSub[4:0]           = tmpIdxLeft[3:0] << 1;
            if( (DsMemMacAgingLeftVal.age[tmpAgingLeSub+1:tmpAgingLeSub]) <= tmpAgingFlagLeft ) {
                tmpAgingFlagLeft[1:0]    = DsMemMacAgingLeftVal.age[tmpAgingLeSub+1:tmpAgingLeSub];
                tmpOverWrLeft            = 1;
                tmpOverWrLeftIdx[6:0]          = tmpIdxLeft;
            }
        }
         // Right check
        if( DsMemMacValidRightVal.valid[ tmpIdxRight[4:0] : tmpIdxRight[4:0] ] && (DsMemMacKeyRightVal.vlanId1[11:0] == MsgLearnInfo.fid) && 
           (DsMemMacKeyRightVal.macAddr1[47:0] == MsgLearnInfo.macSa) && (DsMemMacKeyRightVal.macAddrHi1[15:0] == MsgLearnInfo.macSaHi) && 
           (!DsMemMacStaticRightVal.isStatic[ tmpIdxRight[4:0] : tmpIdxRight[4:0] ]) ) {
            tmpHashRightHit                 = 1;
            tmpRightHitIdx[6:0]  = tmpIdxRight;
        } else if( !DsMemMacValidRightVal.valid[ tmpIdxRight[4:0] : tmpIdxRight[4:0] ] ) {
            tmpHasRightEmpty                = 1;
            tmpRightEmptyIdx[6:0]= tmpIdxRight;
        } else if( !DsMemMacStaticRightVal.isStatic[ tmpIdxRight[4:0] : tmpIdxRight[4:0] ] ) {
            tmpAgingRiSub[4:0]           = tmpIdxRight[3:0] << 1;
            if( (DsMemMacAgingRightVal.age[tmpAgingRiSub+1:tmpAgingRiSub]) <= tmpAgingFlagRight ) {
                tmpAgingFlagRight[1:0]   = DsMemMacAgingRightVal.age[tmpAgingRiSub+1:tmpAgingRiSub];
                tmpOverWrRight           = 1;
                tmpOverWrRightIdx[6:0] = tmpIdxRight;
            }
        }
    
    // sort result
    if( tmpHashLeftHit ) {
        MsgLearnInfo.lrnType[2:0]       = LEFT_HIT;
        MsgLearnInfo.learnIdx  = tmpLeftHitIdx;
        DsMemMacSaVal          = DsMemMac[ tmpLeftHitIdx ];
        CtlLearnLkpLog.leftHitNum[15:0] += 1;
    } else if( tmpHashRightHit ) {
        MsgLearnInfo.lrnType   = RIGHT_HIT;
        MsgLearnInfo.learnIdx  = tmpRightHitIdx;
        DsMemMacSaVal          = DsMemMac[ tmpRightHitIdx ];
        CtlLearnLkpLog.rightHitNum[15:0] += 1;
    } else if( tmpHasLeftEmpth ) {
        MsgLearnInfo.lrnType   = LEFT_EMPTY;
        MsgLearnInfo.learnIdx  = tmpLeftEmptyIdx; 
        CtlLearnLkpLog.leftNewNum[15:0] += 1;
    } else if( tmpHasRightEmpty ) {
        MsgLearnInfo.lrnType   = RIGHT_EMPTY;
        MsgLearnInfo.learnIdx  = tmpRightEmptyIdx;    
        CtlLearnLkpLog.rightNewNum[15:0] += 1;
    } else if( tmpOverWrLeft ) {
        MsgLearnInfo.lrnType   = LEFT_OW;
        MsgLearnInfo.learnIdx  = tmpOverWrLeftIdx;    
        DsMemMacSaVal          = DsMemMac[ tmpOverWrLeftIdx ];
        CtlLearnLkpLog.leftOwNum[15:0] += 1;
    } else if( tmpOverWrRight ) {
        MsgLearnInfo.lrnType   = RIGHT_OW;
        MsgLearnInfo.learnIdx  = tmpOverWrRightIdx;   
        DsMemMacSaVal          = DsMemMac[ tmpOverWrRightIdx ];
        CtlLearnLkpLog.rightOwNum[15:0] += 1;
    }   
    CtlLearnLkpLog.resultIdx[6:0]   = MsgLearnInfo.learnIdx[6:0];
    CtlLearnLkpLog.lrnType     = MsgLearnInfo.lrnType;

    /** Learning Process */
    DsRegPortLearnNumVal       = DsRegPortLearnNum[ MsgLearnInfo.srcPortIdx[4:0] ];
    
    // Security check
    if( (MsgLearnInfo.lrnType == LEFT_HIT) || (MsgLearnInfo.lrnType == RIGHT_HIT) || 
        (MsgLearnInfo.lrnType == LEFT_OW) || (MsgLearnInfo.lrnType == RIGHT_OW) ) {
        tmpStationMove = !DsMemMacSaVal.isMcast && (MsgLearnInfo.srcMap[10:0] != DsMemMacSaVal.destMap[10:0]) && 
                          ( (MsgLearnInfo.lrnType == LEFT_HIT) || (MsgLearnInfo.lrnType == RIGHT_HIT) );
        tmpPhyPort[4:0] = {0, DsMemMacSaVal.destMap[2:0]};
        tmpLagPort[4:0] = {1, DsMemMacSaVal.destMap[2:0]};
        tmpOldPortIdx[4:0] = (DsMemMacSaVal.destMap[10:10]) ? tmpLagPort : tmpPhyPort; 
        if( tmpStationMove && CtlLearn.forbidMove ) {
            MsgLearnInfo.lrnType              = LRN_DISABLE;
            CtlLearnLkpLog.stationMoveDrop = 1;
        } else if( tmpStationMove ) {
            CtlLearnLkpLog.stationAutoMoved = 1;
            tmpStaMoveRecord[63:0] = {CtlStationMoveLog.recordHi[31:0], CtlStationMoveLog.recordLo[31:0]};
            tmpStaMoveRecord[ MsgLearnInfo.srcPortIdx[4:0]:MsgLearnInfo.srcPortIdx[4:0] ] = 1;
            CtlStationMoveLog.recordHi = tmpStaMoveRecord >> 32;
            CtlStationMoveLog.recordLo = tmpStaMoveRecord;
        }
    }
    // update table
    if( MsgLearnInfo.lrnType != LRN_DISABLE ) {
        CtlLearnLkpLog.autoLearnt       = 1;
        TmpDsMemMac.destMap[10:0] = MsgLearnInfo.srcMap[10:0];

        tmpBuckSubIdx[1:0]     = MsgLearnInfo.learnIdx[1:0] ;
        tmpAgingSubIdx[4:0]    = MsgLearnInfo.learnIdx[3:0] << 1;
        tmpValidSubIdx[4:0]    = MsgLearnInfo.learnIdx[4:0] ;
        if( (MsgLearnInfo.lrnType == LEFT_HIT) || (MsgLearnInfo.lrnType == LEFT_EMPTY)
        || (MsgLearnInfo.lrnType == LEFT_OW) ) {
            DsMemMac[ MsgLearnInfo.learnIdx[6:0] ] = TmpDsMemMac;
            DsMemMacKeyLeftVal = DsMemMacKey[ MsgLearnInfo.learnIdx[6:2] ];
            DsMemMacKeyLeftVal.vlanId{tmpBuckSubIdx[1:0]}[11:0] = MsgLearnInfo.fid[11:0];
            DsMemMacKeyLeftVal.macAddr{tmpBuckSubIdx[1:0]}[31:0] = MsgLearnInfo.macSa[31:0];
            DsMemMacKeyLeftVal.macAddrHi{tmpBuckSubIdx[1:0]}[15:0] = MsgLearnInfo.macSaHi[15:0];
            DsMemMacKey[ MsgLearnInfo.learnIdx[6:2] ] = DsMemMacKeyLeftVal;

            DsMemMacValidLeftVal = DsMemMacValid[ MsgLearnInfo.learnIdx[6:5] ];
            DsMemMacValidLeftVal.valid |= 1 << tmpValidSubIdx;
            DsMemMacValid[ MsgLearnInfo.learnIdx[6:5] ] = DsMemMacValidLeftVal;

            DsMemMacAgingLeftVal = DsMemMacAging[ MsgLearnInfo.learnIdx[6:4] ];
            DsMemMacAgingLeftVal.age |= 3 << tmpAgingSubIdx;
            DsMemMacAging[ MsgLearnInfo.learnIdx[6:4] ] = DsMemMacAgingLeftVal;

        } else if( (MsgLearnInfo.lrnType == RIGHT_HIT) || (MsgLearnInfo.lrnType == RIGHT_EMPTY)
        || (MsgLearnInfo.lrnType == RIGHT_OW) ) {
            DsMemMac[ MsgLearnInfo.learnIdx ] = TmpDsMemMac;
            DsMemMacKeyRightVal = DsMemMacKey[ MsgLearnInfo.learnIdx[6:2] ];
            DsMemMacKeyRightVal.vlanId{tmpBuckSubIdx[1:0]}[11:0] = MsgLearnInfo.fid[11:0];
            DsMemMacKeyRightVal.macAddr{tmpBuckSubIdx[1:0]}[31:0] = MsgLearnInfo.macSa[31:0];
            DsMemMacKeyRightVal.macAddrHi{tmpBuckSubIdx[1:0]}[15:0] = MsgLearnInfo.macSaHi[15:0];
            DsMemMacKey[ MsgLearnInfo.learnIdx[6:2] ] = DsMemMacKeyRightVal;

            DsMemMacValidRightVal = DsMemMacValid[ MsgLearnInfo.learnIdx[6:5] ];
            DsMemMacValidRightVal.valid |= 1 << tmpValidSubIdx;
            DsMemMacValid[ MsgLearnInfo.learnIdx[6:5] ] = DsMemMacValidRightVal;

            DsMemMacAgingRightVal = DsMemMacAging[ MsgLearnInfo.learnIdx[6:4] ];
            DsMemMacAgingRightVal.age |= 3 << tmpAgingSubIdx;
            DsMemMacAging[ MsgLearnInfo.learnIdx[6:4] ] = DsMemMacAgingRightVal;
        }

        // overwrite and station move
        if( ((MsgLearnInfo.lrnType != LEFT_HIT) && (MsgLearnInfo.lrnType != RIGHT_HIT)) || tmpStationMove ) {
            DsRegPortLearnNumVal.learntMacNum += 1;
        }
        if( tmpStationMove || (MsgLearnInfo.lrnType == LEFT_OW) || (MsgLearnInfo.lrnType == RIGHT_OW) ) {
            DsRegPortLearnNumOldVal = DsRegPortLearnNum[ tmpOldPortIdx[5:0] ];
            DsRegPortLearnNumOldVal.learntMacNum -= 1;
        }
        DsRegPortLearnNum[ tmpOldPortIdx ] = DsRegPortLearnNumOldVal;
        DsRegPortLearnNum[ MsgLearnInfo.srcPortIdx[4:0]] = DsRegPortLearnNumVal;
    }
}
    