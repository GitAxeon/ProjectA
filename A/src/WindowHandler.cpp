#include "WindowHandler.hpp"
#include "Event.hpp"

#include <SDL3/SDL_events.h>

namespace ProjectA
{
    void WindowHandler::Configure(const Configuration& configuration)
    {
        m_Configuration = configuration;
    }

    Window* WindowHandler::CreateWindow(const WindowInfo& info)
    {
        // Dno if one should check wether/ or not the sdl window is null or something 
        Window* window = new Window(info);
        SDL_WindowID id = SDL_GetWindowID(window->GetSDLWindow());
        
        m_Windows.emplace(id, window);

        return window;
    }

    void WindowHandler::DispatchEvents()
    {
        SDL_Event sdlEvent;
        while(SDL_PollEvent(&sdlEvent))
        {
            Event* event = TranslateEvent(sdlEvent);
            
            if(event != nullptr)
            {
                DispatchEvent(event);
            }

            delete event;
        }
    }

    void WindowHandler::DispatchEvent(Event* event)
    {
        SDL_WindowID id = event->WindowID();

        if(id != 0)
        {
            auto it = m_Windows.find(id);

            if(it == m_Windows.end())
                return;

            Window* window = it->second;
            
            window->HandleEvent(event);
            
            if(window->ShouldClose())
                m_WindowCloseRequested = true;
        }
        else
        {
            for(auto& [id, window] : m_Windows)
            {
                window->HandleEvent(event);
            }
        }
    }

    void WindowHandler::Run()
    {
        while(m_Windows.size() > 0)
        {
            DispatchEvents();
            
            for(auto& [id, window] : m_Windows)
            for(auto layer : window->GetLayerStack())
                 layer->OnUpdate(0.016f);

            for(auto& [id, window] : m_Windows)
            for(auto layer : window->GetLayerStack())
            layer->OnRender();

            for(auto& [id, window] : m_Windows)
            for(auto layer : window->GetLayerStack())
                layer->OnUIRender();
            
            if(m_WindowCloseRequested)
                ReleaseClosedWindows();
        }
    }


    void WindowHandler::RequestWindowClose()
    {
        m_WindowCloseRequested = true;
    }

    void WindowHandler::ReleaseClosedWindows()
    {
        for(auto it = m_Windows.begin(); it != m_Windows.end(); )
        {
            if(it->second->ShouldClose())
            {
                delete it->second;
                it = m_Windows.erase(it);
                continue;
            }

            it++;
        }

        m_WindowCloseRequested = false;
    }

    void WindowHandler::CloseAllWindows()
    {
        m_WindowCloseRequested = true;

        for(auto& [id, window] : m_Windows)
            window->Close();
    }
}