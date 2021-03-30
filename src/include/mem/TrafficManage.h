/*
 * Software Development Kit for Fisilink
 * @file: TrafficManage.h
 * @description: C language expression for TrafficManage module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __TRAFFICMANAGE_REG__
#define __TRAFFICMANAGE_REG__
#include <stdint.h>

/** Define C structure for CtlAdmLog */
typedef struct CtlAdmLog {
    uint32_t enqIpv               : 1;    ///< enqIpv field
    uint32_t gateState            : 1;    ///< gateState field
    uint32_t gateCloseCnt         : 1;    ///< gateCloseCnt field
    uint32_t tailDropCnt          : 1;    ///< tailDropCnt field
    uint32_t wredCnt              : 1;    ///< wredCnt field
} __attribute__((aligned(sizeof(int)))) tCtlAdmLog;

/** Define C structure for TrafficManageCtlCommon */
typedef struct TrafficManageCtlCommon {
    uint32_t cpuPortNo            : 1;    ///< cpuPortNo field
} __attribute__((aligned(sizeof(int)))) tTrafficManageCtlCommon;

/** Define C structure for CtlEnqCfg */
typedef struct CtlEnqCfg {
    uint32_t tsnEn                : 1;    ///< tsnEn field
    uint32_t gateOnly             : 1;    ///< gateOnly field
    uint32_t ipv                  : 1;    ///< ipv field
    uint32_t enqEnBmp             : 1;    ///< enqEnBmp field
} __attribute__((aligned(sizeof(int)))) tCtlEnqCfg;

/** Define C structure for CtlPtpTimerEn */
typedef struct CtlPtpTimerEn {
    uint32_t enable               : 1;    ///< enable field
} __attribute__((aligned(sizeof(int)))) tCtlPtpTimerEn;

/** Define C structure for CtlRepExtPort */
typedef struct CtlRepExtPort {
    uint32_t destPort             : 1;    ///< destPort field
} __attribute__((aligned(sizeof(int)))) tCtlRepExtPort;

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

/** Define C structure for DsMemTsnGate */
typedef struct DsMemTsnGate {
    uint32_t state0               : 1;    ///< state0 field
    uint32_t ipv0                 : 1;    ///< ipv0 field
    uint32_t state1               : 1;    ///< state1 field
    uint32_t ipv1                 : 1;    ///< ipv1 field
} __attribute__((aligned(sizeof(int)))) tDsMemTsnGate;

/** Define C structure for DsRegCpuPktPrior */
typedef struct DsRegCpuPktPrior {
    uint32_t prior                : 1;    ///< prior field
} __attribute__((aligned(sizeof(int)))) tDsRegCpuPktPrior;

/** Define C structure for DsRegPtpTimer */
typedef struct DsRegPtpTimer {
    uint32_t value                : 1;    ///< value field
} __attribute__((aligned(sizeof(int)))) tDsRegPtpTimer;

/** Define C structure for DsRegQueueDrop */
typedef struct DsRegQueueDrop {
    uint32_t tailDropSet          : 1;    ///< tailDropSet field
    uint32_t wredSet              : 1;    ///< wredSet field
} __attribute__((aligned(sizeof(int)))) tDsRegQueueDrop;

/** Define C structure for MsgAdmInfo */
typedef struct MsgAdmInfo {
} __attribute__((aligned(sizeof(int)))) tMsgAdmInfo;

#endif
