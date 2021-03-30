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
#include <clihdl.h>
#include <linenoiseutil.h>
#include <fileutil.h>

int main(int argc, char *argv[])
{
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
