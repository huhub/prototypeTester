/*
 * Software Development Kit for Fisilink
 * @file: const.h
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */

#ifndef __SDK_CONST_H
#define __SDK_CONST_H

// Used by TIPC buffer size
#define TIPC_MSG_SIZE  10240
#define MAX_RESP_LEN   4096
#define MAX_SINGLE_LINE 1024
#define MAX_SEG_FLDS 256

// used by compareExcept
#define MAX_FULL_NAME   512
#define MAX_PKT_LEN     20480     // 10KByte, Most case are calloc memory for string packet
#define MAX_FILE_NAME   128

static const unsigned int TCAM_ADDRESS = 0x7e800000;  ///< TCAM address base
static const unsigned int FLD_ASSIGN_LEN = 128;  ///< the length of one assignment 

// for tracing the config source
static const unsigned char FROM_CM  = 2;    ///< Indicates from Cmodel
static const unsigned char FROM_TCL = 1;    ///< Indicates from TCL
static const unsigned char FROM_CLI = 0;    ///< Indicates from CLI

#if CFG_DUMP == 1
    static const unsigned char INFO_IGR = 0;     ///< dump config in Ingress
    static const unsigned char INFO_TM  = 1;     ///< dump config in Traffic Manage
    static const unsigned char INFO_EGR = 2;     ///< dump config in Egress
    static const unsigned char IN_PKT   = 0;     ///< dump config incoming packet
    static const unsigned char OUT_PKT  = 1;     ///< dump config delivered packet
#endif 

static const unsigned int SDK_FUNC_CLIENT     = 2;       ///< SDK run as a client
static const unsigned int SDK_FUNC_HARDWARE   = 3;       ///< SDK run on hardware
static const unsigned int SDK_FUNC_PROTOCOL   = 4;       ///< SDK run with SoC protocol stack
static const unsigned int SDK_FUNC_INTERACTION= 5;       ///< SDK run with a command line interaction
static const unsigned int SDK_FUNC_SIMULATOR  = 6;       ///< SDK run with a c-language simulator


const static unsigned int CLI_NAME_TYPE = 0x80000001;
const static unsigned int CLI_NAME_INST = 1000 + INST_OFFSET;
const static unsigned int PKT_NAME_TYPE = 0x70000001;
const static unsigned int PKT_NAME_INST = 3000 + INST_OFFSET;

#endif
