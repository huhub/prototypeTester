/*
 * Software Development Kit for Fisilink
 * @file: checksum.c
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#include <stdint.h>
#include <netinet/in.h>

uint16_t incrUpdChksum16( uint16_t oldChk, uint16_t oldFld, uint16_t newFld ) {
#if 0
    __asm__ __volatile__(
        "notw %1; \n"
        "subw %1, %0; \n"
        "sbbw %2, %0; \n"
        "sbbw $0, %0; \n"
        :"=r" (oldChk)
        :"r"(oldFld), "r"(newFld),"0"(oldFld)
    );
    return oldChk;
#endif 
    unsigned long csum = (~oldChk & 0xFFFF) + (~oldFld & 0xFFFF) + newFld ;
    csum  = (csum >> 16) + (csum & 0xFFFF);
    csum += (csum >> 16);
    return ~csum;
}

//static inline uint32_t ChecksumIncrement32(uint32_t old_value, uint32_t new_value) {
//    uint32_t sum = (~old_value >> 16) + (~old_value & 0xFFFF);
//    sum += (new_value >> 16) + (new_value & 0xFFFF);
//    return sum;
//}
//
//static inline uint16_t FoldChecksum(uint32_t cksum) {
//    cksum = (cksum >> 16) + (cksum & 0xFFFF);
//    cksum += (cksum >> 16);
//    return ~cksum;
//}
//
//static inline uint16_t UpdateChecksumWithIncrement(uint16_t old_checksum, uint32_t increment) {
//    return FoldChecksum((~old_checksum & 0xFFFF) + increment);
//}

uint16_t incrUpdChksum32( uint16_t oldChk, uint32_t oldFld, uint32_t newFld ) {
    uint16_t csum  = incrUpdChksum16( oldChk, (oldFld >> 16) & 0xffff, (newFld >> 16) & 0xffff );
    return incrUpdChksum16( csum, oldFld & 0xffff, newFld & 0xffff );
//    uint32_t tmpOld  = ~oldFld;
//    uint32_t csum    = (~oldChk & 0xffff) + (tmpOld >> 16) + (tmpOld & 0xffff) + (newFld >> 16) + (newFld & 0xffff); 
//    csum             = (csum >> 16) + ( csum & 0xffff);
//    csum            += (csum >> 16);
//    return (~csum & 0xffff);
//    uint32_t inc = ChecksumIncrement32(oldFld, newFld);
//    return UpdateChecksumWithIncrement(oldChk, inc);
}

uint16_t incrUpdChksum64( uint16_t oldChk, uint64_t oldFld, uint64_t newFld ) {
    uint16_t csum   = oldChk;
    int i = 0;
    for ( i = 0; i < 4; i++ ) {
        csum = incrUpdChksum16( csum, (oldFld >> (16 * i)) & 0xffff, (newFld >> (16 *i)) & 0xffff );
    }
    return csum;
}

uint16_t checksum (uint8_t* data, uint16_t len) {
    uint64_t sum = 0;
    uint32_t* p  = (uint32_t*) data;
    uint16_t i   = 0;
    while (len >= 4) {
        sum  = sum + p[i++];
        len -= 4;
    }
    if (len >= 2) { 
        sum  = sum + ((uint16_t*) data)[i * 4];
        len -= 2;
    }
    if (len == 1) {
        sum += data[len-1];
    }

    // Fold sum into 16-bit word.
    while (sum>>16) {
        sum = (sum & 0xffff) + (sum>>16);
    }
    return ntohs((uint16_t)~sum);
}
