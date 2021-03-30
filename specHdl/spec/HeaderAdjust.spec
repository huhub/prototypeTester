
function HeaderAdjust( PI, glPktHdr, pktLength[13:0], channelId[0:0], hwDiscard[0:0] ) {
    PI.opCode        = OP_CODE_BCAST;               // 3'd2
    PI.discard       = hwDiscard;
    PI.pktLength     = pktLength;
	
    DsRegChnlAttrVal = DsRegChnlAttr[ channelId ];
    PI.srcPort       = DsRegChnlAttrVal.portId;
	PI.bypassPp      = DsRegChnlAttrVal.bypassPp;
	PI.destMap       = DsRegChnlAttrVal.destMap;
	PI.dot1qType     = DsRegChnlAttrVal.dot1qType;

    PI.hasInnerHdr   = ((PI.srcPort == CtlCommon.cpuPortNo) && CtlCommon.cpuHdrEn);
    
    if( PI.hasInnerHdr ) {
                // parser from_cpu_header
        PI.bypassPp     = glPktHdr[0][7:7];
        PI.opCode       = glPktHdr[0][6:4];
        PI.vlanId       = {glPktHdr[0][3:0], glPktHdr[1]};
        PI.srcPort      = glPktHdr[2];
        PI.destMap      = {glPktHdr[3], glPktHdr[4]};
        PI.prior        = glPktHdr[5][7:3];
        PI.isTsn        = glPktHdr[5][2:2];
        PI.lrnDisable   = glPktHdr[5][1:1];
        PI.forbidEdit   = glPktHdr[5][0:0];
        PI.ts           = {glPktHdr[8], glPktHdr[9], glPktHdr[10], glPktHdr[11], glPktHdr[12], glPktHdr[13], glPktHdr[14], glPktHdr[15]}; 
        PI.criticalPkt  = 1;
		PI.psrOffset   += 8;
    }
    // adjust header for inner header and crc
    PI.hdrLength = (PI.pktLength <= 64) ? PI.pktLength - 4/*strip CRC*/ : 64;
    if (PI.hdrLength < PI.psrOffset) {
        PI.discard         = 1;
        PI.discardBmp[1:1] = 1;
    }
    PI.pktType     = PROTO_TYPE_ETH;   // for first time parser
    CtlHdrAdjLog.isTsn     = PI.isTsn;
    CtlHdrAdjLog.discard     = PI.discard;
    CtlHdrAdjLog.srcPort     = PI.srcPort;
    //CtlHdrAdjLog.pktLenLog     = PI.pktLenLog;
}
    
