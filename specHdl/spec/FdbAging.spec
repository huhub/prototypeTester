
process FdbAging() {
    // The interval of aging is configurable, default interval is 300s/4
    tmp1stFast                  = 0;
    while( CtlAging.agingEn ) {
        if (CtlAging.agingType[1:0] != NORMAL_AGING && tmp1stFast == 0) {
            CtlAging.currentPtr[15:0] = CtlAging.agingMinPtr[15:0];
            tmp1stFast = 1;
        }
        tmpAgingPtr[15:0] = CtlAging.currentPtr >= CtlAging.agingMaxPtr[15:0] ? CtlAging.agingMinPtr : CtlAging.currentPtr;
        
        if ( tmpAgingPtr < CtlAging.agingMidPtr[15:0] ) {
            // Aging process
             AgingProcess( tmpAgingPtr );
        }
        CtlAging.currentPtr    = tmpAgingPtr + 1;
        if( CtlAging.agingType == NORMAL_AGING ) { 
            DelayCycle( CtlAging.agingInterval[31:0] );
        } else if (CtlAging.agingType != NORMAL_AGING && CtlAging.currentPtr > CtlAging.agingMaxPtr) {
            CtlAging.agingType  = NORMAL_AGING;
            tmp1stFast               = 0;
        }
    }
}
// Assume the entry number is power of 2.
static function AgingProcess(  accessPtr[15:0] ) {
    DsMemMacStaticVal      = DsMemMacStatic[ accessPtr[15:5] ];
    DsMemMacAgingVal       = DsMemMacAging[ accessPtr[15:4] ];
    DsMemMacVal            = DsMemMac[ accessPtr ];
    DsMemMacKeyVal         = DsMemMacKey[ accessPtr[15:0] ];
    DsMemMacValidVal       = DsMemMacValid[ accessPtr[15:5] ];
    AgingTableEntry(DsMemMacVal, DsMemMacStaticVal, DsMemMacAgingVal, DsMemMacValidVal, DsMemMacKeyVal, accessPtr[4:0]);
    DsMemMacAging[ accessPtr[15:4] ] = DsMemMacAgingVal;
    DsMemMacValid[ accessPtr[15:5] ] = DsMemMacValidVal;
}

function AgingTableEntry(DsMemMac, DsMemMacStatic, DsMemMacAging, DsMemMacValid, DsMemMacKey, pointer[4:0]) {
    tmpSubIdx[4:0]     = pointer[3:0] << 1;
    tmpIsStatic        = DsMemMacStatic.isStatic[ pointer : pointer ];
    tmpAgingFlag[1:0]  = DsMemMacAging.age[ tmpSubIdx+1 : tmpSubIdx ];
    tmpIsValid         = DsMemMacValid.valid[ pointer : pointer ];
    tmpLagPort[4:0]    = {1, DsMemMac.destMap[2:0]};
    tmpPhyPort[4:0]    = {0, DsMemMac.destMap[2:0]};
    tmpPortIdx[4:0]    = DsMemMac.destMap[10:10] ? tmpLagPort : tmpPhyPort;
    tmpIsPending       = DsMemMac.pending;
    DsRegPortLearnCtrlVal = DsRegPortLearnCtrl[ tmpPortIdx ];
    tmpLock            = DsRegPortLearnCtrlVal.lock;
    DsRegPortLearnNumVal  = DsRegPortLearnNum[ tmpPortIdx ];
    tmpVlanId[11:0]    = DsMemMacKey.vlanId{pointer[1:0]}[11:0];
    tmpOperateEn = ( (CtlAging.perPortEn && (CtlAging.destMap[10:0] == DsMemMac.destMap) ) || 
                     (CtlAging.perVlanEn && (CtlAging.vlanId[11:0] == tmpVlanId)) ||
                     (CtlAging.perPortVlan && (CtlAging.destMap == DsMemMac.destMap) && (CtlAging.vlanId[11:0] == tmpVlanId)) );

    if( (CtlAging.opStatic || !tmpIsStatic) && tmpIsValid && !tmpIsPending ) {
        if( CtlAging.agingType == NORMAL_AGING && !tmpLock) {
            if( tmpAgingFlag[1:0] == 0 ) {
                DsMemMacValid.valid[ pointer : pointer ] = 0;
                DsRegPortLearnNumVal.learntMacNum -= 1;
            } else {
                DsMemMacAging.age[ tmpSubIdx+1 : tmpSubIdx ] = tmpAgingFlag[1:0]-1;
            }
        } else if( CtlAging.agingType == FAST_AGING ) {
            DsMemMacValid.valid[ pointer : pointer ] = 0;
        } else if( CtlAging.agingType == FAST_SPECIAL ) {
            if( tmpOperateEn ) {
                DsMemMacValid.valid[ pointer : pointer ] = 0;
                if( CtlAging.perPortEn || CtlAging.perPortVlan ) {
                    DsRegPortLearnNumVal.learntMacNum -= 1;
                }
            }
        } else if( CtlAging.agingType == REPLACE ) {
            tmpNewPortIdx[4:0] = CtlAging.newDestMap[10:0];
            if (CtlAging.newDestMap[10:10]) {
                tmpNewPortIdx = CtlAging.newDestMap[2:0] + 32;
            }
            DsRegPortLearnNumNewVal = DsRegPortLearnNum[ tmpNewPortIdx ];
            DsRegPortLearnCtrlNewVal = DsRegPortLearnCtrl[ tmpNewPortIdx ];
            tmpNoNumLimit = DsRegPortLearnNumNewVal.learntMacNum < DsRegPortLearnCtrlNewVal.maxMacNum[14:0];
            if( tmpOperateEn && tmpNoNumLimit ) {
                DsMemMac.destMap  = CtlAging.newDestMap;
                DsRegPortLearnNumVal.learntMacNum -= 1;
                DsRegPortLearnNumNewVal.learntMacNum += 1;
                DsRegPortLearnNum[ tmpNewPortIdx ] = DsRegPortLearnNumNewVal;
            }
        } // end of agingType
    }
    DsRegPortLearnNum[ tmpPortIdx ] = DsRegPortLearnNumVal;
}
    