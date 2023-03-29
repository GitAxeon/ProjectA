#pragma once
#include "Scopes.hpp"
#include "SDL3/SDL_video.h"

namespace ProjectA
{
    enum class RenderAPI { SDL, OpenGL, Vulkan };

    class GraphicsContext
    {
    public:
        GraphicsContext();

        virtual int Init(SDL_Window* SDLWindow);
        virtual void Present() const;
        
        static Owned<GraphicsContext> Create(RenderAPI api);

    private:
        RenderAPI m_RenderAPI;
    };
}