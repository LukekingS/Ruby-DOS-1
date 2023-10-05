extern bios

section .data
pstr:
    db 0x9F, "bios test" , 0x9A, 0

section .text



bios_test:
    mov edx, 0xFA0A
    mov ebx, pstr
    call bios
    ret