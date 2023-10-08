#pragma once
#ifndef DEFS_H
#define DEFS_H

#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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
#define arr(v) v*
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

typedef void* VOID_PTR;
typedef arr(void*) VOID_PTR_ARR;
typedef volatile void* VVOID_PTR;
typedef void(*VOID_FPTR)();

typedef uint8_t address8_t;
typedef uint16_t address16_t;

#define ptr_to_addr8(ptr) (address8_t)ptr
#define ptr_to_addr16(ptr) (address16_t)ptr
#define addr_to_ptr(add) (void*)add

//typedef long double ldouble_t;

typedef WORD EWORD;



typedef enum ERROR_STAT_e
{
	ER_FAILED = 10,
	ER_SUCCESS = 20,
	ER_UNDEF = 404,
} ERROR_STAT;

typedef struct ERROR_PAK_s
{
	ERROR_STAT STAT;
	EWORD ECODE;
} ERROR_PAK;

#define MK_ECODE(DOM_CODE, SUB_CODE) (DOM_CODE + SUB_CODE)
#define ER_PAK_PLOAD {ER_UNDEF, 0}

#define ER_PAK_INIT(Nn) ERROR_PAK Nn = ER_PAK_PLOAD
#define ER_PAK_FAILED(Nn, X) \
	Nn.ECODE = X; \
    Nn.STAT = ER_FAILED; \
    return Nn

#define MK_ER_PAK(Nn, X, ST) \
	Nn.ECODE = X; \
    Nn.STAT = ST; \
    return Nn

#define ER_PAK_SUCCESS(Nn, X) \
	Nn.ECODE = X; \
    Nn.STAT = ER_SUCCESS; \
    return Nn

#define ER_PAK_UNDEF(Nn, X) \
	Nn.ECODE = X; \
    Nn.STAT = ER_UNDEF; \
    return Nn

#endif