#pragma once
#ifndef TP40_H
#define TP40_H
#include "def.h"

#define MK_TP40_PAK(header, data, footer) {{header, data, footer}}


//PH_OPCODE = 0xFF,

enum pak_hd_e
{
    PH_NA = 0xAF,
    PH_POLL = 0xAA,
    PH_INFO = 0x24,
    PH_STAT = 0x84
};

enum pak_ft_e
{
    PF_SABY = 0xF1,
    PF_WAK = 0x58,
    PF_SLEP = 0xF5,
    PF_NA = 0xAF
};

typedef union tp40_pak_u
{
    struct
    {
        uint8_t HEAD;
        uint16_t DATA;
        uint8_t FOOT;
        
    };
    int32_t FULL_DATA :5;
} tp40_pak_t;

typedef struct tp40_pin_set_s
{
    uint8_t TX;
    uint8_t RX;
    uint8_t SY;
} tp40_pin_set_t;
extern tp40_pak_t TP_ERROR_PAK;

void tp40_sand(readonly tp40_pin_set_t pins, readonly tp40_pak_t* pack);
tp40_pak_t tp40_get(readonly tp40_pin_set_t pins);
void tp40_wfs(tp40_pin_set_t pins);

#endif