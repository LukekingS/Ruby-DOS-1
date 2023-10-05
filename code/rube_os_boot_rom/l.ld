OUTPUT_FORMAT(binary)
ENTRY(_boot)

SECTIONS
{
    . = 1M;

    .boot :
    {
        KEEP(*(.multiboot))
    }

    .text :
    {
        *(.text)
    }
}