/*
 * Software Development Kit for Fisilink
 * @file: PacketParserOpr.h
 * @description: C language expression for PacketParser module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __PACKETPARSER_OPR__
#define __PACKETPARSER_OPR__
#include <stdint.h>
#include <common/regtbl.h>

/** Read PacketParserTmpDsMemMac data from index to output */
int32_t  readPacketParserTmpDsMemMac    (tMemRegHdr *memPtr, uint32_t index, void *output, uint8_t fromWhere);
/** Set PacketParserTmpDsMemMac data from flds to data */
int32_t  fldSetPacketParserTmpDsMemMac  (void *data, uint32_t nflds, char *flds[]);
/** Get PacketParserTmpDsMemMac fldName data from index to output */
uint32_t fldGetPacketParserTmpDsMemMac  (tMemRegHdr *memPtr, uint32_t index,uint8_t *fldName, void *output, uint8_t fromWhere);
/** Write PacketParserTmpDsMemMac data at index from parav */
int32_t  writePacketParserTmpDsMemMac   (tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], void *output, uint8_t fromWhere);
/** Set data to PacketParserTmpDsMemMac at index */
int32_t  setPacketParserTmpDsMemMac     (tMemRegHdr *memPtr, uint32_t index, void *data, void *output, uint8_t fromWhere);
/** Print PacketParserTmpDsMemMac data to data */
uint32_t printPacketParserTmpDsMemMac   (char *fmtStr, void *data);
/** Reset PacketParserTmpDsMemMac to default data */
int32_t  resetPacketParserTmpDsMemMac   (tMemRegHdr *memPtr, uint8_t flag);
/** Destroy PacketParserTmpDsMemMac allocated memory when exit */
int32_t  destroyPacketParserTmpDsMemMac (tMemRegHdr *memPtr);

#endif
