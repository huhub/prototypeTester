/*
 * Software Development Kit for Fisilink
 * @file: VlanLookupOpr.h
 * @description: C language expression for VlanLookup module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __VLANLOOKUP_OPR__
#define __VLANLOOKUP_OPR__
#include <stdint.h>
#include <common/regtbl.h>

/** Read VlanLookupTmpDsMemMac data from index to output */
int32_t  readVlanLookupTmpDsMemMac    (tMemRegHdr *memPtr, uint32_t index, void *output, uint8_t fromWhere);
/** Set VlanLookupTmpDsMemMac data from flds to data */
int32_t  fldSetVlanLookupTmpDsMemMac  (void *data, uint32_t nflds, char *flds[]);
/** Get VlanLookupTmpDsMemMac fldName data from index to output */
uint32_t fldGetVlanLookupTmpDsMemMac  (tMemRegHdr *memPtr, uint32_t index,uint8_t *fldName, void *output, uint8_t fromWhere);
/** Write VlanLookupTmpDsMemMac data at index from parav */
int32_t  writeVlanLookupTmpDsMemMac   (tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], void *output, uint8_t fromWhere);
/** Set data to VlanLookupTmpDsMemMac at index */
int32_t  setVlanLookupTmpDsMemMac     (tMemRegHdr *memPtr, uint32_t index, void *data, void *output, uint8_t fromWhere);
/** Print VlanLookupTmpDsMemMac data to data */
uint32_t printVlanLookupTmpDsMemMac   (char *fmtStr, void *data);
/** Reset VlanLookupTmpDsMemMac to default data */
int32_t  resetVlanLookupTmpDsMemMac   (tMemRegHdr *memPtr, uint8_t flag);
/** Destroy VlanLookupTmpDsMemMac allocated memory when exit */
int32_t  destroyVlanLookupTmpDsMemMac (tMemRegHdr *memPtr);

#endif
