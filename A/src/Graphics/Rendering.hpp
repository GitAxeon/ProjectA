#pragma once

#include "../Scopes.hpp"
#include "BaseRenderer.hpp"

namespace ProjectA::Render
{
    enum class API { SDL, OpenGL, Vulkan };
}

namespace ProjectA
{
    class GraphicsContext
    {
    public:
        // Construct based on api
        
        /*
            Swap
            Clear
            etc,,,
        */
    private:
    };

    class RenderSystem
    {
    public:
        static Shared<Renderer> CreateRenderer(Render::API api);

    private:
    };
}