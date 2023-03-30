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

    // static std::vector<Window*> g_Windows;
    // static Configuration g_Configuration;
    // static bool g_KeepOpen = true;

    void Configure(const Configuration& configuration);
    bool Init();
    int Run();
    void Deinit();

    bool MultiThreadingEnabled();
    Configuration GetConfiguration();
    std::forward_list<Window*>& GetWindows();
}