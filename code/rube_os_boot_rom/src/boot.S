.section .text
.global _boot
.global main
.global onexit

_boot:  
    call main

    ; hang the CPU if the kernel falls through
    .hang:
        hlt
        jmp .hang
