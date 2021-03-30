/*
 * Software Development Kit for Fisilink
 * @file: IngressPoliceOpr.h
 * @description: C language expression for IngressPolice module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __INGRESSPOLICE_OPR__
#define __INGRESSPOLICE_OPR__
#include <stdint.h>
#include <common/regtbl.h>

/** Read IngressPoliceTmpDsMemMac data from index to output */
int32_t  readIngressPoliceTmpDsMemMac    (tMemRegHdr *memPtr, uint32_t index, void *output, uint8_t fromWhere);
/** Set IngressPoliceTmpDsMemMac data from flds to data */
int32_t  fldSetIngressPoliceTmpDsMemMac  (void *data, uint32_t nflds, char *flds[]);
/** Get IngressPoliceTmpDsMemMac fldName data from index to output */
uint32_t fldGetIngressPoliceTmpDsMemMac  (tMemRegHdr *memPtr, uint32_t index,uint8_t *fldName, void *output, uint8_t fromWhere);
/** Write IngressPoliceTmpDsMemMac data at index from parav */
int32_t  writeIngressPoliceTmpDsMemMac   (tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], void *output, uint8_t fromWhere);
/** Set data to IngressPoliceTmpDsMemMac at index */
int32_t  setIngressPoliceTmpDsMemMac     (tMemRegHdr *memPtr, uint32_t index, void *data, void *output, uint8_t fromWhere);
/** Print IngressPoliceTmpDsMemMac data to data */
uint32_t printIngressPoliceTmpDsMemMac   (char *fmtStr, void *data);
/** Reset IngressPoliceTmpDsMemMac to default data */
int32_t  resetIngressPoliceTmpDsMemMac   (tMemRegHdr *memPtr, uint8_t flag);
/** Destroy IngressPoliceTmpDsMemMac allocated memory when exit */
int32_t  destroyIngressPoliceTmpDsMemMac (tMemRegHdr *memPtr);

#endif
