#pragma once
#ifndef BIOS_CALL_H
#define BIOS_CALL_H
#include "def.h"

#define ZPRINT_CALL_CHAR 0xFA
#define ZPRINT_CALL_STR 0xFA0A
#if __cplusplus
extern "C" {
#endif


ERROR_PAK bios();

ERROR_PAK bios_call(uint16_t work, uint8_t arg, uint8_t _arg, address_t wptr);

#if __cplusplus
}
#endif

#endif