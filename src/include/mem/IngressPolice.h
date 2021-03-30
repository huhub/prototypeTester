/*
 * Software Development Kit for Fisilink
 * @file: IngressPolice.h
 * @description: C language expression for IngressPolice module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __INGRESSPOLICE_REG__
#define __INGRESSPOLICE_REG__
#include <stdint.h>

/** Define C structure for CtlCpuPolice */
typedef struct CtlCpuPolice {
    uint32_t policeEn             : 1;    ///< policeEn field
    uint32_t policePtrBase        : 1;    ///< policePtrBase field
} __attribute__((aligned(sizeof(int)))) tCtlCpuPolice;

/** Define C structure for CtlPolice */
typedef struct CtlPolice {
    uint32_t flowPoliceFirst      : 1;    ///< flowPoliceFirst field
    uint32_t sequentialPolicing   : 1;    ///< sequentialPolicing field
    uint32_t flowStatsEn          : 1;    ///< flowStatsEn field
    uint32_t flowStatsBase        : 1;    ///< flowStatsBase field
    uint32_t portStatsEn          : 1;    ///< portStatsEn field
    uint32_t portStatsBase        : 1;    ///< portStatsBase field
    uint32_t updateEn             : 1;    ///< updateEn field
    uint32_t portCurPtr           : 1;    ///< portCurPtr field
    uint32_t portUpdateIntv       : 1;    ///< portUpdateIntv field
    uint32_t portMaxPtr           : 1;    ///< portMaxPtr field
    uint32_t portMinPtr           : 1;    ///< portMinPtr field
    uint32_t portPerRndDelay      : 1;    ///< portPerRndDelay field
    uint32_t portCurRound         : 1;    ///< portCurRound field
    uint32_t portUpdRound         : 1;    ///< portUpdRound field
    uint32_t portFinalDelay       : 1;    ///< portFinalDelay field
    uint32_t flowCurPtr           : 1;    ///< flowCurPtr field
    uint32_t flowUpdateIntv       : 1;    ///< flowUpdateIntv field
    uint32_t flowMaxPtr           : 1;    ///< flowMaxPtr field
    uint32_t flowMinPtr           : 1;    ///< flowMinPtr field
    uint32_t flowPerRndDelay      : 1;    ///< flowPerRndDelay field
    uint32_t flowCurRound         : 1;    ///< flowCurRound field
    uint32_t flowUpdRound         : 1;    ///< flowUpdRound field
    uint32_t flowFinalDelay       : 1;    ///< flowFinalDelay field
} __attribute__((aligned(sizeof(int)))) tCtlPolice;

/** Define C structure for CtlPoliceLog */
typedef struct CtlPoliceLog {
    uint32_t policeDrop           : 1;    ///< policeDrop field
    uint32_t dropPktCnt           : 1;    ///< dropPktCnt field
    uint32_t portPoEn             : 1;    ///< portPoEn field
    uint32_t flowPoEn             : 1;    ///< flowPoEn field
    uint32_t portPoPtr            : 1;    ///< portPoPtr field
    uint32_t flowPoPtr            : 1;    ///< flowPoPtr field
    uint32_t chkSDUfailed         : 1;    ///< chkSDUfailed field
    uint32_t newColor             : 1;    ///< newColor field
} __attribute__((aligned(sizeof(int)))) tCtlPoliceLog;

/** Define C structure for DsMemTsnHandle */
typedef struct DsMemTsnHandle {
} __attribute__((aligned(sizeof(int)))) tDsMemTsnHandle;

/** Define C structure for DsMemColorStats */
typedef struct DsMemColorStats {
    uint32_t pktCnt               : 1;    ///< pktCnt field
    uint32_t byteCntHi            : 1;    ///< byteCntHi field
    uint32_t byteCntLo            : 1;    ///< byteCntLo field
} __attribute__((aligned(sizeof(int)))) tDsMemColorStats;

/** Define C structure for DsMemCpuPolicePtrMap */
typedef struct DsMemCpuPolicePtrMap {
    uint32_t policePtr            : 1;    ///< policePtr field
} __attribute__((aligned(sizeof(int)))) tDsMemCpuPolicePtrMap;

/** Define C structure for DsMemPolice */
typedef struct DsMemPolice {
} __attribute__((aligned(sizeof(int)))) tDsMemPolice;

/** Define C structure for DsMemPoliceCfg */
typedef struct DsMemPoliceCfg {
    uint32_t dropYellow           : 1;    ///< dropYellow field
    uint32_t markAllRed           : 1;    ///< markAllRed field
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

/** Define C structure for DsMemTsnPolice */
typedef struct DsMemTsnPolice {
    uint32_t policeIndex          : 1;    ///< policeIndex field
    uint32_t chkSDUen             : 1;    ///< chkSDUen field
    uint32_t maxSDU               : 1;    ///< maxSDU field
} __attribute__((aligned(sizeof(int)))) tDsMemTsnPolice;

/** Define C structure for MsgAdmInfo */
typedef struct MsgAdmInfo {
} __attribute__((aligned(sizeof(int)))) tMsgAdmInfo;

#endif
