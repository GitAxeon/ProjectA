#include "Application.hpp"

namespace ProjectA::Application
{
    int Run()
    {
        for(auto& window : g_Windows)
        {
            for(auto& layer : window->GetLayers())
            {
                
            }
        }
        
        while(g_Windows.size() > 0)
        {
            for(auto& window : g_Windows)
            {
                if(!window->IsOpen())
                    continue;

                for(auto& layer : window->GetLayers())
                {
                    
                }
            }
        }
    }
}