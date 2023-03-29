#include "Scopes.hpp"
#include "Window.hpp"
#include "Rendering.hpp"

#include <vector>

namespace ProjectA::Application
{
    std::vector<Owned<Window>> g_Windows;
    Configuration g_Configuration;

    struct Configuration
    {
        Render::API RenderingAPI;
        bool EnableMultiThread;

        Configuration() 
            : RenderingAPI(Render::API::SDL), EnableMultiThread(false) { }
    };

    bool MultiThreadingEnabled() { return g_Configuration.EnableMultiThread; }

    void Configure(const Configuration& configuration)
    {
        g_Configuration = configuration;
    }

    int Run();
}