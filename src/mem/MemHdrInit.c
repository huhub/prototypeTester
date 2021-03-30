/*
 * Software Development Kit for Fisilink
 * @file: MemHdrInit.c
 * @description: C language expression for MemHdrInit module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <log/sdklog.h>
#include <common/rbmem.h>
#include <mem/ModuleInit.h>

int memHdrInit() {
	struct rb_root *root = initMemRoot();
	if (insertHeaderAdjustHdr(root) < 0) {
		servLogError("HeaderAdjust Memory initialization failed.\r\n");
		return -1;
	}
	if (insertPacketParserHdr(root) < 0) {
		servLogError("PacketParser Memory initialization failed.\r\n");
		return -1;
	}
	if (insertVlanLookupHdr(root) < 0) {
		servLogError("VlanLookup Memory initialization failed.\r\n");
		return -1;
	}
	if (insertInterfaceHdr(root) < 0) {
		servLogError("Interface Memory initialization failed.\r\n");
		return -1;
	}
	if (insertLookupManageHdr(root) < 0) {
		servLogError("LookupManage Memory initialization failed.\r\n");
		return -1;
	}
	if (insertPacketProcessHdr(root) < 0) {
		servLogError("PacketProcess Memory initialization failed.\r\n");
		return -1;
	}
	if (insertIngressPoliceHdr(root) < 0) {
		servLogError("IngressPolice Memory initialization failed.\r\n");
		return -1;
	}
	if (insertRedundancyHdr(root) < 0) {
		servLogError("Redundancy Memory initialization failed.\r\n");
		return -1;
	}
	if (insertDestPostHdr(root) < 0) {
		servLogError("DestPost Memory initialization failed.\r\n");
		return -1;
	}
	if (insertTrafficManageHdr(root) < 0) {
		servLogError("TrafficManage Memory initialization failed.\r\n");
		return -1;
	}
	if (insertPacketEditHdr(root) < 0) {
		servLogError("PacketEdit Memory initialization failed.\r\n");
		return -1;
	}
	if (insertMac4CtrlV20Hdr(root) < 0) {
		servLogError("Mac4CtrlV20 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertMac4CtrlV21Hdr(root) < 0) {
		servLogError("Mac4CtrlV21 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertMac4CtrlV22Hdr(root) < 0) {
		servLogError("Mac4CtrlV22 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertMac4CtrlV23Hdr(root) < 0) {
		servLogError("Mac4CtrlV23 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertMac4CtrlV24Hdr(root) < 0) {
		servLogError("Mac4CtrlV24 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertMac4CtrlV25Hdr(root) < 0) {
		servLogError("Mac4CtrlV25 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac0Hdr(root) < 0) {
		servLogError("Gmac0 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac1Hdr(root) < 0) {
		servLogError("Gmac1 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac2Hdr(root) < 0) {
		servLogError("Gmac2 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac3Hdr(root) < 0) {
		servLogError("Gmac3 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac4Hdr(root) < 0) {
		servLogError("Gmac4 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac5Hdr(root) < 0) {
		servLogError("Gmac5 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac6Hdr(root) < 0) {
		servLogError("Gmac6 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac7Hdr(root) < 0) {
		servLogError("Gmac7 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac8Hdr(root) < 0) {
		servLogError("Gmac8 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac9Hdr(root) < 0) {
		servLogError("Gmac9 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac10Hdr(root) < 0) {
		servLogError("Gmac10 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac11Hdr(root) < 0) {
		servLogError("Gmac11 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac12Hdr(root) < 0) {
		servLogError("Gmac12 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac13Hdr(root) < 0) {
		servLogError("Gmac13 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac14Hdr(root) < 0) {
		servLogError("Gmac14 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac15Hdr(root) < 0) {
		servLogError("Gmac15 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac16Hdr(root) < 0) {
		servLogError("Gmac16 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac17Hdr(root) < 0) {
		servLogError("Gmac17 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac18Hdr(root) < 0) {
		servLogError("Gmac18 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac19Hdr(root) < 0) {
		servLogError("Gmac19 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac20Hdr(root) < 0) {
		servLogError("Gmac20 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac21Hdr(root) < 0) {
		servLogError("Gmac21 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac22Hdr(root) < 0) {
		servLogError("Gmac22 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertGmac23Hdr(root) < 0) {
		servLogError("Gmac23 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertQGmac0Hdr(root) < 0) {
		servLogError("QGmac0 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertQGmac1Hdr(root) < 0) {
		servLogError("QGmac1 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertQGmac2Hdr(root) < 0) {
		servLogError("QGmac2 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertQGmac3Hdr(root) < 0) {
		servLogError("QGmac3 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertQGmac4Hdr(root) < 0) {
		servLogError("QGmac4 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertQGmac5Hdr(root) < 0) {
		servLogError("QGmac5 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertXgmac0Hdr(root) < 0) {
		servLogError("Xgmac0 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertXgmac1Hdr(root) < 0) {
		servLogError("Xgmac1 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertXgmac2Hdr(root) < 0) {
		servLogError("Xgmac2 Memory initialization failed.\r\n");
		return -1;
	}
	if (insertXgmac3Hdr(root) < 0) {
		servLogError("Xgmac3 Memory initialization failed.\r\n");
		return -1;
	}
	return 0;
}
