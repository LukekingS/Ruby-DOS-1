.section .text
.global _start
.global main
.global main
_start:

    call main

    ; hang the CPU if the kernel falls through
    .hang:
        hlt
        jmp .hang
