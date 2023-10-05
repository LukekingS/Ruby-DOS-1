#include "zrom_ex.h"

void __sub();
void* _SUB_ = &__sub;

BYTE roms = 0;
ERROR_PAK ex_def(ZROM_EX fun)
{
    ER_PAK_INIT(out);

    if (roms > BASH_ZROM_SIZE)
    {
        rom_ex[roms] = fun;
    }
    else
    {
        ER_PAK_FAILED(out, 0);
    }

    ER_PAK_SUCCESS(out, 0);
}

ERROR_PAK ex_run()
{
    ER_PAK_INIT(out);
    for (size_t i = 0; i < rlen(BASH_ZROM_SIZE); i++)
    {
        ER_PAK_INIT(d);
        d = (*rom_ex)(out);
        if ((d.STAT == ER_UNDEF) || (d.STAT == ER_SUCCESS))
        {
            return d;
        }
    } 
    ER_PAK_SUCCESS(out, 0);
}

ERROR_PAK ex_pop()
{
    ER_PAK_INIT(out);
    for (size_t i = 0; i < rlen(BASH_ZROM_SIZE); i++)
    {
        rom_ex[i] = _SUB_;
    }
    roms = 0;
    ER_PAK_SUCCESS(out, 0);
}