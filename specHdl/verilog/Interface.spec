
function Interface(PI){
    // port property
    DsMemSrcPortVal = DsMemSrcPort[ PI.srcPort ];
    PI.defaultVlanId[11:0] = DsMemSrcPortVal.defaultVlanId[11:0];
    PI.l2AclLabel[5:0] = DsMemSrcPortVal.l2AclLabel[5:0];
    PI.linkAggId[4:0] = DsMemSrcPortVal.linkAggId[4:0];
    PI.defaultPcp[2:0] = DsMemSrcPortVal.defaultPcp[2:0];
    PI.qosPolicy[1:0] = DsMemSrcPortVal.qosPolicy[1:0];
    PI.aft[1:0] = DsMemSrcPortVal.aft[1:0];
    PI.isLinkAggMbr = DsMemSrcPortVal.isLinkAggMbr;
    PI.ingressFilteringEn = DsMemSrcPortVal.ingressFilteringEn;
    PI.portPoliceEn = DsMemSrcPortVal.portPoliceEn;
    PI.lrnDisable = DsMemSrcPortVal.lrnDisable;
    PI.l2SrcMatchDiscard = DsMemSrcPortVal.l2SrcMatchDiscard;
    PI.bpduDrop = DsMemSrcPortVal.bpduDrop;
    PI.stpDisable = DsMemSrcPortVal.stpDisable;
    PI.forcePortBasedVlan = DsMemSrcPortVal.forcePortBasedVlan;
    PI.l2AclEn = DsMemSrcPortVal.l2AclEn;
    PI.l2AclHiPrio = DsMemSrcPortVal.l2AclHiPrio;
    PI.ipv4ForceMacKey = DsMemSrcPortVal.ipv4ForceMacKey;
    PI.ipv6ForceMacKey = DsMemSrcPortVal.ipv6ForceMacKey;
    PI.replaceDscp = DsMemSrcPortVal.replaceDscp;
    PI.replaceCos = DsMemSrcPortVal.replaceCos;
    PI.vlanPrioEn = DsMemSrcPortVal.vlanPrioEn;
    PI.macBasedVlanHiPrio = DsMemSrcPortVal.macBasedVlanHiPrio;
    PI.keepVlanTag = DsMemSrcPortVal.keepVlanTag;
    PI.ingressL2SpanEn = DsMemSrcPortVal.ingressL2SpanEn;
    tmpDefaultPcp[2:0]    = DsMemSrcPortVal.defaultPcp;
    PI.lrnDisable    = PI.lrnDisable | DsMemSrcPortVal.lrnDisable;
    // Accept type
    tmpPr = findPrByType( PROTO_TYPE_ETH );
    tmpTaggedPkt  = tmpPr.qualifier[4:2] != 0;
    tmpSvid[11:0] = {glPktHdr[tmpPr.offset+14][3:0], glPktHdr[tmpPr.offset+15]};
    if (tmpPr.qualifier[2:2]) {
        tmpCvid[11:0] = {glPktHdr[tmpPr.offset+18][3:0], glPktHdr[tmpPr.offset+19]};
        tmpCcos[2:0]  = glPktHdr[tmpPr.offset+18][7:5];
    } else if (tmpPr.qualifier[4:4]) {
        tmpCvid       = {glPktHdr[tmpPr.offset+14][3:0], glPktHdr[tmpPr.offset+15]};
        tmpCcos       = glPktHdr[tmpPr.offset+14][7:5];
    }
    if (DsMemSrcPortVal.aft[1:0] == VLAN_AFT_TAGGED ) {
        PI.aftDiscard     = !tmpTaggedPkt;
    } else if (DsMemSrcPortVal.aft[1:0] == VLAN_AFT_NO_TAG ) {
        PI.aftDiscard     = tmpTaggedPkt;
    } else if (DsMemSrcPortVal.aft[1:0] == VLAN_AFT_NONE ) {
        PI.aftDiscard     = 1;
    }
    PI.removeVlanTag      = tmpTaggedPkt && !DsMemSrcPortVal.keepVlanTag;

    if (PI.aftDiscard ) {
        PI.discard        = PI.discard | 1;
    }

    if (PI.macBasedVlanValid )  
        DsMemMacBasedVlanVal = DsMemMacBasedVlan[ PI.macBasedVlanIdx ];
    if (PI.protocolVlanValid )  
        DsMemProtocolVlanVal = DsMemProtocolVlan[ PI.protocolVlanIdx ];
    // Assgin Vlan
    tmpMacVlanFirst = DsMemSrcPortVal.macBasedVlanHiPrio && PI.macBasedVlanValid;
    tmpUseMacVlan   = tmpMacVlanFirst && DsMemMacBasedVlanVal.replaceVlan;
    if (PI.bypassPp || PI.forbidEdit ) {
        PI.vlanId   = PI.vlanId;
    } else if (PI.macBasedVlanValid && (DsMemMacBasedVlanVal.replaceVlan || !tmpTaggedPkt) ) {
        PI.vlanId   = DsMemMacBasedVlanVal.vlanId;
    } else if (PI.protocolVlanValid && (DsMemProtocolVlanVal.replaceVlan || !tmpTaggedPkt) ) {
        PI.vlanId   = DsMemProtocolVlanVal.vlanId;
    } else if (tmpTaggedPkt && !DsMemSrcPortVal.forcePortBasedVlan ) {
        PI.vlanId   = tmpPr.qualifier[3:2] != 0 ? tmpSvid : tmpCvid;
    } else {
        PI.vlanId   = DsMemSrcPortVal.defaultVlanId;
    }
    // Assign Cos
    DsMemVlanVal   = DsMemVlan[ PI.vlanId ];
    tmpMacCosFirst = tmpMacVlanFirst && DsMemMacBasedVlanVal.replaceCos;
    if (PI.macBasedVlanValid && DsMemMacBasedVlanVal.replaceCos ) {
        tmpCos[2:0]= DsMemMacBasedVlanVal.cos[2:0];
    } else if (PI.protocolVlanValid && DsMemProtocolVlanVal.replaceCos ) {
        tmpCos     = DsMemProtocolVlanVal.cos[2:0];
    } else if (DsMemSrcPortVal.vlanPrioEn ) {
        tmpCos     = DsMemVlanVal.cos[2:0];
    } else if (tmpTaggedPkt && !DsMemSrcPortVal.forcePortBasedVlan ) {
        tmpCos     = tmpPr.qualifier[3:2] != 0 ? glPktHdr[tmpPr.offset+14][7:5] : tmpCcos;
    } else {
        tmpCos     = tmpDefaultPcp[2:0];
    }
    PI.cos         = tmpCos;
    // Assign DSCP

    if (PI.l3Type == PROTO_TYPE_IPV4) {
        tmpIpPr = findPrByType( PROTO_TYPE_IPV4 );
        tmpTos[5:0] = glPktHdr[tmpIpPr.offset+1][7:2];
        tmpIpDaW0[31:0]= glPktHdr[tmpIpPr.offset+16 : tmpIpPr.offset+19];
    } else if (PI.l3Type == PROTO_TYPE_IPV6) {
        tmpIpPr = findPrByType( PROTO_TYPE_IPV6 );
        tmpTos[5:0] = {glPktHdr[tmpIpPr.offset][3:0], glPktHdr[tmpIpPr.offset+1][7:6]};
        tmpIpDaW3[31:0] = glPktHdr[tmpIsIp.offset+24 : tmpIsIp.offset+27];
    }
    tmpMacDscpFirst = tmpMacVlanFirst && DsMemMacBasedVlanVal.replaceDscp;
    if (PI.macBasedVlanValid && DsMemMacBasedVlanVal.replaceDscp ) {
        tmpDscp[5:0]= DsMemMacBasedVlanVal.dscp;
    } else if (PI.protocolVlanValid && DsMemProtocolVlanVal.replaceDscp ) {
        tmpDscp     = DsMemProtocolVlanVal.dscp;
    } else {
        tmpDscp     = tmpTos;
    }
	PI.dscp         = tmpDscp;

    // prior mapping
    tmpIsIp         = (PI.l3Type == PROTO_TYPE_IPV4) || (PI.l3Type == PROTO_TYPE_IPV6);
    if (PI.bypassPp && PI.forbidEdit ) {
        PI.prior  = PI.prior;
    } else if ((PI.qosPolicy == QOS_POLICY_DSCP) && tmpIsIp ) {
        PI.prior  = CtlDscpMapPrior.dscpPrior[0:0]{tmpDscp};
    } else if ((PI.qosPolicy == QOS_POLICY_IPCOS) && tmpIsIp ) {
        PI.prior  = CtlIpPrecdncMapPrior.precPrior{tmpDscp[5:3]};
    } else if (PI.qosPolicy == QOS_POLICY_PORTCOS ) {
        PI.prior  = CtlCosMapPrior.cosPrior[0:0]{tmpDefaultPcp};
    } else if (PI.qosPolicy == QOS_POLICY_COS ) {
        PI.prior  = CtlCosMapPrior.cosPrior[0:0]{tmpCos};
    }

    // VlanProperty
    tmpRouterMacBmp[3:0]   = (DsMemVlanVal.vrrpGrpBmp << 1) + 1;
    
    if (tmpRouterMacBmp[0:0] && (CtlRouterMac.routerMac0[31:0] == tmpMacDa) && 
        (CtlRouterMac.routerMacHi0[15:0] == tmpMacDaHi[15:0])) { 
        tmpIsRouterMac = 1;
    }
    
    if (tmpRouterMacBmp[1:1] && (CtlRouterMac.routerMac1[31:0] == tmpMacDa) && 
        (CtlRouterMac.routerMacHi1[15:0] == tmpMacDaHi[15:0])) { 
        tmpIsRouterMac = 1;
    }
    
    if (tmpRouterMacBmp[2:2] && (CtlRouterMac.routerMac2[31:0] == tmpMacDa) && 
        (CtlRouterMac.routerMacHi2[15:0] == tmpMacDaHi[15:0])) { 
        tmpIsRouterMac = 1;
    }
    
    if (tmpRouterMacBmp[3:3] && (CtlRouterMac.routerMac3[31:0] == tmpMacDa) && 
        (CtlRouterMac.routerMacHi3[15:0] == tmpMacDaHi[15:0])) { 
        tmpIsRouterMac = 1;
    }
    

    tmpMacDaHi[15:0]= glPktHdr[tmpPr.offset : tmpPr.offset+1];
    tmpMacDa[31:0]  = glPktHdr[tmpPr.offset+2 : tmpPr.offset+5];
    tmpMacSaHi[15:0]= glPktHdr[tmpPr.offset+6 : tmpPr.offset+7];
    tmpIsUcastIp    = ( (PI.l3Type == PROTO_TYPE_IPV4) && (4'hE != tmpIpDaW0[31:28]) )
                       || ( (PI.l3Type == PROTO_TYPE_IPV6) && (8'hFF != tmpIpDaW3[31:24]) );
    tmpIsMcastIp    = ( (PI.l3Type == PROTO_TYPE_IPV4) && (4'hE == tmpIpDaW0[31:28]) )
                       || ( (PI.l3Type == PROTO_TYPE_IPV6) && (8'hFF == tmpIpDaW3[31:24]) );
    tmpIsIpMcastMac = ( (tmpMacDaHi == 16'h0100) && (tmpMacDa[31:24] == 8'h5e) && (tmpMacDa[23:23] == 1'h0) )
                       || ( 16'h3333 == tmpMacDaHi );
    PI.routingEn    = ( (tmpIsRouterMac && tmpIsUcastIp) || (tmpIsMcastIp && tmpIsIpMcastMac) )  
                          && DsMemVlanVal.routingEn && !PI.bypassPp;
    // discard frame if correspoding vlan processing MC only
    if (DsMemVlanVal.mcastVlanEn ) {
        PI.discard  = PI.discard | (!tmpMacDaHi[8:8]);
    }
	PI.mcVlanDrop   = DsMemVlanVal.mcastVlanEn && !tmpMacDaHi[8:8];
    PI.lrnDisable  |= tmpMacSaHi[8:8];

    
    tmpTsnDomainIdx[14:0] = {PI.vlanId[7:0], PI.prior[5:3]};
    DsMemTsnDomainVal     = DsMemTsnDomain[ tmpTsnDomainIdx ];
    PI.tsnEn              = CtlTsnFunc.enable && DsMemVlanVal.tsnEn && DsMemTsnDomainVal.corePortBmp[ PI.srcPort:PI.srcPort ];
    
    PI.l3AclEn            = DsMemVlanVal.l3AclEn        ; 
    PI.l3AclLabel         = DsMemVlanVal.l3AclLabel;
    PI.l3SpanEn           = DsMemVlanVal.l3SpanEn       ; 
    PI.stpId              = DsMemVlanVal.stpId;
    PI.fid                = DsMemVlanVal.fid   ; 
    PI.replaceCos        |= DsMemVlanVal.replaceCos;
    PI.replaceDscp       |= DsMemVlanVal.replaceDscp;

    tmpToManageVlan       = (CtlManageVlan.vlanId0[0:0] == PI.vlanId) || (CtlManageVlan.vlanId1[0:0] == PI.vlanId);
    if (DsMemVlanVal.arpInspection && (PI.l3Type == PROTO_TYPE_ARP) && !PI.bypassPp ) {
        PI.copyToCpu      = 1;
        PI.discard        = PI.discard | 1;
        PI.cpuPktType     = CPU_PKT_ARP;
    } else if ((tmpToManageVlan || DsMemVlanVal.routingEn) && tmpPr.qualifier[0:0] && (PI.l3Type == PROTO_TYPE_ARP) && !PI.bypassPp ) {
        PI.copyToCpu      = 1;
        PI.cpuPktType     = CPU_PKT_ARP;
        PI.discard        = PI.discard | ( !DsMemVlanVal.hwBcastArp );
    } 
    
    if ((PI.l3Type == PROTO_TYPE_MSRP) && !PI.bypassPp && DsMemVlanVal.msrpToCpu ) {
        PI.copyToCpu      = 1;
        PI.cpuPktType     = CPU_PKT_MSRP;
        PI.discard        = PI.discard | ( !DsMemVlanVal.hwFwdMsrp );
    }
    if ((PI.l3Type == PROTO_TYPE_MMRP) && !PI.bypassPp && DsMemVlanVal.mmrpToCpu ) {
        PI.copyToCpu      = 1;
        PI.cpuPktType     = CPU_PKT_MMRP;
        PI.discard        = PI.discard | ( !DsMemVlanVal.hwFwdMmrp );
    }
    if ((PI.l3Type == PROTO_TYPE_MVRP) && !PI.bypassPp && DsMemVlanVal.mvrpToCpu ) {
        PI.copyToCpu      = 1;
        PI.cpuPktType     = CPU_PKT_MVRP;
        PI.discard        = PI.discard | ( !DsMemVlanVal.hwFwdMvrp );
    }
    
    if ((PI.l4Type == PROTO_TYPE_IGMP) && DsMemVlanVal.igmpSnoopEn && !PI.bypassPp ) {
        PI.copyToCpu      = 1;
        PI.cpuPktType     = CPU_PKT_IGMP;
        PI.discard        = PI.discard | ( !DsMemVlanVal.hwBcastIgmp );
    }
    if ((PI.l4Type == PROTO_TYPE_MLD) && DsMemVlanVal.mldSnoopEn && !PI.bypassPp ) {
        PI.copyToCpu      = 1;
        PI.cpuPktType     = CPU_PKT_MLD;
        PI.discard        = PI.discard | ( !DsMemVlanVal.hwBcastMld );
    }
    if ((PI.l4Type == PROTO_TYPE_ND) && DsMemVlanVal.ndToCpu && !PI.bypassPp ) {
        PI.copyToCpu      = 1;
        PI.cpuPktType     = CPU_PKT_ND;
        PI.discard        = PI.discard | ( !DsMemVlanVal.hwFwdNd );
    }
    if ((PI.isSnmp) && DsMemVlanVal.snmpToCpu && !PI.bypassPp ) {
        PI.copyToCpu      = 1;
        PI.cpuPktType     = CPU_PKT_SNMP;
        PI.discard        = PI.discard | ( !DsMemVlanVal.hwFwdSnmp );
    }
    
    PI.lrnDisable        |= DsMemVlanVal.lrnDisable;
    PI.fromRemoteSpan     = CtlManageVlan.rmtVlanId[0:0] == PI.vlanId;
        
    // L2 protocol packet decision
    if (!DsMemSrcPortVal.stpDisable ) {
        if (PI.dot1qType[1:1] ) {
            PI.isBpdu     = tmpMacDa[31:0] == CtlIntfBpduMac.sBpduMac && tmpMacDaHi == CtlIntfBpduMac.sBpduMacHi;
        } else {
            PI.isBpdu     = tmpMacDa[31:0] == CtlIntfBpduMac.cBpduMac && tmpMacDaHi == CtlIntfBpduMac.cBpduMacHi;
        }
    }

    if ((PI.srcPort == CtlCommon.cpuPortNo[0:0]) || DsMemSrcPortVal.stpDisable ) {
        PI.stpState       = STP_FWD;
    } else {
        PI.stpIdx         = {PI.srcPort, PI.stpId};
        tmpSubIdx         = PI.stpIdx << 1;
        DsMemStpStateVal  = DsMemStpState[ PI.stpIdx[10:4] ];
        PI.stpState       = DsMemStpStateVal.stpState[tmpSubIdx+1:tmpSubIdx];
    }
    CtlIntfMapLog.aftDiscard[0:0] = PI.aftDiscard;
    CtlIntfMapLog.vlanId[11:0] = PI.vlanId[11:0];
    CtlIntfMapLog.cos[2:0] = PI.cos[2:0];
    CtlIntfMapLog.dscp[5:0] = PI.dscp[5:0];
    CtlIntfMapLog.prior[5:0] = PI.prior[5:0];
    CtlIntfMapLog.isUcastIp[0:0] = PI.isUcastIp;
    CtlIntfMapLog.isMcastIp[0:0] = PI.isMcastIp;
    CtlIntfMapLog.isMcastMac[0:0] = PI.isMcastMac;
    CtlIntfMapLog.routingEn[0:0] = PI.routingEn;
    CtlIntfMapLog.cpuPktType[3:0] = PI.cpuPktType[3:0];
    CtlIntfMapLog.stpIdx[10:0] = PI.stpIdx[10:0];
    CtlIntfMapLog.isBpdu[0:0] = PI.isBpdu;
    CtlIntfMapLog.stpState[1:0] = PI.stpState[1:0];
    CtlIntfMapLog.tsnEn[0:0] = PI.tsnEn;
    CtlIntfMapLog.mcVlanDrop[0:0] = PI.mcVlanDrop;
}
    