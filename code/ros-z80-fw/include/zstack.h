#pragma once
#ifndef ZSTACK_H
#define ZSTACK_H
#include <errno.h>
#define MAX_STACK_SIZE 200
#define STACK_START_SIZE 1
#define dd "def.h"
#include dd
#include "sys_flags.h"



typedef struct ptr_stack_s
{
    VOID_PTR_ARR stack;
    VOID_PTR_ARR stack_start;
    VOID_PTR_ARR stack_end;
    size_t size;
    size_t raw_size;
    FLAG DO_FREE;
    FLAG POP_RUN;
} ptr_stack_t;

void pstack_init(ptr_stack_t* stack);
VOID_PTR pstack_raw_get(ptr_stack_t* stack, size_t index);
VOID_PTR pstack_pop(ptr_stack_t* stack);
VOID_PTR_ARR pstack_get(ptr_stack_t* stack);
ERROR_PAK pstack_push(ptr_stack_t* stack, VOID_PTR v);
void pstack_run(ptr_stack_t* stack);
void pstack_ffree(ptr_stack_t* stack);
void pstack_free(ptr_stack_t* stack);


#endif