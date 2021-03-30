/*
 * Software Development Kit for Fisilink
 * @file: Interface.h
 * @description: C language expression for Interface module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __INTERFACE_REG__
#define __INTERFACE_REG__
#include <stdint.h>

/** Define C structure for InterfaceCtlCommon */
typedef struct InterfaceCtlCommon {
    uint32_t cpuPortNo            : 1;    ///< cpuPortNo field
} __attribute__((aligned(sizeof(int)))) tInterfaceCtlCommon;

/** Define C structure for CtlCosMapPrior */
typedef struct CtlCosMapPrior {
    uint32_t cosPrior             : 1;    ///< cosPrior field
} __attribute__((aligned(sizeof(int)))) tCtlCosMapPrior;

/** Define C structure for CtlDscpMapPrior */
typedef struct CtlDscpMapPrior {
    uint32_t dscpPrior            : 1;    ///< dscpPrior field
} __attribute__((aligned(sizeof(int)))) tCtlDscpMapPrior;

/** Define C structure for CtlIntfBpduMac */
typedef struct CtlIntfBpduMac {
    uint32_t sBpduMac             : 1;    ///< sBpduMac field
    uint32_t sBpduMacHi           : 1;    ///< sBpduMacHi field
    uint32_t cBpduMac             : 1;    ///< cBpduMac field
    uint32_t cBpduMacHi           : 1;    ///< cBpduMacHi field
} __attribute__((aligned(sizeof(int)))) tCtlIntfBpduMac;

/** Define C structure for CtlIntfMapLog */
typedef struct CtlIntfMapLog {
    uint32_t aftDiscard           : 1;    ///< aftDiscard field
    uint32_t vlanId               : 1;    ///< vlanId field
    uint32_t cos                  : 1;    ///< cos field
    uint32_t dscp                 : 1;    ///< dscp field
    uint32_t prior                : 1;    ///< prior field
    uint32_t isUcastIp            : 1;    ///< isUcastIp field
    uint32_t isMcastIp            : 1;    ///< isMcastIp field
    uint32_t isMcastMac           : 1;    ///< isMcastMac field
    uint32_t routingEn            : 1;    ///< routingEn field
    uint32_t cpuPktType           : 1;    ///< cpuPktType field
    uint32_t stpIdx               : 1;    ///< stpIdx field
    uint32_t isBpdu               : 1;    ///< isBpdu field
    uint32_t stpState             : 1;    ///< stpState field
    uint32_t tsnEn                : 1;    ///< tsnEn field
    uint32_t mcVlanDrop           : 1;    ///< mcVlanDrop field
} __attribute__((aligned(sizeof(int)))) tCtlIntfMapLog;

/** Define C structure for CtlIpPrecdncMapPrior */
typedef struct CtlIpPrecdncMapPrior {
    uint32_t precPrior            : 1;    ///< precPrior field
} __attribute__((aligned(sizeof(int)))) tCtlIpPrecdncMapPrior;

/** Define C structure for CtlManageVlan */
typedef struct CtlManageVlan {
    uint32_t vlanId0              : 1;    ///< vlanId0 field
    uint32_t vlanId1              : 1;    ///< vlanId1 field
    uint32_t rmtVlanId            : 1;    ///< rmtVlanId field
} __attribute__((aligned(sizeof(int)))) tCtlManageVlan;

/** Define C structure for CtlRouterMac */
typedef struct CtlRouterMac {
    uint32_t routerMac0           : 1;    ///< routerMac0 field
    uint32_t routerMacHi0         : 1;    ///< routerMacHi0 field
    uint32_t routerMac1           : 1;    ///< routerMac1 field
    uint32_t routerMacHi1         : 1;    ///< routerMacHi1 field
    uint32_t routerMac2           : 1;    ///< routerMac2 field
    uint32_t routerMacHi2         : 1;    ///< routerMacHi2 field
    uint32_t routerMac3           : 1;    ///< routerMac3 field
    uint32_t routerMacHi3         : 1;    ///< routerMacHi3 field
} __attribute__((aligned(sizeof(int)))) tCtlRouterMac;

/** Define C structure for CtlTsnFunc */
typedef struct CtlTsnFunc {
    uint32_t enable               : 1;    ///< enable field
} __attribute__((aligned(sizeof(int)))) tCtlTsnFunc;

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

/** Define C structure for DsMemMacBasedVlan */
typedef struct DsMemMacBasedVlan {
    uint32_t replaceVlan          : 1;    ///< replaceVlan field
    uint32_t vlanId               : 1;    ///< vlanId field
    uint32_t replaceCos           : 1;    ///< replaceCos field
    uint32_t cos                  : 1;    ///< cos field
    uint32_t replaceDscp          : 1;    ///< replaceDscp field
    uint32_t dscp                 : 1;    ///< dscp field
} __attribute__((aligned(sizeof(int)))) tDsMemMacBasedVlan;

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

/** Define C structure for DsMemProtocolVlan */
typedef struct DsMemProtocolVlan {
    uint32_t replaceVlan          : 1;    ///< replaceVlan field
    uint32_t vlanId               : 1;    ///< vlanId field
    uint32_t replaceCos           : 1;    ///< replaceCos field
    uint32_t cos                  : 1;    ///< cos field
    uint32_t replaceDscp          : 1;    ///< replaceDscp field
    uint32_t dscp                 : 1;    ///< dscp field
} __attribute__((aligned(sizeof(int)))) tDsMemProtocolVlan;

/** Define C structure for DsMemSrcPort */
typedef struct DsMemSrcPort {
    uint32_t defaultVlanId        : 1;    ///< defaultVlanId field
    uint32_t l2AclLabel           : 1;    ///< l2AclLabel field
    uint32_t linkAggId            : 1;    ///< linkAggId field
    uint32_t defaultPcp           : 1;    ///< defaultPcp field
    uint32_t qosPolicy            : 1;    ///< qosPolicy field
    uint32_t aft                  : 1;    ///< aft field
    uint32_t isLinkAggMbr         : 1;    ///< isLinkAggMbr field
    uint32_t ingressFilteringEn   : 1;    ///< ingressFilteringEn field
    uint32_t portPoliceEn         : 1;    ///< portPoliceEn field
    uint32_t lrnDisable           : 1;    ///< lrnDisable field
    uint32_t l2SrcMatchDiscard    : 1;    ///< l2SrcMatchDiscard field
    uint32_t bpduDrop             : 1;    ///< bpduDrop field
    uint32_t stpDisable           : 1;    ///< stpDisable field
    uint32_t forcePortBasedVlan   : 1;    ///< forcePortBasedVlan field
    uint32_t l2AclEn              : 1;    ///< l2AclEn field
    uint32_t l2AclHiPrio          : 1;    ///< l2AclHiPrio field
    uint32_t ipv4ForceMacKey      : 1;    ///< ipv4ForceMacKey field
    uint32_t ipv6ForceMacKey      : 1;    ///< ipv6ForceMacKey field
    uint32_t replaceDscp          : 1;    ///< replaceDscp field
    uint32_t replaceCos           : 1;    ///< replaceCos field
    uint32_t vlanPrioEn           : 1;    ///< vlanPrioEn field
    uint32_t macBasedVlanHiPrio   : 1;    ///< macBasedVlanHiPrio field
    uint32_t keepVlanTag          : 1;    ///< keepVlanTag field
    uint32_t ingressL2SpanEn      : 1;    ///< ingressL2SpanEn field
} __attribute__((aligned(sizeof(int)))) tDsMemSrcPort;

/** Define C structure for DsMemStpState */
typedef struct DsMemStpState {
    uint32_t stpState             : 1;    ///< stpState field
} __attribute__((aligned(sizeof(int)))) tDsMemStpState;

/** Define C structure for DsMemTsnDomain */
typedef struct DsMemTsnDomain {
    uint32_t corePortBmp          : 1;    ///< corePortBmp field
} __attribute__((aligned(sizeof(int)))) tDsMemTsnDomain;

/** Define C structure for DsMemVlan */
typedef struct DsMemVlan {
    uint32_t cos                  : 1;    ///< cos field
    uint32_t vrrpGrpBmp           : 1;    ///< vrrpGrpBmp field
    uint32_t routingEn            : 1;    ///< routingEn field
    uint32_t mcastVlanEn          : 1;    ///< mcastVlanEn field
    uint32_t tsnEn                : 1;    ///< tsnEn field
    uint32_t l3AclEn              : 1;    ///< l3AclEn field
    uint32_t l3AclLabel           : 1;    ///< l3AclLabel field
    uint32_t l3SpanEn             : 1;    ///< l3SpanEn field
    uint32_t stpId                : 1;    ///< stpId field
    uint32_t fid                  : 1;    ///< fid field
    uint32_t replaceCos           : 1;    ///< replaceCos field
    uint32_t replaceDscp          : 1;    ///< replaceDscp field
    uint32_t arpInspection        : 1;    ///< arpInspection field
    uint32_t hwBcastArp           : 1;    ///< hwBcastArp field
    uint32_t msrpToCpu            : 1;    ///< msrpToCpu field
    uint32_t hwFwdMsrp            : 1;    ///< hwFwdMsrp field
    uint32_t mmrpToCpu            : 1;    ///< mmrpToCpu field
    uint32_t hwFwdMmrp            : 1;    ///< hwFwdMmrp field
    uint32_t mvrpToCpu            : 1;    ///< mvrpToCpu field
    uint32_t hwFwdMvrp            : 1;    ///< hwFwdMvrp field
    uint32_t igmpSnoopEn          : 1;    ///< igmpSnoopEn field
    uint32_t hwBcastIgmp          : 1;    ///< hwBcastIgmp field
    uint32_t mldSnoopEn           : 1;    ///< mldSnoopEn field
    uint32_t hwBcastMld           : 1;    ///< hwBcastMld field
    uint32_t ndToCpu              : 1;    ///< ndToCpu field
    uint32_t hwFwdNd              : 1;    ///< hwFwdNd field
    uint32_t snmpToCpu            : 1;    ///< snmpToCpu field
    uint32_t hwFwdSnmp            : 1;    ///< hwFwdSnmp field
    uint32_t lrnDisable           : 1;    ///< lrnDisable field
} __attribute__((aligned(sizeof(int)))) tDsMemVlan;

/** Define C structure for MsgAdmInfo */
typedef struct MsgAdmInfo {
} __attribute__((aligned(sizeof(int)))) tMsgAdmInfo;

#endif
