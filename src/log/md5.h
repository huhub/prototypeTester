/*
 * Software Development Kit for Fisilink
 * @file: md5.h
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef _MD5_H_
#define _MD5_H_

#define MD5_HASHBYTES 16

#ifdef __cplusplus
extern "C" {
#endif

/** MD5 file */
void MD5File(const char *filepath, unsigned char *digest);

/** MD5 file S */
char* MD5File_S(const char *filepath, char *buf);

/** MD5 data */
void MD5Data(const unsigned char *data, unsigned int len, unsigned char *digest);

#ifdef __cplusplus
}
#endif

#endif /* !_MD5_H_ */
