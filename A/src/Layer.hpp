#pragma once

#include "Event.hpp"

#include <SDL3/SDL_events.h>

namespace ProjectA
{
    class Layer
    {
    public:
        Layer() { }
        virtual ~Layer() { }
        
        virtual void OnDetach()                 {}
        virtual void OnAttach()                 {}

        virtual void OnEvent(const SDL_Event&)  {}
        virtual void OnEvent(Event*)      {}
        virtual void OnUpdate(float deltaTime)  {}

        virtual void OnRender()                 {}
        virtual void OnUIRender()               {}
    };
}