#include "Event.hpp"

namespace ProjectA
{
    MouseButton SDLButtonToMouseButton(uint8_t SDLButton)
    {
        switch(SDLButton)
        {
            case SDL_BUTTON_LEFT: return MouseButton::Left;
            case SDL_BUTTON_RIGHT: return MouseButton::Right;
            case SDL_BUTTON_MIDDLE: return MouseButton::Middle;
            default: return MouseButton::Uknown;
        }
    }

    SDL_WindowID GetEventTargetWindowID(const SDL_Event& event)
    {
        switch(event.type)
        {
            case SDL_EVENT_KEY_DOWN:
            case SDL_EVENT_KEY_UP:  
                return event.key.windowID;
            case SDL_EVENT_MOUSE_MOTION:
                return event.motion.windowID;
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
            case SDL_EVENT_MOUSE_BUTTON_UP:
                return event.button.windowID;
            case SDL_EVENT_MOUSE_WHEEL:
                return event.wheel.windowID;
            case SDL_EVENT_WINDOW_HIDDEN:
            case SDL_EVENT_WINDOW_EXPOSED:
            case SDL_EVENT_WINDOW_MOVED:
            case SDL_EVENT_WINDOW_RESIZED:
            case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:
            case SDL_EVENT_WINDOW_MINIMIZED:
            case SDL_EVENT_WINDOW_MAXIMIZED:
            case SDL_EVENT_WINDOW_RESTORED:
            case SDL_EVENT_WINDOW_MOUSE_ENTER:
            case SDL_EVENT_WINDOW_MOUSE_LEAVE:
            case SDL_EVENT_WINDOW_FOCUS_GAINED:
            case SDL_EVENT_WINDOW_FOCUS_LOST:
            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
            case SDL_EVENT_WINDOW_TAKE_FOCUS:
            case SDL_EVENT_WINDOW_HIT_TEST:
            case SDL_EVENT_WINDOW_ICCPROF_CHANGED:
            case SDL_EVENT_WINDOW_DISPLAY_CHANGED:
                return event.window.windowID;
            default:
                return 0;
        };
    }

    Event* TranslateEvent(const SDL_Event& e)
    {
        switch(e.type)
        {
            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                return new EventWindowClose(e.window.windowID);

            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                return new EventMouseButtonDown(SDLButtonToMouseButton(e.button.button), false);
            
            case SDL_EVENT_MOUSE_BUTTON_UP:
                return new EventMouseButtonUp(SDLButtonToMouseButton(e.button.button));
            
            case SDL_EVENT_KEY_DOWN:
                return new EventKeyDown(SDLKeycodeToKeycode(e.key.keysym.sym), e.key.repeat);
            
            case SDL_EVENT_KEY_UP:
                return new EventKeyUp(SDLKeycodeToKeycode(e.key.keysym.sym));
            
            default:
                return nullptr;
        }
    }

    Keycode SDLKeycodeToKeycode(const SDL_Keycode k)
    {
        auto it = KeyMapping.find(k);

        if(it != KeyMapping.end())
        {
            return it->second;
        }

        return Keycode::Unknown;
    }
}