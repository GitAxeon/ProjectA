#include "Event.hpp"

#include <tuple>

namespace ProjectA
{
    std::tuple<float, float> MousePosition()
    {
        float x, y;
        SDL_GetMouseState(&x, &y);

        return {x, y};
    }

    MouseButton SDLButtonToMouseButton(uint8_t SDLButton)
    {
        switch(SDLButton)
        {
            case SDL_BUTTON_LEFT: return MouseButton::Left;
            case SDL_BUTTON_RIGHT: return MouseButton::Right;
            case SDL_BUTTON_MIDDLE: return MouseButton::Middle;
            default: return MouseButton::Unknown;
        }
    }

    AWindowID GetEventTargetWindowID(const SDL_Event& event)
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
        AWindowID id = GetEventTargetWindowID(e);

        switch(e.type)
        {
            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                return new EventWindowClose(id);

            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                return new EventMouseButtonDown(id, SDLButtonToMouseButton(e.button.button), false);
            
            case SDL_EVENT_MOUSE_BUTTON_UP:
                return new EventMouseButtonUp(id, SDLButtonToMouseButton(e.button.button));
            
            case SDL_EVENT_KEY_DOWN:
                return new EventKeyDown(id, Key::FromSDLKeycode(e.key.keysym.sym), e.key.repeat);
            
            case SDL_EVENT_KEY_UP:
                return new EventKeyUp(id, Key::FromSDLKeycode(e.key.keysym.sym));
            
            default:
                return nullptr;
        }
    }
}