/*
 * Software Development Kit for Fisilink
 * @file: rbmem.h
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __RB_MEM_H
#define __RB_MEM_H

#include "regtbl.h"

/** Initialieze root of read-black tree for Tables and Registers */
struct rb_root *initMemRoot() ;

/** Get red-black tree root */
struct rb_root *getMemRoot() ;

/** Search Table or Register on red-black tree */
tMemRegHdr *searchMem( char *key ) ;

/** Insert on Table or Register on tree */
int insertMem( struct rb_root *root, tMemRegHdr *memTbl ) ;

/** Delete one Table or Register by key */
int deleteMem( char *key ) ;

/** Format red-black tree print */
void printMemTree( ) ;

/** flag: 0 indicates without memory space reallocation. 1 indicates memory reallocation */
int insertEntry( unsigned char flag ) ;

/** Destroy mem red-black tree when exist */
int destroyEntry( ) ;

/** Get Mem/Reg field name for cli completion */
uint32_t getMemRegFldCompletions(char *list[], char *tblName, char *src) ;

/** Get Mem/Reg name for cli completion */
uint32_t getMemRegCompletions(char *list[], char *src) ;

#endif
