#! /usr/bin/python3 
AccessType = {
    'Spi' : 'eMEM_DIRECT',
}

import re
import os
from database import *
from functools import cmp_to_key

def fldCmp(x, y):
    ret = 0
    if x.offset == y.offset:
        if x.loBit > y.loBit:
            ret = 1
        elif x.loBit < y.loBit:
            ret = -1
    else:
        if x.offset > y.offset:
            ret = 1
        elif x.offset < y.offset:
            ret = -1
    return ret

def getStructTypeByName(name, defaulttype):
    type = TblDict.get(name, defaulttype)
    type = re.sub(r'Ctl\w+InOutStat', 'CtlInOutStat', type)
    type = re.sub(r'Ctl\w+Interrupt', 'CtlInterrupt', type)
    return type

def generateFileComment(filehdl, name, suffix):
    filehdl.write('/*\n * Software Development Kit for Fisilink\n * @file: {0}{1}\n * @description: C language expression for {0} module\n * @note: Copyright (C) 2020 \n *\n * You should have received a copy of the Fisilink License\n * along with this program; if not, write to Fisilink\n */\n\n\n'.format(name, suffix))

def generateDiffCode(hdrPath, libPath, origin, module, descDict):
    # module c file
    with open(os.path.join(libPath, '{0}.c'.format(module)), 'w') as wrCfile: 
        generateFileComment(wrCfile, module, '.c')
        wrCfile.write('#include <stdlib.h>\n#include <assert.h>\n#include <common/hash.h>\n#include <common/rbmem.h>\n#include <mem/{0}Opr.h>\n\n\n'.format(origin))
        wrCfile.write('int insert{0}Hdr(struct rb_root *root) {{\n    tMemRegHdr *hdr = NULL;\n'.format(module))
        cContent       = ''
        # go throuth all reg/mem fields
        for k in sorted(descDict.keys()):
            v         = descDict.get(k)
            name      = ChangedMemReg.get('{0}_{1}'.format(origin, k), k)
            # module c file
            cContent += '    hdr = NULL;\n    hdr = (tMemRegHdr *)calloc(sizeof(tMemRegHdr), 1);\n    assert(hdr != NULL);\n'
            if origin == module:
                cContent += '    hdr->uid           = jsHash("{0}");\n    hdr->name          = "{0}";\n'.format(name)
            else:
                cContent += '    hdr->uid           = jsHash("{0}{1}");\n    hdr->name          = "{0}{1}";\n'.format(module, k)
            typeStr = AccessType.get(module, 'eMEM_INDIRECT')
            cContent += '    hdr->type          = {0};\n'.format(typeStr)
            cContent += '    hdr->widthInQuad   = {0:d};\n'.format(v.width)
            cContent += '    hdr->granularity   = roundupPow2({0:d});\n'.format(v.width)
            cContent += '    hdr->entryNum.entries    = {0:d};\n'.format(v.depth)
            cContent += '    hdr->addrBase.linearAddr = {0:#x};\n'.format(v.address + BaseAddrDict.get(module, 0xff000000))
            cContent += '    hdr->entryList     = NULL;\n    hdr->fldNameList   = NULL;\n    hdr->rwLockList    = NULL;\n'
            cContent += '    hdr->read          = read{0};\n    hdr->write         = write{0};\n    hdr->set           = set{0};\n    hdr->fldSet        = fldSet{0};\n    hdr->fldGet        = fldGet{0};\n    hdr->print         = print{0};\n    hdr->reset         = reset{0};\n    hdr->destroy       = destroy{0};\n'.format(name)
            cContent += '    insertMem(root, hdr);\n\n'
        # module c file
        wrCfile.write(cContent)
        wrCfile.write('\n    return 0;\n} //End of mem init\n')

RegMemNameList = []   # It is used for solving same Mem/Reg name defined in different files
ChangedMemReg  = {}
def generateCommonCode(hdrPath, libPath, module, descDict):
    inFileStruct   = []
    with open(os.path.join(hdrPath, '{0}.h'.format(module)), mode='w') as wrHfile:
        generateFileComment(wrHfile, module, '.h')
        wrHfile.write('#ifndef __{0}_REG__\n#define __{0}_REG__\n#include <stdint.h>\n\n'.format(module.upper()))
        hContent       = ''
        for k in sorted(descDict.keys()):
            v            = descDict.get(k)
            if k in RegMemNameList:         # RegMemName had appeared in advance
                name     = '{0}{1}'.format(module, k)
                ChangedMemReg['{0}_{1}'.format(module, k)] = name
            else: 
                name     = k
                RegMemNameList.append(k)
            typeName     = TblDict.get(k, name)
            if typeName not in inFileStruct:
                hContent += '/** Define C structure for {0} */\n'.format(typeName)
                hContent += 'typedef struct {0} {{\n'.format(typeName)
                # sorted for out-order fields description
                wordOf   = 0
                curBit   = 0
                for fld in sorted(v.getFldList(), key=cmp_to_key(fldCmp)):
                    if wordOf == fld.offset and curBit != fld.loBit:        # there is empty gap in same word
                        hContent += '    uint32_t {0:20} : {1};    ///< Reserved gap 0\n'.format('', fld.loBit - curBit)
                    elif wordOf != fld.offset and curBit > 0:              # there is empty gap between words
                        hContent += '    uint32_t {0:20} : {1};    ///< Reserved gap 1\n'.format('', 32 - curBit)
                    hContent += '    uint32_t {0:20} : {1};    ///< {2}\n'.format(fld.name, fld.width, fld.description)
                    curBit   = (fld.hiBit + 1) & 0x1f
                    wordOf   = fld.offset
                hContent += '}} __attribute__((aligned(sizeof(int)))) t{0};\n\n'.format(typeName)
                inFileStruct.append(typeName)
        wrHfile.write(hContent)
        wrHfile.write('#endif\n'.format(module))

    # Opr header file
    with open(os.path.join(hdrPath, '{0}Opr.h'.format(module)), mode='w') as wrOprHfile:
        generateFileComment(wrOprHfile, module, 'Opr.h')
        wrOprHfile.write('#ifndef __{0}_OPR__\n#define __{0}_OPR__\n#include <stdint.h>\n#include <common/regtbl.h>\n\n'.format(module.upper()))
        oprHContent    = ''
        # Opr header file
        oprHContent += '/** Read {0} data from index to output */\nint32_t  read{0}    (tMemRegHdr *memPtr, uint32_t index, void *output, uint8_t fromWhere);\n'.format(name)
        oprHContent += '/** Set {0} data from flds to data */\nint32_t  fldSet{0}  (void *data, uint32_t nflds, char *flds[]);\n'.format(name)
        oprHContent += '/** Get {0} fldName data from index to output */\nuint32_t fldGet{0}  (tMemRegHdr *memPtr, uint32_t index,uint8_t *fldName, void *output, uint8_t fromWhere);\n'.format(name)
        oprHContent += '/** Write {0} data at index from parav */\nint32_t  write{0}   (tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], void *output, uint8_t fromWhere);\n'.format(name)
        oprHContent += '/** Set data to {0} at index */\nint32_t  set{0}     (tMemRegHdr *memPtr, uint32_t index, void *data, void *output, uint8_t fromWhere);\n'.format(name)
        oprHContent += '/** Print {0} data to data */\nuint32_t print{0}   (char *fmtStr, void *data);\n'.format(name)
        oprHContent += '/** Reset {0} to default data */\nint32_t  reset{0}   (tMemRegHdr *memPtr, uint8_t flag);\n'.format(name)
        oprHContent += '/** Destroy {0} allocated memory when exit */\nint32_t  destroy{0} (tMemRegHdr *memPtr);\n\n'.format(name)
        # Opr header file
        wrOprHfile.write(oprHContent)
        wrOprHfile.write('#endif\n')

    with open(os.path.join(libPath, '{0}Opr.c'.format(module)), mode='w') as wrOprCfile:
        generateFileComment(wrOprCfile, module, 'Opr.c')
        wrOprCfile.write('#include <stdlib.h>\n#include <stdio.h>\n#include <string.h>\n#include <assert.h>\n#include <pthread.h>\n#include <log/sdklog.h>\n#include <common/strutil.h>\n#include <common/regtbl.h>\n#include <common/const.h>\n#include <driver/readwrite.h>\n#include <inttypes.h>\n')
        wrOprCfile.write('#include <mem/{0}.h>\n\n'.format(module))
        oprCContent    = ''
        # module opr c file
        # print function
        oprCContent += '\nuint32_t print{0}(char *fmtStr, void *data) {{\n'.format(name)
        oprCContent += '    assert(data != NULL);\n    assert(fmtStr != NULL);\n'
        oprCContent += '    t{0} *ptr = ((t{0} *)data);\n'.format(typeName)
        fmtTmp = '    sprintf(fmtStr, "{0} : {{\\n'.format(name)
        varTmp = ''
        i = 0
        for item in v.getFldList():
            i = i + 1
            if i % 4 == 0:
                # format print code, 4 field per line
                fmtTmp += '\\\n'
                varTmp += '\n        '
            fmtTmp += '{0:>20} : \\"0x%x\\",\\n'.format('\\"{0}\\"'.format(item.name.strip()))
            varTmp += ', ptr->{0}'.format(item.name.strip())
        oprCContent += '{0}\\n}}\\n"{1});\n'.format(fmtTmp[:-3], varTmp)
        oprCContent += '    return strlen(fmtStr);\n}\n'
    
        # read function
        oprCContent += '\nint32_t  read{0}(tMemRegHdr *memPtr, uint32_t index, void *output) {{\n'.format(name)
        oprCContent += '    assert(output != NULL);\n'
        oprCContent += '    if(index >= memPtr->entryNum.entries) {\n'
        oprCContent += '        sprintf(output, "ERROR: out of range {0}, max %" PRIu64 " but %d\\n", memPtr->entryNum.entries-1, index);\n'.format(name)
        oprCContent += '        return -1;\n'
        oprCContent += '    }\n'
        oprCContent += '    pthread_rwlock_rdlock(memPtr->rwLockList + index);\n'
        oprCContent += '    t{0} *ptr = ((t{0} *)(memPtr->entryList)) + index;\n'.format(typeName)
        oprCContent += '    memcpy(output, ptr, sizeof(t{0}));\n'.format(typeName)
        oprCContent += '    pthread_rwlock_unlock(memPtr->rwLockList + index);\n'
        oprCContent += '    return memPtr->widthInQuad * sizeof(int);\n}\n'
    
        # field set function
        oprCContent += '\nint32_t fldSet{0}(void *data, uint32_t nflds, char *flds[]) {{\n'.format(name)
        oprCContent += '    t{0} *ptr = (t{0} *)data;\n'.format(typeName)
        oprCContent += '    int i      = 0;\n    int num    = 0;\n    int wrFlag = 0;\n    char buf[128]       = {0};\n    char *assignExpr[2] = {NULL};\n'
        oprCContent += '    for (i = 0; i < nflds; i++) {\n'
        oprCContent += '        strcpy(buf, *(flds + i));\n'
        oprCContent += '        num = split(buf, "= ", assignExpr);\n'
        oprCContent += '        if (num != 2) {\n'
        oprCContent += '            servLogError("Illegal assignment expression [%s] in fldSet function.\\r\\n", *(flds + i));\n'
        oprCContent += '        } else {\n'
        i = 0
        for item in v.getFldList():
            if i == 0: 
                oprCContent += '            if(strcasecmp(*assignExpr, "{0}") == 0) {{\n'.format(item.name.strip())
            else: 
                oprCContent += '            }} else if(strcasecmp(*assignExpr, "{0}") == 0) {{\n'.format(item.name.strip())
            oprCContent += '                ptr->{0} = strtoul(*(assignExpr + 1), NULL, 0);\n'.format(item.name.strip())
            oprCContent += '                wrFlag   = 1;\n'
            i   = i + 1;
        oprCContent += '            }} else {{\n                servLogWarn("Unknown field %s in {0}.\\r\\n", *(flds + i));\n'.format(name)
        oprCContent += '            }\n        }\n    }\n    return wrFlag;\n}\n'
    
        # field get function
        oprCContent += '\nuint32_t fldGet{0}(tMemRegHdr *memPtr, uint32_t index, char *fldName, void *output, uint8_t fromWhere) {{\n'.format(name)
        oprCContent += '    if(index >= memPtr->entryNum.entries) {\n'
        oprCContent += '        sprintf(output, "ERROR: out of range {0}, max %" PRIu64 " but %d\\n", memPtr->entryNum.entries-1, index);\n'.format(name)
        oprCContent += '        return -1;\n    }\n'
        oprCContent += '    pthread_rwlock_rdlock(memPtr->rwLockList + index);\n    t{0} *ptr = ((t{0} *)(memPtr->entryList)) + index;\n'.format(typeName)
        oprCContent += '#if NEED_ADDR == 1\n    readHwEntry(ptr, memPtr, index, memPtr->widthInQuad, fromWhere);\n#endif\n'
        oprCContent += '    pthread_rwlock_unlock(memPtr->rwLockList + index);\n'
        
        i = 0
        for item in v.getFldList():
            if i == 0: 
                oprCContent += '    if(strcasecmp(fldName, "{0}") == 0) {{\n'.format(item.name.strip())
            else:
                oprCContent += '    }} else if(strcasecmp(fldName, "{0}") == 0) {{\n'.format(item.name.strip())
            oprCContent += '        *((uint32_t *)output) = ptr->{0};\n'.format(item.name.strip())
            i = i + 1
        oprCContent += '    } else {\n'
        oprCContent += '        servLogWarn("Unknown field %s in {0}.\\r\\n", fldName);\n    }}\n'.format(name)
        oprCContent += '    return sizeof(int);\n}\n'
                
        # write function
        oprCContent += '\nint32_t  write{0}(tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], void *output, uint8_t fromWhere) {{\n'.format(name)
        oprCContent += '    if(index >= memPtr->entryNum.entries) {\n'
        oprCContent += '        sprintf(output, "Error: Out of range {0}, max %" PRIu64 " but %d in write function.\\n", memPtr->entryNum.entries-1, index);\n'.format(name)
        oprCContent += '        return -1;\n'
        oprCContent += '    }\n'
        oprCContent += '    pthread_rwlock_wrlock(memPtr->rwLockList + index);\n'
        oprCContent += '    t{0} *ptr = ((t{0} *)(memPtr->entryList)) + index;\n'.format(typeName)
        oprCContent += '#if NEED_ADDR == 1\n    readHwEntry(ptr, memPtr, index, memPtr->widthInQuad, fromWhere);\n#endif\n'
        oprCContent += '    int modified = fldSet{0}(ptr, parac, parav);\n'.format(name);
        oprCContent += '#if NEED_ADDR == 1\n'
        oprCContent += '    if (modified == 1) {\n        writeHwEntry(memPtr, index, ptr, memPtr->widthInQuad, fromWhere);\n    }\n'
        oprCContent += '#endif\n'
        oprCContent += '    pthread_rwlock_unlock(memPtr->rwLockList + index);\n'
        oprCContent += '    return sizeof(int);\n}\n'
        
        # set function
        oprCContent += '\nint32_t set{0}(tMemRegHdr *memPtr, uint32_t index, void *data, void *output, uint8_t fromWhere) {{\n'.format(name)
        oprCContent += '    assert(data != NULL);\n'
        oprCContent += '    if(index >= memPtr->entryNum.entries) { \n'
        oprCContent +='        sprintf(output, "Error: Out of range {0}, max %" PRIu64 " but %d in set function\\n", memPtr->entryNum.entries-1, index);\n'.format(name)
        oprCContent +='        return -1;\n    }\n'
        oprCContent += '    pthread_rwlock_wrlock(memPtr->rwLockList + index);\n'
        oprCContent +='    memcpy(((t{0} *)(memPtr->entryList)) + index, data, sizeof(t{0}));\n'.format(typeName)
        oprCContent += '#if NEED_ADDR == 1\n    writeHwEntry(memPtr, index, data, memPtr->widthInQuad, fromWhere);\n#endif\n'
        oprCContent += '    pthread_rwlock_unlock(memPtr->rwLockList + index);\n'
        oprCContent +='    return sizeof(int);\n}\n'
    
        # reset function
        oprCContent += '\nint32_t reset{0}(tMemRegHdr *memPtr, uint8_t chgData) {{\n'.format(name)
        oprCContent += '    if(chgData) {\n'
        oprCContent += '        if(memPtr->entryList != NULL) {\n            free(memPtr->entryList);\n        }\n'
        oprCContent += '        t{0} *ptr = (t{0} *)calloc(sizeof(t{0}), {1});\n'.format(typeName, v.depth)
        oprCContent += '        assert(ptr != NULL);\n'
        if(v.depth == 1):
            for item in v.getFldList():
                oprCContent += '        ptr->{0:24} = {1:#x};\n'.format(item.name.strip(), item.defVal); 
        oprCContent += '        memPtr->entryList = ptr;\n        if(memPtr->rwLockList != NULL) {\n            free(memPtr->rwLockList);\n        }\n'
        oprCContent += '        pthread_rwlock_t *lockPtr = (pthread_rwlock_t *)calloc(sizeof(pthread_rwlock_t), {0});\n'.format(v.depth)
        oprCContent += '        assert(lockPtr != NULL);\n'
        if v.depth == 1:
            oprCContent += '        pthread_rwlock_init(lockPtr,  NULL);\n'
        else:
            oprCContent += '        int i = 0;\n'
            oprCContent += '        for (i = 0; i < {0}; i++) {{\n            pthread_rwlock_init(lockPtr + i,  NULL);\n'.format(v.depth)
            if name == "DsMemVlanPortMask":
                oprCContent += '            (ptr + i)->portMask = 0xfffffff;\n'
            elif name == "DsMemSrcPortEgressMask":
                oprCContent += '            (ptr + i)->portEgressMask = 0xfffffff;\n'
            oprCContent += '        }\n'
        oprCContent += '        memPtr->rwLockList = lockPtr;\n'
        oprCContent += '    }\n\n'
        oprCContent += '    if(memPtr->fldNameList != NULL) {\n        free(memPtr->fldNameList);\n    }\n'
        oprCContent += '    char **strAry = (char **)calloc({0}, sizeof(char *));\n'.format(len(v.getFldList())+1)
        oprCContent += '    assert(strAry != NULL);\n'
        i = 0
        for item in v.getFldList():
            oprCContent += '    *(strAry+{1:d})     = "{0}";\n'.format(item.name.strip(), i);
            i    = i + 1
        oprCContent += '    *(strAry+{0:d})     = NULL;\n'.format(i);
        oprCContent += '    memPtr->fldNameList  = strAry;\n    return 0;\n}\n'
    
        # destroy function
        oprCContent += '\nint32_t destroy{0}(tMemRegHdr *memPtr) {{\n'.format(name)
        oprCContent += '    if(memPtr->entryList != NULL) {\n        free(memPtr->entryList);\n    }\n'
        oprCContent += '    memPtr->entryList = NULL;\n'
        oprCContent += '    if(memPtr->fldNameList != NULL) {\n        free(memPtr->fldNameList);\n    }\n'
        oprCContent += '    memPtr->fldNameList = NULL;\n'
        oprCContent += '    if(memPtr->rwLockList != NULL) {\n'
        if v.depth == 1:
            oprCContent += '        pthread_rwlock_destroy(memPtr->rwLockList);\n    }\n'
        else:
            oprCContent += '        int i = 0;\n        for (i = 0; i < {0}; i++) {{\n            pthread_rwlock_destroy(memPtr->rwLockList + i);\n        }}\n'.format(v.depth)
            oprCContent += '        free(memPtr->rwLockList);\n    }\n'
        oprCContent += '    memPtr->rwLockList = NULL;\n    return 0;\n}\n'
    
        # module opr c file
        wrOprCfile.write(oprCContent) 
        wrOprCfile.close()

def calcAddress(offStr):
   seg          = offStr.split("'")
   bitStr       = seg[1].replace('?', '0')
   bitStr       = '0{0}'.format(bitStr.replace('_', ''))
   return int(bitStr, base=2) * 4

class RegMemHdr:
    def __init__(self, colList):
        self.name = colList[0]
        self.fldsList = []
        if (len(colList) == 7):
            self.depth   = int(colList[2])
            self.width   = int(colList[3])
            self.address = calcAddress(colList[5])
        elif (len(colList) == 5):
            self.depth   = 1
            self.width   = int(colList[2])
            self.address = calcAddress(colList[3])

    def addField(self, fld):
        self.fldsList.append(fld)

    def printHdr(self):
        print('<<{0}, {1}, {2}, {3}, {4}>>'.format(self.name, self.width, self.depth, self.address, self.fldsList))

    def getFldList(self):
        return self.fldsList

def calcDefault(valStr):
    seg      = valStr.replace('_', '').split("'")
    value    = 0
    if len(seg) == 2:
        scale    = seg[1][0:1]
        base     = 10
        if scale == 'b' or scale == 'B':
            base = 2
        elif scale == 'd' or scale == 'D':
            base = 10
        elif scale == 'h' or scale == 'H':
            base = 16
        value    = int(seg[1][1:], base)
    else:
        print('xxxxxxxxxxxxxxxxxxxxxx Invalid default string: {0}'.format(valStr))
    return value

class FldDesc:
    def __init__(self, colList):
        self.name   = colList[0]
        self.offset = int(colList[1])
        self.hiBit  = int(colList[2])
        self.loBit  = int(colList[3])
        self.width  = self.hiBit - self.loBit + 1
        if len(colList) == 10:        # Register fields
            self.defVal = calcDefault(colList[-1])
            self.description = colList[-2]
            tmpFlag = '{0}{1}{2}{3}'.format(colList[4], colList[5], colList[6], colList[7]) 
            if tmpFlag == 'NNNN':
                self.ioFlag = 'CPU Read and Write'
            elif tmpFlag == 'YNNN':
                self.ioFlag = 'CPU Read Only'
            elif tmpFlag == 'YNYN':
                self.ioFlag = 'CPU Read Only and RTL Write with Indicate'
            elif tmpFlag == 'NNYN':
                self.ioFlag = 'CPU Read and Write and RTL Write with Indicate'
            elif tmpFlag == 'YYNN':
                self.ioFlag = 'CPU Read Only and RTL Read with Indicate'
            elif tmpFlag == 'NYNN':
                self.ioFlag = 'CPU Read and Write and RTL Read with Indicate'
            else:
                self.ioFlag = '{0} is unknown for {1}'.format(tmpFlag, colList[0])
        else: 
            self.defVal = 0
            self.description = colList[-1]
            tmpFlag = '{0}{1}'.format(colList[4], colList[5]) 
            if tmpFlag == 'YY':
                self.ioFlag = 'Read and Write trigger'
            elif tmpFlag == 'YN':
                self.ioFlag = "Read trigger"
            elif tmpFlag == 'NN':
                self.ioFlag = "No I/O trigger"
            elif tmpFlag == 'NY':
                self.ioFlag = "Write trigger"
            else:
                self.ioFlag = 'Unknown Flag for {0}'.format(colList[0])

    def printFldInfo(self):
        print('<{0}, {1}, {2}, {3}>'.format(self.name, self. offset, self.width, self.defVal))

def transRegTxt2C(path, inDir, include, lib):
    memHdrInitLines = '#include <log/sdklog.h>\n#include <common/rbmem.h>\n#include <mem/ModuleInit.h>\n\nint initMemHdr() {\n\tstruct rb_root *root = initMemRoot();\n'
    moduleInitLines = ''
    for module in ModuleList:
        moduleInitLines += '\n/** init {0} on rbtree */\nint insert{0}Hdr(struct rb_root *root);\n'.format(module)
        memHdrInitLines += '\tif (insert{0}Hdr(root) < 0) {{\n\t\tservLogError("{0} Memory initialization failed.\\r\\n");\n\t\treturn -1;\n\t}}\n'.format(module)
    for i in MemRegNumDict.keys():
        for j in range(MemRegNumDict[i]):
            moduleInitLines += '\n/** init {0}{1} on rbtree */\nint insert{0}{1}Hdr(struct rb_root *root);\n'.format(i, str(j))
            memHdrInitLines += '\tif (insert{0}{1}Hdr(root) < 0) {{\n\t\tservLogError("{0}{1} Memory initialization failed.\\r\\n");\n\t\treturn -1;\n\t}}\n'.format(i, str(j))
    with open(os.path.join(path, '{0}/initMemHdr.h'.format(include)), 'w') as hMemHdrInit:
        generateFileComment(hMemHdrInit, 'initMemHdr', '.h')
        hMemHdrInit.write('#ifndef __MEM_HDR_INIT__\n#define __MEM_HDR_INIT__\n\n/** regtbl memory init */\nint initMemHdr();\n#endif\n')
    with open(os.path.join(path, '{0}/initMemHdr.c'.format(lib)), 'w') as cMemHdrInit:
        generateFileComment(cMemHdrInit, 'initMemHdr', '.c')
        cMemHdrInit.write(memHdrInitLines)
        cMemHdrInit.write('\treturn 0;\n}\n')
    with open(os.path.join(path, '{0}/ModuleInit.h'.format(include)), 'w') as hModuleInit:
        generateFileComment(hModuleInit, 'ModuleInit', '.h')
        hModuleInit.write('#ifndef __MODULE_INIT__\n#define __MODULE_INIT__\n\n')
        hModuleInit.write(moduleInitLines)

    # walk through the inDir
    nRegTxt = 0
    for module in ModuleList:
        module = module + 'Reg.txt'
        nRegTxt = nRegTxt + 1
        print('~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~transforing {}'.format(module))
        # read file
        with open(os.path.join(inDir, module), 'r') as regFile:
            lines = regFile.readlines()
            colList  = lines[1].split('\t')
            if colList[0].endswith('Reg'):
                module = colList[0][:-3]
            if module == 'GigaMac': 
                module = 'Gmac'

            memRegDict    = {}
            regMemName    = ''
            beginMemHdr   = 0
            beginRegHdr   = 0
            beginMemFld   = 0
            beginRegFld   = 0
            for line in lines[2:]:
                colList= line.strip().split('\t')
                if len(colList) == 7 and colList[0] == 'RegMem':
                    beginMemHdr   = 1
                    beginRegHdr   = 0
                    beginMemFld   = 0
                    beginRegFld   = 0
                    continue
                elif len(colList) == 2 and colList[0] == 'MemRegFields':
                    beginMemHdr   = 0
                    beginRegHdr   = 0
                    beginMemFld   = 0
                    beginRegFld   = 0
                    regMemName    = colList[1]
                    continue
                elif len(colList) == 5 and colList[0] == 'Register':
                    beginMemHdr   = 0
                    beginRegHdr   = 1
                    beginMemFld   = 0
                    beginRegFld   = 0
                    continue
                elif len(colList) == 7 and colList[0] == 'Fields':
                    beginMemHdr   = 0
                    beginRegHdr   = 0
                    beginMemFld   = 1
                    beginRegFld   = 0
                    continue
                elif len(colList) == 10 and colList[0] == 'Fields':
                    beginMemHdr   = 0
                    beginRegHdr   = 0
                    beginMemFld   = 0
                    beginRegFld   = 1
                    regMemName    = colList[-1]
                    continue
                elif len(colList) < 2:      #empty line
                    continue
                # parser
                if beginMemHdr == 1 or beginRegHdr == 1:
                    memRegDict[colList[0]] = RegMemHdr(colList)
                if beginMemFld    == 1 or beginRegFld == 1:
                    tmpMod         = memRegDict.get(regMemName)
                    tmpFld         = FldDesc(colList)
                    tmpMod.addField(tmpFld)
            isDp     = 1
            if module in PpRegList:
                isDp = 0
            generateCommonCode(os.path.join(path, include), os.path.join(path, lib), module, memRegDict)

            for i in range(0, MemRegNumDict.get(module, 1)): 
                if module in MemRegNumDict.keys():
                    newModule = '{0}{1}'.format(module, i)
                else:
                    newModule = module
                generateDiffCode(os.path.join(path, include), os.path.join(path, lib), module, newModule, memRegDict)
    return nRegTxt
