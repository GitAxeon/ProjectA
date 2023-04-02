#pragma once

#include "Keycode.hpp"

#include <SDL3/SDL_events.h>

#include <iostream>

namespace ProjectA
{
    enum class EventType 
    { 
        
        WindowClose, WindowResize,
        KeyBoardMove /*:^)*/, KeyDown, KeyUp,
        MouseMove, MouseButtonDown, MouseButtonUp
    };

    #define EVENT_CLASS_TYPE(type)  static EventType GetStaticType() { return EventType::type; }\
                                    virtual EventType GetEventType() const override { return GetStaticType(); }\
                                    virtual const char* GetName() const override { return #type; }
    struct Event
    {
        bool Handled = false;

        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual std::string ToString() const { return GetName(); }

        template<typename T>
        static bool Match(const Event& e)
        {
            return e.GetEventType() == T::GetStaticType();
        }
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }

    SDL_WindowID GetEventTargetWindowID(const SDL_Event& event);

    class KeyDown : public Event
    {
    public:
        KeyDown(Keycode key, bool repeat) 
            : Code(key), Repeat(repeat) { }
         
        Keycode Code;
        bool Repeat = false;

        EVENT_CLASS_TYPE(KeyDown);
    };
}