#pragma once

#include "GraphicsContext.hpp"

#include "SDL3/SDL_render.h"

namespace ProjectA
{
    class SDL_RendererGraphicsContext : public GraphicsContext
    {
    public:
        SDL_RendererGraphicsContext();
        ~SDL_RendererGraphicsContext();
        
        int Init(SDL_Window* SDLWindow) override;
        void Present() const override;

    private:
        SDL_Renderer* m_SDLRenderer;
    };
}