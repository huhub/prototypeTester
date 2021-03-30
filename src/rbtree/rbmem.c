/*
 * Software Development Kit for Fisilink
 * @file: rbmem.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <inttypes.h>       // PRIu64
#include "rbtree.h"
#include "regtbl.h"
#include "hash.h"
#include <utils/strutil.h>

static struct rb_root* MemRoot = NULL;

struct rb_root *getMemRoot() {
    return MemRoot;
}

struct rb_root *initMemRoot() {
    if (MemRoot == NULL) {
        MemRoot = (struct rb_root *)calloc(1, sizeof(struct rb_root));
        assert(MemRoot != NULL);
    }
    return MemRoot;
}

static void printMemRegInfo(tMemRegHdr *mem) {
    printf("%s:\r\n", mem->name);
    char *type = NULL;
    switch(mem->type) {
        case eORAM: 
            type = "OUT-CHIP";
            break;
        case eDRAM: 
            type = "DRAM"    ;
            break;
        case eLPM : 
            type = "LPM"     ; 
            break;
        case eTCAM: 
            type = "TCAM"    ; 
            break;
        case eEM  : 
            type = "EM"      ; 
            break;
        case eHASH: 
            type = "HASH"    ; 
            break;
        default   : 
            type = "ON-CHIP" ;
    }
    printf("--------UID:       :%x\r\n", mem->uid);
    printf("--------Type:      :%s\r\n", type);
    printf("--------Width:     :%d word(s)\r\n", mem->usedDwords);
    printf("--------Granularity:%d word(s)\r\n", mem->entrySize);
    printf("--------Entries    :%" PRIu64 "\r\n", mem->entryNum.entries);
    printf("--------AddrBase   :0x%" PRIx64 "\n\r\n", mem->addrBase.linearAddr);
}

void printMemTree() {
    struct rb_node *node;
    struct rb_root *root = getMemRoot();
    tMemRegHdr *mem = NULL;
    for(node = rb_first(root); node; node = rb_next(node)) {
        mem = container_of(node, tMemRegHdr, rbnode);
        printMemRegInfo(mem);
    }
}

int destroyEntry() {
    struct rb_root *root = getMemRoot();
    struct rb_node *node;
    tMemRegHdr *mem = NULL;
    for(node = rb_first(root); node; node = rb_next(node)) {
        mem = container_of(node, tMemRegHdr, rbnode);
        mem->destroy(mem);
        rb_erase(&(mem->rbnode), root);
    }
    free(MemRoot);
    MemRoot = NULL;
    return 0;
}
    
int insertEntry(uint8_t flag) {
    int ret = 0;
    struct rb_root *root = getMemRoot();
    struct rb_node *node;
    tMemRegHdr *mem = NULL;
    for(node = rb_first(root); node; node = rb_next(node)) {
        mem = container_of(node, tMemRegHdr, rbnode);
        if(mem->reset(mem, flag) != 0) {
            printf("Warning: init %s failed\r\n", mem->name);
            ret = -1;
        }
    }
    return ret;
}

tMemRegHdr * searchMem( char *key) {
    struct rb_root *root =  getMemRoot();
    struct rb_node *node = root->rb_node;
    while (node) {
        tMemRegHdr *memNode = container_of(node, tMemRegHdr, rbnode);

//        int result = strcasecmp(key, memNode->name);
        int result = jsHash(key) - memNode->uid;
        if (result < 0) {
            node = node->rb_left;
        } else if (result > 0) {
            node = node->rb_right;
        } else {
            return memNode;
        }
    }
    return NULL;
}

int insertMem(struct rb_root *root, tMemRegHdr *memTbl) {
    struct rb_node **new = &(root->rb_node);
    struct rb_node *parent = NULL;

    /* Figure out where to put new node */
    while (*new) {
        tMemRegHdr *this = container_of(*new, tMemRegHdr, rbnode);

//        int result = strcasecmp(memTbl->name, this->name);
        int result = memTbl->uid - this->uid;
        parent = *new;
        if (result < 0) {
            new = &((*new)->rb_left);
        } else if (result > 0) {
            new = &((*new)->rb_right);
        } else {
            printf("WARN: %s HASH Confilict to %s\r\n", memTbl->name, this->name);
            return 0;
        }
    }

    /* Add new node and rebalance tree. */
    rb_link_node(&(memTbl->rbnode), parent, new);
    rb_insert_color(&(memTbl->rbnode), root);

    return 0;
}

int deleteMem(char *key) {
    tMemRegHdr *mem      = searchMem(key);
    struct rb_root *root = getMemRoot(); 
    if(!mem) {
        printf("Warning, %s is not found.\r\n", key);
        return -1;
    }
    mem->destroy(mem);
    rb_erase(&(mem->rbnode), root);
    return 0;
}

uint32_t getMemRegFldCompletions(char *list[], char *tblName, char *key) {
    uint32_t len       = 0;
    tMemRegHdr *memHdr = searchMem(tblName);
    if (memHdr != NULL) {
        char **fldHdr = memHdr->fldNameList;
        for (; *fldHdr != NULL; fldHdr++) {
            len += addOneCompletion(list + len, *fldHdr, key);
        }
    }
    return len;
}

uint32_t getMemRegCompletions(char *list[], char *key) {
    uint32_t len         = 0;
    struct rb_node *node = NULL;
    tMemRegHdr *memHdr   = NULL;
    struct rb_root *root = getMemRoot();
    for (node = rb_first(root); node; node = rb_next(node)) {
        memHdr = container_of(node, tMemRegHdr, rbnode);
        len += addOneCompletion(list + len, memHdr->name, key);
    }
    return len;
}
