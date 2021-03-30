/*
 * Software Development Kit for Fisilink
 * @file: PacketEditOpr.h
 * @description: C language expression for PacketEdit module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __PACKETEDIT_OPR__
#define __PACKETEDIT_OPR__
#include <stdint.h>
#include <common/regtbl.h>

/** Read PacketEditTmpDsMemMac data from index to output */
int32_t  readPacketEditTmpDsMemMac    (tMemRegHdr *memPtr, uint32_t index, void *output, uint8_t fromWhere);
/** Set PacketEditTmpDsMemMac data from flds to data */
int32_t  fldSetPacketEditTmpDsMemMac  (void *data, uint32_t nflds, char *flds[]);
/** Get PacketEditTmpDsMemMac fldName data from index to output */
uint32_t fldGetPacketEditTmpDsMemMac  (tMemRegHdr *memPtr, uint32_t index,uint8_t *fldName, void *output, uint8_t fromWhere);
/** Write PacketEditTmpDsMemMac data at index from parav */
int32_t  writePacketEditTmpDsMemMac   (tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], void *output, uint8_t fromWhere);
/** Set data to PacketEditTmpDsMemMac at index */
int32_t  setPacketEditTmpDsMemMac     (tMemRegHdr *memPtr, uint32_t index, void *data, void *output, uint8_t fromWhere);
/** Print PacketEditTmpDsMemMac data to data */
uint32_t printPacketEditTmpDsMemMac   (char *fmtStr, void *data);
/** Reset PacketEditTmpDsMemMac to default data */
int32_t  resetPacketEditTmpDsMemMac   (tMemRegHdr *memPtr, uint8_t flag);
/** Destroy PacketEditTmpDsMemMac allocated memory when exit */
int32_t  destroyPacketEditTmpDsMemMac (tMemRegHdr *memPtr);

#endif
