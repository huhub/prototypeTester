/*
 * Software Development Kit for Fisilink
 * @file: LookupManageOpr.h
 * @description: C language expression for LookupManage module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __LOOKUPMANAGE_OPR__
#define __LOOKUPMANAGE_OPR__
#include <stdint.h>
#include <common/regtbl.h>

/** Read LookupManageTmpDsMemMac data from index to output */
int32_t  readLookupManageTmpDsMemMac    (tMemRegHdr *memPtr, uint32_t index, void *output, uint8_t fromWhere);
/** Set LookupManageTmpDsMemMac data from flds to data */
int32_t  fldSetLookupManageTmpDsMemMac  (void *data, uint32_t nflds, char *flds[]);
/** Get LookupManageTmpDsMemMac fldName data from index to output */
uint32_t fldGetLookupManageTmpDsMemMac  (tMemRegHdr *memPtr, uint32_t index,uint8_t *fldName, void *output, uint8_t fromWhere);
/** Write LookupManageTmpDsMemMac data at index from parav */
int32_t  writeLookupManageTmpDsMemMac   (tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], void *output, uint8_t fromWhere);
/** Set data to LookupManageTmpDsMemMac at index */
int32_t  setLookupManageTmpDsMemMac     (tMemRegHdr *memPtr, uint32_t index, void *data, void *output, uint8_t fromWhere);
/** Print LookupManageTmpDsMemMac data to data */
uint32_t printLookupManageTmpDsMemMac   (char *fmtStr, void *data);
/** Reset LookupManageTmpDsMemMac to default data */
int32_t  resetLookupManageTmpDsMemMac   (tMemRegHdr *memPtr, uint8_t flag);
/** Destroy LookupManageTmpDsMemMac allocated memory when exit */
int32_t  destroyLookupManageTmpDsMemMac (tMemRegHdr *memPtr);

#endif
