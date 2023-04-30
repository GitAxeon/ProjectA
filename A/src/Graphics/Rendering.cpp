#include "Rendering.hpp"

#include "Graphics/OpenGLRenderer.hpp"
#include "Graphics/VulkanRenderer.hpp"

namespace ProjectA
{
    Shared<Renderer> RenderSystem::CreateRenderer(Render::API api)
    {
        switch(api)
        {
            case Render::API::SDL: return nullptr;
            case Render::API::OpenGL: return CreateShared<OpenGLRenderer>();
            case Render::API::Vulkan: return CreateShared<VulkanRenderer>();
        }
    }
}

