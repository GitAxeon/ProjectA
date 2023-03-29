// #include "Renderer.hpp"

// #include <cassert>

// namespace ProjectA
// {
//     Renderer::Renderer(SDL_Renderer* renderer)
//     {
//         assert(renderer != nullptr);

//         m_Renderer = renderer;
//     }

//     Renderer::~Renderer()
//     {
//         SDL_DestroyRenderer(m_Renderer);
//     }

//     void Renderer::SetClearColor(const ColorRGBA& color)
//     {
//         m_ClearColor = color;

//         SDL_SetRenderDrawColor(m_Renderer, color.R, color.G, color.B, color.A);
//     }

//     void Renderer::Clear() const
//     {
//         SDL_RenderClear(m_Renderer);
//     }

//     void Renderer::Present() const
//     {
//         SDL_RenderPresent(m_Renderer);
//     }

//     Renderer Renderer::Create(const Window& window)
//     {
//         uint32_t windowFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
        
//         SDL_Renderer* sdlRenderer = SDL_CreateRenderer(window.GetSDLWindow(), nullptr, windowFlags);

//         return Renderer(sdlRenderer);
//     }

//     Owned<Renderer> Renderer::Create(RenderAPI api, SDL_Window* window)
//     {
//         switch(api)
//         {
//         case RenderAPI::SDL:
//             // return Owned<Renderer_SDL>
//         break;
//         }
//     }
// }