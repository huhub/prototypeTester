/*
 * Software Development Kit for Fisilink
 * @file: log.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/syscall.h>     /* For SYS_xxx definitions */
#include <stdlib.h>
#include <time.h>
#include "error.h"
#include "md5.h"
#include "lz4file.h"
#include "logfile.h"
#include "logstream.h"
#include "log.h"

static const char* const severity[] = { "[DEBUG]", "[INFO]", "[WARN]", "[ERROR]" };
static uint8_t gDebugInfoEnable = 0;

void setLogDbgInfoFlag(uint8_t flag) {
    gDebugInfoEnable = flag;
}

log_handle_t* stream_handle_create(uint8_t streams, uint8_t level) {
    log_handle_t* lh = calloc(1, S_LOG_HANDLE_T);
    if (!lh) exit_throw("failed to calloc!");
    lh->tag   = S_MODE;
    lh->level = level;
    lh->hld   = _stream_handle_create(streams);
    return lh;
}


log_handle_t* file_handle_create(const char* log_filename, size_t max_file_size, size_t max_file_num, size_t max_iobuf_size, uint8_t cflag, const char* password, uint8_t level) {
    log_handle_t* lh = calloc(1, S_LOG_HANDLE_T);
    if (!lh) exit_throw("failed to calloc!");
    lh->tag   = F_MODE;
    lh->level = level;
    lh->hld   = _file_handle_create(log_filename, max_file_size, max_file_num, max_iobuf_size, cflag, password);
    return lh;
}

log_t* add_to_handle_list(log_t* lhs, void* hld) {
    return list_insert_beginning(lhs, hld);
}


void _log_write(log_t *lhs, log_level_t level, const char *format, ...) {
    if (!lhs) {
        error_display("Log handle is null!\n");
        return;
    }

    if (!format) {
        error_display("Log format is null!\n");
        return;
    }

    va_list args;
    va_start(args, format);

    char log_msg[EX_SINGLE_LOG_SIZE] = { 0 };
    uint32_t info_len = 0;

/* debug message */
    if (gDebugInfoEnable == 1) {
        time_t rawtime = time(NULL);
        struct tm timeinfo;
        localtime_r(&rawtime, &timeinfo);
        pid_t tid = syscall(SYS_gettid);
        info_len  = snprintf(log_msg, EX_SINGLE_LOG_SIZE, "%s%04d-%02d-%02d %02d:%02d:%02d <%s :%s>%d : ", severity[level], timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec, va_arg(args, char*), va_arg(args, char*), tid);
    } else {
        info_len  = snprintf(log_msg, EX_SINGLE_LOG_SIZE, "%s<%s :%s>: ", severity[level], va_arg(args, char*), va_arg(args, char*));
    }

    int total_len = vsnprintf(log_msg + info_len, SINGLE_LOG_SIZE - info_len, format, args);
    va_end(args);
    
    if (total_len <= 0 || info_len <= 0 || total_len > SINGLE_LOG_SIZE - info_len) {
        error_display("Failed to vsnprintf a text entry: (total_len) %d\r\n", total_len);
        return;
    }
    total_len += info_len;
    
    log_t *ptrLog = lhs;
    while (ptrLog) {
        log_handle_t *hdl = (log_handle_t*)(ptrLog->data);
        if (hdl->level != LOG_CLOSE && hdl->level <= level) {
            if (hdl->tag == F_MODE) {
                write_file((handle_file_t*)(hdl->hld), log_msg, total_len);
            }
            if (hdl->tag == S_MODE) {
                write_stream((handle_stream_t*)(hdl->hld), level, log_msg);
            }
        }
        ptrLog = ptrLog->next;
    }
}


void log_flush(log_t *lhs) {
    stream_handle_flush();    //stdout flush only once
    while (lhs && (((log_handle_t*)(lhs->data))->tag) == F_MODE) {
        file_handle_flush((handle_file_t*)(((log_handle_t*)(lhs->data))->hld));
        lhs = lhs->next;
    }
}

void log_destory(log_t* lhs) {
    log_handle_t *hdl = NULL;
    while (lhs) {
        hdl = (log_handle_t*)(lhs->data);
        switch (hdl->tag) {
            case F_MODE:
                file_handle_destory((handle_file_t*)(hdl->hld));
                break;
            case S_MODE:
                stream_handle_destory((handle_stream_t*)(hdl->hld));
                break;
            default:
                break;
        }
        lhs = lhs->next;
    }
}

char* log_file_md5(const char* filename, char* digest) {
    assert(filename != NULL);
    return MD5File_S(filename, digest);
}

int log_file_uncompress(const char* src_filename, const char* dst_filename) {
    assert(src_filename != NULL);
    assert(dst_filename != NULL);
    return lz4_file_uncompress(src_filename, dst_filename);
}
