#include "SDL_RendererGraphicsContext.hpp"

namespace ProjectA
{
    SDL_RendererGraphicsContext::SDL_RendererGraphicsContext() { }

    SDL_RendererGraphicsContext::~SDL_RendererGraphicsContext()
    {
        if(m_SDLRenderer)
            SDL_DestroyRenderer(m_SDLRenderer);
    }

    int SDL_RendererGraphicsContext::Init(SDL_Window* SDLWindow)
    {
        uint32_t flags = 0;

        flags |= SDL_RENDERER_ACCELERATED;
        // vsync setting doesn't belong here :L
        flags |= SDL_RENDERER_PRESENTVSYNC;

        m_SDLRenderer = SDL_CreateRenderer(SDLWindow, "", flags);

        return 0;
    }

    void SDL_RendererGraphicsContext::Present() const
    {
        SDL_RenderPresent(m_SDLRenderer);
    }

}