#include "StaticWindowHandler.hpp"
#include "Event.hpp"

#include <SDL3/SDL_events.h>

namespace ProjectA
{
    void StaticWindowHandler::Configure(const Configuration& configuration)
    {
        m_Configuration = configuration;
    }

    Window* StaticWindowHandler::CreateWindow(const WindowInfo& info)
    {
        Window* window = new Window(info);
        SDL_WindowID id = SDL_GetWindowID(window->GetSDLWindow());
        
        m_Windows.emplace(id, window);

        return window;
    }

    void StaticWindowHandler::DispatchEvents()
    {
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            DispatchEvent(e);
        }
    }

    void StaticWindowHandler::DispatchEvent(const SDL_Event& event)
    {
        SDL_WindowID id = GetEventTargetWindowID(event);

        if(id != 0)
        {
            Window* window = m_Windows.at(id);

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

    void StaticWindowHandler::Run()
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

    void StaticWindowHandler::ReleaseClosedWindows()
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
}