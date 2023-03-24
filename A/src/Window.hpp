#pragma once

#include <SDL3/SDL_video.h>

#include <string>

extern bool g_KeepOpen;

namespace ProjectA
{
    struct WindowInfo
    {
        std::string Name = "default";
        unsigned int Width = 700;
        unsigned int Height = 320;
    };

    class Window
    {
    public:
        Window(const WindowInfo& info = WindowInfo());
        ~Window();

        std::string Title() const { return m_Title; }
        unsigned int Width() const { return m_Width; }
        unsigned int Height() const { return m_Height; }
        bool IsOpen() const { return m_IsOpen; }

        void DispatchEvents();
        void Close();   

        SDL_Window* GetSDLWindow() const { return m_Window; }

        void Resize(unsigned int width, unsigned int height); 

    private:
        SDL_Window* m_Window;
        
        std::string m_Title;
        unsigned int m_Width;
        unsigned int m_Height;

        bool m_IsOpen = true;
    };
}