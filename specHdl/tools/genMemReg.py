#! /usr/bin/python 
import re

fldNamePtn         = re.compile(r'([a-z]\w+)(?=\[(\d+):(\d+)\])?\b')
ioPtn              = re.compile( r'[RWIO]{2}\b' )
hexPtn             = re.compile( r'(?:0[xX])?([0-9a-fA-F]+)\b' )
def createRegTxt( inDir, outDir, cHdrDir, cLibDir ):
    # init size statisic string
    memStatStr     = ''
    regStatStr     = ''
    # init for fields definition of RTL
    fldDefineStr = ''
    for moduleName in os.listdir( inDir ):
        tmpPath = os.path.join( inDir, moduleName )
        if os.path.isdir( tmpPath ):
            #print( "\tNow in {0} direction...{1}Reg.txt".format(tmpPath, moduleName) )
            regList      = []
            memList      = []
            # init for regTxt generation
            titleStr     = ''
            memDescStr   = ''
            memFldStr    = ''
            regDescStr   = ''
            regFldStr    = ''
            # init for C code generation

            maxUsedWords = 0
            maxRegWords  = 0
            for regMemFile in sorted( os.listdir( tmpPath ) ):
                filePath = os.path.join( tmpPath, regMemFile )
                if os.path.isfile( filePath ) and regMemFile.endswith( '.txt' ):
                    #print( "\t\t {0}".format(regMemFile) )
                    regMemName              = regMemFile[:-4]
                    orgFile = open( filePath, mode='r', encoding='UTF-8' )
                    regFldList              = []
                    memFldList              = []
                    # 1 go through lines of file to get the number of entries and each field
                    lines = orgFile.readlines()
                    # 1.1 parser the first line
                    fldsOfLine = lines[0].split('\t')
                    if len( fldsOfLine ) < 4 or fldsOfLine[2] != 'EntryNumber':
                        print(" Format of first line ERROR. It should be Name\tReg/MemName\tEntryNumber\tDecimalNumber, but is {0}".format( lines[0] ) )
                        orgFile.close()
                        sys.exit()
                    numOfEntries = int( fldsOfLine[-1].strip() )
                    if numOfEntries == 1:               # 1.1.1 It is register
                        regFldList.append( "\n\nFields\tOffset\tHiBit\tLoBit\tReadOnly\tReadIndicate\tWriteIndicate\tWriteOneIndicate\tDescription\t{0}\n".format( regMemName ) )
                        fldPtr              = regFldList
                    elif numOfEntries > 1:              # 1.1.2 It is memery
                        memFldList.append( "\n\nMemRegFields\t{0}\nFields\tOffset\tHiBit\tLoBit\tReadTrigger\tWriteTrigger\tDescription\n".format( regMemName ) )
                        fldPtr              = memFldList
                    else: 
                        print( "Fail to parser line %s".format( lines[0] ) )
                        orgFile.close()
                        sys.exit()
                    orgFile.close()

                    wordOffset              = 0
                    rsvIdx                  = 0
                    bitOffset               = 0
                    numOfWords              = 0
                    # 1.2 Go throngh from the second line
                    for line in lines[1:]:
                        if len( line.strip() ) == 0:            # empty line bypass
                            continue
                        fldsOfLine = line.split( '\t' )
                        # 1.2.1 get field name from the first column
                        ret                 = fldNamePtn.match( fldsOfLine[0] )
                        if ret:
                            fldName         = ret.group(1)
                            #1.2.2 get width 
                            if ret.lastindex == 3:          #egName[3:0]
                                width       = int( ret.group(2) ) - int( ret.group(3) ) + 1
                            elif ret.lastindex == 1:        #egName
                                width       = 1
                        # 1.2.0 parse io flag, default value and specified description which are from column 2 to 4 optional
                        dscpStr             = "{0} field".format( fldName )
            
                        try:
                            if len( fldsOfLine[3].strip() ):
                                dscpStr = fldsOfLine[3].strip()     # delete enter of the line end
                        except IndexError:
                            print( '-----------------less than 4 colume', line );

                        defaultVal      = 0
                        if numOfEntries == 1: 
                            ioFlag          = "N\tN\tN\tN"  
                            if len( fldsOfLine[1] ):
                                if ioPtn.match( fldsOfLine[1] ):
                                    if fldsOfLine[1] == 'RO':
                                        ioFlag  = "Y\tN\tN\tN"  
                                    elif fldsOfLine[1] == 'RI':
                                        ioFlag  = "N\tY\tN\tN"  
                                    elif fldsOfLine[1] == 'WI':
                                        ioFlag  = "N\tN\tY\tN"  
                                    elif fldsOfLine[1] == 'IW':
                                        ioFlag  = "Y\tN\tY\tN"  
                                    elif fldsOfLine[1] == 'WO':
                                        ioFlag  = "N\tN\tN\tY"  
                            if len( fldsOfLine[2] ):
                                ret2            = hexPtn.match( fldsOfLine[2] )
                                if hexPtn.match( fldsOfLine[2] ):
                                    defaultVal  = int( ret2.group(1), base=16 )
                        elif numOfEntries > 1:
                            ioFlag          = 'N\tN'
                        
                        defValStr           = ''
                        numWords            = (width + bitOffset) >> 5
                        wordRemainder       = (width + bitOffset) & 31;
                        if numWords == 0:                                   # into current word
                            if numOfEntries == 1: 
                                defValStr   = "\t{0}'h{1:x}".format( width, defaultVal )
                            fldPtr.append( "{0}\t{1:d}\t{2:d}\t{3:d}\t{4}\t{5}{6}\n".format(fldName, wordOffset, bitOffset + width -1, bitOffset, ioFlag, dscpStr, defValStr ) )
                            bitOffset      += width
                        elif numWords > 0 :                                 # crose current word
                            if numOfEntries == 1: 
                                defValStr   = '\t{0}\'h{1:x}'.format( 32 - bitOffset, defaultVal & ( (1<<(32-bitOffset))-1) ) 
                            fldPtr.append( "{0}\t{1:d}\t{2:d}\t{3:d}\t{4}\t{5}{6}\n".format(fldName, wordOffset, 31, bitOffset, ioFlag, dscpStr, defValStr ) )
                            wordOffset     += 1
                            bitOffset       = 0
                            for i in range( numWords-1 ):
                                fldPtr.append( "{0}W{1:d}\t{2:d}\t31\t0\t{3}\t{4}\t{5}'h{6:x}\n".format(fldName, i, wordOffset, ioFlag, dscpStr, 32, defaultVal ) )
                                wordOffset += 1
                                bitOffset   = 0
                            if wordRemainder > 0 :                          # tail part
                                if numOfEntries == 1: 
                                    defValStr   = '\t{0}\'h{1:x}'.format( wordRemainder, defaultVal >> (width-wordRemainder) )
                                fldPtr.append( "{0}Hi\t{1:d}\t{2:d}\t{3:d}\t{4}\t{5}{6}\n".format(fldName, wordOffset, wordRemainder-1, 0, ioFlag, dscpStr, defValStr ) )
                                bitOffset   = wordRemainder;

                    # calculate the used words number
                    totalBitNum       = 0;
                    if bitOffset > 0:
                        numOfWords = wordOffset + 1
                    else:
                        numOfWords = wordOffset

                    if numOfEntries * numOfWords > maxUsedWords: 
                        maxUsedWords = numOfEntries * numOfWords

                    tmp            = wordOffset * 32 + bitOffset;
                    if numOfEntries == 1:
                        regStatStr += "{0}\t{1:d}\t{2:d}\t{3}\n".format( regMemName, tmp, numOfEntries, numOfEntries * tmp ) 
                        for itm in regFldList:
                            regFldStr += itm
                        regList.append( "{0} {1:d}".format(regMemName, numOfWords) )
                        if numOfWords > maxRegWords:
                            maxRegWords = numOfWords
                    elif numOfEntries > 1:
                        memStatStr += "{0}\t{1:d}\t{2:d}\t{3}\n".format( regMemName, tmp, numOfEntries, numOfEntries * tmp ) 
                        if len( memFldList ) > 2:
                            memFldList[1] = memFldList[1].replace( "N\tN", "Y\tN", 1 )
                            memFldList[-1] = memFldList[-1].replace( "N\tN", "N\tY", 1 )
                        else:
                            memFldList[1] = memFldList[1].replace( "N\tN", "Y\tY", 1 )
                        memList.append( "{0} {1:d} {2:d}".format( regMemName, numOfWords, numOfEntries ) )
                        for itm in memFldList:
                            memFldStr += itm
                    # generate .h file for sdk platform
                    fldDefineStr += generateFldDef( regMemName, fldPtr )

            modAddrBitWid = len( bin( len( memList ) ) ) - 2                        # All registers are treated as one Memory, so no minus 1
            totalAddrBitWid = len( bin( maxUsedWords-1 ) ) - 2 + modAddrBitWid
            if totalAddrBitWid < 15:
                totalAddrBitWid = 15;
            # 2.0 record one file for calculating address
            titleStr += "FileName\tPrefix\tAddrUpper\tAddrLower\tFlopInput\n{0}Reg\t{1}_\t{2:d}\t2\tY".format( moduleName, moduleName.upper(), totalAddrBitWid+1 )
            memIdx = 0
            if len( memList ) > 0:
                memDescStr += "\n\nRegMem\tFullName\tNumOfEntries\tWords\tMemAddrBits\tDecodeAddress\tDescription"
                for item in memList:
                    infoAry = item.split()
                    name = infoAry[0]
                    width = int( infoAry[1] )
                    depth = int( infoAry[2] )
                    # Generate decodeAddress
                    depBitsNum = len( bin( depth-1 ) ) - 2                  # bin( 9 ) = 0b1001
                    addressStr = decodeAddress( totalAddrBitWid, modAddrBitWid, memIdx, width * depth )
                    memDescStr += "\n{0}\t{0}\t{1:d}\t{2:d}\t{3:d}\t{4}\t{0} RamTable".format( name, depth, width, depBitsNum, formatAddress(totalAddrBitWid, addressStr))
                    memIdx += 1
            regIdx = 0
            if len( regList ) > 0:
                regDescStr += "\n\nRegister\tFullName\tWords\tDecodeAddress\tDescription"
                regIdx = 0
                regNumBits = len( bin( len( regList ) - 1 ) ) - 2
                maxRegAddrBits = len( bin( maxRegWords - 1 ) ) - 2
                regHiAddr = '{0:0{1}b}'.format( memIdx, modAddrBitWid ) + '0' * (totalAddrBitWid - modAddrBitWid - regNumBits - maxRegAddrBits )
                for item in regList:
                    infoAry = item.split()
                    name = infoAry[0]
                    width = int( infoAry[1] )
                    addressStr = decodeAddress( regNumBits + maxRegAddrBits, regNumBits, regIdx, width )
                    regDescStr += '\n{0}\t{0}\t{1:d}\t{2}\t{0}'.format( name, width, formatAddress( totalAddrBitWid, regHiAddr + addressStr ) )
                    regIdx += 1

            # 3 write regtxt file
            wrf = open( os.path.join(outDir, '{0}Reg.txt'.format( moduleName ) ), mode='w' )
            wrf.write( titleStr )
            wrf.write( memDescStr )
            wrf.write( memFldStr )
            wrf.write( regDescStr )
            wrf.write( regFldStr )
            wrf.close()
            
    # extract memory size
    wrf =  open( os.path.join(outDir, 'memorySize.txt'), mode='w' )
    wrf.write( memStatStr )
    wrf.write( regStatStr )
    wrf.close()
    # output field definition file
    wrf = open( os.path.join( outDir, 'fieldDef.h' ), mode = 'w' )
    wrf.write( fldDefineStr )
    wrf.close()

def decodeAddress( totalBits, diffBits, idx, size ):
    diffAddr = '{0:0{1}b}'.format( idx, diffBits )
    if size == 1:
        usedBits = 0
    else:
        usedBits = len( bin( size - 1 ) ) - 2           #bin(5) = 0b101
    usedAddr = '?' * usedBits
    padStr = '0' * ( totalBits - diffBits - usedBits )
    return diffAddr + padStr + usedAddr

def formatAddress( length, addrStr ):
    remainder = ( length - 2 ) % 4
    retStr = addrStr[:remainder]
    for i in range( remainder, length, 4 ):
        retStr += '_' + addrStr[i:i+4]
    tmpStr = "{0}'b{1}".format( length, retStr )                # format to 27'b0_0000_0000_0000_0000_00??_????_??
    return tmpStr.replace( "b_", "b" )

def getHexAddrBase( bitStr, mName ):
    tmpstr = bitStr.replace( '?', '0' )
    return '{0:#x}'.format( int( '0b'+tmpstr, base=2) * 4 + ModuleAddressDict.get(mName, 0x40080000) )

def underlinedUpperStr( orgName ):
    field = ""
    for i in range( len( orgName ) - 1 ):
        if ( orgName[i].isdigit() or orgName[i].islower() ) and orgName[i+1].isupper():
            field = field + orgName[i] + "_"
        else:
            field = field + orgName[i]
    field = field + orgName[-1:]
    return field.upper()

def generateFldDef( name, fldList ):
    content   = ''
    hi        = 0
    lo        = 0
    upperName = underlinedUpperStr( name )
    for item in fldList[1:]:
        flds  = item.split( '\t' )
        width = int( flds[2] ) - int( flds[3] ) + 1
        upperFld = underlinedUpperStr( flds[0] )
        midStr   = '{0}_{1}_RANGE'.format( upperName, upperFld )
        content += '`define    {0:<64s} {1:d}:{2:d}\n'.format( midStr, hi+width-1, lo )
        midStr   = '{0}_{1}_WIDTH'.format( upperName, upperFld )
        content += '`define    {0:<64s} {1:d}\n\n'.format( midStr, width )
        hi += width
        lo += width
    
    prefixStr  = '// {0}\n'.format( name )
    tmpStr     = '{0}_RANGE'.format( upperName )
    prefixStr += '`define    {0:<64s} {1:d}:0\n'.format( tmpStr, hi-1 )
    tmpStr     = '{0}_WIDTH'.format( upperName )
    prefixStr += '`define    {0:<64s} {1:d}\n\n'.format( tmpStr, hi )
    return prefixStr + content

def generateStruct( modName, fldList ):
    name   = modName
    if modName in SharedStruct :
        name  = SharedStruct.get( modName )
    if name not in GeneratedList :
        GeneratedList.append( name )
        retStr = "\ntypedef struct {\n"
        for item in fldList[1:]:
            flds = item.split( '\t' )
            retStr += '\tuint32_t {0:20} : {1};\n'.format( flds[0], int( flds[2] ) - int( flds[3] ) + 1 )
        retStr += "}} __attribute__(( aligned( sizeof(int) ) )) t{0};\n".format( name )
        return retStr
    else :
        return ''

def generateIoFunc( modName, fldList, entryNum ):
    typeName    = SharedStruct.get( modName, modName )
    # print function
    retStr = '\nuint32_t print{0}( char *fmtStr, void *data ) {{\n'.format( modName )
    retStr += '\tassert( data != NULL );\n\tassert( fmtStr != NULL );\n'
    retStr += '\tt{0} *ptr = ((t{0} *)data);\n'.format( typeName )
    fmtTmp = '\tsprintf( fmtStr, "Field(s) of {0}:\\n'.format( modName )
    varTmp = ''
    for item in fldList[1:]:
        flds = item.split( '\t' );
        fmtTmp += '{0:>20}: 0x%x;\\n '.format( flds[0] )
        varTmp += ', ptr->{0}'.format( flds[0] )
    retStr += '{0}"{1} );\n'.format(fmtTmp, varTmp)
    retStr += '\treturn strlen(fmtStr);\n}\n'

    # read function
    retStr += '\nint32_t  read{0}( tMemRegHdr *memPtr, uint32_t index, void *output, uint8_t fromWhere ) {{\n'.format( modName )
    retStr += '\tassert( output != NULL );\n'
    retStr += '\tif( index >= memPtr->entryNum.entries ) {\n'
    retStr += '\t\tservLogError( "ERROR: out of range {0}, max %" PRIu64 " but %d\\n", memPtr->entryNum.entries-1, index );\n'.format( modName )
    retStr += '\t\treturn -1;\n'
    retStr += '\t}\n'
    retStr += '\tpthread_rwlock_rdlock( memPtr->rwLockList + index );\n'
    retStr += '\tmemcpy( output, ((t{0} *)(memPtr->entryList)) + index, sizeof( t{0}) );\n'.format( typeName )
    retStr += '#ifdef USING_HARDWARE\n'
    retStr += '\treadHwEntry( output, memPtr, index, sizeof(t{0}), fromWhere );\n'.format( typeName )
    retStr += '#endif\n'
    retStr += '\tpthread_rwlock_unlock( memPtr->rwLockList + index );\n'
    retStr +='\treturn sizeof( t{0} );\n}}\n'.format(typeName)

    # field set function
    retStr += '\nint32_t fldSet{0} ( void *data, uint32_t nflds, char *flds[] ) {{\n'.format( modName )
    retStr += '\tt{0} *ptr = (t{0} *)data;\n'.format( typeName )
    retStr += '\tint i      = 0;\n'
    retStr += '\tint num    = 0;\n'
    retStr += '\tint wrFlag = 0;\n'
    retStr += '\tchar buf[128]       = {0};\n'
    retStr += '\tchar *assignExpr[2] = {NULL};\n'
    retStr += '\tfor ( i = 0; i < nflds; i++ ) {\n'
    retStr += '\t\tstrcpy( buf, *(flds + i) );\n'
    retStr += '\t\tnum = split(buf, "= ", assignExpr );\n'
    retStr += '\t\tif ( num != 2 ) {\n'
    retStr += '\t\t\tservLogError( "ERROR: illegal assignment expression [%s].\\n", *(flds + i) );\n'
    retStr += '\t\t} else {\n'
    i = 0
    for item in fldList[1:]:
        flds = item.split( '\t' );
        if i == 0: 
            retStr += '\t\t\tif( strcasecmp( *assignExpr, "{0}" ) == 0 ) {{\n'.format( flds[0] )
        else: 
            retStr += '\t\t\t}} else if( strcasecmp( *assignExpr, "{0}" ) == 0 ) {{\n'.format( flds[0] )
        retStr += '\t\t\t\tptr->{0} = strtoul( *(assignExpr + 1), NULL, 0 );\n'.format( flds[0] )
        retStr += '\t\t\t\twrFlag   = 1;\n'.format( flds[0] )
        i   = i + 1;
    retStr += '\t\t\t} else {\n'
    retStr += '\t\t\t\tservLogWarn( "Warning: unknown field typeName %s in {0}.\\n", *(flds + i) );\n'.format( modName )
    retStr += '\t\t\t}\n\t\t}\n\t}\n\treturn wrFlag;\n}\n'

    #field get function
    retStr += '\nuint32_t fldGet{0} ( tMemRegHdr *memPtr, uint32_t index, char *fldName, void *output, uint8_t fromWhere) {{'.format(modName)
    retStr += '\tif( index >= memPtr->entryNum.entries ) {\n'
    retStr += '\t\tservLogError( "ERROR: out of range {0}, max %" PRIu64 " but %d\\n", memPtr->entryNum.entries-1, index );\n'.format( modName )
    retStr += '\t\treturn -1;\n\t}\n'
    retStr += '\tt{0} tmpData = {{0}};\n\tpthread_rwlock_rdlock( memPtr->rwLockList + index );\n'.format( typeName )
    retStr += '\tmemcpy(&tmpData, ((t{0} *)(memPtr->entryList)) + index, sizeof( t{0} ) );\n'.format( typeName )
    retStr += '#ifdef USING_HARDWARE\n'
    retStr += '\treadHwEntry( &tmpData, memPtr, index, sizeof(t{0}), fromWhere );\n'.format( typeName )
    retStr += '#endif\n\tpthread_rwlock_unlock( memPtr->rwLockList + index );\n'
    i = 0
    for item in fldList[1:]:
        flds = item.split( '\t' );
        if i == 0: 
            retStr += '\tif (strcasecmp( fldName, "{0}" ) == 0) {{\n'.format(flds[0])
        else:
            retStr += '\t}} else if (strcasecmp( fldName, "{0}" ) == 0) {{\n'.format(flds[0])
        retStr += '\t\t*((uint32_t *)output) = tmpData.{0};\n'.format(flds[0])
        i = i + 1
    retStr += '\t}\n\treturn sizeof(int);\n}\n'

    # write function
    retStr += '\nint32_t  write{0}( tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], uint8_t fromWhere ) {{\n'.format( modName )
    retStr += '\tif( index >= memPtr->entryNum.entries ) {\n'
    retStr += '\t\tservLogError( "ERROR: out of range {0}, max %" PRIu64 " but %d\\n", memPtr->entryNum.entries-1, index );\n'.format( modName )
    retStr += '\t\treturn -1;\n'
    retStr += '\t}\n'
    retStr += '\tpthread_rwlock_wrlock( memPtr->rwLockList + index );\n'
    retStr += '\tt{0} *ptr = ((t{0} *)(memPtr->entryList)) + index;\n'.format( typeName )
    retStr += '\tint modified = fldSet{0}( ptr, parac, parav );\n'.format( modName );
    retStr += '#ifdef USING_HARDWARE\n'
    retStr += '\tif ( modified == 1 ) {\n'
    retStr += '\t\twriteHwEntry( memPtr, index, ptr, sizeof(t{0}), fromWhere );\n'.format( typeName )
    retStr += '\t}\n'
    retStr += '#endif\n'
    retStr += '\tpthread_rwlock_unlock( memPtr->rwLockList + index );\n'
    retStr += '\treturn sizeof( t{0} );\n}}\n'.format( typeName )
    
    # set function
    retStr += '\nint32_t set{0} ( tMemRegHdr *memPtr, uint32_t index, void *data, uint8_t fromWhere ) {{\n'.format( modName )
    retStr += '\tassert( data != NULL );\n'
    retStr += '\tif( index >= memPtr->entryNum.entries ) { \n'
    retStr +='\t\tservLogError( "ERROR: out of range {0}, max %" PRIu64 " but %d\\n", memPtr->entryNum.entries-1, index );\n'.format( modName )
    retStr +='\t\treturn -1;\n'
    retStr +='\t}\n'
    retStr += '\tpthread_rwlock_wrlock( memPtr->rwLockList + index );\n'
    retStr +='\tmemcpy( ((t{0} *)(memPtr->entryList)) + index, data, sizeof( t{0}) );\n'.format( typeName )
    retStr += '#ifdef USING_HARDWARE\n'
    retStr += '\twriteHwEntry(  memPtr, index, data, sizeof(t{0}), fromWhere );\n'.format( typeName )
    retStr += '#endif\n'
    retStr += '\tpthread_rwlock_unlock( memPtr->rwLockList + index );\n'
    retStr +='\treturn sizeof( t{0} );\n}}\n'.format( typeName )


    # reset function
    retStr += '\nint32_t reset{0}( tMemRegHdr *memPtr, uint8_t chgData ) {{\n'.format( modName )
    retStr += '\tif( chgData ) {\n'
    retStr += '\t\tif( memPtr->entryList != NULL ) {\n'
    retStr += '\t\t\tfree( memPtr->entryList );\n'
    retStr += '\t\t}\n'
    retStr += '\t\tt{0} *ptr = (t{0} *)malloc( sizeof( t{0} ) * memPtr->entryNum.entries );\n'.format( typeName )
    retStr += '\t\tassert( ptr != NULL );\n'
    retStr += '\t\tmemset( ptr, 0, sizeof(t{0}) * memPtr->entryNum.entries );\n'.format( typeName )
    if( entryNum == 1 ):
        for item in fldList[1:]:
            flds = item.split( '\t' )
            val  = flds[-1].split( 'h' )
            retStr += '\t\tptr->{0:24} = 0x{1};\n'.format( flds[0], val[1].strip() ); 
    retStr += '\t\tmemPtr->entryList  = ptr;\n'
    retStr += '\t\tif( memPtr->rwLockList != NULL ) {\n'
    retStr += '\t\t\tfree( memPtr->rwLockList );\n'
    retStr += '\t\t}\n'
    retStr += '\t\tpthread_rwlock_t *lockPtr = (pthread_rwlock_t *)malloc( sizeof(pthread_rwlock_t) * memPtr->entryNum.entries );\n'
    retStr += '\t\tassert( lockPtr != NULL );\n'
    retStr += '\t\tint i = 0;\n'
    retStr += '\t\tfor ( i = 0; i < memPtr->entryNum.entries; i++ ) {\n'
    retStr += '\t\t\tpthread_rwlock_init( lockPtr + i,  NULL );\n'
    retStr += '\t\t}\n'
    retStr += '\t\tmemPtr->rwLockList = lockPtr;\n'
    retStr += '\t}\n\n'
    retStr += '\tif( memPtr->fldNameList != NULL ) {\n'
    retStr += '\t\tfree( memPtr->fldNameList );\n'
    retStr += '\t}\n'
    retStr += '\tchar **strAry = (char **)malloc( sizeof(char *) * {0} );\n'.format( len( fldList ) )
    retStr += '\tassert( strAry != NULL );\n'
    i = 0
    for item in fldList[1:]:
        flds = item.split( '\t' )
        retStr += '\t*(strAry+{1:d})     = "{0}";\n'.format( flds[0], i );
        i    = i + 1
    retStr += '\t*(strAry+{0:d})     = NULL;\n'.format( i );
    retStr += '\tmemPtr->fldNameList  = strAry;\n'
    retStr += '\treturn 0;\n'
    retStr += '}\n'

    # destroy function
    retStr += '\nint32_t destroy{0}( tMemRegHdr *memPtr ) {{\n'.format( modName )
    retStr += '\tif( memPtr->entryList != NULL ) {\n'
    retStr += '\t\tfree( memPtr->entryList );\n'
    retStr += '\t}\n'
    retStr += '\tmemPtr->entryList = NULL;\n'
    retStr += '\tif( memPtr->fldNameList != NULL ) {\n'
    retStr += '\t\tfree( memPtr->fldNameList );\n'
    retStr += '\t}\n'
    retStr += '\tmemPtr->fldNameList = NULL;\n'
    retStr += '\tif( memPtr->rwLockList != NULL ) {\n'
    retStr += '\t\tint i = 0;\n'
    retStr += '\t\tfor ( i = 0; i < memPtr->entryNum.entries; i++ ) {\n'
    retStr += '\t\t\tpthread_rwlock_destroy( memPtr->rwLockList + i );\n'
    retStr += '\t\t}\n'
    retStr += '\t\tfree( memPtr->rwLockList );\n'
    retStr += '\t}\n'
    retStr += '\tmemPtr->rwLockList = NULL;\n'
    retStr += '\treturn 0;\n'
    retStr += '}\n'
    return retStr

def generateFuncHdr( memName ):
    typeName    = SharedStruct.get( memName, memName )
    retStr  = 'int32_t  read{0}    ( tMemRegHdr *memPtr, uint32_t index, void *output, uint8_t fromWhere );\n'.format( memName )
    retStr += 'int32_t  fldSet{0}  ( void *data, uint32_t nflds, char *flds[] );\n'.format( memName  )
    retStr += 'uint32_t fldGet{0}  (tMemRegHdr *memPtr, uint32_t index,uint8_t *fldName, void *output, uint8_t fromWhere);\n'.format(memName)
    retStr += 'int32_t  write{0}   ( tMemRegHdr *memPtr, uint32_t index, uint16_t parac, char *parav[], uint8_t fromWhere );\n'.format( memName )
    retStr += 'int32_t  set{0}     ( tMemRegHdr *memPtr, uint32_t index, void *data, uint8_t fromWhere );\n'.format( memName )
    retStr += 'uint32_t print{0}   ( char *fmtStr, void *data );\n'.format( memName )
    retStr += 'int32_t  reset{0}   ( tMemRegHdr *memPtr, uint8_t flag );\n'.format( memName )
    retStr += 'int32_t  destroy{0} ( tMemRegHdr *memPtr );\n\n'.format( memName )
    return retStr

def generateRegMemDscp( name, width, depth, addr ):
    retStr  = '\n\thdr = NULL;\n'
    retStr += '\thdr = (tMemRegHdr *)malloc( sizeof( tMemRegHdr ) );\n'
    retStr += '\tassert( hdr != NULL );\n'
    retStr += '\thdr->uid                 = JSHash( "{0}" );\n'.format(name)
    retStr += '\thdr->name                = "{0}";\n'.format( name )
    tmpstr = 'eIRAM'
    if width * depth > 512:
        tmpstr = 'eORAM'
    retStr += '\thdr->type                = {0};\n'.format( tmpstr )
    retStr += '\thdr->widthInQuad         = {0:d};\n'.format( width )
    retStr += '\thdr->granularity         = num2pow( {0:d} );\n'.format( width )
    retStr += '\thdr->entryNum.entries    = {0:d};\n'.format( depth )
    retStr += '\thdr->addrBase.linearAddr = {0};\n'.format( addr )
    retStr += '\thdr->entryList           = NULL;\n\thdr->fldNameList         = NULL;\n\thdr->rwLockList          = NULL;\n'
    retStr += '\thdr->read                = read{0};\n'.format( name )
    retStr += '\thdr->write               = write{0};\n'.format( name )
    retStr += '\thdr->set                 = set{0};\n'.format( name )
    retStr += '\thdr->fldSet              = fldSet{0};\n'.format( name )
    retStr += '\thdr->fldGet              = fldGet{0};\n'.format( name )
    retStr += '\thdr->print               = print{0};\n'.format( name )
    retStr += '\thdr->reset               = reset{0};\n'.format( name )
    retStr += '\thdr->destroy             = destroy{0};\n'.format( name )

    retStr += '\trbMemInsert( root, hdr );\n'
    return retStr
ModuleAddressDict = {
    'IgrHdrAdj'                : 0x60000000,
    'IgrVc'                    : 0x64000000,
    'IgrIntf'                  : 0x68000000,
    'IgrLkup'                  : 0x6c000000,
    'IgrLearn'                 : 0x70000000,
    'IgrPktProc'               : 0x74000000,
    'IgrMeter'                 : 0x78000000,
    'IgrFwd'                   : 0x7c000000,
    'IgrRcvy'                  : 0x7c800000,
    'IgrAging'                 : 0x7d000000,
    'IgrPpShare'               : 0x7d800000,
    'IgrParser'                : 0x7e000000,
    'TcamKey'                  : 0x7e800000,
    'Egr'                      : 0x80000000,
}
SharedStruct = {
    'DsMemAclTsn'              : 'DsMemTsnHandle',
    'DsMemHostRouteLeft'       : 'DsMemHostRoute',
    'DsMemHostRouteRight'      : 'DsMemHostRoute',
    'DsMemHostRouteLeftKey'    : 'DsMemHostRouteKey',
    'DsMemHostRouteRightKey'   : 'DsMemHostRouteKey',
    'DsMemHostRouteLeftValid'  : 'DsMemHostRouteValid',
    'DsMemHostRouteRightValid' : 'DsMemHostRouteValid',
    'DsMemHostTsnLeft'         : 'DsMemTsnHandle',
    'DsMemHostTsnRight'        : 'DsMemTsnHandle',
    'DsMemRouteTsn'            : 'DsMemTsnHandle',
    'DsMemMacAgingLeft'        : 'DsMemMacAging', 
    'DsMemMacAgingRight'       : 'DsMemMacAging', 
    'DsMemMacKeyLeft'          : 'DsMemMacKey',
    'DsMemMacKeyRight'         : 'DsMemMacKey',
    'DsMemMacLeft'             : 'DsMemMac',
    'DsMemMacRight'            : 'DsMemMac',
    'DsMemMacStaticLeft'       : 'DsMemMacStatic',
    'DsMemMacStaticRight'      : 'DsMemMacStatic',
    'DsMemMacTsnLeft'          : 'DsMemTsnHandle',
    'DsMemMacTsnRight'         : 'DsMemTsnHandle',
    'DsMemMacValidLeft'        : 'DsMemMacValid',
    'DsMemMacValidRight'       : 'DsMemMacValid',
    'DsMemFlowColorStats'      : 'DsMemColorStats',
    'DsMemPortColorStats'      : 'DsMemColorStats',
    'DsMemFlowPolicer'         : 'DsMemPolicer',
    'DsMemPortPolicer'         : 'DsMemPolicer',
    'DsMemFlowPolicerCntl'     : 'DsMemPolicerCntl',
    'DsMemPortPolicerCntl'     : 'DsMemPolicerCntl',
    'DsMemIndvRcvyCfg'         : 'DsMemRcvyCfg',
    'DsMemStreamRcvyCfg'       : 'DsMemRcvyCfg',
    'DsMemIndvRcvyCnt'         : 'DsMemRcvyCnt',
    'DsMemStreamRcvyCnt'       : 'DsMemRcvyCnt',
    'DsMemIndvRcvySeq'         : 'DsMemRcvySeq',
    'DsMemStreamRcvySeq'       : 'DsMemRcvySeq',
}
GeneratedList = []


import os
import sys, getopt

pwd = '.'
if __name__ == "__main__":
    if len( sys.argv ) < 2:
        print( "genReg.py -i <orgregDir> -o <outputDir> -d <headerDir> -l <libraryDir>" )
        sys.exit()
    print( os.getcwd() )
    pwd = os.getcwd()
    inputDir   = "."
    outputDir  = "."
    hdrDir     = '.'
    libDir     = '.'
    
    try:
        opts, args = getopt.getopt( sys.argv[1:], "hi:o:d:l:", ["help", "indir=", "outdir="] )
    except getopt.GetoptError:
        print( "genReg.py -i <orgregDir> -o <outputDir> -d <headerDir> -l <libraryDir>" )
        sys.exit()
        
    for opt, arg in opts:
        if opt == "-h":
            print( "genReg.py -i <orgregDir> -o <outputDir> -d <headerDir> -l <libraryDir>" )
            sys.exit()
        elif opt in ( "-i", "--indir" ):
            inputDir = arg
            if arg.endswith( '/' ):
                inputDir      = arg[:-1];
        elif opt in ( "-o", "--outdir" ):
            outputDir         = arg
            if arg.endswith( '/' ):
                outputDir     = arg[:-1]
        elif opt in ( "-d", "--hdrdir" ):
            hdrDir            = arg
            if arg.endswith( '/' ):
                hdrDir        = arg[:-1]
        elif opt in ( "-l", "--libdir" ):
            libDir            = arg
            if arg.endswith( '/' ):
                libDir        = arg[:-1]
# read fromWhereal reg/mem files 
    readOrgFiles( inputDir, outputDir, hdrDir, libDir )
    print( "-------------------------Total Structure {0:d}".format( len( GeneratedList ) ) )
