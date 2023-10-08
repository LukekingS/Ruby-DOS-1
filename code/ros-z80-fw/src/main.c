#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "val_defs.h"
#include "zrom_ex.h"

FLAG MCL = 1;

//volatile void r();



void __sub(){return;}

ptr_stack_t exit_er;

void aexit()
{
    pstack_run(&exit_er);
    pstack_free(&exit_er);
    pstack_free(&roms_stack);
}

void kexit()
{
    aexit();
}

void zkill()
{
    MCL = 0;
}

int main()
{
    //rom_ex = malloc(sizeof(ZROM_EX) * 10);
    pstack_init(&exit_er);
    pstack_init(&roms_stack);
    pstack_push(&exit_er, &zkill);
    while(MCL)
    {
        address16_t laddr = 0xFFF;
        BYTE* dr = addr_to_ptr(laddr);
        for (size_t i = 0; i < alen(dr); i++)
        {
            dr[i] = 0xAC;
        }
        //test();
        //assert(dr[0] == 1);
    }
    
    kexit();
    return MK_ECODE(100,45);
}