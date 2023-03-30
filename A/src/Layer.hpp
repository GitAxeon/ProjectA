#pragma once
#include <SDL3/SDL_events.h>

namespace ProjectA
{
    class Layer
    {
    public:
        virtual void OnDetach()                 {}
        virtual void OnAttach()                 {}

        virtual void OnEvent(const SDL_Event&)  {}
        virtual void OnUpdate()                 {}

        virtual void OnRender()                 {}
        virtual void OnUIRender()               {}
    };
}