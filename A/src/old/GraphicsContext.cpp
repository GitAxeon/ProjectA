#include "GraphicsContext.hpp"
#include "SDL_RendererGraphicsContext.hpp"

#include <cassert>
#include <iostream>

namespace ProjectA
{
    GraphicsContext::GraphicsContext() { }
    
    Owned<GraphicsContext> GraphicsContext::Create(RenderAPI api)
    {
        switch(api)
        {
        case RenderAPI::SDL:
            return CreateOwned<SDL_RendererGraphicsContext>();
        break;
        default:
            std::cout << "Selected rendering API not supported currently.\n";
            return nullptr;
        }
    }
}