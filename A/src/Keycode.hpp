#pragma once

#include <SDL3/SDL_keycode.h>

#include <unordered_map>
#include <algorithm>

namespace ProjectA
{
    enum class Keycode
    {
        Unknown,
        
        Enter, Escape, Space,
        Up, Down, Left, Right,
        
        A, B, C, D, E, F, G, H, I,
        J, K, L, M, N, O, P, Q, R,
        S, T, U, V, W, X, Y, Z,

        D0, D1, D2, 
        D3, D4, D5, 
        D6, D7, D8, 
            D9
    };

    inline std::unordered_map<SDL_Keycode, Keycode> KeyMapping =
    {
        {SDLK_UNKNOWN, Keycode::Unknown},
        
        {SDLK_RETURN, Keycode::Enter},
        {SDLK_ESCAPE, Keycode::Escape},
        {SDLK_SPACE, Keycode::Space},

        {SDLK_UP, Keycode::Up}, 
        {SDLK_DOWN, Keycode::Down}, 
        {SDLK_LEFT, Keycode::Left}, 
        {SDLK_RIGHT, Keycode::Right},        

        {SDLK_a, Keycode::A},
        {SDLK_b, Keycode::B},
        {SDLK_c, Keycode::C},
        {SDLK_d, Keycode::D},
        {SDLK_e, Keycode::E},
        {SDLK_f, Keycode::F},
        {SDLK_g, Keycode::G},
        {SDLK_h, Keycode::H},
        {SDLK_i, Keycode::I},
        {SDLK_j, Keycode::J},
        {SDLK_k, Keycode::K},
        {SDLK_l, Keycode::L},
        {SDLK_m, Keycode::M},
        {SDLK_n, Keycode::N},
        {SDLK_o, Keycode::O},
        {SDLK_p, Keycode::P},
        {SDLK_q, Keycode::Q},
        {SDLK_r, Keycode::R},
        {SDLK_s, Keycode::S},
        {SDLK_t, Keycode::T},
        {SDLK_u, Keycode::U},
        {SDLK_v, Keycode::V},
        {SDLK_w, Keycode::W},
        {SDLK_x, Keycode::X},
        {SDLK_y, Keycode::Y},
        {SDLK_z, Keycode::Z},

        {SDLK_0, Keycode::D0},
        {SDLK_1, Keycode::D1},
        {SDLK_2, Keycode::D2},
        {SDLK_3, Keycode::D3},
        {SDLK_4, Keycode::D4},
        {SDLK_5, Keycode::D5},
        {SDLK_6, Keycode::D6},
        {SDLK_7, Keycode::D7},
        {SDLK_8, Keycode::D8},
        {SDLK_9, Keycode::D9}
    };
}