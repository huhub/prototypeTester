/*
 * Software Development Kit for Fisilink
 * @file: ingress.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <cFdbAging.h> 
#include <cPacketParser.h> 
#include <cVlanLookup.h> 
#include <cInterface.h> 
#include <cLookupManage.h> 
#include <cPacketProcess.h> 
#include <cIngressPolice.h> 
#include <cHeaderAdjust.h> 
#include <cDestPost.h> 
#include <cRedundancy.h> 
#include <cmodelUtil.h> 
#include <stdio.h>
#include <stdint.h>
#include <common/const.h>

void ingressProc( uint8_t pktHdr[], tMsgWrInfo *wrInfo, tMsgIgr2Adm *igr2Adm, unsigned long long timestamp, uint32_t seq ) {
    tPktInfo PI = {0};
    PI.ts       = timestamp;
    printf("---------------Enter HeaderAdjust\n");
    HeaderAdjust(pktHdr, wrInfo, &PI);
    //FILE *logFp = fopen("businfo", "w+");
    //outPutPI(logFp, "HeaderAdjust", &PI );
#if CFG_DUMP == 1
    dumpBusInfo("IgrHa2Pa", &PI, INFO_IGR, seq);
#endif
    /*
     *Extract packet information from packet.
     */
    printf("---------------Enter PacketParser\n");
    PacketParser(pktHdr, &PI);
    //outPutPI(logFp, "PacketParser", &PI);
#if CFG_DUMP == 1
    dumpBusInfo("IgrPa2Vc", &PI, INFO_IGR, seq);
#endif
    /*
     *Perform VLAN Classification look up.
     */
    printf("---------------Enter VlanLookup\n");
    VlanLookup(&PI);
    //outPutPI(logFp, "VlanLookup", &PI);
#if CFG_DUMP == 1
    dumpBusInfo("IgrVc2If", &PI, INFO_IGR, seq);
#endif
    /*
     *Extract port property, VLAN assignment, and VLAN property.
     */
    printf("---------------Enter Interface\n");
    Interface(&PI);
    //outPutPI(logFp, "Interface", &PI);
#if CFG_DUMP == 1
    dumpBusInfo("IgrIf2Lkp", &PI, INFO_IGR, seq);
#endif
    /*
     *Perform port property, VLAN assignment, and VLAN property.
     */
    printf("---------------Enter LookupManage\n");
    LookupManage(&PI);
    //outPutPI(logFp, "LookupManage", &PI);
#if CFG_DUMP == 1
    dumpBusInfo("IgrLkp2Pp", &PI, INFO_IGR, seq);
#endif
    /*
     *Process DsAclQos, DsRoute, DsMac, merge destination map, learning, port security, classification and policing.
     */
    printf("---------------Enter PacketProcess\n");
    PacketProcess(&PI);
    //outPutPI(logFp, "PacketProcesss ", &PI);
#if CFG_DUMP == 1
    dumpBusInfo("IgrPp2Me", &PI, INFO_IGR, seq);
#endif
    /*
     * Do meter
     */
    printf("---------------Enter IngressPolice\n");
    IngressPolice(&PI);
    //outPutPI(logFp, "IngressPolice", &PI);
#if CFG_DUMP == 1
    dumpBusInfo("IgrMe2Rcv", &PI, INFO_IGR, seq);
#endif
    /*
    ** Check sequence only for TSN
    */
    printf("---------------Enter RecoverySequence\n");
    RecoverySequence(&PI);
    //outPutPI(logFp, "RecoverySequence", &PI);
#if CFG_DUMP == 1
    dumpBusInfo("IgrRcv2Fwd", &PI, INFO_IGR, seq);
#endif
    
    /*
     *Set final destination, handle link aggregation
     */
    printf("---------------Enter DestPost\n");
    DestPost( &PI, igr2Adm );
    //outPutPI(logFp, "DestPost", &PI);
#if CFG_DUMP == 1
    dumpBusInfo("IgrFwd2Adm", igr2Adm, INFO_TM, seq);
#endif
    //fclose(logFp);
}
