#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "def.h"
#include "zrom_ex.h"

FLAG MCL = 1;
ERROR_PAK test();

volatile void r();

ZROM_EX* rom_ex;

void __sub(){return;}

void aexit()
{

}

int main()
{
    rom_ex = malloc(sizeof(ZROM_EX) * 10);
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
    if (ex_pop().STAT == ER_FAILED)
    {
        while(1);
    }
    free(rom_ex);
    aexit();
    return MK_ECODE(100,45);
}