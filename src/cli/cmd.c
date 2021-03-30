/*
 * Software Development Kit for Fisilink
 * @file: cmd.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */

// commands are used in command line
static int helpUsage(char *argv, void *retVal, uint8_t fromWhere) {
    int i        = 0;
    for(i = 0; (SDK_CMDs + i)->command != NULL; i++) {
        printf("%-16s: %s\r\n", SDK_CMDs[i].command, SDK_CMDs[i].description);
    }
    return 0;
}

static const tCmd SDK_CMDs[] = { 
    { "config",     configCommand, "Integrated SDK command. config: \n\
                      addFdb <mac> <vlanId=digital> <destMap=digital> [...(fields in DsMemMacLeft)]. Add FDB entry at mac+vlanId hashed index and set destMap and another fields according option parameters. \n\
                      addVrf <ipv4/6> <destMap=digital> <vlanId=digital> [...(fields in DsMemRoute and DsMemNexthop)]. Add Host Route entry at ip hashed index and set destMap, vlanId and another fields according option parameters. \n\
                      delFdb <mac> <vlanId=digital>. Delete FDB entry according mac+vlan hashed value. \n\
                      delTcam <TcamTableName> <Index>. Delete TCAM entry by TcamTableName and index. \n\
                      dump <fileName>. Set configuration dump file for configuration dump. \n\
                      log. Load sdk platform config from configuration file. \n\
                      macVlan <mac=digital> <vlan=digital> [...(fields in DsMemMacVasedVlan)]. Add MAC-based Vlan entry at mac hashed index and set vlan and any another fields according option paramenters. \n\
                      qos <port=port> [mode={WDRR|SP}|portBw=(digital)K|M|G] [ q[0~7]=[weigth|(digital)K|M|G] ]. \n\
                      queThrd <wredEn=0|1> [port=port] [queue=queue] [start=startDropThrd] [end=endDropThrd]. \n\
                      tsn <mac=macAddr> <vlanId=digital> <inPort=digital> <destMap=digital> <class=A|B|C|D> <cycleTime=digital(us)> \n\
                      [maxSDU=digital] [ip=ipaddr] [openTime=digital(us)] [baseTime=yyyy-mm-dd@HH:MM:SS] [startOffset=digital(us)]. \n\
                      Config one TSN stream which is clarified by parameters." 
  },
    { "inspectMem", inspectMem,    "Inspect memory value as field:value format. inspectMem <tableName> <index>"                               },
    { "readField",  readField,     "Read fieldName value from index entry of tableName.readField <tableName> <index> <fieldName>"             },
    { "readMem",    readMem,       "Read entire table or register value by tableName and index. readMem <tableName> <index>"                  },
    { "resetMem",   resetMem,      "Reset entire sdk data memory. resetMem <1|0>"                                                             },
    { "showDbg",    showSysDetail, "Show debug info according type. showDbg <init|inout|integ|proc|sch|tsn|version> [portStr|all]"            },
    { "showIntr",   showInterrupt, "show Interrupt filed name. showIntr <CtlName|all>"                                                        },
    { "writeMem",   writeMem,      "Write tableName memory at index to set field with value. writeMem <tableName> <index> [field=digital]..." },
    { "viewMIB",    viewMibInfo,   "Show MIB info according parameter. viewMIB <RxSum|RxRange|TxSum|TxRange|TxError|all> <$portName>"         },
    { "help",          helpUsage,     "Show all commands"                 },
    { "?",             helpUsage,     "Show all commands"                 },
#if USING_HW == 1
    { "cpuSendPkt", cpuSendPacket, "Send special packet from cpu port. cpuSendPkt <Hex packet string>"                                        },
    { "cpuRecvPkt", cpuRecvPacket, "Receive packet from cpu port. cpuSendPkt <0|n>, 0 receive continuously, n max receive packet number."     },
#endif
    { (char *)NULL, NULL,          (char *)NULL                                                                                               }
};

const tCmd *getSdkCmdList()  {
    return SDK_CMDs;
}

const tCmd *findCmd(char *name) {
    register unsigned int i;
    const tCmd *ptr = NULL;
    for (i = 0; SDK_CMDs[i].command != NULL; i++) {
        if (strncmp(name, SDK_CMDs[i].command, strlen(SDK_CMDs[i].command)) == 0) {
            ptr = SDK_CMDs[i];
            break;
        }
    }
    return ptr;
}
