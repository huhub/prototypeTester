/*
 * Software Development Kit for Fisilink
 * @file: hash.h
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __HASH_H
#define __HASH_H

/** hash functioni of SDB */
unsigned int sdbmHash(char *str);

/** hash functioni of RS */
unsigned int rsHash(char *str);

/** hash functioni of JS */
unsigned int jsHash(char *str);

/** hash functioni of PJW */
unsigned int pjwHash(char *str);

/** hash functioni of ELF */
unsigned int elfHash(char *str);

/** hash functioni of BKDR */
unsigned int bkdrHash(char *str);

/** hash functioni of DJB */
unsigned int djbHash(char *str);

/** hash functioni of AP */
unsigned int apHash(char *str);

#endif
