/**
 * Software Development Kit for Fisilink
 * @file: rpccli.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <log/sdklog.h>
#include <const.h>
#include <strutil.h>

static int getCliExecutor(char *cli) {
    uint8_t *retStr = (uint8_t *)calloc(MAX_RESP_LEN, 1);
    assert(retStr != NULL);
    // commands will be excuted on remote server
    if (findSdkCmd(cli) != NULL) {
        servLogInfo("Send CMD: [%s]\n", cli);
        if (rpcSendCli(cli, strlen(cli), retStr) < 0) {
            printf("%s\n", retStr);
        }
    } else {            // commands will be excuted on local
        const tCmd *command = findCommonCmd(cli);
        if(!command) { 
            system(cli);
        } else {
            uint32_t i = 0;
            // find command parameter position
            while(cli[i] && !isspace(cli[i])) {
                i++;
            }
            (*(command->func)) (cli+i, retStr, FROM_CLI);
        }
    }
    free(retStr);
    return 0;
}

void parserCli(char *cli) {
    assert(cli != NULL);
    if (strncmp(cli, "source", 6) == 0) {
        // read file
        char *argv[2] = {NULL};
        uint8_t argc   = 0;
        argc = split(cli, " ", argv);
        if (argc < 2) {
            printf("Usage: source filePath.\n");
            return -1;
        }

        FILE *fp = fopen(*(argv + 1), "r");
        if (fp != NULL) {
            char line[MAX_SINGLE_LINE];
            while (fgets(line, MAX_SINGLE_LINE, fp) != NULL) {
                if (*line == '#' || *line == '/' || *line == '\n' || *line == '\r') {
                    continue;
                }
                getCliExecutor(line);
            }
            fclose(fp);
        } else {
            servLogError("Error: fopen %s in parserCli\n", *(argv + 1));
        }
    }  else if (strncmp(cli, "loop", 4) == 0) {
        // loop getCliExecutor
        char *argv[MAX_SEG_FLDS] = {0};
        uint8_t argc   = 0;
        argc = split(cli, " ", argv);
        loop = strtoul(*argv[0], NULL, 0);
        for (int i = 0; i < loop; i++) {
            getCliExecutor(cli);
        }
    } else {
        getCliExecutor(cli);
    }
}
