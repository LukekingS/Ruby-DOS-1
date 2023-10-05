#include "def.h"
#include "librube/heap.h"
static void(*main)() = addr_to_ptr(0xFFF);

void pos_loader()
{
    void* os_mem_rang = addr_to_ptr(OS_MEM_RANG_S); //= heap_alloc(sizeof(BYTE) * 12500, HEAP_TAG_USED);
    (*main)();
}