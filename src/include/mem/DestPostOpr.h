/*
 * Software Development Kit for Fisilink
 * @file: DestPostOpr.h
 * @description: C language expression for DestPost module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __DESTPOST_OPR__
#define __DESTPOST_OPR__
#include <stdint.h>
#include <common/regtbl.h>

/** Read DestPostTmpDsMemMac data from index to output */
int32_t  readDestPostTmpDsMemMac    (tMemRegHdr *memPtr, uint32_t index, void *output, uint8_t fromWhere);
/** Set DestPostTmpDsMemMac data from flds to data */
int32_t  fldSetDestPostTmpDsMemMac  (void *data, uint32_t nflds, char *flds[]);
/** Get DestPostTmpDsMemMac fldName data from index to output */
uint32_t fldGetDestPostTmpDsMemMac  (tMemRegHdr *memPtr, uint32_t index,uint8_t *fldName, void *output, uint8_t fromWhere);
/** Write DestPostTmpDsMemMac data at index from parav */
int32_t  writeDestPostTmpDsMemMac   (tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], void *output, uint8_t fromWhere);
/** Set data to DestPostTmpDsMemMac at index */
int32_t  setDestPostTmpDsMemMac     (tMemRegHdr *memPtr, uint32_t index, void *data, void *output, uint8_t fromWhere);
/** Print DestPostTmpDsMemMac data to data */
uint32_t printDestPostTmpDsMemMac   (char *fmtStr, void *data);
/** Reset DestPostTmpDsMemMac to default data */
int32_t  resetDestPostTmpDsMemMac   (tMemRegHdr *memPtr, uint8_t flag);
/** Destroy DestPostTmpDsMemMac allocated memory when exit */
int32_t  destroyDestPostTmpDsMemMac (tMemRegHdr *memPtr);

#endif
