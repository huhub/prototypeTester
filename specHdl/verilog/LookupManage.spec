
function LookupManage(PI, PR, glPktHdr) {
    tmpEthPr = findPrByType( PROTO_TYPE_ETH );
    tmpMacDaHi[15:0] = glPktHdr[tmpEthPr.offset : tmpEthPr.offset+1];
    tmpMacDa[31:0]   = glPktHdr[tmpEthPr.offset+2 : tmpEthPr.offset+5];
    if (tmpEthPr.qualifier[4:2] != 3'h0) {    // vlan tagged
        tmpPcp[7:0]  = glPktHdr[tmpEthPr.offset+14][7:5];
    }
    if (PI.l3Type == PROTO_TYPE_IPV4) {
        tmpIpPr = findPrByType( PROTO_TYPE_IPV4 );
        tmpIpDaW0[31:0] = glPktHdr[tmpIpPr.offset+16 : tmpIpPr.offset+19];
        tmpDscp[7:0]    = glPktHdr[tmpIpPr.offset+1];
        tmpL3Next[7:0]  = glPktHdr[tmpIpPr.offset+9];
        tmpHostRouteKeyBuf[135:0] = {8'h0, 32'h0, 32'h0, 32'h0, tmpIpDaW0};
    } else if (PI.l3Type == PROTO_TYPE_IPV6) {
        tmpIpPr = findPrByType( PROTO_TYPE_IPV6 );
        tmpIpDaW3[31:0] = glPktHdr[tmpIpPr.offset+24 : tmpIpPr.offset+27];
        tmpIpDaW2[31:0] = glPktHdr[tmpIpPr.offset+28 : tmpIpPr.offset+31];
        tmpIpDaW1[31:0] = glPktHdr[tmpIpPr.offset+32 : tmpIpPr.offset+35];
        tmpIpDaW0[31:0] = glPktHdr[tmpIpPr.offset+36 : tmpIpPr.offset+39];
        tmpDscp[7:0]    = {glPktHdr[tmpIpPr.offset][3:0], glPktHdr[tmpIpPr.offset+1][7:4]};
        tmpL3Next[7:0]  = glPktHdr[tmpIpPr.offset+6];
        tmpHostRouteKeyBuf[135:0] = {8'h1, tmpIpDaW3[31:0], tmpIpDaW2[31:0], tmpIpDaW1[31:0], tmpIpDaW0[31:0]};
    }

    /** 1 destination MAC lookup */
    if (CtlLkupCfg.macDaKeyEn[0:0]) {
        tmpMacKey[47:0]    = {tmpMacDaHi, tmpMacDa[31:0]};
        tmpCuMacHashL[3:0] = nextCRC8_D64(tmpMacKey, sizeof(tmpMacKey)) & setAllBitOne(calc( 32
));
        tmpCuMacHashR[4:0] = 16 + nextCRC16_D64(tmpMacKey, sizeof(tmpMacKey)) & setAllBitOne(calc( 32
));

        DsMemCuMacKeyLVal = DsMemCuMacKey[ tmpCuMacHashL ];
        DsMemCuMacKeyRVal = DsMemCuMacKey[ tmpCuMacHashR ];
        
    
        if (DsMemCuMacKeyLVal.valid[0:0] && DsMemCuMacKeyLVal.macAddr0 == tmpMacDa &&
            DsMemCuMacKeyLVal.macAddrHi0 == tmpMacDaHi) {
            PI.cuMacHit = 1;
            PI.cuMacIdx = (tmpCuMacHashL << 1) + 0;
        }
        if (DsMemCuMacKeyRVal.valid[0:0] && DsMemCuMacKeyRVal.macAddr0 == tmpMacDa &&
            DsMemCuMacKeyRVal.macAddrHi0 == tmpMacDaHi) {
            PI.cuMacHit = 1;
            PI.cuMacIdx = (tmpCuMacHashL << 1) + 0;
        }
    
        if (DsMemCuMacKeyLVal.valid[1:1] && DsMemCuMacKeyLVal.macAddr1 == tmpMacDa &&
            DsMemCuMacKeyLVal.macAddrHi1 == tmpMacDaHi) {
            PI.cuMacHit = 1;
            PI.cuMacIdx = (tmpCuMacHashL << 1) + 1;
        }
        if (DsMemCuMacKeyRVal.valid[1:1] && DsMemCuMacKeyRVal.macAddr1 == tmpMacDa &&
            DsMemCuMacKeyRVal.macAddrHi1 == tmpMacDaHi) {
            PI.cuMacHit = 1;
            PI.cuMacIdx = (tmpCuMacHashL << 1) + 1;
        }
    
    }

    /** 2 destination MAC + Vlan PCP lookup */
    if (CtlLkupCfg.macPcpKeyEn[0:0]) {
        tmpMacPcpKey[55:0] = {tmpPcp, tmpMacDaHi[15:0], tmpMacDa[31:0]};
        tmpCuMacPcpHashL[3:0] = nextCRC8_D64(tmpMacPcpKey, sizeof(tmpMacPcpKey)) & setAllBitOne(calc( 32
));
        tmpCuMacPcpHashR[4:0] = 16 + nextCRC16_D64(tmpMacPcpKey, sizeof(tmpMacPcpKey)) & setAllBitOne(calc( 32
));

        DsMemCuMacPcpKeyLVal = DsMemCuMacPcpKey[ tmpCuMacPcpHashL ];
        DsMemCuMacPcpKeyRVal = DsMemCuMacPcpKey[ tmpCuMacPcpHashR ];
        
    
        if (DsMemCuMacPcpKeyLVal.valid[0:0] && DsMemCuMacPcpKeyLVal.macAddr0 == tmpMacDa &&
            DsMemCuMacPcpKeyLVal.macAddrHi0 == tmpMacDaHi && DsMemCuMacPcpKeyLVal.pcp0 == tmpPcp) {
            PI.cuMacPcpHit = 1;
            PI.cuMacPcpIdx = (tmpCuMacPcpHashL << 1) + 0;
        }
        if (DsMemCuMacPcpKeyRVal.valid[0:0] && DsMemCuMacPcpKeyRVal.macAddr0 == tmpMacDa &&
            DsMemCuMacPcpKeyRVal.macAddrHi0 == tmpMacDaHi) {
            PI.cuMacPcpHit = 1;
            PI.cuMacPcpIdx = (tmpCuMacPcpHashL << 1) + 0;
        }
    
        if (DsMemCuMacPcpKeyLVal.valid[1:1] && DsMemCuMacPcpKeyLVal.macAddr1 == tmpMacDa &&
            DsMemCuMacPcpKeyLVal.macAddrHi1 == tmpMacDaHi && DsMemCuMacPcpKeyLVal.pcp1 == tmpPcp) {
            PI.cuMacPcpHit = 1;
            PI.cuMacPcpIdx = (tmpCuMacPcpHashL << 1) + 1;
        }
        if (DsMemCuMacPcpKeyRVal.valid[1:1] && DsMemCuMacPcpKeyRVal.macAddr1 == tmpMacDa &&
            DsMemCuMacPcpKeyRVal.macAddrHi1 == tmpMacDaHi) {
            PI.cuMacPcpHit = 1;
            PI.cuMacPcpIdx = (tmpCuMacPcpHashL << 1) + 1;
        }
    
    }
        
    /** 3 destination IP + DSCP */
    if (CtlLkupCfg.ipDscpKeyEn[0:0]) {
        tmpIpDscpKey[135:0] = {tmpDscp, tmpIpDaW3[31:0], tmpIpDaW2[31:0], tmpIpDaW1[31:0], tmpIpDaW0[31:0]};
        tmpCuIpDscpHashL[calc( 16
)-1:0] = nextCRC8_D64(tmpIpDscpKey, sizeof(tmpIpDscpKey)) & setAllBitOne(calc( 16
));
        tmpCuIpDscpHashR[calc( 16
):0] = 8 + nextCRC16_D64(tmpIpDscpKey, sizeof(tmpIpDscpKey)) & setAllBitOne(calc( 16
));

        DsMemCuIpDscpKeyLVal = DsMemCuIpDscpKey[ tmpCuIpDscpHashL ];
        DsMemCuIpDscpKeyRVal = DsMemCuIpDscpKey[ tmpCuIpDscpHashR ];
        
        if (PI.l3Type == PROTO_TYPE_IPV6) {
            if (DsMemCuIpDscpKeyLVal.valid[0:0] && DsMemCuIpDscpKeyLVal.dscp0 = tmpDscp &&
                DsMemCuIpDscpKeyLVal.ipAddr3 == tmpIpDa3 && 
                DsMemCuIpDscpKeyLVal.ipAddr2 == tmpIpDa2 &&
                DsMemCuIpDscpKeyLVal.ipAddr1 == tmpIpDa1 && 
                DsMemCuIpDscpKeyLVal.ipAddr0 == tmpIpDa0) {
                PI.cuIpDscpHit = 1;
                PI.cuIpDscpIdx = (tmpCuIpDscpHashL << 2);
            }
            if (DsMemCuIpDscpKeyRVal.valid[0:0] && DsMemCuIpDscpKeyRVal.dscp0 = tmpDscp &&
                DsMemCuIpDscpKeyRVal.ipAddr3 == tmpIpDa3 && 
                DsMemCuIpDscpKeyRVal.ipAddr2 == tmpIpDa2 &&
                DsMemCuIpDscpKeyRVal.ipAddr1 == tmpIpDa1 && 
                DsMemCuIpDscpKeyRVal.ipAddr0 == tmpIpDa0) {
                PI.cuIpDscpHit = 1;
                PI.cuIpDscpIdx = (tmpCuIpDscpHashR << 2);
            }
        } else {
    
            if (DsMemCuIpDscpKeyLVal.valid[0:0] && DsMemCuIpDscpKeyLVal.ipAddr0 == tmpIpDa0 &&
                DsMemCuIpDscpKeyLVal.dscp0 == tmpDscp) {
                PI.cuIpDscpHit = 1;
                PI.cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 0;
            }
            if (DsMemCuIpDscpKeyRVal.valid[0:0] && DsMemCuIpDscpKeyRVal.macAddr0 == tmpIpDa0 &&
                DsMemCuIpDscpKeyRVal.dscp0 == tmpDscp) {
                PI.cuIpDscpHit = 1;
                PI.cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 0;
            }
    
            if (DsMemCuIpDscpKeyLVal.valid[1:1] && DsMemCuIpDscpKeyLVal.ipAddr1 == tmpIpDa1 &&
                DsMemCuIpDscpKeyLVal.dscp1 == tmpDscp) {
                PI.cuIpDscpHit = 1;
                PI.cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 1;
            }
            if (DsMemCuIpDscpKeyRVal.valid[1:1] && DsMemCuIpDscpKeyRVal.macAddr1 == tmpIpDa1 &&
                DsMemCuIpDscpKeyRVal.dscp1 == tmpDscp) {
                PI.cuIpDscpHit = 1;
                PI.cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 1;
            }
    
            if (DsMemCuIpDscpKeyLVal.valid[2:2] && DsMemCuIpDscpKeyLVal.ipAddr2 == tmpIpDa2 &&
                DsMemCuIpDscpKeyLVal.dscp2 == tmpDscp) {
                PI.cuIpDscpHit = 1;
                PI.cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 2;
            }
            if (DsMemCuIpDscpKeyRVal.valid[2:2] && DsMemCuIpDscpKeyRVal.macAddr2 == tmpIpDa2 &&
                DsMemCuIpDscpKeyRVal.dscp2 == tmpDscp) {
                PI.cuIpDscpHit = 1;
                PI.cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 2;
            }
    
            if (DsMemCuIpDscpKeyLVal.valid[3:3] && DsMemCuIpDscpKeyLVal.ipAddr3 == tmpIpDa3 &&
                DsMemCuIpDscpKeyLVal.dscp3 == tmpDscp) {
                PI.cuIpDscpHit = 1;
                PI.cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 3;
            }
            if (DsMemCuIpDscpKeyRVal.valid[3:3] && DsMemCuIpDscpKeyRVal.macAddr3 == tmpIpDa3 &&
                DsMemCuIpDscpKeyRVal.dscp3 == tmpDscp) {
                PI.cuIpDscpHit = 1;
                PI.cuIpDscpIdx = (tmpCuIpDscpHashL << 1) + 3;
            }
    
        }
    }

    if (PI.l4Type == PROTO_TYPE_UDP) {
        tmpL4Pr = findPrByType( PROTO_TYPE_UDP );
    } else if (PI.l4Type == PROTO_TYPE_TCP) {
        tmpL4Pr = findPrByType( PROTO_TYPE_TCP );
    }
    tmpL4DestPort[15:0] = glPktHdr[tmpL4Pr.offset : tmpL4Pr.offset+1];
    tmpL4SrcPort[15:0]  = glPktHdr[tmpL4Pr.offset+2 : tmpL4Pr.offset+3];

    /** 4 destination IP + Src Port */
    if (CtlLkupCfg.ipSportKeyEn[0:0]) {
        tmpIpSportKey[135:0] = {tmpL4SrcPort, tmpL3Next[7:0], tmpIpDaW3[31:0], tmpIpDaW2[31:0], tmpIpDaW1[31:0], tmpIpDaW0[31:0]};
        tmpCuIpSportHashL[calc( 16
)-1:0] = nextCRC8_D64(tmpIpSportKey, sizeof(tmpIpSportKey)) & setAllBitOne(calc( 16
));
        tmpCuIpSportHashR[calc( 16
):0] = 8 + nextCRC16_D64(tmpIpSportKey, sizeof(tmpIpSportKey)) & setAllBitOne(calc( 16
));

        DsMemCuIpSportKeyLVal = DsMemCuIpSportKey[ tmpCuIpSportHashL ];
        DsMemCuIpSportKeyRVal = DsMemCuIpSportKey[ tmpCuIpSportHashR ];
        
        if (PI.l3Type == PROTO_TYPE_IPV6) {
            if (DsMemCuIpSportKeyLVal.valid[0:0] && DsMemCuIpSportKeyLVal.l3Next0 = tmpL3Next &&
                DsMemCuIpSportKeyLVal.l4SrcPort == tmpL4SrcPort &&
                DsMemCuIpSportKeyLVal.ipAddr3 == tmpIpDa3 && 
                DsMemCuIpSportKeyLVal.ipAddr2 == tmpIpDa2 &&
                DsMemCuIpSportKeyLVal.ipAddr1 == tmpIpDa1 && 
                DsMemCuIpSportKeyLVal.ipAddr0 == tmpIpDa0) {
                PI.cuIpSportHit = 1;
                PI.cuIpSportIdx = (tmpCuIpSportHashL << 2);
            }
            if (DsMemCuIpSportKeyRVal.valid[0:0] && DsMemCuIpSportKeyRVal.L3Next0 = tmpL3Next &&
                DsMemCuIpSportKeyRVal.l4SrcPort == tmpL4SrcPort &&
                DsMemCuIpSportKeyRVal.ipAddr3 == tmpIpDa3 && 
                DsMemCuIpSportKeyRVal.ipAddr2 == tmpIpDa2 &&
                DsMemCuIpSportKeyRVal.ipAddr1 == tmpIpDa1 && 
                DsMemCuIpSportKeyRVal.ipAddr0 == tmpIpDa0) {
                PI.cuIpSportHit = 1;
                PI.cuIpSportIdx = (tmpCuIpSportHashR << 2);
            }
        } else {
    
            if (DsMemCuIpSportKeyLVal.valid[0:0] && DsMemCuIpSportKeyLVal.ipAddr0 == tmpIpDa0 &&
                DsMemCuIpSportKeyLVal.l3Next0 == tmpL3Next && DsMemCuIpSportKeyLVal.l4SrcPort0 == tmpL4SrcPort) {
                PI.cuIpSportHit = 1;
                PI.cuIpSportIdx = (tmpCuIpSportHashL << 1) + 0;
            }
            if (DsMemCuIpSportKeyRVal.valid[0:0] && DsMemCuIpSportKeyRVal.ipAddr0 == tmpIpDa0 &&
                DsMemCuIpSportKeyRVal.l3Next0 == tmpL3Next && DsMemCuIpSportKeyRVal.l4SrcPort0 == tmpL4SrcPort) {
                PI.cuIpSportHit = 1;
                PI.cuIpSportIdx = (tmpCuIpSportHashL << 1) + 0;
            }
    
            if (DsMemCuIpSportKeyLVal.valid[1:1] && DsMemCuIpSportKeyLVal.ipAddr1 == tmpIpDa1 &&
                DsMemCuIpSportKeyLVal.l3Next1 == tmpL3Next && DsMemCuIpSportKeyLVal.l4SrcPort1 == tmpL4SrcPort) {
                PI.cuIpSportHit = 1;
                PI.cuIpSportIdx = (tmpCuIpSportHashL << 1) + 1;
            }
            if (DsMemCuIpSportKeyRVal.valid[1:1] && DsMemCuIpSportKeyRVal.ipAddr1 == tmpIpDa1 &&
                DsMemCuIpSportKeyRVal.l3Next1 == tmpL3Next && DsMemCuIpSportKeyRVal.l4SrcPort1 == tmpL4SrcPort) {
                PI.cuIpSportHit = 1;
                PI.cuIpSportIdx = (tmpCuIpSportHashL << 1) + 1;
            }
    
            if (DsMemCuIpSportKeyLVal.valid[2:2] && DsMemCuIpSportKeyLVal.ipAddr2 == tmpIpDa2 &&
                DsMemCuIpSportKeyLVal.l3Next2 == tmpL3Next && DsMemCuIpSportKeyLVal.l4SrcPort2 == tmpL4SrcPort) {
                PI.cuIpSportHit = 1;
                PI.cuIpSportIdx = (tmpCuIpSportHashL << 1) + 2;
            }
            if (DsMemCuIpSportKeyRVal.valid[2:2] && DsMemCuIpSportKeyRVal.ipAddr2 == tmpIpDa2 &&
                DsMemCuIpSportKeyRVal.l3Next2 == tmpL3Next && DsMemCuIpSportKeyRVal.l4SrcPort2 == tmpL4SrcPort) {
                PI.cuIpSportHit = 1;
                PI.cuIpSportIdx = (tmpCuIpSportHashL << 1) + 2;
            }
    
            if (DsMemCuIpSportKeyLVal.valid[3:3] && DsMemCuIpSportKeyLVal.ipAddr3 == tmpIpDa3 &&
                DsMemCuIpSportKeyLVal.l3Next3 == tmpL3Next && DsMemCuIpSportKeyLVal.l4SrcPort3 == tmpL4SrcPort) {
                PI.cuIpSportHit = 1;
                PI.cuIpSportIdx = (tmpCuIpSportHashL << 1) + 3;
            }
            if (DsMemCuIpSportKeyRVal.valid[3:3] && DsMemCuIpSportKeyRVal.ipAddr3 == tmpIpDa3 &&
                DsMemCuIpSportKeyRVal.l3Next3 == tmpL3Next && DsMemCuIpSportKeyRVal.l4SrcPort3 == tmpL4SrcPort) {
                PI.cuIpSportHit = 1;
                PI.cuIpSportIdx = (tmpCuIpSportHashL << 1) + 3;
            }
    
        }
    }
    /** 5 destination IP + Dest Port */
    if (CtlLkupCfg.ipDportKeyEn[0:0]) {
        tmpIpDportKey[135:0] = {tmpL4DestPort, tmpL3Next[7:0], tmpIpDaW3[31:0], tmpIpDaW2[31:0], tmpIpDaW1[31:0], tmpIpDaW0[31:0]};
        tmpCuIpDportHashL[calc( 16
)-1:0] = nextCRC8_D64(tmpIpDportKey, sizeof(tmpIpDportKey)) & setAllBitOne(calc( 16
));
        tmpCuIpDportHashR[calc( 16
):0] = 8 + nextCRC16_D64(tmpIpDportKey, sizeof(tmpIpDportKey)) & setAllBitOne(calc( 16
));

        DsMemCuIpDportKeyLVal = DsMemCuIpDportKey[ tmpCuIpDportHashL ];
        DsMemCuIpDportKeyRVal = DsMemCuIpDportKey[ tmpCuIpDportHashR ];
        
        if (PI.l3Type == PROTO_TYPE_IPV6) {
            if (DsMemCuIpDportKeyLVal.valid[0:0] && DsMemCuIpDportKeyLVal.l3Next0 = tmpL3Next &&
                DsMemCuIpDportKeyLVal.l4DestPort == tmpL4DestPort &&
                DsMemCuIpDportKeyLVal.ipAddr3 == tmpIpDa3 && 
                DsMemCuIpDportKeyLVal.ipAddr2 == tmpIpDa2 &&
                DsMemCuIpDportKeyLVal.ipAddr1 == tmpIpDa1 && 
                DsMemCuIpDportKeyLVal.ipAddr0 == tmpIpDa0) {
                PI.cuIpDportHit = 1;
                PI.cuIpDportIdx = (tmpCuIpDportHashL << 2);
            }
            if (DsMemCuIpDportKeyRVal.valid[0:0] && DsMemCuIpDportKeyRVal.L3Next0 = tmpL3Next &&
                DsMemCuIpDportKeyRVal.l4DestPort == tmpL4DestPort &&
                DsMemCuIpDportKeyRVal.ipAddr3 == tmpIpDa3 && 
                DsMemCuIpDportKeyRVal.ipAddr2 == tmpIpDa2 &&
                DsMemCuIpDportKeyRVal.ipAddr1 == tmpIpDa1 && 
                DsMemCuIpDportKeyRVal.ipAddr0 == tmpIpDa0) {
                PI.cuIpDportHit = 1;
                PI.cuIpDportIdx = (tmpCuIpDportHashR << 2);
            }
        } else {
    
            if (DsMemCuIpDportKeyLVal.valid[0:0] && DsMemCuIpDportKeyLVal.ipAddr0 == tmpIpDa0 &&
                DsMemCuIpDportKeyLVal.l3Next0 == tmpL3Next && DsMemCuIpDportKeyLVal.l4DestPort0 == tmpL4DestPort) {
                PI.cuIpDportHit = 1;
                PI.cuIpDportIdx = (tmpCuIpDportHashL << 1) + 0;
            }
            if (DsMemCuIpDportKeyRVal.valid[0:0] && DsMemCuIpDportKeyRVal.ipAddr0 == tmpIpDa0 &&
                DsMemCuIpDportKeyRVal.l3Next0 == tmpL3Next && DsMemCuIpDportKeyRVal.l4DestPort0 == tmpL4DestPort) {
                PI.cuIpDportHit = 1;
                PI.cuIpDportIdx = (tmpCuIpDportHashL << 1) + 0;
            }
    
            if (DsMemCuIpDportKeyLVal.valid[1:1] && DsMemCuIpDportKeyLVal.ipAddr1 == tmpIpDa1 &&
                DsMemCuIpDportKeyLVal.l3Next1 == tmpL3Next && DsMemCuIpDportKeyLVal.l4DestPort1 == tmpL4DestPort) {
                PI.cuIpDportHit = 1;
                PI.cuIpDportIdx = (tmpCuIpDportHashL << 1) + 1;
            }
            if (DsMemCuIpDportKeyRVal.valid[1:1] && DsMemCuIpDportKeyRVal.ipAddr1 == tmpIpDa1 &&
                DsMemCuIpDportKeyRVal.l3Next1 == tmpL3Next && DsMemCuIpDportKeyRVal.l4DestPort1 == tmpL4DestPort) {
                PI.cuIpDportHit = 1;
                PI.cuIpDportIdx = (tmpCuIpDportHashL << 1) + 1;
            }
    
            if (DsMemCuIpDportKeyLVal.valid[2:2] && DsMemCuIpDportKeyLVal.ipAddr2 == tmpIpDa2 &&
                DsMemCuIpDportKeyLVal.l3Next2 == tmpL3Next && DsMemCuIpDportKeyLVal.l4DestPort2 == tmpL4DestPort) {
                PI.cuIpDportHit = 1;
                PI.cuIpDportIdx = (tmpCuIpDportHashL << 1) + 2;
            }
            if (DsMemCuIpDportKeyRVal.valid[2:2] && DsMemCuIpDportKeyRVal.ipAddr2 == tmpIpDa2 &&
                DsMemCuIpDportKeyRVal.l3Next2 == tmpL3Next && DsMemCuIpDportKeyRVal.l4DestPort2 == tmpL4DestPort) {
                PI.cuIpDportHit = 1;
                PI.cuIpDportIdx = (tmpCuIpDportHashL << 1) + 2;
            }
    
            if (DsMemCuIpDportKeyLVal.valid[3:3] && DsMemCuIpDportKeyLVal.ipAddr3 == tmpIpDa3 &&
                DsMemCuIpDportKeyLVal.l3Next3 == tmpL3Next && DsMemCuIpDportKeyLVal.l4DestPort3 == tmpL4DestPort) {
                PI.cuIpDportHit = 1;
                PI.cuIpDportIdx = (tmpCuIpDportHashL << 1) + 3;
            }
            if (DsMemCuIpDportKeyRVal.valid[3:3] && DsMemCuIpDportKeyRVal.ipAddr3 == tmpIpDa3 &&
                DsMemCuIpDportKeyRVal.l3Next3 == tmpL3Next && DsMemCuIpDportKeyRVal.l4DestPort3 == tmpL4DestPort) {
                PI.cuIpDportHit = 1;
                PI.cuIpDportIdx = (tmpCuIpDportHashL << 1) + 3;
            }
    
        }
    }

    /** Normal switch forwording */
    if (PI.routingEn ) {
        /** Host route address exactly lookup */
        // Left Hash
        // crc initial value is 8'hff
        tmpRouteHashLeft[2:0]= nextCRC8_D136( tmpHostRouteKeyBuf, sizeof(tmpHostRouteKeyBuf) ) & 3'h7;  
        tmpHostIdxL[5:0]= (tmpRouteHashLeft << 2);
        DsMemHostRouteLeftKeyVal    = DsMemHostRouteKey[ tmpRouteHashLeft ];
        // Right Hash
        // crc, 16'hfffff
        tmpRouteHashRight[3:0] = 8 + (nextCRC16_D136( tmpHostRouteKeyBuf, sizeof(tmpHostRouteKeyBuf) ) & 3'h7);   
        tmpHostIdxR[5:0]= (tmpRouteHashRight << 2);
        DsMemHostRouteRightKeyVal   = DsMemHostRouteKey[ tmpRouteHashRight ];

        if (PI.l3Type == PROTO_TYPE_IPV6 ) {
            if (DsMemHostRouteLeftKeyVal.isValid[0:0] && 
                (1'h1 == DsMemHostRouteLeftKeyVal.isIpv6[0:0]) && 
                (tmpIpDaW3[31:0] == DsMemHostRouteLeftKeyVal.ipAddrF3) && 
                (tmpIpDaW2[31:0] == DsMemHostRouteLeftKeyVal.ipAddrF2) && 
                (tmpIpDaW1[31:0] == DsMemHostRouteLeftKeyVal.ipAddrF1) && 
                (tmpIpDaW0[31:0] == DsMemHostRouteLeftKeyVal.ipAddrF0) ) {
                PI.hostRouteLeftHit      = 1;
                tmpHashLeftIdx[5:0] = tmpHostIdxL;
            }
            // right
            if (DsMemHostRouteRightValidVal.isValid[ tmpHostIdxR[4:0] : tmpHostIdxR[4:0] ] && 
                (1'h1 == DsMemHostRouteRightKeyVal.isIpv6[0:0]) && 
                (tmpIpDaW3[31:0] == DsMemHostRouteRightKeyVal.ipAddrF3) && 
                (tmpIpDaW2[31:0] == DsMemHostRouteRightKeyVal.ipAddrF2) && 
                (tmpIpDaW1[31:0] == DsMemHostRouteRightKeyVal.ipAddrF1) && 
                (tmpIpDaW0[31:0] == DsMemHostRouteRightKeyVal.ipAddrF0) ) {
                PI.hostRouteRightHit      = 1;
                tmpHashRightIdx[5:0] = tmpHostIdxR;
            }
        } else {
    
            if (DsMemHostRouteLeftKeyVal.isValid[ 0:0 ] 
            && (1'h0 == DsMemHostRouteLeftKeyVal.isIpv6F[0:0]) 
            && (tmpIpDaW0[31:0] == DsMemHostRouteLeftKeyVal.ipAddrF0[31:0]) ) {
                PI.hostRouteLeftHit  = 1;
                tmpHashLeftIdx       = tmpHostIdxL + 0;
            }
            // right
            if (DsMemHostRouteRightKeyVal.isValid[ 0 : 0 ] 
            && (1'h0 == DsMemHostRouteRightKeyVal.isIpv6F[0:0]) 
            && (tmpIpDaW0[31:0] == DsMemHostRouteRightKeyVal.ipAddrF0[31:0]) ) {
                PI.hostRouteRightHit = 1;
                tmpHashRightIdx      = tmpHostIdxR + 0;
            }
    
            if (DsMemHostRouteLeftKeyVal.isValid[ 1:1 ] 
            && (1'h0 == DsMemHostRouteLeftKeyVal.isIpv6F[1:1]) 
            && (tmpIpDaW0[31:0] == DsMemHostRouteLeftKeyVal.ipAddrF1[31:0]) ) {
                PI.hostRouteLeftHit  = 1;
                tmpHashLeftIdx       = tmpHostIdxL + 1;
            }
            // right
            if (DsMemHostRouteRightKeyVal.isValid[ 1 : 1 ] 
            && (1'h0 == DsMemHostRouteRightKeyVal.isIpv6F[1:1]) 
            && (tmpIpDaW0[31:0] == DsMemHostRouteRightKeyVal.ipAddrF1[31:0]) ) {
                PI.hostRouteRightHit = 1;
                tmpHashRightIdx      = tmpHostIdxR + 1;
            }
    
            if (DsMemHostRouteLeftKeyVal.isValid[ 2:2 ] 
            && (1'h0 == DsMemHostRouteLeftKeyVal.isIpv6F[2:2]) 
            && (tmpIpDaW0[31:0] == DsMemHostRouteLeftKeyVal.ipAddrF2[31:0]) ) {
                PI.hostRouteLeftHit  = 1;
                tmpHashLeftIdx       = tmpHostIdxL + 2;
            }
            // right
            if (DsMemHostRouteRightKeyVal.isValid[ 2 : 2 ] 
            && (1'h0 == DsMemHostRouteRightKeyVal.isIpv6F[2:2]) 
            && (tmpIpDaW0[31:0] == DsMemHostRouteRightKeyVal.ipAddrF2[31:0]) ) {
                PI.hostRouteRightHit = 1;
                tmpHashRightIdx      = tmpHostIdxR + 2;
            }
    
            if (DsMemHostRouteLeftKeyVal.isValid[ 3:3 ] 
            && (1'h0 == DsMemHostRouteLeftKeyVal.isIpv6F[3:3]) 
            && (tmpIpDaW0[31:0] == DsMemHostRouteLeftKeyVal.ipAddrF3[31:0]) ) {
                PI.hostRouteLeftHit  = 1;
                tmpHashLeftIdx       = tmpHostIdxL + 3;
            }
            // right
            if (DsMemHostRouteRightKeyVal.isValid[ 3 : 3 ] 
            && (1'h0 == DsMemHostRouteRightKeyVal.isIpv6F[3:3]) 
            && (tmpIpDaW0[31:0] == DsMemHostRouteRightKeyVal.ipAddrF3[31:0]) ) {
                PI.hostRouteRightHit = 1;
                tmpHashRightIdx      = tmpHostIdxR + 3;
            }
    
        }
        PI.ipRouteLookup = 1;

        /** Summary lookup result */
        if (PI.hostRouteLeftHit ) {
            PI.ipRouteIdx  = tmpHashLeftIdx;    
        } else if (PI.hostRouteRightHit ) {
            PI.ipRouteIdx  = tmpHashRightIdx;   
        }
    } else {
        /** Bridge Lookup */
        tmpFdbKeyBuf[79:0] = {PI.fid, tmpMacDaHi[15:0], tmpMacDa[31:0]};
        tmpMacHashLeft[5:0] = nextCRC8_D64( tmpFdbKeyBuf, sizeof(tmpFdbKeyBuf)) & 5'h1f;    // Initial value is ffffffff 
        tmpMacHashRight[6:0] = (nextCRC16_D64( tmpFdbKeyBuf, sizeof(tmpFdbKeyBuf)) & 5'h1f) + 32;   // Initial value  is ffff 
        PI.macDaLValid    = 0;
        PI.macDaRValid   = 0;

        // Left hash
        DsMemMacKeyLeftVal      = DsMemMacKey[ tmpMacHashLeft ];
        DsMemMacValidLeftVal    = DsMemMacValid[ tmpMacHashLeft[5:3] ];
        // Right Hash
        DsMemMacKeyRightVal     = DsMemMacKey[ tmpMacHashRight[5:0] ];
        DsMemMacValidRightVal   = DsMemMacValid[ tmpMacHashRight[5:3] ];

    
        tmpIdxLeft[6:0]    = (tmpMacHashLeft << 2) + 0;
        // Left check
        if (DsMemMacValidLeftVal.valid[tmpIdxLeft[4:0] : tmpIdxLeft[4:0]] && (DsMemMacKeyLeftVal.macAddr0[31:0] == tmpMacDa)
            && (DsMemMacKeyLeftVal.vlanId0[11:0] == PI.fid) && (DsMemMacKeyLeftVal.macAddrHi0[15:0] == tmpMacDaHi) ) {
            PI.macDaLValid     = 1;
            PI.macDaIdx     = tmpIdxLeft;
        }
        // Right check
        tmpIdxRight[6:0]   = (tmpMacHashRight << 2) + 0;
        if (DsMemMacValidRightVal.valid[tmpIdxRight[4:0] : tmpIdxRight[4:0]] && (DsMemMacKeyRightVal.macAddr0[31:0] == tmpMacDa)
            && (DsMemMacKeyRightVal.vlanId0[11:0] == PI.fid) && (DsMemMacKeyRightVal.macAddrHi0[15:0] == tmpMacDaHi) ) {
            PI.macDaRValid     = 1;
            PI.macDaIdx      = tmpIdxRight;
        }
    
        tmpIdxLeft[6:0]    = (tmpMacHashLeft << 2) + 1;
        // Left check
        if (DsMemMacValidLeftVal.valid[tmpIdxLeft[4:0] : tmpIdxLeft[4:0]] && (DsMemMacKeyLeftVal.macAddr1[31:0] == tmpMacDa)
            && (DsMemMacKeyLeftVal.vlanId1[11:0] == PI.fid) && (DsMemMacKeyLeftVal.macAddrHi1[15:0] == tmpMacDaHi) ) {
            PI.macDaLValid     = 1;
            PI.macDaIdx     = tmpIdxLeft;
        }
        // Right check
        tmpIdxRight[6:0]   = (tmpMacHashRight << 2) + 1;
        if (DsMemMacValidRightVal.valid[tmpIdxRight[4:0] : tmpIdxRight[4:0]] && (DsMemMacKeyRightVal.macAddr1[31:0] == tmpMacDa)
            && (DsMemMacKeyRightVal.vlanId1[11:0] == PI.fid) && (DsMemMacKeyRightVal.macAddrHi1[15:0] == tmpMacDaHi) ) {
            PI.macDaRValid     = 1;
            PI.macDaIdx      = tmpIdxRight;
        }
    
    }

    CtlLkpMngLog.macDaIdx[12:0] = PI.macDaIdx[12:0];
    CtlLkpMngLog.aclIndex[10:0] = PI.aclIndex[10:0];
    CtlLkpMngLog.routeHitTcam[0:0] = PI.routeHitTcam;
    CtlLkpMngLog.ipRouteLookup[0:0] = PI.ipRouteLookup;
    CtlLkpMngLog.routeHitNatTcam[0:0] = PI.routeHitNatTcam;
    CtlLkpMngLog.hostRouteLeftHit[0:0] = PI.hostRouteLeftHit;
    CtlLkpMngLog.hostRouteRightHit[0:0] = PI.hostRouteRightHit;
    CtlLkpMngLog.aclResultValid[0:0] = PI.aclResultValid;
    CtlLkpMngLog.ipv6AclLookup[0:0] = PI.ipv6AclLookup;
    CtlLkpMngLog.ipRouteIdx[5:0] = PI.ipRouteIdx[5:0];
    CtlLkpMngLog.ipv4AclLookup[0:0] = PI.ipv4AclLookup;
    CtlLkpMngLog.macAclLookup[0:0] = PI.macAclLookup;
    CtlLkpMngLog.macDaLeftValid[0:0] = PI.macDaLeftValid;
    CtlLkpMngLog.macDaRightValid[0:0] = PI.macDaRightValid;
}

    