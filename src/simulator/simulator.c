int cmodelProcess(unsigned char *pkt, char *device, unsigned long long timestamp) {
    if (strncmp(device, "resetSequence", 13) == 0) {
        sInPktSequence  = 0;
        resetHashSeqence();
        resetAclLogSeq();
    } else {
        int srcPort     = 0;
        int userId      = 0;
        int ret = sscanf(device, "vport%d-%d", &userId, &srcPort);
        if (ret == 2) {
            __pishon_debug("Enter cmodel-----------------------------\n");
            unsigned char *glPktHdr        = (char *)malloc(strlen(pkt));
            assert(glPktHdr != NULL);
            tMsWrInfo  msWrInfo = {0};
            unsigned int len    = transText2Hex(glPktHdr, pkt);
            msWrInfo.pktLength    = len + 4;  // +4: length include crc
//            printPacket(glPktHdr, msWrInfo.pktLength);
            msWrInfo.channelId  = srcPort;
        #if CFG_DUMP == 1
            saveCosimPkt(glPktHdr, len, IN_PKT, srcPort);
        #endif
            __pishon_debug("-------@%llx ns: srcPort=%d, pktLength=%d\n", timestamp, srcPort, msWrInfo.pktLength);
            tMsIgr2Adm  msIgr2Adm = {0};
            ingressProc(glPktHdr, &msWrInfo, &msIgr2Adm, timestamp, sInPktSequence);
            trafficManage(glPktHdr, &msIgr2Adm, sInPktSequence, timestamp);
            if (glPktHdr != NULL) {
                free(glPktHdr);
                glPktHdr = NULL;
            }
            sInPktSequence++;
        } else {
            printf("Warning: unknonw device %s, sscanf %d\n", device, ret);
        }
    }
    return 0;
}

