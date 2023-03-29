#pragma once

#include "Layer.hpp"

#include <SDL3/SDL_video.h>

#include <string>

extern bool g_KeepOpen;

namespace ProjectA
{
    struct WindowInfo
    {
        WindowInfo(
            std::string name = "default", 
            unsigned int width = 700,
            unsigned int height = 320,
            Render::API renderingAPI = Render::API::SDL
        ) : Name(name), Width(width), Height(height), RenderingAPI(renderingAPI) { }
        
        std::string Name;
        unsigned int Width;
        unsigned int Height;
        Render::API RenderingAPI;
    };

    class Window
    {
    public:
        Window(const WindowInfo& info);
        ~Window();

        std::string Title() const { return m_Title; }
        unsigned int Width() const { return m_Width; }
        unsigned int Height() const { return m_Height; }
        bool IsOpen() const { return m_IsOpen; }

        void DispatchEvents();
        void Close();   

        SDL_Window* GetSDLWindow() const { return m_SDLWindow; }

        void Resize(unsigned int width, unsigned int height); 

        std::vector<Owned<Layer>>& GetLayers() { return Layers; };

    private:
        SDL_Window* m_SDLWindow;

        std::string m_Title;
        unsigned int m_Width;
        unsigned int m_Height;

        bool m_IsOpen = true;
        
        std::vector<Owned<Layer>> Layers;
        // Owned<GraphicsContext> m_Context;
    };
}