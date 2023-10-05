#include "bios_call.h"

ERROR_PAK bios_call(uint16_t work, uint8_t arg, uint8_t _arg, address_t wptr)
{
    register uint32_t r_work_code asm ("edx");
    register uint8_t r_argI_code asm ("ah");
    register address_t r_work_ptr asm ("ebx");
    register uint8_t argII_code asm ("al");
    r_work_code = work;
    r_argI_code = arg;
    r_work_code = wptr;
    argII_code = _arg;

    return bios();
}

void __cxa_pure_virtual()
{
    // Do nothing or print an error message.
}

ERROR_PAK bios()
{
    register uint32_t work_code asm ("edx");
    register uint8_t arg_code asm ("ah");
    register address_t work_ptr asm ("ebx");

    //asm("\t mov %%dx,%0" : "=r"(work_code));

    register uint8_t argII_code asm ("al");
    //uint16_t argIII_code = 0;
    ER_PAK_INIT(out);
    
    switch (work_code)
    {
    case ZPRINT_CALL_CHAR:
        //todo
        ER_PAK_SUCCESS(out, 0);
        break;
    case ZPRINT_CALL_STR:
    {
        const char* pstr = addr_to_ptr(work_ptr);
        //todo
        ER_PAK_SUCCESS(out, 0);
    }
        break;
    default:
        ER_PAK_FAILED(out, 404);
        break;
    }

    


    ER_PAK_UNDEF(out, 0);
}

 