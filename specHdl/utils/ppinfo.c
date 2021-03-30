/**
	* printf packet info
	*/
#include <ppinfo.h>
#include <stdio.h>
void outPutPI( FILE *fp, char *name, tPktInfo *pi ) {
	fprintf(fp, "  %s  :  PI.vlanId                 = %x\n", name, pi->vlanId);
	fprintf(fp, "  %s  :  PI.phyPort                 = %x\n", name, pi->phyPort);
	fprintf(fp, "  %s  :  PI.fwdBitmap                 = %x\n", name, pi->fwdBitmap);
	fprintf(fp, "  %s  :  PI.ecmpMbrs                 = %x\n", name, pi->ecmpMbrs);
	fprintf(fp, "  %s  :  PI.ecmpHash                 = %x\n", name, pi->ecmpHash);
	fprintf(fp, "  %s  :  PI.nexthopIdx                 = %x\n", name, pi->nexthopIdx);
	fprintf(fp, "  %s  :  PI.destMap                 = %x\n", name, pi->destMap);
	fprintf(fp, "  %s  :  PI.tsnStreamId                 = %x\n", name, pi->tsnStreamId);
	fprintf(fp, "  %s  :  PI.linkAggHash                 = %x\n", name, pi->linkAggHash);
	fprintf(fp, "  %s  :  PI.linkAggId                 = %x\n", name, pi->linkAggId);
	fprintf(fp, "  %s  :  PI.opCode                 = %x\n", name, pi->opCode);
	fprintf(fp, "  %s  :  PI.excpType                 = %x\n", name, pi->excpType);
	fprintf(fp, "  %s  :  PI.ptpType                 = %x\n", name, pi->ptpType);
	fprintf(fp, "  %s  :  PI.fwdBitmapW1                 = %x\n", name, pi->fwdBitmapW1);
	fprintf(fp, "  %s  :  PI.cpuPktType                 = %x\n", name, pi->cpuPktType);
	fprintf(fp, "  %s  :  PI.flowStatsPtr                 = %x\n", name, pi->flowStatsPtr);
	fprintf(fp, "  %s  :  PI.pktLength                 = %x\n", name, pi->pktLength);
	fprintf(fp, "  %s  :  PI.tsnPrior                 = %x\n", name, pi->tsnPrior);
	fprintf(fp, "  %s  :  PI.rtagSeq                 = %x\n", name, pi->rtagSeq);
	fprintf(fp, "  %s  :  PI.prior                 = %x\n", name, pi->prior);
	fprintf(fp, "  %s  :  PI.tsnGateId                 = %x\n", name, pi->tsnGateId);
	fprintf(fp, "  %s  :  PI.tsnCycle                 = %x\n", name, pi->tsnCycle);
	fprintf(fp, "  %s  :  PI.stpId                 = %x\n", name, pi->stpId);
	fprintf(fp, "  %s  :  PI.l3Offset                 = %x\n", name, pi->l3Offset);
	fprintf(fp, "  %s  :  PI.l4Offset                 = %x\n", name, pi->l4Offset);
	fprintf(fp, "  %s  :  PI.l3Type                 = %x\n", name, pi->l3Type);
	fprintf(fp, "  %s  :  PI.l4Type                 = %x\n", name, pi->l4Type);
	fprintf(fp, "  %s  :  PI.tsnCycleSel                 = %x\n", name, pi->tsnCycleSel);
	fprintf(fp, "  %s  :  PI.ethTypeLen                 = %x\n", name, pi->ethTypeLen);
	fprintf(fp, "  %s  :  PI.tsOffset                 = %x\n", name, pi->tsOffset);
	fprintf(fp, "  %s  :  PI.hdrLength                 = %x\n", name, pi->hdrLength);
	fprintf(fp, "  %s  :  PI.l2Offset                 = %x\n", name, pi->l2Offset);
	fprintf(fp, "  %s  :  PI.pktLenLog                 = %x\n", name, pi->pktLenLog);
	fprintf(fp, "  %s  :  PI.newColor                 = %x\n", name, pi->newColor);
	fprintf(fp, "  %s  :  PI.portPoPtr                 = %x\n", name, pi->portPoPtr);
	fprintf(fp, "  %s  :  PI.logicalPort                 = %x\n", name, pi->logicalPort);
	fprintf(fp, "  %s  :  PI.flowPoPtr                 = %x\n", name, pi->flowPoPtr);
	fprintf(fp, "  %s  :  PI.flowPolicePtr                 = %x\n", name, pi->flowPolicePtr);
	fprintf(fp, "  %s  :  PI.tsnHandle                 = %x\n", name, pi->tsnHandle);
	fprintf(fp, "  %s  :  PI.dropPktCnt                 = %x\n", name, pi->dropPktCnt);
	fprintf(fp, "  %s  :  PI.defaultVlanId                 = %x\n", name, pi->defaultVlanId);
	fprintf(fp, "  %s  :  PI.l2AclLabel                 = %x\n", name, pi->l2AclLabel);
	fprintf(fp, "  %s  :  PI.defaultPcp                 = %x\n", name, pi->defaultPcp);
	fprintf(fp, "  %s  :  PI.qosPolicy                 = %x\n", name, pi->qosPolicy);
	fprintf(fp, "  %s  :  PI.aft                 = %x\n", name, pi->aft);
	fprintf(fp, "  %s  :  PI.macDa                 = %x\n", name, pi->macDa);
	fprintf(fp, "  %s  :  PI.macDaHi                 = %x\n", name, pi->macDaHi);
	fprintf(fp, "  %s  :  PI.cos                 = %x\n", name, pi->cos);
	fprintf(fp, "  %s  :  PI.tos                 = %x\n", name, pi->tos);
	fprintf(fp, "  %s  :  PI.dscp                 = %x\n", name, pi->dscp);
	fprintf(fp, "  %s  :  PI.ipDaW0                 = %x\n", name, pi->ipDaW0);
	fprintf(fp, "  %s  :  PI.ipDaW3                 = %x\n", name, pi->ipDaW3);
	fprintf(fp, "  %s  :  PI.macSaHi                 = %x\n", name, pi->macSaHi);
	fprintf(fp, "  %s  :  PI.l3AclLabel                 = %x\n", name, pi->l3AclLabel);
	fprintf(fp, "  %s  :  PI.fid                 = %x\n", name, pi->fid);
	fprintf(fp, "  %s  :  PI.dot1qTypeEn                 = %x\n", name, pi->dot1qTypeEn);
	fprintf(fp, "  %s  :  PI.stpIdx                 = %x\n", name, pi->stpIdx);
	fprintf(fp, "  %s  :  PI.stpState                 = %x\n", name, pi->stpState);
	fprintf(fp, "  %s  :  PI.isIpv6                 = %x\n", name, pi->isIpv6);
	fprintf(fp, "  %s  :  PI.ipDaW2                 = %x\n", name, pi->ipDaW2);
	fprintf(fp, "  %s  :  PI.ipDaW1                 = %x\n", name, pi->ipDaW1);
	fprintf(fp, "  %s  :  PI.tableId0                 = %x\n", name, pi->tableId0);
	fprintf(fp, "  %s  :  PI.tableId1                 = %x\n", name, pi->tableId1);
	fprintf(fp, "  %s  :  PI.flowLabel                 = %x\n", name, pi->flowLabel);
	fprintf(fp, "  %s  :  PI.reserve0                 = %x\n", name, pi->reserve0);
	fprintf(fp, "  %s  :  PI.ttl                 = %x\n", name, pi->ttl);
	fprintf(fp, "  %s  :  PI.l3NextHdr                 = %x\n", name, pi->l3NextHdr);
	fprintf(fp, "  %s  :  PI.lpmIndex                 = %x\n", name, pi->lpmIndex);
	fprintf(fp, "  %s  :  PI.ipOption                 = %x\n", name, pi->ipOption);
	fprintf(fp, "  %s  :  PI.fragmented                 = %x\n", name, pi->fragmented);
	fprintf(fp, "  %s  :  PI.reserve                 = %x\n", name, pi->reserve);
	fprintf(fp, "  %s  :  PI.ipSaW0                 = %x\n", name, pi->ipSaW0);
	fprintf(fp, "  %s  :  PI.reserve2                 = %x\n", name, pi->reserve2);
	fprintf(fp, "  %s  :  PI.tcpFlag                 = %x\n", name, pi->tcpFlag);
	fprintf(fp, "  %s  :  PI.userData1                 = %x\n", name, pi->userData1);
	fprintf(fp, "  %s  :  PI.userData0                 = %x\n", name, pi->userData0);
	fprintf(fp, "  %s  :  PI.l4SrcPort                 = %x\n", name, pi->l4SrcPort);
	fprintf(fp, "  %s  :  PI.l4DestPort                 = %x\n", name, pi->l4DestPort);
	fprintf(fp, "  %s  :  PI.natIdx                 = %x\n", name, pi->natIdx);
	fprintf(fp, "  %s  :  PI.ipRouteIdx                 = %x\n", name, pi->ipRouteIdx);
	fprintf(fp, "  %s  :  PI.aclLabel                 = %x\n", name, pi->aclLabel);
	fprintf(fp, "  %s  :  PI.tableId3                 = %x\n", name, pi->tableId3);
	fprintf(fp, "  %s  :  PI.ipSaW3                 = %x\n", name, pi->ipSaW3);
	fprintf(fp, "  %s  :  PI.ipSaW2                 = %x\n", name, pi->ipSaW2);
	fprintf(fp, "  %s  :  PI.tableId2                 = %x\n", name, pi->tableId2);
	fprintf(fp, "  %s  :  PI.routingEn                 = %x\n", name, pi->routingEn);
	fprintf(fp, "  %s  :  PI.ipSaW1                 = %x\n", name, pi->ipSaW1);
	fprintf(fp, "  %s  :  PI.aclIndex                 = %x\n", name, pi->aclIndex);
	fprintf(fp, "  %s  :  PI.reserve4                 = %x\n", name, pi->reserve4);
	fprintf(fp, "  %s  :  PI.ipv4Flags                 = %x\n", name, pi->ipv4Flags);
	fprintf(fp, "  %s  :  PI.ipOptions                 = %x\n", name, pi->ipOptions);
	fprintf(fp, "  %s  :  PI.reserve3                 = %x\n", name, pi->reserve3);
	fprintf(fp, "  %s  :  PI.reserve1                 = %x\n", name, pi->reserve1);
	fprintf(fp, "  %s  :  PI.macSa                 = %x\n", name, pi->macSa);
	fprintf(fp, "  %s  :  PI.l2HdrProtocol                 = %x\n", name, pi->l2HdrProtocol);
	fprintf(fp, "  %s  :  PI.macDaIdx                 = %x\n", name, pi->macDaIdx);
	fprintf(fp, "  %s  :  PI.ingressTs                 = %lx\n", name, pi->ingressTs);
	fprintf(fp, "  %s  :  PI.hdrBufPtr                 = %x\n", name, pi->hdrBufPtr);
	fprintf(fp, "  %s  :  PI.tailBufPtr                 = %x\n", name, pi->tailBufPtr);
	fprintf(fp, "  %s  :  PI.destPort                 = %x\n", name, pi->destPort);
	fprintf(fp, "  %s  :  PI.cpuPrior                 = %x\n", name, pi->cpuPrior);
	fprintf(fp, "  %s  :  PI.extendIdx                 = %x\n", name, pi->extendIdx);
	fprintf(fp, "  %s  :  PI.tsOp                 = %x\n", name, pi->tsOp);
	fprintf(fp, "  %s  :  PI.parserOffset                 = %x\n", name, pi->parserOffset);
	fprintf(fp, "  %s  :  PI.tpid                 = %x\n", name, pi->tpid);
	fprintf(fp, "  %s  :  PI.lenAdjust                 = %x\n", name, pi->lenAdjust);
	fprintf(fp, "  %s  :  PI.udpChksum                 = %x\n", name, pi->udpChksum);
	fprintf(fp, "  %s  :  PI.cfOffset                 = %x\n", name, pi->cfOffset);
	fprintf(fp, "  %s  :  PI.cf                 = %lx\n", name, pi->cf);
	fprintf(fp, "  %s  :  PI.pktType                 = %x\n", name, pi->pktType);
	fprintf(fp, "  %s  :  PI.subType                 = %x\n", name, pi->subType);
	fprintf(fp, "  %s  :  PI.pldOffset                 = %x\n", name, pi->pldOffset);
	fprintf(fp, "  %s  :  PI.version                 = %x\n", name, pi->version);
	fprintf(fp, "  %s  :  PI.latestPtpCf                 = %lx\n", name, pi->latestPtpCf);
	fprintf(fp, "  %s  :  PI.latestPtpChksum                 = %x\n", name, pi->latestPtpChksum);
	fprintf(fp, "  %s  :  PI.tsOpType                 = %x\n", name, pi->tsOpType);
	fprintf(fp, "  %s  :  PI.updatePtpChksum                 = %x\n", name, pi->updatePtpChksum);
	fprintf(fp, "  %s  :  PI.ts                 = %x\n", name, pi->ts);
	fprintf(fp, "  %s  :  PI.oamIdx                 = %x\n", name, pi->oamIdx);
	fprintf(fp, "  %s  :  PI.stagVlanId                 = %x\n", name, pi->stagVlanId);
	fprintf(fp, "  %s  :  PI.stagCos                 = %x\n", name, pi->stagCos);
	fprintf(fp, "  %s  :  PI.ctagVlanId                 = %x\n", name, pi->ctagVlanId);
	fprintf(fp, "  %s  :  PI.ctagCos                 = %x\n", name, pi->ctagCos);
	fprintf(fp, "  %s  :  PI.l2Type                 = %x\n", name, pi->l2Type);
	fprintf(fp, "  %s  :  PI.randomSeed                 = %x\n", name, pi->randomSeed);
	fprintf(fp, "  %s  :  PI.dosDropBmp                 = %x\n", name, pi->dosDropBmp);
	fprintf(fp, "  %s  :  PI.jumboNum                 = %x\n", name, pi->jumboNum);
	fprintf(fp, "  %s  :  PI.gapValue                 = %x\n", name, pi->gapValue);
	fprintf(fp, "  %s  :  PI.isTsn                 = %x\n", name, pi->isTsn);
	fprintf(fp, "  %s  :  PI.srcPortIdx                 = %x\n", name, pi->srcPortIdx);
	fprintf(fp, "  %s  :  PI.srcMap                 = %x\n", name, pi->srcMap);
	fprintf(fp, "  %s  :  PI.lrnType                 = %x\n", name, pi->lrnType);
	fprintf(fp, "  %s  :  PI.learnIdx                 = %x\n", name, pi->learnIdx);
	fprintf(fp, "  %s  :  PI.cpuFifoFullNum                 = %x\n", name, pi->cpuFifoFullNum);
	fprintf(fp, "  %s  :  PI.hwFifoFullNum                 = %x\n", name, pi->hwFifoFullNum);
	fprintf(fp, "  %s  :  PI.ipSaLsw                 = %x\n", name, pi->ipSaLsw);
	fprintf(fp, "  %s  :  PI.tableId                 = %x\n", name, pi->tableId);
	fprintf(fp, "  %s  :  PI.rsv0                 = %x\n", name, pi->rsv0);
	fprintf(fp, "  %s  :  PI.ipSubnetVlanIndex                 = %x\n", name, pi->ipSubnetVlanIndex);
	fprintf(fp, "  %s  :  PI.macBasedVlanIdx                 = %x\n", name, pi->macBasedVlanIdx);
	fprintf(fp, "  %s  :  PI.protocolVlanIdx                 = %x\n", name, pi->protocolVlanIdx);
	fprintf(fp, "  %s  :  PI.vlanLkpRslt                 = %x\n", name, pi->vlanLkpRslt);
	fprintf(fp, "  %s  :  PI.ingressFilteringEn                 = %x\n", name, pi->ingressFilteringEn);
	fprintf(fp, "  %s  :  PI.discard                 = %x\n", name, pi->discard);
	fprintf(fp, "  %s  :  PI.vlanDiscard                 = %x\n", name, pi->vlanDiscard);
	fprintf(fp, "  %s  :  PI.egrPortFilted                 = %x\n", name, pi->egrPortFilted);
	fprintf(fp, "  %s  :  PI.egrVlanFilted                 = %x\n", name, pi->egrVlanFilted);
	fprintf(fp, "  %s  :  PI.ecmp                 = %x\n", name, pi->ecmp);
	fprintf(fp, "  %s  :  PI.isLinkAggMbr                 = %x\n", name, pi->isLinkAggMbr);
	fprintf(fp, "  %s  :  PI.forceDest                 = %x\n", name, pi->forceDest);
	fprintf(fp, "  %s  :  PI.lagFilted                 = %x\n", name, pi->lagFilted);
	fprintf(fp, "  %s  :  PI.fromRemoteSpan                 = %x\n", name, pi->fromRemoteSpan);
	fprintf(fp, "  %s  :  PI.destLostInCfg                 = %x\n", name, pi->destLostInCfg);
	fprintf(fp, "  %s  :  PI.isBcastMac                 = %x\n", name, pi->isBcastMac);
	fprintf(fp, "  %s  :  PI.isMcastMac                 = %x\n", name, pi->isMcastMac);
	fprintf(fp, "  %s  :  PI.mcastFlood                 = %x\n", name, pi->mcastFlood);
	fprintf(fp, "  %s  :  PI.ucastFlood                 = %x\n", name, pi->ucastFlood);
	fprintf(fp, "  %s  :  PI.exception                 = %x\n", name, pi->exception);
	fprintf(fp, "  %s  :  PI.copyToCpu                 = %x\n", name, pi->copyToCpu);
	fprintf(fp, "  %s  :  PI.criticalPacket                 = %x\n", name, pi->criticalPacket);
	fprintf(fp, "  %s  :  PI.firstDecideToCpu                 = %x\n", name, pi->firstDecideToCpu);
	fprintf(fp, "  %s  :  PI.ptpValid                 = %x\n", name, pi->ptpValid);
	fprintf(fp, "  %s  :  PI.isPtp                 = %x\n", name, pi->isPtp);
	fprintf(fp, "  %s  :  PI.ptpEn                 = %x\n", name, pi->ptpEn);
	fprintf(fp, "  %s  :  PI.redirPtp                 = %x\n", name, pi->redirPtp);
	fprintf(fp, "  %s  :  PI.ptp2Cpu                 = %x\n", name, pi->ptp2Cpu);
	fprintf(fp, "  %s  :  PI.ingressL2SpanEn                 = %x\n", name, pi->ingressL2SpanEn);
	fprintf(fp, "  %s  :  PI.l3SpanEn                 = %x\n", name, pi->l3SpanEn);
	fprintf(fp, "  %s  :  PI.aclQosLogEn                 = %x\n", name, pi->aclQosLogEn);
	fprintf(fp, "  %s  :  PI.igrFlowSpan                 = %x\n", name, pi->igrFlowSpan);
	fprintf(fp, "  %s  :  PI.flowStatsValid                 = %x\n", name, pi->flowStatsValid);
	fprintf(fp, "  %s  :  PI.addRtag                 = %x\n", name, pi->addRtag);
	fprintf(fp, "  %s  :  PI.forbidEdit                 = %x\n", name, pi->forbidEdit);
	fprintf(fp, "  %s  :  PI.rtagValid                 = %x\n", name, pi->rtagValid);
	fprintf(fp, "  %s  :  PI.removeVlanTag                 = %x\n", name, pi->removeVlanTag);
	fprintf(fp, "  %s  :  PI.replaceCos                 = %x\n", name, pi->replaceCos);
	fprintf(fp, "  %s  :  PI.replaceDscp                 = %x\n", name, pi->replaceDscp);
	fprintf(fp, "  %s  :  PI.hasInnerHdr                 = %x\n", name, pi->hasInnerHdr);
	fprintf(fp, "  %s  :  PI.stagValid                 = %x\n", name, pi->stagValid);
	fprintf(fp, "  %s  :  PI.ctagValid                 = %x\n", name, pi->ctagValid);
	fprintf(fp, "  %s  :  PI.byPassPp                 = %x\n", name, pi->byPassPp);
	fprintf(fp, "  %s  :  PI.learningDisable                 = %x\n", name, pi->learningDisable);
	fprintf(fp, "  %s  :  PI.portPoEn                 = %x\n", name, pi->portPoEn);
	fprintf(fp, "  %s  :  PI.portPoliceEn                 = %x\n", name, pi->portPoliceEn);
	fprintf(fp, "  %s  :  PI.flowPoliceValid                 = %x\n", name, pi->flowPoliceValid);
	fprintf(fp, "  %s  :  PI.flowPoEn                 = %x\n", name, pi->flowPoEn);
	fprintf(fp, "  %s  :  PI.chkSDUfailed                 = %x\n", name, pi->chkSDUfailed);
	fprintf(fp, "  %s  :  PI.policeDrop                 = %x\n", name, pi->policeDrop);
	fprintf(fp, "  %s  :  PI.l2SrcMatchDiscard                 = %x\n", name, pi->l2SrcMatchDiscard);
	fprintf(fp, "  %s  :  PI.bpduDrop                 = %x\n", name, pi->bpduDrop);
	fprintf(fp, "  %s  :  PI.stpDisable                 = %x\n", name, pi->stpDisable);
	fprintf(fp, "  %s  :  PI.forcePortBasedVlan                 = %x\n", name, pi->forcePortBasedVlan);
	fprintf(fp, "  %s  :  PI.l2AclEn                 = %x\n", name, pi->l2AclEn);
	fprintf(fp, "  %s  :  PI.l2AclHiPrio                 = %x\n", name, pi->l2AclHiPrio);
	fprintf(fp, "  %s  :  PI.ipv4ForceMacKey                 = %x\n", name, pi->ipv4ForceMacKey);
	fprintf(fp, "  %s  :  PI.ipv6ForceMacKey                 = %x\n", name, pi->ipv6ForceMacKey);
	fprintf(fp, "  %s  :  PI.vlanPrioEn                 = %x\n", name, pi->vlanPrioEn);
	fprintf(fp, "  %s  :  PI.macBasedVlanHiPrio                 = %x\n", name, pi->macBasedVlanHiPrio);
	fprintf(fp, "  %s  :  PI.keepVlanTag                 = %x\n", name, pi->keepVlanTag);
	fprintf(fp, "  %s  :  PI.aftDiscard                 = %x\n", name, pi->aftDiscard);
	fprintf(fp, "  %s  :  PI.ipSubnetVlanValid                 = %x\n", name, pi->ipSubnetVlanValid);
	fprintf(fp, "  %s  :  PI.macBasedVlanValid                 = %x\n", name, pi->macBasedVlanValid);
	fprintf(fp, "  %s  :  PI.protocolVlanValid                 = %x\n", name, pi->protocolVlanValid);
	fprintf(fp, "  %s  :  PI.isUcastIp                 = %x\n", name, pi->isUcastIp);
	fprintf(fp, "  %s  :  PI.isMcastIp                 = %x\n", name, pi->isMcastIp);
	fprintf(fp, "  %s  :  PI.mcVlanDrop                 = %x\n", name, pi->mcVlanDrop);
	fprintf(fp, "  %s  :  PI.tsnEn                 = %x\n", name, pi->tsnEn);
	fprintf(fp, "  %s  :  PI.l3AclEn                 = %x\n", name, pi->l3AclEn);
	fprintf(fp, "  %s  :  PI.isSnmp                 = %x\n", name, pi->isSnmp);
	fprintf(fp, "  %s  :  PI.isBpdu                 = %x\n", name, pi->isBpdu);
	fprintf(fp, "  %s  :  PI.hostRouteLeftHit                 = %x\n", name, pi->hostRouteLeftHit);
	fprintf(fp, "  %s  :  PI.hostRouteRightHit                 = %x\n", name, pi->hostRouteRightHit);
	fprintf(fp, "  %s  :  PI.routeHitTcam                 = %x\n", name, pi->routeHitTcam);
	fprintf(fp, "  %s  :  PI.routeHitNatTcam                 = %x\n", name, pi->routeHitNatTcam);
	fprintf(fp, "  %s  :  PI.ipRouteLookup                 = %x\n", name, pi->ipRouteLookup);
	fprintf(fp, "  %s  :  PI.ipv6AclLookup                 = %x\n", name, pi->ipv6AclLookup);
	fprintf(fp, "  %s  :  PI.ipv4AclLookup                 = %x\n", name, pi->ipv4AclLookup);
	fprintf(fp, "  %s  :  PI.aclQosResultValid                 = %x\n", name, pi->aclQosResultValid);
	fprintf(fp, "  %s  :  PI.macDaLeftValid                 = %x\n", name, pi->macDaLeftValid);
	fprintf(fp, "  %s  :  PI.macDaRightValid                 = %x\n", name, pi->macDaRightValid);
	fprintf(fp, "  %s  :  PI.aclResultValid                 = %x\n", name, pi->aclResultValid);
	fprintf(fp, "  %s  :  PI.macAclLookup                 = %x\n", name, pi->macAclLookup);
	fprintf(fp, "  %s  :  PI.extendFlag                 = %x\n", name, pi->extendFlag);
	fprintf(fp, "  %s  :  PI.egrExcp                 = %x\n", name, pi->egrExcp);
	fprintf(fp, "  %s  :  PI.addCpuHdr                 = %x\n", name, pi->addCpuHdr);
	fprintf(fp, "  %s  :  PI.l2IngSpanPkt                 = %x\n", name, pi->l2IngSpanPkt);
	fprintf(fp, "  %s  :  PI.l2EgrSpanPkt                 = %x\n", name, pi->l2EgrSpanPkt);
	fprintf(fp, "  %s  :  PI.validRemoteSpan                 = %x\n", name, pi->validRemoteSpan);
	fprintf(fp, "  %s  :  PI.egrStpChkFail                 = %x\n", name, pi->egrStpChkFail);
	fprintf(fp, "  %s  :  PI.validFromInnerHdr                 = %x\n", name, pi->validFromInnerHdr);
	fprintf(fp, "  %s  :  PI.validSVlan                 = %x\n", name, pi->validSVlan);
	fprintf(fp, "  %s  :  PI.validCVlan                 = %x\n", name, pi->validCVlan);
	fprintf(fp, "  %s  :  PI.validRtag                 = %x\n", name, pi->validRtag);
	fprintf(fp, "  %s  :  PI.addVlanTag                 = %x\n", name, pi->addVlanTag);
	fprintf(fp, "  %s  :  PI.ptpPortTypeChkFail                 = %x\n", name, pi->ptpPortTypeChkFail);
	fprintf(fp, "  %s  :  PI.truncateCpuPkt                 = %x\n", name, pi->truncateCpuPkt);
	fprintf(fp, "  %s  :  PI.removeInnerHdr                 = %x\n", name, pi->removeInnerHdr);
	fprintf(fp, "  %s  :  PI.updateMacSa                 = %x\n", name, pi->updateMacSa);
	fprintf(fp, "  %s  :  PI.updateMacDa                 = %x\n", name, pi->updateMacDa);
	fprintf(fp, "  %s  :  PI.tsOpEn                 = %x\n", name, pi->tsOpEn);
	fprintf(fp, "  %s  :  PI.updPtpChksum                 = %x\n", name, pi->updPtpChksum);
	fprintf(fp, "  %s  :  PI.updPtpCf                 = %x\n", name, pi->updPtpCf);
	fprintf(fp, "  %s  :  PI.updPtpTs                 = %x\n", name, pi->updPtpTs);
	fprintf(fp, "  %s  :  PI.intrPtpTs                 = %x\n", name, pi->intrPtpTs);
	fprintf(fp, "  %s  :  PI.validInnerVlan                 = %x\n", name, pi->validInnerVlan);
	fprintf(fp, "  %s  :  PI.validOuterVlan                 = %x\n", name, pi->validOuterVlan);
	fprintf(fp, "  %s  :  PI.egrDiscard                 = %x\n", name, pi->egrDiscard);
	fprintf(fp, "  %s  :  PI.routedPkt                 = %x\n", name, pi->routedPkt);
	fprintf(fp, "  %s  :  PI.removeCpuHdr                 = %x\n", name, pi->removeCpuHdr);
	fprintf(fp, "  %s  :  PI.remoteSpan                 = %x\n", name, pi->remoteSpan);
	fprintf(fp, "  %s  :  PI.xconErr                 = %x\n", name, pi->xconErr);
	fprintf(fp, "  %s  :  PI.cfmMdl                 = %x\n", name, pi->cfmMdl);
	fprintf(fp, "  %s  :  PI.oamEgrIdxValid                 = %x\n", name, pi->oamEgrIdxValid);
	fprintf(fp, "  %s  :  PI.l2HdrError                 = %x\n", name, pi->l2HdrError);
	fprintf(fp, "  %s  :  PI.l3HdrError                 = %x\n", name, pi->l3HdrError);
	fprintf(fp, "  %s  :  PI.otherHeader                 = %x\n", name, pi->otherHeader);
	fprintf(fp, "  %s  :  PI.l4HdrError                 = %x\n", name, pi->l4HdrError);
	fprintf(fp, "  %s  :  PI.isAvFrame                 = %x\n", name, pi->isAvFrame);
	fprintf(fp, "  %s  :  PI.rtpPkt                 = %x\n", name, pi->rtpPkt);
	fprintf(fp, "  %s  :  PI.rtcpPkt                 = %x\n", name, pi->rtcpPkt);
	fprintf(fp, "  %s  :  PI.snmpPkt                 = %x\n", name, pi->snmpPkt);
	fprintf(fp, "  %s  :  PI.isBfd                 = %x\n", name, pi->isBfd);
	fprintf(fp, "  %s  :  PI.aclDiscard                 = %x\n", name, pi->aclDiscard);
	fprintf(fp, "  %s  :  PI.routeProcess                 = %x\n", name, pi->routeProcess);
	fprintf(fp, "  %s  :  PI.routeDiscard                 = %x\n", name, pi->routeDiscard);
	fprintf(fp, "  %s  :  PI.routeExcpDiscard                 = %x\n", name, pi->routeExcpDiscard);
	fprintf(fp, "  %s  :  PI.bridgeProcess                 = %x\n", name, pi->bridgeProcess);
	fprintf(fp, "  %s  :  PI.destMacKnown                 = %x\n", name, pi->destMacKnown);
	fprintf(fp, "  %s  :  PI.entryPend                 = %x\n", name, pi->entryPend);
	fprintf(fp, "  %s  :  PI.l2UcastSrcMatchDiscard                 = %x\n", name, pi->l2UcastSrcMatchDiscard);
	fprintf(fp, "  %s  :  PI.macDaDiscard                 = %x\n", name, pi->macDaDiscard);
	fprintf(fp, "  %s  :  PI.igrStpCheckDiscard                 = %x\n", name, pi->igrStpCheckDiscard);
	fprintf(fp, "  %s  :  PI.stormDrop                 = %x\n", name, pi->stormDrop);
	fprintf(fp, "  %s  :  PI.lrnPortLockDiscard                 = %x\n", name, pi->lrnPortLockDiscard);
	fprintf(fp, "  %s  :  PI.lrnNumExceedDiscard                 = %x\n", name, pi->lrnNumExceedDiscard);
	fprintf(fp, "  %s  :  PI.eapolDiscard                 = %x\n", name, pi->eapolDiscard);
	fprintf(fp, "  %s  :  PI.dot1xDiscard                 = %x\n", name, pi->dot1xDiscard);
	fprintf(fp, "  %s  :  PI.ptpDiscard                 = %x\n", name, pi->ptpDiscard);
	fprintf(fp, "  %s  :  PI.chkMacSaFail                 = %x\n", name, pi->chkMacSaFail);
}