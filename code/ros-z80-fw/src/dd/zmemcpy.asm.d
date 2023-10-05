TODO = 0xFF

//string:
//    .db  0xAF, "FUCK", 0, 0xAA

// include "bios.asm"
// incbin "file",offset,length



zmemcpy::
    ld hl, #0xF // from buff
    ld de, #0xF // to buff
    ld bc, #0xF // mem buff size
    ldir
    