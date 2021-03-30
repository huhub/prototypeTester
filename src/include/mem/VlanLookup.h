/*
 * Software Development Kit for Fisilink
 * @file: VlanLookup.h
 * @description: C language expression for VlanLookup module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __VLANLOOKUP_REG__
#define __VLANLOOKUP_REG__
#include <stdint.h>

/** Define C structure for VlanLookupCtlCommon */
typedef struct VlanLookupCtlCommon {
    uint32_t ofPortNo             : 1;    ///< ofPortNo field
    uint32_t cpuPortNo            : 1;    ///< cpuPortNo field
} __attribute__((aligned(sizeof(int)))) tVlanLookupCtlCommon;

/** Define C structure for CtlProtocolVlanKey */
typedef struct CtlProtocolVlanKey {
    uint32_t entryValid           : 1;    ///< entryValid field
    uint32_t protoData0           : 1;    ///< protoData0 field
    uint32_t protoMask0           : 1;    ///< protoMask0 field
    uint32_t protoData1           : 1;    ///< protoData1 field
    uint32_t protoMask1           : 1;    ///< protoMask1 field
    uint32_t protoData2           : 1;    ///< protoData2 field
    uint32_t protoMask2           : 1;    ///< protoMask2 field
    uint32_t protoData3           : 1;    ///< protoData3 field
    uint32_t protoMask3           : 1;    ///< protoMask3 field
    uint32_t protoData4           : 1;    ///< protoData4 field
    uint32_t protoMask4           : 1;    ///< protoMask4 field
    uint32_t protoData5           : 1;    ///< protoData5 field
    uint32_t protoMask5           : 1;    ///< protoMask5 field
    uint32_t protoData6           : 1;    ///< protoData6 field
    uint32_t protoMask6           : 1;    ///< protoMask6 field
    uint32_t protoData7           : 1;    ///< protoData7 field
    uint32_t protoMask7           : 1;    ///< protoMask7 field
} __attribute__((aligned(sizeof(int)))) tCtlProtocolVlanKey;

/** Define C structure for CtlVlanLookupLog */
typedef struct CtlVlanLookupLog {
    uint32_t vlanLkpRslt          : 1;    ///< vlanLkpRslt field
    uint32_t eapolDiscard         : 1;    ///< eapolDiscard field
    uint32_t dot1xDiscard         : 1;    ///< dot1xDiscard field
    uint32_t chkMacSaFail         : 1;    ///< chkMacSaFail field
    uint32_t ptpDiscard           : 1;    ///< ptpDiscard field
    uint32_t ipSubnetVlanValid    : 1;    ///< ipSubnetVlanValid field
    uint32_t macBasedVlanValid    : 1;    ///< macBasedVlanValid field
    uint32_t protocolVlanValid    : 1;    ///< protocolVlanValid field
    uint32_t isTsn                : 1;    ///< isTsn field
    uint32_t ptpEn                : 1;    ///< ptpEn field
} __attribute__((aligned(sizeof(int)))) tCtlVlanLookupLog;

/** Define C structure for DsMemTsnHandle */
typedef struct DsMemTsnHandle {
} __attribute__((aligned(sizeof(int)))) tDsMemTsnHandle;

/** Define C structure for DsMemColorStats */
typedef struct DsMemColorStats {
} __attribute__((aligned(sizeof(int)))) tDsMemColorStats;

/** Define C structure for DsMemPolice */
typedef struct DsMemPolice {
} __attribute__((aligned(sizeof(int)))) tDsMemPolice;

/** Define C structure for DsMemPoliceCfg */
typedef struct DsMemPoliceCfg {
} __attribute__((aligned(sizeof(int)))) tDsMemPoliceCfg;

/** Define C structure for DsMemRoute */
typedef struct DsMemRoute {
} __attribute__((aligned(sizeof(int)))) tDsMemRoute;

/** Define C structure for DsMemHostRouteKey */
typedef struct DsMemHostRouteKey {
} __attribute__((aligned(sizeof(int)))) tDsMemHostRouteKey;

/** Define C structure for DsMemHostRouteValid */
typedef struct DsMemHostRouteValid {
} __attribute__((aligned(sizeof(int)))) tDsMemHostRouteValid;

/** Define C structure for DsMemRcvyCfg */
typedef struct DsMemRcvyCfg {
} __attribute__((aligned(sizeof(int)))) tDsMemRcvyCfg;

/** Define C structure for DsMemRcvyCnt */
typedef struct DsMemRcvyCnt {
} __attribute__((aligned(sizeof(int)))) tDsMemRcvyCnt;

/** Define C structure for DsMemRcvySeq */
typedef struct DsMemRcvySeq {
} __attribute__((aligned(sizeof(int)))) tDsMemRcvySeq;

/** Define C structure for DsMemMacAging */
typedef struct DsMemMacAging {
} __attribute__((aligned(sizeof(int)))) tDsMemMacAging;

/** Define C structure for DsMemMacBasedVlanKey */
typedef struct DsMemMacBasedVlanKey {
    uint32_t entryValid           : 1;    ///< entryValid field
    uint32_t macSa0               : 1;    ///< macSa0 field
    uint32_t macSaHi0             : 1;    ///< macSaHi0 field
    uint32_t macSa1               : 1;    ///< macSa1 field
    uint32_t macSaHi1             : 1;    ///< macSaHi1 field
    uint32_t macSa2               : 1;    ///< macSa2 field
    uint32_t macSaHi2             : 1;    ///< macSaHi2 field
    uint32_t macSa3               : 1;    ///< macSa3 field
    uint32_t macSaHi3             : 1;    ///< macSaHi3 field
} __attribute__((aligned(sizeof(int)))) tDsMemMacBasedVlanKey;

/** Define C structure for DsMemMacKey */
typedef struct DsMemMacKey {
} __attribute__((aligned(sizeof(int)))) tDsMemMacKey;

/** Define C structure for DsMemMac */
typedef struct DsMemMac {
} __attribute__((aligned(sizeof(int)))) tDsMemMac;

/** Define C structure for DsMemMacStatic */
typedef struct DsMemMacStatic {
} __attribute__((aligned(sizeof(int)))) tDsMemMacStatic;

/** Define C structure for DsMemMacValid */
typedef struct DsMemMacValid {
} __attribute__((aligned(sizeof(int)))) tDsMemMacValid;

/** Define C structure for DsMemPhyPort */
typedef struct DsMemPhyPort {
    uint32_t logicalPort          : 1;    ///< logicalPort field
    uint32_t dot1xEn              : 1;    ///< dot1xEn field
    uint32_t dot1xDrop            : 1;    ///< dot1xDrop field
    uint32_t avAsTsn              : 1;    ///< avAsTsn field
    uint32_t ptpEn                : 1;    ///< ptpEn field
    uint32_t ptpPortType          : 1;    ///< ptpPortType field
    uint32_t macBasedVlanEn       : 1;    ///< macBasedVlanEn field
    uint32_t protocolVlanEn       : 1;    ///< protocolVlanEn field
} __attribute__((aligned(sizeof(int)))) tDsMemPhyPort;

/** Define C structure for MsgAdmInfo */
typedef struct MsgAdmInfo {
} __attribute__((aligned(sizeof(int)))) tMsgAdmInfo;

#endif
