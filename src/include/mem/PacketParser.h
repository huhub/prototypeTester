/*
 * Software Development Kit for Fisilink
 * @file: PacketParser.h
 * @description: C language expression for PacketParser module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __PACKETPARSER_REG__
#define __PACKETPARSER_REG__
#include <stdint.h>

/** Define C structure for CtlDosControl */
typedef struct CtlDosControl {
    uint32_t macSaEqMacDaDrop     : 1;    ///< macSaEqMacDaDrop field
    uint32_t sipEqDipDrop         : 1;    ///< sipEqDipDrop field
    uint32_t icmpFragDrop         : 1;    ///< icmpFragDrop field
    uint32_t icmpV4PingSizeCheck  : 1;    ///< icmpV4PingSizeCheck field
    uint32_t icmpV4MaxSize        : 1;    ///< icmpV4MaxSize field
    uint32_t icmpV6PingSizeCheck  : 1;    ///< icmpV6PingSizeCheck field
    uint32_t icmpV6MaxSize        : 1;    ///< icmpV6MaxSize field
    uint32_t tcpFlagsCtl0Seq0En   : 1;    ///< tcpFlagsCtl0Seq0En field
    uint32_t tcpSportEqDportDrop  : 1;    ///< tcpSportEqDportDrop field
    uint32_t tcpFlagSynFinDrop    : 1;    ///< tcpFlagSynFinDrop field
    uint32_t tcpFlagFinUrgPshSeq0Drop : 1;    ///< tcpFlagFinUrgPshSeq0Drop field
    uint32_t tcpFragOffset1Drop   : 1;    ///< tcpFragOffset1Drop field
    uint32_t tcpHdrPartialDrop    : 1;    ///< tcpHdrPartialDrop field
    uint32_t udpSportEqDportDrop  : 1;    ///< udpSportEqDportDrop field
} __attribute__((aligned(sizeof(int)))) tCtlDosControl;

/** Define C structure for CtlL2HdrProtoCam */
typedef struct CtlL2HdrProtoCam {
    uint32_t valid                : 1;    ///< valid field
    uint32_t l2ProtoData0         : 1;    ///< l2ProtoData0 field
    uint32_t l2ProtoMask0         : 1;    ///< l2ProtoMask0 field
    uint32_t l3Type0              : 1;    ///< l3Type0 field
    uint32_t l2ProtoData1         : 1;    ///< l2ProtoData1 field
    uint32_t l2ProtoMask1         : 1;    ///< l2ProtoMask1 field
    uint32_t l3Type1              : 1;    ///< l3Type1 field
    uint32_t l2ProtoData2         : 1;    ///< l2ProtoData2 field
    uint32_t l2ProtoMask2         : 1;    ///< l2ProtoMask2 field
    uint32_t l3Type2              : 1;    ///< l3Type2 field
    uint32_t l2ProtoData3         : 1;    ///< l2ProtoData3 field
    uint32_t l2ProtoMask3         : 1;    ///< l2ProtoMask3 field
    uint32_t l3Type3              : 1;    ///< l3Type3 field
    uint32_t l2ProtoData4         : 1;    ///< l2ProtoData4 field
    uint32_t l2ProtoMask4         : 1;    ///< l2ProtoMask4 field
    uint32_t l3Type4              : 1;    ///< l3Type4 field
    uint32_t l2ProtoData5         : 1;    ///< l2ProtoData5 field
    uint32_t l2ProtoMask5         : 1;    ///< l2ProtoMask5 field
    uint32_t l3Type5              : 1;    ///< l3Type5 field
    uint32_t l2ProtoData6         : 1;    ///< l2ProtoData6 field
    uint32_t l2ProtoMask6         : 1;    ///< l2ProtoMask6 field
    uint32_t l3Type6              : 1;    ///< l3Type6 field
    uint32_t l2ProtoData7         : 1;    ///< l2ProtoData7 field
    uint32_t l2ProtoMask7         : 1;    ///< l2ProtoMask7 field
    uint32_t l3Type7              : 1;    ///< l3Type7 field
} __attribute__((aligned(sizeof(int)))) tCtlL2HdrProtoCam;

/** Define C structure for CtlL3HdrProtoCam */
typedef struct CtlL3HdrProtoCam {
    uint32_t isValid              : 1;    ///< isValid field
    uint32_t l3TypeMask0          : 1;    ///< l3TypeMask0 field
    uint32_t l3TypeData0          : 1;    ///< l3TypeData0 field
    uint32_t l3ProtoMask0         : 1;    ///< l3ProtoMask0 field
    uint32_t l3ProtoData0         : 1;    ///< l3ProtoData0 field
    uint32_t l4Type0              : 1;    ///< l4Type0 field
    uint32_t protocol             : 1;    ///< protocol field
    uint32_t l3TypeMask1          : 1;    ///< l3TypeMask1 field
    uint32_t l3TypeData1          : 1;    ///< l3TypeData1 field
    uint32_t l3ProtoMask1         : 1;    ///< l3ProtoMask1 field
    uint32_t l3ProtoData1         : 1;    ///< l3ProtoData1 field
    uint32_t l4Type1              : 1;    ///< l4Type1 field
    uint32_t l3TypeMask2          : 1;    ///< l3TypeMask2 field
    uint32_t l3TypeData2          : 1;    ///< l3TypeData2 field
    uint32_t l3ProtoMask2         : 1;    ///< l3ProtoMask2 field
    uint32_t l3ProtoData2         : 1;    ///< l3ProtoData2 field
    uint32_t l4Type2              : 1;    ///< l4Type2 field
    uint32_t l3TypeMask3          : 1;    ///< l3TypeMask3 field
    uint32_t l3TypeData3          : 1;    ///< l3TypeData3 field
    uint32_t l3ProtoMask3         : 1;    ///< l3ProtoMask3 field
    uint32_t l3ProtoData3         : 1;    ///< l3ProtoData3 field
    uint32_t l4Type3              : 1;    ///< l4Type3 field
    uint32_t l3TypeMask4          : 1;    ///< l3TypeMask4 field
    uint32_t l3TypeData4          : 1;    ///< l3TypeData4 field
    uint32_t l3ProtoMask4         : 1;    ///< l3ProtoMask4 field
    uint32_t l3ProtoData4         : 1;    ///< l3ProtoData4 field
    uint32_t l4Type4              : 1;    ///< l4Type4 field
    uint32_t l3TypeMask5          : 1;    ///< l3TypeMask5 field
    uint32_t l3TypeData5          : 1;    ///< l3TypeData5 field
    uint32_t l3ProtoMask5         : 1;    ///< l3ProtoMask5 field
    uint32_t l3ProtoData5         : 1;    ///< l3ProtoData5 field
    uint32_t l4Type5              : 1;    ///< l4Type5 field
    uint32_t l3TypeMask6          : 1;    ///< l3TypeMask6 field
    uint32_t l3TypeData6          : 1;    ///< l3TypeData6 field
    uint32_t l3ProtoMask6         : 1;    ///< l3ProtoMask6 field
    uint32_t l3ProtoData6         : 1;    ///< l3ProtoData6 field
    uint32_t l4Type6              : 1;    ///< l4Type6 field
    uint32_t l3TypeMask7          : 1;    ///< l3TypeMask7 field
    uint32_t l3TypeData7          : 1;    ///< l3TypeData7 field
    uint32_t l3ProtoMask7         : 1;    ///< l3ProtoMask7 field
    uint32_t l3ProtoData7         : 1;    ///< l3ProtoData7 field
    uint32_t l4Type7              : 1;    ///< l4Type7 field
    uint32_t l3TypeMask8          : 1;    ///< l3TypeMask8 field
    uint32_t l3TypeData8          : 1;    ///< l3TypeData8 field
    uint32_t l3ProtoMask8         : 1;    ///< l3ProtoMask8 field
    uint32_t l3ProtoData8         : 1;    ///< l3ProtoData8 field
    uint32_t l4Type8              : 1;    ///< l4Type8 field
    uint32_t l3TypeMask9          : 1;    ///< l3TypeMask9 field
    uint32_t l3TypeData9          : 1;    ///< l3TypeData9 field
    uint32_t l3ProtoMask9         : 1;    ///< l3ProtoMask9 field
    uint32_t l3ProtoData9         : 1;    ///< l3ProtoData9 field
    uint32_t l4Type9              : 1;    ///< l4Type9 field
    uint32_t l3TypeMask10         : 1;    ///< l3TypeMask10 field
    uint32_t l3TypeData10         : 1;    ///< l3TypeData10 field
    uint32_t l3ProtoMask10        : 1;    ///< l3ProtoMask10 field
    uint32_t l3ProtoData10        : 1;    ///< l3ProtoData10 field
    uint32_t l4Type10             : 1;    ///< l4Type10 field
    uint32_t l3TypeMask11         : 1;    ///< l3TypeMask11 field
    uint32_t l3TypeData11         : 1;    ///< l3TypeData11 field
    uint32_t l3ProtoMask11        : 1;    ///< l3ProtoMask11 field
    uint32_t l3ProtoData11        : 1;    ///< l3ProtoData11 field
    uint32_t l4Type11             : 1;    ///< l4Type11 field
    uint32_t l3TypeMask12         : 1;    ///< l3TypeMask12 field
    uint32_t l3TypeData12         : 1;    ///< l3TypeData12 field
    uint32_t l3ProtoMask12        : 1;    ///< l3ProtoMask12 field
    uint32_t l3ProtoData12        : 1;    ///< l3ProtoData12 field
    uint32_t l4Type12             : 1;    ///< l4Type12 field
    uint32_t l3TypeMask13         : 1;    ///< l3TypeMask13 field
    uint32_t l3TypeData13         : 1;    ///< l3TypeData13 field
    uint32_t l3ProtoMask13        : 1;    ///< l3ProtoMask13 field
    uint32_t l3ProtoData13        : 1;    ///< l3ProtoData13 field
    uint32_t l4Type13             : 1;    ///< l4Type13 field
    uint32_t l3TypeMask14         : 1;    ///< l3TypeMask14 field
    uint32_t l3TypeData14         : 1;    ///< l3TypeData14 field
    uint32_t l3ProtoMask14        : 1;    ///< l3ProtoMask14 field
    uint32_t l3ProtoData14        : 1;    ///< l3ProtoData14 field
    uint32_t l4Type14             : 1;    ///< l4Type14 field
    uint32_t l3TypeMask15         : 1;    ///< l3TypeMask15 field
    uint32_t l3TypeData15         : 1;    ///< l3TypeData15 field
    uint32_t l3ProtoMask15        : 1;    ///< l3ProtoMask15 field
    uint32_t l3ProtoData15        : 1;    ///< l3ProtoData15 field
    uint32_t l4Type15             : 1;    ///< l4Type15 field
} __attribute__((aligned(sizeof(int)))) tCtlL3HdrProtoCam;

/** Define C structure for CtlParserEthernet */
typedef struct CtlParserEthernet {
    uint32_t svlanTpid            : 1;    ///< svlanTpid field
    uint32_t cvlanTpid            : 1;    ///< cvlanTpid field
    uint32_t stagFirst            : 1;    ///< stagFirst field
    uint32_t maxLength            : 1;    ///< maxLength field
    uint32_t allowNoneZeroOui     : 1;    ///< allowNoneZeroOui field
    uint32_t ethSapCtlLen         : 1;    ///< ethSapCtlLen field
    uint32_t ccmOpcode            : 1;    ///< ccmOpcode field
    uint32_t lmmOpcode            : 1;    ///< lmmOpcode field
    uint32_t lmrOpcode            : 1;    ///< lmrOpcode field
    uint32_t dmmOpcode            : 1;    ///< dmmOpcode field
    uint32_t dmrOpcode            : 1;    ///< dmrOpcode field
    uint32_t tcpHdrMinSize        : 1;    ///< tcpHdrMinSize field
} __attribute__((aligned(sizeof(int)))) tCtlParserEthernet;

/** Define C structure for CtlParserL4Port */
typedef struct CtlParserL4Port {
    uint32_t ptpPort0             : 1;    ///< ptpPort0 field
    uint32_t ptpPort1             : 1;    ///< ptpPort1 field
    uint32_t bfdPort0             : 1;    ///< bfdPort0 field
    uint32_t bfdPort1             : 1;    ///< bfdPort1 field
    uint32_t bfdEcho              : 1;    ///< bfdEcho field
    uint32_t avbPortLo            : 1;    ///< avbPortLo field
    uint32_t avbPortHi            : 1;    ///< avbPortHi field
    uint32_t snmpPort0            : 1;    ///< snmpPort0 field
    uint32_t snmpPort1            : 1;    ///< snmpPort1 field
} __attribute__((aligned(sizeof(int)))) tCtlParserL4Port;

/** Define C structure for CtlParserTsn */
typedef struct CtlParserTsn {
    uint32_t rtagTpid             : 1;    ///< rtagTpid field
    uint32_t prpTpid              : 1;    ///< prpTpid field
    uint32_t hsrTpid              : 1;    ///< hsrTpid field
} __attribute__((aligned(sizeof(int)))) tCtlParserTsn;

/** Define C structure for CtlPktParserLog */
typedef struct CtlPktParserLog {
    uint32_t userData0            : 1;    ///< userData0 field
    uint32_t userData1            : 1;    ///< userData1 field
    uint32_t randomSeed           : 1;    ///< randomSeed field
    uint32_t dosDropBmp           : 1;    ///< dosDropBmp field
    uint32_t l2Type               : 1;    ///< l2Type field
    uint32_t stagValid            : 1;    ///< stagValid field
    uint32_t ctagValid            : 1;    ///< ctagValid field
    uint32_t rtagValid            : 1;    ///< rtagValid field
    uint32_t l3Type               : 1;    ///< l3Type field
    uint32_t l4Type               : 1;    ///< l4Type field
    uint32_t l2HdrError           : 1;    ///< l2HdrError field
    uint32_t l3HdrError           : 1;    ///< l3HdrError field
    uint32_t l4HdrError           : 1;    ///< l4HdrError field
    uint32_t rtcpPkt              : 1;    ///< rtcpPkt field
    uint32_t isPtp                : 1;    ///< isPtp field
    uint32_t rtpPkt               : 1;    ///< rtpPkt field
    uint32_t snmpPkt              : 1;    ///< snmpPkt field
    uint32_t isBfd                : 1;    ///< isBfd field
    uint32_t jumboNum             : 1;    ///< jumboNum field
} __attribute__((aligned(sizeof(int)))) tCtlPktParserLog;

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

/** Define C structure for DsMemUdfOffset */
typedef struct DsMemUdfOffset {
    uint32_t udfOffset0           : 1;    ///< udfOffset0 field
    uint32_t udfOffset1           : 1;    ///< udfOffset1 field
} __attribute__((aligned(sizeof(int)))) tDsMemUdfOffset;

/** Define C structure for MsgAdmInfo */
typedef struct MsgAdmInfo {
} __attribute__((aligned(sizeof(int)))) tMsgAdmInfo;

#endif
