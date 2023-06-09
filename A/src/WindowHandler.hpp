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

        static void Configure(const Configuration& configuration);
        static Window* CreateWindow(const WindowInfo& info);
        static void CloseAllWindows();
        static void Run();
        static void RequestWindowClose();

    private:
        WindowHandler() = default;
        ~WindowHandler() = default;

        static void DispatchEvents();
        static void DispatchEvent(Event* test);
        static void ReleaseClosedWindows();

    private:
        inline static Configuration m_Configuration;
        inline static std::map<SDL_WindowID, Window*> m_Windows;
        inline static bool m_WindowCloseRequested = false;
    };
}