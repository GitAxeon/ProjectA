#pragma once

#include "../Scopes.hpp"
#include "BaseRenderer.hpp"

namespace ProjectA::Render
{
    enum class API { SDL, OpenGL, Vulkan };
}

namespace ProjectA
{
    class RenderSystem
    {
    public:
        static Shared<Renderer> CreateRenderer(Render::API api);
    private:
    };
}