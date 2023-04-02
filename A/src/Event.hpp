#pragma once 

#include <SDL3/SDL_events.h>

namespace ProjectA
{
    enum class EventType 
    { 
        
        WindowClose, WindowResize,
        KeyBoardMove /*:^)*/, KeyDown, KeyUp,
        MouseMove, MouseButtonDown, MouseButtonUp
    };

    #define EVENT_CLASS_TYPE(type)  static EventType GetEventType() { return EventType::type; } \
                                    virtual const char* GetName() const override { return #type; }
    struct Event
    {
        bool Handled = false;

        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual std::string ToString() const { return GetName(); }
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }

    SDL_WindowID GetEventTargetWindowID(const SDL_Event& event);

    class KeyEvent : public Event
    {
        
    };
}