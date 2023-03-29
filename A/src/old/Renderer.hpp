#pragma once

#include "Window.hpp"
#include "Color.hpp"

#include <SDL3/SDL_render.h>

namespace ProjectA
{
    class Renderer
    {
    public:
        Renderer() {}
        ~Renderer();

        virtual int Init();
        void SetClearColor(const ColorRGBA& color = ColorRGBA());
        void Clear() const;
        
        static Owned<Renderer> Create(RenderAPI api, SDL_Window* window);

    private:
        ColorRGBA m_ClearColor;
    };
}