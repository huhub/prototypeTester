/*
 * Software Development Kit for Fisilink
 * @file: RedundancyOpr.h
 * @description: C language expression for Redundancy module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __REDUNDANCY_OPR__
#define __REDUNDANCY_OPR__
#include <stdint.h>
#include <common/regtbl.h>

/** Read RedundancyTmpDsMemMac data from index to output */
int32_t  readRedundancyTmpDsMemMac    (tMemRegHdr *memPtr, uint32_t index, void *output, uint8_t fromWhere);
/** Set RedundancyTmpDsMemMac data from flds to data */
int32_t  fldSetRedundancyTmpDsMemMac  (void *data, uint32_t nflds, char *flds[]);
/** Get RedundancyTmpDsMemMac fldName data from index to output */
uint32_t fldGetRedundancyTmpDsMemMac  (tMemRegHdr *memPtr, uint32_t index,uint8_t *fldName, void *output, uint8_t fromWhere);
/** Write RedundancyTmpDsMemMac data at index from parav */
int32_t  writeRedundancyTmpDsMemMac   (tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], void *output, uint8_t fromWhere);
/** Set data to RedundancyTmpDsMemMac at index */
int32_t  setRedundancyTmpDsMemMac     (tMemRegHdr *memPtr, uint32_t index, void *data, void *output, uint8_t fromWhere);
/** Print RedundancyTmpDsMemMac data to data */
uint32_t printRedundancyTmpDsMemMac   (char *fmtStr, void *data);
/** Reset RedundancyTmpDsMemMac to default data */
int32_t  resetRedundancyTmpDsMemMac   (tMemRegHdr *memPtr, uint8_t flag);
/** Destroy RedundancyTmpDsMemMac allocated memory when exit */
int32_t  destroyRedundancyTmpDsMemMac (tMemRegHdr *memPtr);

#endif
