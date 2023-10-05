#pragma once
#ifndef MEM_H
#define MEM_H
#include "def.h"
//#include "rint.h"

#ifdef __cplusplus
extern "C" {
#endif

void* memcpy(void* dest, void* src, size_t n);
size_t strlen(const char* str);

#ifdef __cplusplus
}
#endif

#endif

