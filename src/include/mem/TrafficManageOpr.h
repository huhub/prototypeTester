/*
 * Software Development Kit for Fisilink
 * @file: TrafficManageOpr.h
 * @description: C language expression for TrafficManage module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __TRAFFICMANAGE_OPR__
#define __TRAFFICMANAGE_OPR__
#include <stdint.h>
#include <common/regtbl.h>

/** Read TrafficManageTmpDsMemMac data from index to output */
int32_t  readTrafficManageTmpDsMemMac    (tMemRegHdr *memPtr, uint32_t index, void *output, uint8_t fromWhere);
/** Set TrafficManageTmpDsMemMac data from flds to data */
int32_t  fldSetTrafficManageTmpDsMemMac  (void *data, uint32_t nflds, char *flds[]);
/** Get TrafficManageTmpDsMemMac fldName data from index to output */
uint32_t fldGetTrafficManageTmpDsMemMac  (tMemRegHdr *memPtr, uint32_t index,uint8_t *fldName, void *output, uint8_t fromWhere);
/** Write TrafficManageTmpDsMemMac data at index from parav */
int32_t  writeTrafficManageTmpDsMemMac   (tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], void *output, uint8_t fromWhere);
/** Set data to TrafficManageTmpDsMemMac at index */
int32_t  setTrafficManageTmpDsMemMac     (tMemRegHdr *memPtr, uint32_t index, void *data, void *output, uint8_t fromWhere);
/** Print TrafficManageTmpDsMemMac data to data */
uint32_t printTrafficManageTmpDsMemMac   (char *fmtStr, void *data);
/** Reset TrafficManageTmpDsMemMac to default data */
int32_t  resetTrafficManageTmpDsMemMac   (tMemRegHdr *memPtr, uint8_t flag);
/** Destroy TrafficManageTmpDsMemMac allocated memory when exit */
int32_t  destroyTrafficManageTmpDsMemMac (tMemRegHdr *memPtr);

#endif
