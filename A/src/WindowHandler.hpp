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

        static WindowHandler* GetInstance();

        WindowHandler(WindowHandler&) = delete;
        void operator=(const WindowHandler&) = delete;

        void Configure(const Configuration& configuration);
        Window* CreateWindow(const WindowInfo& info);

        void Run();

    private:
        WindowHandler() = default;
        ~WindowHandler() = default;

        void DispatchEvents();
        void DispatchEvent(const SDL_Event& event);

        void ReleaseClosedWindows();

    private:
        static WindowHandler* m_Instance;

        Configuration m_Configuration;
        std::map<SDL_WindowID, Window*> m_Windows;

        bool m_WindowCloseRequested = false;
    };
}