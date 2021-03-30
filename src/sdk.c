#include <rbmem.h>
#include <tipcserv.h>
#include <linenoise.h>
#include <linenoiseutil.h>
#include <fileutil.h>
#include <clihdl.h>
#include <sdklog.h>
#include <mem/MemHdrInit.h>

int main(int argc, char *argv[])
{
    if (sdkLogInit() != 0) { 
        return -1;
    }
    servLogInfo("Boot: logger system OK.\n");

    if (initMemHdr() < 0) { 
        return -1; 
    }
    servLogInfo("Boot: init memory OK.\n");

    if (insertEntry(1) < 0) { 
        return -1; 
    }
    servLogInfo("Boot: insert entry OK.\n");

    startupCliService();
    servLogInfo("Boot: init remote cli executor OK.\n");

    startupPktService();
    servLogInfo("Boot: cmodel simulator OK.\n");

    unsigned char path[MAX_FULL_NAME];
    getSdkFileAbsPath(path, "log/sdk_cli_history.txt");
    initLineNoise(path);
    char *line, *cli;
    while ((line = linenoise("client >>")) != NULL) {
        cli = strip(line);
        if (strcmp(cli, "exit") == 0) {
            free(line);
            break;
        }
        if (*cli && strlen(cli) > 0) {
            linenoiseHistoryAdd(cli);
            linenoiseHistorySave(path);
            parserCli(cli);
        }
        free(line);
    }
}
