#pragma once
#ifndef ZROM_H
#define ZROM_H
#include "def.h"
#include "zstack.h"

typedef ERROR_PAK (*ZROM_EX)(ERROR_PAK);
//typedef int (*MAIN_PTR)();

extern ptr_stack_t roms_stack;

//extern ZROM_EX* rom_ex;
#define BASH_ZROM_SIZE 10
//extern BYTE roms;

ERROR_PAK ex_def(ZROM_EX fun);
ERROR_PAK ex_run();
//ERROR_PAK ex_pop();


#endif