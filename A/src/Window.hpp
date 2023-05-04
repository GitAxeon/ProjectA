#pragma once

#include "LayerStack.hpp"
#include "Graphics/Rendering.hpp"

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_events.h>

#include <string>
#include <cstdint>

namespace ProjectA
{
    struct WindowInfo
    {
        WindowInfo(
            std::string name = "default", 
            uint32_t width = 700,
            uint32_t height = 320,
            Render::API renderingAPI = Render::API::SDL
        ) : Name(name), Width(width), Height(height), RenderingAPI(renderingAPI) { }
        
        std::string Name;
        uint32_t Width;
        uint32_t Height;
        Render::API RenderingAPI;
    };

    class Window
    {
    public:
        Window(const WindowInfo& info);
        ~Window();

        std::string Title() const { return m_WindowInfo.Name; }
        uint32_t Width() const { return m_WindowInfo.Width; }
        uint32_t Height() const { return m_WindowInfo.Height; }
        bool IsOpen() const { return m_IsOpen; }
        bool ShouldClose() const { return !m_IsOpen; }
        void Resize(uint32_t width, uint32_t height);
        void Close();
        
        SDL_Window* GetSDLWindow() const { return m_SDLWindow; }
        Layer* GetLayer() { return nullptr; }
        LayerStack& GetLayerStack() { return m_Layers; };

        template<typename... T>
        static void AddLayer(Window* anyWindow)
        {
            auto& layers = anyWindow->GetLayerStack();
            Layer* layer = nullptr;
            ((layer = new T, layer->SupplyWindow(anyWindow), layers.Push(layer), layer->OnAttach()), ...);
        }

        void HandleEvent(Event* event);
        void UpdateLayers();

    private:
        SDL_Window* m_SDLWindow;

        WindowInfo m_WindowInfo;
        bool m_IsOpen = true;
        
        LayerStack m_Layers;
        
        GraphicsContext m_Context;
    }; 
}