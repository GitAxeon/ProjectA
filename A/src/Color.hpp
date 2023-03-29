#pragma once
#include <cstdint>

namespace ProjectA
{
    struct ColorRGBA
    {
        ColorRGBA(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255) 
            : R(r), G(g), B(b), A(a) { }
        
        uint8_t R;
        uint8_t G;
        uint8_t B;
        uint8_t A;
    };
}