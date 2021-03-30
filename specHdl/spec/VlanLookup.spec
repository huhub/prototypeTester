
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
    
    
    PI.ptpEn      = ((PI.srcPort == CtlCommon.ofPortNo) || (PI.srcPort == CtlCommon.cpuPortNo)) ? 
                     1 : DsMemPhyPortVal.ptpEn && (DsMemPhyPortVal.ptpPortType != PTP_PORT_DISABLE);
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
    
        if( DsMemMacBasedVlanKeyVal.entryValid[0:0] && (tmpMacSa[31:0] == DsMemMacBasedVlanKeyVal.macSa0) && 
            (DsMemMacBasedVlanKeyVal.macSaHi0 == tmpMacSaHi) ) {
            PI.macBasedVlanValid     = 1;
            PI.macBasedVlanIdx  = (tmpIdx << 2) + 0;
        }
    
        if( DsMemMacBasedVlanKeyVal.entryValid[1:1] && (tmpMacSa == DsMemMacBasedVlanKeyVal.macSa1) && 
            (DsMemMacBasedVlanKeyVal.macSaHi1 == tmpMacSaHi) ) {
            PI.macBasedVlanValid     = 1;
            PI.macBasedVlanIdx  = (tmpIdx << 2) + 1;
        }
    
        if( DsMemMacBasedVlanKeyVal.entryValid[2:2] && (tmpMacSa == DsMemMacBasedVlanKeyVal.macSa2) && 
            (DsMemMacBasedVlanKeyVal.macSaHi2 == tmpMacSaHi) ) {
            PI.macBasedVlanValid     = 1;
            PI.macBasedVlanIdx  = (tmpIdx << 2) + 2;
        }
    
        if( DsMemMacBasedVlanKeyVal.entryValid[3:3] && (tmpMacSa[31:0] == DsMemMacBasedVlanKeyVal.macSa3) && 
            (DsMemMacBasedVlanKeyVal.macSaHi3 == tmpMacSaHi) ) {
            PI.macBasedVlanValid     = 1;
            PI.macBasedVlanIdx  = (tmpIdx << 2) + 3;
        }
    
    }
    if( DsMemPhyPortVal.protocolVlanEn ) {
        tmpL2Tpid[15:0] = {glPktHdr[PI.l3Offset], glPktHdr[PI.l3Offset+1]};
    
        if (CtlProtocolVlanKey.entryValid[0:0] && ((CtlProtocolVlanKey.protoData0 & 
            CtlProtocolVlanKey.protoMask0) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask0))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx     = (PI.srcPort << 3) + 0;
        }
    
        if (CtlProtocolVlanKey.entryValid[1:1] && ((CtlProtocolVlanKey.protoData1 & 
            CtlProtocolVlanKey.protoMask1) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask1))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx     = (PI.srcPort << 3) + 1;
        }
    
        if (CtlProtocolVlanKey.entryValid[2:2] && ((CtlProtocolVlanKey.protoData2 & 
            CtlProtocolVlanKey.protoMask2) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask2))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx     = (PI.srcPort << 3) + 2;
        }
    
        if (CtlProtocolVlanKey.entryValid[3:3] && ((CtlProtocolVlanKey.protoData3 & 
            CtlProtocolVlanKey.protoMask3) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask3))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx     = (PI.srcPort << 3) + 3;
        }
    
        if (CtlProtocolVlanKey.entryValid[4:4] && ((CtlProtocolVlanKey.protoData4 & 
            CtlProtocolVlanKey.protoMask4) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask4))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx     = (PI.srcPort << 3) + 4;
        }
    
        if (CtlProtocolVlanKey.entryValid[5:5] && ((CtlProtocolVlanKey.protoData5 & 
            CtlProtocolVlanKey.protoMask5) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask5))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx     = (PI.srcPort << 3) + 5;
        }
    
        if (CtlProtocolVlanKey.entryValid[6:6] && ((CtlProtocolVlanKey.protoData6 & 
            CtlProtocolVlanKey.protoMask6) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask6))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx     = (PI.srcPort << 3) + 6;
        }
    
        if (CtlProtocolVlanKey.entryValid[7:7] && ((CtlProtocolVlanKey.protoData7 & 
            CtlProtocolVlanKey.protoMask7) == (tmpL2Tpid & CtlProtocolVlanKey.protoMask7))) {
            PI.protocolVlanValid   = 1;
            PI.protocolVlanIdx     = (PI.srcPort << 3) + 7;
        }
    
    }
    PI.vlanLkpRslt = PI.protocolVlanValid ? PI.protocolVlanIdx : PI.macBasedVlanValid ? PI.macBasedVlanIdx : 0;
    CtlVlanLookupLog.vlanLkpRslt = PI.vlanLkpRslt;
    CtlVlanLookupLog.eapolDiscard = PI.eapolDiscard;
    CtlVlanLookupLog.dot1xDiscard = PI.dot1xDiscard;
    CtlVlanLookupLog.chkMacSaFail = PI.chkMacSaFail;
    CtlVlanLookupLog.ptpDiscard = PI.ptpDiscard;
    CtlVlanLookupLog.ipSubnetVlanValid = PI.ipSubnetVlanValid;
    CtlVlanLookupLog.macBasedVlanValid = PI.macBasedVlanValid;
    CtlVlanLookupLog.protocolVlanValid = PI.protocolVlanValid;
    CtlVlanLookupLog.isTsn = PI.isTsn;
    CtlVlanLookupLog.ptpEn = PI.ptpEn;
}
    
