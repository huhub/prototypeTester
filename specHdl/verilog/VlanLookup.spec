
function VlanLookup(PI) {
    PI.cpuPktType        = CPU_PKT_NONE;
    DsMemPhyPortVal      = DsMemPhyPort[ PI.srcPort ];
    // EAPOL check
    PI.logicalPort       = DsMemPhyPortVal.logicalPort;
    if( (PI.l3Type == L3_TYPE_EAPOL) && DsMemPhyPortVal.dot1xEn && !PI.bypassPp ) {
        PI.copyToCpu          = 1;
        PI.discard            = PI.discard | 1;
        PI.cpuPktType         = CPU_PKT_EAPOL;
        PI.eapolDiscard = 1;
    }
    if( DsMemPhyPortVal.dot1xEn && DsMemPhyPortVal.dot1xDrop && (PI.l3Type != L3_TYPE_EAPOL) ){
        PI.discard            = PI.discard | 1;
        PI.dot1xDiscard = 1;
    }
    
    PI.isTsn      = PI.isTsn | (DsMemPhyPortVal.avAsTsn && PI.isAvFrame);
    
    
    PI.ptpEn      = ((PI.srcPort == CtlCommon.ofPortNo[0:0]) || (PI.srcPort == CtlCommon.cpuPortNo[0:0])) ? 
                     1 : DsMemPhyPortVal.ptpEn && (DsMemPhyPortVal.ptpPortType[1:0] != PTP_PORT_DISABLE);
    PI.ptpDiscard = PI.isPtp && !PI.ptpEn;
    PI.discard    = PI.discard | PI.ptpDiscard;
    

    // Vlan classification
    tmpPr =  findPrByType( PROTO_TYPE_ETH );
    if (DsMemPhyPortVal.macBasedVlanEn) {
        tmpMacSaHi[15:0] = {glPktHdr[tmpPr.offset+6], glPktHdr[tmpPr.offset+7]};
        tmpMacSa[31:0]   = {glPktHdr[tmpPr.offset+8], glPktHdr[tmpPr.offset+11]};
        bufKey[47:0]  = glPktHdr[tmpPr.offset+6 : tmpPr.offset+11];
        // Initial value is 0
        tmpIdx = CRC8_D48( bufKey, sizeof(bufKey) ) & 7'h7f;   
        DsMemMacBasedVlanKeyVal  = DsMemMacBasedVlanKey[ tmpIdx ];
    
        if( DsMemMacBasedVlanKeyVal.entryValid[0:0] && (tmpMacSa[31:0] == DsMemMacBasedVlanKeyVal.macSa0[31:0]) && 
            (DsMemMacBasedVlanKeyVal.macSaHi0[15:0] == tmpMacSaHi[15:0]) ) {
            PI.macBasedVlanValid     = 1;
            PI.macBasedVlanIdx  = (tmpIdx << 2) + 0;
        }
    
        if( DsMemMacBasedVlanKeyVal.entryValid[1:1] && (tmpMacSa[31:0] == DsMemMacBasedVlanKeyVal.macSa1[31:0]) && 
            (DsMemMacBasedVlanKeyVal.macSaHi1[15:0] == tmpMacSaHi[15:0]) ) {
            PI.macBasedVlanValid     = 1;
            PI.macBasedVlanIdx  = (tmpIdx << 2) + 1;
        }
    
        if( DsMemMacBasedVlanKeyVal.entryValid[2:2] && (tmpMacSa[31:0] == DsMemMacBasedVlanKeyVal.macSa2[31:0]) && 
            (DsMemMacBasedVlanKeyVal.macSaHi2[15:0] == tmpMacSaHi[15:0]) ) {
            PI.macBasedVlanValid     = 1;
            PI.macBasedVlanIdx  = (tmpIdx << 2) + 2;
        }
    
        if( DsMemMacBasedVlanKeyVal.entryValid[3:3] && (tmpMacSa[31:0] == DsMemMacBasedVlanKeyVal.macSa3[31:0]) && 
            (DsMemMacBasedVlanKeyVal.macSaHi3[15:0] == tmpMacSaHi[15:0]) ) {
            PI.macBasedVlanValid     = 1;
            PI.macBasedVlanIdx  = (tmpIdx << 2) + 3;
        }
    
    }
    if( DsMemPhyPortVal.protocolVlanEn ) {
        tmpL2Tpid[15:0] = {glPktHdr[PI.l3Offset], glPktHdr[PI.l3Offset+1]};
    
        if (CtlProtocolVlanKey.entryValid[0:0] && ((CtlProtocolVlanKey.protoData0[15:0] & 
            CtlProtocolVlanKey.protoMask0[15:0]) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask0[15:0]))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx[7:0]     = (PI.srcPort << 3) + 0;
        }
    
        if (CtlProtocolVlanKey.entryValid[1:1] && ((CtlProtocolVlanKey.protoData1[15:0] & 
            CtlProtocolVlanKey.protoMask1[15:0]) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask1[15:0]))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx[7:0]     = (PI.srcPort << 3) + 1;
        }
    
        if (CtlProtocolVlanKey.entryValid[2:2] && ((CtlProtocolVlanKey.protoData2[15:0] & 
            CtlProtocolVlanKey.protoMask2[15:0]) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask2[15:0]))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx[7:0]     = (PI.srcPort << 3) + 2;
        }
    
        if (CtlProtocolVlanKey.entryValid[3:3] && ((CtlProtocolVlanKey.protoData3[15:0] & 
            CtlProtocolVlanKey.protoMask3[15:0]) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask3[15:0]))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx[7:0]     = (PI.srcPort << 3) + 3;
        }
    
        if (CtlProtocolVlanKey.entryValid[4:4] && ((CtlProtocolVlanKey.protoData4[15:0] & 
            CtlProtocolVlanKey.protoMask4[15:0]) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask4[15:0]))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx[7:0]     = (PI.srcPort << 3) + 4;
        }
    
        if (CtlProtocolVlanKey.entryValid[5:5] && ((CtlProtocolVlanKey.protoData5[15:0] & 
            CtlProtocolVlanKey.protoMask5[15:0]) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask5[15:0]))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx[7:0]     = (PI.srcPort << 3) + 5;
        }
    
        if (CtlProtocolVlanKey.entryValid[6:6] && ((CtlProtocolVlanKey.protoData6[15:0] & 
            CtlProtocolVlanKey.protoMask6[15:0]) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask6[15:0]))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx[7:0]     = (PI.srcPort << 3) + 6;
        }
    
        if (CtlProtocolVlanKey.entryValid[7:7] && ((CtlProtocolVlanKey.protoData7[15:0] & 
            CtlProtocolVlanKey.protoMask7[15:0]) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask7[15:0]))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx[7:0]     = (PI.srcPort << 3) + 7;
        }
    
    }
    PI.vlanLkpRslt = PI.protocolVlanValid ? PI.protocolVlanIdx : PI.macBasedVlanValid ? PI.macBasedVlanIdx : 0;
    CtlVlanLookupLog.vlanLkpRslt[10:0] = PI.vlanLkpRslt[10:0];
    CtlVlanLookupLog.eapolDiscard[0:0] = PI.eapolDiscard;
    CtlVlanLookupLog.dot1xDiscard[0:0] = PI.dot1xDiscard;
    CtlVlanLookupLog.chkMacSaFail[0:0] = PI.chkMacSaFail;
    CtlVlanLookupLog.ptpDiscard[0:0] = PI.ptpDiscard;
    CtlVlanLookupLog.ipSubnetVlanValid[0:0] = PI.ipSubnetVlanValid;
    CtlVlanLookupLog.macBasedVlanValid[0:0] = PI.macBasedVlanValid;
    CtlVlanLookupLog.protocolVlanValid[0:0] = PI.protocolVlanValid;
    CtlVlanLookupLog.isTsn[0:0] = PI.isTsn;
    CtlVlanLookupLog.ptpEn[0:0] = PI.ptpEn;
}
    
