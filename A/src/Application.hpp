#pragma once

#include "Scopes.hpp"
#include "Window.hpp"
#include "Rendering.hpp"

#include <vector>

namespace ProjectA
{
    struct Configuration
    {
        Render::API RenderingAPI;
        bool EnableMultiThreading;

        Configuration() 
            : RenderingAPI(Render::API::SDL), EnableMultiThreading(false) { }
    };

    std::vector<Owned<Window>> g_Windows;
    Configuration g_Configuration;

    bool Init();
    bool Close();
    bool MultiThreadingEnabled();
    void Configure(const Configuration& configuration);
    Configuration GetConfiguration();
    
    std::vector<Owned<Window>>& GetWindows();
}

// namespace ProjectA
// {
//     static Application g_Application;

//     class Application
//     {
//     public:
//         struct Configuration
//         {
//             Render::API RenderingAPI;
//             bool EnableMultiThreading;

//             Configuration() 
//                 : RenderingAPI(Render::API::SDL), EnableMultiThreading(false) { }
//         };

//     public:
//         Application();
//         ~Application();

//         bool Init();
//         bool MultiThreadingEnabled() const { return m_Configuration.EnableMultiThreading; }
//         void Configure(const Configuration& configuration);
//         Configuration GetConfiguration() const;
        
//         std::vector<Owned<Window>>& GetWindows();

//     private:
//         std::vector<Owned<Window>> m_Windows;
//         Configuration m_Configuration;
//     };
// }