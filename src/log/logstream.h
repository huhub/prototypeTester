/*
 * Software Development Kit for Fisilink
 * @file: logstream.h
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef _LOG_STREAM_H_
#define _LOG_STREAM_H_

#include "log.h"

#define STYLE_SIZE  64

/** struct for stdout */
typedef struct handle_stream_t {
    char            style[S_LOG_LEVEL][STYLE_SIZE];    ///< style
    FILE*           streams[S_LOG_LEVEL];    ///< stream handles
} handle_stream_t;

#define S_LOG_STREAM_SIZE   sizeof(handle_stream_t)

/** create stdout handle */
void* _stream_handle_create(uint8_t streams);

/** write to stdout */
void write_stream(handle_stream_t* sh, log_level_t level, char* msg);

/** flush stdout */
void stream_handle_flush();

/** destory stdout */
void stream_handle_destory(handle_stream_t* sh);


#endif // !_LOG_STREAM_H_
