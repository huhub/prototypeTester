/*
 * Software Development Kit for Fisilink
 * @file: InterfaceOpr.h
 * @description: C language expression for Interface module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __INTERFACE_OPR__
#define __INTERFACE_OPR__
#include <stdint.h>
#include <common/regtbl.h>

/** Read InterfaceTmpDsMemMac data from index to output */
int32_t  readInterfaceTmpDsMemMac    (tMemRegHdr *memPtr, uint32_t index, void *output, uint8_t fromWhere);
/** Set InterfaceTmpDsMemMac data from flds to data */
int32_t  fldSetInterfaceTmpDsMemMac  (void *data, uint32_t nflds, char *flds[]);
/** Get InterfaceTmpDsMemMac fldName data from index to output */
uint32_t fldGetInterfaceTmpDsMemMac  (tMemRegHdr *memPtr, uint32_t index,uint8_t *fldName, void *output, uint8_t fromWhere);
/** Write InterfaceTmpDsMemMac data at index from parav */
int32_t  writeInterfaceTmpDsMemMac   (tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], void *output, uint8_t fromWhere);
/** Set data to InterfaceTmpDsMemMac at index */
int32_t  setInterfaceTmpDsMemMac     (tMemRegHdr *memPtr, uint32_t index, void *data, void *output, uint8_t fromWhere);
/** Print InterfaceTmpDsMemMac data to data */
uint32_t printInterfaceTmpDsMemMac   (char *fmtStr, void *data);
/** Reset InterfaceTmpDsMemMac to default data */
int32_t  resetInterfaceTmpDsMemMac   (tMemRegHdr *memPtr, uint8_t flag);
/** Destroy InterfaceTmpDsMemMac allocated memory when exit */
int32_t  destroyInterfaceTmpDsMemMac (tMemRegHdr *memPtr);

#endif
