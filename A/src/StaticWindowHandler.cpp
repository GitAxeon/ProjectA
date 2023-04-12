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
        // Dno if one should check wether/ or not the sdl window is null or something 
        Window* window = new Window(info);
        SDL_WindowID id = SDL_GetWindowID(window->GetSDLWindow());
        
        m_Windows.emplace(id, window);

        return window;
    }

    void StaticWindowHandler::DispatchEvents()
    {
        SDL_Event sdlEvent;
        while(SDL_PollEvent(&sdlEvent))
        {
            Event* evnt = TranslateEvent(sdlEvent);
            
            if(evnt != nullptr)
            {
                DispatchEvent(evnt);
            }

            delete evnt;
        }
    }

    void StaticWindowHandler::DispatchEvent(Event* event)
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

    void StaticWindowHandler::CloseAllWindows()
    {
        m_WindowCloseRequested = true;

        for(auto& [id, window] : m_Windows)
            window->Close();
    }
}