#!/bin/python3
import os
import re
import sys
import datetime
from method import *

def transSpec2Cmodel(specPath, cmodelPath, specFileName, funcExtern):
    with open('{}{}'.format(specPath, specFileName), 'r') as f:
        funcsList  = []
        dsCtlList  = []	 # use to store the DsMem or Ctl
        tmpVarList = []  # use to store the tmpVar
        cStyleLinesList = []
        tmpVarDict = {}

        # funcsList is a two-dimensional array, the first dimension uses to store different function, the second to store value, DsCtl .eg  
        funcIdentification = re.compile(r'(\bfunction\b)|(^process)')
        lines = f.readlines()
        listsIndex = 0
        
        #devision of scope
        for line in lines:
            if len(line.strip()) == 0: # skip bland line
                continue
            if funcIdentification.search(line) or 'static' in line:
                listsIndex += 1
                funcsList.append([])
                tmpVarList.append(set())    
                dsCtlList.append(set())
                
                # add the function declaration and modify the line to c style
                args = get_str_btw(line, '(', ')')
                argsList = args.split(',')
                for i in range(len(argsList)):
                    if 'glPkt' in argsList[i]:
                        argsList[i] = 'uint8_t *{}'.format(argsList[i].strip())# indicator or array?
                    elif 'PI' in argsList[i]:
                        argsList[i] = 'tPktInfo *{}'.format(argsList[i].strip())
                    elif '[' in argsList[i]:
                        width = get_str_btw(argsList[i], '[', ']').split(':')
                        width = int(width[0].strip())-int(width[1].strip())+1
                        arg = re.sub(r'\[\d+:\d+\]', '', argsList[i])
                        argsList[i] = 'uint{}_t {}'.format(str(judge(specFileName, arg, width)), arg)
                    else:
                        argsList[i] = 'uint8_t {}'.format(argsList[i].strip())
                line = re.sub(r'\(.*\)', '({})'.format(', '.join(argsList)), line)
                line = funcIdentification.sub('void', line)
                funcExtern += '{}'.format(re.sub('{', ';\n', line))
            try:
                funcsList[listsIndex-1].append(line)	
            except IndexError:
                print('\033[1;35m Error: {} has to start with function|process|static \033[0m'.format(specFileName))

        for i in range(listsIndex):
            # declare some variable
            for j in range(len(funcsList[i])):
                if funcsList[i][j].strip().startswith('//'):
                    continue
                tmpVarDeclare(specFileName, funcsList[i][j], tmpVarList[i], tmpVarDict)
                ctlDeclare(funcsList[i][j], dsCtlList[i])

                funcsList[i][j] = tblDeclare(funcsList[i][j], dsCtlList[i])
                funcsList[i][j] = removeScale(funcsList[i][j], tmpVarDict)
                funcsList[i][j] = funcsList[i][j].replace('.', '->')
                funcsList[i][j] = funcsList[i][j].replace('\'d', '')
                funcsList[i][j] = re.sub(r'\d+\'h', '0x', funcsList[i][j])

                funcsList[i][j] = defineTmpPkt(funcsList[i][j])
                funcsList[i][j] = defineTmpBuf(funcsList[i][j])
                funcsList[i][j] = callCrc(funcsList[i][j])
                funcsList[i][j] = setCtl(funcsList[i][j])
                funcsList[i][j] = setTbl(funcsList[i][j])

                funcsList[i][j] = bitCombine(funcsList[i][j])
                funcsList[i][j] = bitSet(funcsList[i][j])
                funcsList[i][j] = bitGet(funcsList[i][j])

                #funcsList[i][j] = fillArray(funcsList[i][j])
                funcsList[i][j] = assignPacket(funcsList[i][j])

            funcsList[i].insert(1, ''.join(dsCtlList[i])+'\n')
            funcsList[i].insert(1, ''.join(tmpVarList[i])+'\n')
            cStyleLinesList += funcsList[i]

    #write cmodel code
    with open('{}{}'.format(cmodelPath,specFileName[:-4]+'c'), 'w+') as f:
        f.write('/*\n * cmodel for Pishon\n * @file: {}\n * @description: auto generage\n * @note: Copyright (C) {}\n *\n * You should have received a copy of the Fisilink License\n * along with this program; if not, write to Fisilink\n */\n\n'.format(specFileName[:-5], datetime.datetime.now()))
        f.write('#include <assert.h>\n') 
        f.write('#include <string.h>\n')
        f.write('#include <stdlib.h>\n')
        f.write('#include <stdio.h>\n')
        f.write('#include <stdint.h>\n')
        f.write('#include <ppinfo.h>\n')
        f.write('#include <ppenum.h>\n')
        f.write('#include <mem/{}Opr.h>\n'.format(specFileName[:-5]))
        f.write('#include <mem/{}.h>\n'.format(specFileName[:-5]))
        f.write('\n')
        f.write((''.join(cStyleLinesList)))	
    
    return funcExtern
