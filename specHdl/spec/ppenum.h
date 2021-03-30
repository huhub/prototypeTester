enum TunnelType { 
    TUNNEL_TYPE_NONE,
    TUNNEL_TYPE_MPLS,
    TUNNEL_TYPE_GRE,
    TUNNEL_TYPE_L2TP,
    TUNNEL_TYPE_VXLAN,
}

enum VlanAft {
	VLAN_AFT_ALL, 
	VLAN_AFT_TAGGED,
	VLAN_AFT_NO_TAG,
	VLAN_AFT_NONE,    // discard all
}

enum PsrProto {
    PROTO_TYPE_INVALID,
    // layer 2
    PROTO_TYPE_ETH,
    // layer 3
    PROTO_TYPE_IPV4,   // 2
    PROTO_TYPE_IPV6,
    PROTO_TYPE_ARP,
    PROTO_TYPE_MPLS,
    PROTO_TYPE_SLOW,
    PROTO_TYPE_EAPOL,
    PROTO_TYPE_GOOSE,
    PROTO_TYPE_SMV,
    PROTO_TYPE_LLDP,
    PROTO_TYPE_MMRP,
    PROTO_TYPE_MVRP,
    PROTO_TYPE_PTP,
    PROTO_TYPE_NCMT,
    PROTO_TYPE_CFM,
    PROTO_TYPE_ROCE,
    PROTO_TYPE_ISIS,
    // layer 4
    PROTO_TYPE_UDP = 32,  // 16
    PROTO_TYPE_TCP,
    PROTO_TYPE_HOP,
    PROTO_TYPE_ICMP,
    PROTO_TYPE_IGMP,
    PROTO_TYPE_EGP,
    PROTO_TYPE_IGP,
    PROTO_TYPE_V6PING,
    PROTO_TYPE_MLD,
    PROTO_TYPE_ND,
    PROTO_TYPE_SRV6,
    PROTO_TYPE_GRE,
    PROTO_TYPE_AH,
    PROTO_TYPE_L2TP,
    PROTO_TYPE_SCTP,
    PROTO_TYPE_MPLS_IN_IP,
    // layer 5
    PROTO_TYPE_SNMP = 64,   // 32
    PROTO_TYPE_BFD,
    PROTO_TYPE_1722,
    PROTO_TYPE_APS,
} 

enum LoopPkt {
    LOOP_PKT_INVALID,
    LOOP_PKT_UPMEP,
}

enum Opcode {
    OP_CODE_BCAST,
    OP_CODE_MCAST,
    OP_CODE_UCAST,
    OP_CODE_NAT,
};

enum QosPolicy {
    QOS_POLICY_COS,
    QOS_POLICY_PORTCOS,
    QOS_POLICY_DSCP,
    QOS_POLICY_IPCOS,
};

enum Layer2Type {
    L2_TYPE_NONE,
    L2_TYPE_ETHV2,
    L2_TYPE_ETHSAP,
    L2_TYPE_ETHSNAP,
};

enum Layer3Type {
    L3_TYPE_NONE,
    L3_TYPE_IPV4,        /* 0x0800 */
    L3_TYPE_ARP,         /* 0x0806/8035 */
    L3_TYPE_MSRP,        /* 0x22EA */
    L3_TYPE_1722,        /* 0x22F0 */
    L3_TYPE_IPV6,        /* 0x86DD */
    L3_TYPE_EFM,         /* 0x8809 */
    L3_TYPE_MPLS,        /* 0x8847/8848 */
    L3_TYPE_EAPOL,       /* 0x888E */
    L3_TYPE_LLDP,        /* 0x88CC using 01-80-c2-00-00-0e */
    L3_TYPE_MMRP,        /* 0x88F5 */
    L3_TYPE_MVRP,        /* 0x88F6 */
    L3_TYPE_PTP,         /* 0x88F7, using 01-80-c2-00-00-0e */
    L3_TYPE_NCMT,        /* 0x88FE, send to destination */
    L3_TYPE_CFM,         /* 0x8902, using 01-80-C2-00-00-30 ~ 01-80-C2-00-00-3F */
    L3_TYPE_ROCEV1,      /* 0x8915 */
    L3_TYPE_ISIS,        /* 0xFEFE send to destination */
    L3_TYPE_UDF,         /* 0xFF02 */
    L3_TYPE_UNKNOWN,     
};

enum Layer4Type {
    L4_TYPE_NONE,
    L4_TYPE_TCP,
    L4_TYPE_UDP,
    L4_TYPE_ICMP,
    L4_TYPE_IGMP,
    L4_TYPE_V6ICMP,
    L4_TYPE_MLD,
    L4_TYPE_ND,
    L4_TYPE_UDF,
};

enum StpState {
    STP_FWD,
    STP_BLK,
    STP_LEARN,
    STP_DISCARD,
};

enum PktColor {
    COLOR_NONE,
    COLOR_RED,
    COLOR_YELLOW,
    COLOR_GREEN,
};

enum AgingType {
    NORMAL_AGING,
    FAST_AGING,
    FAST_SPECIAL,
    REPLACE,
};

enum LrnType {
    LRN_DISABLE,
    LEFT_HIT,
    RIGHT_HIT,
    LEFT_EMPTY,
    RIGHT_EMPTY,
    LEFT_OW,
    RIGHT_OW,
};

enum CpuPktType {
    CPU_PKT_NONE,
    CPU_PKT_EAPOL,
    CPU_PKT_ARP,
    CPU_PKT_IGMP,
    CPU_PKT_MLD,
    CPU_PKT_BPDU,
    CPU_PKT_ND,
	CPU_PKT_SNMP,
    CPU_PKT_MACDALKP,
    CPU_PKT_ROUTELKP,
    CPU_PKT_DHCP,
    CPU_PKT_MSRP,
    CPU_PKT_MMRP,
    CPU_PKT_MVRP,
};

enum ExceptionType {
    EXCP_NONE,
    EXCP_ROUTE,
    EXCP_LOCKVIOLATION,
    EXCP_STATIONMOVEVIOLATION,
    EXCP_MACNUMLIMITVIOLATION,
    EXCP_MTUCHECKFAILED,
    EXCP_L3IFMATCH,
    EXCP_NONE = 15,
};

enum PtpPortType {
    PTP_PORT_PASSIVE,
    PTP_PORT_DISABLE,
    PTP_PORT_SLAVE,
    PTP_PORT_MASTER,
};

enum PtpOpType {
    PTP_OP_NONE,
    PTP_OP_ONE_STEP,
    PTP_OP_TWO_STEP,
};

enum PtpDevType {
    PTP_DEV_NONE,
    PTP_DEV_MNG,
    PTP_DEV_TC_P2P,
    PTP_DEV_TC_E2E,
    PTP_DEV_BC,
    PTP_DEV_OC,
};

enum PtpMsgType {
    PTP_MSG_SYNC,
    PTP_MSG_DELAY_REQ,
    PTP_MSG_PDELAY_REQ,
    PTP_MSG_PDELAY_RESP,
    PTP_MSG_FOLLOW_UP   = 8,
    PTP_MSG_DELAY_RESP,
    PTP_MSG_PDELAY_RESP_FOLLOW_UP,
    PTP_MSG_ANNOUNCE,
    PTP_MSG_SIGNALING,
    PTP_MSG_MANAGEMENT,
};

enum TsnGateState {
    TSN_GATE_CLOSE,
    TSN_GATE_OPEN,
}

enum RcvyAlg {
    RCVY_NONE,
    RCVY_VECTOR,
    RCVY_MATCH,
};

/*******MPLS by fykong 2020-10-20***********/

//oam
#define VS_OAM_LABEL        0xd
#define VP_OAM_LABEL        0xd
#define VC_OAM_CW_1         0x10008902
#define VC_OAM_CW_2         0x10007ffa

#define UDP_LSP_PW_PING     3503
#define UDP_BFD_SINGLE_HOP  3784
#define UDP_BFD_MULTI_HOP   4784
#define UDP_BFD_ECHO        3785

#define IP_UDP              0x11
#define OAM_TYPE            0x8902

//bfd for pw protocols
#define BFD_FOR_PW_WITHOUT_IP_HEAD_1    0x10000007
#define BFD_FOR_PW_WITHOUT_IP_HEAD_2    0x10000022
#define BFD_FOR_PW_WITH_IPV4_HEAD       0x10000021
/*by-pass*/
#define ACH_TYPE_BY_PASS_APS       0x100000ff


enum mpls_action {
	MPLS_ACTION_UNKNOW, // Drop packet if set.
	MPLS_ACTION_IPOP, // Pop mpls label, i=internal, set to distiguish BoS label, to make sure L2 and L3 labels is at the bottom of stack.
	MPLS_ACTION_LSP, // Swap label if set, new label is retreived from lsp_nhi table.
	MPLS_ACTION_L2_NO_CW, // Label is the bottom L2VPN label without CW.
	MPLS_ACTION_L2_CW, // Label is the bottom L2VPN label with CW.
	MPLS_ACTION_L3, // Insert packet into L3 processing.
	MPLS_ACTION_max_value // Number of items
};

enum mpls_edit_action {
    MPLS_NO_EDIT_ACTION,
	MPLS_EXTRACT_MPLS_LABEL,                        //pop one mpls label
	MPLS_EXTRACT_MPLS_LABEL_LABEL,                  //pop two mpls labels
	MPLS_EXTRACT_MPLS_LABEL_LABEL_LABEL,            //pop three mpls labels
	MPLS_EXTRACT_MPLS_ETHERTYPE_LABEL,              //pop 0x8847 + one mpls label
	MPLS_EXTRACT_MPLS_ETHERTYPE_LABEL_LABEL,        //pop 0x8847 + two mpls label
	MPLS_EXTRACT_MPLS_ETHERTYPE_LABEL_LABEL_LABEL,  //pop 0x8847 + three mpls label
	MPLS_SWAP_MPLS_LABEL,                           //swap one mpls label
	MPLS_EXTRACT_MPLS_LABEL_SWAP_LABEL,             //pop one mpls label + swap inner label	
	MPLS_EXTRACT_MPLS_LABEL_CW,
	MPLS_EXTRACT_MPLS_LABEL_LABEL_CW,
	MPLS_EXTRACT_MPLS_LABEL_LABEL_LABEL_CW,
    //MPLS_SWAP_MPLS_LABEL_LABEL,                     //swap two mpls label, MSPW??
};

enum protocol_pkt_type {
    PROTOCOL_PKT_TYPE_UNUSED = 0,
	OAM_TYPE_VS_OAM          = 1,
	OAM_TYPE_VP_OAM          = 2,
	OAM_TYPE_VC_OAM          = 3,
	OAM_TYPE_BFD_FOR_IP,
	OAM_TYPE_BFD_FOR_PW1,
	OAM_TYPE_BFD_FOR_PW2,
	OAM_TYPE_BY_PASS_APS,

	OAM_TYPE_VCCV2,
	SCC_TYPE_LSP_PING_TRACE,
	SCC_TYPE_PW_TRACE,
	SCC_TYPE_PW_PING,
	SCC_TYPE_PW_BFD_ECHO,

};

enum vp_type {
    VP_TYPE_VPWS, // VPWS, the packet is not forwarded by the Bridge MAC forwarding, instead the new destination is the dvp_id.
    VP_TYPE_VPLS, // VPLS
    VP_TYPE_MSPW, // MS-PW
    VP_TYPE_VXLAN, // VXLAN
};


enum service_type {
	SERVICE_TYPE_DEBUG,
	SERVICE_TYPE_LSP,
	SERVICE_TYPE_L2VPN,
	SERVICE_TYPE_L3,
	SERVICE_TYPE_L2_NNI,
    //service_type_OAM,
};

