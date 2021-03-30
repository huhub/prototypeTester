/*
 * cmodel for Pishon
 * @file: LookupManage
 * @description: auto generage
 * @note: Copyright (C) 2021-03-29 12:40:57.452899
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
#include <mem/LookupManageOpr.h>
#include <mem/LookupManage.h>

void LookupManage(tPktInfo *PI, uint8_t PR, uint8_t *glPktHdr) {
	uint8_t tmpCuIpSportHashR = 0;
	uint8_t tmpCuIpDportHashR = 0;
	uint8_t tmpCuMacPcpHashL = 0;
	uint16_t tmpL4DestPort = 0;
	uint8_t tmpCuMacPcpHashR = 0;
	uint8_t tmpIdxLeft = 0;
	uint8_t tmpMacHashLeft = 0;
	uint16_t tmpL4SrcPort = 0;
	uint32_t tmpIpDaW1 = 0;
	uint8_t tmpHashLeftIdx = 0;
	uint8_t tmpIdxRight = 0;
	uint8_t tmpMacHashRight = 0;
	uint8_t tmpCuMacHashL = 0;
	uint16_t tmpMacDaHi = 0;
	uint8_t tmpPcp = 0;
	uint8_t tmpL4Pr = 0;
	uint32_t tmpIpDaW0 = 0;
	uint8_t tmpCuMacHashR = 0;
	uint8_t tmpHashRightIdx = 0;
	uint8_t tmpCuIpDscpHashR = 0;
	uint8_t tmpIpPr = 0;
	uint32_t tmpIpDaW2 = 0;
	uint8_t tmpHostIdxL = 0;
	uint8_t tmpRouteHashLeft = 0;
	uint32_t tmpIpDaW3 = 0;
	uint8_t tmpL3Next = 0;
	uint8_t tmpEthPr = 0;
	uint32_t tmpMacDa = 0;
	uint8_t tmpCuIpDscpHashL = 0;
	uint8_t tmpCuIpDportHashL = 0;
	uint8_t tmpDscp = 0;
	uint8_t tmpHostIdxR = 0;
	uint8_t tmpCuIpSportHashL = 0;
	uint8_t tmpRouteHashRight = 0;

	tDsMemCuIpSportKey DsMemCuIpSportKeyRValTmp = {0};
	tDsMemCuIpSportKey *DsMemCuIpSportKeyRVal = &DsMemCuIpSportKeyRValTmp;
	tDsMemCuIpDscpKey DsMemCuIpDscpKeyRValTmp = {0};
	tDsMemCuIpDscpKey *DsMemCuIpDscpKeyRVal = &DsMemCuIpDscpKeyRValTmp;
	tDsMemCuIpDportKey DsMemCuIpDportKeyLValTmp = {0};
	tDsMemCuIpDportKey *DsMemCuIpDportKeyLVal = &DsMemCuIpDportKeyLValTmp;
	tCtlLkupCfg CtlLkupCfgTmp = {0};
	tCtlLkupCfg *CtlLkupCfg = &CtlLkupCfgTmp;
	readCtlLkupCfg("CtlLkupCfg", 0, CtlLkupCfg, 0);
	tDsMemMacValid DsMemMacValidLeftValTmp = {0};
	tDsMemMacValid *DsMemMacValidLeftVal = &DsMemMacValidLeftValTmp;
	tDsMemCuMacKey DsMemCuMacKeyLValTmp = {0};
	tDsMemCuMacKey *DsMemCuMacKeyLVal = &DsMemCuMacKeyLValTmp;
	tDsMemHostRouteKey DsMemHostRouteLeftKeyValTmp = {0};
	tDsMemHostRouteKey *DsMemHostRouteLeftKeyVal = &DsMemHostRouteLeftKeyValTmp;
	tDsMemCuMacKey DsMemCuMacKeyRValTmp = {0};
	tDsMemCuMacKey *DsMemCuMacKeyRVal = &DsMemCuMacKeyRValTmp;
	tDsMemCuMacPcpKey DsMemCuMacPcpKeyRValTmp = {0};
	tDsMemCuMacPcpKey *DsMemCuMacPcpKeyRVal = &DsMemCuMacPcpKeyRValTmp;
	tDsMemMacKey DsMemMacKeyRightValTmp = {0};
	tDsMemMacKey *DsMemMacKeyRightVal = &DsMemMacKeyRightValTmp;
	tDsMemCuIpDscpKey DsMemCuIpDscpKeyLValTmp = {0};
	tDsMemCuIpDscpKey *DsMemCuIpDscpKeyLVal = &DsMemCuIpDscpKeyLValTmp;
	tDsMemHostRouteKey DsMemHostRouteRightKeyValTmp = {0};
	tDsMemHostRouteKey *DsMemHostRouteRightKeyVal = &DsMemHostRouteRightKeyValTmp;
	tDsMemCuMacPcpKey DsMemCuMacPcpKeyLValTmp = {0};
	tDsMemCuMacPcpKey *DsMemCuMacPcpKeyLVal = &DsMemCuMacPcpKeyLValTmp;
	tDsMemMacKey DsMemMacKeyLeftValTmp = {0};
	tDsMemMacKey *DsMemMacKeyLeftVal = &DsMemMacKeyLeftValTmp;
	tDsMemCuIpDportKey DsMemCuIpDportKeyRValTmp = {0};
	tDsMemCuIpDportKey *DsMemCuIpDportKeyRVal = &DsMemCuIpDportKeyRValTmp;
	tDsMemMacValid DsMemMacValidRightValTmp = {0};
	tDsMemMacValid *DsMemMacValidRightVal = &DsMemMacValidRightValTmp;
	tDsMemCuIpSportKey DsMemCuIpSportKeyLValTmp = {0};
	tDsMemCuIpSportKey *DsMemCuIpSportKeyLVal = &DsMemCuIpSportKeyLValTmp;
	tCtlLkpMngLog CtlLkpMngLogTmp = {0};
	tCtlLkpMngLog *CtlLkpMngLog = &CtlLkpMngLogTmp;
	readCtlLkpMngLog("CtlLkpMngLog", 0, CtlLkpMngLog, 0);

    tmpEthPr = findPrByType( PROTO_TYPE_ETH );
    tmpMacDaHi = GET_BITS(glPktHdr, tmpEthPr->offset+1, tmpEthPr->offset);
    tmpMacDa   = GET_BITS(glPktHdr, tmpEthPr->offset+5, tmpEthPr->offset+2);
    if ( GET_BITS(tmpEthPr->qualifier, 2, 4) != 0x0) {    // vlan tagged
        tmpPcp  = GET_BITS(glPktHdr[tmpEthPr->offset+14], 5, 7);
    }
    if (PI->l3Type == PROTO_TYPE_IPV4) {
        tmpIpPr = findPrByType( PROTO_TYPE_IPV4 );
        tmpIpDaW0 = GET_BITS(glPktHdr, tmpIpPr->offset+19, tmpIpPr->offset+16);
        tmpDscp    = glPktHdr[tmpIpPr->offset+1];
        tmpL3Next  = glPktHdr[tmpIpPr->offset+9];
        SET_BITS(bufHostRouteKey, 0, 135, (((uint64_t)0x0<<32) + ((uint64_t)0x0<<24) + ((uint64_t)0x0<<16) + ((uint64_t)0x0<<8) + ( tmpIpDaW0)));
    } else if (PI->l3Type == PROTO_TYPE_IPV6) {
        tmpIpPr = findPrByType( PROTO_TYPE_IPV6 );
        tmpIpDaW3 = GET_BITS(glPktHdr, tmpIpPr->offset+27, tmpIpPr->offset+24);
        tmpIpDaW2 = GET_BITS(glPktHdr, tmpIpPr->offset+31, tmpIpPr->offset+28);
        tmpIpDaW1 = GET_BITS(glPktHdr, tmpIpPr->offset+35, tmpIpPr->offset+32);
        tmpIpDaW0 = GET_BITS(glPktHdr, tmpIpPr->offset+39, tmpIpPr->offset+36);
        tmpDscp    = ((uint64_t) GET_BITS(glPktHdr[tmpIpPr->offset], 0, 3)<<4) + ( GET_BITS(glPktHdr[tmpIpPr->offset+1], 4, 7));
        tmpL3Next  = glPktHdr[tmpIpPr->offset+6];
        SET_BITS(bufHostRouteKey, 0, 135, (((uint64_t)0x1<<128) + ((uint64_t) GET_BITS(tmpIpDaW3, 0, 31)<<96) + ((uint64_t) GET_BITS(tmpIpDaW2, 0, 31)<<64) + ((uint64_t) GET_BITS(tmpIpDaW1, 0, 31)<<32) + ( GET_BITS(tmpIpDaW0, 0, 31))));
    }
    /** 1 destination MAC lookup */
    if (CtlLkupCfg->macDaKeyEn) {
        SET_BITS(bufMacKey, 0, 47, (((uint64_t)tmpMacDaHi<<32) + ( GET_BITS(tmpMacDa, 0, 31))));
        tmpCuMacHashL = crc_8(bufMacKey, sizeof(bufMacKey)) & setAllBitOne(calc( 32
));
        tmpCuMacHashR = 16 + crc_ccitt_ffff(bufMacKey, sizeof(bufMacKey)) & setAllBitOne(calc( 32
));
        rpcRdMem("DsMemCuMacKey", tmpCuMacHashL, DsMemCuMacKeyLVal);
        rpcRdMem("DsMemCuMacKey", tmpCuMacHashR, DsMemCuMacKeyRVal);
        if ( GET_BITS(DsMemCuMacKeyLVal->valid, 0, 0) && DsMemCuMacKeyLVal->macAddr0 == tmpMacDa &&
            DsMemCuMacKeyLVal->macAddrHi0 == tmpMacDaHi) {
            PI->cuMacHit = 1;
            PI->cuMacIdx = (tmpCuMacHashL << 1) + 0;
        }
        if ( GET_BITS(DsMemCuMacKeyRVal->valid, 0, 0) && DsMemCuMacKeyRVal->macAddr0 == tmpMacDa &&
            DsMemCuMacKeyRVal->macAddrHi0 == tmpMacDaHi) {
            PI->cuMacHit = 1;
            PI->cuMacIdx = (tmpCuMacHashL << 1) + 0;
        }
        if ( GET_BITS(DsMemCuMacKeyLVal->valid, 1, 1) && DsMemCuMacKeyLVal->macAddr1 == tmpMacDa &&
            DsMemCuMacKeyLVal->macAddrHi1 == tmpMacDaHi) {
            PI->cuMacHit = 1;
            PI->cuMacIdx = (tmpCuMacHashL << 1) + 1;
        }
        if ( GET_BITS(DsMemCuMacKeyRVal->valid, 1, 1) && DsMemCuMacKeyRVal->macAddr1 == tmpMacDa &&
            DsMemCuMacKeyRVal->macAddrHi1 == tmpMacDaHi) {
            PI->cuMacHit = 1;
            PI->cuMacIdx = (tmpCuMacHashL << 1) + 1;
        }
    }
    /** 2 destination MAC + Vlan PCP lookup */
    if (CtlLkupCfg->macPcpKeyEn) {
        SET_BITS(bufMacPcpKey, 0, 55, (((uint64_t)tmpPcp<<48) + ((uint64_t) GET_BITS(tmpMacDaHi, 0, 15)<<32) + ( GET_BITS(tmpMacDa, 0, 31))));
        tmpCuMacPcpHashL = crc_8(bufMacPcpKey, sizeof(bufMacPcpKey)) & setAllBitOne(calc( 32
));
        tmpCuMacPcpHashR = 16 + crc_ccitt_ffff(bufMacPcpKey, sizeof(bufMacPcpKey)) & setAllBitOne(calc( 32
));
        rpcRdMem("DsMemCuMacPcpKey", tmpCuMacPcpHashL, DsMemCuMacPcpKeyLVal);
        rpcRdMem("DsMemCuMacPcpKey", tmpCuMacPcpHashR, DsMemCuMacPcpKeyRVal);
        if ( GET_BITS(DsMemCuMacPcpKeyLVal->valid, 0, 0) && DsMemCuMacPcpKeyLVal->macAddr0 == tmpMacDa &&
            DsMemCuMacPcpKeyLVal->macAddrHi0 == tmpMacDaHi && DsMemCuMacPcpKeyLVal->pcp0 == tmpPcp) {
            PI->cuMacPcpHit = 1;
            PI->cuMacPcpIdx = (tmpCuMacPcpHashL << 1) + 0;
        }
        if ( GET_BITS(DsMemCuMacPcpKeyRVal->valid, 0, 0) && DsMemCuMacPcpKeyRVal->macAddr0 == tmpMacDa &&
            DsMemCuMacPcpKeyRVal->macAddrHi0 == tmpMacDaHi) {
            PI->cuMacPcpHit = 1;
            PI->cuMacPcpIdx = (tmpCuMacPcpHashL << 1) + 0;
        }
        if ( GET_BITS(DsMemCuMacPcpKeyLVal->valid, 1, 1) && DsMemCuMacPcpKeyLVal->macAddr1 == tmpMacDa &&
            DsMemCuMacPcpKeyLVal->macAddrHi1 == tmpMacDaHi && DsMemCuMacPcpKeyLVal->pcp1 == tmpPcp) {
            PI->cuMacPcpHit = 1;
            PI->cuMacPcpIdx = (tmpCuMacPcpHashL << 1) + 1;
        }
        if ( GET_BITS(DsMemCuMacPcpKeyRVal->valid, 1, 1) && DsMemCuMacPcpKeyRVal->macAddr1 == tmpMacDa &&
            DsMemCuMacPcpKeyRVal->macAddrHi1 == tmpMacDaHi) {
            PI->cuMacPcpHit = 1;
            PI->cuMacPcpIdx = (tmpCuMacPcpHashL << 1) + 1;
        }
    }
    /** 3 destination IP + DSCP */
    if (CtlLkupCfg->ipDscpKeyEn) {
        SET_BITS(bufIpDscpKey, 0, 135, (((uint64_t)tmpDscp<<128) + ((uint64_t) GET_BITS(tmpIpDaW3, 0, 31)<<96) + ((uint64_t) GET_BITS(tmpIpDaW2, 0, 31)<<64) + ((uint64_t) GET_BITS(tmpIpDaW1, 0, 31)<<32) + ( GET_BITS(tmpIpDaW0, 0, 31))));
        tmpCuIpDscpHashL[calc( 16
)-1:0] = crc_8(bufIpDscpKey, sizeof(bufIpDscpKey)) & setAllBitOne(calc( 16
));
        tmpCuIpDscpHashR[calc( 16
):0] = 8 + crc_ccitt_ffff(bufIpDscpKey, sizeof(bufIpDscpKey)) & setAllBitOne(calc( 16
));
        rpcRdMem("DsMemCuIpDscpKey", tmpCuIpDscpHashL, DsMemCuIpDscpKeyLVal);
        rpcRdMem("DsMemCuIpDscpKey", tmpCuIpDscpHashR, DsMemCuIpDscpKeyRVal);
        if (PI->l3Type == PROTO_TYPE_IPV6) {
            if ( GET_BITS(DsMemCuIpDscpKeyLVal->valid, 0, 0) && DsMemCuIpDscpKeyLVal->dscp0 = tmpDscp &&
                DsMemCuIpDscpKeyLVal->ipAddr3 == tmpIpDa3 && 
                DsMemCuIpDscpKeyLVal->ipAddr2 == tmpIpDa2 &&
                DsMemCuIpDscpKeyLVal->ipAddr1 == tmpIpDa1 && 
                DsMemCuIpDscpKeyLVal->ipAddr0 == tmpIpDa0) {
                PI->cuIpDscpHit = 1;
                PI->cuIpDscpIdx = (tmpCuIpDscpHashL << 2);
            }
            if ( GET_BITS(DsMemCuIpDscpKeyRVal->valid, 0, 0) && DsMemCuIpDscpKeyRVal->dscp0 = tmpDscp &&
                DsMemCuIpDscpKeyRVal->ipAddr3 == tmpIpDa3 && 
                DsMemCuIpDscpKeyRVal->ipAddr2 == tmpIpDa2 &&
                DsMemCuIpDscpKeyRVal->ipAddr1 == tmpIpDa1 && 
                DsMemCuIpDscpKeyRVal->ipAddr0 == tmpIpDa0) {
                PI->cuIpDscpHit = 1;
                PI->cuIpDscpIdx = (tmpCuIpDscpHashR << 2);
            }
        } else {
            if ( GET_BITS(DsMemCuIpDscpKeyLVal->valid, 0, 0) && DsMemCuIpDscpKeyLVal->ipAddr0 == tmpIpDa0 &&
                DsMemCuIpDscpKeyLVal->dscp0 == tmpDscp) {
                PI->cuIpDscpHit = 1;
                PI->cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 0;
            }
            if ( GET_BITS(DsMemCuIpDscpKeyRVal->valid, 0, 0) && DsMemCuIpDscpKeyRVal->macAddr0 == tmpIpDa0 &&
                DsMemCuIpDscpKeyRVal->dscp0 == tmpDscp) {
                PI->cuIpDscpHit = 1;
                PI->cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 0;
            }
            if ( GET_BITS(DsMemCuIpDscpKeyLVal->valid, 1, 1) && DsMemCuIpDscpKeyLVal->ipAddr1 == tmpIpDa1 &&
                DsMemCuIpDscpKeyLVal->dscp1 == tmpDscp) {
                PI->cuIpDscpHit = 1;
                PI->cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 1;
            }
            if ( GET_BITS(DsMemCuIpDscpKeyRVal->valid, 1, 1) && DsMemCuIpDscpKeyRVal->macAddr1 == tmpIpDa1 &&
                DsMemCuIpDscpKeyRVal->dscp1 == tmpDscp) {
                PI->cuIpDscpHit = 1;
                PI->cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 1;
            }
            if ( GET_BITS(DsMemCuIpDscpKeyLVal->valid, 2, 2) && DsMemCuIpDscpKeyLVal->ipAddr2 == tmpIpDa2 &&
                DsMemCuIpDscpKeyLVal->dscp2 == tmpDscp) {
                PI->cuIpDscpHit = 1;
                PI->cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 2;
            }
            if ( GET_BITS(DsMemCuIpDscpKeyRVal->valid, 2, 2) && DsMemCuIpDscpKeyRVal->macAddr2 == tmpIpDa2 &&
                DsMemCuIpDscpKeyRVal->dscp2 == tmpDscp) {
                PI->cuIpDscpHit = 1;
                PI->cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 2;
            }
            if ( GET_BITS(DsMemCuIpDscpKeyLVal->valid, 3, 3) && DsMemCuIpDscpKeyLVal->ipAddr3 == tmpIpDa3 &&
                DsMemCuIpDscpKeyLVal->dscp3 == tmpDscp) {
                PI->cuIpDscpHit = 1;
                PI->cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 3;
            }
            if ( GET_BITS(DsMemCuIpDscpKeyRVal->valid, 3, 3) && DsMemCuIpDscpKeyRVal->macAddr3 == tmpIpDa3 &&
                DsMemCuIpDscpKeyRVal->dscp3 == tmpDscp) {
                PI->cuIpDscpHit = 1;
                PI->cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 3;
            }
        }
    }
    if (PI->l4Type == PROTO_TYPE_UDP) {
        tmpL4Pr = findPrByType( PROTO_TYPE_UDP );
    } else if (PI->l4Type == PROTO_TYPE_TCP) {
        tmpL4Pr = findPrByType( PROTO_TYPE_TCP );
    }
    tmpL4DestPort = GET_BITS(glPktHdr, tmpL4Pr->offset+1, tmpL4Pr->offset);
    tmpL4SrcPort  = GET_BITS(glPktHdr, tmpL4Pr->offset+3, tmpL4Pr->offset+2);
    /** 4 destination IP + Src Port */
    if (CtlLkupCfg->ipSportKeyEn) {
        SET_BITS(bufIpSportKey, 0, 135, (((uint64_t)tmpL4SrcPort<<136) + ((uint64_t) GET_BITS(tmpL3Next, 0, 7)<<128) + ((uint64_t) GET_BITS(tmpIpDaW3, 0, 31)<<96) + ((uint64_t) GET_BITS(tmpIpDaW2, 0, 31)<<64) + ((uint64_t) GET_BITS(tmpIpDaW1, 0, 31)<<32) + ( GET_BITS(tmpIpDaW0, 0, 31))));
        tmpCuIpSportHashL[calc( 16)-1:0] = crc_8(bufIpSportKey, sizeof(bufIpSportKey)) & setAllBitOne(calc( 16));
        tmpCuIpSportHashR[calc( 16):0] = 8 + crc_ccitt_ffff(bufIpSportKey, sizeof(bufIpSportKey)) & setAllBitOne(calc( 16));
        rpcRdMem("DsMemCuIpSportKey", tmpCuIpSportHashL, DsMemCuIpSportKeyLVal);
        rpcRdMem("DsMemCuIpSportKey", tmpCuIpSportHashR, DsMemCuIpSportKeyRVal);
        if (PI->l3Type == PROTO_TYPE_IPV6) {
            if ( GET_BITS(DsMemCuIpSportKeyLVal->valid, 0, 0) && DsMemCuIpSportKeyLVal->l3Next0 = tmpL3Next &&
                DsMemCuIpSportKeyLVal->l4SrcPort == tmpL4SrcPort &&
                DsMemCuIpSportKeyLVal->ipAddr3 == tmpIpDa3 && 
                DsMemCuIpSportKeyLVal->ipAddr2 == tmpIpDa2 &&
                DsMemCuIpSportKeyLVal->ipAddr1 == tmpIpDa1 && 
                DsMemCuIpSportKeyLVal->ipAddr0 == tmpIpDa0) {
                PI->cuIpSportHit = 1;
                PI->cuIpSportIdx = (tmpCuIpSportHashL << 2);
            }
            if ( GET_BITS(DsMemCuIpSportKeyRVal->valid, 0, 0) && DsMemCuIpSportKeyRVal->L3Next0 = tmpL3Next &&
                DsMemCuIpSportKeyRVal->l4SrcPort == tmpL4SrcPort &&
                DsMemCuIpSportKeyRVal->ipAddr3 == tmpIpDa3 && 
                DsMemCuIpSportKeyRVal->ipAddr2 == tmpIpDa2 &&
                DsMemCuIpSportKeyRVal->ipAddr1 == tmpIpDa1 && 
                DsMemCuIpSportKeyRVal->ipAddr0 == tmpIpDa0) {
                PI->cuIpSportHit = 1;
                PI->cuIpSportIdx = (tmpCuIpSportHashR << 2);
            }
        } else {
            if ( GET_BITS(DsMemCuIpSportKeyLVal->valid, 0, 0) && DsMemCuIpSportKeyLVal->ipAddr0 == tmpIpDa0 &&
                DsMemCuIpSportKeyLVal->l3Next0 == tmpL3Next && DsMemCuIpSportKeyLVal->l4SrcPort0 == tmpL4SrcPort) {
                PI->cuIpSportHit = 1;
                PI->cuIpSportIdx = (tmpCuIpSportHashL << 1) + 0;
            }
            if ( GET_BITS(DsMemCuIpSportKeyRVal->valid, 0, 0) && DsMemCuIpSportKeyRVal->ipAddr0 == tmpIpDa0 &&
                DsMemCuIpSportKeyRVal->l3Next0 == tmpL3Next && DsMemCuIpSportKeyRVal->l4SrcPort0 == tmpL4SrcPort) {
                PI->cuIpSportHit = 1;
                PI->cuIpSportIdx = (tmpCuIpSportHashL << 1) + 0;
            }
            if ( GET_BITS(DsMemCuIpSportKeyLVal->valid, 1, 1) && DsMemCuIpSportKeyLVal->ipAddr1 == tmpIpDa1 &&
                DsMemCuIpSportKeyLVal->l3Next1 == tmpL3Next && DsMemCuIpSportKeyLVal->l4SrcPort1 == tmpL4SrcPort) {
                PI->cuIpSportHit = 1;
                PI->cuIpSportIdx = (tmpCuIpSportHashL << 1) + 1;
            }
            if ( GET_BITS(DsMemCuIpSportKeyRVal->valid, 1, 1) && DsMemCuIpSportKeyRVal->ipAddr1 == tmpIpDa1 &&
                DsMemCuIpSportKeyRVal->l3Next1 == tmpL3Next && DsMemCuIpSportKeyRVal->l4SrcPort1 == tmpL4SrcPort) {
                PI->cuIpSportHit = 1;
                PI->cuIpSportIdx = (tmpCuIpSportHashL << 1) + 1;
            }
            if ( GET_BITS(DsMemCuIpSportKeyLVal->valid, 2, 2) && DsMemCuIpSportKeyLVal->ipAddr2 == tmpIpDa2 &&
                DsMemCuIpSportKeyLVal->l3Next2 == tmpL3Next && DsMemCuIpSportKeyLVal->l4SrcPort2 == tmpL4SrcPort) {
                PI->cuIpSportHit = 1;
                PI->cuIpSportIdx = (tmpCuIpSportHashL << 1) + 2;
            }
            if ( GET_BITS(DsMemCuIpSportKeyRVal->valid, 2, 2) && DsMemCuIpSportKeyRVal->ipAddr2 == tmpIpDa2 &&
                DsMemCuIpSportKeyRVal->l3Next2 == tmpL3Next && DsMemCuIpSportKeyRVal->l4SrcPort2 == tmpL4SrcPort) {
                PI->cuIpSportHit = 1;
                PI->cuIpSportIdx = (tmpCuIpSportHashL << 1) + 2;
            }
            if ( GET_BITS(DsMemCuIpSportKeyLVal->valid, 3, 3) && DsMemCuIpSportKeyLVal->ipAddr3 == tmpIpDa3 &&
                DsMemCuIpSportKeyLVal->l3Next3 == tmpL3Next && DsMemCuIpSportKeyLVal->l4SrcPort3 == tmpL4SrcPort) {
                PI->cuIpSportHit = 1;
                PI->cuIpSportIdx = (tmpCuIpSportHashL << 1) + 3;
            }
            if ( GET_BITS(DsMemCuIpSportKeyRVal->valid, 3, 3) && DsMemCuIpSportKeyRVal->ipAddr3 == tmpIpDa3 &&
                DsMemCuIpSportKeyRVal->l3Next3 == tmpL3Next && DsMemCuIpSportKeyRVal->l4SrcPort3 == tmpL4SrcPort) {
                PI->cuIpSportHit = 1;
                PI->cuIpSportIdx = (tmpCuIpSportHashL << 1) + 3;
            }
        }
    }
    /** 5 destination IP + Dest Port */
    if (CtlLkupCfg->ipDportKeyEn) {
        SET_BITS(bufIpDportKey, 0, 135, (((uint64_t)tmpL4DestPort<<136) + ((uint64_t) GET_BITS(tmpL3Next, 0, 7)<<128) + ((uint64_t) GET_BITS(tmpIpDaW3, 0, 31)<<96) + ((uint64_t) GET_BITS(tmpIpDaW2, 0, 31)<<64) + ((uint64_t) GET_BITS(tmpIpDaW1, 0, 31)<<32) + ( GET_BITS(tmpIpDaW0, 0, 31))));
        tmpCuIpDportHashL[calc( 16
)-1:0] = crc_8(bufIpDportKey, sizeof(bufIpDportKey)) & setAllBitOne(calc( 16
));
        tmpCuIpDportHashR[calc( 16
):0] = 8 + crc_ccitt_ffff(bufIpDportKey, sizeof(bufIpDportKey)) & setAllBitOne(calc( 16
));
        rpcRdMem("DsMemCuIpDportKey", tmpCuIpDportHashL, DsMemCuIpDportKeyLVal);
        rpcRdMem("DsMemCuIpDportKey", tmpCuIpDportHashR, DsMemCuIpDportKeyRVal);
        if (PI->l3Type == PROTO_TYPE_IPV6) {
            if ( GET_BITS(DsMemCuIpDportKeyLVal->valid, 0, 0) && DsMemCuIpDportKeyLVal->l3Next0 = tmpL3Next &&
                DsMemCuIpDportKeyLVal->l4DestPort == tmpL4DestPort &&
                DsMemCuIpDportKeyLVal->ipAddr3 == tmpIpDa3 && 
                DsMemCuIpDportKeyLVal->ipAddr2 == tmpIpDa2 &&
                DsMemCuIpDportKeyLVal->ipAddr1 == tmpIpDa1 && 
                DsMemCuIpDportKeyLVal->ipAddr0 == tmpIpDa0) {
                PI->cuIpDportHit = 1;
                PI->cuIpDportIdx = (tmpCuIpDportHashL << 2);
            }
            if ( GET_BITS(DsMemCuIpDportKeyRVal->valid, 0, 0) && DsMemCuIpDportKeyRVal->L3Next0 = tmpL3Next &&
                DsMemCuIpDportKeyRVal->l4DestPort == tmpL4DestPort &&
                DsMemCuIpDportKeyRVal->ipAddr3 == tmpIpDa3 && 
                DsMemCuIpDportKeyRVal->ipAddr2 == tmpIpDa2 &&
                DsMemCuIpDportKeyRVal->ipAddr1 == tmpIpDa1 && 
                DsMemCuIpDportKeyRVal->ipAddr0 == tmpIpDa0) {
                PI->cuIpDportHit = 1;
                PI->cuIpDportIdx = (tmpCuIpDportHashR << 2);
            }
        } else {
            if ( GET_BITS(DsMemCuIpDportKeyLVal->valid, 0, 0) && DsMemCuIpDportKeyLVal->ipAddr0 == tmpIpDa0 &&
                DsMemCuIpDportKeyLVal->l3Next0 == tmpL3Next && DsMemCuIpDportKeyLVal->l4DestPort0 == tmpL4DestPort) {
                PI->cuIpDportHit = 1;
                PI->cuIpDportIdx = (tmpCuIpDportHashL << 1) + 0;
            }
            if ( GET_BITS(DsMemCuIpDportKeyRVal->valid, 0, 0) && DsMemCuIpDportKeyRVal->ipAddr0 == tmpIpDa0 &&
                DsMemCuIpDportKeyRVal->l3Next0 == tmpL3Next && DsMemCuIpDportKeyRVal->l4DestPort0 == tmpL4DestPort) {
                PI->cuIpDportHit = 1;
                PI->cuIpDportIdx = (tmpCuIpDportHashL << 1) + 0;
            }
            if ( GET_BITS(DsMemCuIpDportKeyLVal->valid, 1, 1) && DsMemCuIpDportKeyLVal->ipAddr1 == tmpIpDa1 &&
                DsMemCuIpDportKeyLVal->l3Next1 == tmpL3Next && DsMemCuIpDportKeyLVal->l4DestPort1 == tmpL4DestPort) {
                PI->cuIpDportHit = 1;
                PI->cuIpDportIdx = (tmpCuIpDportHashL << 1) + 1;
            }
            if ( GET_BITS(DsMemCuIpDportKeyRVal->valid, 1, 1) && DsMemCuIpDportKeyRVal->ipAddr1 == tmpIpDa1 &&
                DsMemCuIpDportKeyRVal->l3Next1 == tmpL3Next && DsMemCuIpDportKeyRVal->l4DestPort1 == tmpL4DestPort) {
                PI->cuIpDportHit = 1;
                PI->cuIpDportIdx = (tmpCuIpDportHashL << 1) + 1;
            }
            if ( GET_BITS(DsMemCuIpDportKeyLVal->valid, 2, 2) && DsMemCuIpDportKeyLVal->ipAddr2 == tmpIpDa2 &&
                DsMemCuIpDportKeyLVal->l3Next2 == tmpL3Next && DsMemCuIpDportKeyLVal->l4DestPort2 == tmpL4DestPort) {
                PI->cuIpDportHit = 1;
                PI->cuIpDportIdx = (tmpCuIpDportHashL << 1) + 2;
            }
            if ( GET_BITS(DsMemCuIpDportKeyRVal->valid, 2, 2) && DsMemCuIpDportKeyRVal->ipAddr2 == tmpIpDa2 &&
                DsMemCuIpDportKeyRVal->l3Next2 == tmpL3Next && DsMemCuIpDportKeyRVal->l4DestPort2 == tmpL4DestPort) {
                PI->cuIpDportHit = 1;
                PI->cuIpDportIdx = (tmpCuIpDportHashL << 1) + 2;
            }
            if ( GET_BITS(DsMemCuIpDportKeyLVal->valid, 3, 3) && DsMemCuIpDportKeyLVal->ipAddr3 == tmpIpDa3 &&
                DsMemCuIpDportKeyLVal->l3Next3 == tmpL3Next && DsMemCuIpDportKeyLVal->l4DestPort3 == tmpL4DestPort) {
                PI->cuIpDportHit = 1;
                PI->cuIpDportIdx = (tmpCuIpDportHashL << 1) + 3;
            }
            if ( GET_BITS(DsMemCuIpDportKeyRVal->valid, 3, 3) && DsMemCuIpDportKeyRVal->ipAddr3 == tmpIpDa3 &&
                DsMemCuIpDportKeyRVal->l3Next3 == tmpL3Next && DsMemCuIpDportKeyRVal->l4DestPort3 == tmpL4DestPort) {
                PI->cuIpDportHit = 1;
                PI->cuIpDportIdx = (tmpCuIpDportHashL << 1) + 3;
            }
        }
    }
    /** Normal switch forwording */
    if (PI->routingEn ) {
        /** Host route address exactly lookup */
        // Left Hash
        // crc initial value is 8'hff
        tmpRouteHashLeft= crc8( bufHostRouteKey, sizeof(bufHostRouteKey) ) & 0x7;  
        tmpHostIdxL= (tmpRouteHashLeft << 2);
        rpcRdMem("DsMemHostRouteKey", tmpRouteHashLeft, DsMemHostRouteLeftKeyVal);
        // Right Hash
        // crc, 16'hfffff
        tmpRouteHashRight = 8 + (crc_ccitt_ffff( bufHostRouteKey, sizeof(bufHostRouteKey) ) & 0x7);   
        tmpHostIdxR= (tmpRouteHashRight << 2);
        rpcRdMem("DsMemHostRouteKey", tmpRouteHashRight, DsMemHostRouteRightKeyVal);
        if (PI->l3Type == PROTO_TYPE_IPV6 ) {
            if ( GET_BITS(DsMemHostRouteLeftKeyVal->isValid, 0, 0) && 
                (0x1 == GET_BITS(DsMemHostRouteLeftKeyVal->isIpv6, 0, 0)) && 
                ( GET_BITS(tmpIpDaW3, 0, 31) == DsMemHostRouteLeftKeyVal->ipAddrF3) && 
                ( GET_BITS(tmpIpDaW2, 0, 31) == DsMemHostRouteLeftKeyVal->ipAddrF2) && 
                ( GET_BITS(tmpIpDaW1, 0, 31) == DsMemHostRouteLeftKeyVal->ipAddrF1) && 
                ( GET_BITS(tmpIpDaW0, 0, 31) == DsMemHostRouteLeftKeyVal->ipAddrF0) ) {
                PI->hostRouteLeftHit      = 1;
                tmpHashLeftIdx = tmpHostIdxL;
            }
            // right
            if ( GET_BITS(DsMemHostRouteRightValidVal->isValid, GET_BITS(tmpHostIdxR, 0, 4), GET_BITS(tmpHostIdxR, 0, 4)) && 
                (0x1 == GET_BITS(DsMemHostRouteRightKeyVal->isIpv6, 0, 0)) && 
                ( GET_BITS(tmpIpDaW3, 0, 31) == DsMemHostRouteRightKeyVal->ipAddrF3) && 
                ( GET_BITS(tmpIpDaW2, 0, 31) == DsMemHostRouteRightKeyVal->ipAddrF2) && 
                ( GET_BITS(tmpIpDaW1, 0, 31) == DsMemHostRouteRightKeyVal->ipAddrF1) && 
                ( GET_BITS(tmpIpDaW0, 0, 31) == DsMemHostRouteRightKeyVal->ipAddrF0) ) {
                PI->hostRouteRightHit      = 1;
                tmpHashRightIdx = tmpHostIdxR;
            }
        } else {
            if ( GET_BITS(DsMemHostRouteLeftKeyVal->isValid, 0, 0) 
            && (0x0 == GET_BITS(DsMemHostRouteLeftKeyVal->isIpv6F, 0, 0)) 
            && ( GET_BITS(tmpIpDaW0, 0, 31) == DsMemHostRouteLeftKeyVal->ipAddrF0) ) {
                PI->hostRouteLeftHit  = 1;
                tmpHashLeftIdx       = tmpHostIdxL + 0;
            }
            // right
            if ( GET_BITS(DsMemHostRouteRightKeyVal->isValid, 0, 0) 
            && (0x0 == GET_BITS(DsMemHostRouteRightKeyVal->isIpv6F, 0, 0)) 
            && ( GET_BITS(tmpIpDaW0, 0, 31) == DsMemHostRouteRightKeyVal->ipAddrF0) ) {
                PI->hostRouteRightHit = 1;
                tmpHashRightIdx      = tmpHostIdxR + 0;
            }
            if ( GET_BITS(DsMemHostRouteLeftKeyVal->isValid, 1, 1) 
            && (0x0 == GET_BITS(DsMemHostRouteLeftKeyVal->isIpv6F, 1, 1)) 
            && ( GET_BITS(tmpIpDaW0, 0, 31) == DsMemHostRouteLeftKeyVal->ipAddrF1) ) {
                PI->hostRouteLeftHit  = 1;
                tmpHashLeftIdx       = tmpHostIdxL + 1;
            }
            // right
            if ( GET_BITS(DsMemHostRouteRightKeyVal->isValid, 1, 1) 
            && (0x0 == GET_BITS(DsMemHostRouteRightKeyVal->isIpv6F, 1, 1)) 
            && ( GET_BITS(tmpIpDaW0, 0, 31) == DsMemHostRouteRightKeyVal->ipAddrF1) ) {
                PI->hostRouteRightHit = 1;
                tmpHashRightIdx      = tmpHostIdxR + 1;
            }
            if ( GET_BITS(DsMemHostRouteLeftKeyVal->isValid, 2, 2) 
            && (0x0 == GET_BITS(DsMemHostRouteLeftKeyVal->isIpv6F, 2, 2)) 
            && ( GET_BITS(tmpIpDaW0, 0, 31) == DsMemHostRouteLeftKeyVal->ipAddrF2) ) {
                PI->hostRouteLeftHit  = 1;
                tmpHashLeftIdx       = tmpHostIdxL + 2;
            }
            // right
            if ( GET_BITS(DsMemHostRouteRightKeyVal->isValid, 2, 2) 
            && (0x0 == GET_BITS(DsMemHostRouteRightKeyVal->isIpv6F, 2, 2)) 
            && ( GET_BITS(tmpIpDaW0, 0, 31) == DsMemHostRouteRightKeyVal->ipAddrF2) ) {
                PI->hostRouteRightHit = 1;
                tmpHashRightIdx      = tmpHostIdxR + 2;
            }
            if ( GET_BITS(DsMemHostRouteLeftKeyVal->isValid, 3, 3) 
            && (0x0 == GET_BITS(DsMemHostRouteLeftKeyVal->isIpv6F, 3, 3)) 
            && ( GET_BITS(tmpIpDaW0, 0, 31) == DsMemHostRouteLeftKeyVal->ipAddrF3) ) {
                PI->hostRouteLeftHit  = 1;
                tmpHashLeftIdx       = tmpHostIdxL + 3;
            }
            // right
            if ( GET_BITS(DsMemHostRouteRightKeyVal->isValid, 3, 3) 
            && (0x0 == GET_BITS(DsMemHostRouteRightKeyVal->isIpv6F, 3, 3)) 
            && ( GET_BITS(tmpIpDaW0, 0, 31) == DsMemHostRouteRightKeyVal->ipAddrF3) ) {
                PI->hostRouteRightHit = 1;
                tmpHashRightIdx      = tmpHostIdxR + 3;
            }
        }
        PI->ipRouteLookup = 1;
        /** Summary lookup result */
        if (PI->hostRouteLeftHit ) {
            PI->ipRouteIdx  = tmpHashLeftIdx;    
        } else if (PI->hostRouteRightHit ) {
            PI->ipRouteIdx  = tmpHashRightIdx;   
        }
    } else {
        /** Bridge Lookup */
        SET_BITS(bufFdbkey, 0, 79, (((uint64_t)PI->fid<<48) + ((uint64_t) GET_BITS(tmpMacDaHi, 0, 15)<<32) + ( GET_BITS(tmpMacDa, 0, 31))));
        tmpMacHashLeft = crc_8( bufFdbkey, sizeof(bufFdbkey)) & 0x1f;    // Initial value is ffffffff 
        tmpMacHashRight = (crc_ccitt_ffff( bufFdbkey, sizeof(bufFdbkey)) & 0x1f) + 32;   // Initial value  is ffff 
        PI->macDaLValid    = 0;
        PI->macDaRValid   = 0;
        // Left hash
        rpcRdMem("DsMemMacKey", tmpMacHashLeft, DsMemMacKeyLeftVal);
        rpcRdMem("DsMemMacValid", GET_BITS(tmpMacHashLeft, 3, 5), DsMemMacValidLeftVal);
        // Right Hash
        rpcRdMem("DsMemMacKey", GET_BITS(tmpMacHashRight, 0, 5), DsMemMacKeyRightVal);
        rpcRdMem("DsMemMacValid", GET_BITS(tmpMacHashRight, 3, 5), DsMemMacValidRightVal);
        tmpIdxLeft    = (tmpMacHashLeft << 2) + 0;
        // Left check
        if ( GET_BITS(DsMemMacValidLeftVal->valid, GET_BITS(tmpIdxLeft, 0, 4), GET_BITS(tmpIdxLeft, 0, 4)) && (DsMemMacKeyLeftVal->macAddr0 == tmpMacDa)
            && (DsMemMacKeyLeftVal->vlanId0 == PI->fid) && (DsMemMacKeyLeftVal->macAddrHi0 == tmpMacDaHi) ) {
            PI->macDaLValid     = 1;
            PI->macDaIdx     = tmpIdxLeft;
        }
        // Right check
        tmpIdxRight   = (tmpMacHashRight << 2) + 0;
        if ( GET_BITS(DsMemMacValidRightVal->valid, GET_BITS(tmpIdxRight, 0, 4), GET_BITS(tmpIdxRight, 0, 4)) && (DsMemMacKeyRightVal->macAddr0 == tmpMacDa)
            && (DsMemMacKeyRightVal->vlanId0 == PI->fid) && (DsMemMacKeyRightVal->macAddrHi0 == tmpMacDaHi) ) {
            PI->macDaRValid     = 1;
            PI->macDaIdx      = tmpIdxRight;
        }
        tmpIdxLeft    = (tmpMacHashLeft << 2) + 1;
        // Left check
        if ( GET_BITS(DsMemMacValidLeftVal->valid, GET_BITS(tmpIdxLeft, 0, 4), GET_BITS(tmpIdxLeft, 0, 4)) && (DsMemMacKeyLeftVal->macAddr1 == tmpMacDa)
            && (DsMemMacKeyLeftVal->vlanId1 == PI->fid) && (DsMemMacKeyLeftVal->macAddrHi1 == tmpMacDaHi) ) {
            PI->macDaLValid     = 1;
            PI->macDaIdx     = tmpIdxLeft;
        }
        // Right check
        tmpIdxRight   = (tmpMacHashRight << 2) + 1;
        if ( GET_BITS(DsMemMacValidRightVal->valid, GET_BITS(tmpIdxRight, 0, 4), GET_BITS(tmpIdxRight, 0, 4)) && (DsMemMacKeyRightVal->macAddr1 == tmpMacDa)
            && (DsMemMacKeyRightVal->vlanId1 == PI->fid) && (DsMemMacKeyRightVal->macAddrHi1 == tmpMacDaHi) ) {
            PI->macDaRValid     = 1;
            PI->macDaIdx      = tmpIdxRight;
        }
    }
    CtlLkpMngLog->macDaIdx = PI->macDaIdx;
    CtlLkpMngLog->aclIndex = PI->aclIndex;
    CtlLkpMngLog->routeHitTcam = PI->routeHitTcam;
    CtlLkpMngLog->ipRouteLookup = PI->ipRouteLookup;
    CtlLkpMngLog->routeHitNatTcam = PI->routeHitNatTcam;
    CtlLkpMngLog->hostRouteLeftHit = PI->hostRouteLeftHit;
    CtlLkpMngLog->hostRouteRightHit = PI->hostRouteRightHit;
    CtlLkpMngLog->aclResultValid = PI->aclResultValid;
    CtlLkpMngLog->ipv6AclLookup = PI->ipv6AclLookup;
    CtlLkpMngLog->ipRouteIdx = PI->ipRouteIdx;
    CtlLkpMngLog->ipv4AclLookup = PI->ipv4AclLookup;
    CtlLkpMngLog->macAclLookup = PI->macAclLookup;
    CtlLkpMngLog->macDaLeftValid = PI->macDaLeftValid;
    CtlLkpMngLog->macDaRightValid = PI->macDaRightValid;
}
