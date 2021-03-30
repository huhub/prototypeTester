#!/bin/python3
import os, re, sys, argparse, math
from database import *

def tmpVarDeclare(specFileName, line, tmpVariableSet, tmpVarDict):
    tmpVarPattern = re.compile(r'^\s+(tmp\w+){0}(\[{0}(\d+){0}:{0}(\d)+{0}\])?'.format('\s*'))
    if tmpVarPattern.match(line):
        tmpVarName = tmpVarPattern.match(line).group(1)
        width = 1
        tmpVarDeclare = '\tuint8_t {} = 0;\n'.format(tmpVarName) 
        if tmpVarPattern.match(line).group(2):
            tmpVarWidth = tmpVarPattern.match(line).group(3)
            width = int(tmpVarPattern.match(line).group(3))+1
            tmpVarDeclare = '\tuint{}_t {} = 0;\n'.format(str(judge(specFileName, tmpVarName, width)), tmpVarName)
        if tmpVarName not in tmpVarDict.keys():
            if tmpVarPattern.match(line).group(2) and tmpVarPattern.match(line).group(4) != '0':
                print('{} need define: \033[1;35m {} \033[0m'.format(specFileName, tmpVarName))
            else:
                tmpVarDict[tmpVarName] = width
        tmpVariableSet.add(tmpVarDeclare)

def ctlDeclare(line, dsCtlSet):
    ctlPattern = re.compile(r'(\bCtl\w+)')  
    if ctlPattern.search(line):
        ctlName = ctlPattern.search(line).group(1)
        ctlDeclare = '\tt{0} {0}Tmp = {{0}};\n\tt{0} *{0} = &{0}Tmp;\n\tread{0}("{0}", 0, {0}, 0);\n'.format(ctlName)
        dsCtlSet.add(ctlDeclare)

def tblDeclare(line, dsCtlSet):
    dsPattern = re.compile(r'(\bDs[MR]e[mg]\w+\d*Val\d*){0}={0}(Ds\w+){0}\[{0}(\S+){0}\]'.format('\s*'))
    if dsPattern.search(line):
        indent = re.compile(r'(\s*).*').match(line).group(1)
        varName = dsPattern.search(line).group(1)
        dsName = dsPattern.search(line).group(2)
        dsIdx = dsPattern.search(line).group(3)
        dsType = 't'+dsName
        if dsName in TblDict.keys():
            dsType = 't'+TblDict[dsName]
        dsDeclare = '\t{0} {1}Tmp = {{0}};\n\t{0} *{1} = &{1}Tmp;\n'.format(dsType, varName)
        line = '{}rpcRdMem("{}", {}, {});\n'.format(indent, dsName, dsIdx, varName)
        dsCtlSet.add(dsDeclare)
    return line

def removeScale(line, tmpVarDict):
    pattern = re.compile(r'^\s*(tmp\w+)\[(\d+):\d+\]')
    if pattern.search(line):
        indent = re.compile(r'(\s*).*').match(line).group(1)
        tmpVar = pattern.search(line).group(1)
        width  = int(pattern.search(line).group(2))+1
        if tmpVar in tmpVarDict.keys() and tmpVarDict[tmpVar] == width:
            line = pattern.sub(indent+tmpVar, line)
    return line

def defineTmpPkt(line):
    pattern = re.compile(r'(glPktTmp\w+)\[0:(\d+)\]{0}={0}(glPkt\w+){0}\[{0}(\S+){0}:'.format('\s*'))
    if pattern.search(line):
        indent = re.compile(r'(\s*).*').match(line).group(1)
        glPktTmp = pattern.search(line).group(1)
        size     = str(int(pattern.search(line).group(2))+1)
        glPkt    = pattern.search(line).group(3)
        offset   = pattern.search(line).group(4)
        line = '{0}uint8_t {1}[{2}] = {{0}};\n{0}memcpy({1}, {3}+{4}, {2});\n'.format(indent, glPktTmp, size,  glPkt, offset)
    return line

def defineTmpBuf(line):
    pattern = re.compile(r'(buf\w+)\[(\d+):0\]{0}={0}(glPkt\w+){0}\[{0}(\S+){0}:'.format('\s*'))
    if pattern.search(line):
        indent = re.compile(r'(\s*).*').match(line).group(1)
        bufKey = pattern.search(line).group(1)
        size   = str((int(pattern.search(line).group(2))+1)//8)
        glPkt  = pattern.search(line).group(3)
        offset = pattern.search(line).group(4)
        line = '{0}uint8_t {1}[{2}] = {{0}};\n{0}memcpy({1}, {3}+{4}, {2});\n'.format(indent, bufKey, size,  glPkt, offset)
    return line
        
def setCtl(line):
    pattern = re.compile('^\s+(Ctl\w+)\.(\w+)(?:\[\d+{0}:{0}\d+\])?{0}={0}(.*);'.format('\s*'))
    if pattern.search(line):
        ctlName = pattern.search(line).group(1)
        indent = re.compile(r'(\s*).*').match(line).group(1)
        line = line+'{1}rpcSetMem( "{0}", 0, {0}, sizeof(t{0}) );\n'.format(ctlName, indent)
    return line

def setTbl(line):
    pattern = re.compile(r'(\bDs[MR]e[mg]\w+){0}\[{0}(\S+{0}\+?{0}(?:\d+)?)\]{0}={0}(.*){0};'.format('\s*'))
    if pattern.search(line):
        dsName  = pattern.search(line).group(1)
        dsIdx  = pattern.search(line).group(2)
        varName  = pattern.search(line).group(3)
        dsType = 't'+dsName
        indent = re.compile(r'(\s*).*').match(line).group(1)
        if dsName in TblDict.keys():
            dsType = 't'+TblDict[dsName]
        line = '{}rpcSetMem( "{}", {}, {}, sizeof({}) );\n'.format(indent, dsName, dsIdx, varName, dsType)
    return line

def bitCombine(line):
    pattern = re.compile(r'(\{\s*\S*, .*?\})')
    if pattern.search(line):
        leftBucketNum = line.count('{') 
        rightBucketNum = line.count('}') 
        cycTimes = min(leftBucketNum, rightBucketNum)
        for i in range(cycTimes):
            bucketContent = pattern.search(line).group(1)
            bitCom = get_str_btw(bucketContent, "{", "}")
            tmpList = bitCom.split(',')
            shift = 0
            for i in range(len(tmpList)-1,0,-1):
                if re.search(r'\[(\d+):(\d+)\]', tmpList[i]):
                    numLeft = re.search(r'\[(\d+):(\d+)\]', tmpList[i]).group(1)
                    numRight = re.search(r'\[(\d+):(\d+)\]', tmpList[i]).group(2)
                    shift += int(numLeft)-int(numRight)+1
                    tmpList[i] = '<<'+str(shift)+') + ('+tmpList[i]
                else:
                    shift += 8
                    tmpList[i] = '<<'+str(shift)+ ') + ('+tmpList[i]
                #if shift > 31:
                tmpList[i-1] = '(uint64_t)'+tmpList[i-1].strip()
            tmpList[0] = '('+tmpList[0]
            tmpList[len(tmpList)-1] += ')'
            line = pattern.sub( ''.join(tmpList), line, count=1)
    return line

def bitSet(line):
    pattern = re.compile(r'{0}(\S+)\[{0}(\S+){0}:{0}(\S+)\]{0}={0}(.*);'.format('\s*'))
    indent = re.compile(r'(\s*).*')
    if pattern.match(line):
        varName = pattern.search(line).group(1)
        bitLeft = pattern.search(line).group(2)
        bitRigh = pattern.search(line).group(3)
        setValu = pattern.search(line).group(4)
        line = '{}SET_BITS({}, {}, {}, ({}));\n'.format(indent.match(line).group(1), varName, bitRigh, bitLeft, setValu)
    return line

def bitGet(line):
    pattern = re.compile(r'{0}\b((?:\w+)?(?:->)?\w+(?:\[\S+\])?){0}\[{0}(\S+){0}:{0}(\S+){0}\]'.format('\s*'))
    circulation = line.count('[')
    for i in range(circulation):
        if pattern.search(line):
            varName = pattern.search(line).group(1)
            bitLeft = pattern.search(line).group(2)
            bitRigh = pattern.search(line).group(3)
            line = pattern.sub(' GET_BITS({}, {}, {})'.format(varName, bitRigh, bitLeft), line, count=1)
    return line

def fillArray(line, VarDict):
    tmpVarPattern = re.compile(r'(\btmp\w+Buf\d*){0}\[{0}(\d+){0}:{0}(\d+){0}\]{0}={0}(.*);'.format('\s*'))
    if tmpVarPattern.search(line):
        newline = ''
        listsAll = tmpVarPattern.findall(line)
        leftVal, left, right, rightVal= listsAll[0]
        try:
            arrLen = VarDict[leftVal]
            begin = (int(arrLen) - int(left) - 1)//8
            size = (int(left) - int(right) + 1)//8
            indent = re.compile(r'(\s*).*').match(line).group(1)
            for i in range(size):
                rightShift = 8 * (size-i-1)  
                newline += '{}{}[{}]  = ({}) >> {};\n'.format(indent, leftVal, str(begin+i), rightVal, rightShift)
            line = newline
        except (IndexError):
            print('{} is not defined previously'.format(leftVal))
    return line


def getPriorNo(line, VarDict, moduleName):
    pattern = re.compile(r'(?:(\w+\.?\w+\S+)\s*=\s*)?([CD][ts][lMR]\w+\.\w+)\{\s*(\w+\.?\w+)\s*(\[\s*(\d+)\s*:\s*(\d+)\])\s*(?:-\s*\d)?\s*\}(\[\s*\d+\s*:\s*\d+\])(?:\s*=\s*(\w+\.?\w+\S+))?')
    if pattern.search(line):
        newline = ''
        listsAll = pattern.findall(line)
        leftVal, field, index, suffix1, width1, width2, suffix2, rightVal = listsAll[0]
        loop = 2 ** (int(width1) - int(width2)+1)
        if '-' in line and '1' in line:
            loop -= 1
        if '-' in line and '2' in line:
            loop -= 2
        indent = re.compile(r'(\s*).*').search(line).group(1)
        for i in range(loop):
            pass
    return line

def assignPacket(line):
    pattern = re.compile(r'\s+(\{.*\})\s*=\s*(\S+)\s*;')
    newline = ''
    if pattern.match(line):
        bucketContent = pattern.search(line).group(1)
        rightVal = pattern.match(line).group(2) 
        bitCom = get_str_btw(bucketContent, "{", "}")
        tmpList = bitCom.split(',')
        leftValNum = len(tmpList)
        indent = re.compile(r'(\s*).*').match(line).group(1)
        for i in range(leftValNum):
            newline += '{}{} = {} >> {};\n'.format(indent, tmpList[i].strip(), rightVal, str(8*(leftValNum-i-1)))
        return newline
    return line

def callCrc(line):
    crcPattern = re.compile(r'\b((\w+)?CRC\w+)\b')
    if crcPattern.search(line):
        line = crcPattern.sub(CrcDict[crcPattern.search(line).group(1)], line)
    return line

def movePacket(line):
    pattern = re.compile(r'(\s*)(glPkt\w+)\s*=\s*glPkt\w+\s*\+\s*(.*);')
    if pattern.search(line):
        indent = pattern.search(line).group(1)
        pkt    = pattern.search(line).group(2)
        offset = pattern.search(line).group(3)
        line   = '{0}for (int i = PI->pktLength; i >= {1} - PI->ethTypeLen; i--) {{\n{0}\t*({2} + i + 100 - {1} + PI->ethTypeLen) = *({2} + i);\n{0}}}\n{0}memset({2}, 0, 100);\n'.format(indent, offset, pkt)
    return line

def headEdit(line):
    pattern = re.compile(r'(\s*)HeaderEdit\(\s*(\w+),\s*(\w+),\s*(\w+)')
    if pattern.search(line):
        indent   = pattern.search(line).group(1)
        pkt     = pattern.search(line).group(2)
        fldLen  = pattern.search(line).group(3)
        content = pattern.search(line).group(4)
        line = '{}headerEdit({}, {}, {}, sizeof({}), PI->pktLength);\n'.format(indent, pkt, content, fldLen, fldLen);
    return line

def debugOption(line):
    pattern = re.compile(r'^(\s*)(PI->\w+)\s*=.*;')
    if pattern.search(line):
        indent   = pattern.search(line).group(1)
        info    = pattern.search(line).group(2)
        line = line #+ '{}__debug({});\n'.format(indent, info)
    return line

##################################################################################################

def get_str_btw(s, f, b):
    par = s.partition(f)
    return (par[2].partition(b))[0][:]
    
def judge(module, variable, bitWidth):
    if bitWidth in range(9):
        return 8
    elif bitWidth in range(8,17):
        return 16
    elif bitWidth in range(17,33):
        return 32
    elif bitWidth in range(33,65):
        return 64
    else:
        print('\033[1;35m {}:{} width is illegal \033[0m'.format(module, variable))
