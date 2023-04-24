#include "Window.hpp"
#include "WindowHandler.hpp"

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
        for(auto layer : m_Layers)
        {
            layer->OnDetach();
        }

        m_Layers.Clear();
        SDL_DestroyWindow(m_SDLWindow);
    }

    void Window::Close()
    {
        m_IsOpen = false;
        WindowHandler::RequestWindowClose();
    }

    void Window::Resize(uint32_t width, uint32_t height)
    {
        assert(width != 0 && height != 0);
        
        SDL_SetWindowSize(m_SDLWindow, width ,height);

        m_WindowInfo.Width = width;
        m_WindowInfo.Height = height;
    }

    void Window::HandleEvent(Event* event)
    {
        switch(event->GetType())
        {
        case EventType::WindowClose:
            m_IsOpen = false;
        break;
        case EventType::KeyDown:
            auto keydown = Event::Cast<EventKeyDown>(event);
            
            if(keydown->Key() == Key::Key::Escape)
            {
                WindowHandler::CloseAllWindows();
            }
        break;
        }

        for(auto layer : m_Layers)
        {
            layer->OnEvent(event);
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