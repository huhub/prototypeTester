/*
 * Software Development Kit for Fisilink
 * @file: DestPost.h
 * @description: C language expression for DestPost module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __DESTPOST_REG__
#define __DESTPOST_REG__
#include <stdint.h>

/** Define C structure for DestPostCtlCommon */
typedef struct DestPostCtlCommon {
    uint32_t cpuPortNo            : 1;    ///< cpuPortNo field
} __attribute__((aligned(sizeof(int)))) tDestPostCtlCommon;

/** Define C structure for CtlCpuStats */
typedef struct CtlCpuStats {
    uint32_t statsEn              : 1;    ///< statsEn field
} __attribute__((aligned(sizeof(int)))) tCtlCpuStats;

/** Define C structure for CtlFwdDest */
typedef struct CtlFwdDest {
    uint32_t redirPtpType         : 1;    ///< redirPtpType field
    uint32_t ptpSnifferType       : 1;    ///< ptpSnifferType field
} __attribute__((aligned(sizeof(int)))) tCtlFwdDest;

/** Define C structure for CtlFwdEgressFilter */
typedef struct CtlFwdEgressFilter {
    uint32_t egrFilteringEn       : 1;    ///< egrFilteringEn field
} __attribute__((aligned(sizeof(int)))) tCtlFwdEgressFilter;

/** Define C structure for CtlFwdEgressSpan */
typedef struct CtlFwdEgressSpan {
    uint32_t l2EgrSpanEn          : 1;    ///< l2EgrSpanEn field
} __attribute__((aligned(sizeof(int)))) tCtlFwdEgressSpan;

/** Define C structure for CtlFwdExcp */
typedef struct CtlFwdExcp {
    uint32_t excepToCpu           : 1;    ///< excepToCpu field
} __attribute__((aligned(sizeof(int)))) tCtlFwdExcp;

/** Define C structure for CtlFwdLog */
typedef struct CtlFwdLog {
    uint32_t fwdBitmap            : 1;    ///< fwdBitmap field
    uint32_t fwdBitmapW1          : 1;    ///< fwdBitmapW1 field
    uint32_t vlanDiscard          : 1;    ///< vlanDiscard field
    uint32_t mcastFlood           : 1;    ///< mcastFlood field
    uint32_t destMap              : 1;    ///< destMap field
    uint32_t opCode               : 1;    ///< opCode field
    uint32_t ucastFlood           : 1;    ///< ucastFlood field
    uint32_t criticalPacket       : 1;    ///< criticalPacket field
    uint32_t forbidEdit           : 1;    ///< forbidEdit field
    uint32_t redirPtp             : 1;    ///< redirPtp field
    uint32_t egrPortFilted        : 1;    ///< egrPortFilted field
    uint32_t egrVlanFilted        : 1;    ///< egrVlanFilted field
    uint32_t lagFilted            : 1;    ///< lagFilted field
    uint32_t ptpValid             : 1;    ///< ptpValid field
    uint32_t ptp2Cpu              : 1;    ///< ptp2Cpu field
    uint32_t addRtag              : 1;    ///< addRtag field
    uint32_t tsnGateId            : 1;    ///< tsnGateId field
    uint32_t tsnCycle             : 1;    ///< tsnCycle field
    uint32_t cpuPktType           : 1;    ///< cpuPktType field
    uint32_t destLostInCfg        : 1;    ///< destLostInCfg field
} __attribute__((aligned(sizeof(int)))) tCtlFwdLog;

/** Define C structure for CtlFwdMcast */
typedef struct CtlFwdMcast {
    uint32_t mcFilteringEn        : 1;    ///< mcFilteringEn field
    uint32_t mcastExcludeSrc      : 1;    ///< mcastExcludeSrc field
} __attribute__((aligned(sizeof(int)))) tCtlFwdMcast;

/** Define C structure for CtlFwdPortIsolate */
typedef struct CtlFwdPortIsolate {
    uint32_t vlanId               : 1;    ///< vlanId field
    uint32_t forcePortEgressMask  : 1;    ///< forcePortEgressMask field
} __attribute__((aligned(sizeof(int)))) tCtlFwdPortIsolate;

/** Define C structure for CtlFwdUnknownFilter */
typedef struct CtlFwdUnknownFilter {
    uint32_t bcastFilter          : 1;    ///< bcastFilter field
    uint32_t unknownMcastFilter   : 1;    ///< unknownMcastFilter field
    uint32_t unknownUcastFilter   : 1;    ///< unknownUcastFilter field
} __attribute__((aligned(sizeof(int)))) tCtlFwdUnknownFilter;

/** Define C structure for DsMemTsnHandle */
typedef struct DsMemTsnHandle {
} __attribute__((aligned(sizeof(int)))) tDsMemTsnHandle;

/** Define C structure for DsMemCpuStats */
typedef struct DsMemCpuStats {
    uint32_t pktCnt               : 1;    ///< pktCnt field
    uint32_t byteCntHi            : 1;    ///< byteCntHi field
    uint32_t byteCnt              : 1;    ///< byteCnt field
} __attribute__((aligned(sizeof(int)))) tDsMemCpuStats;

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

/** Define C structure for DsMemMcastPort */
typedef struct DsMemMcastPort {
    uint32_t portMask             : 1;    ///< portMask field
    uint32_t applyVlanMask        : 1;    ///< applyVlanMask field
} __attribute__((aligned(sizeof(int)))) tDsMemMcastPort;

/** Define C structure for DsMemSrcPortEgressMask */
typedef struct DsMemSrcPortEgressMask {
    uint32_t portEgressMask       : 1;    ///< portEgressMask field
} __attribute__((aligned(sizeof(int)))) tDsMemSrcPortEgressMask;

/** Define C structure for DsMemTsnEdit */
typedef struct DsMemTsnEdit {
    uint32_t genSeqNum            : 1;    ///< genSeqNum field
} __attribute__((aligned(sizeof(int)))) tDsMemTsnEdit;

/** Define C structure for DsMemTsnSpec */
typedef struct DsMemTsnSpec {
    uint32_t gateId               : 1;    ///< gateId field
    uint32_t cycleSel             : 1;    ///< cycleSel field
    uint32_t prior                : 1;    ///< prior field
    uint32_t addRtag              : 1;    ///< addRtag field
} __attribute__((aligned(sizeof(int)))) tDsMemTsnSpec;

/** Define C structure for DsMemTsnSplit */
typedef struct DsMemTsnSplit {
    uint32_t destBmp              : 1;    ///< destBmp field
} __attribute__((aligned(sizeof(int)))) tDsMemTsnSplit;

/** Define C structure for DsMemVlanPortMask */
typedef struct DsMemVlanPortMask {
    uint32_t portMask             : 1;    ///< portMask field
} __attribute__((aligned(sizeof(int)))) tDsMemVlanPortMask;

/** Define C structure for DsRegDestPortChnlMap */
typedef struct DsRegDestPortChnlMap {
    uint32_t channelId            : 1;    ///< channelId field
} __attribute__((aligned(sizeof(int)))) tDsRegDestPortChnlMap;

/** Define C structure for DsRegLagGrp */
typedef struct DsRegLagGrp {
    uint32_t memberBitmap         : 1;    ///< memberBitmap field
    uint32_t linkNumber           : 1;    ///< linkNumber field
    uint32_t srcMatchDiscard      : 1;    ///< srcMatchDiscard field
} __attribute__((aligned(sizeof(int)))) tDsRegLagGrp;

/** Define C structure for DsRegLagPort */
typedef struct DsRegLagPort {
    uint32_t destPort             : 1;    ///< destPort field
} __attribute__((aligned(sizeof(int)))) tDsRegLagPort;

/** Define C structure for MsgAdmInfo */
typedef struct MsgAdmInfo {
} __attribute__((aligned(sizeof(int)))) tMsgAdmInfo;

#endif
