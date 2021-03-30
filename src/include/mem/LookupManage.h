/*
 * Software Development Kit for Fisilink
 * @file: LookupManage.h
 * @description: C language expression for LookupManage module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __LOOKUPMANAGE_REG__
#define __LOOKUPMANAGE_REG__
#include <stdint.h>

/** Define C structure for CtlLkpMngLog */
typedef struct CtlLkpMngLog {
    uint32_t macDaIdx             : 1;    ///< macDaIdx field
    uint32_t aclIndex             : 1;    ///< aclIndex field
    uint32_t routeHitTcam         : 1;    ///< routeHitTcam field
    uint32_t ipRouteLookup        : 1;    ///< ipRouteLookup field
    uint32_t routeHitNatTcam      : 1;    ///< routeHitNatTcam field
    uint32_t hostRouteLeftHit     : 1;    ///< hostRouteLeftHit field
    uint32_t hostRouteRightHit    : 1;    ///< hostRouteRightHit field
    uint32_t aclResultValid       : 1;    ///< aclResultValid field
    uint32_t ipv6AclLookup        : 1;    ///< ipv6AclLookup field
    uint32_t ipRouteIdx           : 1;    ///< ipRouteIdx field
    uint32_t ipv4AclLookup        : 1;    ///< ipv4AclLookup field
    uint32_t macAclLookup         : 1;    ///< macAclLookup field
    uint32_t macDaLeftValid       : 1;    ///< macDaLeftValid field
    uint32_t macDaRightValid      : 1;    ///< macDaRightValid field
} __attribute__((aligned(sizeof(int)))) tCtlLkpMngLog;

/** Define C structure for CtlLkupCfg */
typedef struct CtlLkupCfg {
    uint32_t macDaKeyEn           : 1;    ///< macDaKeyEn field
    uint32_t macPcpKeyEn          : 1;    ///< macPcpKeyEn field
    uint32_t ipDscpKeyEn          : 1;    ///< ipDscpKeyEn field
    uint32_t ipSportKeyEn         : 1;    ///< ipSportKeyEn field
    uint32_t ipDportKeyEn         : 1;    ///< ipDportKeyEn field
} __attribute__((aligned(sizeof(int)))) tCtlLkupCfg;

/** Define C structure for DsMemTsnHandle */
typedef struct DsMemTsnHandle {
} __attribute__((aligned(sizeof(int)))) tDsMemTsnHandle;

/** Define C structure for DsMemCuIpDportKeyL */
typedef struct DsMemCuIpDportKeyL {
    uint32_t valid                : 1;    ///< valid field
    uint32_t l3Next0              : 1;    ///< l3Next0 field
    uint32_t l4DestPort           : 1;    ///< l4DestPort field
    uint32_t ipAddr3              : 1;    ///< ipAddr3 field
    uint32_t ipAddr2              : 1;    ///< ipAddr2 field
    uint32_t ipAddr1              : 1;    ///< ipAddr1 field
    uint32_t ipAddr0              : 1;    ///< ipAddr0 field
    uint32_t l4DestPort0          : 1;    ///< l4DestPort0 field
    uint32_t l3Next1              : 1;    ///< l3Next1 field
    uint32_t l4DestPort1          : 1;    ///< l4DestPort1 field
    uint32_t l3Next2              : 1;    ///< l3Next2 field
    uint32_t l4DestPort2          : 1;    ///< l4DestPort2 field
    uint32_t l3Next3              : 1;    ///< l3Next3 field
    uint32_t l4DestPort3          : 1;    ///< l4DestPort3 field
} __attribute__((aligned(sizeof(int)))) tDsMemCuIpDportKeyL;

/** Define C structure for DsMemCuIpDportKeyR */
typedef struct DsMemCuIpDportKeyR {
    uint32_t valid                : 1;    ///< valid field
    uint32_t valid                : 1;    ///< valid field
    uint32_t l4DestPort           : 1;    ///< l4DestPort field
    uint32_t ipAddr3              : 1;    ///< ipAddr3 field
    uint32_t ipAddr2              : 1;    ///< ipAddr2 field
    uint32_t ipAddr1              : 1;    ///< ipAddr1 field
    uint32_t ipAddr0              : 1;    ///< ipAddr0 field
    uint32_t l3Next0              : 1;    ///< l3Next0 field
    uint32_t l4DestPort0          : 1;    ///< l4DestPort0 field
    uint32_t l3Next1              : 1;    ///< l3Next1 field
    uint32_t l4DestPort1          : 1;    ///< l4DestPort1 field
    uint32_t l3Next2              : 1;    ///< l3Next2 field
    uint32_t l4DestPort2          : 1;    ///< l4DestPort2 field
    uint32_t l3Next3              : 1;    ///< l3Next3 field
    uint32_t l4DestPort3          : 1;    ///< l4DestPort3 field
} __attribute__((aligned(sizeof(int)))) tDsMemCuIpDportKeyR;

/** Define C structure for DsMemCuIpDscpKeyL */
typedef struct DsMemCuIpDscpKeyL {
    uint32_t valid                : 1;    ///< valid field
    uint32_t dscp0                : 1;    ///< dscp0 field
    uint32_t ipAddr3              : 1;    ///< ipAddr3 field
    uint32_t ipAddr2              : 1;    ///< ipAddr2 field
    uint32_t ipAddr1              : 1;    ///< ipAddr1 field
    uint32_t ipAddr0              : 1;    ///< ipAddr0 field
    uint32_t dscp1                : 1;    ///< dscp1 field
    uint32_t dscp2                : 1;    ///< dscp2 field
    uint32_t dscp3                : 1;    ///< dscp3 field
} __attribute__((aligned(sizeof(int)))) tDsMemCuIpDscpKeyL;

/** Define C structure for DsMemCuIpDscpKeyR */
typedef struct DsMemCuIpDscpKeyR {
    uint32_t valid                : 1;    ///< valid field
    uint32_t dscp0                : 1;    ///< dscp0 field
    uint32_t ipAddr3              : 1;    ///< ipAddr3 field
    uint32_t ipAddr2              : 1;    ///< ipAddr2 field
    uint32_t ipAddr1              : 1;    ///< ipAddr1 field
    uint32_t ipAddr0              : 1;    ///< ipAddr0 field
    uint32_t macAddr0             : 1;    ///< macAddr0 field
    uint32_t macAddr1             : 1;    ///< macAddr1 field
    uint32_t dscp1                : 1;    ///< dscp1 field
    uint32_t macAddr2             : 1;    ///< macAddr2 field
    uint32_t dscp2                : 1;    ///< dscp2 field
    uint32_t macAddr3             : 1;    ///< macAddr3 field
    uint32_t dscp3                : 1;    ///< dscp3 field
} __attribute__((aligned(sizeof(int)))) tDsMemCuIpDscpKeyR;

/** Define C structure for DsMemCuIpSportKeyL */
typedef struct DsMemCuIpSportKeyL {
    uint32_t valid                : 1;    ///< valid field
    uint32_t l3Next0              : 1;    ///< l3Next0 field
    uint32_t l4SrcPort            : 1;    ///< l4SrcPort field
    uint32_t ipAddr3              : 1;    ///< ipAddr3 field
    uint32_t ipAddr2              : 1;    ///< ipAddr2 field
    uint32_t ipAddr1              : 1;    ///< ipAddr1 field
    uint32_t ipAddr0              : 1;    ///< ipAddr0 field
    uint32_t l4SrcPort0           : 1;    ///< l4SrcPort0 field
    uint32_t l3Next1              : 1;    ///< l3Next1 field
    uint32_t l4SrcPort1           : 1;    ///< l4SrcPort1 field
    uint32_t l3Next2              : 1;    ///< l3Next2 field
    uint32_t l4SrcPort2           : 1;    ///< l4SrcPort2 field
    uint32_t l3Next3              : 1;    ///< l3Next3 field
    uint32_t l4SrcPort3           : 1;    ///< l4SrcPort3 field
} __attribute__((aligned(sizeof(int)))) tDsMemCuIpSportKeyL;

/** Define C structure for DsMemCuIpSportKeyR */
typedef struct DsMemCuIpSportKeyR {
    uint32_t valid                : 1;    ///< valid field
    uint32_t valid                : 1;    ///< valid field
    uint32_t l4SrcPort            : 1;    ///< l4SrcPort field
    uint32_t ipAddr3              : 1;    ///< ipAddr3 field
    uint32_t ipAddr2              : 1;    ///< ipAddr2 field
    uint32_t ipAddr1              : 1;    ///< ipAddr1 field
    uint32_t ipAddr0              : 1;    ///< ipAddr0 field
    uint32_t l3Next0              : 1;    ///< l3Next0 field
    uint32_t l4SrcPort0           : 1;    ///< l4SrcPort0 field
    uint32_t l3Next1              : 1;    ///< l3Next1 field
    uint32_t l4SrcPort1           : 1;    ///< l4SrcPort1 field
    uint32_t l3Next2              : 1;    ///< l3Next2 field
    uint32_t l4SrcPort2           : 1;    ///< l4SrcPort2 field
    uint32_t l3Next3              : 1;    ///< l3Next3 field
    uint32_t l4SrcPort3           : 1;    ///< l4SrcPort3 field
} __attribute__((aligned(sizeof(int)))) tDsMemCuIpSportKeyR;

/** Define C structure for DsMemCuMacKeyL */
typedef struct DsMemCuMacKeyL {
    uint32_t valid                : 1;    ///< valid field
    uint32_t macAddr0             : 1;    ///< macAddr0 field
    uint32_t macAddrHi0           : 1;    ///< macAddrHi0 field
    uint32_t macAddr1             : 1;    ///< macAddr1 field
    uint32_t macAddrHi1           : 1;    ///< macAddrHi1 field
} __attribute__((aligned(sizeof(int)))) tDsMemCuMacKeyL;

/** Define C structure for DsMemCuMacKeyR */
typedef struct DsMemCuMacKeyR {
    uint32_t valid                : 1;    ///< valid field
    uint32_t macAddr0             : 1;    ///< macAddr0 field
    uint32_t macAddrHi0           : 1;    ///< macAddrHi0 field
    uint32_t macAddr1             : 1;    ///< macAddr1 field
    uint32_t macAddrHi1           : 1;    ///< macAddrHi1 field
} __attribute__((aligned(sizeof(int)))) tDsMemCuMacKeyR;

/** Define C structure for DsMemCuMacPcpKeyL */
typedef struct DsMemCuMacPcpKeyL {
    uint32_t valid                : 1;    ///< valid field
    uint32_t macAddr0             : 1;    ///< macAddr0 field
    uint32_t macAddrHi0           : 1;    ///< macAddrHi0 field
    uint32_t pcp0                 : 1;    ///< pcp0 field
    uint32_t macAddr1             : 1;    ///< macAddr1 field
    uint32_t macAddrHi1           : 1;    ///< macAddrHi1 field
    uint32_t pcp1                 : 1;    ///< pcp1 field
} __attribute__((aligned(sizeof(int)))) tDsMemCuMacPcpKeyL;

/** Define C structure for DsMemCuMacPcpKeyR */
typedef struct DsMemCuMacPcpKeyR {
    uint32_t valid                : 1;    ///< valid field
    uint32_t macAddr0             : 1;    ///< macAddr0 field
    uint32_t macAddrHi0           : 1;    ///< macAddrHi0 field
    uint32_t macAddr1             : 1;    ///< macAddr1 field
    uint32_t macAddrHi1           : 1;    ///< macAddrHi1 field
} __attribute__((aligned(sizeof(int)))) tDsMemCuMacPcpKeyR;

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
    uint32_t isValid              : 1;    ///< isValid field
    uint32_t isIpv6               : 1;    ///< isIpv6 field
    uint32_t ipAddrF3             : 1;    ///< ipAddrF3 field
    uint32_t ipAddrF2             : 1;    ///< ipAddrF2 field
    uint32_t ipAddrF1             : 1;    ///< ipAddrF1 field
    uint32_t ipAddrF0             : 1;    ///< ipAddrF0 field
    uint32_t isIpv6F              : 1;    ///< isIpv6F field
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

/** Define C structure for DsMemMacKey */
typedef struct DsMemMacKey {
    uint32_t macAddr0             : 1;    ///< macAddr0 field
    uint32_t vlanId0              : 1;    ///< vlanId0 field
    uint32_t macAddrHi0           : 1;    ///< macAddrHi0 field
    uint32_t macAddr1             : 1;    ///< macAddr1 field
    uint32_t vlanId1              : 1;    ///< vlanId1 field
    uint32_t macAddrHi1           : 1;    ///< macAddrHi1 field
} __attribute__((aligned(sizeof(int)))) tDsMemMacKey;

/** Define C structure for DsMemMac */
typedef struct DsMemMac {
} __attribute__((aligned(sizeof(int)))) tDsMemMac;

/** Define C structure for DsMemMacStatic */
typedef struct DsMemMacStatic {
} __attribute__((aligned(sizeof(int)))) tDsMemMacStatic;

/** Define C structure for DsMemMacValid */
typedef struct DsMemMacValid {
    uint32_t valid                : 1;    ///< valid field
} __attribute__((aligned(sizeof(int)))) tDsMemMacValid;

/** Define C structure for MsgAdmInfo */
typedef struct MsgAdmInfo {
} __attribute__((aligned(sizeof(int)))) tMsgAdmInfo;

#endif
