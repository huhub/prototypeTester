/*
 * Software Development Kit for Fisilink
 * @file: PacketProcessOpr.h
 * @description: C language expression for PacketProcess module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __PACKETPROCESS_OPR__
#define __PACKETPROCESS_OPR__
#include <stdint.h>
#include <common/regtbl.h>

/** Read PacketProcessTmpDsMemMac data from index to output */
int32_t  readPacketProcessTmpDsMemMac    (tMemRegHdr *memPtr, uint32_t index, void *output, uint8_t fromWhere);
/** Set PacketProcessTmpDsMemMac data from flds to data */
int32_t  fldSetPacketProcessTmpDsMemMac  (void *data, uint32_t nflds, char *flds[]);
/** Get PacketProcessTmpDsMemMac fldName data from index to output */
uint32_t fldGetPacketProcessTmpDsMemMac  (tMemRegHdr *memPtr, uint32_t index,uint8_t *fldName, void *output, uint8_t fromWhere);
/** Write PacketProcessTmpDsMemMac data at index from parav */
int32_t  writePacketProcessTmpDsMemMac   (tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], void *output, uint8_t fromWhere);
/** Set data to PacketProcessTmpDsMemMac at index */
int32_t  setPacketProcessTmpDsMemMac     (tMemRegHdr *memPtr, uint32_t index, void *data, void *output, uint8_t fromWhere);
/** Print PacketProcessTmpDsMemMac data to data */
uint32_t printPacketProcessTmpDsMemMac   (char *fmtStr, void *data);
/** Reset PacketProcessTmpDsMemMac to default data */
int32_t  resetPacketProcessTmpDsMemMac   (tMemRegHdr *memPtr, uint8_t flag);
/** Destroy PacketProcessTmpDsMemMac allocated memory when exit */
int32_t  destroyPacketProcessTmpDsMemMac (tMemRegHdr *memPtr);

#endif
