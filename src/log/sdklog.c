/*
 * Software Development Kit for Fisilink
 * @file: sdklog.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <stdint.h>
#include <stdio.h>          // FILE
#include <stdlib.h>
#include <string.h>          
#include "log.h"
#include "logfile.h"
#include <const.h>
#include <strutil.h>
#include <fileutil.h>

typedef struct {
    uint32_t maxPort;

    uint8_t  *log_file_serv_name;
    uint8_t  *log_file_user_name;
    //the maximum number files for stored log
    uint32_t log_max_backup_num;
    uint32_t log_max_file_size;
    //0: NORMAL, 1: encryption, 2: compress
    uint32_t log_store_mode;
    uint32_t log_mirror_stdout_enable;
    //0: debug, 1: info, 2: warning, 3: error, 9: close
    uint32_t log_file_level;
    uint32_t log_stream_level;
    uint32_t log_with_debug_msg;
    //password for encrypt if the necessary
    uint8_t  *log_encrypt_passwd;
} tLogCfg;


static log_t *SERVER_LOG_LIST = NULL;
static log_t *CLIENT_LOG_LIST = NULL;

log_t * getServLog() {
    return SERVER_LOG_LIST;
}

log_t * getClntLog() {
    return CLIENT_LOG_LIST;
}

static uint32_t readCfgFile( tLogCfg *logCfg, uint8_t *cfgName ) {
    uint32_t ret = 0;
    unsigned char path[MAX_FULL_NAME];
    getSdkFileAbsPath(path, cfgName);
    FILE *fp     = fopen(path, "r");
    if (fp == NULL) {
        perror( "fopen in readCfgFile" );
        ret      = 1;
    } else { 
        uint8_t buffer[MAX_SINGLE_LINE];
        char *assign[2] = {NULL};
        uint8_t nFld;
        uint8_t len;
        while (fgets(buffer, MAX_SINGLE_LINE, fp) != NULL) {
            nFld = split(buffer, "=", assign); 
            if (nFld == 2) {
                if (strcmp(assign[0], "log_file_serv_name") == 0) {
                    logCfg->log_file_serv_name = strdup(assign[1]);
                    len = strlen(logCfg->log_file_serv_name);
                    if (logCfg->log_file_serv_name[len-1] == '\n') {
                        logCfg->log_file_serv_name[len-1] = '\0';
                    }
                } else if (strcmp(assign[0], "log_file_user_name") == 0) {
                    logCfg->log_file_user_name = strdup(assign[1]);
                    len = strlen(logCfg->log_file_user_name);
                    if (logCfg->log_file_user_name[len-1] == '\n') {
                        logCfg->log_file_user_name[len-1] = '\0';
                    }
                } else if (strcmp(assign[0], "log_max_backup_num") == 0) {
                    logCfg->log_max_backup_num = strtoul(assign[1], NULL, 0);
                } else if (strcmp(assign[0], "log_max_file_size") == 0) {
                    logCfg->log_max_file_size  = strtoul(assign[1], NULL, 0);
                } else if (strcmp(assign[0], "log_store_mode") == 0) {
                    logCfg->log_store_mode     = strtoul(assign[1], NULL, 0);
                } else if (strcmp(assign[0], "log_mirror_stdout_enable") == 0) {
                    logCfg->log_mirror_stdout_enable = strtoul(assign[1], NULL, 0);
                } else if (strcmp(assign[0], "log_file_level") == 0) {
                    logCfg->log_file_level     = strtoul(assign[1], NULL, 0);
                } else if (strcmp(assign[0], "log_stream_level") == 0) {
                    logCfg->log_stream_level   = strtoul(assign[1], NULL, 0);
                } else if (strcmp(assign[0], "log_with_debug_msg") == 0) {
                    logCfg->log_with_debug_msg = strtoul(assign[1], NULL, 0);
                } else if (strcmp(assign[0], "log_encrypt_passwd") == 0) {
                    logCfg->log_encrypt_passwd = strdup(assign[1]);;
                    len = strlen(logCfg->log_encrypt_passwd);
                    if (logCfg->log_encrypt_passwd[len-1] == '\n') {
                        logCfg->log_encrypt_passwd[len-1] = '\0';
                    }
                }
            }
        }
        fclose(fp);
    }

    return ret;
}

static uint8_t updateFileLogNode(log_t *list, uint8_t *fileName, tLogCfg *cfg) {
    uint8_t updated    = 0;
    log_t *hdr         = list;
    if (hdr != NULL) {
        log_handle_t  *node    = NULL;
        handle_file_t *fHdl    = NULL;
        while(hdr) {
            node = (log_handle_t *)(hdr->data);
            if (node->tag == F_MODE) {
                fHdl = (handle_file_t *)(node->hld);
                if (strcmp(fHdl->file_path, fileName) == 0) {
                    updated              = 1;
                    node->level          = cfg->log_file_level;
                    fHdl->max_file_size  = cfg->log_max_file_size;
                    fHdl->max_bak_num    = cfg->log_max_backup_num;
                    _iobuf_init(fHdl, SINGLE_LOG_SIZE, cfg->log_store_mode, cfg->log_encrypt_passwd);
                } else {
                // delete node
                    node->level          = LOG_CLOSE;
                }
            }
            hdr = hdr->next;
        }
    }
    
    return updated;
}

static uint8_t updateStreamLogNode(log_t *list, uint32_t level) {
    uint8_t updated    = 0;
    log_t *hdr         = list;
    if (hdr != NULL) {
        log_handle_t *node    = NULL;
        while(hdr) {
            node       = (log_handle_t *)(hdr->data);
            if (node->tag == S_MODE) {
                updated     = 1;
                node->level = level;
            }
            hdr = hdr->next;
        }
    }
    return updated;
}

static uint8_t initLogList(log_t **list, tLogCfg *cfg, uint8_t isServ) {
    uint8_t tmpPath[MAX_FULL_NAME];
    uint8_t *fileName = cfg->log_file_serv_name;
    if (isServ == 0) {
        fileName      = cfg->log_file_user_name;
    }
    if (fileName != NULL) { 
        // 1 update log file 
        getSdkFileAbsPath(tmpPath, fileName);
        uint8_t flag = updateFileLogNode(*list, tmpPath, cfg);
        if (flag == 0) {
            log_handle_t *log = file_handle_create(tmpPath, cfg->log_max_file_size, cfg->log_max_backup_num, 
                             SINGLE_LOG_SIZE, cfg->log_store_mode, cfg->log_encrypt_passwd, cfg->log_file_level);
            *list             = add_to_handle_list(*list, (void *)log);
        }
    }
    if (cfg->log_mirror_stdout_enable == 1) {
        uint8_t updateStrm = updateStreamLogNode(*list, cfg->log_stream_level);
        if (updateStrm == 0) {
            void  *strmLog = stream_handle_create(ERROR_STDERR, cfg->log_stream_level);
            strmLog        = set_stream_param(strmLog, LOG_ERROR, FRED, NULL, NULL);
            strmLog        = set_stream_param(strmLog, LOG_DEBUG, FGREEN, NULL, NULL);
            strmLog        = set_stream_param(strmLog, LOG_WARN, FYELLOW, NULL, UNDERLINE);
            *list          = add_to_handle_list(*list, strmLog);
        }
    }
    return 0;
}

uint32_t sdkLogInit() {
    uint32_t ret  = 0;
    // read config file 
    tLogCfg cfg = {0};
    readCfgFile( &cfg, "config/PishonConfig.cfg" );
    // init log file and stream
    setLogDbgInfoFlag(cfg.log_with_debug_msg);
    initLogList(&SERVER_LOG_LIST, &cfg, 1);
    initLogList(&CLIENT_LOG_LIST, &cfg, 0);
    // release tempory config
    if (cfg.log_file_serv_name != NULL) free(cfg.log_file_serv_name);
    if (cfg.log_file_user_name != NULL) free(cfg.log_file_user_name);
    if (cfg.log_encrypt_passwd != NULL) free(cfg.log_encrypt_passwd);
    return ret;
}

uint32_t destorySdkLog() {
    if (SERVER_LOG_LIST != NULL) {
        log_destory(SERVER_LOG_LIST);
        SERVER_LOG_LIST = NULL;
    }
    if (CLIENT_LOG_LIST != NULL) {
        log_destory(CLIENT_LOG_LIST);
        CLIENT_LOG_LIST = NULL;
    }
    return 0;
}

uint32_t loadSdkLogCfg() {
    // init list
    sdkLogInit();     
    return 0;
} 
