/*
 * cmodel for Pishon
 * @file: Interface
 * @description: auto generage
 * @note: Copyright (C) 2021-03-29 12:40:57.420361
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
#include <mem/InterfaceOpr.h>
#include <mem/Interface.h>

void Interface(tPktInfo *PI){
	uint8_t tmpIsIp = 0;
	uint8_t tmpCvid = 0;
	uint8_t tmpDefaultPcp = 0;
	uint8_t tmpMacDscpFirst = 0;
	uint16_t tmpTsnDomainIdx = 0;
	uint8_t tmpRouterMacBmp = 0;
	uint8_t tmpIsRouterMac = 0;
	uint8_t tmpMacCosFirst = 0;
	uint8_t tmpUseMacVlan = 0;
	uint8_t tmpSubIdx = 0;
	uint8_t tmpCos = 0;
	uint16_t tmpMacDaHi = 0;
	uint8_t tmpPr = 0;
	uint8_t tmpMacVlanFirst = 0;
	uint8_t tmpCcos = 0;
	uint16_t tmpSvid = 0;
	uint32_t tmpIpDaW0 = 0;
	uint16_t tmpMacSaHi = 0;
	uint8_t tmpIsMcastIp = 0;
	uint8_t tmpToManageVlan = 0;
	uint8_t tmpIpPr = 0;
	uint8_t tmpIsIpMcastMac = 0;
	uint8_t tmpIsUcastIp = 0;
	uint8_t tmpTaggedPkt = 0;
	uint8_t tmpTos = 0;
	uint32_t tmpIpDaW3 = 0;
	uint32_t tmpMacDa = 0;
	uint16_t tmpCvid = 0;
	uint8_t tmpDscp = 0;

	tCtlRouterMac CtlRouterMacTmp = {0};
	tCtlRouterMac *CtlRouterMac = &CtlRouterMacTmp;
	readCtlRouterMac("CtlRouterMac", 0, CtlRouterMac, 0);
	tCtlIntfBpduMac CtlIntfBpduMacTmp = {0};
	tCtlIntfBpduMac *CtlIntfBpduMac = &CtlIntfBpduMacTmp;
	readCtlIntfBpduMac("CtlIntfBpduMac", 0, CtlIntfBpduMac, 0);
	tCtlIntfMapLog CtlIntfMapLogTmp = {0};
	tCtlIntfMapLog *CtlIntfMapLog = &CtlIntfMapLogTmp;
	readCtlIntfMapLog("CtlIntfMapLog", 0, CtlIntfMapLog, 0);
	tDsMemVlan DsMemVlanValTmp = {0};
	tDsMemVlan *DsMemVlanVal = &DsMemVlanValTmp;
	tCtlCosMapPrior CtlCosMapPriorTmp = {0};
	tCtlCosMapPrior *CtlCosMapPrior = &CtlCosMapPriorTmp;
	readCtlCosMapPrior("CtlCosMapPrior", 0, CtlCosMapPrior, 0);
	tCtlTsnFunc CtlTsnFuncTmp = {0};
	tCtlTsnFunc *CtlTsnFunc = &CtlTsnFuncTmp;
	readCtlTsnFunc("CtlTsnFunc", 0, CtlTsnFunc, 0);
	tDsMemSrcPort DsMemSrcPortValTmp = {0};
	tDsMemSrcPort *DsMemSrcPortVal = &DsMemSrcPortValTmp;
	tCtlCommon CtlCommonTmp = {0};
	tCtlCommon *CtlCommon = &CtlCommonTmp;
	readCtlCommon("CtlCommon", 0, CtlCommon, 0);
	tDsMemStpState DsMemStpStateValTmp = {0};
	tDsMemStpState *DsMemStpStateVal = &DsMemStpStateValTmp;
	tDsMemMacBasedVlan DsMemMacBasedVlanValTmp = {0};
	tDsMemMacBasedVlan *DsMemMacBasedVlanVal = &DsMemMacBasedVlanValTmp;
	tCtlIpPrecdncMapPrior CtlIpPrecdncMapPriorTmp = {0};
	tCtlIpPrecdncMapPrior *CtlIpPrecdncMapPrior = &CtlIpPrecdncMapPriorTmp;
	readCtlIpPrecdncMapPrior("CtlIpPrecdncMapPrior", 0, CtlIpPrecdncMapPrior, 0);
	tDsMemProtocolVlan DsMemProtocolVlanValTmp = {0};
	tDsMemProtocolVlan *DsMemProtocolVlanVal = &DsMemProtocolVlanValTmp;
	tCtlManageVlan CtlManageVlanTmp = {0};
	tCtlManageVlan *CtlManageVlan = &CtlManageVlanTmp;
	readCtlManageVlan("CtlManageVlan", 0, CtlManageVlan, 0);
	tDsMemTsnDomain DsMemTsnDomainValTmp = {0};
	tDsMemTsnDomain *DsMemTsnDomainVal = &DsMemTsnDomainValTmp;
	tCtlDscpMapPrior CtlDscpMapPriorTmp = {0};
	tCtlDscpMapPrior *CtlDscpMapPrior = &CtlDscpMapPriorTmp;
	readCtlDscpMapPrior("CtlDscpMapPrior", 0, CtlDscpMapPrior, 0);

    // port property
    rpcRdMem("DsMemSrcPort", PI->srcPort, DsMemSrcPortVal);
    PI->defaultVlanId = DsMemSrcPortVal->defaultVlanId;
    PI->l2AclLabel = DsMemSrcPortVal->l2AclLabel;
    PI->linkAggId = DsMemSrcPortVal->linkAggId;
    PI->defaultPcp = DsMemSrcPortVal->defaultPcp;
    PI->qosPolicy = DsMemSrcPortVal->qosPolicy;
    PI->aft = DsMemSrcPortVal->aft;
    PI->isLinkAggMbr = DsMemSrcPortVal->isLinkAggMbr;
    PI->ingressFilteringEn = DsMemSrcPortVal->ingressFilteringEn;
    PI->portPoliceEn = DsMemSrcPortVal->portPoliceEn;
    PI->lrnDisable = DsMemSrcPortVal->lrnDisable;
    PI->l2SrcMatchDiscard = DsMemSrcPortVal->l2SrcMatchDiscard;
    PI->bpduDrop = DsMemSrcPortVal->bpduDrop;
    PI->stpDisable = DsMemSrcPortVal->stpDisable;
    PI->forcePortBasedVlan = DsMemSrcPortVal->forcePortBasedVlan;
    PI->l2AclEn = DsMemSrcPortVal->l2AclEn;
    PI->l2AclHiPrio = DsMemSrcPortVal->l2AclHiPrio;
    PI->ipv4ForceMacKey = DsMemSrcPortVal->ipv4ForceMacKey;
    PI->ipv6ForceMacKey = DsMemSrcPortVal->ipv6ForceMacKey;
    PI->replaceDscp = DsMemSrcPortVal->replaceDscp;
    PI->replaceCos = DsMemSrcPortVal->replaceCos;
    PI->vlanPrioEn = DsMemSrcPortVal->vlanPrioEn;
    PI->macBasedVlanHiPrio = DsMemSrcPortVal->macBasedVlanHiPrio;
    PI->keepVlanTag = DsMemSrcPortVal->keepVlanTag;
    PI->ingressL2SpanEn = DsMemSrcPortVal->ingressL2SpanEn;
    tmpDefaultPcp    = DsMemSrcPortVal->defaultPcp;
    PI->lrnDisable    = PI->lrnDisable | DsMemSrcPortVal->lrnDisable;
    // Accept type
    tmpPr = findPrByType( PROTO_TYPE_ETH );
    tmpTaggedPkt  = GET_BITS(tmpPr->qualifier, 2, 4) != 0;
    tmpSvid = ((uint64_t) GET_BITS(glPktHdr[tmpPr->offset+14], 0, 3)<<8) + ( glPktHdr[tmpPr->offset+15]);
    if ( GET_BITS(tmpPr->qualifier, 2, 2)) {
        tmpCvid = ((uint64_t) GET_BITS(glPktHdr[tmpPr->offset+18], 0, 3)<<8) + ( glPktHdr[tmpPr->offset+19]);
        tmpCcos  = GET_BITS(glPktHdr[tmpPr->offset+18], 5, 7);
    } else if ( GET_BITS(tmpPr->qualifier, 4, 4)) {
        tmpCvid       = ((uint64_t) GET_BITS(glPktHdr[tmpPr->offset+14], 0, 3)<<8) + ( glPktHdr[tmpPr->offset+15]);
        tmpCcos       = GET_BITS(glPktHdr[tmpPr->offset+14], 5, 7);
    }
    if (DsMemSrcPortVal->aft == VLAN_AFT_TAGGED ) {
        PI->aftDiscard     = !tmpTaggedPkt;
    } else if (DsMemSrcPortVal->aft == VLAN_AFT_NO_TAG ) {
        PI->aftDiscard     = tmpTaggedPkt;
    } else if (DsMemSrcPortVal->aft == VLAN_AFT_NONE ) {
        PI->aftDiscard     = 1;
    }
    PI->removeVlanTag      = tmpTaggedPkt && !DsMemSrcPortVal->keepVlanTag;
    if (PI->aftDiscard ) {
        PI->discard        = PI->discard | 1;
    }
    if (PI->macBasedVlanValid )  
        rpcRdMem("DsMemMacBasedVlan", PI->macBasedVlanIdx, DsMemMacBasedVlanVal);
    if (PI->protocolVlanValid )  
        rpcRdMem("DsMemProtocolVlan", PI->protocolVlanIdx, DsMemProtocolVlanVal);
    // Assgin Vlan
    tmpMacVlanFirst = DsMemSrcPortVal->macBasedVlanHiPrio && PI->macBasedVlanValid;
    tmpUseMacVlan   = tmpMacVlanFirst && DsMemMacBasedVlanVal->replaceVlan;
    if (PI->bypassPp || PI->forbidEdit ) {
        PI->vlanId   = PI->vlanId;
    } else if (PI->macBasedVlanValid && (DsMemMacBasedVlanVal->replaceVlan || !tmpTaggedPkt) ) {
        PI->vlanId   = DsMemMacBasedVlanVal->vlanId;
    } else if (PI->protocolVlanValid && (DsMemProtocolVlanVal->replaceVlan || !tmpTaggedPkt) ) {
        PI->vlanId   = DsMemProtocolVlanVal->vlanId;
    } else if (tmpTaggedPkt && !DsMemSrcPortVal->forcePortBasedVlan ) {
        PI->vlanId   = GET_BITS(tmpPr->qualifier, 2, 3) != 0 ? tmpSvid : tmpCvid;
    } else {
        PI->vlanId   = DsMemSrcPortVal->defaultVlanId;
    }
    // Assign Cos
    rpcRdMem("DsMemVlan", PI->vlanId, DsMemVlanVal);
    tmpMacCosFirst = tmpMacVlanFirst && DsMemMacBasedVlanVal->replaceCos;
    if (PI->macBasedVlanValid && DsMemMacBasedVlanVal->replaceCos ) {
        tmpCos= DsMemMacBasedVlanVal->cos;
    } else if (PI->protocolVlanValid && DsMemProtocolVlanVal->replaceCos ) {
        tmpCos     = DsMemProtocolVlanVal->cos;
    } else if (DsMemSrcPortVal->vlanPrioEn ) {
        tmpCos     = DsMemVlanVal->cos;
    } else if (tmpTaggedPkt && !DsMemSrcPortVal->forcePortBasedVlan ) {
        tmpCos     = GET_BITS(tmpPr->qualifier, 2, 3) != 0 ? GET_BITS(glPktHdr[tmpPr->offset+14], 5, 7) : tmpCcos;
    } else {
        tmpCos     = tmpDefaultPcp;
    }
    PI->cos         = tmpCos;
    // Assign DSCP
    if (PI->l3Type == PROTO_TYPE_IPV4) {
        tmpIpPr = findPrByType( PROTO_TYPE_IPV4 );
        tmpTos = GET_BITS(glPktHdr[tmpIpPr->offset+1], 2, 7);
        tmpIpDaW0= GET_BITS(glPktHdr, tmpIpPr->offset+19, tmpIpPr->offset+16);
    } else if (PI->l3Type == PROTO_TYPE_IPV6) {
        tmpIpPr = findPrByType( PROTO_TYPE_IPV6 );
        tmpTos = ((uint64_t) GET_BITS(glPktHdr[tmpIpPr->offset], 0, 3)<<2) + ( GET_BITS(glPktHdr[tmpIpPr->offset+1], 6, 7));
        tmpIpDaW3 = GET_BITS(glPktHdr, tmpIsIp->offset+27, tmpIsIp->offset+24);
    }
    tmpMacDscpFirst = tmpMacVlanFirst && DsMemMacBasedVlanVal->replaceDscp;
    if (PI->macBasedVlanValid && DsMemMacBasedVlanVal->replaceDscp ) {
        tmpDscp= DsMemMacBasedVlanVal->dscp;
    } else if (PI->protocolVlanValid && DsMemProtocolVlanVal->replaceDscp ) {
        tmpDscp     = DsMemProtocolVlanVal->dscp;
    } else {
        tmpDscp     = tmpTos;
    }
	PI->dscp         = tmpDscp;
    // prior mapping
    tmpIsIp         = (PI->l3Type == PROTO_TYPE_IPV4) || (PI->l3Type == PROTO_TYPE_IPV6);
    if (PI->bypassPp && PI->forbidEdit ) {
        PI->prior  = PI->prior;
    } else if ((PI->qosPolicy == QOS_POLICY_DSCP) && tmpIsIp ) {
        PI->prior  = CtlDscpMapPrior->dscpPrior{tmpDscp};
    } else if ((PI->qosPolicy == QOS_POLICY_IPCOS) && tmpIsIp ) {
        PI->prior  = CtlIpPrecdncMapPrior->precPrior{ GET_BITS(tmpDscp, 3, 5)};
    } else if (PI->qosPolicy == QOS_POLICY_PORTCOS ) {
        PI->prior  = CtlCosMapPrior->cosPrior{ GET_BITS(tmpDefaultPcp, 0, 2)};
    } else if (PI->qosPolicy == QOS_POLICY_COS ) {
        PI->prior  = CtlCosMapPrior->cosPrior{tmpCos};
    }
    // VlanProperty
    tmpRouterMacBmp   = (DsMemVlanVal->vrrpGrpBmp << 1) + 1;
    tmpMacDaHi= GET_BITS(glPktHdr, tmpPr->offset+1, tmpPr->offset);
    tmpMacDa  = GET_BITS(glPktHdr, tmpPr->offset+5, tmpPr->offset+2);
    tmpMacSaHi= GET_BITS(glPktHdr, tmpPr->offset+7, tmpPr->offset+6);
    if ( GET_BITS(tmpRouterMacBmp, 0, 0) && (CtlRouterMac->routerMac0 == tmpMacDa) && 
        (CtlRouterMac->routerMacHi0 == tmpMacDaHi)) { 
        tmpIsRouterMac = 1;
    }
    if ( GET_BITS(tmpRouterMacBmp, 1, 1) && (CtlRouterMac->routerMac1 == tmpMacDa) && 
        (CtlRouterMac->routerMacHi1 == tmpMacDaHi)) { 
        tmpIsRouterMac = 1;
    }
    if ( GET_BITS(tmpRouterMacBmp, 2, 2) && (CtlRouterMac->routerMac2 == tmpMacDa) && 
        (CtlRouterMac->routerMacHi2 == tmpMacDaHi)) { 
        tmpIsRouterMac = 1;
    }
    if ( GET_BITS(tmpRouterMacBmp, 3, 3) && (CtlRouterMac->routerMac3 == tmpMacDa) && 
        (CtlRouterMac->routerMacHi3 == tmpMacDaHi)) { 
        tmpIsRouterMac = 1;
    }
    tmpIsUcastIp    = ( (PI->l3Type == PROTO_TYPE_IPV4) && (0xE != GET_BITS(tmpIpDaW0, 28, 31)) )
                       || ( (PI->l3Type == PROTO_TYPE_IPV6) && (0xFF != GET_BITS(tmpIpDaW3, 24, 31)) );
    tmpIsMcastIp    = ( (PI->l3Type == PROTO_TYPE_IPV4) && (0xE == GET_BITS(tmpIpDaW0, 28, 31)) )
                       || ( (PI->l3Type == PROTO_TYPE_IPV6) && (0xFF == GET_BITS(tmpIpDaW3, 24, 31)) );
    tmpIsIpMcastMac = ( (tmpMacDaHi == 0x0100) && ( GET_BITS(tmpMacDa, 24, 31) == 0x5e) && ( GET_BITS(tmpMacDa, 23, 23) == 0x0) )
                       || ( 0x3333 == tmpMacDaHi );
    PI->routingEn    = ( (tmpIsRouterMac && tmpIsUcastIp) || (tmpIsMcastIp && tmpIsIpMcastMac) )  
                          && DsMemVlanVal->routingEn && !PI->bypassPp;
    // discard frame if correspoding vlan processing MC only
    if (DsMemVlanVal->mcastVlanEn ) {
        PI->discard  = PI->discard | (! GET_BITS(tmpMacDaHi, 8, 8));
    }
	PI->mcVlanDrop   = DsMemVlanVal->mcastVlanEn && ! GET_BITS(tmpMacDaHi, 8, 8);
    PI->lrnDisable  |= GET_BITS(tmpMacSaHi, 8, 8);
    tmpTsnDomainIdx = ((uint64_t) GET_BITS(PI->vlanId, 0, 7)<<3) + ( GET_BITS(PI->prior, 3, 5));
    rpcRdMem("DsMemTsnDomain", tmpTsnDomainIdx, DsMemTsnDomainVal);
    PI->tsnEn              = CtlTsnFunc->enable && DsMemVlanVal->tsnEn && GET_BITS(DsMemTsnDomainVal->corePortBmp, PI->srcPort, PI->srcPort);
    PI->l3AclEn            = DsMemVlanVal->l3AclEn        ; 
    PI->l3AclLabel         = DsMemVlanVal->l3AclLabel;
    PI->l3SpanEn           = DsMemVlanVal->l3SpanEn       ; 
    PI->stpId              = DsMemVlanVal->stpId;
    PI->fid                = DsMemVlanVal->fid   ; 
    PI->replaceCos        |= DsMemVlanVal->replaceCos;
    PI->replaceDscp       |= DsMemVlanVal->replaceDscp;
    tmpToManageVlan       = (CtlManageVlan->vlanId0 == PI->vlanId) || (CtlManageVlan->vlanId1 == PI->vlanId);
    if (DsMemVlanVal->arpInspection && (PI->l3Type == PROTO_TYPE_ARP) && !PI->bypassPp ) {
        PI->copyToCpu      = 1;
        PI->discard        = PI->discard | 1;
        PI->cpuPktType     = CPU_PKT_ARP;
    } else if ((tmpToManageVlan || DsMemVlanVal->routingEn) && GET_BITS(tmpPr->qualifier, 0, 0) && (PI->l3Type == PROTO_TYPE_ARP) && !PI->bypassPp ) {
        PI->copyToCpu      = 1;
        PI->cpuPktType     = CPU_PKT_ARP;
        PI->discard        = PI->discard | ( !DsMemVlanVal->hwBcastArp );
    } 
    if ((PI->l3Type == PROTO_TYPE_MSRP) && !PI->bypassPp && DsMemVlanVal->msrpToCpu ) {
        PI->copyToCpu      = 1;
        PI->cpuPktType     = CPU_PKT_MSRP;
        PI->discard        = PI->discard | ( !DsMemVlanVal->hwFwdMsrp );
    }
    if ((PI->l3Type == PROTO_TYPE_MMRP) && !PI->bypassPp && DsMemVlanVal->mmrpToCpu ) {
        PI->copyToCpu      = 1;
        PI->cpuPktType     = CPU_PKT_MMRP;
        PI->discard        = PI->discard | ( !DsMemVlanVal->hwFwdMmrp );
    }
    if ((PI->l3Type == PROTO_TYPE_MVRP) && !PI->bypassPp && DsMemVlanVal->mvrpToCpu ) {
        PI->copyToCpu      = 1;
        PI->cpuPktType     = CPU_PKT_MVRP;
        PI->discard        = PI->discard | ( !DsMemVlanVal->hwFwdMvrp );
    }
    if ((PI->l4Type == PROTO_TYPE_IGMP) && DsMemVlanVal->igmpSnoopEn && !PI->bypassPp ) {
        PI->copyToCpu      = 1;
        PI->cpuPktType     = CPU_PKT_IGMP;
        PI->discard        = PI->discard | ( !DsMemVlanVal->hwBcastIgmp );
    }
    if ((PI->l4Type == PROTO_TYPE_MLD) && DsMemVlanVal->mldSnoopEn && !PI->bypassPp ) {
        PI->copyToCpu      = 1;
        PI->cpuPktType     = CPU_PKT_MLD;
        PI->discard        = PI->discard | ( !DsMemVlanVal->hwBcastMld );
    }
    if ((PI->l4Type == PROTO_TYPE_ND) && DsMemVlanVal->ndToCpu && !PI->bypassPp ) {
        PI->copyToCpu      = 1;
        PI->cpuPktType     = CPU_PKT_ND;
        PI->discard        = PI->discard | ( !DsMemVlanVal->hwFwdNd );
    }
    if ((PI->isSnmp) && DsMemVlanVal->snmpToCpu && !PI->bypassPp ) {
        PI->copyToCpu      = 1;
        PI->cpuPktType     = CPU_PKT_SNMP;
        PI->discard        = PI->discard | ( !DsMemVlanVal->hwFwdSnmp );
    }
    PI->lrnDisable        |= DsMemVlanVal->lrnDisable;
    PI->fromRemoteSpan     = CtlManageVlan->rmtVlanId == PI->vlanId;
    // L2 protocol packet decision
    if (!DsMemSrcPortVal->stpDisable ) {
        if ( GET_BITS(PI->dot1qType, 1, 1) ) {
            PI->isBpdu     = tmpMacDa == CtlIntfBpduMac->sBpduMac && tmpMacDaHi == CtlIntfBpduMac->sBpduMacHi;
        } else {
            PI->isBpdu     = tmpMacDa == CtlIntfBpduMac->cBpduMac && tmpMacDaHi == CtlIntfBpduMac->cBpduMacHi;
        }
    }
    if ((PI->srcPort == CtlCommon->cpuPortNo) || DsMemSrcPortVal->stpDisable ) {
        PI->stpState       = STP_FWD;
    } else {
        PI->stpIdx         = ((uint64_t)PI->srcPort<<8) + ( PI->stpId);
        tmpSubIdx         = PI->stpIdx << 1;
        rpcRdMem("DsMemStpState", GET_BITS(PI->stpIdx, 4, 10), DsMemStpStateVal);
        PI->stpState       = GET_BITS(DsMemStpStateVal->stpState, tmpSubIdx, tmpSubIdx+1);
    }
    CtlIntfMapLog->aftDiscard = PI->aftDiscard;
    CtlIntfMapLog->vlanId = PI->vlanId;
    CtlIntfMapLog->cos = PI->cos;
    CtlIntfMapLog->dscp = PI->dscp;
    CtlIntfMapLog->prior = PI->prior;
    CtlIntfMapLog->isUcastIp = PI->isUcastIp;
    CtlIntfMapLog->isMcastIp = PI->isMcastIp;
    CtlIntfMapLog->isMcastMac = PI->isMcastMac;
    CtlIntfMapLog->routingEn = PI->routingEn;
    CtlIntfMapLog->cpuPktType = PI->cpuPktType;
    CtlIntfMapLog->stpIdx = PI->stpIdx;
    CtlIntfMapLog->isBpdu = PI->isBpdu;
    CtlIntfMapLog->stpState = PI->stpState;
    CtlIntfMapLog->tsnEn = PI->tsnEn;
    CtlIntfMapLog->mcVlanDrop = PI->mcVlanDrop;
}
