#pragma once
#ifndef DEFS_H
#define DEFS_H
#include "rint.h"
#ifdef __cplusplus
extern "C" {
#endif




#define C_CALL extern "C"
#define cli() asm volatile("cli")
#define C_CALL_BLOCK(def) extern "C" {def}


#ifndef __cplusplus
#define NULL ((void*)0)
#include <stdbool.h>
#else
#define NULL nullptr
//#define const auto val
//#define auto var
#endif
#include "rint.h"

#define OS_MEM_RANG_S 0xFFFFC000

#define FFUNC(NAME) NAME##_
#define FMOD_FUNC(MODN, NAME) __##MODN##_##MOD##_##NAME

#define RUBE 1526
#define xlim(val, maxn) ((val <= maxn) ? (val) : (maxn))
#define xabs(val) ((val < 0) ? (-val) : (val))
#define IN_IF(IF, DO, ELSE) ((IF) ? (DO) : (ELSE))
#define RUBE_WEAK_CALL __attribute__((weak))
#define SWITCH(val) (val = !val)
#define BIT_TO_BYTE(X) ((X) / 8)
//#define xCON(va, min, max) 
#define rlen(v) (v - 1)
#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet((value), (bit)) : bitClear((value), (bit)))

#define readonly const
//#define final const
#define byte_ref &
#define arrlen(val) (size_t)(sizeof(val) / sizeof(*val))
#define alen(v) rlen(arrlen(v))
typedef bool FLAG;

typedef readonly bool CFLAG;

typedef unsigned long       DWORD;

typedef unsigned char       BYTE;

typedef BYTE BYTE_FLAG;

typedef readonly BYTE CBYTE_FLAG;

typedef unsigned short      WORD;

typedef signed long       SDWORD;

typedef signed char       SBYTE;

typedef signed short      SWORD;

//typedef unsigned short address_t;

#define addr_to_ptr(add) (void*)add

typedef long double ldouble_t;

typedef DWORD EDWORD;



typedef enum e_ERROR_STAT
{
	ER_FAILED = 10,
	ER_SUCCESS = 20,
	ER_UNDEF = 404,
} ERROR_STAT;

typedef struct
{
	ERROR_STAT STAT;
	EDWORD ECODE;
} ERROR_PAK;

#define MK_ECODE(DOM_CODE, SUB_CODE) (DOM_CODE + SUB_CODE)
#define ER_PAK_PLOAD {ER_UNDEF, 0}

#define ER_PAK_INIT(Nn) ERROR_PAK Nn = ER_PAK_PLOAD
#define ER_PAK_FAILED(Nn, X) \
	Nn.ECODE = X; \
    Nn.STAT = ER_FAILED; \
    return Nn

#define ER_PAK_SUCCESS(Nn, X) \
	Nn.ECODE = X; \
    Nn.STAT = ER_SUCCESS; \
    return Nn

#define ER_PAK_UNDEF(Nn, X) \
	Nn.ECODE = X; \
    Nn.STAT = ER_UNDEF; \
    return Nn

#ifdef __cplusplus
}
#endif


#endif