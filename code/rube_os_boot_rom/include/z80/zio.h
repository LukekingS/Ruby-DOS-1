#pragma once
#ifndef ZIO_H
#define ZIO_H
#include "def.h"

#ifdef __cplusplus
extern "C" {
#endif
FLAG has_osdisk();

//void zfopen(const char* fname);
//ERROR_PAK zfclose(FILE* file);
void* zraw_file(const char* fname);
char zgetkey();
FLAG zverify_addr(address_t adder);
FLAG zverify_p(void* ptr);
void* zmalloc(size_t mem_size);
void* zadder_get(address_t adder);
void* zmemcpy(void* t, readonly void* f, size_t s);
ERROR_PAK zfree(void* ptr);


__inline void* malloc(size_t size) {return zmalloc(size);}
__inline ERROR_PAK free(void* ptr) {return zfree(ptr);}
#ifdef __cplusplus
}
#endif

#endif