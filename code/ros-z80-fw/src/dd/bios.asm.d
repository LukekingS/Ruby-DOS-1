PRINT_SIZE:
    db 0xFF, 0xFF

START_STR_PTR:
    db 0
END_STR_PTR:
    db 0
PRINT_TODO:
    db 0

zprint:
Is
    ld de, PRINT_SIZE
    ; ex hx, xl
    ld hl, START_STR_PTR
    ld bc, END_STR_PTR
    jr zmemcpy
    ;ff
print_loop:
    
    jr print_loop


