#include "A.hpp"

#include <SDL3/SDL.h>
#include <SDL3/SDL_mixer.h>

#include <cassert>
#include <iostream>
#include <algorithm>

namespace ProjectA
{
    bool Init()
    {
        int r_SDLInit = SDL_Init(SDL_INIT_EVERYTHING);
        assert(r_SDLInit == 0);

        int r_SDLMixerInit = Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
        assert(r_SDLMixerInit == 0);

        return (r_SDLInit == r_SDLMixerInit == 0);
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
    
    std::forward_list<Window*>& GetWindows()
    {
        return g_Windows;
    }


    int Run()
    {
        while(g_WindowCount > 0)
        {
            std::cout << g_WindowCount << std::endl;
            bool removeClosedWindows = false;

            SDL_Event e;
            while(SDL_PollEvent(&e))
            {
                SDL_WindowID id = e.window.windowID;

                for(auto window : g_Windows)
                {
                    if(SDL_GetWindowID(window->GetSDLWindow()) == id)
                    {
                        window->HandleEvent(e);

                        if(window->ShouldClose())
                            removeClosedWindows = true;

                        break;
                    }
                }
            }

            for(auto window : g_Windows)
            {
                //window->DispatchEvents();
                window->UpdateLayers();
            }

            for(auto window : g_Windows)
            {
                for(auto layer : window->GetLayerStack())
                {
                    layer->OnRender();
                }
            }

            for(auto window : g_Windows)
            {
                for(auto layer : window->GetLayerStack())
                {
                    layer->OnUIRender();
                }
            }

            //std::remove_if(g_Windows.begin(), g_Windows.end(), [](Window* w) { return !w->IsOpen(); });

            if(removeClosedWindows)
            {
                auto previous = g_Windows.before_begin();
                for(auto it = g_Windows.begin(); it != g_Windows.end(); it++)
                {
                    if((*it)->ShouldClose())
                    {
                        delete (*it);
                        it = g_Windows.erase_after(previous);
                        std::cout << "Removed window uwu" << std::endl;
                        g_WindowCount--;
                    }
                    else
                    {
                        previous = it;
                        it++;
                    }
                }
            }
        }

        return 0;
    }
    
    void Deinit()
    {
        for(Window* window : g_Windows)
        {
            delete window;
        }

        g_Windows.clear();

        SDL_Quit();
        Mix_CloseAudio();
    }
}