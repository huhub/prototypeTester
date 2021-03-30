/*
 * Software Development Kit for Fisilink
 * @file: cli.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>              // isspace
#include <assert.h>
#include <cli/cmd.h>
#include <log/sdklog.h>
#include <strutil.h>
#include <fileutil.h>
#include <linenoise.h>
#include <const.h>

static uint32_t getCliNameCompletions(char *list[], char *key) {
    const tCmd *cmd     = NULL;
    const tCmd *cmdList = getSdkCmdList();
    uint32_t  index, len = 0;
    for(index = 0; (cmdList + index)->command != NULL; index++) {
        cmd  = cmdList + index;
        len += addOneCompletion(list + len, cmd->command, key);
    }
    return len;
}

static uint32_t getCompletionFromList(char *list[], char *src[], char *key) {
    uint32_t len = 0;
    uint8_t  i   = 0;
    for (i = 0; *(src + i) != NULL; i++) {
        len += addOneCompletion(list + len, *(src + i), key);
    }
    return len;
}

static void cliCompletionCallback(const char *buf, linenoiseCompletions *lc) {
    assert(buf != NULL);
    const uint32_t orgLen = strlen(buf);
    // 1 make commandline one copy
    char *dupStr  = strdup(buf);
    // 2 split command line
    char *cmdSegments[MAX_SEG_FLDS] =  {NULL};
    int segNum = split(dupStr, " ", cmdSegments);
    char *key  = NULL;
    if (segNum > 0 && !isspace(*(buf+orgLen-1))) {  // key is from partial input, eg readMem Ctl, Ctl is key
        key    = cmdSegments[segNum - 1];
    }
    // 3 check input command string
    uint32_t candidateNum = 0;
    char *candidateList[MAX_SEG_FLDS] = {NULL};
    if (orgLen == 0 || (segNum == 1 && !isspace(*(buf+orgLen-1)))) { // command or local files
        candidateNum  = getCliNameCompletions(candidateList, key);
        candidateNum += getCompletionFromList(candidateList + candidateNum, sShellCmd, key);
        candidateNum += getDirFileCompletions(candidateList + candidateNum, key);
    } else if (orgLen > 0) {      //complete according command
        if(strncmp(buf, "readMem", 7) == 0 || strncmp(buf, "writeMem", 8) == 0 || 
            strncmp(buf, "inspectMem", 10) == 0 || strncmp(buf, "readField", 9) == 0) {
            if (segNum > 2) {
                candidateNum = getMemRegFldCompletions(candidateList, *(cmdSegments + 1), key);
            } else {
                candidateNum = getMemRegCompletions(candidateList, key);
            }
        } else if (strncmp(buf, "config tsn", 10) == 0) {
            if (segNum > 2 || (segNum == 2 && isspace(*(buf+orgLen-1)))) {
                candidateNum = getCompletionFromList(candidateList, sTsnParas, key);
            }
        } else if (strncmp(buf, "config addFdb", 13) == 0) {
            if (segNum > 3 || (segNum == 3 && isspace(*(buf+orgLen-1)))) {
                candidateNum = getCompletionFromList(candidateList, sFdbParas, key);
                candidateNum += getMemRegFldCompletions(candidateList + candidateNum, "DsMemMacLeft", key);
            }
        } else if (strncmp(buf, "config addVrf", 13) == 0) {
            if (segNum > 3 || (segNum == 3 && isspace(*(buf+orgLen-1)))) {
                candidateNum  = getCompletionFromList(candidateList, sRouteParas, key);
                candidateNum += getMemRegFldCompletions(candidateList + candidateNum, "DsMemHostRouteLeft", key);
                candidateNum += getMemRegFldCompletions(candidateList + candidateNum, "DsMemNexthop", key);
            }
        } else if (strncmp(buf, "config", 6) == 0)  {
            candidateNum  = getCompletionFromList(candidateList, sConfigCmd, key);
        } else if (strncmp(buf, "showDbg", 7) == 0) {
            if (segNum > 2 || (segNum == 2 && isspace(*(buf+orgLen-1)))) {
                candidateNum = getCompletionFromList(candidateList, sPortStrParas, key);
            } else if (segNum > 1 || (segNum == 1 && isspace(*(buf+orgLen-1)))) {
                candidateNum = getCompletionFromList(candidateList, sDbgTypeParas, key);
            }
        } else if (strncmp(buf, "viewMIB", 7) == 0) {
            if (segNum > 2 || (segNum == 2 && isspace(*(buf+orgLen-1)))) {
                candidateNum = getCompletionFromList(candidateList, sPortStrParas, key);
            } else if (segNum > 1 || (segNum == 1 && isspace(*(buf+orgLen-1)))) {
                candidateNum = getCompletionFromList(candidateList, sMibTypeParas, key);
            }
        } else if (strncmp(buf, "showIntr", 8) == 0) {
            candidateNum = getIntrCompletions(candidateList, key);
        } else {
            candidateNum = getDirFileCompletions(candidateList, key);
        }
    }
        
    uint32_t i = 0;
    char *tmpStr = (char *)malloc(MAX_SINGLE_LINE);
    assert(buf != NULL);
    for (i = 0; i < candidateNum; i++) {
        sprintf(tmpStr, "%s%s", buf, *(candidateList + i));
        linenoiseAddCompletion(lc, tmpStr);
        free(*(candidateList + i));
    }
    free(tmpStr);
    free(dupStr);
}

static char *cliHintsCallback(const char *buf, int *color, int *bold) {
    char *tmp = NULL;
    unsigned char i = 0;
    for (i = 0; *(hintKey + i) != NULL; i++) {
        if (strcasecmp(buf, *(hintKey + i)) == 0) {
            tmp = *(hintStr + i);
        }
    }
    *color = 34;
    *bold  = 0;
    return tmp;
}

void initLineNoise(unsigned char *historyFile) {
    linenoiseSetCompletionCallback(cliCompletionCallback);
    linenoiseSetHintsCallback(cliHintsCallback);
    linenoiseSetMultiLine(1);
    linenoiseHistoryLoad(historyFile);
}
