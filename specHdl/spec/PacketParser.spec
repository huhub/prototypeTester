
function PacketParser( PI, PR, glPktHdr ) {
    if (PI.pktType == PROTO_TYPE_ETH) {
        // Layer 2 header 
        tmpPr               = findPrByType( PROTO_TYPE_ETH );
        tmpQualifier[15:0] = 0;
        tmpPr.protocol      = PROTO_TYPE_ETH;
        tmpPr.offset        = PI.psrOffset ;
        glPktTmpL2Hdr[0:25] = glPktHdr[PI.psrOffset : PI.psrOffset+25];  // ETH+double VLAN+RTAG
        // isBc
        tmpQualifier[0:0] = ({glPktTmpL2Hdr[0], glPktTmpL2Hdr[1]} == 16'hffff) && ({glPktTmpL2Hdr[2], glPktTmpL2Hdr[3]} == 16'hffff) && ({glPktTmpL2Hdr[4], glPktTmpL2Hdr[5]} == 16'hffff); 
        // isMC
        tmpQualifier[1:1] =  !tmpQualifier[0:0] && glPktTmpL2Hdr[0][0:0] == 1'h1;
        // validDoubleVlan
        if (20 < PI.hdrLength - PI.psrOffset) {
            tmpQualifier[2:2] = PI.dot1qType[1:1] && PI.dot1qType[0:0] && ({glPktTmpL2Hdr[12], glPktTmpL2Hdr[13]} == CtlParserEthernet.svlanTpid) && ({glPktTmpL2Hdr[16], glPktTmpL2Hdr[17]} == CtlParserEthernet.cvlanTpid); 
        }
        if (16 < PI.hdrLength - PI.psrOffset) {
            // validSvlan    
            tmpQualifier[3:3] = !tmpQualifier[2:2] && CtlParserEthernet.stagFirst && PI.dot1qType[1:1] && ({glPktTmpL2Hdr[12], glPktTmpL2Hdr[13]} == CtlParserEthernet.svlanTpid);
            // validCvlan
            tmpQualifier[4:4] = !tmpQualifier[2:2] && PI.dot1qType[0:0] && ({glPktTmpL2Hdr[12], glPktTmpL2Hdr[13]} == CtlParserEthernet.cvlanTpid);
        }
        // validRTag
        tmpRtagTpid[15:0] = tmpQualifier[2:2] ? {glPktTmpL2Hdr[20], glPktTmpL2Hdr[21]} :
                            tmpQualifier[4:3] != 0 ? {glPktTmpL2Hdr[16], glPktTmpL2Hdr[17]} :
                            {glPktTmpL2Hdr[12], glPktTmpL2Hdr[13]};
        PI.l3Offset = tmpQualifier[2:2] ? 12 + 4 + 4 :
                      tmpQualifier[4:3] != 0 ? 12 + 4 : 12;
        PI.l3Offset += PI.psrOffset;
        if (6 < PI.hdrLength - PI.l3Offset) {
            tmpQualifier[5:5] = tmpRtagTpid == CtlParserTsn.rtagTpid || tmpRtagTpid == CtlParserTsn.prpTpid || tmpRtagTpid == CtlParserTsn.hsrTpid;
        }
        if (tmpQualifier[5:5]) { 
            PI.l3Offset += 6; 
        }
        
        // Decide ether type
        tmpL2HdrError      = PI.l3Offset + 2 > PI.hdrLength;
        tmpTypeOrLen[15:0] = tmpL2HdrError ? 0: {glPktTmpHdr[PI.l3Offset], glPktTmpHdr[PI.l3Offset+1]};
        glPktTmpHdr[0:8]   = glPktHdr[PI.l3Offset : PI.l3Offset + 8];

        tmpSap[15:0]       = PI.l3Offset + 4 > PI.hdrLength ? 0 :{glPktTmpHdr[2], glPktTmpHdr[3]};
        tmpSapCtl[7:0]     = PI.l3Offset + 5 > PI.hdrLength ? 0 : glPktTmpHdr[4];
        tmpSnapOui[23:0]   = PI.l3Offset + 7 > PI.hdrLength ? 0 :{glPktTmpHdr[5], glPktTmpHdr[6], glPktTmpHdr[7]};

        if( !tmpL2HdrError && (tmpTypeOrLen >= CtlParserEthernet.maxLength) ) {
            // Ethernet II encapsulation
        } else if(!tmpL2HdrError && (tmpSap == 16'hAAAA) && (tmpSapCtl == 8'h03) && 
                  (CtlParserEthernet.allowNoneZeroOui || (tmpSnapOui == 0) ) ) {
            PI.l3Offset   += 6;                // SAP + SAPCTL + OUI
            tmpQualifier[6:6] = 1;
        } else if(!tmpL2HdrError && (PI.l3Offset+4+CtlParserEthernet.ethSapCtlLen) <= PI.hdrLength) {
            tmpQualifier[7:7] = 1;
        } else {
            PI.discard         = 1;
            PI.discardBmp[2:2] = 1;
        }
            
        PI.jumboNum += (!tmpL2HdrError && PI.pktLength > CtlParserEthernet.maxLength) ? 1:0;
        PI.discard  |= tmpL2HdrError;
        PI.discardBmp[3:3] = 1;

        // save current header
        tmpQualifier[15:8] = PI.l3Offset - PI.psrOffset;  // length
        PI.psrOffset       = PI.l3Offset + 2;    // 2 is for TPID, for layer 3 parser
        tmpPr.qualifier    = tmpQualifier;
        // Layer III type decision
        tmpTypeOrLen      = {glPktHdr[PI.l3Offset], glPktHdr[PI.l3Offset+1]};
        switch( tmpTypeOrLen ) {
            case 16'h0800: PI.pktType = PROTO_TYPE_IPV4; break;
            case 16'h86dd: PI.pktType = PROTO_TYPE_IPV6; break;
            case 16'h0806:
            case 16'h8035: PI.pktType = PROTO_TYPE_ARP;  break;
            case 16'h8847:
            case 16'h8848: PI.pktType = PROTO_TYPE_MPLS; break;
            case 16'h8809: PI.pktType = PROTO_TYPE_SLOW; break;
            case 16'h888E: PI.pktType = PROTO_TYPE_EAPOL;break;
            case 16'h88CC: PI.pktType = PROTO_TYPE_LLDP; break;
            case 16'h88B8: PI.pktType = PROTO_TYPE_GOOSE; break;
            case 16'h88BA: PI.pktType = PROTO_TYPE_SMV; break;
            case 16'h88F5: PI.pktType = PROTO_TYPE_MMRP; break;
            case 16'h88F6: PI.pktType = PROTO_TYPE_MVRP; break;
            case 16'h88F7: PI.pktType = PROTO_TYPE_PTP; break;
            case 16'h88FE: PI.pktType = PROTO_TYPE_NCMT; break;
            case 16'h8902: PI.pktType = PROTO_TYPE_CFM; break;
            case 16'h8915: PI.pktType = PROTO_TYPE_ROCE; break;
            case 16'hFEFE: PI.pktType = PROTO_TYPE_ISIS; break;
            default:       PI.pktType = PROTO_TYPE_INVALID;
        }
        if (PI.pktType == PROTO_TYPE_INVALID) {
    
            if (CtlL2HdrProtoCam.valid[0:0] && (CtlL2HdrProtoCam.l2ProtoData0[15:0] & CtlL2HdrProtoCam.l2ProtoMask0[15:0]) == (tmpTypeOrLen & CtlL2HdrProtoCam.l2ProtoMask0)) 
                PI.pktType = CtlL2HdrProtoCam.l3Type0;
    
            if (CtlL2HdrProtoCam.valid[1:1] && (CtlL2HdrProtoCam.l2ProtoData1[15:0] & CtlL2HdrProtoCam.l2ProtoMask1[15:0]) == (tmpTypeOrLen & CtlL2HdrProtoCam.l2ProtoMask1)) 
                PI.pktType = CtlL2HdrProtoCam.l3Type1;
    
            if (CtlL2HdrProtoCam.valid[2:2] && (CtlL2HdrProtoCam.l2ProtoData2[15:0] & CtlL2HdrProtoCam.l2ProtoMask2[15:0]) == (tmpTypeOrLen & CtlL2HdrProtoCam.l2ProtoMask2)) 
                PI.pktType = CtlL2HdrProtoCam.l3Type2;
    
            if (CtlL2HdrProtoCam.valid[3:3] && (CtlL2HdrProtoCam.l2ProtoData3[15:0] & CtlL2HdrProtoCam.l2ProtoMask3[15:0]) == (tmpTypeOrLen & CtlL2HdrProtoCam.l2ProtoMask3)) 
                PI.pktType = CtlL2HdrProtoCam.l3Type3;
    
            if (CtlL2HdrProtoCam.valid[4:4] && (CtlL2HdrProtoCam.l2ProtoData4[15:0] & CtlL2HdrProtoCam.l2ProtoMask4[15:0]) == (tmpTypeOrLen & CtlL2HdrProtoCam.l2ProtoMask4)) 
                PI.pktType = CtlL2HdrProtoCam.l3Type4;
    
            if (CtlL2HdrProtoCam.valid[5:5] && (CtlL2HdrProtoCam.l2ProtoData5[15:0] & CtlL2HdrProtoCam.l2ProtoMask5[15:0]) == (tmpTypeOrLen & CtlL2HdrProtoCam.l2ProtoMask5)) 
                PI.pktType = CtlL2HdrProtoCam.l3Type5;
    
            if (CtlL2HdrProtoCam.valid[6:6] && (CtlL2HdrProtoCam.l2ProtoData6[15:0] & CtlL2HdrProtoCam.l2ProtoMask6[15:0]) == (tmpTypeOrLen & CtlL2HdrProtoCam.l2ProtoMask6)) 
                PI.pktType = CtlL2HdrProtoCam.l3Type6;
    
            if (CtlL2HdrProtoCam.valid[7:7] && (CtlL2HdrProtoCam.l2ProtoData7[15:0] & CtlL2HdrProtoCam.l2ProtoMask7[15:0]) == (tmpTypeOrLen & CtlL2HdrProtoCam.l2ProtoMask7)) 
                PI.pktType = CtlL2HdrProtoCam.l3Type7;
    
        }
        PI.l3Type = PI.pktType;
    }

    // Decide Layer 3 type
    if (PI.pktType > PROTO_TYPE_ETH && PI.pktType < PROTO_TYPE_UDP) {
        PI.l3Offset       = PI.psrOffset - 2;
        if (PI.pktType == PROTO_TYPE_IPV4) {    // IPv4
            tmpIhl        = glPktHdr[PI.psrOffset][3:0]; 
            tmpL3HdrError = (tmpIhl << 2) > (PI.hdrLength - PI.psrOffset);
            if (!tmpL3HdrError) {
                tmpPr                = findPrByType( PROTO_TYPE_IPV4 );
                tmpPr.offset         = PI.psrOffset;
                tmpPr.protocol       = PROTO_TYPE_IPV4;
                // ipDa isMC
                tmpPr.qualifier[0:0] = glPktHdr[PI.psrOffset+16] == 8'hE0;
                tmpFragOffset[12:0] = {glPktTmpL3Hdr[6][4:0], glPktTmpL3Hdr[7]};
                // is1stFragment
                tmpPr.qualifier[1:1] = tmpFragOffset == 1;
                // isFragmented
                tmpPr.qualifier[2:2] = tmpFragOffset != 0;
                // hasOption
                tmpPr.qualifier[3:3] = tmpIhl > 5;
                tmpPr.qualifier[15:8]= tmpIhl << 2;
                tmpL3NextProto       = glPktHdr[PI.psrOffset + 9];
                PI.psrOffset        += qualifier[15:8];
            }
        } else if (PI.pktType == PROTO_TYPE_IPV6) {    // IPv6
            tmpL3HdrError = 40 > PI.hdrLength - PI.psrOffset;
            if (!tmpL3HdrError) {
                tmpPr                = findPrByType( PROTO_TYPE_IPV6 );
                tmpPr.offset         = PI.psrOffset;
                tmpPr.protocol       = PROTO_TYPE_IPV6;
                // ipDa isMC
                tmpPr.qualifier[0:0] = glPktHdr[PI.psrOffset+24] == 8'hFF;
                tmpL3NextProto       = glPktHdr[PI.psrOffset + 6];
                // hasOption
                tmpPr.qualifier[3:3] = tmpL3NextProto == 0   || /* hop-by-hop */ tmpL3NextProto == 44  || /* Ipv6-fragment */ tmpL3NextProto == 50  || /* ESP */ tmpL3NextProto == 51  || /* AH */ tmpL3NextProto == 60  || /* Destination option */ tmpL3NextProto == 135 || /* Mobility */ tmpL3NextProto == 139 || /* Host identity */ tmpL3NextProto == 140 ;  // Shim6
                PI.psrOffset        += 40;
            }
        
        } else if (PI.pktType == PROTO_TYPE_ARP) {    // ARP, RARP 
            /* hardware type (2-byte), protocol type (2-byte), hardware length (1-byte), 
            protocol length (1-byte), operation (2-byte), sender hardware addres (6-byte),
            sender protocol address (4-byte), receiver hardware address (6-byte), receiver protocol address (4-byte)*/ 
            tmpL3HdrError    = 18 > PI.hdrLength - PI.psrOffset;
            if (!tmpL3HdrError) {
                tmpPr            = findPrByType( PROTO_TYPE_ARP );
                tmpPr.offset     = PI.psrOffset;
                tmpPr.protocol   = PROTO_TYPE_ARP;
            }
        } else if (PI.pktType == PROTO_TYPE_SLOW) {    // EFM 
            /* subtype (1-byte), flags (2-byte), code (1-byte) */
            tmpL3HdrError    = 4 > PI.hdrLength - PI.psrOffset;
            if (!tmpL3HdrError) {
                tmpPr            = findPrByType( PROTO_TYPE_SLOW );
                tmpPr.offset     = PI.psrOffset;
                tmpPr.protocol   = PROTO_TYPE_SLOW;
            }
        } else if (PI.pktType == PROTO_TYPE_EAPOL) {    // EAPoL 
            /* protocol version (1-byte), packet type (1-byte), packet body length (2-byte)*/
            tmpL3HdrError    = 4 > PI.hdrLength - PI.psrOffset;
            if (!tmpL3HdrError) {
                tmpPr            = findPrByType( PROTO_TYPE_EAPOL );
                tmpPr.offset     = PI.psrOffset;
                tmpPr.protocol   = PROTO_TYPE_EAPOL;
            }
        } else if (PI.pktType == PROTO_TYPE_LLDP) {    // LLDP 
            /* chassis ID TLV (4+-byte), port ID TLV (4+-byte), ttl TLV (4-byte), End  TLV (2-byte)*/
            tmpL3HdrError    = 14 > PI.hdrLength - PI.psrOffset;
            if (!tmpL3HdrError) {
                tmpPr            = findPrByType( PROTO_TYPE_LLDP );
                tmpPr.offset     = PI.psrOffset;
                tmpPr.protocol   = PROTO_TYPE_LLDP;
            }
        } else if (PI.pktType == PROTO_TYPE_PTP) {    // PTP 
            /*Msg Type (4-bit), trans spec (4-bit), version (4-bit), reserve (4-bit), msg length (2-byte),
              domain (1-byte), reserve (1-byte), flag (2-byte), correction field (8-byte), reserve (4-byte), 
              source port ID (10-byte), sequence (2-byte), control (1-byte), log msg interval (1-byte)*/
            tmpL3HdrError    = 34 > PI.hdrLength - PI.psrOffset;
            if (!tmpL3HdrError) {
                tmpPr            = findPrByType( PROTO_TYPE_PTP );
                tmpPr.offset     = PI.psrOffset;
                tmpPr.protocol   = PROTO_TYPE_PTP;
                PI.isPtp         = 1;
            }
        } else if (PI.pktType == PROTO_TYPE_CFM) {    // CFM 
            /* MD level (3-bit), version (5-bit), opCode (1-byte), flags (1-byte), sequence (1-byte),
               Loopback transaction ID (4-tyte), LTR Transaction ID (4-byte), LTM transaction ID (4-byte)*/
            tmpL3HdrError    = 16 > PI.hdrLength - PI.psrOffset;
            if (!tmpL3HdrError) {
                tmpPr            = findPrByType( PROTO_TYPE_CFM );
                tmpPr.offset     = PI.psrOffset;
                tmpPr.protocol   = PROTO_TYPE_CFM;
                PI.isCfm         = 1;
                tmpOpcode        = glPktHdr[ PI.psrOffset + 1];
                // CCM flag 
                tmpPr.qualifier[0:0] = (tmOpcode == CtlParserEthernet.ccmOpcode);
                // LM flag
                tmpPr.qualifier[1:1] = (tmOpcode == CtlParserEthernet.lmmOpcode) || (tmOpcode == CtlParserEthernet.lmrOpcode);
                // DM flag
                tmpPr.qualifier[2:2] = (tmOpcode == CtlParserEthernet.dmmOpcode) || (tmOpcode == CtlParserEthernet.dmrOpcode);
            }
        } else if (PI.pktType == PROTO_TYPE_ISIS) {    // ISIS
            /* Intra domain routing protocol discriminator (1-byte), length (1-byte), 
               version/protocol ID extension (1-byte), ID length (1-byte), reserve (3-bit), PDU type (5-bit), 
               version (1-byte), reserve (1-byte), maximum area address (1-byte)*/
            tmpL3HdrError    = 8 > PI.hdrLength - PI.psrOffset;
            if (!tmpL3HdrError) {
                tmpPr            = findPrByType( PROTO_TYPE_ISIS );
                tmpPr.offset     = PI.psrOffset;
                tmpPr.protocol   = PROTO_TYPE_ISIS;
            }
        }
    
        if (tmpL3HdrError) {
            PI.discard         = 1;
            PI.discardBmp[4:4] = 1;
        }
        // Layer IV type decision
        switch( tmpL3NextProto ) {
            case 8'h06: PI.pktType = PROTO_TYPE_TCP; break;
            case 8'h11: PI.pktType = PROTO_TYPE_UDP; break;
            default:    PI.pktType = PROTO_TYPE_INVALID;
        }
        if (PI.l4Type == PROTO_TYPE_INVALID) { 
    
            if (CtlL3HdrProtoCam.isValid[0:0] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask0) == 
             (CtlL3HdrProtoCam.l3TypeData0 & CtlL3HdrProtoCam.l3TypeMask0)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask0) == 
                 (CtlL3HdrProtoCam.l3ProtoData0 & CtlL3HdrProtoCam.l3ProtoMask0))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type0;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }
    
            if (CtlL3HdrProtoCam.isValid[1:1] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask1) == 
             (CtlL3HdrProtoCam.l3TypeData1 & CtlL3HdrProtoCam.l3TypeMask1)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask1) == 
                 (CtlL3HdrProtoCam.l3ProtoData1 & CtlL3HdrProtoCam.l3ProtoMask1))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type1;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }
    
            if (CtlL3HdrProtoCam.isValid[2:2] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask2) == 
             (CtlL3HdrProtoCam.l3TypeData2 & CtlL3HdrProtoCam.l3TypeMask2)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask2) == 
                 (CtlL3HdrProtoCam.l3ProtoData2 & CtlL3HdrProtoCam.l3ProtoMask2))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type2;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }
    
            if (CtlL3HdrProtoCam.isValid[3:3] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask3) == 
             (CtlL3HdrProtoCam.l3TypeData3 & CtlL3HdrProtoCam.l3TypeMask3)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask3) == 
                 (CtlL3HdrProtoCam.l3ProtoData3 & CtlL3HdrProtoCam.l3ProtoMask3))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type3;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }

            if (CtlL3HdrProtoCam.isValid[4:4] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask4) == 
             (CtlL3HdrProtoCam.l3TypeData4 & CtlL3HdrProtoCam.l3TypeMask4)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask4) == 
                 (CtlL3HdrProtoCam.l3ProtoData4 & CtlL3HdrProtoCam.l3ProtoMask4))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type4;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }
    
            if (CtlL3HdrProtoCam.isValid[5:5] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask5) == 
             (CtlL3HdrProtoCam.l3TypeData5 & CtlL3HdrProtoCam.l3TypeMask5)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask5) == 
                 (CtlL3HdrProtoCam.l3ProtoData5 & CtlL3HdrProtoCam.l3ProtoMask5))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type5;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }
    
            if (CtlL3HdrProtoCam.isValid[6:6] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask6) == 
             (CtlL3HdrProtoCam.l3TypeData6 & CtlL3HdrProtoCam.l3TypeMask6)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask6) == 
                 (CtlL3HdrProtoCam.l3ProtoData6 & CtlL3HdrProtoCam.l3ProtoMask6))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type6;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }
    
            if (CtlL3HdrProtoCam.isValid[7:7] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask7) == 
             (CtlL3HdrProtoCam.l3TypeData7 & CtlL3HdrProtoCam.l3TypeMask7)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask7) == 
                 (CtlL3HdrProtoCam.l3ProtoData7 & CtlL3HdrProtoCam.l3ProtoMask7))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type7;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }
    
            if (CtlL3HdrProtoCam.isValid[8:8] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask8) == 
             (CtlL3HdrProtoCam.l3TypeData8 & CtlL3HdrProtoCam.l3TypeMask8)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask8) == 
                 (CtlL3HdrProtoCam.l3ProtoData8 & CtlL3HdrProtoCam.l3ProtoMask8))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type8;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }
    
            if (CtlL3HdrProtoCam.isValid[9:9] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask9) == 
             (CtlL3HdrProtoCam.l3TypeData9 & CtlL3HdrProtoCam.l3TypeMask9)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask9) == 
                 (CtlL3HdrProtoCam.l3ProtoData9 & CtlL3HdrProtoCam.l3ProtoMask9))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type9;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }
    
            if (CtlL3HdrProtoCam.isValid[10:10] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask10) == 
             (CtlL3HdrProtoCam.l3TypeData10 & CtlL3HdrProtoCam.l3TypeMask10)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask10) == 
                 (CtlL3HdrProtoCam.l3ProtoData10 & CtlL3HdrProtoCam.l3ProtoMask10))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type10;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }
    
            if (CtlL3HdrProtoCam.isValid[11:11] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask11) == 
             (CtlL3HdrProtoCam.l3TypeData11 & CtlL3HdrProtoCam.l3TypeMask11)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask11) == 
                 (CtlL3HdrProtoCam.l3ProtoData11 & CtlL3HdrProtoCam.l3ProtoMask11))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type11;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }
    
            if (CtlL3HdrProtoCam.isValid[12:12] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask12) == 
             (CtlL3HdrProtoCam.l3TypeData12 & CtlL3HdrProtoCam.l3TypeMask12)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask12) == 
                 (CtlL3HdrProtoCam.l3ProtoData12 & CtlL3HdrProtoCam.l3ProtoMask12))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type12;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }
    
            if (CtlL3HdrProtoCam.isValid[13:13] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask13) == 
             (CtlL3HdrProtoCam.l3TypeData13 & CtlL3HdrProtoCam.l3TypeMask13)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask13) == 
                 (CtlL3HdrProtoCam.l3ProtoData13 & CtlL3HdrProtoCam.l3ProtoMask13))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type13;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }
    
            if (CtlL3HdrProtoCam.isValid[14:14] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask14) == 
             (CtlL3HdrProtoCam.l3TypeData14 & CtlL3HdrProtoCam.l3TypeMask14)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask14) == 
                 (CtlL3HdrProtoCam.l3ProtoData14 & CtlL3HdrProtoCam.l3ProtoMask14))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type14;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }
    
            if (CtlL3HdrProtoCam.isValid[15:15] && ((PI.l3Type & CtlL3HdrProtoCam.l3TypeMask15) == 
             (CtlL3HdrProtoCam.l3TypeData15 & CtlL3HdrProtoCam.l3TypeMask15)) && 
               ((tmpL3NextProto & CtlL3HdrProtoCam.l3ProtoMask15) == 
                 (CtlL3HdrProtoCam.l3ProtoData15 & CtlL3HdrProtoCam.l3ProtoMask15))) {
                PI.pktType     = CtlL3HdrProtoCam.l4Type15;
                tmpPr.protocol = CtlL3HdrProtoCam.protocol;
            }
    
        }
        // V6 MLD or ND
        if( (PI.l4Type == PROTO_TYPE_ICMP) && (PI.l3Type == PROTO_TYPE_IPV6) && (PI.l4Offset < PI.hdrLength)) {
            if( glPktHdr[ PI.l4Offset ] == 128 || glPktHdr[ PI.l4Offset ] == 129 ) {
                PI.l4Type           = PROTO_TYPE_V6PING;
            } else if( glPktHdr[ PI.l4Offset ] == 130 || glPktHdr[ PI.l4Offset ] == 131 || glPktHdr[ PI.l4Offset ] == 132 ) { 
                PI.l4Type           = PROTO_TYPE_MLD;
            } else if( glPktHdr[ PI.l4Offset ] == 133 || glPktHdr[ PI.l4Offset ] == 134 || glPktHdr[ PI.l4Offset ] == 135 
                    || glPktHdr[ PI.l4Offset ] == 136 || glPktHdr[ PI.l4Offset ] == 137 ) { 
                PI.l4Type           = PROTO_TYPE_ND;
            }
        }
        if ((PI.l4Type == PROTO_TYPE_ICMP) && (PI.l3Type == PROTO_TYPE_IPV4) && (PI.l4Offset < PI.hdrLength ) &&
            ((glPktHdr[PI.l4Offset] == 0) || (glPktHdr[PI.l4Offset] == 8)) ) {
            tmpIsV4PingPacket       = 1;
        }
        PI.l4Type = PI.pktType;
    }

    // Layer 4 
    if (PI.pktType >= PROTO_TYPE_UDP) {
        PI.l4Offset     = PI.psrOffset;
        if (PI.pktType == PROTO_TYPE_TCP) {         // TCP
            tmpL4HdrError = 20 > PI.hdrLength - PI.psrOffset;
            if (!tmpL4HdrError) {
                tmpPr          = findPrByType( PROTO_TYPE_TCP );
                tmpPr.offset   = PI.psrOffset;
                tmpPr.protocol = PROTO_TYPE_TCP;
                tmpPr.qualifier[15:8] = 20;
                tmpL4DestPort  = {glPktHdr[PI.psrOffset + 2], glPktHdr[PI.psrOffset + 3]};
                tmpPr.qualifier[0:0]  = tmpL4DestPort == {glPktHdr[PI.psrOffset], glPktHdr[PI.psrOffset + 1]};
                tmpPr.qualifier[1:1]  = {glPktHdr[PI.psrOffset+4], glPktHdr[PI.psrOffset+7]} == 32'h0;
            }
        } else if (PI.pktType == PROTO_TYPE_UDP) { // UDP
            tmpL4HdrError  = 8 > PI.hdrLength - PI.psrOffset;
            if (!tmpL4HdrError) {
                tmpPr          = findPrByType( PROTO_TYEP_UDP );
                tmpPr.protocol = PROTO_TYPE_UDP;
                tmpPr.qualifier[15:8] = 8;
                tmpL4DestPort  = {glPktHdr[PI.psrOffset + 2], glPktHdr[PI.psrOffset + 3]};
                tmpPr.qualifier[0:0]  = tmpL4DestPort == {glPktHdr[PI.psrOffset], glPktHdr[PI.psrOffset + 1]};
            }
        }
        // parser common UDP payload
        if ((PI.l4Type == PROTO_TYPE_UDP) && (tmpL4DestPort == CtlParserL4Port.ptpPort0 || tmpL4DestPort == CtlParserL4Port.ptpPort1)) {   // PTP
            tmpL4HdrError  = 34 > PI.hdrLength - PI.psrOffset - 8;
            if (!tmpL4HdrError) {
                PI.isPtp       = 1;
                tmpPr          = findPrByType( PROTO_TYPE_PTP );
                tmpPr.offset   = PI.psrOffset + 8;
                tmpPr.protocol = PROTO_TYPE_PTP;
            }
        } else if ((PI.l4Type == PROTO_TYPE_UDP) && (tmpL4DestPort == CtlParserL4Port.bfdPort0 || tmpL4DestPort == CtlParserL4Port.bfdPort1)) {  // BFD
            /*version (3-bit), diagnostic (5-bit), state (2-bit), P (1-bit), F (1-bit), C (1-bit), A (1-bit), D (1-bit), M (1-bit),
              detect multi (1-byte), length (1-byte), my discriminator (4-byte), your discriminator (4-byte),
              desired min Tx interval (4-byte), required Min Rx interval (4-byte), required min Echo Rx interval (4-byte)*/
            tmpL4HdrError  = 24 > PI.hdrLength - PI.psrOffset - 8;
            if (!tmpL4HdrError) {
                PI.isBfd       = 1;
                tmpPr          = findPrByType( PROTO_TYPE_BFD );
                tmpPr.offset   = PI.psrOffset + 8;
                tmpPr.protocol = PROTO_TYPE_BFD;
            }
        } else if ((PI.l4Type == PROTO_TYPE_UDP) && (tmpL4DestPort == CtlParserL4Port.bfdEcho)) {  // BFD Echo
            PI.isBfdEcho       = 1;
        }
    }
    
    tmpIsAvb = (PI.l4Type == PROTO_TYPE_UDP) && (tmpL4DestPort >= CtlParserL4Port.avbPortLo) && (tmpL4DestPort <= CtlParserL4Port.avbPortHi);
    if( (tmpIsAvb && (tmpL4DestPort[0:0] == 0)) || PI.l3Type == PROTO_TYPE_1722 ) {
        PI.isAvFrame   = 1;
        PI.rtpPkt      = 1;
    } else if ( tmpIsAvb && (tmpL4DestPort[0:0] == 1) ) { // RTCP
        PI.discard     = PI.discard | 1;
        PI.copyToCpu   = 1;
        PI.rtcpPkt     = 1;
    }
    
    if( (PI.l4Type == PROTO_TYPE_UDP) && ((tmpL4DestPort == CtlParserL4Port.snmpPort0)
                            ||(tmpL4DestPort == CtlParserL4Port.snmpPort1)) ) {
        PI.isSnmp      = 1;
        PI.snmpPkt     = 1;
    }
        
    // User define field
    tmpIdx[5:0]         = {PI.l3Type[2:0], PI.l4Type[2:0]};   // Truncate l3Type and l4Type
    DsMemUdfOffsetVal   = DsMemUdfOffset[ tmpIdx ];
    tmpOffset0[7:0]     = DsMemUdfOffsetVal.udfOffset0 + PI.l3Offset;
    if( tmpOffset0 > PI.hdrLength ) {
        PI.userData0    = 0;
    } else {
        glPktTmpUdfHdr[0:1]= glPktHdr[tmpOffset0 : tmpOffset0 + 1];
        PI.userData0    = {glPktTmpUdfHdr[0], glPktTmpUdfHdr[1]};
    }
    tmpOffset1[7:0]     = DsMemUdfOffsetVal.udfOffset1 + PI.l3Offset;
    if( tmpOffset1 > PI.hdrLength ) {
        PI.userData1    = 0;
    } else {
        glPktTmpUdfHdr[0:1]= glPktHdr[tmpOffset1 : tmpOffset1 + 1];
        PI.userData1    = {glPktTmpUdfHdr[0], glPktTmpUdfHdr[1]};
    }


    // DOS 
    tmpPr        = findPrByType( PROTO_TYPE_ETH );
    tmpMacAddrEq = glPktHdr[tmpPr.offset : tmpPr.offset+5] == glPktHdr[tmpPr.offset+6 : tmpPr.offset+11];
    PI.dosDropBmp    = 0;
    if (CtlDosControl.macSaEqMacDaDrop && tmpMacAddrEq) {
        PI.discard         = PI.discard | 1;
        PI.dosDropBmp = 1;
    }

    if (PI.l3Type == PROTO_TYPE_IPV4) {
        tmpIpPr = findPrByType( PROTO_TYPE_IPV4 );
        tmpIpSaEqDa = glPktHdr[tmpIpPr.offset+12 : tmpIpPr.offset+15] == glPktHdr[tmpIpPr.offset+16 : tmpIpPr.offset+19];
    } else if (PI.l3Type == PROTO_TYPE_IPV6) {
        tmpIpPr = findPrByType( PROTO_TYPE_IPV6 );
        tmpIpSaEqDa = glPktHdr[tmpIpPr.offset+8 : tmpIpPr.offset+23] == glPktHdr[tmpIpPr.offset+24 : tmpIpPr.offset+39];
    }
    if ( !tmpL3HdrError && CtlDosControl.sipEqDipDrop && tmpIpSaEqDa ) {
        PI.discard         = PI.discard | 1;
        PI.dosDropBmp[2:2] = 1;
    }
    if ( !tmpL4HdrError && CtlDosControl.icmpFragDrop && tmpIpPr.qualifier[2:2] && (PI.l4Type == PROTO_TYPE_ICMP) ) {
        PI.discard         = PI.discard | 1;
        PI.dosDropBmp[9:9] = 1;
    }
    tmpV4PingSizeCheckFailed = CtlDosControl.icmpV4PingSizeCheck && tmpIsV4PingPacket && 
                               (PI.pktLength > CtlDosControl.icmpV4MaxSize);
    tmpV6PingSizeCheckFailed = CtlDosControl.icmpV6PingSizeCheck && PI.l4Type == PROTO_TYPE_V6PING && 
                               (PI.pktLength > CtlDosControl.icmpV6MaxSize);
    if( tmpV4PingSizeCheckFailed || tmpV6PingSizeCheckFailed ) {
        PI.discard           = PI.discard | 1;
        PI.dosDropBmp[10:10] = 1;
    }

    tmpIsTcp = (PI.l4Type == PROTO_TYPE_TCP) && !tmpL4HdrError;
    tmpPr    = findPrByType( PROTO_TYPE_TCP );
    if ( CtlDosControl.tcpFlagsCtl0Seq0En && tmpPr.qualifier[1:1] && (glPktHdr[tmpPr.offset+13][5:0] == 0) && tmpIsTcp ) {
        PI.discard         = PI.discard | 1;
        PI.dosDropBmp[1:1] = 1;
    }
    if ( CtlDosControl.tcpSportEqDportDrop && tmpIsTcp && tmpPr.qualifier[0:0] ) {
        PI.discard         = PI.discard | 1;
        PI.dosDropBmp[4:4] = 1;
    }
    if ( CtlDosControl.tcpFlagSynFinDrop && tmpIsTcp && (glPktHdr[tmpPr.offset+13][1:0] == 2'h11) ) {
        PI.discard         = PI.discard | 1;
        PI.dosDropBmp[5:5] = 1;
    }
    if ( CtlDosControl.tcpFlagFinUrgPshSeq0Drop && tmpIsTcp && tmpPr.qualifier[1:1] && 
       ((glPktHdr[tmpPr.offset+13][5:0] & 6'h29) == 6'h29)) {
        PI.discard         = PI.discard | 1;
        PI.dosDropBmp[6:6] = 1;
    }
    if ( CtlDosControl.tcpFragOffset1Drop && tmpIsTcp && tmpIpPr.qualifier[1:1] ) {
        PI.discard         = PI.discard | 1;
        PI.dosDropBmp[7:7] = 1;
    }
    if ( CtlDosControl.tcpHdrPartialDrop && glPktHdr[tmpIpPr.offset+6][5:5] && !tmpIpPr.qualifier[2:2] &&
         tmpPr.qualifier[15:8] < CtlParserEthernet.tcpHdrMinSize) {
        PI.discard         = PI.discard | 1;
        PI.dosDropBmp[8:8] = 1;
    }

    tmpPr = findPrByType( PROTO_TYEP_UDP );
    tmpIsUdp = !tmpL4HdrError && (PI.l4Type == PROTO_TYPE_UDP);
    if ( tmpIsUdp && CtlDosControl.udpSportEqDportDrop && tmpPr.qualifier[0:0] ) {
        PI.discard         = PI.discard | 1;
        PI.dosDropBmp[3:3] = 1;
    }
    CtlPktParserLog.userData0    = PI.userData0;
    CtlPktParserLog.userData1    = PI.userData1;
    CtlPktParserLog.randomSeed    = PI.randomSeed;
    CtlPktParserLog.dosDropBmp    = PI.dosDropBmp;
    CtlPktParserLog.l2Type    = PI.l2Type;
    CtlPktParserLog.stagValid    = PI.stagValid;
    CtlPktParserLog.ctagValid    = PI.ctagValid;
    CtlPktParserLog.rtagValid    = PI.rtagValid;
    CtlPktParserLog.l3Type    = PI.l3Type;
    CtlPktParserLog.l4Type   = PI.l4Type;
    CtlPktParserLog.l2HdrError    = PI.l2HdrError;
    CtlPktParserLog.l3HdrError    = PI.l3HdrError;
    CtlPktParserLog.l4HdrError    = PI.l4HdrError;
    CtlPktParserLog.rtcpPkt    = PI.rtcpPkt;
    CtlPktParserLog.isPtp    = PI.isPtp;
    CtlPktParserLog.rtpPkt    = PI.rtpPkt;
    CtlPktParserLog.snmpPkt    = PI.snmpPkt;
    CtlPktParserLog.isBfd    = PI.isBfd;
    CtlPktParserLog.jumboNum    = PI.jumboNum;
}

    
