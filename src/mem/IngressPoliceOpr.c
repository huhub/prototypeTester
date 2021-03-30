/*
 * Software Development Kit for Fisilink
 * @file: IngressPoliceOpr.c
 * @description: C language expression for IngressPolice module
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>
#include <log/sdklog.h>
#include <common/strutil.h>
#include <common/regtbl.h>
#include <common/const.h>
#include <driver/readwrite.h>
#include <inttypes.h>
#include <mem/IngressPolice.h>


uint32_t printIngressPoliceTmpDsMemMac(char *fmtStr, void *data) {
    assert(data != NULL);
    assert(fmtStr != NULL);
    tDsMemMac *ptr = ((tDsMemMac *)data);
    sprintf(fmtStr, "IngressPoliceTmpDsMemMac : \n}\n");
    return strlen(fmtStr);
}

int32_t  readIngressPoliceTmpDsMemMac(tMemRegHdr *memPtr, uint32_t index, void *output) {
    assert(output != NULL);
    if(index >= memPtr->entryNum.entries) {
        sprintf(output, "ERROR: out of range IngressPoliceTmpDsMemMac, max %" PRIu64 " but %d\n", memPtr->entryNum.entries-1, index);
        return -1;
    }
    pthread_rwlock_rdlock(memPtr->rwLockList + index);
    tDsMemMac *ptr = ((tDsMemMac *)(memPtr->entryList)) + index;
    memcpy(output, ptr, sizeof(tDsMemMac));
    pthread_rwlock_unlock(memPtr->rwLockList + index);
    return memPtr->widthInQuad * sizeof(int);
}

int32_t fldSetIngressPoliceTmpDsMemMac(void *data, uint32_t nflds, char *flds[]) {
    tDsMemMac *ptr = (tDsMemMac *)data;
    int i      = 0;
    int num    = 0;
    int wrFlag = 0;
    char buf[128]       = {0};
    char *assignExpr[2] = {NULL};
    for (i = 0; i < nflds; i++) {
        strcpy(buf, *(flds + i));
        num = split(buf, "= ", assignExpr);
        if (num != 2) {
            servLogError("Illegal assignment expression [%s] in fldSet function.\r\n", *(flds + i));
        } else {
            } else {
                servLogWarn("Unknown field %s in IngressPoliceTmpDsMemMac.\r\n", *(flds + i));
            }
        }
    }
    return wrFlag;
}

uint32_t fldGetIngressPoliceTmpDsMemMac(tMemRegHdr *memPtr, uint32_t index, char *fldName, void *output, uint8_t fromWhere) {
    if(index >= memPtr->entryNum.entries) {
        sprintf(output, "ERROR: out of range IngressPoliceTmpDsMemMac, max %" PRIu64 " but %d\n", memPtr->entryNum.entries-1, index);
        return -1;
    }
    pthread_rwlock_rdlock(memPtr->rwLockList + index);
    tDsMemMac *ptr = ((tDsMemMac *)(memPtr->entryList)) + index;
#if NEED_ADDR == 1
    readHwEntry(ptr, memPtr, index, memPtr->widthInQuad, fromWhere);
#endif
    pthread_rwlock_unlock(memPtr->rwLockList + index);
    } else {
        servLogWarn("Unknown field %s in IngressPoliceTmpDsMemMac.\r\n", fldName);
    }
    return sizeof(int);
}

int32_t  writeIngressPoliceTmpDsMemMac(tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], void *output, uint8_t fromWhere) {
    if(index >= memPtr->entryNum.entries) {
        sprintf(output, "Error: Out of range IngressPoliceTmpDsMemMac, max %" PRIu64 " but %d in write function.\n", memPtr->entryNum.entries-1, index);
        return -1;
    }
    pthread_rwlock_wrlock(memPtr->rwLockList + index);
    tDsMemMac *ptr = ((tDsMemMac *)(memPtr->entryList)) + index;
#if NEED_ADDR == 1
    readHwEntry(ptr, memPtr, index, memPtr->widthInQuad, fromWhere);
#endif
    int modified = fldSetIngressPoliceTmpDsMemMac(ptr, parac, parav);
#if NEED_ADDR == 1
    if (modified == 1) {
        writeHwEntry(memPtr, index, ptr, memPtr->widthInQuad, fromWhere);
    }
#endif
    pthread_rwlock_unlock(memPtr->rwLockList + index);
    return sizeof(int);
}

int32_t setIngressPoliceTmpDsMemMac(tMemRegHdr *memPtr, uint32_t index, void *data, void *output, uint8_t fromWhere) {
    assert(data != NULL);
    if(index >= memPtr->entryNum.entries) { 
        sprintf(output, "Error: Out of range IngressPoliceTmpDsMemMac, max %" PRIu64 " but %d in set function\n", memPtr->entryNum.entries-1, index);
        return -1;
    }
    pthread_rwlock_wrlock(memPtr->rwLockList + index);
    memcpy(((tDsMemMac *)(memPtr->entryList)) + index, data, sizeof(tDsMemMac));
#if NEED_ADDR == 1
    writeHwEntry(memPtr, index, data, memPtr->widthInQuad, fromWhere);
#endif
    pthread_rwlock_unlock(memPtr->rwLockList + index);
    return sizeof(int);
}

int32_t resetIngressPoliceTmpDsMemMac(tMemRegHdr *memPtr, uint8_t chgData) {
    if(chgData) {
        if(memPtr->entryList != NULL) {
            free(memPtr->entryList);
        }
        tDsMemMac *ptr = (tDsMemMac *)calloc(sizeof(tDsMemMac), 1);
        assert(ptr != NULL);
        memPtr->entryList = ptr;
        if(memPtr->rwLockList != NULL) {
            free(memPtr->rwLockList);
        }
        pthread_rwlock_t *lockPtr = (pthread_rwlock_t *)calloc(sizeof(pthread_rwlock_t), 1);
        assert(lockPtr != NULL);
        pthread_rwlock_init(lockPtr,  NULL);
        memPtr->rwLockList = lockPtr;
    }

    if(memPtr->fldNameList != NULL) {
        free(memPtr->fldNameList);
    }
    char **strAry = (char **)calloc(1, sizeof(char *));
    assert(strAry != NULL);
    *(strAry+0)     = NULL;
    memPtr->fldNameList  = strAry;
    return 0;
}

int32_t destroyIngressPoliceTmpDsMemMac(tMemRegHdr *memPtr) {
    if(memPtr->entryList != NULL) {
        free(memPtr->entryList);
    }
    memPtr->entryList = NULL;
    if(memPtr->fldNameList != NULL) {
        free(memPtr->fldNameList);
    }
    memPtr->fldNameList = NULL;
    if(memPtr->rwLockList != NULL) {
        pthread_rwlock_destroy(memPtr->rwLockList);
    }
    memPtr->rwLockList = NULL;
    return 0;
}
