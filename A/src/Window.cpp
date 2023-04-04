#include "Window.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_hints.h>
#include <imgui.h>
#include <backends/imgui_impl_sdl3.h>    

#include <cassert>
#include <iostream>

namespace ProjectA
{
    Window::Window(const WindowInfo& info)
    {
        m_WindowInfo = info;

        SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
        m_SDLWindow = SDL_CreateWindow(info.Name.c_str(), info.Width, info.Height, SDL_WINDOW_RESIZABLE);

        assert(m_SDLWindow);
    }

    Window::~Window()
    {
        m_Layers.Clear();
        SDL_DestroyWindow(m_SDLWindow);
    }

    void Window::Close()
    {
        m_IsOpen = false;
    }

    void Window::Resize(unsigned int width, unsigned int height)
    {
        assert(width != 0 && height != 0);
        
        SDL_SetWindowSize(m_SDLWindow, width ,height);

        m_WindowInfo.Width = width;
        m_WindowInfo.Height = height;
    }

    void Window::HandleEvent(const SDL_Event& event, Event* test)
    {
        switch(event.type)
        {
        case SDL_EVENT_QUIT:
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
            m_IsOpen = false;
        break;
        case SDL_EVENT_KEY_DOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                m_IsOpen = false;
            }
        }

        for(auto layer : m_Layers)
        {
            layer->OnEvent(event);
            layer->OnEvent(test);
        }
    }

    void Window::UpdateLayers()
    {
        for(auto layer : m_Layers)
        {
            layer->OnUpdate(0.016f);
        }
    }
}