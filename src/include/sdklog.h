/*
 * Software Development Kit for Fisilink
 * @file: sdklog.h
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __SDK_LOG
#define __SDK_LOG
#include "log.h"
#include <stdint.h>

#define servLogDebug(format, ...) _log_write(getServLog(), LOG_DEBUG, format, __FILE__, _STR(__LINE__), ##__VA_ARGS__)
#define servLogInfo(format, ...)  _log_write(getServLog(), LOG_INFO,  format, __FILE__, _STR(__LINE__), ##__VA_ARGS__)
#define servLogWarn(format, ...)  _log_write(getServLog(), LOG_WARN,  format, __FILE__, _STR(__LINE__), ##__VA_ARGS__)
#define servLogError(format, ...) _log_write(getServLog(), LOG_ERROR, format, __FILE__, _STR(__LINE__), ##__VA_ARGS__)
                                                                                       
#define clntLogDebug(format, ...) _log_write(getClntLog(), LOG_DEBUG, format, __FILE__, _STR(__LINE__), ##__VA_ARGS__)
#define clntLogInfo(format, ...)  _log_write(getClntLog(), LOG_INFO,  format, __FILE__, _STR(__LINE__), ##__VA_ARGS__)
#define clntLogWarn(format, ...)  _log_write(getClntLog(), LOG_WARN,  format, __FILE__, _STR(__LINE__), ##__VA_ARGS__)
#define clntLogError(format, ...) _log_write(getClntLog(), LOG_ERROR, format, __FILE__, _STR(__LINE__), ##__VA_ARGS__)

/** get server log handle */
log_t * getServLog() ;

/** get clenet log handle */
log_t * getClntLog() ;

/** log system init */
uint32_t sdkLogInit() ;

/** destroy log */
uint32_t destorySdkLog() ;

/** reconfig log system */
uint32_t loadSdkLogCfg();

#endif
