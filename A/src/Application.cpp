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
            bool windowRequestedClose = DispatchEvents();

            for(auto window : g_Windows)
            for(auto layer : window->GetLayerStack())
                 layer->OnRender();


            for(auto window : g_Windows)
            for(auto layer : window->GetLayerStack())
                layer->OnRender();

            for(auto window : g_Windows)
            for(auto layer : window->GetLayerStack())
                layer->OnUIRender();


            if(windowRequestedClose)
                ReleaseClosedWindows();
        }

        return 0;
    }
    
    void Deinit()
    {   
        ReleaseWindows();

        SDL_Quit();
        Mix_CloseAudio();
    }

    bool DispatchEvents()
    {
        int windowCloseRequested = 0;

        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            if(DispatchEvent(e))
                windowCloseRequested++;
        }

        return windowCloseRequested;
    }

    bool DispatchEvent(const SDL_Event& event)
    {
        bool windowRequestedClose = false;
        SDL_WindowID id = event.window.windowID;

        for(auto window : g_Windows)
        {
            if(SDL_GetWindowID(window->GetSDLWindow()) == id)
            {
                window->HandleEvent(event);

                if(window->ShouldClose())
                    windowRequestedClose = true;

                break;
            }
        }

        return windowRequestedClose;
    }

    void ReleaseClosedWindows()
    {
        auto previous = g_Windows.before_begin();
        auto it = g_Windows.begin();
        auto end = g_Windows.end();

        while(it != end)
        {
            if((*it)->ShouldClose())
            {
                delete (*it);
                it = g_Windows.erase_after(previous);
                g_WindowCount--;
                continue;
            }

            previous = it;
            it++;
        }
    }

    void ReleaseWindows()
    {
        for(Window* window : g_Windows)
        {
            delete window;
        }

        g_Windows.clear();
    }
}