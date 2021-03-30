/*
 * cmodel for Pishon
 * @file: cmodel.h
 * @description: auto generage
 * @note: Copyright (C) 2021-03-29 12:40:57.594806
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */

#ifndef __CMODEL_H__
#define __CMODEL_H__

void HeaderAdjust(tPktInfo *PI, uint8_t *glPktHdr, uint16_t  pktLength, uint8_t  channelId, uint8_t  hwDiscard ) ;

void PacketParser(tPktInfo *PI, uint8_t PR, uint8_t *glPktHdr) ;

void VlanLookup(tPktInfo *PI) ;

void Interface(tPktInfo *PI);

void LookupManage(tPktInfo *PI, uint8_t PR, uint8_t *glPktHdr) ;

void PacketProcess(tPktInfo *PI) ;

void StormCtrlUpdate(uint8_t ) ;

void IngressPolice(tPktInfo *PI, uint8_t *glPktHdr, uint8_t PR) ;

static int FlowPolicingOpr(uint8_t pktLen, uint8_t  color, uint8_t flowPoEn, uint8_t flowPoPtr) ;

static int PortPolicingOpr(uint8_t pktLen, uint8_t  color, uint8_t portPoEn, uint8_t portPoPtr) ;

static int PoliceMetering(uint8_t pktLen, uint8_t  color, uint8_t DsMemPolice, uint8_t DsMemPoliceCfg) ;

void PortMeterUpdate(uint8_t ) ;

void FlowMeterUpdate(uint8_t ) ;

void updateMeterEntry(uint8_t DsMemPolice, uint8_t DsMemPoliceCfg) ;

void Redundancy(tPktInfo *PI) ;

static void individualRecovery(tPktInfo *PI) ;

static void mergeRecovery(tPktInfo *PI) ;

static void matchRecoveryAlgorithm(uint8_t DsMemRcvyCfg, uint8_t DsMemRcvySeq, uint8_t DsMemRcvyCnt, uint8_t discardLog, uint8_t deltaLog, tPktInfo *PI) ;

static void vectorRecoveryAlgorithm(uint8_t DsMemRcvyCfg, uint8_t DsMemRcvySeq, uint8_t DsMemRcvyCnt, uint8_t discardLog, uint8_t deltaLog, tPktInfo *PI) ;

static void sequenceRecoveryReset(uint8_t DsMemRcvyCfg, uint8_t DsMemRcvySeq) ;

void RcvyIndvResetTimer(uint8_t ) ;

void RcvyMergeResetTimer(uint8_t ) ;

void DestPost(tPktInfo *PI, uint8_t MsgIgr2Adm) ;

static int getEnqueueIpv(uint8_t port, uint8_t MsgAdmInfo) ;

static void Egress(uint8_t tMsgAdmInfo *msg, uint8_t uint8_t *packet) ;

void AdmissionControl(tPktInfo *PI, uint64_t  ts, uint16_t  hdrBufPtr, uint16_t  tailBufPtr) ;

//ASIC: void PacketReplicate(uint8_t MsgAdmInfo) ;

void PacketEdit(tPktInfo *PI, uint8_t *glPktNew, uint8_t MsgAdmInfo) ;

static void EgrOamProc(uint8_t DsMemDestPortVal, uint8_t DsMemDestVlanVal, tPktInfo *PI) ;

#endif