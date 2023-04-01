#pragma once

#include "Window.hpp"

#include <map>

namespace ProjectA
{
    class WindowHandler
    {
    public:
        struct Configuration
        {
            Render::API RenderingAPI;
            bool EnableMultiThreading;

            Configuration() 
                : RenderingAPI(Render::API::SDL), EnableMultiThreading(false) { }
        };

        static WindowHandler& Instance();

        void Configure(const Configuration& configuration);
        Window* CreateWindow(const WindowInfo& info);

        void Run();

    private:
        WindowHandler() = default;
        ~WindowHandler() = default;

        WindowHandler(const WindowHandler&) = delete;
        WindowHandler& operator=(const WindowHandler&) = delete;

        void DispatchEvents();
        void DispatchEvent(const SDL_Event& event);

        void ReleaseClosedWindows();

    private:
        inline static Configuration m_Configuration;
        inline static std::map<SDL_WindowID, Window*> m_Windows;
        inline static bool m_WindowCloseRequested = false;
    };

    inline WindowHandler& Puebes = WindowHandler::Instance();
}