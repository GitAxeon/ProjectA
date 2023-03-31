#pragma once 

#include <SDL3/SDL_events.h>

namespace ProjectA
{
    enum class EventType 
    { 
        AE_QUIT,
        AE_WINDOW_CLOSE_REQUEST,
        AE_WINDOW_RESIZE,
        AE_KEYDOWN,
        AE_KEYUP,
        AE_MOUSE_MOVE,
        AE_MOUSE_DOWN,
        AE_MOUSE_UP
    };

    struct Event
    {
        EventType Type;

    };

    SDL_WindowID GetEventTargetWindowID(const SDL_Event& event);
}