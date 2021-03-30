/*
 * Software Development Kit for Fisilink
 * @file: logfile.h
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef _LOG_FILE_H_
#define _LOG_FILE_H_

#include "log.h"

/** handle file structure */
typedef struct {
    uint8_t         *wkey;      ///< key
    int             cflag;      ///< flag
    char            *file_path;      ///< log file path
    FILE            *f_log;      ///< log file 
    char            *io_buf;      ///< io buffer
    size_t          io_cap;      ///< io cap
    size_t          max_file_size;      ///< maximum file size
    size_t          cur_file_size;      ///< current file size
    size_t          cur_bak_num;      ///< current
    size_t          max_bak_num;      ///< maximum
    pthread_mutex_t mutex;      ///< mutex lock
} handle_file_t;

#define S_LOG_FILE_SIZE sizeof(handle_file_t)

#define AES_128     0x10

#define AES_EX(n)   (((n)&(AES_128-1)) != 0 ? ((n)|(AES_128-1))+1 : (n))

//round up to the next power of 16 for aes
#define EX_SINGLE_LOG_SIZE AES_EX(SINGLE_LOG_SIZE)

/** io buffer init */
int _iobuf_init(handle_file_t * fh, size_t io_ms, int flag, const char* pwd) ;

/** create file handle */
void* _file_handle_create(const char* log_filename, size_t max_file_size, size_t max_file_bak, size_t max_iobuf_size, uint8_t cflag, const char* password);



/**
 * write message to file.
 * @param fh - log flie handle.
 * @param msg - message.
 */
void write_file(handle_file_t *fh, char *msg, size_t len);


/**
 * flush io buffer to file.
 * @param lh - log flie handle.
 */
void file_handle_flush(handle_file_t *lh);

/**
 * destory flie handle.
 * @param lh - log handle.
 */
void file_handle_destory(handle_file_t *lh);



#endif //!_LOG_FILE_H_

