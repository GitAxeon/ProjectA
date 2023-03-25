#include "Window.hpp"

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_hints.h>
#include <imgui.h>
#include <backends/imgui_impl_sdl3.h>    

#include <cassert>

namespace ProjectA
{
    Window::Window(const WindowInfo& info)
    {
        m_Title = info.Name;
        m_Width = info.Width;
        m_Height = info.Height;

        SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
        m_Window = SDL_CreateWindow(m_Title.c_str(), m_Width, m_Height, SDL_WINDOW_RESIZABLE);
        
        assert(m_Window);
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_Window);
    }

    void Window::Close()
    {
        m_IsOpen = false;
    }

    void Window::DispatchEvents()
    {
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            ImGui_ImplSDL3_ProcessEvent(&e);

            switch(e.type)
            {
            case SDL_EVENT_QUIT:
                m_IsOpen = false;
            break;
            case SDL_EVENT_KEY_DOWN:
                if(e.key.keysym.sym == SDLK_ESCAPE)
                {
                    g_KeepOpen = false;
                    m_IsOpen = false;
                }
            }
        }
    }

    void Window::Resize(unsigned int width, unsigned int height)
    {
        assert(width != 0 && height != 0);
        
        SDL_SetWindowSize(m_Window, width ,height);

        m_Width = width;
        m_Height = height;
    }
}