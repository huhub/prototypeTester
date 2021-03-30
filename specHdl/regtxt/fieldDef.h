// CtlDosControl
`define    CTL_DOS_CONTROL_RANGE                                            13:0
`define    CTL_DOS_CONTROL_WIDTH                                            14

`define    CTL_DOS_CONTROL_MAC_SA_EQ_MAC_DA_DROP_RANGE                      0:0
`define    CTL_DOS_CONTROL_MAC_SA_EQ_MAC_DA_DROP_WIDTH                      1

`define    CTL_DOS_CONTROL_SIP_EQ_DIP_DROP_RANGE                            1:1
`define    CTL_DOS_CONTROL_SIP_EQ_DIP_DROP_WIDTH                            1

`define    CTL_DOS_CONTROL_ICMP_FRAG_DROP_RANGE                             2:2
`define    CTL_DOS_CONTROL_ICMP_FRAG_DROP_WIDTH                             1

`define    CTL_DOS_CONTROL_ICMP_V4_PING_SIZE_CHECK_RANGE                    3:3
`define    CTL_DOS_CONTROL_ICMP_V4_PING_SIZE_CHECK_WIDTH                    1

`define    CTL_DOS_CONTROL_ICMP_V4_MAX_SIZE_RANGE                           4:4
`define    CTL_DOS_CONTROL_ICMP_V4_MAX_SIZE_WIDTH                           1

`define    CTL_DOS_CONTROL_ICMP_V6_PING_SIZE_CHECK_RANGE                    5:5
`define    CTL_DOS_CONTROL_ICMP_V6_PING_SIZE_CHECK_WIDTH                    1

`define    CTL_DOS_CONTROL_ICMP_V6_MAX_SIZE_RANGE                           6:6
`define    CTL_DOS_CONTROL_ICMP_V6_MAX_SIZE_WIDTH                           1

`define    CTL_DOS_CONTROL_TCP_FLAGS_CTL0_SEQ0_EN_RANGE                     7:7
`define    CTL_DOS_CONTROL_TCP_FLAGS_CTL0_SEQ0_EN_WIDTH                     1

`define    CTL_DOS_CONTROL_TCP_SPORT_EQ_DPORT_DROP_RANGE                    8:8
`define    CTL_DOS_CONTROL_TCP_SPORT_EQ_DPORT_DROP_WIDTH                    1

`define    CTL_DOS_CONTROL_TCP_FLAG_SYN_FIN_DROP_RANGE                      9:9
`define    CTL_DOS_CONTROL_TCP_FLAG_SYN_FIN_DROP_WIDTH                      1

`define    CTL_DOS_CONTROL_TCP_FLAG_FIN_URG_PSH_SEQ0_DROP_RANGE             10:10
`define    CTL_DOS_CONTROL_TCP_FLAG_FIN_URG_PSH_SEQ0_DROP_WIDTH             1

`define    CTL_DOS_CONTROL_TCP_FRAG_OFFSET1_DROP_RANGE                      11:11
`define    CTL_DOS_CONTROL_TCP_FRAG_OFFSET1_DROP_WIDTH                      1

`define    CTL_DOS_CONTROL_TCP_HDR_PARTIAL_DROP_RANGE                       12:12
`define    CTL_DOS_CONTROL_TCP_HDR_PARTIAL_DROP_WIDTH                       1

`define    CTL_DOS_CONTROL_UDP_SPORT_EQ_DPORT_DROP_RANGE                    13:13
`define    CTL_DOS_CONTROL_UDP_SPORT_EQ_DPORT_DROP_WIDTH                    1

// CtlL2HdrProtoCam
`define    CTL_L2_HDR_PROTO_CAM_RANGE                                       24:0
`define    CTL_L2_HDR_PROTO_CAM_WIDTH                                       25

`define    CTL_L2_HDR_PROTO_CAM_VALID_RANGE                                 0:0
`define    CTL_L2_HDR_PROTO_CAM_VALID_WIDTH                                 1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA0_RANGE                        1:1
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA0_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK0_RANGE                        2:2
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK0_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE0_RANGE                              3:3
`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE0_WIDTH                              1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA1_RANGE                        4:4
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA1_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK1_RANGE                        5:5
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK1_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE1_RANGE                              6:6
`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE1_WIDTH                              1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA2_RANGE                        7:7
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA2_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK2_RANGE                        8:8
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK2_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE2_RANGE                              9:9
`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE2_WIDTH                              1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA3_RANGE                        10:10
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA3_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK3_RANGE                        11:11
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK3_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE3_RANGE                              12:12
`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE3_WIDTH                              1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA4_RANGE                        13:13
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA4_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK4_RANGE                        14:14
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK4_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE4_RANGE                              15:15
`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE4_WIDTH                              1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA5_RANGE                        16:16
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA5_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK5_RANGE                        17:17
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK5_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE5_RANGE                              18:18
`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE5_WIDTH                              1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA6_RANGE                        19:19
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA6_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK6_RANGE                        20:20
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK6_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE6_RANGE                              21:21
`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE6_WIDTH                              1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA7_RANGE                        22:22
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_DATA7_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK7_RANGE                        23:23
`define    CTL_L2_HDR_PROTO_CAM_L2_PROTO_MASK7_WIDTH                        1

`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE7_RANGE                              24:24
`define    CTL_L2_HDR_PROTO_CAM_L3_TYPE7_WIDTH                              1

// CtlL3HdrProtoCam
`define    CTL_L3_HDR_PROTO_CAM_RANGE                                       81:0
`define    CTL_L3_HDR_PROTO_CAM_WIDTH                                       82

`define    CTL_L3_HDR_PROTO_CAM_IS_VALID_RANGE                              0:0
`define    CTL_L3_HDR_PROTO_CAM_IS_VALID_WIDTH                              1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK0_RANGE                         1:1
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK0_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA0_RANGE                         2:2
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA0_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK0_RANGE                        3:3
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK0_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA0_RANGE                        4:4
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA0_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE0_RANGE                              5:5
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE0_WIDTH                              1

`define    CTL_L3_HDR_PROTO_CAM_PROTOCOL_RANGE                              6:6
`define    CTL_L3_HDR_PROTO_CAM_PROTOCOL_WIDTH                              1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK1_RANGE                         7:7
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK1_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA1_RANGE                         8:8
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA1_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK1_RANGE                        9:9
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK1_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA1_RANGE                        10:10
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA1_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE1_RANGE                              11:11
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE1_WIDTH                              1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK2_RANGE                         12:12
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK2_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA2_RANGE                         13:13
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA2_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK2_RANGE                        14:14
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK2_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA2_RANGE                        15:15
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA2_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE2_RANGE                              16:16
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE2_WIDTH                              1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK3_RANGE                         17:17
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK3_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA3_RANGE                         18:18
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA3_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK3_RANGE                        19:19
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK3_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA3_RANGE                        20:20
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA3_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE3_RANGE                              21:21
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE3_WIDTH                              1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK4_RANGE                         22:22
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK4_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA4_RANGE                         23:23
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA4_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK4_RANGE                        24:24
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK4_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA4_RANGE                        25:25
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA4_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE4_RANGE                              26:26
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE4_WIDTH                              1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK5_RANGE                         27:27
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK5_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA5_RANGE                         28:28
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA5_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK5_RANGE                        29:29
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK5_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA5_RANGE                        30:30
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA5_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE5_RANGE                              31:31
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE5_WIDTH                              1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK6_RANGE                         32:32
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK6_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA6_RANGE                         33:33
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA6_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK6_RANGE                        34:34
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK6_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA6_RANGE                        35:35
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA6_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE6_RANGE                              36:36
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE6_WIDTH                              1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK7_RANGE                         37:37
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK7_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA7_RANGE                         38:38
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA7_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK7_RANGE                        39:39
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK7_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA7_RANGE                        40:40
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA7_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE7_RANGE                              41:41
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE7_WIDTH                              1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK8_RANGE                         42:42
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK8_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA8_RANGE                         43:43
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA8_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK8_RANGE                        44:44
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK8_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA8_RANGE                        45:45
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA8_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE8_RANGE                              46:46
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE8_WIDTH                              1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK9_RANGE                         47:47
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK9_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA9_RANGE                         48:48
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA9_WIDTH                         1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK9_RANGE                        49:49
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK9_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA9_RANGE                        50:50
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA9_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE9_RANGE                              51:51
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE9_WIDTH                              1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK10_RANGE                        52:52
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK10_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA10_RANGE                        53:53
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA10_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK10_RANGE                       54:54
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK10_WIDTH                       1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA10_RANGE                       55:55
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA10_WIDTH                       1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE10_RANGE                             56:56
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE10_WIDTH                             1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK11_RANGE                        57:57
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK11_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA11_RANGE                        58:58
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA11_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK11_RANGE                       59:59
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK11_WIDTH                       1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA11_RANGE                       60:60
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA11_WIDTH                       1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE11_RANGE                             61:61
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE11_WIDTH                             1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK12_RANGE                        62:62
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK12_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA12_RANGE                        63:63
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA12_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK12_RANGE                       64:64
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK12_WIDTH                       1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA12_RANGE                       65:65
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA12_WIDTH                       1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE12_RANGE                             66:66
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE12_WIDTH                             1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK13_RANGE                        67:67
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK13_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA13_RANGE                        68:68
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA13_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK13_RANGE                       69:69
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK13_WIDTH                       1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA13_RANGE                       70:70
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA13_WIDTH                       1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE13_RANGE                             71:71
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE13_WIDTH                             1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK14_RANGE                        72:72
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK14_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA14_RANGE                        73:73
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA14_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK14_RANGE                       74:74
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK14_WIDTH                       1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA14_RANGE                       75:75
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA14_WIDTH                       1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE14_RANGE                             76:76
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE14_WIDTH                             1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK15_RANGE                        77:77
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_MASK15_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA15_RANGE                        78:78
`define    CTL_L3_HDR_PROTO_CAM_L3_TYPE_DATA15_WIDTH                        1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK15_RANGE                       79:79
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_MASK15_WIDTH                       1

`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA15_RANGE                       80:80
`define    CTL_L3_HDR_PROTO_CAM_L3_PROTO_DATA15_WIDTH                       1

`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE15_RANGE                             81:81
`define    CTL_L3_HDR_PROTO_CAM_L4_TYPE15_WIDTH                             1

// CtlParserEthernet
`define    CTL_PARSER_ETHERNET_RANGE                                        11:0
`define    CTL_PARSER_ETHERNET_WIDTH                                        12

`define    CTL_PARSER_ETHERNET_SVLAN_TPID_RANGE                             0:0
`define    CTL_PARSER_ETHERNET_SVLAN_TPID_WIDTH                             1

`define    CTL_PARSER_ETHERNET_CVLAN_TPID_RANGE                             1:1
`define    CTL_PARSER_ETHERNET_CVLAN_TPID_WIDTH                             1

`define    CTL_PARSER_ETHERNET_STAG_FIRST_RANGE                             2:2
`define    CTL_PARSER_ETHERNET_STAG_FIRST_WIDTH                             1

`define    CTL_PARSER_ETHERNET_MAX_LENGTH_RANGE                             3:3
`define    CTL_PARSER_ETHERNET_MAX_LENGTH_WIDTH                             1

`define    CTL_PARSER_ETHERNET_ALLOW_NONE_ZERO_OUI_RANGE                    4:4
`define    CTL_PARSER_ETHERNET_ALLOW_NONE_ZERO_OUI_WIDTH                    1

`define    CTL_PARSER_ETHERNET_ETH_SAP_CTL_LEN_RANGE                        5:5
`define    CTL_PARSER_ETHERNET_ETH_SAP_CTL_LEN_WIDTH                        1

`define    CTL_PARSER_ETHERNET_CCM_OPCODE_RANGE                             6:6
`define    CTL_PARSER_ETHERNET_CCM_OPCODE_WIDTH                             1

`define    CTL_PARSER_ETHERNET_LMM_OPCODE_RANGE                             7:7
`define    CTL_PARSER_ETHERNET_LMM_OPCODE_WIDTH                             1

`define    CTL_PARSER_ETHERNET_LMR_OPCODE_RANGE                             8:8
`define    CTL_PARSER_ETHERNET_LMR_OPCODE_WIDTH                             1

`define    CTL_PARSER_ETHERNET_DMM_OPCODE_RANGE                             9:9
`define    CTL_PARSER_ETHERNET_DMM_OPCODE_WIDTH                             1

`define    CTL_PARSER_ETHERNET_DMR_OPCODE_RANGE                             10:10
`define    CTL_PARSER_ETHERNET_DMR_OPCODE_WIDTH                             1

`define    CTL_PARSER_ETHERNET_TCP_HDR_MIN_SIZE_RANGE                       11:11
`define    CTL_PARSER_ETHERNET_TCP_HDR_MIN_SIZE_WIDTH                       1

// CtlParserL4Port
`define    CTL_PARSER_L4_PORT_RANGE                                         8:0
`define    CTL_PARSER_L4_PORT_WIDTH                                         9

`define    CTL_PARSER_L4_PORT_PTP_PORT0_RANGE                               0:0
`define    CTL_PARSER_L4_PORT_PTP_PORT0_WIDTH                               1

`define    CTL_PARSER_L4_PORT_PTP_PORT1_RANGE                               1:1
`define    CTL_PARSER_L4_PORT_PTP_PORT1_WIDTH                               1

`define    CTL_PARSER_L4_PORT_BFD_PORT0_RANGE                               2:2
`define    CTL_PARSER_L4_PORT_BFD_PORT0_WIDTH                               1

`define    CTL_PARSER_L4_PORT_BFD_PORT1_RANGE                               3:3
`define    CTL_PARSER_L4_PORT_BFD_PORT1_WIDTH                               1

`define    CTL_PARSER_L4_PORT_BFD_ECHO_RANGE                                4:4
`define    CTL_PARSER_L4_PORT_BFD_ECHO_WIDTH                                1

`define    CTL_PARSER_L4_PORT_AVB_PORT_LO_RANGE                             5:5
`define    CTL_PARSER_L4_PORT_AVB_PORT_LO_WIDTH                             1

`define    CTL_PARSER_L4_PORT_AVB_PORT_HI_RANGE                             6:6
`define    CTL_PARSER_L4_PORT_AVB_PORT_HI_WIDTH                             1

`define    CTL_PARSER_L4_PORT_SNMP_PORT0_RANGE                              7:7
`define    CTL_PARSER_L4_PORT_SNMP_PORT0_WIDTH                              1

`define    CTL_PARSER_L4_PORT_SNMP_PORT1_RANGE                              8:8
`define    CTL_PARSER_L4_PORT_SNMP_PORT1_WIDTH                              1

// CtlParserTsn
`define    CTL_PARSER_TSN_RANGE                                             2:0
`define    CTL_PARSER_TSN_WIDTH                                             3

`define    CTL_PARSER_TSN_RTAG_TPID_RANGE                                   0:0
`define    CTL_PARSER_TSN_RTAG_TPID_WIDTH                                   1

`define    CTL_PARSER_TSN_PRP_TPID_RANGE                                    1:1
`define    CTL_PARSER_TSN_PRP_TPID_WIDTH                                    1

`define    CTL_PARSER_TSN_HSR_TPID_RANGE                                    2:2
`define    CTL_PARSER_TSN_HSR_TPID_WIDTH                                    1

// CtlPktParserLog
`define    CTL_PKT_PARSER_LOG_RANGE                                         18:0
`define    CTL_PKT_PARSER_LOG_WIDTH                                         19

`define    CTL_PKT_PARSER_LOG_USER_DATA0_RANGE                              0:0
`define    CTL_PKT_PARSER_LOG_USER_DATA0_WIDTH                              1

`define    CTL_PKT_PARSER_LOG_USER_DATA1_RANGE                              1:1
`define    CTL_PKT_PARSER_LOG_USER_DATA1_WIDTH                              1

`define    CTL_PKT_PARSER_LOG_RANDOM_SEED_RANGE                             2:2
`define    CTL_PKT_PARSER_LOG_RANDOM_SEED_WIDTH                             1

`define    CTL_PKT_PARSER_LOG_DOS_DROP_BMP_RANGE                            3:3
`define    CTL_PKT_PARSER_LOG_DOS_DROP_BMP_WIDTH                            1

`define    CTL_PKT_PARSER_LOG_L2_TYPE_RANGE                                 4:4
`define    CTL_PKT_PARSER_LOG_L2_TYPE_WIDTH                                 1

`define    CTL_PKT_PARSER_LOG_STAG_VALID_RANGE                              5:5
`define    CTL_PKT_PARSER_LOG_STAG_VALID_WIDTH                              1

`define    CTL_PKT_PARSER_LOG_CTAG_VALID_RANGE                              6:6
`define    CTL_PKT_PARSER_LOG_CTAG_VALID_WIDTH                              1

`define    CTL_PKT_PARSER_LOG_RTAG_VALID_RANGE                              7:7
`define    CTL_PKT_PARSER_LOG_RTAG_VALID_WIDTH                              1

`define    CTL_PKT_PARSER_LOG_L3_TYPE_RANGE                                 8:8
`define    CTL_PKT_PARSER_LOG_L3_TYPE_WIDTH                                 1

`define    CTL_PKT_PARSER_LOG_L4_TYPE_RANGE                                 9:9
`define    CTL_PKT_PARSER_LOG_L4_TYPE_WIDTH                                 1

`define    CTL_PKT_PARSER_LOG_L2_HDR_ERROR_RANGE                            10:10
`define    CTL_PKT_PARSER_LOG_L2_HDR_ERROR_WIDTH                            1

`define    CTL_PKT_PARSER_LOG_L3_HDR_ERROR_RANGE                            11:11
`define    CTL_PKT_PARSER_LOG_L3_HDR_ERROR_WIDTH                            1

`define    CTL_PKT_PARSER_LOG_L4_HDR_ERROR_RANGE                            12:12
`define    CTL_PKT_PARSER_LOG_L4_HDR_ERROR_WIDTH                            1

`define    CTL_PKT_PARSER_LOG_RTCP_PKT_RANGE                                13:13
`define    CTL_PKT_PARSER_LOG_RTCP_PKT_WIDTH                                1

`define    CTL_PKT_PARSER_LOG_IS_PTP_RANGE                                  14:14
`define    CTL_PKT_PARSER_LOG_IS_PTP_WIDTH                                  1

`define    CTL_PKT_PARSER_LOG_RTP_PKT_RANGE                                 15:15
`define    CTL_PKT_PARSER_LOG_RTP_PKT_WIDTH                                 1

`define    CTL_PKT_PARSER_LOG_SNMP_PKT_RANGE                                16:16
`define    CTL_PKT_PARSER_LOG_SNMP_PKT_WIDTH                                1

`define    CTL_PKT_PARSER_LOG_IS_BFD_RANGE                                  17:17
`define    CTL_PKT_PARSER_LOG_IS_BFD_WIDTH                                  1

`define    CTL_PKT_PARSER_LOG_JUMBO_NUM_RANGE                               18:18
`define    CTL_PKT_PARSER_LOG_JUMBO_NUM_WIDTH                               1

// DsMemAclTsn
`define    DS_MEM_ACL_TSN_RANGE                                             -1:0
`define    DS_MEM_ACL_TSN_WIDTH                                             0

// DsMemFlowColorStats
`define    DS_MEM_FLOW_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_FLOW_COLOR_STATS_WIDTH                                    0

// DsMemFlowPolice
`define    DS_MEM_FLOW_POLICE_RANGE                                         -1:0
`define    DS_MEM_FLOW_POLICE_WIDTH                                         0

// DsMemFlowPoliceCfg
`define    DS_MEM_FLOW_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_FLOW_POLICE_CFG_WIDTH                                     0

// DsMemHostRoute
`define    DS_MEM_HOST_ROUTE_RANGE                                          -1:0
`define    DS_MEM_HOST_ROUTE_WIDTH                                          0

// DsMemHostRouteLeft
`define    DS_MEM_HOST_ROUTE_LEFT_RANGE                                     -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_WIDTH                                     0

// DsMemHostRouteLeftKey
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_RANGE                                 -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_WIDTH                                 0

// DsMemHostRouteLeftValid
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_RANGE                               -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_WIDTH                               0

// DsMemHostRouteRight
`define    DS_MEM_HOST_ROUTE_RIGHT_RANGE                                    -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_WIDTH                                    0

// DsMemHostRouteRightKey
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_RANGE                                -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_WIDTH                                0

// DsMemHostRouteRightValid
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_RANGE                              -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_WIDTH                              0

// DsMemHostTsn
`define    DS_MEM_HOST_TSN_RANGE                                            -1:0
`define    DS_MEM_HOST_TSN_WIDTH                                            0

// DsMemHostTsnLeft
`define    DS_MEM_HOST_TSN_LEFT_RANGE                                       -1:0
`define    DS_MEM_HOST_TSN_LEFT_WIDTH                                       0

// DsMemHostTsnRight
`define    DS_MEM_HOST_TSN_RIGHT_RANGE                                      -1:0
`define    DS_MEM_HOST_TSN_RIGHT_WIDTH                                      0

// DsMemIndvRcvyCfg
`define    DS_MEM_INDV_RCVY_CFG_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CFG_WIDTH                                       0

// DsMemIndvRcvyCnt
`define    DS_MEM_INDV_RCVY_CNT_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CNT_WIDTH                                       0

// DsMemIndvRcvySeq
`define    DS_MEM_INDV_RCVY_SEQ_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_SEQ_WIDTH                                       0

// DsMemMacAgingLeft
`define    DS_MEM_MAC_AGING_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_AGING_LEFT_WIDTH                                      0

// DsMemMacAgingRight
`define    DS_MEM_MAC_AGING_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_AGING_RIGHT_WIDTH                                     0

// DsMemMacKeyLeft
`define    DS_MEM_MAC_KEY_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_KEY_LEFT_WIDTH                                        0

// DsMemMacKeyRight
`define    DS_MEM_MAC_KEY_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_KEY_RIGHT_WIDTH                                       0

// DsMemMacLeft
`define    DS_MEM_MAC_LEFT_RANGE                                            -1:0
`define    DS_MEM_MAC_LEFT_WIDTH                                            0

// DsMemMacRight
`define    DS_MEM_MAC_RIGHT_RANGE                                           -1:0
`define    DS_MEM_MAC_RIGHT_WIDTH                                           0

// DsMemMacStaticLeft
`define    DS_MEM_MAC_STATIC_LEFT_RANGE                                     -1:0
`define    DS_MEM_MAC_STATIC_LEFT_WIDTH                                     0

// DsMemMacStaticRight
`define    DS_MEM_MAC_STATIC_RIGHT_RANGE                                    -1:0
`define    DS_MEM_MAC_STATIC_RIGHT_WIDTH                                    0

// DsMemMacTsn
`define    DS_MEM_MAC_TSN_RANGE                                             -1:0
`define    DS_MEM_MAC_TSN_WIDTH                                             0

// DsMemMacTsnLeft
`define    DS_MEM_MAC_TSN_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_TSN_LEFT_WIDTH                                        0

// DsMemMacTsnRight
`define    DS_MEM_MAC_TSN_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_TSN_RIGHT_WIDTH                                       0

// DsMemMacValidLeft
`define    DS_MEM_MAC_VALID_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_VALID_LEFT_WIDTH                                      0

// DsMemMacValidRight
`define    DS_MEM_MAC_VALID_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_VALID_RIGHT_WIDTH                                     0

// DsMemPortColorStats
`define    DS_MEM_PORT_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_PORT_COLOR_STATS_WIDTH                                    0

// DsMemPortPolice
`define    DS_MEM_PORT_POLICE_RANGE                                         -1:0
`define    DS_MEM_PORT_POLICE_WIDTH                                         0

// DsMemPortPoliceCfg
`define    DS_MEM_PORT_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_PORT_POLICE_CFG_WIDTH                                     0

// DsMemRouteTsn
`define    DS_MEM_ROUTE_TSN_RANGE                                           -1:0
`define    DS_MEM_ROUTE_TSN_WIDTH                                           0

// DsMemStreamRcvyCfg
`define    DS_MEM_STREAM_RCVY_CFG_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CFG_WIDTH                                     0

// DsMemStreamRcvyCnt
`define    DS_MEM_STREAM_RCVY_CNT_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CNT_WIDTH                                     0

// DsMemStreamRcvySeq
`define    DS_MEM_STREAM_RCVY_SEQ_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_SEQ_WIDTH                                     0

// DsMemUdfOffset
`define    DS_MEM_UDF_OFFSET_RANGE                                          1:0
`define    DS_MEM_UDF_OFFSET_WIDTH                                          2

`define    DS_MEM_UDF_OFFSET_UDF_OFFSET0_RANGE                              0:0
`define    DS_MEM_UDF_OFFSET_UDF_OFFSET0_WIDTH                              1

`define    DS_MEM_UDF_OFFSET_UDF_OFFSET1_RANGE                              1:1
`define    DS_MEM_UDF_OFFSET_UDF_OFFSET1_WIDTH                              1

// MsgAdmInfo0
`define    MSG_ADM_INFO0_RANGE                                              -1:0
`define    MSG_ADM_INFO0_WIDTH                                              0

// TmpDsMemMac
`define    TMP_DS_MEM_MAC_RANGE                                             -1:0
`define    TMP_DS_MEM_MAC_WIDTH                                             0

// CtlCommon
`define    CTL_COMMON_RANGE                                                 1:0
`define    CTL_COMMON_WIDTH                                                 2

`define    CTL_COMMON_OF_PORT_NO_RANGE                                      0:0
`define    CTL_COMMON_OF_PORT_NO_WIDTH                                      1

`define    CTL_COMMON_CPU_PORT_NO_RANGE                                     1:1
`define    CTL_COMMON_CPU_PORT_NO_WIDTH                                     1

// CtlProtocolVlanKey
`define    CTL_PROTOCOL_VLAN_KEY_RANGE                                      16:0
`define    CTL_PROTOCOL_VLAN_KEY_WIDTH                                      17

`define    CTL_PROTOCOL_VLAN_KEY_ENTRY_VALID_RANGE                          0:0
`define    CTL_PROTOCOL_VLAN_KEY_ENTRY_VALID_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA0_RANGE                          1:1
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA0_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK0_RANGE                          2:2
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK0_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA1_RANGE                          3:3
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA1_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK1_RANGE                          4:4
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK1_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA2_RANGE                          5:5
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA2_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK2_RANGE                          6:6
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK2_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA3_RANGE                          7:7
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA3_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK3_RANGE                          8:8
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK3_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA4_RANGE                          9:9
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA4_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK4_RANGE                          10:10
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK4_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA5_RANGE                          11:11
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA5_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK5_RANGE                          12:12
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK5_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA6_RANGE                          13:13
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA6_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK6_RANGE                          14:14
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK6_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA7_RANGE                          15:15
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_DATA7_WIDTH                          1

`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK7_RANGE                          16:16
`define    CTL_PROTOCOL_VLAN_KEY_PROTO_MASK7_WIDTH                          1

// CtlVlanLookupLog
`define    CTL_VLAN_LOOKUP_LOG_RANGE                                        9:0
`define    CTL_VLAN_LOOKUP_LOG_WIDTH                                        10

`define    CTL_VLAN_LOOKUP_LOG_VLAN_LKP_RSLT_RANGE                          0:0
`define    CTL_VLAN_LOOKUP_LOG_VLAN_LKP_RSLT_WIDTH                          1

`define    CTL_VLAN_LOOKUP_LOG_EAPOL_DISCARD_RANGE                          1:1
`define    CTL_VLAN_LOOKUP_LOG_EAPOL_DISCARD_WIDTH                          1

`define    CTL_VLAN_LOOKUP_LOG_DOT1X_DISCARD_RANGE                          2:2
`define    CTL_VLAN_LOOKUP_LOG_DOT1X_DISCARD_WIDTH                          1

`define    CTL_VLAN_LOOKUP_LOG_CHK_MAC_SA_FAIL_RANGE                        3:3
`define    CTL_VLAN_LOOKUP_LOG_CHK_MAC_SA_FAIL_WIDTH                        1

`define    CTL_VLAN_LOOKUP_LOG_PTP_DISCARD_RANGE                            4:4
`define    CTL_VLAN_LOOKUP_LOG_PTP_DISCARD_WIDTH                            1

`define    CTL_VLAN_LOOKUP_LOG_IP_SUBNET_VLAN_VALID_RANGE                   5:5
`define    CTL_VLAN_LOOKUP_LOG_IP_SUBNET_VLAN_VALID_WIDTH                   1

`define    CTL_VLAN_LOOKUP_LOG_MAC_BASED_VLAN_VALID_RANGE                   6:6
`define    CTL_VLAN_LOOKUP_LOG_MAC_BASED_VLAN_VALID_WIDTH                   1

`define    CTL_VLAN_LOOKUP_LOG_PROTOCOL_VLAN_VALID_RANGE                    7:7
`define    CTL_VLAN_LOOKUP_LOG_PROTOCOL_VLAN_VALID_WIDTH                    1

`define    CTL_VLAN_LOOKUP_LOG_IS_TSN_RANGE                                 8:8
`define    CTL_VLAN_LOOKUP_LOG_IS_TSN_WIDTH                                 1

`define    CTL_VLAN_LOOKUP_LOG_PTP_EN_RANGE                                 9:9
`define    CTL_VLAN_LOOKUP_LOG_PTP_EN_WIDTH                                 1

// DsMemAclTsn
`define    DS_MEM_ACL_TSN_RANGE                                             -1:0
`define    DS_MEM_ACL_TSN_WIDTH                                             0

// DsMemFlowColorStats
`define    DS_MEM_FLOW_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_FLOW_COLOR_STATS_WIDTH                                    0

// DsMemFlowPolice
`define    DS_MEM_FLOW_POLICE_RANGE                                         -1:0
`define    DS_MEM_FLOW_POLICE_WIDTH                                         0

// DsMemFlowPoliceCfg
`define    DS_MEM_FLOW_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_FLOW_POLICE_CFG_WIDTH                                     0

// DsMemHostRoute
`define    DS_MEM_HOST_ROUTE_RANGE                                          -1:0
`define    DS_MEM_HOST_ROUTE_WIDTH                                          0

// DsMemHostRouteLeft
`define    DS_MEM_HOST_ROUTE_LEFT_RANGE                                     -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_WIDTH                                     0

// DsMemHostRouteLeftKey
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_RANGE                                 -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_WIDTH                                 0

// DsMemHostRouteLeftValid
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_RANGE                               -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_WIDTH                               0

// DsMemHostRouteRight
`define    DS_MEM_HOST_ROUTE_RIGHT_RANGE                                    -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_WIDTH                                    0

// DsMemHostRouteRightKey
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_RANGE                                -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_WIDTH                                0

// DsMemHostRouteRightValid
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_RANGE                              -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_WIDTH                              0

// DsMemHostTsn
`define    DS_MEM_HOST_TSN_RANGE                                            -1:0
`define    DS_MEM_HOST_TSN_WIDTH                                            0

// DsMemHostTsnLeft
`define    DS_MEM_HOST_TSN_LEFT_RANGE                                       -1:0
`define    DS_MEM_HOST_TSN_LEFT_WIDTH                                       0

// DsMemHostTsnRight
`define    DS_MEM_HOST_TSN_RIGHT_RANGE                                      -1:0
`define    DS_MEM_HOST_TSN_RIGHT_WIDTH                                      0

// DsMemIndvRcvyCfg
`define    DS_MEM_INDV_RCVY_CFG_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CFG_WIDTH                                       0

// DsMemIndvRcvyCnt
`define    DS_MEM_INDV_RCVY_CNT_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CNT_WIDTH                                       0

// DsMemIndvRcvySeq
`define    DS_MEM_INDV_RCVY_SEQ_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_SEQ_WIDTH                                       0

// DsMemMacAgingLeft
`define    DS_MEM_MAC_AGING_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_AGING_LEFT_WIDTH                                      0

// DsMemMacAgingRight
`define    DS_MEM_MAC_AGING_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_AGING_RIGHT_WIDTH                                     0

// DsMemMacBasedVlanKey
`define    DS_MEM_MAC_BASED_VLAN_KEY_RANGE                                  8:0
`define    DS_MEM_MAC_BASED_VLAN_KEY_WIDTH                                  9

`define    DS_MEM_MAC_BASED_VLAN_KEY_ENTRY_VALID_RANGE                      0:0
`define    DS_MEM_MAC_BASED_VLAN_KEY_ENTRY_VALID_WIDTH                      1

`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA0_RANGE                          1:1
`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA0_WIDTH                          1

`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA_HI0_RANGE                       2:2
`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA_HI0_WIDTH                       1

`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA1_RANGE                          3:3
`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA1_WIDTH                          1

`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA_HI1_RANGE                       4:4
`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA_HI1_WIDTH                       1

`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA2_RANGE                          5:5
`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA2_WIDTH                          1

`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA_HI2_RANGE                       6:6
`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA_HI2_WIDTH                       1

`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA3_RANGE                          7:7
`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA3_WIDTH                          1

`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA_HI3_RANGE                       8:8
`define    DS_MEM_MAC_BASED_VLAN_KEY_MAC_SA_HI3_WIDTH                       1

// DsMemMacKeyLeft
`define    DS_MEM_MAC_KEY_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_KEY_LEFT_WIDTH                                        0

// DsMemMacKeyRight
`define    DS_MEM_MAC_KEY_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_KEY_RIGHT_WIDTH                                       0

// DsMemMacLeft
`define    DS_MEM_MAC_LEFT_RANGE                                            -1:0
`define    DS_MEM_MAC_LEFT_WIDTH                                            0

// DsMemMacRight
`define    DS_MEM_MAC_RIGHT_RANGE                                           -1:0
`define    DS_MEM_MAC_RIGHT_WIDTH                                           0

// DsMemMacStaticLeft
`define    DS_MEM_MAC_STATIC_LEFT_RANGE                                     -1:0
`define    DS_MEM_MAC_STATIC_LEFT_WIDTH                                     0

// DsMemMacStaticRight
`define    DS_MEM_MAC_STATIC_RIGHT_RANGE                                    -1:0
`define    DS_MEM_MAC_STATIC_RIGHT_WIDTH                                    0

// DsMemMacTsn
`define    DS_MEM_MAC_TSN_RANGE                                             -1:0
`define    DS_MEM_MAC_TSN_WIDTH                                             0

// DsMemMacTsnLeft
`define    DS_MEM_MAC_TSN_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_TSN_LEFT_WIDTH                                        0

// DsMemMacTsnRight
`define    DS_MEM_MAC_TSN_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_TSN_RIGHT_WIDTH                                       0

// DsMemMacValidLeft
`define    DS_MEM_MAC_VALID_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_VALID_LEFT_WIDTH                                      0

// DsMemMacValidRight
`define    DS_MEM_MAC_VALID_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_VALID_RIGHT_WIDTH                                     0

// DsMemPhyPort
`define    DS_MEM_PHY_PORT_RANGE                                            7:0
`define    DS_MEM_PHY_PORT_WIDTH                                            8

`define    DS_MEM_PHY_PORT_LOGICAL_PORT_RANGE                               0:0
`define    DS_MEM_PHY_PORT_LOGICAL_PORT_WIDTH                               1

`define    DS_MEM_PHY_PORT_DOT1X_EN_RANGE                                   1:1
`define    DS_MEM_PHY_PORT_DOT1X_EN_WIDTH                                   1

`define    DS_MEM_PHY_PORT_DOT1X_DROP_RANGE                                 2:2
`define    DS_MEM_PHY_PORT_DOT1X_DROP_WIDTH                                 1

`define    DS_MEM_PHY_PORT_AV_AS_TSN_RANGE                                  3:3
`define    DS_MEM_PHY_PORT_AV_AS_TSN_WIDTH                                  1

`define    DS_MEM_PHY_PORT_PTP_EN_RANGE                                     4:4
`define    DS_MEM_PHY_PORT_PTP_EN_WIDTH                                     1

`define    DS_MEM_PHY_PORT_PTP_PORT_TYPE_RANGE                              5:5
`define    DS_MEM_PHY_PORT_PTP_PORT_TYPE_WIDTH                              1

`define    DS_MEM_PHY_PORT_MAC_BASED_VLAN_EN_RANGE                          6:6
`define    DS_MEM_PHY_PORT_MAC_BASED_VLAN_EN_WIDTH                          1

`define    DS_MEM_PHY_PORT_PROTOCOL_VLAN_EN_RANGE                           7:7
`define    DS_MEM_PHY_PORT_PROTOCOL_VLAN_EN_WIDTH                           1

// DsMemPortColorStats
`define    DS_MEM_PORT_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_PORT_COLOR_STATS_WIDTH                                    0

// DsMemPortPolice
`define    DS_MEM_PORT_POLICE_RANGE                                         -1:0
`define    DS_MEM_PORT_POLICE_WIDTH                                         0

// DsMemPortPoliceCfg
`define    DS_MEM_PORT_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_PORT_POLICE_CFG_WIDTH                                     0

// DsMemRouteTsn
`define    DS_MEM_ROUTE_TSN_RANGE                                           -1:0
`define    DS_MEM_ROUTE_TSN_WIDTH                                           0

// DsMemStreamRcvyCfg
`define    DS_MEM_STREAM_RCVY_CFG_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CFG_WIDTH                                     0

// DsMemStreamRcvyCnt
`define    DS_MEM_STREAM_RCVY_CNT_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CNT_WIDTH                                     0

// DsMemStreamRcvySeq
`define    DS_MEM_STREAM_RCVY_SEQ_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_SEQ_WIDTH                                     0

// MsgAdmInfo0
`define    MSG_ADM_INFO0_RANGE                                              -1:0
`define    MSG_ADM_INFO0_WIDTH                                              0

// TmpDsMemMac
`define    TMP_DS_MEM_MAC_RANGE                                             -1:0
`define    TMP_DS_MEM_MAC_WIDTH                                             0

// CtlLkpMngLog
`define    CTL_LKP_MNG_LOG_RANGE                                            13:0
`define    CTL_LKP_MNG_LOG_WIDTH                                            14

`define    CTL_LKP_MNG_LOG_MAC_DA_IDX_RANGE                                 0:0
`define    CTL_LKP_MNG_LOG_MAC_DA_IDX_WIDTH                                 1

`define    CTL_LKP_MNG_LOG_ACL_INDEX_RANGE                                  1:1
`define    CTL_LKP_MNG_LOG_ACL_INDEX_WIDTH                                  1

`define    CTL_LKP_MNG_LOG_ROUTE_HIT_TCAM_RANGE                             2:2
`define    CTL_LKP_MNG_LOG_ROUTE_HIT_TCAM_WIDTH                             1

`define    CTL_LKP_MNG_LOG_IP_ROUTE_LOOKUP_RANGE                            3:3
`define    CTL_LKP_MNG_LOG_IP_ROUTE_LOOKUP_WIDTH                            1

`define    CTL_LKP_MNG_LOG_ROUTE_HIT_NAT_TCAM_RANGE                         4:4
`define    CTL_LKP_MNG_LOG_ROUTE_HIT_NAT_TCAM_WIDTH                         1

`define    CTL_LKP_MNG_LOG_HOST_ROUTE_LEFT_HIT_RANGE                        5:5
`define    CTL_LKP_MNG_LOG_HOST_ROUTE_LEFT_HIT_WIDTH                        1

`define    CTL_LKP_MNG_LOG_HOST_ROUTE_RIGHT_HIT_RANGE                       6:6
`define    CTL_LKP_MNG_LOG_HOST_ROUTE_RIGHT_HIT_WIDTH                       1

`define    CTL_LKP_MNG_LOG_ACL_RESULT_VALID_RANGE                           7:7
`define    CTL_LKP_MNG_LOG_ACL_RESULT_VALID_WIDTH                           1

`define    CTL_LKP_MNG_LOG_IPV6_ACL_LOOKUP_RANGE                            8:8
`define    CTL_LKP_MNG_LOG_IPV6_ACL_LOOKUP_WIDTH                            1

`define    CTL_LKP_MNG_LOG_IP_ROUTE_IDX_RANGE                               9:9
`define    CTL_LKP_MNG_LOG_IP_ROUTE_IDX_WIDTH                               1

`define    CTL_LKP_MNG_LOG_IPV4_ACL_LOOKUP_RANGE                            10:10
`define    CTL_LKP_MNG_LOG_IPV4_ACL_LOOKUP_WIDTH                            1

`define    CTL_LKP_MNG_LOG_MAC_ACL_LOOKUP_RANGE                             11:11
`define    CTL_LKP_MNG_LOG_MAC_ACL_LOOKUP_WIDTH                             1

`define    CTL_LKP_MNG_LOG_MAC_DA_LEFT_VALID_RANGE                          12:12
`define    CTL_LKP_MNG_LOG_MAC_DA_LEFT_VALID_WIDTH                          1

`define    CTL_LKP_MNG_LOG_MAC_DA_RIGHT_VALID_RANGE                         13:13
`define    CTL_LKP_MNG_LOG_MAC_DA_RIGHT_VALID_WIDTH                         1

// CtlLkupCfg
`define    CTL_LKUP_CFG_RANGE                                               4:0
`define    CTL_LKUP_CFG_WIDTH                                               5

`define    CTL_LKUP_CFG_MAC_DA_KEY_EN_RANGE                                 0:0
`define    CTL_LKUP_CFG_MAC_DA_KEY_EN_WIDTH                                 1

`define    CTL_LKUP_CFG_MAC_PCP_KEY_EN_RANGE                                1:1
`define    CTL_LKUP_CFG_MAC_PCP_KEY_EN_WIDTH                                1

`define    CTL_LKUP_CFG_IP_DSCP_KEY_EN_RANGE                                2:2
`define    CTL_LKUP_CFG_IP_DSCP_KEY_EN_WIDTH                                1

`define    CTL_LKUP_CFG_IP_SPORT_KEY_EN_RANGE                               3:3
`define    CTL_LKUP_CFG_IP_SPORT_KEY_EN_WIDTH                               1

`define    CTL_LKUP_CFG_IP_DPORT_KEY_EN_RANGE                               4:4
`define    CTL_LKUP_CFG_IP_DPORT_KEY_EN_WIDTH                               1

// DsMemAclTsn
`define    DS_MEM_ACL_TSN_RANGE                                             -1:0
`define    DS_MEM_ACL_TSN_WIDTH                                             0

// DsMemCuIpDportKeyL
`define    DS_MEM_CU_IP_DPORT_KEY_L_RANGE                                   13:0
`define    DS_MEM_CU_IP_DPORT_KEY_L_WIDTH                                   14

`define    DS_MEM_CU_IP_DPORT_KEY_L_VALID_RANGE                             0:0
`define    DS_MEM_CU_IP_DPORT_KEY_L_VALID_WIDTH                             1

`define    DS_MEM_CU_IP_DPORT_KEY_L_L3_NEXT0_RANGE                          1:1
`define    DS_MEM_CU_IP_DPORT_KEY_L_L3_NEXT0_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_L_L4_DEST_PORT_RANGE                      2:2
`define    DS_MEM_CU_IP_DPORT_KEY_L_L4_DEST_PORT_WIDTH                      1

`define    DS_MEM_CU_IP_DPORT_KEY_L_IP_ADDR3_RANGE                          3:3
`define    DS_MEM_CU_IP_DPORT_KEY_L_IP_ADDR3_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_L_IP_ADDR2_RANGE                          4:4
`define    DS_MEM_CU_IP_DPORT_KEY_L_IP_ADDR2_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_L_IP_ADDR1_RANGE                          5:5
`define    DS_MEM_CU_IP_DPORT_KEY_L_IP_ADDR1_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_L_IP_ADDR0_RANGE                          6:6
`define    DS_MEM_CU_IP_DPORT_KEY_L_IP_ADDR0_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_L_L4_DEST_PORT0_RANGE                     7:7
`define    DS_MEM_CU_IP_DPORT_KEY_L_L4_DEST_PORT0_WIDTH                     1

`define    DS_MEM_CU_IP_DPORT_KEY_L_L3_NEXT1_RANGE                          8:8
`define    DS_MEM_CU_IP_DPORT_KEY_L_L3_NEXT1_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_L_L4_DEST_PORT1_RANGE                     9:9
`define    DS_MEM_CU_IP_DPORT_KEY_L_L4_DEST_PORT1_WIDTH                     1

`define    DS_MEM_CU_IP_DPORT_KEY_L_L3_NEXT2_RANGE                          10:10
`define    DS_MEM_CU_IP_DPORT_KEY_L_L3_NEXT2_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_L_L4_DEST_PORT2_RANGE                     11:11
`define    DS_MEM_CU_IP_DPORT_KEY_L_L4_DEST_PORT2_WIDTH                     1

`define    DS_MEM_CU_IP_DPORT_KEY_L_L3_NEXT3_RANGE                          12:12
`define    DS_MEM_CU_IP_DPORT_KEY_L_L3_NEXT3_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_L_L4_DEST_PORT3_RANGE                     13:13
`define    DS_MEM_CU_IP_DPORT_KEY_L_L4_DEST_PORT3_WIDTH                     1

// DsMemCuIpDportKeyR
`define    DS_MEM_CU_IP_DPORT_KEY_R_RANGE                                   14:0
`define    DS_MEM_CU_IP_DPORT_KEY_R_WIDTH                                   15

`define    DS_MEM_CU_IP_DPORT_KEY_R_VALID_RANGE                             0:0
`define    DS_MEM_CU_IP_DPORT_KEY_R_VALID_WIDTH                             1

`define    DS_MEM_CU_IP_DPORT_KEY_R_VALID_RANGE                             1:1
`define    DS_MEM_CU_IP_DPORT_KEY_R_VALID_WIDTH                             1

`define    DS_MEM_CU_IP_DPORT_KEY_R_L4_DEST_PORT_RANGE                      2:2
`define    DS_MEM_CU_IP_DPORT_KEY_R_L4_DEST_PORT_WIDTH                      1

`define    DS_MEM_CU_IP_DPORT_KEY_R_IP_ADDR3_RANGE                          3:3
`define    DS_MEM_CU_IP_DPORT_KEY_R_IP_ADDR3_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_R_IP_ADDR2_RANGE                          4:4
`define    DS_MEM_CU_IP_DPORT_KEY_R_IP_ADDR2_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_R_IP_ADDR1_RANGE                          5:5
`define    DS_MEM_CU_IP_DPORT_KEY_R_IP_ADDR1_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_R_IP_ADDR0_RANGE                          6:6
`define    DS_MEM_CU_IP_DPORT_KEY_R_IP_ADDR0_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_R_L3_NEXT0_RANGE                          7:7
`define    DS_MEM_CU_IP_DPORT_KEY_R_L3_NEXT0_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_R_L4_DEST_PORT0_RANGE                     8:8
`define    DS_MEM_CU_IP_DPORT_KEY_R_L4_DEST_PORT0_WIDTH                     1

`define    DS_MEM_CU_IP_DPORT_KEY_R_L3_NEXT1_RANGE                          9:9
`define    DS_MEM_CU_IP_DPORT_KEY_R_L3_NEXT1_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_R_L4_DEST_PORT1_RANGE                     10:10
`define    DS_MEM_CU_IP_DPORT_KEY_R_L4_DEST_PORT1_WIDTH                     1

`define    DS_MEM_CU_IP_DPORT_KEY_R_L3_NEXT2_RANGE                          11:11
`define    DS_MEM_CU_IP_DPORT_KEY_R_L3_NEXT2_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_R_L4_DEST_PORT2_RANGE                     12:12
`define    DS_MEM_CU_IP_DPORT_KEY_R_L4_DEST_PORT2_WIDTH                     1

`define    DS_MEM_CU_IP_DPORT_KEY_R_L3_NEXT3_RANGE                          13:13
`define    DS_MEM_CU_IP_DPORT_KEY_R_L3_NEXT3_WIDTH                          1

`define    DS_MEM_CU_IP_DPORT_KEY_R_L4_DEST_PORT3_RANGE                     14:14
`define    DS_MEM_CU_IP_DPORT_KEY_R_L4_DEST_PORT3_WIDTH                     1

// DsMemCuIpDscpKeyL
`define    DS_MEM_CU_IP_DSCP_KEY_L_RANGE                                    8:0
`define    DS_MEM_CU_IP_DSCP_KEY_L_WIDTH                                    9

`define    DS_MEM_CU_IP_DSCP_KEY_L_VALID_RANGE                              0:0
`define    DS_MEM_CU_IP_DSCP_KEY_L_VALID_WIDTH                              1

`define    DS_MEM_CU_IP_DSCP_KEY_L_DSCP0_RANGE                              1:1
`define    DS_MEM_CU_IP_DSCP_KEY_L_DSCP0_WIDTH                              1

`define    DS_MEM_CU_IP_DSCP_KEY_L_IP_ADDR3_RANGE                           2:2
`define    DS_MEM_CU_IP_DSCP_KEY_L_IP_ADDR3_WIDTH                           1

`define    DS_MEM_CU_IP_DSCP_KEY_L_IP_ADDR2_RANGE                           3:3
`define    DS_MEM_CU_IP_DSCP_KEY_L_IP_ADDR2_WIDTH                           1

`define    DS_MEM_CU_IP_DSCP_KEY_L_IP_ADDR1_RANGE                           4:4
`define    DS_MEM_CU_IP_DSCP_KEY_L_IP_ADDR1_WIDTH                           1

`define    DS_MEM_CU_IP_DSCP_KEY_L_IP_ADDR0_RANGE                           5:5
`define    DS_MEM_CU_IP_DSCP_KEY_L_IP_ADDR0_WIDTH                           1

`define    DS_MEM_CU_IP_DSCP_KEY_L_DSCP1_RANGE                              6:6
`define    DS_MEM_CU_IP_DSCP_KEY_L_DSCP1_WIDTH                              1

`define    DS_MEM_CU_IP_DSCP_KEY_L_DSCP2_RANGE                              7:7
`define    DS_MEM_CU_IP_DSCP_KEY_L_DSCP2_WIDTH                              1

`define    DS_MEM_CU_IP_DSCP_KEY_L_DSCP3_RANGE                              8:8
`define    DS_MEM_CU_IP_DSCP_KEY_L_DSCP3_WIDTH                              1

// DsMemCuIpDscpKeyR
`define    DS_MEM_CU_IP_DSCP_KEY_R_RANGE                                    12:0
`define    DS_MEM_CU_IP_DSCP_KEY_R_WIDTH                                    13

`define    DS_MEM_CU_IP_DSCP_KEY_R_VALID_RANGE                              0:0
`define    DS_MEM_CU_IP_DSCP_KEY_R_VALID_WIDTH                              1

`define    DS_MEM_CU_IP_DSCP_KEY_R_DSCP0_RANGE                              1:1
`define    DS_MEM_CU_IP_DSCP_KEY_R_DSCP0_WIDTH                              1

`define    DS_MEM_CU_IP_DSCP_KEY_R_IP_ADDR3_RANGE                           2:2
`define    DS_MEM_CU_IP_DSCP_KEY_R_IP_ADDR3_WIDTH                           1

`define    DS_MEM_CU_IP_DSCP_KEY_R_IP_ADDR2_RANGE                           3:3
`define    DS_MEM_CU_IP_DSCP_KEY_R_IP_ADDR2_WIDTH                           1

`define    DS_MEM_CU_IP_DSCP_KEY_R_IP_ADDR1_RANGE                           4:4
`define    DS_MEM_CU_IP_DSCP_KEY_R_IP_ADDR1_WIDTH                           1

`define    DS_MEM_CU_IP_DSCP_KEY_R_IP_ADDR0_RANGE                           5:5
`define    DS_MEM_CU_IP_DSCP_KEY_R_IP_ADDR0_WIDTH                           1

`define    DS_MEM_CU_IP_DSCP_KEY_R_MAC_ADDR0_RANGE                          6:6
`define    DS_MEM_CU_IP_DSCP_KEY_R_MAC_ADDR0_WIDTH                          1

`define    DS_MEM_CU_IP_DSCP_KEY_R_MAC_ADDR1_RANGE                          7:7
`define    DS_MEM_CU_IP_DSCP_KEY_R_MAC_ADDR1_WIDTH                          1

`define    DS_MEM_CU_IP_DSCP_KEY_R_DSCP1_RANGE                              8:8
`define    DS_MEM_CU_IP_DSCP_KEY_R_DSCP1_WIDTH                              1

`define    DS_MEM_CU_IP_DSCP_KEY_R_MAC_ADDR2_RANGE                          9:9
`define    DS_MEM_CU_IP_DSCP_KEY_R_MAC_ADDR2_WIDTH                          1

`define    DS_MEM_CU_IP_DSCP_KEY_R_DSCP2_RANGE                              10:10
`define    DS_MEM_CU_IP_DSCP_KEY_R_DSCP2_WIDTH                              1

`define    DS_MEM_CU_IP_DSCP_KEY_R_MAC_ADDR3_RANGE                          11:11
`define    DS_MEM_CU_IP_DSCP_KEY_R_MAC_ADDR3_WIDTH                          1

`define    DS_MEM_CU_IP_DSCP_KEY_R_DSCP3_RANGE                              12:12
`define    DS_MEM_CU_IP_DSCP_KEY_R_DSCP3_WIDTH                              1

// DsMemCuIpSportKeyL
`define    DS_MEM_CU_IP_SPORT_KEY_L_RANGE                                   13:0
`define    DS_MEM_CU_IP_SPORT_KEY_L_WIDTH                                   14

`define    DS_MEM_CU_IP_SPORT_KEY_L_VALID_RANGE                             0:0
`define    DS_MEM_CU_IP_SPORT_KEY_L_VALID_WIDTH                             1

`define    DS_MEM_CU_IP_SPORT_KEY_L_L3_NEXT0_RANGE                          1:1
`define    DS_MEM_CU_IP_SPORT_KEY_L_L3_NEXT0_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_L_L4_SRC_PORT_RANGE                       2:2
`define    DS_MEM_CU_IP_SPORT_KEY_L_L4_SRC_PORT_WIDTH                       1

`define    DS_MEM_CU_IP_SPORT_KEY_L_IP_ADDR3_RANGE                          3:3
`define    DS_MEM_CU_IP_SPORT_KEY_L_IP_ADDR3_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_L_IP_ADDR2_RANGE                          4:4
`define    DS_MEM_CU_IP_SPORT_KEY_L_IP_ADDR2_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_L_IP_ADDR1_RANGE                          5:5
`define    DS_MEM_CU_IP_SPORT_KEY_L_IP_ADDR1_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_L_IP_ADDR0_RANGE                          6:6
`define    DS_MEM_CU_IP_SPORT_KEY_L_IP_ADDR0_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_L_L4_SRC_PORT0_RANGE                      7:7
`define    DS_MEM_CU_IP_SPORT_KEY_L_L4_SRC_PORT0_WIDTH                      1

`define    DS_MEM_CU_IP_SPORT_KEY_L_L3_NEXT1_RANGE                          8:8
`define    DS_MEM_CU_IP_SPORT_KEY_L_L3_NEXT1_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_L_L4_SRC_PORT1_RANGE                      9:9
`define    DS_MEM_CU_IP_SPORT_KEY_L_L4_SRC_PORT1_WIDTH                      1

`define    DS_MEM_CU_IP_SPORT_KEY_L_L3_NEXT2_RANGE                          10:10
`define    DS_MEM_CU_IP_SPORT_KEY_L_L3_NEXT2_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_L_L4_SRC_PORT2_RANGE                      11:11
`define    DS_MEM_CU_IP_SPORT_KEY_L_L4_SRC_PORT2_WIDTH                      1

`define    DS_MEM_CU_IP_SPORT_KEY_L_L3_NEXT3_RANGE                          12:12
`define    DS_MEM_CU_IP_SPORT_KEY_L_L3_NEXT3_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_L_L4_SRC_PORT3_RANGE                      13:13
`define    DS_MEM_CU_IP_SPORT_KEY_L_L4_SRC_PORT3_WIDTH                      1

// DsMemCuIpSportKeyR
`define    DS_MEM_CU_IP_SPORT_KEY_R_RANGE                                   14:0
`define    DS_MEM_CU_IP_SPORT_KEY_R_WIDTH                                   15

`define    DS_MEM_CU_IP_SPORT_KEY_R_VALID_RANGE                             0:0
`define    DS_MEM_CU_IP_SPORT_KEY_R_VALID_WIDTH                             1

`define    DS_MEM_CU_IP_SPORT_KEY_R_VALID_RANGE                             1:1
`define    DS_MEM_CU_IP_SPORT_KEY_R_VALID_WIDTH                             1

`define    DS_MEM_CU_IP_SPORT_KEY_R_L4_SRC_PORT_RANGE                       2:2
`define    DS_MEM_CU_IP_SPORT_KEY_R_L4_SRC_PORT_WIDTH                       1

`define    DS_MEM_CU_IP_SPORT_KEY_R_IP_ADDR3_RANGE                          3:3
`define    DS_MEM_CU_IP_SPORT_KEY_R_IP_ADDR3_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_R_IP_ADDR2_RANGE                          4:4
`define    DS_MEM_CU_IP_SPORT_KEY_R_IP_ADDR2_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_R_IP_ADDR1_RANGE                          5:5
`define    DS_MEM_CU_IP_SPORT_KEY_R_IP_ADDR1_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_R_IP_ADDR0_RANGE                          6:6
`define    DS_MEM_CU_IP_SPORT_KEY_R_IP_ADDR0_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_R_L3_NEXT0_RANGE                          7:7
`define    DS_MEM_CU_IP_SPORT_KEY_R_L3_NEXT0_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_R_L4_SRC_PORT0_RANGE                      8:8
`define    DS_MEM_CU_IP_SPORT_KEY_R_L4_SRC_PORT0_WIDTH                      1

`define    DS_MEM_CU_IP_SPORT_KEY_R_L3_NEXT1_RANGE                          9:9
`define    DS_MEM_CU_IP_SPORT_KEY_R_L3_NEXT1_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_R_L4_SRC_PORT1_RANGE                      10:10
`define    DS_MEM_CU_IP_SPORT_KEY_R_L4_SRC_PORT1_WIDTH                      1

`define    DS_MEM_CU_IP_SPORT_KEY_R_L3_NEXT2_RANGE                          11:11
`define    DS_MEM_CU_IP_SPORT_KEY_R_L3_NEXT2_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_R_L4_SRC_PORT2_RANGE                      12:12
`define    DS_MEM_CU_IP_SPORT_KEY_R_L4_SRC_PORT2_WIDTH                      1

`define    DS_MEM_CU_IP_SPORT_KEY_R_L3_NEXT3_RANGE                          13:13
`define    DS_MEM_CU_IP_SPORT_KEY_R_L3_NEXT3_WIDTH                          1

`define    DS_MEM_CU_IP_SPORT_KEY_R_L4_SRC_PORT3_RANGE                      14:14
`define    DS_MEM_CU_IP_SPORT_KEY_R_L4_SRC_PORT3_WIDTH                      1

// DsMemCuMacKeyL
`define    DS_MEM_CU_MAC_KEY_L_RANGE                                        4:0
`define    DS_MEM_CU_MAC_KEY_L_WIDTH                                        5

`define    DS_MEM_CU_MAC_KEY_L_VALID_RANGE                                  0:0
`define    DS_MEM_CU_MAC_KEY_L_VALID_WIDTH                                  1

`define    DS_MEM_CU_MAC_KEY_L_MAC_ADDR0_RANGE                              1:1
`define    DS_MEM_CU_MAC_KEY_L_MAC_ADDR0_WIDTH                              1

`define    DS_MEM_CU_MAC_KEY_L_MAC_ADDR_HI0_RANGE                           2:2
`define    DS_MEM_CU_MAC_KEY_L_MAC_ADDR_HI0_WIDTH                           1

`define    DS_MEM_CU_MAC_KEY_L_MAC_ADDR1_RANGE                              3:3
`define    DS_MEM_CU_MAC_KEY_L_MAC_ADDR1_WIDTH                              1

`define    DS_MEM_CU_MAC_KEY_L_MAC_ADDR_HI1_RANGE                           4:4
`define    DS_MEM_CU_MAC_KEY_L_MAC_ADDR_HI1_WIDTH                           1

// DsMemCuMacKeyR
`define    DS_MEM_CU_MAC_KEY_R_RANGE                                        4:0
`define    DS_MEM_CU_MAC_KEY_R_WIDTH                                        5

`define    DS_MEM_CU_MAC_KEY_R_VALID_RANGE                                  0:0
`define    DS_MEM_CU_MAC_KEY_R_VALID_WIDTH                                  1

`define    DS_MEM_CU_MAC_KEY_R_MAC_ADDR0_RANGE                              1:1
`define    DS_MEM_CU_MAC_KEY_R_MAC_ADDR0_WIDTH                              1

`define    DS_MEM_CU_MAC_KEY_R_MAC_ADDR_HI0_RANGE                           2:2
`define    DS_MEM_CU_MAC_KEY_R_MAC_ADDR_HI0_WIDTH                           1

`define    DS_MEM_CU_MAC_KEY_R_MAC_ADDR1_RANGE                              3:3
`define    DS_MEM_CU_MAC_KEY_R_MAC_ADDR1_WIDTH                              1

`define    DS_MEM_CU_MAC_KEY_R_MAC_ADDR_HI1_RANGE                           4:4
`define    DS_MEM_CU_MAC_KEY_R_MAC_ADDR_HI1_WIDTH                           1

// DsMemCuMacPcpKeyL
`define    DS_MEM_CU_MAC_PCP_KEY_L_RANGE                                    6:0
`define    DS_MEM_CU_MAC_PCP_KEY_L_WIDTH                                    7

`define    DS_MEM_CU_MAC_PCP_KEY_L_VALID_RANGE                              0:0
`define    DS_MEM_CU_MAC_PCP_KEY_L_VALID_WIDTH                              1

`define    DS_MEM_CU_MAC_PCP_KEY_L_MAC_ADDR0_RANGE                          1:1
`define    DS_MEM_CU_MAC_PCP_KEY_L_MAC_ADDR0_WIDTH                          1

`define    DS_MEM_CU_MAC_PCP_KEY_L_MAC_ADDR_HI0_RANGE                       2:2
`define    DS_MEM_CU_MAC_PCP_KEY_L_MAC_ADDR_HI0_WIDTH                       1

`define    DS_MEM_CU_MAC_PCP_KEY_L_PCP0_RANGE                               3:3
`define    DS_MEM_CU_MAC_PCP_KEY_L_PCP0_WIDTH                               1

`define    DS_MEM_CU_MAC_PCP_KEY_L_MAC_ADDR1_RANGE                          4:4
`define    DS_MEM_CU_MAC_PCP_KEY_L_MAC_ADDR1_WIDTH                          1

`define    DS_MEM_CU_MAC_PCP_KEY_L_MAC_ADDR_HI1_RANGE                       5:5
`define    DS_MEM_CU_MAC_PCP_KEY_L_MAC_ADDR_HI1_WIDTH                       1

`define    DS_MEM_CU_MAC_PCP_KEY_L_PCP1_RANGE                               6:6
`define    DS_MEM_CU_MAC_PCP_KEY_L_PCP1_WIDTH                               1

// DsMemCuMacPcpKeyR
`define    DS_MEM_CU_MAC_PCP_KEY_R_RANGE                                    4:0
`define    DS_MEM_CU_MAC_PCP_KEY_R_WIDTH                                    5

`define    DS_MEM_CU_MAC_PCP_KEY_R_VALID_RANGE                              0:0
`define    DS_MEM_CU_MAC_PCP_KEY_R_VALID_WIDTH                              1

`define    DS_MEM_CU_MAC_PCP_KEY_R_MAC_ADDR0_RANGE                          1:1
`define    DS_MEM_CU_MAC_PCP_KEY_R_MAC_ADDR0_WIDTH                          1

`define    DS_MEM_CU_MAC_PCP_KEY_R_MAC_ADDR_HI0_RANGE                       2:2
`define    DS_MEM_CU_MAC_PCP_KEY_R_MAC_ADDR_HI0_WIDTH                       1

`define    DS_MEM_CU_MAC_PCP_KEY_R_MAC_ADDR1_RANGE                          3:3
`define    DS_MEM_CU_MAC_PCP_KEY_R_MAC_ADDR1_WIDTH                          1

`define    DS_MEM_CU_MAC_PCP_KEY_R_MAC_ADDR_HI1_RANGE                       4:4
`define    DS_MEM_CU_MAC_PCP_KEY_R_MAC_ADDR_HI1_WIDTH                       1

// DsMemFlowColorStats
`define    DS_MEM_FLOW_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_FLOW_COLOR_STATS_WIDTH                                    0

// DsMemFlowPolice
`define    DS_MEM_FLOW_POLICE_RANGE                                         -1:0
`define    DS_MEM_FLOW_POLICE_WIDTH                                         0

// DsMemFlowPoliceCfg
`define    DS_MEM_FLOW_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_FLOW_POLICE_CFG_WIDTH                                     0

// DsMemHostRoute
`define    DS_MEM_HOST_ROUTE_RANGE                                          -1:0
`define    DS_MEM_HOST_ROUTE_WIDTH                                          0

// DsMemHostRouteLeft
`define    DS_MEM_HOST_ROUTE_LEFT_RANGE                                     -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_WIDTH                                     0

// DsMemHostRouteLeftKey
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_RANGE                                 6:0
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_WIDTH                                 7

`define    DS_MEM_HOST_ROUTE_LEFT_KEY_IS_VALID_RANGE                        0:0
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_IS_VALID_WIDTH                        1

`define    DS_MEM_HOST_ROUTE_LEFT_KEY_IS_IPV6_RANGE                         1:1
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_IS_IPV6_WIDTH                         1

`define    DS_MEM_HOST_ROUTE_LEFT_KEY_IP_ADDR_F3_RANGE                      2:2
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_IP_ADDR_F3_WIDTH                      1

`define    DS_MEM_HOST_ROUTE_LEFT_KEY_IP_ADDR_F2_RANGE                      3:3
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_IP_ADDR_F2_WIDTH                      1

`define    DS_MEM_HOST_ROUTE_LEFT_KEY_IP_ADDR_F1_RANGE                      4:4
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_IP_ADDR_F1_WIDTH                      1

`define    DS_MEM_HOST_ROUTE_LEFT_KEY_IP_ADDR_F0_RANGE                      5:5
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_IP_ADDR_F0_WIDTH                      1

`define    DS_MEM_HOST_ROUTE_LEFT_KEY_IS_IPV6_F_RANGE                       6:6
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_IS_IPV6_F_WIDTH                       1

// DsMemHostRouteLeftValid
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_RANGE                               -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_WIDTH                               0

// DsMemHostRouteRight
`define    DS_MEM_HOST_ROUTE_RIGHT_RANGE                                    -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_WIDTH                                    0

// DsMemHostRouteRightKey
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_RANGE                                6:0
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_WIDTH                                7

`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_IS_IPV6_RANGE                        0:0
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_IS_IPV6_WIDTH                        1

`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_IP_ADDR_F3_RANGE                     1:1
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_IP_ADDR_F3_WIDTH                     1

`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_IP_ADDR_F2_RANGE                     2:2
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_IP_ADDR_F2_WIDTH                     1

`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_IP_ADDR_F1_RANGE                     3:3
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_IP_ADDR_F1_WIDTH                     1

`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_IP_ADDR_F0_RANGE                     4:4
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_IP_ADDR_F0_WIDTH                     1

`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_IS_VALID_RANGE                       5:5
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_IS_VALID_WIDTH                       1

`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_IS_IPV6_F_RANGE                      6:6
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_IS_IPV6_F_WIDTH                      1

// DsMemHostRouteRightValid
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_RANGE                              0:0
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_WIDTH                              1

`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_IS_VALID_RANGE                     0:0
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_IS_VALID_WIDTH                     1

// DsMemHostTsn
`define    DS_MEM_HOST_TSN_RANGE                                            -1:0
`define    DS_MEM_HOST_TSN_WIDTH                                            0

// DsMemHostTsnLeft
`define    DS_MEM_HOST_TSN_LEFT_RANGE                                       -1:0
`define    DS_MEM_HOST_TSN_LEFT_WIDTH                                       0

// DsMemHostTsnRight
`define    DS_MEM_HOST_TSN_RIGHT_RANGE                                      -1:0
`define    DS_MEM_HOST_TSN_RIGHT_WIDTH                                      0

// DsMemIndvRcvyCfg
`define    DS_MEM_INDV_RCVY_CFG_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CFG_WIDTH                                       0

// DsMemIndvRcvyCnt
`define    DS_MEM_INDV_RCVY_CNT_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CNT_WIDTH                                       0

// DsMemIndvRcvySeq
`define    DS_MEM_INDV_RCVY_SEQ_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_SEQ_WIDTH                                       0

// DsMemMacAgingLeft
`define    DS_MEM_MAC_AGING_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_AGING_LEFT_WIDTH                                      0

// DsMemMacAgingRight
`define    DS_MEM_MAC_AGING_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_AGING_RIGHT_WIDTH                                     0

// DsMemMacKeyLeft
`define    DS_MEM_MAC_KEY_LEFT_RANGE                                        5:0
`define    DS_MEM_MAC_KEY_LEFT_WIDTH                                        6

`define    DS_MEM_MAC_KEY_LEFT_MAC_ADDR0_RANGE                              0:0
`define    DS_MEM_MAC_KEY_LEFT_MAC_ADDR0_WIDTH                              1

`define    DS_MEM_MAC_KEY_LEFT_VLAN_ID0_RANGE                               1:1
`define    DS_MEM_MAC_KEY_LEFT_VLAN_ID0_WIDTH                               1

`define    DS_MEM_MAC_KEY_LEFT_MAC_ADDR_HI0_RANGE                           2:2
`define    DS_MEM_MAC_KEY_LEFT_MAC_ADDR_HI0_WIDTH                           1

`define    DS_MEM_MAC_KEY_LEFT_MAC_ADDR1_RANGE                              3:3
`define    DS_MEM_MAC_KEY_LEFT_MAC_ADDR1_WIDTH                              1

`define    DS_MEM_MAC_KEY_LEFT_VLAN_ID1_RANGE                               4:4
`define    DS_MEM_MAC_KEY_LEFT_VLAN_ID1_WIDTH                               1

`define    DS_MEM_MAC_KEY_LEFT_MAC_ADDR_HI1_RANGE                           5:5
`define    DS_MEM_MAC_KEY_LEFT_MAC_ADDR_HI1_WIDTH                           1

// DsMemMacKeyRight
`define    DS_MEM_MAC_KEY_RIGHT_RANGE                                       5:0
`define    DS_MEM_MAC_KEY_RIGHT_WIDTH                                       6

`define    DS_MEM_MAC_KEY_RIGHT_MAC_ADDR0_RANGE                             0:0
`define    DS_MEM_MAC_KEY_RIGHT_MAC_ADDR0_WIDTH                             1

`define    DS_MEM_MAC_KEY_RIGHT_VLAN_ID0_RANGE                              1:1
`define    DS_MEM_MAC_KEY_RIGHT_VLAN_ID0_WIDTH                              1

`define    DS_MEM_MAC_KEY_RIGHT_MAC_ADDR_HI0_RANGE                          2:2
`define    DS_MEM_MAC_KEY_RIGHT_MAC_ADDR_HI0_WIDTH                          1

`define    DS_MEM_MAC_KEY_RIGHT_MAC_ADDR1_RANGE                             3:3
`define    DS_MEM_MAC_KEY_RIGHT_MAC_ADDR1_WIDTH                             1

`define    DS_MEM_MAC_KEY_RIGHT_VLAN_ID1_RANGE                              4:4
`define    DS_MEM_MAC_KEY_RIGHT_VLAN_ID1_WIDTH                              1

`define    DS_MEM_MAC_KEY_RIGHT_MAC_ADDR_HI1_RANGE                          5:5
`define    DS_MEM_MAC_KEY_RIGHT_MAC_ADDR_HI1_WIDTH                          1

// DsMemMacLeft
`define    DS_MEM_MAC_LEFT_RANGE                                            -1:0
`define    DS_MEM_MAC_LEFT_WIDTH                                            0

// DsMemMacRight
`define    DS_MEM_MAC_RIGHT_RANGE                                           -1:0
`define    DS_MEM_MAC_RIGHT_WIDTH                                           0

// DsMemMacStaticLeft
`define    DS_MEM_MAC_STATIC_LEFT_RANGE                                     -1:0
`define    DS_MEM_MAC_STATIC_LEFT_WIDTH                                     0

// DsMemMacStaticRight
`define    DS_MEM_MAC_STATIC_RIGHT_RANGE                                    -1:0
`define    DS_MEM_MAC_STATIC_RIGHT_WIDTH                                    0

// DsMemMacTsn
`define    DS_MEM_MAC_TSN_RANGE                                             -1:0
`define    DS_MEM_MAC_TSN_WIDTH                                             0

// DsMemMacTsnLeft
`define    DS_MEM_MAC_TSN_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_TSN_LEFT_WIDTH                                        0

// DsMemMacTsnRight
`define    DS_MEM_MAC_TSN_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_TSN_RIGHT_WIDTH                                       0

// DsMemMacValidLeft
`define    DS_MEM_MAC_VALID_LEFT_RANGE                                      0:0
`define    DS_MEM_MAC_VALID_LEFT_WIDTH                                      1

`define    DS_MEM_MAC_VALID_LEFT_VALID_RANGE                                0:0
`define    DS_MEM_MAC_VALID_LEFT_VALID_WIDTH                                1

// DsMemMacValidRight
`define    DS_MEM_MAC_VALID_RIGHT_RANGE                                     0:0
`define    DS_MEM_MAC_VALID_RIGHT_WIDTH                                     1

`define    DS_MEM_MAC_VALID_RIGHT_VALID_RANGE                               0:0
`define    DS_MEM_MAC_VALID_RIGHT_VALID_WIDTH                               1

// DsMemPortColorStats
`define    DS_MEM_PORT_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_PORT_COLOR_STATS_WIDTH                                    0

// DsMemPortPolice
`define    DS_MEM_PORT_POLICE_RANGE                                         -1:0
`define    DS_MEM_PORT_POLICE_WIDTH                                         0

// DsMemPortPoliceCfg
`define    DS_MEM_PORT_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_PORT_POLICE_CFG_WIDTH                                     0

// DsMemRouteTsn
`define    DS_MEM_ROUTE_TSN_RANGE                                           -1:0
`define    DS_MEM_ROUTE_TSN_WIDTH                                           0

// DsMemStreamRcvyCfg
`define    DS_MEM_STREAM_RCVY_CFG_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CFG_WIDTH                                     0

// DsMemStreamRcvyCnt
`define    DS_MEM_STREAM_RCVY_CNT_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CNT_WIDTH                                     0

// DsMemStreamRcvySeq
`define    DS_MEM_STREAM_RCVY_SEQ_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_SEQ_WIDTH                                     0

// MsgAdmInfo0
`define    MSG_ADM_INFO0_RANGE                                              -1:0
`define    MSG_ADM_INFO0_WIDTH                                              0

// TmpDsMemMac
`define    TMP_DS_MEM_MAC_RANGE                                             -1:0
`define    TMP_DS_MEM_MAC_WIDTH                                             0

// CtlCommon
`define    CTL_COMMON_RANGE                                                 0:0
`define    CTL_COMMON_WIDTH                                                 1

`define    CTL_COMMON_CPU_PORT_NO_RANGE                                     0:0
`define    CTL_COMMON_CPU_PORT_NO_WIDTH                                     1

// CtlCosMapPrior
`define    CTL_COS_MAP_PRIOR_RANGE                                          0:0
`define    CTL_COS_MAP_PRIOR_WIDTH                                          1

`define    CTL_COS_MAP_PRIOR_COS_PRIOR_RANGE                                0:0
`define    CTL_COS_MAP_PRIOR_COS_PRIOR_WIDTH                                1

// CtlDscpMapPrior
`define    CTL_DSCP_MAP_PRIOR_RANGE                                         0:0
`define    CTL_DSCP_MAP_PRIOR_WIDTH                                         1

`define    CTL_DSCP_MAP_PRIOR_DSCP_PRIOR_RANGE                              0:0
`define    CTL_DSCP_MAP_PRIOR_DSCP_PRIOR_WIDTH                              1

// CtlIntfBpduMac
`define    CTL_INTF_BPDU_MAC_RANGE                                          3:0
`define    CTL_INTF_BPDU_MAC_WIDTH                                          4

`define    CTL_INTF_BPDU_MAC_S_BPDU_MAC_RANGE                               0:0
`define    CTL_INTF_BPDU_MAC_S_BPDU_MAC_WIDTH                               1

`define    CTL_INTF_BPDU_MAC_S_BPDU_MAC_HI_RANGE                            1:1
`define    CTL_INTF_BPDU_MAC_S_BPDU_MAC_HI_WIDTH                            1

`define    CTL_INTF_BPDU_MAC_C_BPDU_MAC_RANGE                               2:2
`define    CTL_INTF_BPDU_MAC_C_BPDU_MAC_WIDTH                               1

`define    CTL_INTF_BPDU_MAC_C_BPDU_MAC_HI_RANGE                            3:3
`define    CTL_INTF_BPDU_MAC_C_BPDU_MAC_HI_WIDTH                            1

// CtlIntfMapLog
`define    CTL_INTF_MAP_LOG_RANGE                                           14:0
`define    CTL_INTF_MAP_LOG_WIDTH                                           15

`define    CTL_INTF_MAP_LOG_AFT_DISCARD_RANGE                               0:0
`define    CTL_INTF_MAP_LOG_AFT_DISCARD_WIDTH                               1

`define    CTL_INTF_MAP_LOG_VLAN_ID_RANGE                                   1:1
`define    CTL_INTF_MAP_LOG_VLAN_ID_WIDTH                                   1

`define    CTL_INTF_MAP_LOG_COS_RANGE                                       2:2
`define    CTL_INTF_MAP_LOG_COS_WIDTH                                       1

`define    CTL_INTF_MAP_LOG_DSCP_RANGE                                      3:3
`define    CTL_INTF_MAP_LOG_DSCP_WIDTH                                      1

`define    CTL_INTF_MAP_LOG_PRIOR_RANGE                                     4:4
`define    CTL_INTF_MAP_LOG_PRIOR_WIDTH                                     1

`define    CTL_INTF_MAP_LOG_IS_UCAST_IP_RANGE                               5:5
`define    CTL_INTF_MAP_LOG_IS_UCAST_IP_WIDTH                               1

`define    CTL_INTF_MAP_LOG_IS_MCAST_IP_RANGE                               6:6
`define    CTL_INTF_MAP_LOG_IS_MCAST_IP_WIDTH                               1

`define    CTL_INTF_MAP_LOG_IS_MCAST_MAC_RANGE                              7:7
`define    CTL_INTF_MAP_LOG_IS_MCAST_MAC_WIDTH                              1

`define    CTL_INTF_MAP_LOG_ROUTING_EN_RANGE                                8:8
`define    CTL_INTF_MAP_LOG_ROUTING_EN_WIDTH                                1

`define    CTL_INTF_MAP_LOG_CPU_PKT_TYPE_RANGE                              9:9
`define    CTL_INTF_MAP_LOG_CPU_PKT_TYPE_WIDTH                              1

`define    CTL_INTF_MAP_LOG_STP_IDX_RANGE                                   10:10
`define    CTL_INTF_MAP_LOG_STP_IDX_WIDTH                                   1

`define    CTL_INTF_MAP_LOG_IS_BPDU_RANGE                                   11:11
`define    CTL_INTF_MAP_LOG_IS_BPDU_WIDTH                                   1

`define    CTL_INTF_MAP_LOG_STP_STATE_RANGE                                 12:12
`define    CTL_INTF_MAP_LOG_STP_STATE_WIDTH                                 1

`define    CTL_INTF_MAP_LOG_TSN_EN_RANGE                                    13:13
`define    CTL_INTF_MAP_LOG_TSN_EN_WIDTH                                    1

`define    CTL_INTF_MAP_LOG_MC_VLAN_DROP_RANGE                              14:14
`define    CTL_INTF_MAP_LOG_MC_VLAN_DROP_WIDTH                              1

// CtlIpPrecdncMapPrior
`define    CTL_IP_PRECDNC_MAP_PRIOR_RANGE                                   0:0
`define    CTL_IP_PRECDNC_MAP_PRIOR_WIDTH                                   1

`define    CTL_IP_PRECDNC_MAP_PRIOR_PREC_PRIOR_RANGE                        0:0
`define    CTL_IP_PRECDNC_MAP_PRIOR_PREC_PRIOR_WIDTH                        1

// CtlManageVlan
`define    CTL_MANAGE_VLAN_RANGE                                            2:0
`define    CTL_MANAGE_VLAN_WIDTH                                            3

`define    CTL_MANAGE_VLAN_VLAN_ID0_RANGE                                   0:0
`define    CTL_MANAGE_VLAN_VLAN_ID0_WIDTH                                   1

`define    CTL_MANAGE_VLAN_VLAN_ID1_RANGE                                   1:1
`define    CTL_MANAGE_VLAN_VLAN_ID1_WIDTH                                   1

`define    CTL_MANAGE_VLAN_RMT_VLAN_ID_RANGE                                2:2
`define    CTL_MANAGE_VLAN_RMT_VLAN_ID_WIDTH                                1

// CtlRouterMac
`define    CTL_ROUTER_MAC_RANGE                                             7:0
`define    CTL_ROUTER_MAC_WIDTH                                             8

`define    CTL_ROUTER_MAC_ROUTER_MAC0_RANGE                                 0:0
`define    CTL_ROUTER_MAC_ROUTER_MAC0_WIDTH                                 1

`define    CTL_ROUTER_MAC_ROUTER_MAC_HI0_RANGE                              1:1
`define    CTL_ROUTER_MAC_ROUTER_MAC_HI0_WIDTH                              1

`define    CTL_ROUTER_MAC_ROUTER_MAC1_RANGE                                 2:2
`define    CTL_ROUTER_MAC_ROUTER_MAC1_WIDTH                                 1

`define    CTL_ROUTER_MAC_ROUTER_MAC_HI1_RANGE                              3:3
`define    CTL_ROUTER_MAC_ROUTER_MAC_HI1_WIDTH                              1

`define    CTL_ROUTER_MAC_ROUTER_MAC2_RANGE                                 4:4
`define    CTL_ROUTER_MAC_ROUTER_MAC2_WIDTH                                 1

`define    CTL_ROUTER_MAC_ROUTER_MAC_HI2_RANGE                              5:5
`define    CTL_ROUTER_MAC_ROUTER_MAC_HI2_WIDTH                              1

`define    CTL_ROUTER_MAC_ROUTER_MAC3_RANGE                                 6:6
`define    CTL_ROUTER_MAC_ROUTER_MAC3_WIDTH                                 1

`define    CTL_ROUTER_MAC_ROUTER_MAC_HI3_RANGE                              7:7
`define    CTL_ROUTER_MAC_ROUTER_MAC_HI3_WIDTH                              1

// CtlTsnFunc
`define    CTL_TSN_FUNC_RANGE                                               0:0
`define    CTL_TSN_FUNC_WIDTH                                               1

`define    CTL_TSN_FUNC_ENABLE_RANGE                                        0:0
`define    CTL_TSN_FUNC_ENABLE_WIDTH                                        1

// DsMemAclTsn
`define    DS_MEM_ACL_TSN_RANGE                                             -1:0
`define    DS_MEM_ACL_TSN_WIDTH                                             0

// DsMemFlowColorStats
`define    DS_MEM_FLOW_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_FLOW_COLOR_STATS_WIDTH                                    0

// DsMemFlowPolice
`define    DS_MEM_FLOW_POLICE_RANGE                                         -1:0
`define    DS_MEM_FLOW_POLICE_WIDTH                                         0

// DsMemFlowPoliceCfg
`define    DS_MEM_FLOW_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_FLOW_POLICE_CFG_WIDTH                                     0

// DsMemHostRoute
`define    DS_MEM_HOST_ROUTE_RANGE                                          -1:0
`define    DS_MEM_HOST_ROUTE_WIDTH                                          0

// DsMemHostRouteLeft
`define    DS_MEM_HOST_ROUTE_LEFT_RANGE                                     -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_WIDTH                                     0

// DsMemHostRouteLeftKey
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_RANGE                                 -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_WIDTH                                 0

// DsMemHostRouteLeftValid
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_RANGE                               -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_WIDTH                               0

// DsMemHostRouteRight
`define    DS_MEM_HOST_ROUTE_RIGHT_RANGE                                    -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_WIDTH                                    0

// DsMemHostRouteRightKey
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_RANGE                                -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_WIDTH                                0

// DsMemHostRouteRightValid
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_RANGE                              -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_WIDTH                              0

// DsMemHostTsn
`define    DS_MEM_HOST_TSN_RANGE                                            -1:0
`define    DS_MEM_HOST_TSN_WIDTH                                            0

// DsMemHostTsnLeft
`define    DS_MEM_HOST_TSN_LEFT_RANGE                                       -1:0
`define    DS_MEM_HOST_TSN_LEFT_WIDTH                                       0

// DsMemHostTsnRight
`define    DS_MEM_HOST_TSN_RIGHT_RANGE                                      -1:0
`define    DS_MEM_HOST_TSN_RIGHT_WIDTH                                      0

// DsMemIndvRcvyCfg
`define    DS_MEM_INDV_RCVY_CFG_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CFG_WIDTH                                       0

// DsMemIndvRcvyCnt
`define    DS_MEM_INDV_RCVY_CNT_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CNT_WIDTH                                       0

// DsMemIndvRcvySeq
`define    DS_MEM_INDV_RCVY_SEQ_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_SEQ_WIDTH                                       0

// DsMemMacAgingLeft
`define    DS_MEM_MAC_AGING_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_AGING_LEFT_WIDTH                                      0

// DsMemMacAgingRight
`define    DS_MEM_MAC_AGING_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_AGING_RIGHT_WIDTH                                     0

// DsMemMacBasedVlan
`define    DS_MEM_MAC_BASED_VLAN_RANGE                                      5:0
`define    DS_MEM_MAC_BASED_VLAN_WIDTH                                      6

`define    DS_MEM_MAC_BASED_VLAN_REPLACE_VLAN_RANGE                         0:0
`define    DS_MEM_MAC_BASED_VLAN_REPLACE_VLAN_WIDTH                         1

`define    DS_MEM_MAC_BASED_VLAN_VLAN_ID_RANGE                              1:1
`define    DS_MEM_MAC_BASED_VLAN_VLAN_ID_WIDTH                              1

`define    DS_MEM_MAC_BASED_VLAN_REPLACE_COS_RANGE                          2:2
`define    DS_MEM_MAC_BASED_VLAN_REPLACE_COS_WIDTH                          1

`define    DS_MEM_MAC_BASED_VLAN_COS_RANGE                                  3:3
`define    DS_MEM_MAC_BASED_VLAN_COS_WIDTH                                  1

`define    DS_MEM_MAC_BASED_VLAN_REPLACE_DSCP_RANGE                         4:4
`define    DS_MEM_MAC_BASED_VLAN_REPLACE_DSCP_WIDTH                         1

`define    DS_MEM_MAC_BASED_VLAN_DSCP_RANGE                                 5:5
`define    DS_MEM_MAC_BASED_VLAN_DSCP_WIDTH                                 1

// DsMemMacKeyLeft
`define    DS_MEM_MAC_KEY_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_KEY_LEFT_WIDTH                                        0

// DsMemMacKeyRight
`define    DS_MEM_MAC_KEY_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_KEY_RIGHT_WIDTH                                       0

// DsMemMacLeft
`define    DS_MEM_MAC_LEFT_RANGE                                            -1:0
`define    DS_MEM_MAC_LEFT_WIDTH                                            0

// DsMemMacRight
`define    DS_MEM_MAC_RIGHT_RANGE                                           -1:0
`define    DS_MEM_MAC_RIGHT_WIDTH                                           0

// DsMemMacStaticLeft
`define    DS_MEM_MAC_STATIC_LEFT_RANGE                                     -1:0
`define    DS_MEM_MAC_STATIC_LEFT_WIDTH                                     0

// DsMemMacStaticRight
`define    DS_MEM_MAC_STATIC_RIGHT_RANGE                                    -1:0
`define    DS_MEM_MAC_STATIC_RIGHT_WIDTH                                    0

// DsMemMacTsn
`define    DS_MEM_MAC_TSN_RANGE                                             -1:0
`define    DS_MEM_MAC_TSN_WIDTH                                             0

// DsMemMacTsnLeft
`define    DS_MEM_MAC_TSN_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_TSN_LEFT_WIDTH                                        0

// DsMemMacTsnRight
`define    DS_MEM_MAC_TSN_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_TSN_RIGHT_WIDTH                                       0

// DsMemMacValidLeft
`define    DS_MEM_MAC_VALID_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_VALID_LEFT_WIDTH                                      0

// DsMemMacValidRight
`define    DS_MEM_MAC_VALID_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_VALID_RIGHT_WIDTH                                     0

// DsMemPortColorStats
`define    DS_MEM_PORT_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_PORT_COLOR_STATS_WIDTH                                    0

// DsMemPortPolice
`define    DS_MEM_PORT_POLICE_RANGE                                         -1:0
`define    DS_MEM_PORT_POLICE_WIDTH                                         0

// DsMemPortPoliceCfg
`define    DS_MEM_PORT_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_PORT_POLICE_CFG_WIDTH                                     0

// DsMemProtocolVlan
`define    DS_MEM_PROTOCOL_VLAN_RANGE                                       5:0
`define    DS_MEM_PROTOCOL_VLAN_WIDTH                                       6

`define    DS_MEM_PROTOCOL_VLAN_REPLACE_VLAN_RANGE                          0:0
`define    DS_MEM_PROTOCOL_VLAN_REPLACE_VLAN_WIDTH                          1

`define    DS_MEM_PROTOCOL_VLAN_VLAN_ID_RANGE                               1:1
`define    DS_MEM_PROTOCOL_VLAN_VLAN_ID_WIDTH                               1

`define    DS_MEM_PROTOCOL_VLAN_REPLACE_COS_RANGE                           2:2
`define    DS_MEM_PROTOCOL_VLAN_REPLACE_COS_WIDTH                           1

`define    DS_MEM_PROTOCOL_VLAN_COS_RANGE                                   3:3
`define    DS_MEM_PROTOCOL_VLAN_COS_WIDTH                                   1

`define    DS_MEM_PROTOCOL_VLAN_REPLACE_DSCP_RANGE                          4:4
`define    DS_MEM_PROTOCOL_VLAN_REPLACE_DSCP_WIDTH                          1

`define    DS_MEM_PROTOCOL_VLAN_DSCP_RANGE                                  5:5
`define    DS_MEM_PROTOCOL_VLAN_DSCP_WIDTH                                  1

// DsMemRouteTsn
`define    DS_MEM_ROUTE_TSN_RANGE                                           -1:0
`define    DS_MEM_ROUTE_TSN_WIDTH                                           0

// DsMemSrcPort
`define    DS_MEM_SRC_PORT_RANGE                                            23:0
`define    DS_MEM_SRC_PORT_WIDTH                                            24

`define    DS_MEM_SRC_PORT_DEFAULT_VLAN_ID_RANGE                            0:0
`define    DS_MEM_SRC_PORT_DEFAULT_VLAN_ID_WIDTH                            1

`define    DS_MEM_SRC_PORT_L2_ACL_LABEL_RANGE                               1:1
`define    DS_MEM_SRC_PORT_L2_ACL_LABEL_WIDTH                               1

`define    DS_MEM_SRC_PORT_LINK_AGG_ID_RANGE                                2:2
`define    DS_MEM_SRC_PORT_LINK_AGG_ID_WIDTH                                1

`define    DS_MEM_SRC_PORT_DEFAULT_PCP_RANGE                                3:3
`define    DS_MEM_SRC_PORT_DEFAULT_PCP_WIDTH                                1

`define    DS_MEM_SRC_PORT_QOS_POLICY_RANGE                                 4:4
`define    DS_MEM_SRC_PORT_QOS_POLICY_WIDTH                                 1

`define    DS_MEM_SRC_PORT_AFT_RANGE                                        5:5
`define    DS_MEM_SRC_PORT_AFT_WIDTH                                        1

`define    DS_MEM_SRC_PORT_IS_LINK_AGG_MBR_RANGE                            6:6
`define    DS_MEM_SRC_PORT_IS_LINK_AGG_MBR_WIDTH                            1

`define    DS_MEM_SRC_PORT_INGRESS_FILTERING_EN_RANGE                       7:7
`define    DS_MEM_SRC_PORT_INGRESS_FILTERING_EN_WIDTH                       1

`define    DS_MEM_SRC_PORT_PORT_POLICE_EN_RANGE                             8:8
`define    DS_MEM_SRC_PORT_PORT_POLICE_EN_WIDTH                             1

`define    DS_MEM_SRC_PORT_LRN_DISABLE_RANGE                                9:9
`define    DS_MEM_SRC_PORT_LRN_DISABLE_WIDTH                                1

`define    DS_MEM_SRC_PORT_L2_SRC_MATCH_DISCARD_RANGE                       10:10
`define    DS_MEM_SRC_PORT_L2_SRC_MATCH_DISCARD_WIDTH                       1

`define    DS_MEM_SRC_PORT_BPDU_DROP_RANGE                                  11:11
`define    DS_MEM_SRC_PORT_BPDU_DROP_WIDTH                                  1

`define    DS_MEM_SRC_PORT_STP_DISABLE_RANGE                                12:12
`define    DS_MEM_SRC_PORT_STP_DISABLE_WIDTH                                1

`define    DS_MEM_SRC_PORT_FORCE_PORT_BASED_VLAN_RANGE                      13:13
`define    DS_MEM_SRC_PORT_FORCE_PORT_BASED_VLAN_WIDTH                      1

`define    DS_MEM_SRC_PORT_L2_ACL_EN_RANGE                                  14:14
`define    DS_MEM_SRC_PORT_L2_ACL_EN_WIDTH                                  1

`define    DS_MEM_SRC_PORT_L2_ACL_HI_PRIO_RANGE                             15:15
`define    DS_MEM_SRC_PORT_L2_ACL_HI_PRIO_WIDTH                             1

`define    DS_MEM_SRC_PORT_IPV4_FORCE_MAC_KEY_RANGE                         16:16
`define    DS_MEM_SRC_PORT_IPV4_FORCE_MAC_KEY_WIDTH                         1

`define    DS_MEM_SRC_PORT_IPV6_FORCE_MAC_KEY_RANGE                         17:17
`define    DS_MEM_SRC_PORT_IPV6_FORCE_MAC_KEY_WIDTH                         1

`define    DS_MEM_SRC_PORT_REPLACE_DSCP_RANGE                               18:18
`define    DS_MEM_SRC_PORT_REPLACE_DSCP_WIDTH                               1

`define    DS_MEM_SRC_PORT_REPLACE_COS_RANGE                                19:19
`define    DS_MEM_SRC_PORT_REPLACE_COS_WIDTH                                1

`define    DS_MEM_SRC_PORT_VLAN_PRIO_EN_RANGE                               20:20
`define    DS_MEM_SRC_PORT_VLAN_PRIO_EN_WIDTH                               1

`define    DS_MEM_SRC_PORT_MAC_BASED_VLAN_HI_PRIO_RANGE                     21:21
`define    DS_MEM_SRC_PORT_MAC_BASED_VLAN_HI_PRIO_WIDTH                     1

`define    DS_MEM_SRC_PORT_KEEP_VLAN_TAG_RANGE                              22:22
`define    DS_MEM_SRC_PORT_KEEP_VLAN_TAG_WIDTH                              1

`define    DS_MEM_SRC_PORT_INGRESS_L2_SPAN_EN_RANGE                         23:23
`define    DS_MEM_SRC_PORT_INGRESS_L2_SPAN_EN_WIDTH                         1

// DsMemStpState
`define    DS_MEM_STP_STATE_RANGE                                           0:0
`define    DS_MEM_STP_STATE_WIDTH                                           1

`define    DS_MEM_STP_STATE_STP_STATE_RANGE                                 0:0
`define    DS_MEM_STP_STATE_STP_STATE_WIDTH                                 1

// DsMemStreamRcvyCfg
`define    DS_MEM_STREAM_RCVY_CFG_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CFG_WIDTH                                     0

// DsMemStreamRcvyCnt
`define    DS_MEM_STREAM_RCVY_CNT_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CNT_WIDTH                                     0

// DsMemStreamRcvySeq
`define    DS_MEM_STREAM_RCVY_SEQ_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_SEQ_WIDTH                                     0

// DsMemTsnDomain
`define    DS_MEM_TSN_DOMAIN_RANGE                                          0:0
`define    DS_MEM_TSN_DOMAIN_WIDTH                                          1

`define    DS_MEM_TSN_DOMAIN_CORE_PORT_BMP_RANGE                            0:0
`define    DS_MEM_TSN_DOMAIN_CORE_PORT_BMP_WIDTH                            1

// DsMemVlan
`define    DS_MEM_VLAN_RANGE                                                28:0
`define    DS_MEM_VLAN_WIDTH                                                29

`define    DS_MEM_VLAN_COS_RANGE                                            0:0
`define    DS_MEM_VLAN_COS_WIDTH                                            1

`define    DS_MEM_VLAN_VRRP_GRP_BMP_RANGE                                   1:1
`define    DS_MEM_VLAN_VRRP_GRP_BMP_WIDTH                                   1

`define    DS_MEM_VLAN_ROUTING_EN_RANGE                                     2:2
`define    DS_MEM_VLAN_ROUTING_EN_WIDTH                                     1

`define    DS_MEM_VLAN_MCAST_VLAN_EN_RANGE                                  3:3
`define    DS_MEM_VLAN_MCAST_VLAN_EN_WIDTH                                  1

`define    DS_MEM_VLAN_TSN_EN_RANGE                                         4:4
`define    DS_MEM_VLAN_TSN_EN_WIDTH                                         1

`define    DS_MEM_VLAN_L3_ACL_EN_RANGE                                      5:5
`define    DS_MEM_VLAN_L3_ACL_EN_WIDTH                                      1

`define    DS_MEM_VLAN_L3_ACL_LABEL_RANGE                                   6:6
`define    DS_MEM_VLAN_L3_ACL_LABEL_WIDTH                                   1

`define    DS_MEM_VLAN_L3_SPAN_EN_RANGE                                     7:7
`define    DS_MEM_VLAN_L3_SPAN_EN_WIDTH                                     1

`define    DS_MEM_VLAN_STP_ID_RANGE                                         8:8
`define    DS_MEM_VLAN_STP_ID_WIDTH                                         1

`define    DS_MEM_VLAN_FID_RANGE                                            9:9
`define    DS_MEM_VLAN_FID_WIDTH                                            1

`define    DS_MEM_VLAN_REPLACE_COS_RANGE                                    10:10
`define    DS_MEM_VLAN_REPLACE_COS_WIDTH                                    1

`define    DS_MEM_VLAN_REPLACE_DSCP_RANGE                                   11:11
`define    DS_MEM_VLAN_REPLACE_DSCP_WIDTH                                   1

`define    DS_MEM_VLAN_ARP_INSPECTION_RANGE                                 12:12
`define    DS_MEM_VLAN_ARP_INSPECTION_WIDTH                                 1

`define    DS_MEM_VLAN_HW_BCAST_ARP_RANGE                                   13:13
`define    DS_MEM_VLAN_HW_BCAST_ARP_WIDTH                                   1

`define    DS_MEM_VLAN_MSRP_TO_CPU_RANGE                                    14:14
`define    DS_MEM_VLAN_MSRP_TO_CPU_WIDTH                                    1

`define    DS_MEM_VLAN_HW_FWD_MSRP_RANGE                                    15:15
`define    DS_MEM_VLAN_HW_FWD_MSRP_WIDTH                                    1

`define    DS_MEM_VLAN_MMRP_TO_CPU_RANGE                                    16:16
`define    DS_MEM_VLAN_MMRP_TO_CPU_WIDTH                                    1

`define    DS_MEM_VLAN_HW_FWD_MMRP_RANGE                                    17:17
`define    DS_MEM_VLAN_HW_FWD_MMRP_WIDTH                                    1

`define    DS_MEM_VLAN_MVRP_TO_CPU_RANGE                                    18:18
`define    DS_MEM_VLAN_MVRP_TO_CPU_WIDTH                                    1

`define    DS_MEM_VLAN_HW_FWD_MVRP_RANGE                                    19:19
`define    DS_MEM_VLAN_HW_FWD_MVRP_WIDTH                                    1

`define    DS_MEM_VLAN_IGMP_SNOOP_EN_RANGE                                  20:20
`define    DS_MEM_VLAN_IGMP_SNOOP_EN_WIDTH                                  1

`define    DS_MEM_VLAN_HW_BCAST_IGMP_RANGE                                  21:21
`define    DS_MEM_VLAN_HW_BCAST_IGMP_WIDTH                                  1

`define    DS_MEM_VLAN_MLD_SNOOP_EN_RANGE                                   22:22
`define    DS_MEM_VLAN_MLD_SNOOP_EN_WIDTH                                   1

`define    DS_MEM_VLAN_HW_BCAST_MLD_RANGE                                   23:23
`define    DS_MEM_VLAN_HW_BCAST_MLD_WIDTH                                   1

`define    DS_MEM_VLAN_ND_TO_CPU_RANGE                                      24:24
`define    DS_MEM_VLAN_ND_TO_CPU_WIDTH                                      1

`define    DS_MEM_VLAN_HW_FWD_ND_RANGE                                      25:25
`define    DS_MEM_VLAN_HW_FWD_ND_WIDTH                                      1

`define    DS_MEM_VLAN_SNMP_TO_CPU_RANGE                                    26:26
`define    DS_MEM_VLAN_SNMP_TO_CPU_WIDTH                                    1

`define    DS_MEM_VLAN_HW_FWD_SNMP_RANGE                                    27:27
`define    DS_MEM_VLAN_HW_FWD_SNMP_WIDTH                                    1

`define    DS_MEM_VLAN_LRN_DISABLE_RANGE                                    28:28
`define    DS_MEM_VLAN_LRN_DISABLE_WIDTH                                    1

// MsgAdmInfo0
`define    MSG_ADM_INFO0_RANGE                                              -1:0
`define    MSG_ADM_INFO0_WIDTH                                              0

// TmpDsMemMac
`define    TMP_DS_MEM_MAC_RANGE                                             -1:0
`define    TMP_DS_MEM_MAC_WIDTH                                             0

// CtlCommon
`define    CTL_COMMON_RANGE                                                 1:0
`define    CTL_COMMON_WIDTH                                                 2

`define    CTL_COMMON_CPU_PORT_NO_RANGE                                     0:0
`define    CTL_COMMON_CPU_PORT_NO_WIDTH                                     1

`define    CTL_COMMON_CPU_HDR_EN_RANGE                                      1:1
`define    CTL_COMMON_CPU_HDR_EN_WIDTH                                      1

// CtlHdrAdjLog
`define    CTL_HDR_ADJ_LOG_RANGE                                            3:0
`define    CTL_HDR_ADJ_LOG_WIDTH                                            4

`define    CTL_HDR_ADJ_LOG_IS_TSN_RANGE                                     0:0
`define    CTL_HDR_ADJ_LOG_IS_TSN_WIDTH                                     1

`define    CTL_HDR_ADJ_LOG_DISCARD_RANGE                                    1:1
`define    CTL_HDR_ADJ_LOG_DISCARD_WIDTH                                    1

`define    CTL_HDR_ADJ_LOG_SRC_PORT_RANGE                                   2:2
`define    CTL_HDR_ADJ_LOG_SRC_PORT_WIDTH                                   1

`define    CTL_HDR_ADJ_LOG_PKT_LEN_LOG_RANGE                                3:3
`define    CTL_HDR_ADJ_LOG_PKT_LEN_LOG_WIDTH                                1

// DsMemAclTsn
`define    DS_MEM_ACL_TSN_RANGE                                             -1:0
`define    DS_MEM_ACL_TSN_WIDTH                                             0

// DsMemFlowColorStats
`define    DS_MEM_FLOW_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_FLOW_COLOR_STATS_WIDTH                                    0

// DsMemFlowPolice
`define    DS_MEM_FLOW_POLICE_RANGE                                         -1:0
`define    DS_MEM_FLOW_POLICE_WIDTH                                         0

// DsMemFlowPoliceCfg
`define    DS_MEM_FLOW_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_FLOW_POLICE_CFG_WIDTH                                     0

// DsMemHostRoute
`define    DS_MEM_HOST_ROUTE_RANGE                                          -1:0
`define    DS_MEM_HOST_ROUTE_WIDTH                                          0

// DsMemHostRouteLeft
`define    DS_MEM_HOST_ROUTE_LEFT_RANGE                                     -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_WIDTH                                     0

// DsMemHostRouteLeftKey
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_RANGE                                 -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_WIDTH                                 0

// DsMemHostRouteLeftValid
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_RANGE                               -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_WIDTH                               0

// DsMemHostRouteRight
`define    DS_MEM_HOST_ROUTE_RIGHT_RANGE                                    -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_WIDTH                                    0

// DsMemHostRouteRightKey
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_RANGE                                -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_WIDTH                                0

// DsMemHostRouteRightValid
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_RANGE                              -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_WIDTH                              0

// DsMemHostTsn
`define    DS_MEM_HOST_TSN_RANGE                                            -1:0
`define    DS_MEM_HOST_TSN_WIDTH                                            0

// DsMemHostTsnLeft
`define    DS_MEM_HOST_TSN_LEFT_RANGE                                       -1:0
`define    DS_MEM_HOST_TSN_LEFT_WIDTH                                       0

// DsMemHostTsnRight
`define    DS_MEM_HOST_TSN_RIGHT_RANGE                                      -1:0
`define    DS_MEM_HOST_TSN_RIGHT_WIDTH                                      0

// DsMemIndvRcvyCfg
`define    DS_MEM_INDV_RCVY_CFG_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CFG_WIDTH                                       0

// DsMemIndvRcvyCnt
`define    DS_MEM_INDV_RCVY_CNT_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CNT_WIDTH                                       0

// DsMemIndvRcvySeq
`define    DS_MEM_INDV_RCVY_SEQ_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_SEQ_WIDTH                                       0

// DsMemMacAgingLeft
`define    DS_MEM_MAC_AGING_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_AGING_LEFT_WIDTH                                      0

// DsMemMacAgingRight
`define    DS_MEM_MAC_AGING_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_AGING_RIGHT_WIDTH                                     0

// DsMemMacKeyLeft
`define    DS_MEM_MAC_KEY_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_KEY_LEFT_WIDTH                                        0

// DsMemMacKeyRight
`define    DS_MEM_MAC_KEY_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_KEY_RIGHT_WIDTH                                       0

// DsMemMacLeft
`define    DS_MEM_MAC_LEFT_RANGE                                            -1:0
`define    DS_MEM_MAC_LEFT_WIDTH                                            0

// DsMemMacRight
`define    DS_MEM_MAC_RIGHT_RANGE                                           -1:0
`define    DS_MEM_MAC_RIGHT_WIDTH                                           0

// DsMemMacStaticLeft
`define    DS_MEM_MAC_STATIC_LEFT_RANGE                                     -1:0
`define    DS_MEM_MAC_STATIC_LEFT_WIDTH                                     0

// DsMemMacStaticRight
`define    DS_MEM_MAC_STATIC_RIGHT_RANGE                                    -1:0
`define    DS_MEM_MAC_STATIC_RIGHT_WIDTH                                    0

// DsMemMacTsn
`define    DS_MEM_MAC_TSN_RANGE                                             -1:0
`define    DS_MEM_MAC_TSN_WIDTH                                             0

// DsMemMacTsnLeft
`define    DS_MEM_MAC_TSN_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_TSN_LEFT_WIDTH                                        0

// DsMemMacTsnRight
`define    DS_MEM_MAC_TSN_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_TSN_RIGHT_WIDTH                                       0

// DsMemMacValidLeft
`define    DS_MEM_MAC_VALID_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_VALID_LEFT_WIDTH                                      0

// DsMemMacValidRight
`define    DS_MEM_MAC_VALID_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_VALID_RIGHT_WIDTH                                     0

// DsMemPortColorStats
`define    DS_MEM_PORT_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_PORT_COLOR_STATS_WIDTH                                    0

// DsMemPortPolice
`define    DS_MEM_PORT_POLICE_RANGE                                         -1:0
`define    DS_MEM_PORT_POLICE_WIDTH                                         0

// DsMemPortPoliceCfg
`define    DS_MEM_PORT_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_PORT_POLICE_CFG_WIDTH                                     0

// DsMemRouteTsn
`define    DS_MEM_ROUTE_TSN_RANGE                                           -1:0
`define    DS_MEM_ROUTE_TSN_WIDTH                                           0

// DsMemStreamRcvyCfg
`define    DS_MEM_STREAM_RCVY_CFG_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CFG_WIDTH                                     0

// DsMemStreamRcvyCnt
`define    DS_MEM_STREAM_RCVY_CNT_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CNT_WIDTH                                     0

// DsMemStreamRcvySeq
`define    DS_MEM_STREAM_RCVY_SEQ_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_SEQ_WIDTH                                     0

// DsRegChnlAttr
`define    DS_REG_CHNL_ATTR_RANGE                                           3:0
`define    DS_REG_CHNL_ATTR_WIDTH                                           4

`define    DS_REG_CHNL_ATTR_PORT_ID_RANGE                                   0:0
`define    DS_REG_CHNL_ATTR_PORT_ID_WIDTH                                   1

`define    DS_REG_CHNL_ATTR_BYPASS_PP_RANGE                                 1:1
`define    DS_REG_CHNL_ATTR_BYPASS_PP_WIDTH                                 1

`define    DS_REG_CHNL_ATTR_DEST_MAP_RANGE                                  2:2
`define    DS_REG_CHNL_ATTR_DEST_MAP_WIDTH                                  1

`define    DS_REG_CHNL_ATTR_DOT1Q_TYPE_RANGE                                3:3
`define    DS_REG_CHNL_ATTR_DOT1Q_TYPE_WIDTH                                1

// MsgAdmInfo0
`define    MSG_ADM_INFO0_RANGE                                              -1:0
`define    MSG_ADM_INFO0_WIDTH                                              0

// TmpDsMemMac
`define    TMP_DS_MEM_MAC_RANGE                                             -1:0
`define    TMP_DS_MEM_MAC_WIDTH                                             0

// CtlCommon
`define    CTL_COMMON_RANGE                                                 0:0
`define    CTL_COMMON_WIDTH                                                 1

`define    CTL_COMMON_CPU_PORT_NO_RANGE                                     0:0
`define    CTL_COMMON_CPU_PORT_NO_WIDTH                                     1

// CtlEgrCpu
`define    CTL_EGR_CPU_RANGE                                                2:0
`define    CTL_EGR_CPU_WIDTH                                                3

`define    CTL_EGR_CPU_FORBID_EDIT_RANGE                                    0:0
`define    CTL_EGR_CPU_FORBID_EDIT_WIDTH                                    1

`define    CTL_EGR_CPU_NEED_CPU_HDR_RANGE                                   1:1
`define    CTL_EGR_CPU_NEED_CPU_HDR_WIDTH                                   1

`define    CTL_EGR_CPU_MAX_LENGTH_RANGE                                     2:2
`define    CTL_EGR_CPU_MAX_LENGTH_WIDTH                                     1

// CtlEgrDot1qTpid
`define    CTL_EGR_DOT1Q_TPID_RANGE                                         0:0
`define    CTL_EGR_DOT1Q_TPID_WIDTH                                         1

`define    CTL_EGR_DOT1Q_TPID_TPID_OUT_RANGE                                0:0
`define    CTL_EGR_DOT1Q_TPID_TPID_OUT_WIDTH                                1

// CtlEgrEdit
`define    CTL_EGR_EDIT_RANGE                                               9:0
`define    CTL_EGR_EDIT_WIDTH                                               10

`define    CTL_EGR_EDIT_V4_PTP_UDP_CHKSUM_SET0_RANGE                        0:0
`define    CTL_EGR_EDIT_V4_PTP_UDP_CHKSUM_SET0_WIDTH                        1

`define    CTL_EGR_EDIT_RTAG_TPID_RANGE                                     1:1
`define    CTL_EGR_EDIT_RTAG_TPID_WIDTH                                     1

`define    CTL_EGR_EDIT_RTAG_CONTENT_RANGE                                  2:2
`define    CTL_EGR_EDIT_RTAG_CONTENT_WIDTH                                  1

`define    CTL_EGR_EDIT_PTP_UPD_MAC_SA_EN_RANGE                             3:3
`define    CTL_EGR_EDIT_PTP_UPD_MAC_SA_EN_WIDTH                             1

`define    CTL_EGR_EDIT_PTP_MAC_ADDR_RANGE                                  4:4
`define    CTL_EGR_EDIT_PTP_MAC_ADDR_WIDTH                                  1

`define    CTL_EGR_EDIT_PTP_MAC_ADDR_HI_RANGE                               5:5
`define    CTL_EGR_EDIT_PTP_MAC_ADDR_HI_WIDTH                               1

`define    CTL_EGR_EDIT_UPD_V6_PTP_UDP_CHKSUM_RANGE                         6:6
`define    CTL_EGR_EDIT_UPD_V6_PTP_UDP_CHKSUM_WIDTH                         1

`define    CTL_EGR_EDIT_PTP_DEV_TYPE_RANGE                                  7:7
`define    CTL_EGR_EDIT_PTP_DEV_TYPE_WIDTH                                  1

`define    CTL_EGR_EDIT_CF_MISSED_TYPE_RANGE                                8:8
`define    CTL_EGR_EDIT_CF_MISSED_TYPE_WIDTH                                1

`define    CTL_EGR_EDIT_TS_MISSED_TYPE_RANGE                                9:9
`define    CTL_EGR_EDIT_TS_MISSED_TYPE_WIDTH                                1

// CtlEgrExcpDestPort
`define    CTL_EGR_EXCP_DEST_PORT_RANGE                                     1:0
`define    CTL_EGR_EXCP_DEST_PORT_WIDTH                                     2

`define    CTL_EGR_EXCP_DEST_PORT_DEST_PORT_RANGE                           0:0
`define    CTL_EGR_EXCP_DEST_PORT_DEST_PORT_WIDTH                           1

`define    CTL_EGR_EXCP_DEST_PORT_EXCP_ADD_CPU_HDR_RANGE                    1:1
`define    CTL_EGR_EXCP_DEST_PORT_EXCP_ADD_CPU_HDR_WIDTH                    1

// CtlEgrExt
`define    CTL_EGR_EXT_RANGE                                                2:0
`define    CTL_EGR_EXT_WIDTH                                                3

`define    CTL_EGR_EXT_EXT_FORBID_EDIT_RANGE                                0:0
`define    CTL_EGR_EXT_EXT_FORBID_EDIT_WIDTH                                1

`define    CTL_EGR_EXT_EXT_NEED_CPU_HDR_RANGE                               1:1
`define    CTL_EGR_EXT_EXT_NEED_CPU_HDR_WIDTH                               1

`define    CTL_EGR_EXT_EXT_REMOTE_SPAN_RANGE                                2:2
`define    CTL_EGR_EXT_EXT_REMOTE_SPAN_WIDTH                                1

// CtlEgrLog
`define    CTL_EGR_LOG_RANGE                                                22:0
`define    CTL_EGR_LOG_WIDTH                                                23

`define    CTL_EGR_LOG_VLAN_ID_RANGE                                        0:0
`define    CTL_EGR_LOG_VLAN_ID_WIDTH                                        1

`define    CTL_EGR_LOG_EXCP_TYPE_RANGE                                      1:1
`define    CTL_EGR_LOG_EXCP_TYPE_WIDTH                                      1

`define    CTL_EGR_LOG_OP_CODE_RANGE                                        2:2
`define    CTL_EGR_LOG_OP_CODE_WIDTH                                        1

`define    CTL_EGR_LOG_EGR_DISCARD_RANGE                                    3:3
`define    CTL_EGR_LOG_EGR_DISCARD_WIDTH                                    1

`define    CTL_EGR_LOG_ROUTED_PKT_RANGE                                     4:4
`define    CTL_EGR_LOG_ROUTED_PKT_WIDTH                                     1

`define    CTL_EGR_LOG_REMOVE_CPU_HDR_RANGE                                 5:5
`define    CTL_EGR_LOG_REMOVE_CPU_HDR_WIDTH                                 1

`define    CTL_EGR_LOG_ADD_CPU_HDR_RANGE                                    6:6
`define    CTL_EGR_LOG_ADD_CPU_HDR_WIDTH                                    1

`define    CTL_EGR_LOG_UPDATE_MAC_DA_RANGE                                  7:7
`define    CTL_EGR_LOG_UPDATE_MAC_DA_WIDTH                                  1

`define    CTL_EGR_LOG_UPDATE_MAC_SA_RANGE                                  8:8
`define    CTL_EGR_LOG_UPDATE_MAC_SA_WIDTH                                  1

`define    CTL_EGR_LOG_REMOVE_VLAN_TAG_RANGE                                9:9
`define    CTL_EGR_LOG_REMOVE_VLAN_TAG_WIDTH                                1

`define    CTL_EGR_LOG_ADD_VLAN_TAG_RANGE                                   10:10
`define    CTL_EGR_LOG_ADD_VLAN_TAG_WIDTH                                   1

`define    CTL_EGR_LOG_REMOTE_SPAN_RANGE                                    11:11
`define    CTL_EGR_LOG_REMOTE_SPAN_WIDTH                                    1

`define    CTL_EGR_LOG_ADD_RTAG_RANGE                                       12:12
`define    CTL_EGR_LOG_ADD_RTAG_WIDTH                                       1

`define    CTL_EGR_LOG_REPLACE_COS_RANGE                                    13:13
`define    CTL_EGR_LOG_REPLACE_COS_WIDTH                                    1

`define    CTL_EGR_LOG_REPLACE_DSCP_RANGE                                   14:14
`define    CTL_EGR_LOG_REPLACE_DSCP_WIDTH                                   1

`define    CTL_EGR_LOG_EGR_STP_CHK_FAIL_RANGE                               15:15
`define    CTL_EGR_LOG_EGR_STP_CHK_FAIL_WIDTH                               1

`define    CTL_EGR_LOG_PTP_PORT_TYPE_CHK_FAIL_RANGE                         16:16
`define    CTL_EGR_LOG_PTP_PORT_TYPE_CHK_FAIL_WIDTH                         1

`define    CTL_EGR_LOG_PTP_TYPE_RANGE                                       17:17
`define    CTL_EGR_LOG_PTP_TYPE_WIDTH                                       1

`define    CTL_EGR_LOG_UPD_PTP_TS_RANGE                                     18:18
`define    CTL_EGR_LOG_UPD_PTP_TS_WIDTH                                     1

`define    CTL_EGR_LOG_UPD_PTP_CF_RANGE                                     19:19
`define    CTL_EGR_LOG_UPD_PTP_CF_WIDTH                                     1

`define    CTL_EGR_LOG_INTR_PTP_TS_RANGE                                    20:20
`define    CTL_EGR_LOG_INTR_PTP_TS_WIDTH                                    1

`define    CTL_EGR_LOG_XCON_ERR_RANGE                                       21:21
`define    CTL_EGR_LOG_XCON_ERR_WIDTH                                       1

`define    CTL_EGR_LOG_TRUNCATE_CPU_PKT_RANGE                               22:22
`define    CTL_EGR_LOG_TRUNCATE_CPU_PKT_WIDTH                               1

// CtlEgrOam
`define    CTL_EGR_OAM_RANGE                                                0:0
`define    CTL_EGR_OAM_WIDTH                                                1

`define    CTL_EGR_OAM_OAM_OBEY_DISCARD_RANGE                               0:0
`define    CTL_EGR_OAM_OAM_OBEY_DISCARD_WIDTH                               1

// CtlRemoteSpan
`define    CTL_REMOTE_SPAN_RANGE                                            3:0
`define    CTL_REMOTE_SPAN_WIDTH                                            4

`define    CTL_REMOTE_SPAN_COS_VALID_RANGE                                  0:0
`define    CTL_REMOTE_SPAN_COS_VALID_WIDTH                                  1

`define    CTL_REMOTE_SPAN_COS_RANGE                                        1:1
`define    CTL_REMOTE_SPAN_COS_WIDTH                                        1

`define    CTL_REMOTE_SPAN_TPID_RANGE                                       2:2
`define    CTL_REMOTE_SPAN_TPID_WIDTH                                       1

`define    CTL_REMOTE_SPAN_VLAN_ID_RANGE                                    3:3
`define    CTL_REMOTE_SPAN_VLAN_ID_WIDTH                                    1

// CtlRouterPktMac
`define    CTL_ROUTER_PKT_MAC_RANGE                                         1:0
`define    CTL_ROUTER_PKT_MAC_WIDTH                                         2

`define    CTL_ROUTER_PKT_MAC_ROUTER_MAC_RANGE                              0:0
`define    CTL_ROUTER_PKT_MAC_ROUTER_MAC_WIDTH                              1

`define    CTL_ROUTER_PKT_MAC_ROUTER_MAC_HI_RANGE                           1:1
`define    CTL_ROUTER_PKT_MAC_ROUTER_MAC_HI_WIDTH                           1

// DsMemAclTsn
`define    DS_MEM_ACL_TSN_RANGE                                             -1:0
`define    DS_MEM_ACL_TSN_WIDTH                                             0

// DsMemDestPort
`define    DS_MEM_DEST_PORT_RANGE                                           7:0
`define    DS_MEM_DEST_PORT_WIDTH                                           8

`define    DS_MEM_DEST_PORT_PTP_EN_RANGE                                    0:0
`define    DS_MEM_DEST_PORT_PTP_EN_WIDTH                                    1

`define    DS_MEM_DEST_PORT_SPECIFY_OUT_VID_RANGE                           1:1
`define    DS_MEM_DEST_PORT_SPECIFY_OUT_VID_WIDTH                           1

`define    DS_MEM_DEST_PORT_DOT1Q_TYPE_RANGE                                2:2
`define    DS_MEM_DEST_PORT_DOT1Q_TYPE_WIDTH                                1

`define    DS_MEM_DEST_PORT_REPLACE_COS_RANGE                               3:3
`define    DS_MEM_DEST_PORT_REPLACE_COS_WIDTH                               1

`define    DS_MEM_DEST_PORT_REPLACE_DSCP_RANGE                              4:4
`define    DS_MEM_DEST_PORT_REPLACE_DSCP_WIDTH                              1

`define    DS_MEM_DEST_PORT_PTP_PORT_TYPE_RANGE                             5:5
`define    DS_MEM_DEST_PORT_PTP_PORT_TYPE_WIDTH                             1

`define    DS_MEM_DEST_PORT_SPECIFIED_VLAN_ID_RANGE                         6:6
`define    DS_MEM_DEST_PORT_SPECIFIED_VLAN_ID_WIDTH                         1

`define    DS_MEM_DEST_PORT_PORT_ETH_OAM_EN_RANGE                           7:7
`define    DS_MEM_DEST_PORT_PORT_ETH_OAM_EN_WIDTH                           1

// DsMemDestStpState
`define    DS_MEM_DEST_STP_STATE_RANGE                                      0:0
`define    DS_MEM_DEST_STP_STATE_WIDTH                                      1

`define    DS_MEM_DEST_STP_STATE_STP_STATE_RANGE                            0:0
`define    DS_MEM_DEST_STP_STATE_STP_STATE_WIDTH                            1

// DsMemDestVlan
`define    DS_MEM_DEST_VLAN_RANGE                                           4:0
`define    DS_MEM_DEST_VLAN_WIDTH                                           5

`define    DS_MEM_DEST_VLAN_L3_IF_CHECK_RANGE                               0:0
`define    DS_MEM_DEST_VLAN_L3_IF_CHECK_WIDTH                               1

`define    DS_MEM_DEST_VLAN_MTU_CHECK_RANGE                                 1:1
`define    DS_MEM_DEST_VLAN_MTU_CHECK_WIDTH                                 1

`define    DS_MEM_DEST_VLAN_MTU_SIZE_RANGE                                  2:2
`define    DS_MEM_DEST_VLAN_MTU_SIZE_WIDTH                                  1

`define    DS_MEM_DEST_VLAN_UNTAG_PORT_BMP_RANGE                            3:3
`define    DS_MEM_DEST_VLAN_UNTAG_PORT_BMP_WIDTH                            1

`define    DS_MEM_DEST_VLAN_VLAN_ETH_OAM_EN_RANGE                           4:4
`define    DS_MEM_DEST_VLAN_VLAN_ETH_OAM_EN_WIDTH                           1

// DsMemEgrExcpStats
`define    DS_MEM_EGR_EXCP_STATS_RANGE                                      1:0
`define    DS_MEM_EGR_EXCP_STATS_WIDTH                                      2

`define    DS_MEM_EGR_EXCP_STATS_PKT_CNT_RANGE                              0:0
`define    DS_MEM_EGR_EXCP_STATS_PKT_CNT_WIDTH                              1

`define    DS_MEM_EGR_EXCP_STATS_BYTE_CNT_RANGE                             1:1
`define    DS_MEM_EGR_EXCP_STATS_BYTE_CNT_WIDTH                             1

// DsMemEgrMepPtr
`define    DS_MEM_EGR_MEP_PTR_RANGE                                         0:0
`define    DS_MEM_EGR_MEP_PTR_WIDTH                                         1

`define    DS_MEM_EGR_MEP_PTR_OAM_IDX_RANGE                                 0:0
`define    DS_MEM_EGR_MEP_PTR_OAM_IDX_WIDTH                                 1

// DsMemEgrOamKey
`define    DS_MEM_EGR_OAM_KEY_RANGE                                         4:0
`define    DS_MEM_EGR_OAM_KEY_WIDTH                                         5

`define    DS_MEM_EGR_OAM_KEY_KEY0_RANGE                                    0:0
`define    DS_MEM_EGR_OAM_KEY_KEY0_WIDTH                                    1

`define    DS_MEM_EGR_OAM_KEY_VALID_RANGE                                   1:1
`define    DS_MEM_EGR_OAM_KEY_VALID_WIDTH                                   1

`define    DS_MEM_EGR_OAM_KEY_KEY1_RANGE                                    2:2
`define    DS_MEM_EGR_OAM_KEY_KEY1_WIDTH                                    1

`define    DS_MEM_EGR_OAM_KEY_KEY2_RANGE                                    3:3
`define    DS_MEM_EGR_OAM_KEY_KEY2_WIDTH                                    1

`define    DS_MEM_EGR_OAM_KEY_KEY3_RANGE                                    4:4
`define    DS_MEM_EGR_OAM_KEY_KEY3_WIDTH                                    1

// DsMemEgrOamSession
`define    DS_MEM_EGR_OAM_SESSION_RANGE                                     1:0
`define    DS_MEM_EGR_OAM_SESSION_WIDTH                                     2

`define    DS_MEM_EGR_OAM_SESSION_MDL_BMP_RANGE                             0:0
`define    DS_MEM_EGR_OAM_SESSION_MDL_BMP_WIDTH                             1

`define    DS_MEM_EGR_OAM_SESSION_MEP_BASE_PTR_RANGE                        1:1
`define    DS_MEM_EGR_OAM_SESSION_MEP_BASE_PTR_WIDTH                        1

// DsMemEgrSrcPort
`define    DS_MEM_EGR_SRC_PORT_RANGE                                        0:0
`define    DS_MEM_EGR_SRC_PORT_WIDTH                                        1

`define    DS_MEM_EGR_SRC_PORT_P_DELAY_RANGE                                0:0
`define    DS_MEM_EGR_SRC_PORT_P_DELAY_WIDTH                                1

// DsMemFlowColorStats
`define    DS_MEM_FLOW_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_FLOW_COLOR_STATS_WIDTH                                    0

// DsMemFlowPolice
`define    DS_MEM_FLOW_POLICE_RANGE                                         -1:0
`define    DS_MEM_FLOW_POLICE_WIDTH                                         0

// DsMemFlowPoliceCfg
`define    DS_MEM_FLOW_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_FLOW_POLICE_CFG_WIDTH                                     0

// DsMemHostRoute
`define    DS_MEM_HOST_ROUTE_RANGE                                          -1:0
`define    DS_MEM_HOST_ROUTE_WIDTH                                          0

// DsMemHostRouteLeft
`define    DS_MEM_HOST_ROUTE_LEFT_RANGE                                     -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_WIDTH                                     0

// DsMemHostRouteLeftKey
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_RANGE                                 -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_WIDTH                                 0

// DsMemHostRouteLeftValid
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_RANGE                               -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_WIDTH                               0

// DsMemHostRouteRight
`define    DS_MEM_HOST_ROUTE_RIGHT_RANGE                                    -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_WIDTH                                    0

// DsMemHostRouteRightKey
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_RANGE                                -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_WIDTH                                0

// DsMemHostRouteRightValid
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_RANGE                              -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_WIDTH                              0

// DsMemHostTsn
`define    DS_MEM_HOST_TSN_RANGE                                            -1:0
`define    DS_MEM_HOST_TSN_WIDTH                                            0

// DsMemHostTsnLeft
`define    DS_MEM_HOST_TSN_LEFT_RANGE                                       -1:0
`define    DS_MEM_HOST_TSN_LEFT_WIDTH                                       0

// DsMemHostTsnRight
`define    DS_MEM_HOST_TSN_RIGHT_RANGE                                      -1:0
`define    DS_MEM_HOST_TSN_RIGHT_WIDTH                                      0

// DsMemIndvRcvyCfg
`define    DS_MEM_INDV_RCVY_CFG_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CFG_WIDTH                                       0

// DsMemIndvRcvyCnt
`define    DS_MEM_INDV_RCVY_CNT_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CNT_WIDTH                                       0

// DsMemIndvRcvySeq
`define    DS_MEM_INDV_RCVY_SEQ_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_SEQ_WIDTH                                       0

// DsMemL3Mcast
`define    DS_MEM_L3_MCAST_RANGE                                            0:0
`define    DS_MEM_L3_MCAST_WIDTH                                            1

`define    DS_MEM_L3_MCAST_NEXTHOP_IDX_RANGE                                0:0
`define    DS_MEM_L3_MCAST_NEXTHOP_IDX_WIDTH                                1

// DsMemMacAgingLeft
`define    DS_MEM_MAC_AGING_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_AGING_LEFT_WIDTH                                      0

// DsMemMacAgingRight
`define    DS_MEM_MAC_AGING_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_AGING_RIGHT_WIDTH                                     0

// DsMemMacKeyLeft
`define    DS_MEM_MAC_KEY_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_KEY_LEFT_WIDTH                                        0

// DsMemMacKeyRight
`define    DS_MEM_MAC_KEY_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_KEY_RIGHT_WIDTH                                       0

// DsMemMacLeft
`define    DS_MEM_MAC_LEFT_RANGE                                            -1:0
`define    DS_MEM_MAC_LEFT_WIDTH                                            0

// DsMemMacRight
`define    DS_MEM_MAC_RIGHT_RANGE                                           -1:0
`define    DS_MEM_MAC_RIGHT_WIDTH                                           0

// DsMemMacStaticLeft
`define    DS_MEM_MAC_STATIC_LEFT_RANGE                                     -1:0
`define    DS_MEM_MAC_STATIC_LEFT_WIDTH                                     0

// DsMemMacStaticRight
`define    DS_MEM_MAC_STATIC_RIGHT_RANGE                                    -1:0
`define    DS_MEM_MAC_STATIC_RIGHT_WIDTH                                    0

// DsMemMacTsn
`define    DS_MEM_MAC_TSN_RANGE                                             -1:0
`define    DS_MEM_MAC_TSN_WIDTH                                             0

// DsMemMacTsnLeft
`define    DS_MEM_MAC_TSN_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_TSN_LEFT_WIDTH                                        0

// DsMemMacTsnRight
`define    DS_MEM_MAC_TSN_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_TSN_RIGHT_WIDTH                                       0

// DsMemMacValidLeft
`define    DS_MEM_MAC_VALID_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_VALID_LEFT_WIDTH                                      0

// DsMemMacValidRight
`define    DS_MEM_MAC_VALID_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_VALID_RIGHT_WIDTH                                     0

// DsMemNexthop
`define    DS_MEM_NEXTHOP_RANGE                                             5:0
`define    DS_MEM_NEXTHOP_WIDTH                                             6

`define    DS_MEM_NEXTHOP_VLAN_ID_RANGE                                     0:0
`define    DS_MEM_NEXTHOP_VLAN_ID_WIDTH                                     1

`define    DS_MEM_NEXTHOP_IP_SA_RANGE                                       1:1
`define    DS_MEM_NEXTHOP_IP_SA_WIDTH                                       1

`define    DS_MEM_NEXTHOP_L4_SRC_PORT_RANGE                                 2:2
`define    DS_MEM_NEXTHOP_L4_SRC_PORT_WIDTH                                 1

`define    DS_MEM_NEXTHOP_MAC_DA_HI_RANGE                                   3:3
`define    DS_MEM_NEXTHOP_MAC_DA_HI_WIDTH                                   1

`define    DS_MEM_NEXTHOP_MAC_DA_RANGE                                      4:4
`define    DS_MEM_NEXTHOP_MAC_DA_WIDTH                                      1

`define    DS_MEM_NEXTHOP_ROUTER_MAC_IDX_RANGE                              5:5
`define    DS_MEM_NEXTHOP_ROUTER_MAC_IDX_WIDTH                              1

// DsMemPortColorStats
`define    DS_MEM_PORT_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_PORT_COLOR_STATS_WIDTH                                    0

// DsMemPortPolice
`define    DS_MEM_PORT_POLICE_RANGE                                         -1:0
`define    DS_MEM_PORT_POLICE_WIDTH                                         0

// DsMemPortPoliceCfg
`define    DS_MEM_PORT_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_PORT_POLICE_CFG_WIDTH                                     0

// DsMemRouteTsn
`define    DS_MEM_ROUTE_TSN_RANGE                                           -1:0
`define    DS_MEM_ROUTE_TSN_WIDTH                                           0

// DsMemStreamRcvyCfg
`define    DS_MEM_STREAM_RCVY_CFG_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CFG_WIDTH                                     0

// DsMemStreamRcvyCnt
`define    DS_MEM_STREAM_RCVY_CNT_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CNT_WIDTH                                     0

// DsMemStreamRcvySeq
`define    DS_MEM_STREAM_RCVY_SEQ_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_SEQ_WIDTH                                     0

// DsRegEgrPriorMap
`define    DS_REG_EGR_PRIOR_MAP_RANGE                                       1:0
`define    DS_REG_EGR_PRIOR_MAP_WIDTH                                       2

`define    DS_REG_EGR_PRIOR_MAP_DSCP_RANGE                                  0:0
`define    DS_REG_EGR_PRIOR_MAP_DSCP_WIDTH                                  1

`define    DS_REG_EGR_PRIOR_MAP_COS_RANGE                                   1:1
`define    DS_REG_EGR_PRIOR_MAP_COS_WIDTH                                   1

// MsgAdmInfo0
`define    MSG_ADM_INFO0_RANGE                                              -1:0
`define    MSG_ADM_INFO0_WIDTH                                              0

// TmpDsMemMac
`define    TMP_DS_MEM_MAC_RANGE                                             -1:0
`define    TMP_DS_MEM_MAC_WIDTH                                             0

// CtlRcvy
`define    CTL_RCVY_RANGE                                                   5:0
`define    CTL_RCVY_WIDTH                                                   6

`define    CTL_RCVY_INDV_SEQ_RESET_EN_RANGE                                 0:0
`define    CTL_RCVY_INDV_SEQ_RESET_EN_WIDTH                                 1

`define    CTL_RCVY_INDV_DELAY_PER_ENTRY_RANGE                              1:1
`define    CTL_RCVY_INDV_DELAY_PER_ENTRY_WIDTH                              1

`define    CTL_RCVY_INDV_MINUS_CYCLE_RANGE                                  2:2
`define    CTL_RCVY_INDV_MINUS_CYCLE_WIDTH                                  1

`define    CTL_RCVY_MERGE_SEQ_RESET_EN_RANGE                                3:3
`define    CTL_RCVY_MERGE_SEQ_RESET_EN_WIDTH                                1

`define    CTL_RCVY_MERGE_DELAY_PER_ENTRY_RANGE                             4:4
`define    CTL_RCVY_MERGE_DELAY_PER_ENTRY_WIDTH                             1

`define    CTL_RCVY_MERGE_MINUS_CYCLE_RANGE                                 5:5
`define    CTL_RCVY_MERGE_MINUS_CYCLE_WIDTH                                 1

// CtlRcvyLog
`define    CTL_RCVY_LOG_RANGE                                               5:0
`define    CTL_RCVY_LOG_WIDTH                                               6

`define    CTL_RCVY_LOG_TSN_STREAM_ID_RANGE                                 0:0
`define    CTL_RCVY_LOG_TSN_STREAM_ID_WIDTH                                 1

`define    CTL_RCVY_LOG_RTAG_SEQ_RANGE                                      1:1
`define    CTL_RCVY_LOG_RTAG_SEQ_WIDTH                                      1

`define    CTL_RCVY_LOG_DISCARD_INDV_RANGE                                  2:2
`define    CTL_RCVY_LOG_DISCARD_INDV_WIDTH                                  1

`define    CTL_RCVY_LOG_SEQ_DELTA_INDV_RANGE                                3:3
`define    CTL_RCVY_LOG_SEQ_DELTA_INDV_WIDTH                                1

`define    CTL_RCVY_LOG_DISCARD_MERG_RANGE                                  4:4
`define    CTL_RCVY_LOG_DISCARD_MERG_WIDTH                                  1

`define    CTL_RCVY_LOG_SEQ_DELTA_MERG_RANGE                                5:5
`define    CTL_RCVY_LOG_SEQ_DELTA_MERG_WIDTH                                1

// DsMemAclTsn
`define    DS_MEM_ACL_TSN_RANGE                                             -1:0
`define    DS_MEM_ACL_TSN_WIDTH                                             0

// DsMemFlowColorStats
`define    DS_MEM_FLOW_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_FLOW_COLOR_STATS_WIDTH                                    0

// DsMemFlowPolice
`define    DS_MEM_FLOW_POLICE_RANGE                                         -1:0
`define    DS_MEM_FLOW_POLICE_WIDTH                                         0

// DsMemFlowPoliceCfg
`define    DS_MEM_FLOW_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_FLOW_POLICE_CFG_WIDTH                                     0

// DsMemHandle2StreamId
`define    DS_MEM_HANDLE2_STREAM_ID_RANGE                                   0:0
`define    DS_MEM_HANDLE2_STREAM_ID_WIDTH                                   1

`define    DS_MEM_HANDLE2_STREAM_ID_STREAM_ID_RANGE                         0:0
`define    DS_MEM_HANDLE2_STREAM_ID_STREAM_ID_WIDTH                         1

// DsMemHostRoute
`define    DS_MEM_HOST_ROUTE_RANGE                                          -1:0
`define    DS_MEM_HOST_ROUTE_WIDTH                                          0

// DsMemHostRouteLeft
`define    DS_MEM_HOST_ROUTE_LEFT_RANGE                                     -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_WIDTH                                     0

// DsMemHostRouteLeftKey
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_RANGE                                 -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_WIDTH                                 0

// DsMemHostRouteLeftValid
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_RANGE                               -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_WIDTH                               0

// DsMemHostRouteRight
`define    DS_MEM_HOST_ROUTE_RIGHT_RANGE                                    -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_WIDTH                                    0

// DsMemHostRouteRightKey
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_RANGE                                -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_WIDTH                                0

// DsMemHostRouteRightValid
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_RANGE                              -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_WIDTH                              0

// DsMemHostTsn
`define    DS_MEM_HOST_TSN_RANGE                                            -1:0
`define    DS_MEM_HOST_TSN_WIDTH                                            0

// DsMemHostTsnLeft
`define    DS_MEM_HOST_TSN_LEFT_RANGE                                       -1:0
`define    DS_MEM_HOST_TSN_LEFT_WIDTH                                       0

// DsMemHostTsnRight
`define    DS_MEM_HOST_TSN_RIGHT_RANGE                                      -1:0
`define    DS_MEM_HOST_TSN_RIGHT_WIDTH                                      0

// DsMemIndvRcvyCfg
`define    DS_MEM_INDV_RCVY_CFG_RANGE                                       0:0
`define    DS_MEM_INDV_RCVY_CFG_WIDTH                                       1

`define    DS_MEM_INDV_RCVY_CFG_FRER_RCVY_ALG_RANGE                         0:0
`define    DS_MEM_INDV_RCVY_CFG_FRER_RCVY_ALG_WIDTH                         1

// DsMemIndvRcvyCnt
`define    DS_MEM_INDV_RCVY_CNT_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CNT_WIDTH                                       0

// DsMemIndvRcvySeq
`define    DS_MEM_INDV_RCVY_SEQ_RANGE                                       1:0
`define    DS_MEM_INDV_RCVY_SEQ_WIDTH                                       2

`define    DS_MEM_INDV_RCVY_SEQ_TAKE_ANY_RANGE                              0:0
`define    DS_MEM_INDV_RCVY_SEQ_TAKE_ANY_WIDTH                              1

`define    DS_MEM_INDV_RCVY_SEQ_REMAIN_TICKS_RANGE                          1:1
`define    DS_MEM_INDV_RCVY_SEQ_REMAIN_TICKS_WIDTH                          1

// DsMemMacAgingLeft
`define    DS_MEM_MAC_AGING_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_AGING_LEFT_WIDTH                                      0

// DsMemMacAgingRight
`define    DS_MEM_MAC_AGING_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_AGING_RIGHT_WIDTH                                     0

// DsMemMacKeyLeft
`define    DS_MEM_MAC_KEY_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_KEY_LEFT_WIDTH                                        0

// DsMemMacKeyRight
`define    DS_MEM_MAC_KEY_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_KEY_RIGHT_WIDTH                                       0

// DsMemMacLeft
`define    DS_MEM_MAC_LEFT_RANGE                                            -1:0
`define    DS_MEM_MAC_LEFT_WIDTH                                            0

// DsMemMacRight
`define    DS_MEM_MAC_RIGHT_RANGE                                           -1:0
`define    DS_MEM_MAC_RIGHT_WIDTH                                           0

// DsMemMacStaticLeft
`define    DS_MEM_MAC_STATIC_LEFT_RANGE                                     -1:0
`define    DS_MEM_MAC_STATIC_LEFT_WIDTH                                     0

// DsMemMacStaticRight
`define    DS_MEM_MAC_STATIC_RIGHT_RANGE                                    -1:0
`define    DS_MEM_MAC_STATIC_RIGHT_WIDTH                                    0

// DsMemMacTsn
`define    DS_MEM_MAC_TSN_RANGE                                             -1:0
`define    DS_MEM_MAC_TSN_WIDTH                                             0

// DsMemMacTsnLeft
`define    DS_MEM_MAC_TSN_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_TSN_LEFT_WIDTH                                        0

// DsMemMacTsnRight
`define    DS_MEM_MAC_TSN_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_TSN_RIGHT_WIDTH                                       0

// DsMemMacValidLeft
`define    DS_MEM_MAC_VALID_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_VALID_LEFT_WIDTH                                      0

// DsMemMacValidRight
`define    DS_MEM_MAC_VALID_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_VALID_RIGHT_WIDTH                                     0

// DsMemPortColorStats
`define    DS_MEM_PORT_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_PORT_COLOR_STATS_WIDTH                                    0

// DsMemPortPolice
`define    DS_MEM_PORT_POLICE_RANGE                                         -1:0
`define    DS_MEM_PORT_POLICE_WIDTH                                         0

// DsMemPortPoliceCfg
`define    DS_MEM_PORT_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_PORT_POLICE_CFG_WIDTH                                     0

// DsMemRcvyCfg
`define    DS_MEM_RCVY_CFG_RANGE                                            4:0
`define    DS_MEM_RCVY_CFG_WIDTH                                            5

`define    DS_MEM_RCVY_CFG_RESET_TICKS_RANGE                                0:0
`define    DS_MEM_RCVY_CFG_RESET_TICKS_WIDTH                                1

`define    DS_MEM_RCVY_CFG_ILLEGAL_PKT_RESET_RANGE                          1:1
`define    DS_MEM_RCVY_CFG_ILLEGAL_PKT_RESET_WIDTH                          1

`define    DS_MEM_RCVY_CFG_FRER_ACCEPT_NO_SEQ_RANGE                         2:2
`define    DS_MEM_RCVY_CFG_FRER_ACCEPT_NO_SEQ_WIDTH                         1

`define    DS_MEM_RCVY_CFG_HISTORY_LEN_RANGE                                3:3
`define    DS_MEM_RCVY_CFG_HISTORY_LEN_WIDTH                                1

`define    DS_MEM_RCVY_CFG_FRER_RCVY_ALG_RANGE                              4:4
`define    DS_MEM_RCVY_CFG_FRER_RCVY_ALG_WIDTH                              1

// DsMemRcvyCnt
`define    DS_MEM_RCVY_CNT_RANGE                                            6:0
`define    DS_MEM_RCVY_CNT_WIDTH                                            7

`define    DS_MEM_RCVY_CNT_FLOW_TAGLESS_PKTS_RANGE                          0:0
`define    DS_MEM_RCVY_CNT_FLOW_TAGLESS_PKTS_WIDTH                          1

`define    DS_MEM_RCVY_CNT_FLOW_PASSED_PKTS_RANGE                           1:1
`define    DS_MEM_RCVY_CNT_FLOW_PASSED_PKTS_WIDTH                           1

`define    DS_MEM_RCVY_CNT_PORT_PASSED_PKTS_RANGE                           2:2
`define    DS_MEM_RCVY_CNT_PORT_PASSED_PKTS_WIDTH                           1

`define    DS_MEM_RCVY_CNT_FLOW_DISCARD_PKTS_RANGE                          3:3
`define    DS_MEM_RCVY_CNT_FLOW_DISCARD_PKTS_WIDTH                          1

`define    DS_MEM_RCVY_CNT_PORT_DISCARD_PKTS_RANGE                          4:4
`define    DS_MEM_RCVY_CNT_PORT_DISCARD_PKTS_WIDTH                          1

`define    DS_MEM_RCVY_CNT_FLOW_OUT_ORDER_CNT_RANGE                         5:5
`define    DS_MEM_RCVY_CNT_FLOW_OUT_ORDER_CNT_WIDTH                         1

`define    DS_MEM_RCVY_CNT_FLOW_ROGUE_PKTS_RANGE                            6:6
`define    DS_MEM_RCVY_CNT_FLOW_ROGUE_PKTS_WIDTH                            1

// DsMemRcvySeq
`define    DS_MEM_RCVY_SEQ_RANGE                                            4:0
`define    DS_MEM_RCVY_SEQ_WIDTH                                            5

`define    DS_MEM_RCVY_SEQ_RCVY_SEQ_RANGE                                   0:0
`define    DS_MEM_RCVY_SEQ_RCVY_SEQ_WIDTH                                   1

`define    DS_MEM_RCVY_SEQ_TAKE_ANY_RANGE                                   1:1
`define    DS_MEM_RCVY_SEQ_TAKE_ANY_WIDTH                                   1

`define    DS_MEM_RCVY_SEQ_REMAIN_TICKS_RANGE                               2:2
`define    DS_MEM_RCVY_SEQ_REMAIN_TICKS_WIDTH                               1

`define    DS_MEM_RCVY_SEQ_SEQ_HISTORY_RANGE                                3:3
`define    DS_MEM_RCVY_SEQ_SEQ_HISTORY_WIDTH                                1

`define    DS_MEM_RCVY_SEQ_RCVY_RESET_CNT_RANGE                             4:4
`define    DS_MEM_RCVY_SEQ_RCVY_RESET_CNT_WIDTH                             1

// DsMemRouteTsn
`define    DS_MEM_ROUTE_TSN_RANGE                                           -1:0
`define    DS_MEM_ROUTE_TSN_WIDTH                                           0

// DsMemStreamRcvyCfg
`define    DS_MEM_STREAM_RCVY_CFG_RANGE                                     1:0
`define    DS_MEM_STREAM_RCVY_CFG_WIDTH                                     2

`define    DS_MEM_STREAM_RCVY_CFG_REDUNDANCY_PATHS_RANGE                    0:0
`define    DS_MEM_STREAM_RCVY_CFG_REDUNDANCY_PATHS_WIDTH                    1

`define    DS_MEM_STREAM_RCVY_CFG_FRER_RCVY_ALG_RANGE                       1:1
`define    DS_MEM_STREAM_RCVY_CFG_FRER_RCVY_ALG_WIDTH                       1

// DsMemStreamRcvyCnt
`define    DS_MEM_STREAM_RCVY_CNT_RANGE                                     1:0
`define    DS_MEM_STREAM_RCVY_CNT_WIDTH                                     2

`define    DS_MEM_STREAM_RCVY_CNT_FLOW_PASSED_PKTS_RANGE                    0:0
`define    DS_MEM_STREAM_RCVY_CNT_FLOW_PASSED_PKTS_WIDTH                    1

`define    DS_MEM_STREAM_RCVY_CNT_FLOW_DISCARD_PKTS_RANGE                   1:1
`define    DS_MEM_STREAM_RCVY_CNT_FLOW_DISCARD_PKTS_WIDTH                   1

// DsMemStreamRcvySeq
`define    DS_MEM_STREAM_RCVY_SEQ_RANGE                                     2:0
`define    DS_MEM_STREAM_RCVY_SEQ_WIDTH                                     3

`define    DS_MEM_STREAM_RCVY_SEQ_LATENT_ERROR_RESET_CNT_RANGE              0:0
`define    DS_MEM_STREAM_RCVY_SEQ_LATENT_ERROR_RESET_CNT_WIDTH              1

`define    DS_MEM_STREAM_RCVY_SEQ_TAKE_ANY_RANGE                            1:1
`define    DS_MEM_STREAM_RCVY_SEQ_TAKE_ANY_WIDTH                            1

`define    DS_MEM_STREAM_RCVY_SEQ_REMAIN_TICKS_RANGE                        2:2
`define    DS_MEM_STREAM_RCVY_SEQ_REMAIN_TICKS_WIDTH                        1

// MsgAdmInfo0
`define    MSG_ADM_INFO0_RANGE                                              -1:0
`define    MSG_ADM_INFO0_WIDTH                                              0

// TmpDsMemMac
`define    TMP_DS_MEM_MAC_RANGE                                             -1:0
`define    TMP_DS_MEM_MAC_WIDTH                                             0

// CtlCpuPolice
`define    CTL_CPU_POLICE_RANGE                                             1:0
`define    CTL_CPU_POLICE_WIDTH                                             2

`define    CTL_CPU_POLICE_POLICE_EN_RANGE                                   0:0
`define    CTL_CPU_POLICE_POLICE_EN_WIDTH                                   1

`define    CTL_CPU_POLICE_POLICE_PTR_BASE_RANGE                             1:1
`define    CTL_CPU_POLICE_POLICE_PTR_BASE_WIDTH                             1

// CtlPolice
`define    CTL_POLICE_RANGE                                                 22:0
`define    CTL_POLICE_WIDTH                                                 23

`define    CTL_POLICE_FLOW_POLICE_FIRST_RANGE                               0:0
`define    CTL_POLICE_FLOW_POLICE_FIRST_WIDTH                               1

`define    CTL_POLICE_SEQUENTIAL_POLICING_RANGE                             1:1
`define    CTL_POLICE_SEQUENTIAL_POLICING_WIDTH                             1

`define    CTL_POLICE_FLOW_STATS_EN_RANGE                                   2:2
`define    CTL_POLICE_FLOW_STATS_EN_WIDTH                                   1

`define    CTL_POLICE_FLOW_STATS_BASE_RANGE                                 3:3
`define    CTL_POLICE_FLOW_STATS_BASE_WIDTH                                 1

`define    CTL_POLICE_PORT_STATS_EN_RANGE                                   4:4
`define    CTL_POLICE_PORT_STATS_EN_WIDTH                                   1

`define    CTL_POLICE_PORT_STATS_BASE_RANGE                                 5:5
`define    CTL_POLICE_PORT_STATS_BASE_WIDTH                                 1

`define    CTL_POLICE_UPDATE_EN_RANGE                                       6:6
`define    CTL_POLICE_UPDATE_EN_WIDTH                                       1

`define    CTL_POLICE_PORT_CUR_PTR_RANGE                                    7:7
`define    CTL_POLICE_PORT_CUR_PTR_WIDTH                                    1

`define    CTL_POLICE_PORT_UPDATE_INTV_RANGE                                8:8
`define    CTL_POLICE_PORT_UPDATE_INTV_WIDTH                                1

`define    CTL_POLICE_PORT_MAX_PTR_RANGE                                    9:9
`define    CTL_POLICE_PORT_MAX_PTR_WIDTH                                    1

`define    CTL_POLICE_PORT_MIN_PTR_RANGE                                    10:10
`define    CTL_POLICE_PORT_MIN_PTR_WIDTH                                    1

`define    CTL_POLICE_PORT_PER_RND_DELAY_RANGE                              11:11
`define    CTL_POLICE_PORT_PER_RND_DELAY_WIDTH                              1

`define    CTL_POLICE_PORT_CUR_ROUND_RANGE                                  12:12
`define    CTL_POLICE_PORT_CUR_ROUND_WIDTH                                  1

`define    CTL_POLICE_PORT_UPD_ROUND_RANGE                                  13:13
`define    CTL_POLICE_PORT_UPD_ROUND_WIDTH                                  1

`define    CTL_POLICE_PORT_FINAL_DELAY_RANGE                                14:14
`define    CTL_POLICE_PORT_FINAL_DELAY_WIDTH                                1

`define    CTL_POLICE_FLOW_CUR_PTR_RANGE                                    15:15
`define    CTL_POLICE_FLOW_CUR_PTR_WIDTH                                    1

`define    CTL_POLICE_FLOW_UPDATE_INTV_RANGE                                16:16
`define    CTL_POLICE_FLOW_UPDATE_INTV_WIDTH                                1

`define    CTL_POLICE_FLOW_MAX_PTR_RANGE                                    17:17
`define    CTL_POLICE_FLOW_MAX_PTR_WIDTH                                    1

`define    CTL_POLICE_FLOW_MIN_PTR_RANGE                                    18:18
`define    CTL_POLICE_FLOW_MIN_PTR_WIDTH                                    1

`define    CTL_POLICE_FLOW_PER_RND_DELAY_RANGE                              19:19
`define    CTL_POLICE_FLOW_PER_RND_DELAY_WIDTH                              1

`define    CTL_POLICE_FLOW_CUR_ROUND_RANGE                                  20:20
`define    CTL_POLICE_FLOW_CUR_ROUND_WIDTH                                  1

`define    CTL_POLICE_FLOW_UPD_ROUND_RANGE                                  21:21
`define    CTL_POLICE_FLOW_UPD_ROUND_WIDTH                                  1

`define    CTL_POLICE_FLOW_FINAL_DELAY_RANGE                                22:22
`define    CTL_POLICE_FLOW_FINAL_DELAY_WIDTH                                1

// CtlPoliceLog
`define    CTL_POLICE_LOG_RANGE                                             7:0
`define    CTL_POLICE_LOG_WIDTH                                             8

`define    CTL_POLICE_LOG_POLICE_DROP_RANGE                                 0:0
`define    CTL_POLICE_LOG_POLICE_DROP_WIDTH                                 1

`define    CTL_POLICE_LOG_DROP_PKT_CNT_RANGE                                1:1
`define    CTL_POLICE_LOG_DROP_PKT_CNT_WIDTH                                1

`define    CTL_POLICE_LOG_PORT_PO_EN_RANGE                                  2:2
`define    CTL_POLICE_LOG_PORT_PO_EN_WIDTH                                  1

`define    CTL_POLICE_LOG_FLOW_PO_EN_RANGE                                  3:3
`define    CTL_POLICE_LOG_FLOW_PO_EN_WIDTH                                  1

`define    CTL_POLICE_LOG_PORT_PO_PTR_RANGE                                 4:4
`define    CTL_POLICE_LOG_PORT_PO_PTR_WIDTH                                 1

`define    CTL_POLICE_LOG_FLOW_PO_PTR_RANGE                                 5:5
`define    CTL_POLICE_LOG_FLOW_PO_PTR_WIDTH                                 1

`define    CTL_POLICE_LOG_CHK_SDUFAILED_RANGE                               6:6
`define    CTL_POLICE_LOG_CHK_SDUFAILED_WIDTH                               1

`define    CTL_POLICE_LOG_NEW_COLOR_RANGE                                   7:7
`define    CTL_POLICE_LOG_NEW_COLOR_WIDTH                                   1

// DsMemAclTsn
`define    DS_MEM_ACL_TSN_RANGE                                             -1:0
`define    DS_MEM_ACL_TSN_WIDTH                                             0

// DsMemColorStats
`define    DS_MEM_COLOR_STATS_RANGE                                         2:0
`define    DS_MEM_COLOR_STATS_WIDTH                                         3

`define    DS_MEM_COLOR_STATS_PKT_CNT_RANGE                                 0:0
`define    DS_MEM_COLOR_STATS_PKT_CNT_WIDTH                                 1

`define    DS_MEM_COLOR_STATS_BYTE_CNT_HI_RANGE                             1:1
`define    DS_MEM_COLOR_STATS_BYTE_CNT_HI_WIDTH                             1

`define    DS_MEM_COLOR_STATS_BYTE_CNT_LO_RANGE                             2:2
`define    DS_MEM_COLOR_STATS_BYTE_CNT_LO_WIDTH                             1

// DsMemCpuPolicePtrMap
`define    DS_MEM_CPU_POLICE_PTR_MAP_RANGE                                  0:0
`define    DS_MEM_CPU_POLICE_PTR_MAP_WIDTH                                  1

`define    DS_MEM_CPU_POLICE_PTR_MAP_POLICE_PTR_RANGE                       0:0
`define    DS_MEM_CPU_POLICE_PTR_MAP_POLICE_PTR_WIDTH                       1

// DsMemFlowColorStats
`define    DS_MEM_FLOW_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_FLOW_COLOR_STATS_WIDTH                                    0

// DsMemFlowPolice
`define    DS_MEM_FLOW_POLICE_RANGE                                         -1:0
`define    DS_MEM_FLOW_POLICE_WIDTH                                         0

// DsMemFlowPoliceCfg
`define    DS_MEM_FLOW_POLICE_CFG_RANGE                                     1:0
`define    DS_MEM_FLOW_POLICE_CFG_WIDTH                                     2

`define    DS_MEM_FLOW_POLICE_CFG_DROP_YELLOW_RANGE                         0:0
`define    DS_MEM_FLOW_POLICE_CFG_DROP_YELLOW_WIDTH                         1

`define    DS_MEM_FLOW_POLICE_CFG_MARK_ALL_RED_RANGE                        1:1
`define    DS_MEM_FLOW_POLICE_CFG_MARK_ALL_RED_WIDTH                        1

// DsMemHostRoute
`define    DS_MEM_HOST_ROUTE_RANGE                                          -1:0
`define    DS_MEM_HOST_ROUTE_WIDTH                                          0

// DsMemHostRouteLeft
`define    DS_MEM_HOST_ROUTE_LEFT_RANGE                                     -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_WIDTH                                     0

// DsMemHostRouteLeftKey
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_RANGE                                 -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_WIDTH                                 0

// DsMemHostRouteLeftValid
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_RANGE                               -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_WIDTH                               0

// DsMemHostRouteRight
`define    DS_MEM_HOST_ROUTE_RIGHT_RANGE                                    -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_WIDTH                                    0

// DsMemHostRouteRightKey
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_RANGE                                -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_WIDTH                                0

// DsMemHostRouteRightValid
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_RANGE                              -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_WIDTH                              0

// DsMemHostTsn
`define    DS_MEM_HOST_TSN_RANGE                                            -1:0
`define    DS_MEM_HOST_TSN_WIDTH                                            0

// DsMemHostTsnLeft
`define    DS_MEM_HOST_TSN_LEFT_RANGE                                       -1:0
`define    DS_MEM_HOST_TSN_LEFT_WIDTH                                       0

// DsMemHostTsnRight
`define    DS_MEM_HOST_TSN_RIGHT_RANGE                                      -1:0
`define    DS_MEM_HOST_TSN_RIGHT_WIDTH                                      0

// DsMemIndvRcvyCfg
`define    DS_MEM_INDV_RCVY_CFG_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CFG_WIDTH                                       0

// DsMemIndvRcvyCnt
`define    DS_MEM_INDV_RCVY_CNT_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CNT_WIDTH                                       0

// DsMemIndvRcvySeq
`define    DS_MEM_INDV_RCVY_SEQ_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_SEQ_WIDTH                                       0

// DsMemMacAgingLeft
`define    DS_MEM_MAC_AGING_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_AGING_LEFT_WIDTH                                      0

// DsMemMacAgingRight
`define    DS_MEM_MAC_AGING_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_AGING_RIGHT_WIDTH                                     0

// DsMemMacKeyLeft
`define    DS_MEM_MAC_KEY_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_KEY_LEFT_WIDTH                                        0

// DsMemMacKeyRight
`define    DS_MEM_MAC_KEY_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_KEY_RIGHT_WIDTH                                       0

// DsMemMacLeft
`define    DS_MEM_MAC_LEFT_RANGE                                            -1:0
`define    DS_MEM_MAC_LEFT_WIDTH                                            0

// DsMemMacRight
`define    DS_MEM_MAC_RIGHT_RANGE                                           -1:0
`define    DS_MEM_MAC_RIGHT_WIDTH                                           0

// DsMemMacStaticLeft
`define    DS_MEM_MAC_STATIC_LEFT_RANGE                                     -1:0
`define    DS_MEM_MAC_STATIC_LEFT_WIDTH                                     0

// DsMemMacStaticRight
`define    DS_MEM_MAC_STATIC_RIGHT_RANGE                                    -1:0
`define    DS_MEM_MAC_STATIC_RIGHT_WIDTH                                    0

// DsMemMacTsn
`define    DS_MEM_MAC_TSN_RANGE                                             -1:0
`define    DS_MEM_MAC_TSN_WIDTH                                             0

// DsMemMacTsnLeft
`define    DS_MEM_MAC_TSN_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_TSN_LEFT_WIDTH                                        0

// DsMemMacTsnRight
`define    DS_MEM_MAC_TSN_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_TSN_RIGHT_WIDTH                                       0

// DsMemMacValidLeft
`define    DS_MEM_MAC_VALID_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_VALID_LEFT_WIDTH                                      0

// DsMemMacValidRight
`define    DS_MEM_MAC_VALID_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_VALID_RIGHT_WIDTH                                     0

// DsMemPolice
`define    DS_MEM_POLICE_RANGE                                              1:0
`define    DS_MEM_POLICE_WIDTH                                              2

`define    DS_MEM_POLICE_COMMIT_COUNT_RANGE                                 0:0
`define    DS_MEM_POLICE_COMMIT_COUNT_WIDTH                                 1

`define    DS_MEM_POLICE_PEAK_COUNT_RANGE                                   1:1
`define    DS_MEM_POLICE_PEAK_COUNT_WIDTH                                   1

// DsMemPoliceCfg
`define    DS_MEM_POLICE_CFG_RANGE                                          7:0
`define    DS_MEM_POLICE_CFG_WIDTH                                          8

`define    DS_MEM_POLICE_CFG_SR_TCM_MODE_RANGE                              0:0
`define    DS_MEM_POLICE_CFG_SR_TCM_MODE_WIDTH                              1

`define    DS_MEM_POLICE_CFG_COLOR_BLIND_MODE_RANGE                         1:1
`define    DS_MEM_POLICE_CFG_COLOR_BLIND_MODE_WIDTH                         1

`define    DS_MEM_POLICE_CFG_COLOR_DROP_CODE_RANGE                          2:2
`define    DS_MEM_POLICE_CFG_COLOR_DROP_CODE_WIDTH                          1

`define    DS_MEM_POLICE_CFG_CBS_BYTE_RANGE                                 3:3
`define    DS_MEM_POLICE_CFG_CBS_BYTE_WIDTH                                 1

`define    DS_MEM_POLICE_CFG_PBS_BYTE_RANGE                                 4:4
`define    DS_MEM_POLICE_CFG_PBS_BYTE_WIDTH                                 1

`define    DS_MEM_POLICE_CFG_UPDATE_EN_RANGE                                5:5
`define    DS_MEM_POLICE_CFG_UPDATE_EN_WIDTH                                1

`define    DS_MEM_POLICE_CFG_CIR_BPS_RANGE                                  6:6
`define    DS_MEM_POLICE_CFG_CIR_BPS_WIDTH                                  1

`define    DS_MEM_POLICE_CFG_PIR_BPS_RANGE                                  7:7
`define    DS_MEM_POLICE_CFG_PIR_BPS_WIDTH                                  1

// DsMemPortColorStats
`define    DS_MEM_PORT_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_PORT_COLOR_STATS_WIDTH                                    0

// DsMemPortPolice
`define    DS_MEM_PORT_POLICE_RANGE                                         -1:0
`define    DS_MEM_PORT_POLICE_WIDTH                                         0

// DsMemPortPoliceCfg
`define    DS_MEM_PORT_POLICE_CFG_RANGE                                     1:0
`define    DS_MEM_PORT_POLICE_CFG_WIDTH                                     2

`define    DS_MEM_PORT_POLICE_CFG_DROP_YELLOW_RANGE                         0:0
`define    DS_MEM_PORT_POLICE_CFG_DROP_YELLOW_WIDTH                         1

`define    DS_MEM_PORT_POLICE_CFG_MARK_ALL_RED_RANGE                        1:1
`define    DS_MEM_PORT_POLICE_CFG_MARK_ALL_RED_WIDTH                        1

// DsMemRouteTsn
`define    DS_MEM_ROUTE_TSN_RANGE                                           -1:0
`define    DS_MEM_ROUTE_TSN_WIDTH                                           0

// DsMemStreamRcvyCfg
`define    DS_MEM_STREAM_RCVY_CFG_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CFG_WIDTH                                     0

// DsMemStreamRcvyCnt
`define    DS_MEM_STREAM_RCVY_CNT_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CNT_WIDTH                                     0

// DsMemStreamRcvySeq
`define    DS_MEM_STREAM_RCVY_SEQ_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_SEQ_WIDTH                                     0

// DsMemTsnPolice
`define    DS_MEM_TSN_POLICE_RANGE                                          2:0
`define    DS_MEM_TSN_POLICE_WIDTH                                          3

`define    DS_MEM_TSN_POLICE_POLICE_INDEX_RANGE                             0:0
`define    DS_MEM_TSN_POLICE_POLICE_INDEX_WIDTH                             1

`define    DS_MEM_TSN_POLICE_CHK_SDUEN_RANGE                                1:1
`define    DS_MEM_TSN_POLICE_CHK_SDUEN_WIDTH                                1

`define    DS_MEM_TSN_POLICE_MAX_SDU_RANGE                                  2:2
`define    DS_MEM_TSN_POLICE_MAX_SDU_WIDTH                                  1

// MsgAdmInfo0
`define    MSG_ADM_INFO0_RANGE                                              -1:0
`define    MSG_ADM_INFO0_WIDTH                                              0

// TmpDsMemMac
`define    TMP_DS_MEM_MAC_RANGE                                             -1:0
`define    TMP_DS_MEM_MAC_WIDTH                                             0

// CtlAdmLog
`define    CTL_ADM_LOG_RANGE                                                4:0
`define    CTL_ADM_LOG_WIDTH                                                5

`define    CTL_ADM_LOG_ENQ_IPV_RANGE                                        0:0
`define    CTL_ADM_LOG_ENQ_IPV_WIDTH                                        1

`define    CTL_ADM_LOG_GATE_STATE_RANGE                                     1:1
`define    CTL_ADM_LOG_GATE_STATE_WIDTH                                     1

`define    CTL_ADM_LOG_GATE_CLOSE_CNT_RANGE                                 2:2
`define    CTL_ADM_LOG_GATE_CLOSE_CNT_WIDTH                                 1

`define    CTL_ADM_LOG_TAIL_DROP_CNT_RANGE                                  3:3
`define    CTL_ADM_LOG_TAIL_DROP_CNT_WIDTH                                  1

`define    CTL_ADM_LOG_WRED_CNT_RANGE                                       4:4
`define    CTL_ADM_LOG_WRED_CNT_WIDTH                                       1

// CtlCommon
`define    CTL_COMMON_RANGE                                                 0:0
`define    CTL_COMMON_WIDTH                                                 1

`define    CTL_COMMON_CPU_PORT_NO_RANGE                                     0:0
`define    CTL_COMMON_CPU_PORT_NO_WIDTH                                     1

// CtlEnqCfg
`define    CTL_ENQ_CFG_RANGE                                                3:0
`define    CTL_ENQ_CFG_WIDTH                                                4

`define    CTL_ENQ_CFG_TSN_EN_RANGE                                         0:0
`define    CTL_ENQ_CFG_TSN_EN_WIDTH                                         1

`define    CTL_ENQ_CFG_GATE_ONLY_RANGE                                      1:1
`define    CTL_ENQ_CFG_GATE_ONLY_WIDTH                                      1

`define    CTL_ENQ_CFG_IPV_RANGE                                            2:2
`define    CTL_ENQ_CFG_IPV_WIDTH                                            1

`define    CTL_ENQ_CFG_ENQ_EN_BMP_RANGE                                     3:3
`define    CTL_ENQ_CFG_ENQ_EN_BMP_WIDTH                                     1

// CtlPtpTimerEn
`define    CTL_PTP_TIMER_EN_RANGE                                           0:0
`define    CTL_PTP_TIMER_EN_WIDTH                                           1

`define    CTL_PTP_TIMER_EN_ENABLE_RANGE                                    0:0
`define    CTL_PTP_TIMER_EN_ENABLE_WIDTH                                    1

// CtlRepExtPort
`define    CTL_REP_EXT_PORT_RANGE                                           0:0
`define    CTL_REP_EXT_PORT_WIDTH                                           1

`define    CTL_REP_EXT_PORT_DEST_PORT_RANGE                                 0:0
`define    CTL_REP_EXT_PORT_DEST_PORT_WIDTH                                 1

// DsMemAclTsn
`define    DS_MEM_ACL_TSN_RANGE                                             -1:0
`define    DS_MEM_ACL_TSN_WIDTH                                             0

// DsMemFlowColorStats
`define    DS_MEM_FLOW_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_FLOW_COLOR_STATS_WIDTH                                    0

// DsMemFlowPolice
`define    DS_MEM_FLOW_POLICE_RANGE                                         -1:0
`define    DS_MEM_FLOW_POLICE_WIDTH                                         0

// DsMemFlowPoliceCfg
`define    DS_MEM_FLOW_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_FLOW_POLICE_CFG_WIDTH                                     0

// DsMemHostRoute
`define    DS_MEM_HOST_ROUTE_RANGE                                          -1:0
`define    DS_MEM_HOST_ROUTE_WIDTH                                          0

// DsMemHostRouteLeft
`define    DS_MEM_HOST_ROUTE_LEFT_RANGE                                     -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_WIDTH                                     0

// DsMemHostRouteLeftKey
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_RANGE                                 -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_WIDTH                                 0

// DsMemHostRouteLeftValid
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_RANGE                               -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_WIDTH                               0

// DsMemHostRouteRight
`define    DS_MEM_HOST_ROUTE_RIGHT_RANGE                                    -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_WIDTH                                    0

// DsMemHostRouteRightKey
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_RANGE                                -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_WIDTH                                0

// DsMemHostRouteRightValid
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_RANGE                              -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_WIDTH                              0

// DsMemHostTsn
`define    DS_MEM_HOST_TSN_RANGE                                            -1:0
`define    DS_MEM_HOST_TSN_WIDTH                                            0

// DsMemHostTsnLeft
`define    DS_MEM_HOST_TSN_LEFT_RANGE                                       -1:0
`define    DS_MEM_HOST_TSN_LEFT_WIDTH                                       0

// DsMemHostTsnRight
`define    DS_MEM_HOST_TSN_RIGHT_RANGE                                      -1:0
`define    DS_MEM_HOST_TSN_RIGHT_WIDTH                                      0

// DsMemIndvRcvyCfg
`define    DS_MEM_INDV_RCVY_CFG_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CFG_WIDTH                                       0

// DsMemIndvRcvyCnt
`define    DS_MEM_INDV_RCVY_CNT_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CNT_WIDTH                                       0

// DsMemIndvRcvySeq
`define    DS_MEM_INDV_RCVY_SEQ_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_SEQ_WIDTH                                       0

// DsMemMacAgingLeft
`define    DS_MEM_MAC_AGING_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_AGING_LEFT_WIDTH                                      0

// DsMemMacAgingRight
`define    DS_MEM_MAC_AGING_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_AGING_RIGHT_WIDTH                                     0

// DsMemMacKeyLeft
`define    DS_MEM_MAC_KEY_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_KEY_LEFT_WIDTH                                        0

// DsMemMacKeyRight
`define    DS_MEM_MAC_KEY_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_KEY_RIGHT_WIDTH                                       0

// DsMemMacLeft
`define    DS_MEM_MAC_LEFT_RANGE                                            -1:0
`define    DS_MEM_MAC_LEFT_WIDTH                                            0

// DsMemMacRight
`define    DS_MEM_MAC_RIGHT_RANGE                                           -1:0
`define    DS_MEM_MAC_RIGHT_WIDTH                                           0

// DsMemMacStaticLeft
`define    DS_MEM_MAC_STATIC_LEFT_RANGE                                     -1:0
`define    DS_MEM_MAC_STATIC_LEFT_WIDTH                                     0

// DsMemMacStaticRight
`define    DS_MEM_MAC_STATIC_RIGHT_RANGE                                    -1:0
`define    DS_MEM_MAC_STATIC_RIGHT_WIDTH                                    0

// DsMemMacTsn
`define    DS_MEM_MAC_TSN_RANGE                                             -1:0
`define    DS_MEM_MAC_TSN_WIDTH                                             0

// DsMemMacTsnLeft
`define    DS_MEM_MAC_TSN_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_TSN_LEFT_WIDTH                                        0

// DsMemMacTsnRight
`define    DS_MEM_MAC_TSN_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_TSN_RIGHT_WIDTH                                       0

// DsMemMacValidLeft
`define    DS_MEM_MAC_VALID_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_VALID_LEFT_WIDTH                                      0

// DsMemMacValidRight
`define    DS_MEM_MAC_VALID_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_VALID_RIGHT_WIDTH                                     0

// DsMemPortColorStats
`define    DS_MEM_PORT_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_PORT_COLOR_STATS_WIDTH                                    0

// DsMemPortPolice
`define    DS_MEM_PORT_POLICE_RANGE                                         -1:0
`define    DS_MEM_PORT_POLICE_WIDTH                                         0

// DsMemPortPoliceCfg
`define    DS_MEM_PORT_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_PORT_POLICE_CFG_WIDTH                                     0

// DsMemRouteTsn
`define    DS_MEM_ROUTE_TSN_RANGE                                           -1:0
`define    DS_MEM_ROUTE_TSN_WIDTH                                           0

// DsMemStreamRcvyCfg
`define    DS_MEM_STREAM_RCVY_CFG_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CFG_WIDTH                                     0

// DsMemStreamRcvyCnt
`define    DS_MEM_STREAM_RCVY_CNT_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CNT_WIDTH                                     0

// DsMemStreamRcvySeq
`define    DS_MEM_STREAM_RCVY_SEQ_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_SEQ_WIDTH                                     0

// DsMemTsnGate
`define    DS_MEM_TSN_GATE_RANGE                                            3:0
`define    DS_MEM_TSN_GATE_WIDTH                                            4

`define    DS_MEM_TSN_GATE_STATE0_RANGE                                     0:0
`define    DS_MEM_TSN_GATE_STATE0_WIDTH                                     1

`define    DS_MEM_TSN_GATE_IPV0_RANGE                                       1:1
`define    DS_MEM_TSN_GATE_IPV0_WIDTH                                       1

`define    DS_MEM_TSN_GATE_STATE1_RANGE                                     2:2
`define    DS_MEM_TSN_GATE_STATE1_WIDTH                                     1

`define    DS_MEM_TSN_GATE_IPV1_RANGE                                       3:3
`define    DS_MEM_TSN_GATE_IPV1_WIDTH                                       1

// DsRegCpuPktPrior
`define    DS_REG_CPU_PKT_PRIOR_RANGE                                       0:0
`define    DS_REG_CPU_PKT_PRIOR_WIDTH                                       1

`define    DS_REG_CPU_PKT_PRIOR_PRIOR_RANGE                                 0:0
`define    DS_REG_CPU_PKT_PRIOR_PRIOR_WIDTH                                 1

// DsRegPtpTimer
`define    DS_REG_PTP_TIMER_RANGE                                           0:0
`define    DS_REG_PTP_TIMER_WIDTH                                           1

`define    DS_REG_PTP_TIMER_VALUE_RANGE                                     0:0
`define    DS_REG_PTP_TIMER_VALUE_WIDTH                                     1

// DsRegQueueDrop
`define    DS_REG_QUEUE_DROP_RANGE                                          1:0
`define    DS_REG_QUEUE_DROP_WIDTH                                          2

`define    DS_REG_QUEUE_DROP_TAIL_DROP_SET_RANGE                            0:0
`define    DS_REG_QUEUE_DROP_TAIL_DROP_SET_WIDTH                            1

`define    DS_REG_QUEUE_DROP_WRED_SET_RANGE                                 1:1
`define    DS_REG_QUEUE_DROP_WRED_SET_WIDTH                                 1

// MsgAdmInfo0
`define    MSG_ADM_INFO0_RANGE                                              -1:0
`define    MSG_ADM_INFO0_WIDTH                                              0

// TmpDsMemMac
`define    TMP_DS_MEM_MAC_RANGE                                             -1:0
`define    TMP_DS_MEM_MAC_WIDTH                                             0

// CtlCommon
`define    CTL_COMMON_RANGE                                                 0:0
`define    CTL_COMMON_WIDTH                                                 1

`define    CTL_COMMON_CPU_PORT_NO_RANGE                                     0:0
`define    CTL_COMMON_CPU_PORT_NO_WIDTH                                     1

// CtlCpuStats
`define    CTL_CPU_STATS_RANGE                                              0:0
`define    CTL_CPU_STATS_WIDTH                                              1

`define    CTL_CPU_STATS_STATS_EN_RANGE                                     0:0
`define    CTL_CPU_STATS_STATS_EN_WIDTH                                     1

// CtlFwdDest
`define    CTL_FWD_DEST_RANGE                                               1:0
`define    CTL_FWD_DEST_WIDTH                                               2

`define    CTL_FWD_DEST_REDIR_PTP_TYPE_RANGE                                0:0
`define    CTL_FWD_DEST_REDIR_PTP_TYPE_WIDTH                                1

`define    CTL_FWD_DEST_PTP_SNIFFER_TYPE_RANGE                              1:1
`define    CTL_FWD_DEST_PTP_SNIFFER_TYPE_WIDTH                              1

// CtlFwdEgressFilter
`define    CTL_FWD_EGRESS_FILTER_RANGE                                      0:0
`define    CTL_FWD_EGRESS_FILTER_WIDTH                                      1

`define    CTL_FWD_EGRESS_FILTER_EGR_FILTERING_EN_RANGE                     0:0
`define    CTL_FWD_EGRESS_FILTER_EGR_FILTERING_EN_WIDTH                     1

// CtlFwdEgressSpan
`define    CTL_FWD_EGRESS_SPAN_RANGE                                        0:0
`define    CTL_FWD_EGRESS_SPAN_WIDTH                                        1

`define    CTL_FWD_EGRESS_SPAN_L2_EGR_SPAN_EN_RANGE                         0:0
`define    CTL_FWD_EGRESS_SPAN_L2_EGR_SPAN_EN_WIDTH                         1

// CtlFwdExcp
`define    CTL_FWD_EXCP_RANGE                                               0:0
`define    CTL_FWD_EXCP_WIDTH                                               1

`define    CTL_FWD_EXCP_EXCEP_TO_CPU_RANGE                                  0:0
`define    CTL_FWD_EXCP_EXCEP_TO_CPU_WIDTH                                  1

// CtlFwdLog
`define    CTL_FWD_LOG_RANGE                                                19:0
`define    CTL_FWD_LOG_WIDTH                                                20

`define    CTL_FWD_LOG_FWD_BITMAP_RANGE                                     0:0
`define    CTL_FWD_LOG_FWD_BITMAP_WIDTH                                     1

`define    CTL_FWD_LOG_FWD_BITMAP_W1_RANGE                                  1:1
`define    CTL_FWD_LOG_FWD_BITMAP_W1_WIDTH                                  1

`define    CTL_FWD_LOG_VLAN_DISCARD_RANGE                                   2:2
`define    CTL_FWD_LOG_VLAN_DISCARD_WIDTH                                   1

`define    CTL_FWD_LOG_MCAST_FLOOD_RANGE                                    3:3
`define    CTL_FWD_LOG_MCAST_FLOOD_WIDTH                                    1

`define    CTL_FWD_LOG_DEST_MAP_RANGE                                       4:4
`define    CTL_FWD_LOG_DEST_MAP_WIDTH                                       1

`define    CTL_FWD_LOG_OP_CODE_RANGE                                        5:5
`define    CTL_FWD_LOG_OP_CODE_WIDTH                                        1

`define    CTL_FWD_LOG_UCAST_FLOOD_RANGE                                    6:6
`define    CTL_FWD_LOG_UCAST_FLOOD_WIDTH                                    1

`define    CTL_FWD_LOG_CRITICAL_PACKET_RANGE                                7:7
`define    CTL_FWD_LOG_CRITICAL_PACKET_WIDTH                                1

`define    CTL_FWD_LOG_FORBID_EDIT_RANGE                                    8:8
`define    CTL_FWD_LOG_FORBID_EDIT_WIDTH                                    1

`define    CTL_FWD_LOG_REDIR_PTP_RANGE                                      9:9
`define    CTL_FWD_LOG_REDIR_PTP_WIDTH                                      1

`define    CTL_FWD_LOG_EGR_PORT_FILTED_RANGE                                10:10
`define    CTL_FWD_LOG_EGR_PORT_FILTED_WIDTH                                1

`define    CTL_FWD_LOG_EGR_VLAN_FILTED_RANGE                                11:11
`define    CTL_FWD_LOG_EGR_VLAN_FILTED_WIDTH                                1

`define    CTL_FWD_LOG_LAG_FILTED_RANGE                                     12:12
`define    CTL_FWD_LOG_LAG_FILTED_WIDTH                                     1

`define    CTL_FWD_LOG_PTP_VALID_RANGE                                      13:13
`define    CTL_FWD_LOG_PTP_VALID_WIDTH                                      1

`define    CTL_FWD_LOG_PTP2_CPU_RANGE                                       14:14
`define    CTL_FWD_LOG_PTP2_CPU_WIDTH                                       1

`define    CTL_FWD_LOG_ADD_RTAG_RANGE                                       15:15
`define    CTL_FWD_LOG_ADD_RTAG_WIDTH                                       1

`define    CTL_FWD_LOG_TSN_GATE_ID_RANGE                                    16:16
`define    CTL_FWD_LOG_TSN_GATE_ID_WIDTH                                    1

`define    CTL_FWD_LOG_TSN_CYCLE_RANGE                                      17:17
`define    CTL_FWD_LOG_TSN_CYCLE_WIDTH                                      1

`define    CTL_FWD_LOG_CPU_PKT_TYPE_RANGE                                   18:18
`define    CTL_FWD_LOG_CPU_PKT_TYPE_WIDTH                                   1

`define    CTL_FWD_LOG_DEST_LOST_IN_CFG_RANGE                               19:19
`define    CTL_FWD_LOG_DEST_LOST_IN_CFG_WIDTH                               1

// CtlFwdMcast
`define    CTL_FWD_MCAST_RANGE                                              1:0
`define    CTL_FWD_MCAST_WIDTH                                              2

`define    CTL_FWD_MCAST_MC_FILTERING_EN_RANGE                              0:0
`define    CTL_FWD_MCAST_MC_FILTERING_EN_WIDTH                              1

`define    CTL_FWD_MCAST_MCAST_EXCLUDE_SRC_RANGE                            1:1
`define    CTL_FWD_MCAST_MCAST_EXCLUDE_SRC_WIDTH                            1

// CtlFwdPortIsolate
`define    CTL_FWD_PORT_ISOLATE_RANGE                                       1:0
`define    CTL_FWD_PORT_ISOLATE_WIDTH                                       2

`define    CTL_FWD_PORT_ISOLATE_VLAN_ID_RANGE                               0:0
`define    CTL_FWD_PORT_ISOLATE_VLAN_ID_WIDTH                               1

`define    CTL_FWD_PORT_ISOLATE_FORCE_PORT_EGRESS_MASK_RANGE                1:1
`define    CTL_FWD_PORT_ISOLATE_FORCE_PORT_EGRESS_MASK_WIDTH                1

// CtlFwdUnknownFilter
`define    CTL_FWD_UNKNOWN_FILTER_RANGE                                     2:0
`define    CTL_FWD_UNKNOWN_FILTER_WIDTH                                     3

`define    CTL_FWD_UNKNOWN_FILTER_BCAST_FILTER_RANGE                        0:0
`define    CTL_FWD_UNKNOWN_FILTER_BCAST_FILTER_WIDTH                        1

`define    CTL_FWD_UNKNOWN_FILTER_UNKNOWN_MCAST_FILTER_RANGE                1:1
`define    CTL_FWD_UNKNOWN_FILTER_UNKNOWN_MCAST_FILTER_WIDTH                1

`define    CTL_FWD_UNKNOWN_FILTER_UNKNOWN_UCAST_FILTER_RANGE                2:2
`define    CTL_FWD_UNKNOWN_FILTER_UNKNOWN_UCAST_FILTER_WIDTH                1

// DsMemAclTsn
`define    DS_MEM_ACL_TSN_RANGE                                             -1:0
`define    DS_MEM_ACL_TSN_WIDTH                                             0

// DsMemCpuStats
`define    DS_MEM_CPU_STATS_RANGE                                           2:0
`define    DS_MEM_CPU_STATS_WIDTH                                           3

`define    DS_MEM_CPU_STATS_PKT_CNT_RANGE                                   0:0
`define    DS_MEM_CPU_STATS_PKT_CNT_WIDTH                                   1

`define    DS_MEM_CPU_STATS_BYTE_CNT_HI_RANGE                               1:1
`define    DS_MEM_CPU_STATS_BYTE_CNT_HI_WIDTH                               1

`define    DS_MEM_CPU_STATS_BYTE_CNT_RANGE                                  2:2
`define    DS_MEM_CPU_STATS_BYTE_CNT_WIDTH                                  1

// DsMemFlowColorStats
`define    DS_MEM_FLOW_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_FLOW_COLOR_STATS_WIDTH                                    0

// DsMemFlowPolice
`define    DS_MEM_FLOW_POLICE_RANGE                                         -1:0
`define    DS_MEM_FLOW_POLICE_WIDTH                                         0

// DsMemFlowPoliceCfg
`define    DS_MEM_FLOW_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_FLOW_POLICE_CFG_WIDTH                                     0

// DsMemHostRoute
`define    DS_MEM_HOST_ROUTE_RANGE                                          -1:0
`define    DS_MEM_HOST_ROUTE_WIDTH                                          0

// DsMemHostRouteLeft
`define    DS_MEM_HOST_ROUTE_LEFT_RANGE                                     -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_WIDTH                                     0

// DsMemHostRouteLeftKey
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_RANGE                                 -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_WIDTH                                 0

// DsMemHostRouteLeftValid
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_RANGE                               -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_WIDTH                               0

// DsMemHostRouteRight
`define    DS_MEM_HOST_ROUTE_RIGHT_RANGE                                    -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_WIDTH                                    0

// DsMemHostRouteRightKey
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_RANGE                                -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_WIDTH                                0

// DsMemHostRouteRightValid
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_RANGE                              -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_WIDTH                              0

// DsMemHostTsn
`define    DS_MEM_HOST_TSN_RANGE                                            -1:0
`define    DS_MEM_HOST_TSN_WIDTH                                            0

// DsMemHostTsnLeft
`define    DS_MEM_HOST_TSN_LEFT_RANGE                                       -1:0
`define    DS_MEM_HOST_TSN_LEFT_WIDTH                                       0

// DsMemHostTsnRight
`define    DS_MEM_HOST_TSN_RIGHT_RANGE                                      -1:0
`define    DS_MEM_HOST_TSN_RIGHT_WIDTH                                      0

// DsMemIndvRcvyCfg
`define    DS_MEM_INDV_RCVY_CFG_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CFG_WIDTH                                       0

// DsMemIndvRcvyCnt
`define    DS_MEM_INDV_RCVY_CNT_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CNT_WIDTH                                       0

// DsMemIndvRcvySeq
`define    DS_MEM_INDV_RCVY_SEQ_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_SEQ_WIDTH                                       0

// DsMemMacAgingLeft
`define    DS_MEM_MAC_AGING_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_AGING_LEFT_WIDTH                                      0

// DsMemMacAgingRight
`define    DS_MEM_MAC_AGING_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_AGING_RIGHT_WIDTH                                     0

// DsMemMacKeyLeft
`define    DS_MEM_MAC_KEY_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_KEY_LEFT_WIDTH                                        0

// DsMemMacKeyRight
`define    DS_MEM_MAC_KEY_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_KEY_RIGHT_WIDTH                                       0

// DsMemMacLeft
`define    DS_MEM_MAC_LEFT_RANGE                                            -1:0
`define    DS_MEM_MAC_LEFT_WIDTH                                            0

// DsMemMacRight
`define    DS_MEM_MAC_RIGHT_RANGE                                           -1:0
`define    DS_MEM_MAC_RIGHT_WIDTH                                           0

// DsMemMacStaticLeft
`define    DS_MEM_MAC_STATIC_LEFT_RANGE                                     -1:0
`define    DS_MEM_MAC_STATIC_LEFT_WIDTH                                     0

// DsMemMacStaticRight
`define    DS_MEM_MAC_STATIC_RIGHT_RANGE                                    -1:0
`define    DS_MEM_MAC_STATIC_RIGHT_WIDTH                                    0

// DsMemMacTsn
`define    DS_MEM_MAC_TSN_RANGE                                             -1:0
`define    DS_MEM_MAC_TSN_WIDTH                                             0

// DsMemMacTsnLeft
`define    DS_MEM_MAC_TSN_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_TSN_LEFT_WIDTH                                        0

// DsMemMacTsnRight
`define    DS_MEM_MAC_TSN_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_TSN_RIGHT_WIDTH                                       0

// DsMemMacValidLeft
`define    DS_MEM_MAC_VALID_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_VALID_LEFT_WIDTH                                      0

// DsMemMacValidRight
`define    DS_MEM_MAC_VALID_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_VALID_RIGHT_WIDTH                                     0

// DsMemMcastPort
`define    DS_MEM_MCAST_PORT_RANGE                                          1:0
`define    DS_MEM_MCAST_PORT_WIDTH                                          2

`define    DS_MEM_MCAST_PORT_PORT_MASK_RANGE                                0:0
`define    DS_MEM_MCAST_PORT_PORT_MASK_WIDTH                                1

`define    DS_MEM_MCAST_PORT_APPLY_VLAN_MASK_RANGE                          1:1
`define    DS_MEM_MCAST_PORT_APPLY_VLAN_MASK_WIDTH                          1

// DsMemPortColorStats
`define    DS_MEM_PORT_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_PORT_COLOR_STATS_WIDTH                                    0

// DsMemPortPolice
`define    DS_MEM_PORT_POLICE_RANGE                                         -1:0
`define    DS_MEM_PORT_POLICE_WIDTH                                         0

// DsMemPortPoliceCfg
`define    DS_MEM_PORT_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_PORT_POLICE_CFG_WIDTH                                     0

// DsMemRouteTsn
`define    DS_MEM_ROUTE_TSN_RANGE                                           -1:0
`define    DS_MEM_ROUTE_TSN_WIDTH                                           0

// DsMemSrcPortEgressMask
`define    DS_MEM_SRC_PORT_EGRESS_MASK_RANGE                                0:0
`define    DS_MEM_SRC_PORT_EGRESS_MASK_WIDTH                                1

`define    DS_MEM_SRC_PORT_EGRESS_MASK_PORT_EGRESS_MASK_RANGE               0:0
`define    DS_MEM_SRC_PORT_EGRESS_MASK_PORT_EGRESS_MASK_WIDTH               1

// DsMemStreamRcvyCfg
`define    DS_MEM_STREAM_RCVY_CFG_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CFG_WIDTH                                     0

// DsMemStreamRcvyCnt
`define    DS_MEM_STREAM_RCVY_CNT_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CNT_WIDTH                                     0

// DsMemStreamRcvySeq
`define    DS_MEM_STREAM_RCVY_SEQ_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_SEQ_WIDTH                                     0

// DsMemTsnEdit
`define    DS_MEM_TSN_EDIT_RANGE                                            0:0
`define    DS_MEM_TSN_EDIT_WIDTH                                            1

`define    DS_MEM_TSN_EDIT_GEN_SEQ_NUM_RANGE                                0:0
`define    DS_MEM_TSN_EDIT_GEN_SEQ_NUM_WIDTH                                1

// DsMemTsnSpec
`define    DS_MEM_TSN_SPEC_RANGE                                            3:0
`define    DS_MEM_TSN_SPEC_WIDTH                                            4

`define    DS_MEM_TSN_SPEC_GATE_ID_RANGE                                    0:0
`define    DS_MEM_TSN_SPEC_GATE_ID_WIDTH                                    1

`define    DS_MEM_TSN_SPEC_CYCLE_SEL_RANGE                                  1:1
`define    DS_MEM_TSN_SPEC_CYCLE_SEL_WIDTH                                  1

`define    DS_MEM_TSN_SPEC_PRIOR_RANGE                                      2:2
`define    DS_MEM_TSN_SPEC_PRIOR_WIDTH                                      1

`define    DS_MEM_TSN_SPEC_ADD_RTAG_RANGE                                   3:3
`define    DS_MEM_TSN_SPEC_ADD_RTAG_WIDTH                                   1

// DsMemTsnSplit
`define    DS_MEM_TSN_SPLIT_RANGE                                           0:0
`define    DS_MEM_TSN_SPLIT_WIDTH                                           1

`define    DS_MEM_TSN_SPLIT_DEST_BMP_RANGE                                  0:0
`define    DS_MEM_TSN_SPLIT_DEST_BMP_WIDTH                                  1

// DsMemVlanPortMask
`define    DS_MEM_VLAN_PORT_MASK_RANGE                                      0:0
`define    DS_MEM_VLAN_PORT_MASK_WIDTH                                      1

`define    DS_MEM_VLAN_PORT_MASK_PORT_MASK_RANGE                            0:0
`define    DS_MEM_VLAN_PORT_MASK_PORT_MASK_WIDTH                            1

// DsRegDestPortChnlMap
`define    DS_REG_DEST_PORT_CHNL_MAP_RANGE                                  0:0
`define    DS_REG_DEST_PORT_CHNL_MAP_WIDTH                                  1

`define    DS_REG_DEST_PORT_CHNL_MAP_CHANNEL_ID_RANGE                       0:0
`define    DS_REG_DEST_PORT_CHNL_MAP_CHANNEL_ID_WIDTH                       1

// DsRegLagGrp
`define    DS_REG_LAG_GRP_RANGE                                             2:0
`define    DS_REG_LAG_GRP_WIDTH                                             3

`define    DS_REG_LAG_GRP_MEMBER_BITMAP_RANGE                               0:0
`define    DS_REG_LAG_GRP_MEMBER_BITMAP_WIDTH                               1

`define    DS_REG_LAG_GRP_LINK_NUMBER_RANGE                                 1:1
`define    DS_REG_LAG_GRP_LINK_NUMBER_WIDTH                                 1

`define    DS_REG_LAG_GRP_SRC_MATCH_DISCARD_RANGE                           2:2
`define    DS_REG_LAG_GRP_SRC_MATCH_DISCARD_WIDTH                           1

// DsRegLagPort
`define    DS_REG_LAG_PORT_RANGE                                            0:0
`define    DS_REG_LAG_PORT_WIDTH                                            1

`define    DS_REG_LAG_PORT_DEST_PORT_RANGE                                  0:0
`define    DS_REG_LAG_PORT_DEST_PORT_WIDTH                                  1

// MsgAdmInfo0
`define    MSG_ADM_INFO0_RANGE                                              -1:0
`define    MSG_ADM_INFO0_WIDTH                                              0

// TmpDsMemMac
`define    TMP_DS_MEM_MAC_RANGE                                             -1:0
`define    TMP_DS_MEM_MAC_WIDTH                                             0

// CtlMacLearn
`define    CTL_MAC_LEARN_RANGE                                              6:0
`define    CTL_MAC_LEARN_WIDTH                                              7

`define    CTL_MAC_LEARN_CPU_LEARN_EN_RANGE                                 0:0
`define    CTL_MAC_LEARN_CPU_LEARN_EN_WIDTH                                 1

`define    CTL_MAC_LEARN_CPU_LEARN_NUM_RANGE                                1:1
`define    CTL_MAC_LEARN_CPU_LEARN_NUM_WIDTH                                1

`define    CTL_MAC_LEARN_CPU_FIFO_DEPTH_RANGE                               2:2
`define    CTL_MAC_LEARN_CPU_FIFO_DEPTH_WIDTH                               1

`define    CTL_MAC_LEARN_CPU_LRN_NUM_THRD_RANGE                             3:3
`define    CTL_MAC_LEARN_CPU_LRN_NUM_THRD_WIDTH                             1

`define    CTL_MAC_LEARN_HW_LEARN_NUM_RANGE                                 4:4
`define    CTL_MAC_LEARN_HW_LEARN_NUM_WIDTH                                 1

`define    CTL_MAC_LEARN_HW_FIFO_DEPTH_RANGE                                5:5
`define    CTL_MAC_LEARN_HW_FIFO_DEPTH_WIDTH                                1

`define    CTL_MAC_LEARN_HW_LRN_NUM_THRD_RANGE                              6:6
`define    CTL_MAC_LEARN_HW_LRN_NUM_THRD_WIDTH                              1

// CtlPktProcLog
`define    CTL_PKT_PROC_LOG_RANGE                                           18:0
`define    CTL_PKT_PROC_LOG_WIDTH                                           19

`define    CTL_PKT_PROC_LOG_CPU_FIFO_FULL_NUM_RANGE                         0:0
`define    CTL_PKT_PROC_LOG_CPU_FIFO_FULL_NUM_WIDTH                         1

`define    CTL_PKT_PROC_LOG_HW_FIFO_FULL_NUM_RANGE                          1:1
`define    CTL_PKT_PROC_LOG_HW_FIFO_FULL_NUM_WIDTH                          1

`define    CTL_PKT_PROC_LOG_ACL_QOS_LOG_EN_RANGE                            2:2
`define    CTL_PKT_PROC_LOG_ACL_QOS_LOG_EN_WIDTH                            1

`define    CTL_PKT_PROC_LOG_ACL_DISCARD_RANGE                               3:3
`define    CTL_PKT_PROC_LOG_ACL_DISCARD_WIDTH                               1

`define    CTL_PKT_PROC_LOG_ROUTE_DISCARD_RANGE                             4:4
`define    CTL_PKT_PROC_LOG_ROUTE_DISCARD_WIDTH                             1

`define    CTL_PKT_PROC_LOG_ROUTE_EXCP_DISCARD_RANGE                        5:5
`define    CTL_PKT_PROC_LOG_ROUTE_EXCP_DISCARD_WIDTH                        1

`define    CTL_PKT_PROC_LOG_ROUTE_PROCESS_RANGE                             6:6
`define    CTL_PKT_PROC_LOG_ROUTE_PROCESS_WIDTH                             1

`define    CTL_PKT_PROC_LOG_BRIDGE_PROCESS_RANGE                            7:7
`define    CTL_PKT_PROC_LOG_BRIDGE_PROCESS_WIDTH                            1

`define    CTL_PKT_PROC_LOG_DEST_MAC_KNOWN_RANGE                            8:8
`define    CTL_PKT_PROC_LOG_DEST_MAC_KNOWN_WIDTH                            1

`define    CTL_PKT_PROC_LOG_L2_UCAST_SRC_MATCH_DISCARD_RANGE                9:9
`define    CTL_PKT_PROC_LOG_L2_UCAST_SRC_MATCH_DISCARD_WIDTH                1

`define    CTL_PKT_PROC_LOG_MAC_DA_DISCARD_RANGE                            10:10
`define    CTL_PKT_PROC_LOG_MAC_DA_DISCARD_WIDTH                            1

`define    CTL_PKT_PROC_LOG_IGR_STP_CHECK_DISCARD_RANGE                     11:11
`define    CTL_PKT_PROC_LOG_IGR_STP_CHECK_DISCARD_WIDTH                     1

`define    CTL_PKT_PROC_LOG_STORM_DROP_RANGE                                12:12
`define    CTL_PKT_PROC_LOG_STORM_DROP_WIDTH                                1

`define    CTL_PKT_PROC_LOG_LRN_PORT_LOCK_DISCARD_RANGE                     13:13
`define    CTL_PKT_PROC_LOG_LRN_PORT_LOCK_DISCARD_WIDTH                     1

`define    CTL_PKT_PROC_LOG_LRN_NUM_EXCEED_DISCARD_RANGE                    14:14
`define    CTL_PKT_PROC_LOG_LRN_NUM_EXCEED_DISCARD_WIDTH                    1

`define    CTL_PKT_PROC_LOG_IS_TSN_RANGE                                    15:15
`define    CTL_PKT_PROC_LOG_IS_TSN_WIDTH                                    1

`define    CTL_PKT_PROC_LOG_TSN_HANDLE_RANGE                                16:16
`define    CTL_PKT_PROC_LOG_TSN_HANDLE_WIDTH                                1

`define    CTL_PKT_PROC_LOG_IGR_FLOW_SPAN_RANGE                             17:17
`define    CTL_PKT_PROC_LOG_IGR_FLOW_SPAN_WIDTH                             1

`define    CTL_PKT_PROC_LOG_ENTRY_PEND_RANGE                                18:18
`define    CTL_PKT_PROC_LOG_ENTRY_PEND_WIDTH                                1

// CtlPpGapConfig
`define    CTL_PP_GAP_CONFIG_RANGE                                          0:0
`define    CTL_PP_GAP_CONFIG_WIDTH                                          1

`define    CTL_PP_GAP_CONFIG_GAP_VALUE_RANGE                                0:0
`define    CTL_PP_GAP_CONFIG_GAP_VALUE_WIDTH                                1

// CtlStormCntl
`define    CTL_STORM_CNTL_RANGE                                             7:0
`define    CTL_STORM_CNTL_WIDTH                                             8

`define    CTL_STORM_CNTL_ENABLE_RANGE                                      0:0
`define    CTL_STORM_CNTL_ENABLE_WIDTH                                      1

`define    CTL_STORM_CNTL_STORM_CUR_PTR_RANGE                               1:1
`define    CTL_STORM_CNTL_STORM_CUR_PTR_WIDTH                               1

`define    CTL_STORM_CNTL_STORM_INTERVAL_RANGE                              2:2
`define    CTL_STORM_CNTL_STORM_INTERVAL_WIDTH                              1

`define    CTL_STORM_CNTL_STORM_MAX_PTR_RANGE                               3:3
`define    CTL_STORM_CNTL_STORM_MAX_PTR_WIDTH                               1

`define    CTL_STORM_CNTL_STORM_MIN_PTR_RANGE                               4:4
`define    CTL_STORM_CNTL_STORM_MIN_PTR_WIDTH                               1

`define    CTL_STORM_CNTL_STORM_FINAL_DELAY_RANGE                           5:5
`define    CTL_STORM_CNTL_STORM_FINAL_DELAY_WIDTH                           1

`define    CTL_STORM_CNTL_STORM_CUR_ROUND_RANGE                             6:6
`define    CTL_STORM_CNTL_STORM_CUR_ROUND_WIDTH                             1

`define    CTL_STORM_CNTL_STORM_UPD_ROUND_RANGE                             7:7
`define    CTL_STORM_CNTL_STORM_UPD_ROUND_WIDTH                             1

// DsMemAclTsn
`define    DS_MEM_ACL_TSN_RANGE                                             -1:0
`define    DS_MEM_ACL_TSN_WIDTH                                             0

// DsMemCustomFdb
`define    DS_MEM_CUSTOM_FDB_RANGE                                          8:0
`define    DS_MEM_CUSTOM_FDB_WIDTH                                          9

`define    DS_MEM_CUSTOM_FDB_IS_TSN_RANGE                                   0:0
`define    DS_MEM_CUSTOM_FDB_IS_TSN_WIDTH                                   1

`define    DS_MEM_CUSTOM_FDB_TSN_HANDLE_RANGE                               1:1
`define    DS_MEM_CUSTOM_FDB_TSN_HANDLE_WIDTH                               1

`define    DS_MEM_CUSTOM_FDB_FLOW_POLICE_PTR_RANGE                          2:2
`define    DS_MEM_CUSTOM_FDB_FLOW_POLICE_PTR_WIDTH                          1

`define    DS_MEM_CUSTOM_FDB_FLOW_POLICE_VALID_RANGE                        3:3
`define    DS_MEM_CUSTOM_FDB_FLOW_POLICE_VALID_WIDTH                        1

`define    DS_MEM_CUSTOM_FDB_FLOW_STATS_VALID_RANGE                         4:4
`define    DS_MEM_CUSTOM_FDB_FLOW_STATS_VALID_WIDTH                         1

`define    DS_MEM_CUSTOM_FDB_FLOW_STATS_PTR_RANGE                           5:5
`define    DS_MEM_CUSTOM_FDB_FLOW_STATS_PTR_WIDTH                           1

`define    DS_MEM_CUSTOM_FDB_DEST_MAP_RANGE                                 6:6
`define    DS_MEM_CUSTOM_FDB_DEST_MAP_WIDTH                                 1

`define    DS_MEM_CUSTOM_FDB_IS_MCAST_RANGE                                 7:7
`define    DS_MEM_CUSTOM_FDB_IS_MCAST_WIDTH                                 1

`define    DS_MEM_CUSTOM_FDB_MIRROR_EN_RANGE                                8:8
`define    DS_MEM_CUSTOM_FDB_MIRROR_EN_WIDTH                                1

// DsMemFlowColorStats
`define    DS_MEM_FLOW_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_FLOW_COLOR_STATS_WIDTH                                    0

// DsMemFlowPolice
`define    DS_MEM_FLOW_POLICE_RANGE                                         -1:0
`define    DS_MEM_FLOW_POLICE_WIDTH                                         0

// DsMemFlowPoliceCfg
`define    DS_MEM_FLOW_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_FLOW_POLICE_CFG_WIDTH                                     0

// DsMemHostRoute
`define    DS_MEM_HOST_ROUTE_RANGE                                          -1:0
`define    DS_MEM_HOST_ROUTE_WIDTH                                          0

// DsMemHostRouteLeft
`define    DS_MEM_HOST_ROUTE_LEFT_RANGE                                     -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_WIDTH                                     0

// DsMemHostRouteLeftKey
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_RANGE                                 -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_KEY_WIDTH                                 0

// DsMemHostRouteLeftValid
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_RANGE                               -1:0
`define    DS_MEM_HOST_ROUTE_LEFT_VALID_WIDTH                               0

// DsMemHostRouteRight
`define    DS_MEM_HOST_ROUTE_RIGHT_RANGE                                    -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_WIDTH                                    0

// DsMemHostRouteRightKey
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_RANGE                                -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_KEY_WIDTH                                0

// DsMemHostRouteRightValid
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_RANGE                              -1:0
`define    DS_MEM_HOST_ROUTE_RIGHT_VALID_WIDTH                              0

// DsMemHostTsn
`define    DS_MEM_HOST_TSN_RANGE                                            -1:0
`define    DS_MEM_HOST_TSN_WIDTH                                            0

// DsMemHostTsnLeft
`define    DS_MEM_HOST_TSN_LEFT_RANGE                                       -1:0
`define    DS_MEM_HOST_TSN_LEFT_WIDTH                                       0

// DsMemHostTsnRight
`define    DS_MEM_HOST_TSN_RIGHT_RANGE                                      -1:0
`define    DS_MEM_HOST_TSN_RIGHT_WIDTH                                      0

// DsMemIndvRcvyCfg
`define    DS_MEM_INDV_RCVY_CFG_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CFG_WIDTH                                       0

// DsMemIndvRcvyCnt
`define    DS_MEM_INDV_RCVY_CNT_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_CNT_WIDTH                                       0

// DsMemIndvRcvySeq
`define    DS_MEM_INDV_RCVY_SEQ_RANGE                                       -1:0
`define    DS_MEM_INDV_RCVY_SEQ_WIDTH                                       0

// DsMemMac
`define    DS_MEM_MAC_RANGE                                                 9:0
`define    DS_MEM_MAC_WIDTH                                                 10

`define    DS_MEM_MAC_PENDING_RANGE                                         0:0
`define    DS_MEM_MAC_PENDING_WIDTH                                         1

`define    DS_MEM_MAC_FLOW_POLICE_PTR_RANGE                                 1:1
`define    DS_MEM_MAC_FLOW_POLICE_PTR_WIDTH                                 1

`define    DS_MEM_MAC_FLOW_POLICE_VALID_RANGE                               2:2
`define    DS_MEM_MAC_FLOW_POLICE_VALID_WIDTH                               1

`define    DS_MEM_MAC_FLOW_STATS_VALID_RANGE                                3:3
`define    DS_MEM_MAC_FLOW_STATS_VALID_WIDTH                                1

`define    DS_MEM_MAC_FLOW_STATS_PTR_RANGE                                  4:4
`define    DS_MEM_MAC_FLOW_STATS_PTR_WIDTH                                  1

`define    DS_MEM_MAC_DEST_MAP_RANGE                                        5:5
`define    DS_MEM_MAC_DEST_MAP_WIDTH                                        1

`define    DS_MEM_MAC_IS_MCAST_RANGE                                        6:6
`define    DS_MEM_MAC_IS_MCAST_WIDTH                                        1

`define    DS_MEM_MAC_MIRROR_EN_RANGE                                       7:7
`define    DS_MEM_MAC_MIRROR_EN_WIDTH                                       1

`define    DS_MEM_MAC_DST_DISCARD_RANGE                                     8:8
`define    DS_MEM_MAC_DST_DISCARD_WIDTH                                     1

`define    DS_MEM_MAC_COPY_TO_CPU_RANGE                                     9:9
`define    DS_MEM_MAC_COPY_TO_CPU_WIDTH                                     1

// DsMemMacAgingLeft
`define    DS_MEM_MAC_AGING_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_AGING_LEFT_WIDTH                                      0

// DsMemMacAgingRight
`define    DS_MEM_MAC_AGING_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_AGING_RIGHT_WIDTH                                     0

// DsMemMacKeyLeft
`define    DS_MEM_MAC_KEY_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_KEY_LEFT_WIDTH                                        0

// DsMemMacKeyRight
`define    DS_MEM_MAC_KEY_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_KEY_RIGHT_WIDTH                                       0

// DsMemMacLeft
`define    DS_MEM_MAC_LEFT_RANGE                                            -1:0
`define    DS_MEM_MAC_LEFT_WIDTH                                            0

// DsMemMacRight
`define    DS_MEM_MAC_RIGHT_RANGE                                           -1:0
`define    DS_MEM_MAC_RIGHT_WIDTH                                           0

// DsMemMacStaticLeft
`define    DS_MEM_MAC_STATIC_LEFT_RANGE                                     -1:0
`define    DS_MEM_MAC_STATIC_LEFT_WIDTH                                     0

// DsMemMacStaticRight
`define    DS_MEM_MAC_STATIC_RIGHT_RANGE                                    -1:0
`define    DS_MEM_MAC_STATIC_RIGHT_WIDTH                                    0

// DsMemMacTsn
`define    DS_MEM_MAC_TSN_RANGE                                             1:0
`define    DS_MEM_MAC_TSN_WIDTH                                             2

`define    DS_MEM_MAC_TSN_IS_TSN_RANGE                                      0:0
`define    DS_MEM_MAC_TSN_IS_TSN_WIDTH                                      1

`define    DS_MEM_MAC_TSN_TSN_HANDLE_RANGE                                  1:1
`define    DS_MEM_MAC_TSN_TSN_HANDLE_WIDTH                                  1

// DsMemMacTsnLeft
`define    DS_MEM_MAC_TSN_LEFT_RANGE                                        -1:0
`define    DS_MEM_MAC_TSN_LEFT_WIDTH                                        0

// DsMemMacTsnRight
`define    DS_MEM_MAC_TSN_RIGHT_RANGE                                       -1:0
`define    DS_MEM_MAC_TSN_RIGHT_WIDTH                                       0

// DsMemMacValidLeft
`define    DS_MEM_MAC_VALID_LEFT_RANGE                                      -1:0
`define    DS_MEM_MAC_VALID_LEFT_WIDTH                                      0

// DsMemMacValidRight
`define    DS_MEM_MAC_VALID_RIGHT_RANGE                                     -1:0
`define    DS_MEM_MAC_VALID_RIGHT_WIDTH                                     0

// DsMemPortColorStats
`define    DS_MEM_PORT_COLOR_STATS_RANGE                                    -1:0
`define    DS_MEM_PORT_COLOR_STATS_WIDTH                                    0

// DsMemPortPolice
`define    DS_MEM_PORT_POLICE_RANGE                                         -1:0
`define    DS_MEM_PORT_POLICE_WIDTH                                         0

// DsMemPortPoliceCfg
`define    DS_MEM_PORT_POLICE_CFG_RANGE                                     -1:0
`define    DS_MEM_PORT_POLICE_CFG_WIDTH                                     0

// DsMemRoute
`define    DS_MEM_ROUTE_RANGE                                               9:0
`define    DS_MEM_ROUTE_WIDTH                                               10

`define    DS_MEM_ROUTE_DEST_MAP_RANGE                                      0:0
`define    DS_MEM_ROUTE_DEST_MAP_WIDTH                                      1

`define    DS_MEM_ROUTE_NEXTHOP_IDX_RANGE                                   1:1
`define    DS_MEM_ROUTE_NEXTHOP_IDX_WIDTH                                   1

`define    DS_MEM_ROUTE_FLOW_POLICE_PTR_RANGE                               2:2
`define    DS_MEM_ROUTE_FLOW_POLICE_PTR_WIDTH                               1

`define    DS_MEM_ROUTE_FLOW_POLICE_VALID_RANGE                             3:3
`define    DS_MEM_ROUTE_FLOW_POLICE_VALID_WIDTH                             1

`define    DS_MEM_ROUTE_FLOW_STATS_VALID_RANGE                              4:4
`define    DS_MEM_ROUTE_FLOW_STATS_VALID_WIDTH                              1

`define    DS_MEM_ROUTE_FLOW_STATS_PTR_RANGE                                5:5
`define    DS_MEM_ROUTE_FLOW_STATS_PTR_WIDTH                                1

`define    DS_MEM_ROUTE_MIRROR_EN_RANGE                                     6:6
`define    DS_MEM_ROUTE_MIRROR_EN_WIDTH                                     1

`define    DS_MEM_ROUTE_DISCARD_RANGE                                       7:7
`define    DS_MEM_ROUTE_DISCARD_WIDTH                                       1

`define    DS_MEM_ROUTE_COPY_TO_CPU_RANGE                                   8:8
`define    DS_MEM_ROUTE_COPY_TO_CPU_WIDTH                                   1

`define    DS_MEM_ROUTE_NAT_RANGE                                           9:9
`define    DS_MEM_ROUTE_NAT_WIDTH                                           1

// DsMemRouteTsn
`define    DS_MEM_ROUTE_TSN_RANGE                                           1:0
`define    DS_MEM_ROUTE_TSN_WIDTH                                           2

`define    DS_MEM_ROUTE_TSN_IS_TSN_RANGE                                    0:0
`define    DS_MEM_ROUTE_TSN_IS_TSN_WIDTH                                    1

`define    DS_MEM_ROUTE_TSN_TSN_HANDLE_RANGE                                1:1
`define    DS_MEM_ROUTE_TSN_TSN_HANDLE_WIDTH                                1

// DsMemStorm
`define    DS_MEM_STORM_RANGE                                               0:0
`define    DS_MEM_STORM_WIDTH                                               1

`define    DS_MEM_STORM_RUNNING_COUNTER_RANGE                               0:0
`define    DS_MEM_STORM_RUNNING_COUNTER_WIDTH                               1

// DsMemStormCtrl
`define    DS_MEM_STORM_CTRL_RANGE                                          2:0
`define    DS_MEM_STORM_CTRL_WIDTH                                          3

`define    DS_MEM_STORM_CTRL_STORM_CTRL_EN_RANGE                            0:0
`define    DS_MEM_STORM_CTRL_STORM_CTRL_EN_WIDTH                            1

`define    DS_MEM_STORM_CTRL_THRESHOLD_RANGE                                1:1
`define    DS_MEM_STORM_CTRL_THRESHOLD_WIDTH                                1

`define    DS_MEM_STORM_CTRL_USE_PKT_COUNT_RANGE                            2:2
`define    DS_MEM_STORM_CTRL_USE_PKT_COUNT_WIDTH                            1

// DsMemStreamRcvyCfg
`define    DS_MEM_STREAM_RCVY_CFG_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CFG_WIDTH                                     0

// DsMemStreamRcvyCnt
`define    DS_MEM_STREAM_RCVY_CNT_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_CNT_WIDTH                                     0

// DsMemStreamRcvySeq
`define    DS_MEM_STREAM_RCVY_SEQ_RANGE                                     -1:0
`define    DS_MEM_STREAM_RCVY_SEQ_WIDTH                                     0

// DsRegPortLearnCtrl
`define    DS_REG_PORT_LEARN_CTRL_RANGE                                     4:0
`define    DS_REG_PORT_LEARN_CTRL_WIDTH                                     5

`define    DS_REG_PORT_LEARN_CTRL_LOCK_RANGE                                0:0
`define    DS_REG_PORT_LEARN_CTRL_LOCK_WIDTH                                1

`define    DS_REG_PORT_LEARN_CTRL_VIOLATION_TO_CPU_RANGE                    1:1
`define    DS_REG_PORT_LEARN_CTRL_VIOLATION_TO_CPU_WIDTH                    1

`define    DS_REG_PORT_LEARN_CTRL_MAX_MAC_NUM_RANGE                         2:2
`define    DS_REG_PORT_LEARN_CTRL_MAX_MAC_NUM_WIDTH                         1

`define    DS_REG_PORT_LEARN_CTRL_MAC_NUM_LIMIT_EN_RANGE                    3:3
`define    DS_REG_PORT_LEARN_CTRL_MAC_NUM_LIMIT_EN_WIDTH                    1

`define    DS_REG_PORT_LEARN_CTRL_LRN_NUM_EXCEED_DISCARD_RANGE              4:4
`define    DS_REG_PORT_LEARN_CTRL_LRN_NUM_EXCEED_DISCARD_WIDTH              1

// DsRegPortLearnNum
`define    DS_REG_PORT_LEARN_NUM_RANGE                                      0:0
`define    DS_REG_PORT_LEARN_NUM_WIDTH                                      1

`define    DS_REG_PORT_LEARN_NUM_LEARNT_MAC_NUM_RANGE                       0:0
`define    DS_REG_PORT_LEARN_NUM_LEARNT_MAC_NUM_WIDTH                       1

// MsgAdmInfo0
`define    MSG_ADM_INFO0_RANGE                                              -1:0
`define    MSG_ADM_INFO0_WIDTH                                              0

// TmpDsMemMac
`define    TMP_DS_MEM_MAC_RANGE                                             -1:0
`define    TMP_DS_MEM_MAC_WIDTH                                             0

