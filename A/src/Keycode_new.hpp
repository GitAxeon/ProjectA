#pragma once

#include <SDL3/SDL_events.h>

#include <string>

#define KEY_INFO  \
        X(Unknown, Unknown, SDLK_UNKNOWN) \
        X(Enter, Enter, SDLK_RETURN) \
        X(Escape, Escape, SDLK_ESCAPE) \
        X(Space, Space, SDLK_SPACE) \
        X(Up, Up, SDLK_UP) \
        X(Down, Down, SDLK_DOWN) \
        X(Left, Left, SDLK_LEFT) \
        X(Right, Right, SDLK_RIGHT) \
        X(A, A, SDLK_a) \
        X(B, B, SDLK_b) \
        X(C, C, SDLK_c) \
        X(D, D, SDLK_d) \
        X(E, E, SDLK_e) \
        X(F, F, SDLK_f) \
        X(G, G, SDLK_g) \
        X(H, H, SDLK_h) \
        X(I, I, SDLK_i) \
        X(J, J, SDLK_j) \
        X(K, K, SDLK_k) \
        X(L, L, SDLK_l) \
        X(M, M, SDLK_m) \
        X(N, N, SDLK_n) \
        X(O, O, SDLK_o) \
        X(P, P, SDLK_p) \
        X(Q, Q, SDLK_q) \
        X(R, R, SDLK_r) \
        X(S, S, SDLK_s) \
        X(T, T, SDLK_t) \
        X(U, U, SDLK_u) \
        X(V, V, SDLK_v) \
        X(W, W, SDLK_w) \
        X(X, X, SDLK_x) \
        X(Y, Y, SDLK_y) \
        X(Z, Z, SDLK_z) \
        X(D0, 0, SDLK_0) \
        X(D1, 1, SDLK_1) \
        X(D2, 2, SDLK_2) \
        X(D3, 3, SDLK_3) \
        X(D4, 4, SDLK_4) \
        X(D5, 5, SDLK_5) \
        X(D6, 6, SDLK_6) \
        X(D7, 7, SDLK_7) \
        X(D8, 8, SDLK_8) \
        X(D9, 9, SDLK_9)

namespace ProjectA::Key
{
    enum Key
    {
        #define X(name, value, sdl_value) name,
        KEY_INFO
        #undef X
    };

    inline Key FromSDLKeycode(const SDL_Keycode sdlKey)
    {
        switch(sdlKey)
        {
            #define X(name, value, sdl_value) case sdl_value: return Key::name;
            KEY_INFO
            #undef X

            default:
                return Key::Unknown;
        }
    }

    inline std::string ToString(Key key)
    {
        switch(key)
        {
            #define X(name, value, sdl_value) case Key::name: return #value;
            KEY_INFO
            #undef X

            default:
                return "Unknown";
        }
    }
}