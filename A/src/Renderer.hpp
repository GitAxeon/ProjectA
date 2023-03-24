#pragma once

#include "Window.hpp"

#include <SDL3/SDL_render.h>

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

    class Renderer
    {
    public:
        Renderer(SDL_Renderer* renderer);
        ~Renderer();

        void SetClearColor(const ColorRGBA& color = ColorRGBA());
        void Clear() const;

        void Present() const;

        SDL_Renderer* GetSDLRenderer() const { return m_Renderer; };

    static Renderer Create(const Window& window);
    private:
        SDL_Renderer* m_Renderer;
        ColorRGBA m_ClearColor;
    };

}