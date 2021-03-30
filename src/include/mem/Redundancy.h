/*
 * Software Development Kit for Fisilink
 * @file: Redundancy.h
 * @description: C language expression for Redundancy module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __REDUNDANCY_REG__
#define __REDUNDANCY_REG__
#include <stdint.h>

/** Define C structure for CtlRcvy */
typedef struct CtlRcvy {
    uint32_t indvSeqResetEn       : 1;    ///< indvSeqResetEn field
    uint32_t indvDelayPerEntry    : 1;    ///< indvDelayPerEntry field
    uint32_t indvMinusCycle       : 1;    ///< indvMinusCycle field
    uint32_t mergeSeqResetEn      : 1;    ///< mergeSeqResetEn field
    uint32_t mergeDelayPerEntry   : 1;    ///< mergeDelayPerEntry field
    uint32_t mergeMinusCycle      : 1;    ///< mergeMinusCycle field
} __attribute__((aligned(sizeof(int)))) tCtlRcvy;

/** Define C structure for CtlRcvyLog */
typedef struct CtlRcvyLog {
    uint32_t tsnStreamId          : 1;    ///< tsnStreamId field
    uint32_t rtagSeq              : 1;    ///< rtagSeq field
    uint32_t discardIndv          : 1;    ///< discardIndv field
    uint32_t seqDeltaIndv         : 1;    ///< seqDeltaIndv field
    uint32_t discardMerg          : 1;    ///< discardMerg field
    uint32_t seqDeltaMerg         : 1;    ///< seqDeltaMerg field
} __attribute__((aligned(sizeof(int)))) tCtlRcvyLog;

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

/** Define C structure for DsMemHandle2StreamId */
typedef struct DsMemHandle2StreamId {
    uint32_t streamId             : 1;    ///< streamId field
} __attribute__((aligned(sizeof(int)))) tDsMemHandle2StreamId;

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
    uint32_t frerRcvyAlg          : 1;    ///< frerRcvyAlg field
} __attribute__((aligned(sizeof(int)))) tDsMemRcvyCfg;

/** Define C structure for DsMemRcvyCnt */
typedef struct DsMemRcvyCnt {
} __attribute__((aligned(sizeof(int)))) tDsMemRcvyCnt;

/** Define C structure for DsMemRcvySeq */
typedef struct DsMemRcvySeq {
    uint32_t takeAny              : 1;    ///< takeAny field
    uint32_t remainTicks          : 1;    ///< remainTicks field
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

/** Define C structure for MsgAdmInfo */
typedef struct MsgAdmInfo {
} __attribute__((aligned(sizeof(int)))) tMsgAdmInfo;

#endif
