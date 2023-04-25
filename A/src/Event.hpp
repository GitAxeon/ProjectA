#pragma once

#include "Keycode_new.hpp"

#include <SDL3/SDL_events.h>

#include <iostream>
#include <cstdint>
#include <sstream>

namespace ProjectA
{
    class Event;
    using AWindowID = SDL_WindowID;

    AWindowID GetEventTargetWindowID(const SDL_Event& event);
    Event* TranslateEvent(const SDL_Event& e);

    std::tuple<float, float> MousePosition();

    enum class EventType 
    {
        None,
        WindowClose, WindowResize,
        KeyBoardMove /*:^)*/, KeyDown, KeyUp,
        MouseMove, MouseButtonDown, MouseButtonUp
    };

    enum class MouseButton
    {
        Unknown,
        Left,
        Middle,
        Right
    };

    constexpr int MouseButtonID(MouseButton button)
    {
        switch(button)
        {
        case MouseButton::Left:
            return 0;
        case MouseButton::Middle:
            return 2;
        case MouseButton::Right:
            return 1;
        case MouseButton::Unknown:
        default:
            return -1;
        }
    }

    #define CreateClassType(typename) static EventType GetStaticType() { return EventType::typename; }\
                                            EventType GetType() const { return GetStaticType(); }\
                                            const char* GetName() const { return #typename; }                           
    class Event
    {
    public:        
        virtual EventType GetType() const = 0;
        virtual const char* GetName() const = 0;
        virtual std::string ToString() const { return GetName(); }

        AWindowID WindowID() const { return m_WindowID; }

        template<typename T>
        bool MatchesType() const
        {
            return GetType() == T::GetStaticType();
        }

        template<typename T>
        static T* Cast(Event* eventPtr)
        {
            return static_cast<T*>(eventPtr);
        }
        
    protected:
        Event(AWindowID windowID) : m_WindowID(windowID) { }

    public: 
        bool Handled = false;
    private:
        AWindowID m_WindowID = 0;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }

    class EventWindowClose : public Event
    {
    public:
        EventWindowClose(AWindowID windowID) : Event(windowID) { }

        CreateClassType(WindowClose);
    };

    class EventWindowResize : public Event
    {
        EventWindowResize(AWindowID windowID, uint32_t width, uint32_t height)
            : Event(windowID), m_Width(width), m_Height(height) { }

        uint32_t Width() const { return m_Width; }
        uint32_t Height() const { return m_Height; }
        

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << " Width: " << m_Width << " Height: " << m_Height;
            return ss.str();
        }

        CreateClassType(WindowResize)

    private:
        uint32_t m_Width;
        uint32_t m_Height;
    };

    class EventKeyDown : public Event
    {
    public:
        EventKeyDown(SDL_Keycode windowID, Key::Key key, bool repeating) 
            : Event(windowID), m_Key(key), m_Repeating(repeating) { }

        Key::Key Key() const { return m_Key; }
        bool KeyEquals(Key::Key key) const { return key == m_Key; }

        bool Repeating() const { return m_Repeating; }
        bool NotRepeating() const { return !m_Repeating; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << " Key: " << Key::ToString(m_Key);
            ss << (m_Repeating ? " repeating: " : "");
            return ss.str();
        }

        CreateClassType(KeyDown)
    
    private:
        Key::Key m_Key;
        bool m_Repeating = false;
    };

    class EventKeyUp : public Event
    {
    public:
        EventKeyUp(AWindowID windowID, Key::Key key)
            : Event(windowID), m_Key(key) { }

        Key::Key Key() const { return m_Key; }
        bool KeyEquals(Key::Key key) const { return key == m_Key; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << " Key: " << Key::ToString(m_Key);
            return ss.str();
        }

        CreateClassType(KeyUp)
    
    private:
        Key::Key m_Key;
    };

    class EventMouseButtonDown : public Event
    {
    public: 
        EventMouseButtonDown(AWindowID windowID, MouseButton button, bool repeating)
            : Event(windowID), m_Button(button), m_Repeating(repeating) { }

        MouseButton Button() const { return m_Button; }
        bool Repeating() const { return m_Repeating; }
        bool NotRepeating() const { return !m_Repeating; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << " Button: " << MouseButtonID(m_Button);
            ss << (m_Repeating ? " Repeating" : "");
            return ss.str();
        }

        CreateClassType(MouseButtonDown)

    private:
        MouseButton m_Button;
        bool m_Repeating;
    };

    class EventMouseButtonUp : public Event
    {
    public:
        EventMouseButtonUp(AWindowID windowID, MouseButton button)
            : Event(windowID), m_Button(button) { }

        MouseButton Button() const { return m_Button; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << " Button: " << MouseButtonID(m_Button);
            return ss.str();
        }

        CreateClassType(MouseButtonUp)

    private:
        MouseButton m_Button;
    };
}