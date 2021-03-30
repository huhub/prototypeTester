/*
 * Software Development Kit for Fisilink
 * @file: lz4file.h
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef _LZ4_FILE_H_
#define _LZ4_FILE_H_


/** lz4 compress */
int lz4_file_compress(const char *in_filename, const char *out_filename);

/** file uncompress */
int lz4_file_uncompress(const char *in_filename, const char *out_filename);


#endif  /*!_LZ4_FILE_H_*/
