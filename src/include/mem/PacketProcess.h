/*
 * Software Development Kit for Fisilink
 * @file: PacketProcess.h
 * @description: C language expression for PacketProcess module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __PACKETPROCESS_REG__
#define __PACKETPROCESS_REG__
#include <stdint.h>

/** Define C structure for CtlMacLearn */
typedef struct CtlMacLearn {
    uint32_t cpuLearnEn           : 1;    ///< cpuLearnEn field
    uint32_t cpuLearnNum          : 1;    ///< cpuLearnNum field
    uint32_t cpuFifoDepth         : 1;    ///< cpuFifoDepth field
    uint32_t cpuLrnNumThrd        : 1;    ///< cpuLrnNumThrd field
    uint32_t hwLearnNum           : 1;    ///< hwLearnNum field
    uint32_t hwFifoDepth          : 1;    ///< hwFifoDepth field
    uint32_t hwLrnNumThrd         : 1;    ///< hwLrnNumThrd field
} __attribute__((aligned(sizeof(int)))) tCtlMacLearn;

/** Define C structure for CtlPktProcLog */
typedef struct CtlPktProcLog {
    uint32_t cpuFifoFullNum       : 1;    ///< cpuFifoFullNum field
    uint32_t hwFifoFullNum        : 1;    ///< hwFifoFullNum field
    uint32_t aclQosLogEn          : 1;    ///< aclQosLogEn field
    uint32_t aclDiscard           : 1;    ///< aclDiscard field
    uint32_t routeDiscard         : 1;    ///< routeDiscard field
    uint32_t routeExcpDiscard     : 1;    ///< routeExcpDiscard field
    uint32_t routeProcess         : 1;    ///< routeProcess field
    uint32_t bridgeProcess        : 1;    ///< bridgeProcess field
    uint32_t destMacKnown         : 1;    ///< destMacKnown field
    uint32_t l2UcastSrcMatchDiscard : 1;    ///< l2UcastSrcMatchDiscard field
    uint32_t macDaDiscard         : 1;    ///< macDaDiscard field
    uint32_t igrStpCheckDiscard   : 1;    ///< igrStpCheckDiscard field
    uint32_t stormDrop            : 1;    ///< stormDrop field
    uint32_t lrnPortLockDiscard   : 1;    ///< lrnPortLockDiscard field
    uint32_t lrnNumExceedDiscard  : 1;    ///< lrnNumExceedDiscard field
    uint32_t isTsn                : 1;    ///< isTsn field
    uint32_t tsnHandle            : 1;    ///< tsnHandle field
    uint32_t igrFlowSpan          : 1;    ///< igrFlowSpan field
    uint32_t entryPend            : 1;    ///< entryPend field
} __attribute__((aligned(sizeof(int)))) tCtlPktProcLog;

/** Define C structure for CtlPpGapConfig */
typedef struct CtlPpGapConfig {
    uint32_t gapValue             : 1;    ///< gapValue field
} __attribute__((aligned(sizeof(int)))) tCtlPpGapConfig;

/** Define C structure for CtlStormCntl */
typedef struct CtlStormCntl {
    uint32_t enable               : 1;    ///< enable field
    uint32_t stormCurPtr          : 1;    ///< stormCurPtr field
    uint32_t stormInterval        : 1;    ///< stormInterval field
    uint32_t stormMaxPtr          : 1;    ///< stormMaxPtr field
    uint32_t stormMinPtr          : 1;    ///< stormMinPtr field
    uint32_t stormFinalDelay      : 1;    ///< stormFinalDelay field
    uint32_t stormCurRound        : 1;    ///< stormCurRound field
    uint32_t stormUpdRound        : 1;    ///< stormUpdRound field
} __attribute__((aligned(sizeof(int)))) tCtlStormCntl;

/** Define C structure for DsMemTsnHandle */
typedef struct DsMemTsnHandle {
} __attribute__((aligned(sizeof(int)))) tDsMemTsnHandle;

/** Define C structure for DsMemCustomFdb */
typedef struct DsMemCustomFdb {
    uint32_t isTsn                : 1;    ///< isTsn field
    uint32_t tsnHandle            : 1;    ///< tsnHandle field
    uint32_t flowPolicePtr        : 1;    ///< flowPolicePtr field
    uint32_t flowPoliceValid      : 1;    ///< flowPoliceValid field
    uint32_t flowStatsValid       : 1;    ///< flowStatsValid field
    uint32_t flowStatsPtr         : 1;    ///< flowStatsPtr field
    uint32_t destMap              : 1;    ///< destMap field
    uint32_t isMcast              : 1;    ///< isMcast field
    uint32_t mirrorEn             : 1;    ///< mirrorEn field
} __attribute__((aligned(sizeof(int)))) tDsMemCustomFdb;

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

/** Define C structure for DsMemMac */
typedef struct DsMemMac {
    uint32_t pending              : 1;    ///< pending field
    uint32_t flowPolicePtr        : 1;    ///< flowPolicePtr field
    uint32_t flowPoliceValid      : 1;    ///< flowPoliceValid field
    uint32_t flowStatsValid       : 1;    ///< flowStatsValid field
    uint32_t flowStatsPtr         : 1;    ///< flowStatsPtr field
    uint32_t destMap              : 1;    ///< destMap field
    uint32_t isMcast              : 1;    ///< isMcast field
    uint32_t mirrorEn             : 1;    ///< mirrorEn field
    uint32_t dstDiscard           : 1;    ///< dstDiscard field
    uint32_t copyToCpu            : 1;    ///< copyToCpu field
} __attribute__((aligned(sizeof(int)))) tDsMemMac;

/** Define C structure for DsMemMacAging */
typedef struct DsMemMacAging {
} __attribute__((aligned(sizeof(int)))) tDsMemMacAging;

/** Define C structure for DsMemMacKey */
typedef struct DsMemMacKey {
} __attribute__((aligned(sizeof(int)))) tDsMemMacKey;

/** Define C structure for DsMemMacStatic */
typedef struct DsMemMacStatic {
} __attribute__((aligned(sizeof(int)))) tDsMemMacStatic;

/** Define C structure for DsMemMacValid */
typedef struct DsMemMacValid {
} __attribute__((aligned(sizeof(int)))) tDsMemMacValid;

/** Define C structure for DsMemStorm */
typedef struct DsMemStorm {
    uint32_t runningCounter       : 1;    ///< runningCounter field
} __attribute__((aligned(sizeof(int)))) tDsMemStorm;

/** Define C structure for DsMemStormCtrl */
typedef struct DsMemStormCtrl {
    uint32_t stormCtrlEn          : 1;    ///< stormCtrlEn field
    uint32_t threshold            : 1;    ///< threshold field
    uint32_t usePktCount          : 1;    ///< usePktCount field
} __attribute__((aligned(sizeof(int)))) tDsMemStormCtrl;

/** Define C structure for DsRegPortLearnCtrl */
typedef struct DsRegPortLearnCtrl {
    uint32_t lock                 : 1;    ///< lock field
    uint32_t violationToCpu       : 1;    ///< violationToCpu field
    uint32_t maxMacNum            : 1;    ///< maxMacNum field
    uint32_t macNumLimitEn        : 1;    ///< macNumLimitEn field
    uint32_t lrnNumExceedDiscard  : 1;    ///< lrnNumExceedDiscard field
} __attribute__((aligned(sizeof(int)))) tDsRegPortLearnCtrl;

/** Define C structure for DsRegPortLearnNum */
typedef struct DsRegPortLearnNum {
    uint32_t learntMacNum         : 1;    ///< learntMacNum field
} __attribute__((aligned(sizeof(int)))) tDsRegPortLearnNum;

/** Define C structure for MsgAdmInfo */
typedef struct MsgAdmInfo {
} __attribute__((aligned(sizeof(int)))) tMsgAdmInfo;

#endif
