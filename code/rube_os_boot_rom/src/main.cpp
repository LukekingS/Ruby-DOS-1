#include "def.h"
#include "z80/zio.h"
#include "bios_call.h"
#include "pair.hpp"

const char* NO_OS_STR = "\x9Fno system present\ninsert system boot disk\x9A";
const char* WOS_STR = "\xAFRube OS\xAA";

C_CALL int main()
{
START:
    bios_call(ZPRINT_CALL_STR, 0, 0, (address_t)WOS_STR);
    if (!has_osdisk())
    {
        ERROR_PAK e = bios_call(ZPRINT_CALL_STR, 0, 0, (address_t)NO_OS_STR);
        if (e.ECODE == ER_FAILED)
        {
            while(1);
        }
        goto START;
    }

    void* os_ptr = zraw_file("os.bin");
    if (zverify_p(os_ptr))
    {
        zmemcpy((void*)0xFF000000, os_ptr, sizeof(uint8_t) * 54);
    }
    free(os_ptr);
    __asm volatile("call 0xFF000000");

    return 0;
}
