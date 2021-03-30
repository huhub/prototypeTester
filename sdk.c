/*
 * Software Development Kit for Fisilink
 * @file: sdkserver.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <log/sdklog.h>
#include <mem/MemHdrInit.h>

#include <cli/cli.h>
#include <cli/cmd.h>
#include <cli/serv.h>
#include <common/const.h>
#include <common/version.h>
#include <common/strutil.h>
#include <common/fileutil.h>
#include <common/signalhdl.h>
#include <common/linenoise.h>
#include <driver/access.h>
#include <device/chipapi.h>
#include <rpc/rpccli.h>
#include "../cmodel/include/cmodelProcess.h"

static const struct option longOption[] = {
    {"help",       no_argument,       NULL, 'h'},
    {"version",    no_argument,       NULL, 'v'},
    {"fpga",       no_argument,       NULL, 'f'},
    {"simulator",  no_argument,       NULL, 's'},
    {NULL, 0, NULL, 0}
};

static char * const shortOption = "hvfs";

static void showUsage() {
    printf("Usage:\n\
    -h, --help              Output this usage.\n\
    -v, --version           Output SDK version information.\n\
    -f, --fpga              Run SDK on hardware as a server.\n\
    -s, --simulator         Run SDK with C-language simulator.\n\
    ");
}

static unsigned int parseOptions(int argc, char *argv[]) {
    unsigned int flag = 0;
    int opt = 0;
    if ((opt = getopt_long(argc, argv, shortOption, longOption, NULL)) != -1) {
        switch(opt) {
            case 'h':
            case '?':
                showUsage();
                break;
            case 'v':
                printf("%s\n", SDK_VERSION);
                break;
            case 'f':
                flag = SDK_FUNC_FPGA;
                break;
            case 's':
                flag = SDK_FUNC_SIMULATOR;
                break;
            default:
                break;
        }
    }
    return flag;
}

int main(int argc, char *argv[])
{
    unsigned int runFlag = parseOptions(argc, argv);
    // --help or --version options
    if (runFlag == 0) {
        return 0;
    }

    if (sdkLogInit() != 0) { 
        return -1;
    }
    servLogInfo("Boot: logger system OK.\n");

    if (memHdrInit() < 0) { 
        return -1; 
    }
    servLogInfo("Boot: init memory OK.\n");

    unsigned char serverFlag = 1;
    if (runFlag & (1 << SDK_FUNC_CLIENT)) {
        serverFlag = 0;
    }
    if (insertEntry(serverFlag) < 0) { 
        return -1; 
    }
    servLogInfo("Boot: insert entry OK.\n");

//start from here ganbadie!!!
    unsigned char hwFlag = runFlag & (1 << SDK_FUNC_HARDWARE);
    if (hwFlag) { 
        if (startupHardware(0) != 0) {
            return -1; 
        }
        servLogInfo("Boot: hardware OK.\n");
    }
    if (serverFlag) {
        startupMemService();
        startupEngines(0);
        servLogInfo("Boot: memory service OK.\n");
    }
    if (hwFlag) {
        startupHwDaemon();
        setHwDaemonEnable(1);
        servLogInfo("Boot: interrupt service OK.\n");
     }

    unsigned char protocolFlag = runFlag & (1 << SDK_FUNC_PROTOCOL);
    if (protocolFlag) { 
        if (ppsOpen(1) < 0) {
            return -1; 
        }
        ppsEnable(1);
        servLogInfo("Boot: SOC protocol stack OK.\n");
    }

    unsigned char path[MAX_FULL_NAME];
    getSdkFileAbsPath(path, "log/sdk_cmd_history.txt");
    unsigned char cliFlag = runFlag & (1 << SDK_FUNC_INTERACTION);
    if (cliFlag) {
        initLineNoise(path);
        servLogInfo("Boot: init CLI OK.\n");
    }
#if USING_HW == 0 && CENTRAL == 1 
    if (!hwFlag && (runFlag & (1 << SDK_FUNC_SIMULATOR))) {
        initPktProc();
        servLogInfo("Boot: CMODEL simulator OK.\n");
    }
#endif

    if (cliFlag) {
        char *line, *cmd;
        int ret = 0;
        while ((line = linenoise("Server>>")) != NULL) {
            cmd = strip(line);
            if (strcmp(cmd, "exit") == 0) {
                free(line);
                break;
            }
            if (*cmd && strlen(cmd) > 0) {
                linenoiseHistoryAdd(cmd);
                linenoiseHistorySave(path);

                ret = rpcExecCmd(cmd);
                if (ret < 0) {
                    clntLogError("%s executes failed. return %d.\r\n", cmd, ret);
                }
            }
            free(line);
        }
    } else {
        while(~getchar()) { }      // wait for Ctrl + c
    }

    if (protocolFlag) {
        ppsEnable(0);
        int ret = ppsClose(1);
        servLogInfo("SDK stop: SOC protocol stack %s.\n", ret < 0 ? "FAIL" : "OK");
    }

    if (hwFlag) {
        setHwDaemonEnable(0);
        freeRegBus();
        servLogInfo("SDK stop: interrupt and bus OK.\n");
    }
    if (serverFlag) {
        stopEngines();
        servLogInfo("SDK stop: destory engines OK.\n");
    }
    destroyMemTree();
    servLogInfo("SDK stop: destory memory OK.\n");
    destorySdkLog();

    return 0;
}


