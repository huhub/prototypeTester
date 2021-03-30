/*
 * Software Development Kit for Fisilink
 * @file: HeaderAdjustOpr.h
 * @description: C language expression for HeaderAdjust module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __HEADERADJUST_OPR__
#define __HEADERADJUST_OPR__
#include <stdint.h>
#include <common/regtbl.h>

/** Read TmpDsMemMac data from index to output */
int32_t  readTmpDsMemMac    (tMemRegHdr *memPtr, uint32_t index, void *output, uint8_t fromWhere);
/** Set TmpDsMemMac data from flds to data */
int32_t  fldSetTmpDsMemMac  (void *data, uint32_t nflds, char *flds[]);
/** Get TmpDsMemMac fldName data from index to output */
uint32_t fldGetTmpDsMemMac  (tMemRegHdr *memPtr, uint32_t index,uint8_t *fldName, void *output, uint8_t fromWhere);
/** Write TmpDsMemMac data at index from parav */
int32_t  writeTmpDsMemMac   (tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], void *output, uint8_t fromWhere);
/** Set data to TmpDsMemMac at index */
int32_t  setTmpDsMemMac     (tMemRegHdr *memPtr, uint32_t index, void *data, void *output, uint8_t fromWhere);
/** Print TmpDsMemMac data to data */
uint32_t printTmpDsMemMac   (char *fmtStr, void *data);
/** Reset TmpDsMemMac to default data */
int32_t  resetTmpDsMemMac   (tMemRegHdr *memPtr, uint8_t flag);
/** Destroy TmpDsMemMac allocated memory when exit */
int32_t  destroyTmpDsMemMac (tMemRegHdr *memPtr);

#endif
