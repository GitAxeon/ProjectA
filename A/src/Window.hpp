#pragma once

#include "LayerStack.hpp"
#include "Rendering.hpp"

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_events.h>

#include <string>

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

        std::string Title() const { return m_WindowInfo.Name; }
        unsigned int Width() const { return m_WindowInfo.Width; }
        unsigned int Height() const { return m_WindowInfo.Height; }
        bool IsOpen() const { return m_IsOpen; }
        bool ShouldClose() const { return !m_IsOpen; }
        LayerStack& GetLayerStack() { return m_Layers; };
        SDL_Window* GetSDLWindow() const { return m_SDLWindow; }
        void Close();   
        
        static Window* Create(const WindowInfo& info);
        static void AddLayer(Window* window, Layer* layer);
        void Resize(unsigned int width, unsigned int height);

        void HandleEvent(const SDL_Event& event);
        void UpdateLayers();

    private:
        SDL_Window* m_SDLWindow;

        WindowInfo m_WindowInfo;
        bool m_IsOpen = true;
        
        LayerStack m_Layers;
    }; 
}