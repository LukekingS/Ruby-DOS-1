#pragma once 

#ifndef COLOR_H
#define COLOR_H
#include "rint.h"

typedef union color_u
{
    struct
    {
        uint16_t blue  :5;
        uint16_t green :6;
        uint16_t red   :5;
    };
    uint16_t full;

} color_t;


#endif