#include "Application.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_mixer.h>

#include <cassert>

// namespace ProjectA::Application
// {
//     int Run()
//     {
//         for(auto& window : g_Windows)
//         {
//             for(auto& layer : window->GetLayers())
//             {
                
//             }
//         }
        
//         while(g_Windows.size() > 0)
//         {
//             for(auto& window : g_Windows)
//             {
//                 if(!window->IsOpen())
//                     continue;

//                 for(auto& layer : window->GetLayers())
//                 {
                    
//                 }
//             }
//         }
//     }
// }

namespace ProjectA
{
    bool Init()
    {
        int r_SDLInit = SDL_Init(SDL_INIT_EVERYTHING);
        assert(r_SDLInit == 0);

        int r_SDLMixerInit = Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
        assert(r_SDLMixerInit == 0);
    }

    bool MultiThreadingEnabled()
    { 
        return g_Configuration.EnableMultiThreading;
    }

    void Configure(const Configuration& configuration)
    {
        g_Configuration = configuration;
    }

    Configuration GetConfiguration()
    {
        return g_Configuration;
    }
    
    std::vector<Owned<Window>>& GetWindows()
    {
        return g_Windows;
    }
}