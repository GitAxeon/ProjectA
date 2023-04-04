#pragma once

#include "Keycode.hpp"

#include <SDL3/SDL_events.h>

#include <iostream>

namespace ProjectA
{
    class Event;
    SDL_WindowID GetEventTargetWindowID(const SDL_Event& event);
    Event* TranslateEvent(const SDL_Event& e);
    Keycode SDLKeycodeToKeycode(const SDL_Keycode k);

    enum class EventType 
    {
        None,
        WindowClose, WindowResize,
        KeyBoardMove /*:^)*/, KeyDown, KeyUp,
        MouseMove, MouseButtonDown, MouseButtonUp
    };

    enum class MouseButton
    {
        Uknown,
        Left,
        Middle,
        Right
    };

    #define CreateClassType(typename) static EventType GetStaticType() { return EventType::typename; }\
                                            EventType GetType() const { return GetStaticType(); }\
                                            const char* GetName() const { return #typename; }\
                                            virtual std::string ToString() const { return GetName(); }
    class Event
    {
    public:        
        virtual EventType GetType() const = 0;
        virtual std::string ToString() const = 0;

        template<typename T>
        bool MatchesType() const
        {
            return GetType() == T::GetStaticType();
        }
        
    public: 
        bool Handled = false;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }

    class WindowEvent : public Event
    {
    public:
        SDL_WindowID WindowID() const { return m_WindowID; }

    protected:
        WindowEvent(SDL_WindowID windowID) : m_WindowID(windowID) { }

        SDL_WindowID m_WindowID;
    };

    class EventWindowClose : public WindowEvent
    {
    public:
        EventWindowClose(SDL_WindowID windowID) : WindowEvent(windowID) { }

        CreateClassType(WindowClose);
    };

    class EventWindowResize : public WindowEvent
    {
        EventWindowResize(SDL_WindowID windowID, unsigned int width, unsigned int height)
            : WindowEvent(windowID), m_Width(width), m_Height(height) { }

        CreateClassType(WindowResize)

        unsigned int Width() const { return m_Width; }
        unsigned int Height() const { return m_Height; }

    private:
        unsigned int m_Width;
        unsigned int m_Height;
    };

    class EventKeyDown : public Event
    {
    public:
        EventKeyDown(Keycode key, bool repeating) : m_Code(key), m_Repeating(repeating) { }
        
        CreateClassType(KeyDown)
    
    private:
        Keycode m_Code;
        bool m_Repeating = false;
    };

    class EventKeyUp : public Event
    {
    public:
        EventKeyUp(Keycode key) : Code(key) { }

        CreateClassType(KeyUp)
    
    private:
        Keycode Code;
    };

    class EventMouseButtonDown : public Event
    {
    public: 
        EventMouseButtonDown(MouseButton button, bool repeating)
            : m_Button(button), m_Repeating(repeating) { }

        CreateClassType(MouseButtonDown);

    private:
        MouseButton m_Button;
        bool m_Repeating;
    };

    class EventMouseButtonUp : public Event
    {
    public:
        EventMouseButtonUp(MouseButton button)
            : m_Button(button) { }
        
        CreateClassType(MouseButtonUp)

    private:
        MouseButton m_Button;
    };
}