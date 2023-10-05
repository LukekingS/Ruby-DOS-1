#include "mem.h"

void* memcpy(void* dest, void* src, size_t n)
{

    // if dest is NULL we can't perform a copy so return NULL as an 'error status'
    if (dest == NULL) return NULL;
    
    // We need to copy each byte from src to dest, but we can't assign as we do 
    // in the loop below using void (we'll get an error).  At the same time, we 
    // know that a char == one byte, and that we can assign from a char to a char,
    // so instead we cast both dest and src to pointers to chars so we can assign 
    // each char/byte from src to dest.
    char *char_dest = (char *) dest;
    char *char_src = (char *) src;
    
    // copy each n char/bytes from src to dest
    for (size_t i = 0; i < n; i++)
        char_dest[i] = char_src[i];
        
    // return the dest pointer as the official memcpy() function does
    return dest;
}

size_t strlen(const char* str)
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}