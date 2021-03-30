/*
 * Software Development Kit for Fisilink
 * @file: PacketEdit.h
 * @description: C language expression for PacketEdit module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __PACKETEDIT_REG__
#define __PACKETEDIT_REG__
#include <stdint.h>

/** Define C structure for PacketEditCtlCommon */
typedef struct PacketEditCtlCommon {
    uint32_t cpuPortNo            : 1;    ///< cpuPortNo field
} __attribute__((aligned(sizeof(int)))) tPacketEditCtlCommon;

/** Define C structure for CtlEgrCpu */
typedef struct CtlEgrCpu {
    uint32_t forbidEdit           : 1;    ///< forbidEdit field
    uint32_t needCpuHdr           : 1;    ///< needCpuHdr field
    uint32_t maxLength            : 1;    ///< maxLength field
} __attribute__((aligned(sizeof(int)))) tCtlEgrCpu;

/** Define C structure for CtlEgrDot1qTpid */
typedef struct CtlEgrDot1qTpid {
    uint32_t tpidOut              : 1;    ///< tpidOut field
} __attribute__((aligned(sizeof(int)))) tCtlEgrDot1qTpid;

/** Define C structure for CtlEgrEdit */
typedef struct CtlEgrEdit {
    uint32_t v4PtpUdpChksumSet0   : 1;    ///< v4PtpUdpChksumSet0 field
    uint32_t rtagTpid             : 1;    ///< rtagTpid field
    uint32_t rtagContent          : 1;    ///< rtagContent field
    uint32_t ptpUpdMacSaEn        : 1;    ///< ptpUpdMacSaEn field
    uint32_t ptpMacAddr           : 1;    ///< ptpMacAddr field
    uint32_t ptpMacAddrHi         : 1;    ///< ptpMacAddrHi field
    uint32_t updV6PtpUdpChksum    : 1;    ///< updV6PtpUdpChksum field
    uint32_t ptpDevType           : 1;    ///< ptpDevType field
    uint32_t cfMissedType         : 1;    ///< cfMissedType field
    uint32_t tsMissedType         : 1;    ///< tsMissedType field
} __attribute__((aligned(sizeof(int)))) tCtlEgrEdit;

/** Define C structure for CtlEgrExcpDestPort */
typedef struct CtlEgrExcpDestPort {
    uint32_t destPort             : 1;    ///< destPort field
    uint32_t excpAddCpuHdr        : 1;    ///< excpAddCpuHdr field
} __attribute__((aligned(sizeof(int)))) tCtlEgrExcpDestPort;

/** Define C structure for CtlEgrExt */
typedef struct CtlEgrExt {
    uint32_t extForbidEdit        : 1;    ///< extForbidEdit field
    uint32_t extNeedCpuHdr        : 1;    ///< extNeedCpuHdr field
    uint32_t extRemoteSpan        : 1;    ///< extRemoteSpan field
} __attribute__((aligned(sizeof(int)))) tCtlEgrExt;

/** Define C structure for CtlEgrLog */
typedef struct CtlEgrLog {
    uint32_t vlanId               : 1;    ///< vlanId field
    uint32_t excpType             : 1;    ///< excpType field
    uint32_t opCode               : 1;    ///< opCode field
    uint32_t egrDiscard           : 1;    ///< egrDiscard field
    uint32_t routedPkt            : 1;    ///< routedPkt field
    uint32_t removeCpuHdr         : 1;    ///< removeCpuHdr field
    uint32_t addCpuHdr            : 1;    ///< addCpuHdr field
    uint32_t updateMacDa          : 1;    ///< updateMacDa field
    uint32_t updateMacSa          : 1;    ///< updateMacSa field
    uint32_t removeVlanTag        : 1;    ///< removeVlanTag field
    uint32_t addVlanTag           : 1;    ///< addVlanTag field
    uint32_t remoteSpan           : 1;    ///< remoteSpan field
    uint32_t addRtag              : 1;    ///< addRtag field
    uint32_t replaceCos           : 1;    ///< replaceCos field
    uint32_t replaceDscp          : 1;    ///< replaceDscp field
    uint32_t egrStpChkFail        : 1;    ///< egrStpChkFail field
    uint32_t ptpPortTypeChkFail   : 1;    ///< ptpPortTypeChkFail field
    uint32_t ptpType              : 1;    ///< ptpType field
    uint32_t updPtpTs             : 1;    ///< updPtpTs field
    uint32_t updPtpCf             : 1;    ///< updPtpCf field
    uint32_t intrPtpTs            : 1;    ///< intrPtpTs field
    uint32_t xconErr              : 1;    ///< xconErr field
    uint32_t truncateCpuPkt       : 1;    ///< truncateCpuPkt field
} __attribute__((aligned(sizeof(int)))) tCtlEgrLog;

/** Define C structure for CtlEgrOam */
typedef struct CtlEgrOam {
    uint32_t oamObeyDiscard       : 1;    ///< oamObeyDiscard field
} __attribute__((aligned(sizeof(int)))) tCtlEgrOam;

/** Define C structure for CtlRemoteSpan */
typedef struct CtlRemoteSpan {
    uint32_t cosValid             : 1;    ///< cosValid field
    uint32_t cos                  : 1;    ///< cos field
    uint32_t tpid                 : 1;    ///< tpid field
    uint32_t vlanId               : 1;    ///< vlanId field
} __attribute__((aligned(sizeof(int)))) tCtlRemoteSpan;

/** Define C structure for CtlRouterPktMac */
typedef struct CtlRouterPktMac {
    uint32_t routerMac            : 1;    ///< routerMac field
    uint32_t routerMacHi          : 1;    ///< routerMacHi field
} __attribute__((aligned(sizeof(int)))) tCtlRouterPktMac;

/** Define C structure for DsMemTsnHandle */
typedef struct DsMemTsnHandle {
} __attribute__((aligned(sizeof(int)))) tDsMemTsnHandle;

/** Define C structure for DsMemDestPort */
typedef struct DsMemDestPort {
    uint32_t ptpEn                : 1;    ///< ptpEn field
    uint32_t specifyOutVid        : 1;    ///< specifyOutVid field
    uint32_t dot1qType            : 1;    ///< dot1qType field
    uint32_t replaceCos           : 1;    ///< replaceCos field
    uint32_t replaceDscp          : 1;    ///< replaceDscp field
    uint32_t ptpPortType          : 1;    ///< ptpPortType field
    uint32_t specifiedVlanId      : 1;    ///< specifiedVlanId field
    uint32_t portEthOamEn         : 1;    ///< portEthOamEn field
} __attribute__((aligned(sizeof(int)))) tDsMemDestPort;

/** Define C structure for DsMemDestStpState */
typedef struct DsMemDestStpState {
    uint32_t stpState             : 1;    ///< stpState field
} __attribute__((aligned(sizeof(int)))) tDsMemDestStpState;

/** Define C structure for DsMemDestVlan */
typedef struct DsMemDestVlan {
    uint32_t l3IfCheck            : 1;    ///< l3IfCheck field
    uint32_t mtuCheck             : 1;    ///< mtuCheck field
    uint32_t mtuSize              : 1;    ///< mtuSize field
    uint32_t untagPortBmp         : 1;    ///< untagPortBmp field
    uint32_t vlanEthOamEn         : 1;    ///< vlanEthOamEn field
} __attribute__((aligned(sizeof(int)))) tDsMemDestVlan;

/** Define C structure for DsMemEgrExcpStats */
typedef struct DsMemEgrExcpStats {
    uint32_t pktCnt               : 1;    ///< pktCnt field
    uint32_t byteCnt              : 1;    ///< byteCnt field
} __attribute__((aligned(sizeof(int)))) tDsMemEgrExcpStats;

/** Define C structure for DsMemEgrMepPtr */
typedef struct DsMemEgrMepPtr {
    uint32_t oamIdx               : 1;    ///< oamIdx field
} __attribute__((aligned(sizeof(int)))) tDsMemEgrMepPtr;

/** Define C structure for DsMemEgrOamKey */
typedef struct DsMemEgrOamKey {
    uint32_t key0                 : 1;    ///< key0 field
    uint32_t valid                : 1;    ///< valid field
    uint32_t key1                 : 1;    ///< key1 field
    uint32_t key2                 : 1;    ///< key2 field
    uint32_t key3                 : 1;    ///< key3 field
} __attribute__((aligned(sizeof(int)))) tDsMemEgrOamKey;

/** Define C structure for DsMemEgrOamSession */
typedef struct DsMemEgrOamSession {
    uint32_t mdlBmp               : 1;    ///< mdlBmp field
    uint32_t mepBasePtr           : 1;    ///< mepBasePtr field
} __attribute__((aligned(sizeof(int)))) tDsMemEgrOamSession;

/** Define C structure for DsMemEgrSrcPort */
typedef struct DsMemEgrSrcPort {
    uint32_t pDelay               : 1;    ///< pDelay field
} __attribute__((aligned(sizeof(int)))) tDsMemEgrSrcPort;

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

/** Define C structure for DsMemL3Mcast */
typedef struct DsMemL3Mcast {
    uint32_t nexthopIdx           : 1;    ///< nexthopIdx field
} __attribute__((aligned(sizeof(int)))) tDsMemL3Mcast;

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

/** Define C structure for DsMemNexthop */
typedef struct DsMemNexthop {
    uint32_t vlanId               : 1;    ///< vlanId field
    uint32_t ipSa                 : 1;    ///< ipSa field
    uint32_t l4SrcPort            : 1;    ///< l4SrcPort field
    uint32_t macDaHi              : 1;    ///< macDaHi field
    uint32_t macDa                : 1;    ///< macDa field
    uint32_t routerMacIdx         : 1;    ///< routerMacIdx field
} __attribute__((aligned(sizeof(int)))) tDsMemNexthop;

/** Define C structure for DsRegEgrPriorMap */
typedef struct DsRegEgrPriorMap {
    uint32_t dscp                 : 1;    ///< dscp field
    uint32_t cos                  : 1;    ///< cos field
} __attribute__((aligned(sizeof(int)))) tDsRegEgrPriorMap;

/** Define C structure for MsgAdmInfo */
typedef struct MsgAdmInfo {
} __attribute__((aligned(sizeof(int)))) tMsgAdmInfo;

#endif
