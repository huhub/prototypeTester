/*
 * cmodel for Pishon
 * @file: VlanLookup
 * @description: auto generage
 * @note: Copyright (C) 2021-03-29 12:40:57.406404
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
#include <mem/VlanLookupOpr.h>
#include <mem/VlanLookup.h>

void VlanLookup(tPktInfo *PI) {
	uint32_t tmpMacSa = 0;
	uint16_t tmpL2Tpid = 0;
	uint8_t tmpPr = 0;
	uint16_t tmpMacSaHi = 0;
	uint8_t tmpIdx = 0;

	tDsMemMacBasedVlanKey DsMemMacBasedVlanKeyValTmp = {0};
	tDsMemMacBasedVlanKey *DsMemMacBasedVlanKeyVal = &DsMemMacBasedVlanKeyValTmp;
	tCtlProtocolVlanKey CtlProtocolVlanKeyTmp = {0};
	tCtlProtocolVlanKey *CtlProtocolVlanKey = &CtlProtocolVlanKeyTmp;
	readCtlProtocolVlanKey("CtlProtocolVlanKey", 0, CtlProtocolVlanKey, 0);
	tCtlCommon CtlCommonTmp = {0};
	tCtlCommon *CtlCommon = &CtlCommonTmp;
	readCtlCommon("CtlCommon", 0, CtlCommon, 0);
	tCtlVlanLookupLog CtlVlanLookupLogTmp = {0};
	tCtlVlanLookupLog *CtlVlanLookupLog = &CtlVlanLookupLogTmp;
	readCtlVlanLookupLog("CtlVlanLookupLog", 0, CtlVlanLookupLog, 0);
	tDsMemPhyPort DsMemPhyPortValTmp = {0};
	tDsMemPhyPort *DsMemPhyPortVal = &DsMemPhyPortValTmp;

    PI->cpuPktType        = CPU_PKT_NONE;
    rpcRdMem("DsMemPhyPort", PI->srcPort, DsMemPhyPortVal);
    // EAPOL check
    PI->logicalPort       = DsMemPhyPortVal->logicalPort;
    if( (PI->l3Type == L3_TYPE_EAPOL) && DsMemPhyPortVal->dot1xEn && !PI->bypassPp ) {
        PI->copyToCpu          = 1;
        PI->discard            = PI->discard | 1;
        PI->cpuPktType         = CPU_PKT_EAPOL;
        PI->eapolDiscard = 1;
    }
    if( DsMemPhyPortVal->dot1xEn && DsMemPhyPortVal->dot1xDrop && (PI->l3Type != L3_TYPE_EAPOL) ){
        PI->discard            = PI->discard | 1;
        PI->dot1xDiscard = 1;
    }
    PI->isTsn      = PI->isTsn | (DsMemPhyPortVal->avAsTsn && PI->isAvFrame);
    PI->ptpEn      = ((PI->srcPort == CtlCommon->ofPortNo) || (PI->srcPort == CtlCommon->cpuPortNo)) ? 
                     1 : DsMemPhyPortVal->ptpEn && (DsMemPhyPortVal->ptpPortType != PTP_PORT_DISABLE);
    PI->ptpDiscard = PI->isPtp && !PI->ptpEn;
    PI->discard    = PI->discard | PI->ptpDiscard;
    // Vlan classification
    tmpPr =  findPrByType( PROTO_TYPE_ETH );
    if (DsMemPhyPortVal->macBasedVlanEn) {
        tmpMacSaHi = ((uint64_t)glPktHdr[tmpPr->offset+6]<<8) + ( glPktHdr[tmpPr->offset+7]);
        tmpMacSa   = ((uint64_t)glPktHdr[tmpPr->offset+8]<<8) + ( glPktHdr[tmpPr->offset+11]);
        uint8_t bufKey[6] = {0};
        memcpy(bufKey, glPktHdr+tmpPr->offset+6, 6);
        // Initial value is 0
        tmpIdx = crc_8( bufKey, sizeof(bufKey) ) & 0x7f;   
        rpcRdMem("DsMemMacBasedVlanKey", tmpIdx, DsMemMacBasedVlanKeyVal);
        if( GET_BITS(DsMemMacBasedVlanKeyVal->entryValid, 0, 0) && ( GET_BITS(tmpMacSa, 0, 31) == DsMemMacBasedVlanKeyVal->macSa0) && 
            (DsMemMacBasedVlanKeyVal->macSaHi0 == tmpMacSaHi) ) {
            PI->macBasedVlanValid     = 1;
            PI->macBasedVlanIdx  = (tmpIdx << 2) + 0;
        }
        if( GET_BITS(DsMemMacBasedVlanKeyVal->entryValid, 1, 1) && (tmpMacSa == DsMemMacBasedVlanKeyVal->macSa1) && 
            (DsMemMacBasedVlanKeyVal->macSaHi1 == tmpMacSaHi) ) {
            PI->macBasedVlanValid     = 1;
            PI->macBasedVlanIdx  = (tmpIdx << 2) + 1;
        }
        if( GET_BITS(DsMemMacBasedVlanKeyVal->entryValid, 2, 2) && (tmpMacSa == DsMemMacBasedVlanKeyVal->macSa2) && 
            (DsMemMacBasedVlanKeyVal->macSaHi2 == tmpMacSaHi) ) {
            PI->macBasedVlanValid     = 1;
            PI->macBasedVlanIdx  = (tmpIdx << 2) + 2;
        }
        if( GET_BITS(DsMemMacBasedVlanKeyVal->entryValid, 3, 3) && ( GET_BITS(tmpMacSa, 0, 31) == DsMemMacBasedVlanKeyVal->macSa3) && 
            (DsMemMacBasedVlanKeyVal->macSaHi3 == tmpMacSaHi) ) {
            PI->macBasedVlanValid     = 1;
            PI->macBasedVlanIdx  = (tmpIdx << 2) + 3;
        }
    }
    if( DsMemPhyPortVal->protocolVlanEn ) {
        tmpL2Tpid = ((uint64_t)glPktHdr[PI->l3Offset]<<8) + ( glPktHdr[PI->l3Offset+1]);
        if ( GET_BITS(CtlProtocolVlanKey->entryValid, 0, 0) && ((CtlProtocolVlanKey->protoData0 & 
            CtlProtocolVlanKey->protoMask0) == (tmpL2Tpid & CtlProtocolVlanKey->protoMask0))) {
            PI->protocolVlanValid   = 1;
            PI->protocolVlanIdx     = (PI->srcPort << 3) + 0;
        }
        if ( GET_BITS(CtlProtocolVlanKey->entryValid, 1, 1) && ((CtlProtocolVlanKey->protoData1 & 
            CtlProtocolVlanKey->protoMask1) == (tmpL2Tpid & CtlProtocolVlanKey->protoMask1))) {
            PI->protocolVlanValid   = 1;
            PI->protocolVlanIdx     = (PI->srcPort << 3) + 1;
        }
        if ( GET_BITS(CtlProtocolVlanKey->entryValid, 2, 2) && ((CtlProtocolVlanKey->protoData2 & 
            CtlProtocolVlanKey->protoMask2) == (tmpL2Tpid & CtlProtocolVlanKey->protoMask2))) {
            PI->protocolVlanValid   = 1;
            PI->protocolVlanIdx     = (PI->srcPort << 3) + 2;
        }
        if ( GET_BITS(CtlProtocolVlanKey->entryValid, 3, 3) && ((CtlProtocolVlanKey->protoData3 & 
            CtlProtocolVlanKey->protoMask3) == (tmpL2Tpid & CtlProtocolVlanKey->protoMask3))) {
            PI->protocolVlanValid   = 1;
            PI->protocolVlanIdx     = (PI->srcPort << 3) + 3;
        }
        if ( GET_BITS(CtlProtocolVlanKey->entryValid, 4, 4) && ((CtlProtocolVlanKey->protoData4 & 
            CtlProtocolVlanKey->protoMask4) == (tmpL2Tpid & CtlProtocolVlanKey->protoMask4))) {
            PI->protocolVlanValid   = 1;
            PI->protocolVlanIdx     = (PI->srcPort << 3) + 4;
        }
        if ( GET_BITS(CtlProtocolVlanKey->entryValid, 5, 5) && ((CtlProtocolVlanKey->protoData5 & 
            CtlProtocolVlanKey->protoMask5) == (tmpL2Tpid & CtlProtocolVlanKey->protoMask5))) {
            PI->protocolVlanValid   = 1;
            PI->protocolVlanIdx     = (PI->srcPort << 3) + 5;
        }
        if ( GET_BITS(CtlProtocolVlanKey->entryValid, 6, 6) && ((CtlProtocolVlanKey->protoData6 & 
            CtlProtocolVlanKey->protoMask6) == (tmpL2Tpid & CtlProtocolVlanKey->protoMask6))) {
            PI->protocolVlanValid   = 1;
            PI->protocolVlanIdx     = (PI->srcPort << 3) + 6;
        }
        if ( GET_BITS(CtlProtocolVlanKey->entryValid, 7, 7) && ((CtlProtocolVlanKey->protoData7 & 
            CtlProtocolVlanKey->protoMask7) == (tmpL2Tpid & CtlProtocolVlanKey->protoMask7))) {
            PI->protocolVlanValid   = 1;
            PI->protocolVlanIdx     = (PI->srcPort << 3) + 7;
        }
    }
    PI->vlanLkpRslt = PI->protocolVlanValid ? PI->protocolVlanIdx : PI->macBasedVlanValid ? PI->macBasedVlanIdx : 0;
    CtlVlanLookupLog->vlanLkpRslt = PI->vlanLkpRslt;
    CtlVlanLookupLog->eapolDiscard = PI->eapolDiscard;
    CtlVlanLookupLog->dot1xDiscard = PI->dot1xDiscard;
    CtlVlanLookupLog->chkMacSaFail = PI->chkMacSaFail;
    CtlVlanLookupLog->ptpDiscard = PI->ptpDiscard;
    CtlVlanLookupLog->ipSubnetVlanValid = PI->ipSubnetVlanValid;
    CtlVlanLookupLog->macBasedVlanValid = PI->macBasedVlanValid;
    CtlVlanLookupLog->protocolVlanValid = PI->protocolVlanValid;
    CtlVlanLookupLog->isTsn = PI->isTsn;
    CtlVlanLookupLog->ptpEn = PI->ptpEn;
}
