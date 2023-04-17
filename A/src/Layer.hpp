#pragma once

#include "Event.hpp"

#include <SDL3/SDL_events.h>

namespace ProjectA
{
    class Window;

    class Layer
    {
    public:
        Layer() : m_Window(nullptr) { }
        Layer(Window* window) : m_Window(window) { }

        virtual ~Layer() { }
        
        virtual void OnDetach()                 {}
        virtual void OnAttach()                 {}
        
        virtual void OnEvent(Event*)      {}
        virtual void OnUpdate(float deltaTime)  {}

        virtual void OnRender()                 {}
        virtual void OnUIRender()               {}

        Window* GetWindow() const { return m_Window; }
        
    private:
        Window* m_Window;
    };
}