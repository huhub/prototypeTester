#! /usr/bin/python3
BaseAddrDict = {
    'IgrHdrAdj' : 0x60000000,
    'IgrVc'     : 0x64000000,
    'IgrIntf'   : 0x68000000,
    'IgrLkup'   : 0x6c000000,
    'IgrLearn'  : 0x70000000,
    'IgrPktProc': 0x74000000,
    'IgrMeter'  : 0x78000000,
    'IgrFwd'    : 0x7c000000,
    'IgrRcvy'   : 0x7c800000,
    'IgrAging'  : 0x7d000000,
    'IgrPpShare': 0x7d800000,
    'IgrParser' : 0x7e000000,
    'TcamKey'   : 0x7e800000,
    'Tcam'      : 0x7e800000,
    'Egr'       : 0x80000000,
    'Config'    : 0x00000000, 
    'IrqCtrl'   : 0x01000000, 
    'MdioWrap'  : 0x02000000, 
    'CpuGmac'   : 0x03000000,
    'Mac4CtrlV20' : 0x20000000, 'Mac4CtrlV21' : 0x20080000, 'Mac4CtrlV22' : 0x20100000, 'Mac4CtrlV23' : 0x20180000,
    'Mac4CtrlV24' : 0x20200000, 'Mac4CtrlV25' : 0x20280000, 
    'QGmac0'    : 0x20050000, 'QGmac1'    : 0x200d0000, 'QGmac2'    : 0x20150000, 'QGmac3'    : 0x201d0000, 
    'QGmac4'    : 0x20250000, 'QGmac5'    : 0x202d0000,
    'Gmac0'     : 0x20010000, 'Gmac1'     : 0x20020000, 'Gmac2'     : 0x20030000, 'Gmac3'     : 0x20040000,
    'Gmac4'     : 0x20090000, 'Gmac5'     : 0x200a0000, 'Gmac6'     : 0x200b0000, 'Gmac7'     : 0x200c0000,
    'Gmac8'     : 0x20110000, 'Gmac9'     : 0x20120000, 'Gmac10'    : 0x20130000, 'Gmac11'    : 0x20140000,
    'Gmac12'    : 0x20190000, 'Gmac13'    : 0x201a0000, 'Gmac14'    : 0x201b0000, 'Gmac15'    : 0x201c0000,
    'Gmac16'    : 0x20210000, 'Gmac17'    : 0x20220000, 'Gmac18'    : 0x20230000, 'Gmac19'    : 0x20240000,
    'Gmac20'    : 0x20290000, 'Gmac21'    : 0x202a0000, 'Gmac22'    : 0x202b0000, 'Gmac23'    : 0x202c0000,
    'MiscCtrl'  : 0x20300000,
    'Xgmac0'    : 0x20400000, 'Xgmac1'    : 0x20500000, 'Xgmac2'    : 0x20600000, 'Xgmac3'    : 0x20700000,
    'RxTdm'     : 0x21000000,
    'TxTdmV2'   : 0x22000000,
    'TmWrite'   : 0x40000000,
    'TmAdm'     : 0x40080000,
    'TmRep'     : 0x40100000,
    'TmRead'    : 0x40180000,
    'TmSch'     : 0x40200000,
    'PktBuffer' : 0x40280000,
    'Ptp'       : 0xa0000000,
    'Serdes'    : 0xc0000000,
}

MemRegNumDict = { 'Mac4CtrlV2'  : 6, 'Gmac' : 24, 'QGmac' : 6, 'Xgmac' : 4, }

CrcDict = {
    'CRC8_D48' : 'crc_8',
    'nextCRC8_D48' : 'crc_8',
    'nextCRC8_D64' : 'crc_8',
    'nextCRC8_D136' : 'crc8',
    'nextCRC16_D64' : 'crc_ccitt_ffff',
    'nextCRC16_D136' : 'crc_ccitt_ffff',
    'nextCRC32_D64' : 'crc_32',
}
    
TblDict = {
    'DsMemAclTsn'              : 'DsMemTsnHandle',
    'DsMemHostRouteLeft'       : 'DsMemRoute',
    'DsMemHostRouteRight'      : 'DsMemRoute',
    'DsMemHostRoute'           : 'DsMemRoute',
    'DsMemHostRouteLeftKey'    : 'DsMemHostRouteKey',
    'DsMemHostRouteRightKey'   : 'DsMemHostRouteKey',
    'DsMemHostRouteLeftValid'  : 'DsMemHostRouteValid',
    'DsMemHostRouteRightValid' : 'DsMemHostRouteValid',
    'DsMemHostTsnLeft'         : 'DsMemTsnHandle',
    'DsMemHostTsnRight'        : 'DsMemTsnHandle',
    'DsMemHostTsn'             : 'DsMemTsnHandle',
    'DsMemRouteTsn'            : 'DsMemTsnHandle',
    'DsMemMacAgingLeft'        : 'DsMemMacAging', 
    'DsMemMacAgingRight'       : 'DsMemMacAging', 
    'DsMemMacKeyLeft'          : 'DsMemMacKey',
    'DsMemMacKeyRight'         : 'DsMemMacKey',
    'DsMemMacLeft'             : 'DsMemMac',
    'DsMemMacRight'            : 'DsMemMac',
    'TmpDsMemMac'              : 'DsMemMac',
    'DsMemMacStaticLeft'       : 'DsMemMacStatic',
    'DsMemMacStaticRight'      : 'DsMemMacStatic',
    'DsMemMacTsnLeft'          : 'DsMemTsnHandle',
    'DsMemMacTsnRight'         : 'DsMemTsnHandle',
    'DsMemMacTsn'              : 'DsMemTsnHandle',
    'DsMemMacValidLeft'        : 'DsMemMacValid',
    'DsMemMacValidRight'       : 'DsMemMacValid',
    'DsMemFlowColorStats'      : 'DsMemColorStats',
    'DsMemPortColorStats'      : 'DsMemColorStats',
    'DsMemFlowPolice'          : 'DsMemPolice',
    'DsMemPortPolice'          : 'DsMemPolice',
    'DsMemFlowPoliceCfg'       : 'DsMemPoliceCfg',
    'DsMemPortPoliceCfg'       : 'DsMemPoliceCfg',
    'DsMemIndvRcvyCfg'         : 'DsMemRcvyCfg',
    'DsMemStreamRcvyCfg'       : 'DsMemRcvyCfg',
    'DsMemIndvRcvyCnt'         : 'DsMemRcvyCnt',
    'DsMemStreamRcvyCnt'       : 'DsMemRcvyCnt',
    'DsMemIndvRcvySeq'         : 'DsMemRcvySeq',
    'DsMemStreamRcvySeq'       : 'DsMemRcvySeq',
    'MsgAdmInfo0'              : 'MsgAdmInfo'
}

global ModuleList
ModuleList = ['HeaderAdjust', 'PacketParser', 'VlanLookup', 'Interface', 'LookupManage', 'PacketProcess', 'IngressPolice', 'Redundancy', 'DestPost', 'TrafficManage', 'PacketEdit']

global PpRegList
PpRegList = [module+'Reg.txt' for module in ModuleList]
