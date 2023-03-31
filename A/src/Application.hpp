#pragma once

#include "Scopes.hpp"
#include "Window.hpp"
#include "Rendering.hpp"

#include <forward_list>

namespace ProjectA
{
    struct Configuration
    {
        Render::API RenderingAPI;
        bool EnableMultiThreading;

        Configuration() 
            : RenderingAPI(Render::API::SDL), EnableMultiThreading(false) { }
    };

    void Configure(const Configuration& configuration);
    bool Init();
    void Deinit();
    int Run();

    bool DispatchEvents();
    bool DispatchEvent(const SDL_Event& event);
    void ReleaseClosedWindows();
    void ReleaseWindows();

    bool MultiThreadingEnabled();
    Configuration GetConfiguration();
    std::forward_list<Window*>& GetWindows();
}