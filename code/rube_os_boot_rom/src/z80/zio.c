#include "z80/zio.h"

FLAG has_osdisk()
{
    //todo
    return 0;
}

/*FILE* zfopen(const char* fname)
{
    return NULL;
}

ERROR_PAK zfclose(FILE* file)
{
    ER_PAK_INIT(out);
    ER_PAK_SUCCESS(out, 0);
}*/
void* zraw_file(const char* fname)
{
    return NULL;
}

void* zadder_get(address_t adder)
{
    return NULL;
}

void* zmalloc(size_t mem_size)
{
    return NULL;
}

FLAG zverify_addr(address_t adder)
{
    return 0;
}

FLAG zverify_p(void* ptr)
{
    address_t a = (address_t)ptr;
    return zverify_addr(a);
}

void* zmemcpy(void* t, readonly void* f, size_t s)
{
    return t;
}

char zgetkey()
{
    return 'A';
}

ERROR_PAK zfree(void* ptr)
{
    ER_PAK_INIT(out);
    ER_PAK_SUCCESS(out, 0);
}