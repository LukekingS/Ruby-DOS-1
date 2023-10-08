#include "zstack.h"
#include "val_defs.h"
#define VPTR_SIZE sizeof(VOID_PTR)
void* _SUB_ = &__sub;

void pstack_init(ptr_stack_t* stack)
{
    stack->size = 1;
    stack->stack = malloc(VPTR_SIZE * 1);
    stack->raw_size = VPTR_SIZE * 1;
    stack->stack_end = stack->stack - arrlen(stack->stack);
    stack->stack_start = stack->stack;
    stack->stack[0] = _SUB_;
    stack->DO_FREE = 0;
    stack->POP_RUN = 1;
}

ERROR_PAK pstack_push(ptr_stack_t* stack, VOID_PTR v)
{
    ER_PAK_INIT(out);
    if (stack->size <= MAX_STACK_SIZE)
    {
        ER_PAK_FAILED(out, 10);
    }
    if (stack->size == 1)
    {
        stack->stack[0] = v;
        ER_PAK_SUCCESS(out, 0);
    }
    else if (stack->size != 0 && stack->size != 1)
    {
        size_t nsize = stack->raw_size + VPTR_SIZE;
        stack->stack = realloc(stack->stack, nsize);
        stack->size = arrlen(stack->stack);
        stack->stack_start = stack->stack;
        stack->stack_end = stack->stack - arrlen(stack->stack);
        ER_PAK_SUCCESS(out, 0);
    }
    else
    {
        ER_PAK_SUCCESS(out, 0);
    }
    ER_PAK_UNDEF(out, 0);
}

VOID_PTR pstack_raw_get(ptr_stack_t* stack, size_t index)
{
    return stack->stack[index];
}

VOID_PTR_ARR pstack_get(ptr_stack_t* stack)
{
    VOID_PTR_ARR o = malloc(stack->raw_size);
    memcpy(o, stack->stack, stack->raw_size);
    return o;
}

void pstack_run(ptr_stack_t* stack)
{
    switch (stack->POP_RUN)
    {
    case true:
        for (size_t i = stack->size; i > 0; i--)
        {
            void(*fun)()  = pstack_pop(stack);
            (*fun)();
        } 
        return;
        break;
    case false:
NPOP:
        for (size_t i = 0; i < stack->size; i++)
        {
            void(*fun)() = stack->stack[i];
            (*fun)();
        } 
        return;
        break;
    
    default:
        goto NPOP;
        break;
    }
    return;
}

VOID_PTR pstack_pop(ptr_stack_t* stack)
{
    if (stack->size == 1)
    {
        VOID_PTR o = stack->stack[0];
        if (!stack->DO_FREE)
        {
            pstack_free(stack);
        }
        return o;
    }
    else
    {
        size_t nsize = stack->raw_size - VPTR_SIZE;
        VOID_PTR o = stack->stack_start[0];
        stack->stack = realloc(stack->stack, nsize);
        stack->stack_start = stack->stack;
        stack->stack_end = stack->stack - arrlen(stack->stack);
    }

    return NULL;
}

void pstack_free(ptr_stack_t* stack)
{
    free(stack->stack);
    stack->raw_size = 0;
    stack->stack_end = NULL;
    stack->stack_start = NULL;
    stack->stack = NULL;
    stack->size = 0;
}

void pstack_ffree(ptr_stack_t* stack)
{
    stack->DO_FREE = 1;
    for (size_t i = stack->size; i > 0; i--)
    {
        
        free(pstack_pop(stack));
        /*if ((d.STAT == ER_UNDEF) || (d.STAT == ER_SUCCESS))
        {
            return d;
        }*/
        
    } 
    free(stack->stack);
    stack->raw_size = 0;
    stack->stack_end = NULL;
    stack->stack_start = NULL;
    stack->stack = NULL;
    stack->size = 0;
    stack->DO_FREE = 0;
    stack->POP_RUN = 1;
}