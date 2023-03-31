#include "WindowHandler.hpp"
#include "Event.hpp"

#include <SDL3/SDL_events.h>

namespace ProjectA
{
    WindowHandler* WindowHandler::m_Instance { nullptr };

    WindowHandler* WindowHandler::GetInstance()
    {
        if(m_Instance == nullptr)
        {
            m_Instance = new WindowHandler;
        }

        return m_Instance;
    }

    void WindowHandler::Configure(const Configuration& configuration)
    {
        m_Configuration = configuration;
    }

    Window* WindowHandler::CreateWindow(const WindowInfo& info)
    {
        Window* window = new Window(info);
        SDL_WindowID id = SDL_GetWindowID(window->GetSDLWindow());
        
        m_Windows.emplace(id, window);

        return window;
    }

    void WindowHandler::DispatchEvents()
    {
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            DispatchEvent(e);
        }
    }

    void WindowHandler::DispatchEvent(const SDL_Event& event)
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
}