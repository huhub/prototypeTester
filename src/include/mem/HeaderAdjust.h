/*
 * Software Development Kit for Fisilink
 * @file: HeaderAdjust.h
 * @description: C language expression for HeaderAdjust module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __HEADERADJUST_REG__
#define __HEADERADJUST_REG__
#include <stdint.h>

/** Define C structure for CtlCommon */
typedef struct CtlCommon {
    uint32_t cpuPortNo            : 1;    ///< cpuPortNo field
    uint32_t cpuHdrEn             : 1;    ///< cpuHdrEn field
} __attribute__((aligned(sizeof(int)))) tCtlCommon;

/** Define C structure for CtlHdrAdjLog */
typedef struct CtlHdrAdjLog {
    uint32_t isTsn                : 1;    ///< isTsn field
    uint32_t discard              : 1;    ///< discard field
    uint32_t srcPort              : 1;    ///< srcPort field
    uint32_t pktLenLog            : 1;    ///< pktLenLog field
} __attribute__((aligned(sizeof(int)))) tCtlHdrAdjLog;

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

/** Define C structure for DsRegChnlAttr */
typedef struct DsRegChnlAttr {
    uint32_t portId               : 1;    ///< portId field
    uint32_t bypassPp             : 1;    ///< bypassPp field
    uint32_t destMap              : 1;    ///< destMap field
    uint32_t dot1qType            : 1;    ///< dot1qType field
} __attribute__((aligned(sizeof(int)))) tDsRegChnlAttr;

/** Define C structure for MsgAdmInfo */
typedef struct MsgAdmInfo {
} __attribute__((aligned(sizeof(int)))) tMsgAdmInfo;

#endif
