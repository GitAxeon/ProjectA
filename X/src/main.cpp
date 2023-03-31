#include "A.hpp"
#include "WindowHandler.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    class DemoLayer : public ProjectA::Layer
    {    
        void OnAttach() override
        {
            std::cout << "Attached\n";
        }

        void OnUpdate(float deltaTime) override
        {
            // std::cout << "I am gamelayer wooo\n";
        }

        void OnRender() override
        {
            // std::cout << "#HELP I TRYING RENDER\n";
        }

        void OnEvent(const SDL_Event& e)
        {
            if(e.type == SDL_EVENT_KEY_DOWN && e.key.keysym.sym == SDLK_p)
            {
                // ProjectA::Window* wnd = ProjectA::Window::Create({ "Test window", 700, 320 });
                ProjectA::Window* wnd = ProjectA::WindowHandler::GetInstance()->CreateWindow({ "Test window", 700, 320 }); 
                ProjectA::Window::AddLayer(wnd, new DemoLayer);
            }
        }
    };

    // ProjectA::Configuration config;
    // config.RenderingAPI = ProjectA::Render::API::SDL;
    // config.EnableMultiThreading = false;

    // ProjectA::Configure(config);
    // ProjectA::Init();

    // ProjectA::Window* MainWindow = ProjectA::Window::Create({"Main window", 700, 320});
    // ProjectA::Window::AddLayer(MainWindow, new DemoLayer);

    // ProjectA::Window* EditorWindow = ProjectA::Window::Create({"Editor window", 700, 320});
    // ProjectA::Window::AddLayer(EditorWindow, new DemoLayer);

    // ProjectA::Run();
    
    // ProjectA::Deinit();

    ProjectA::Init();

    ProjectA::WindowHandler::Configuration config;
    config.EnableMultiThreading = false;
    config.RenderingAPI = ProjectA::Render::API::SDL;

    ProjectA::WindowHandler* windowHandler = ProjectA::WindowHandler::GetInstance();
    windowHandler->Configure(config);

    ProjectA::Window* MainWindow = windowHandler->CreateWindow({ "Main window", 700, 320 });
    ProjectA::Window::AddLayer(MainWindow, new DemoLayer);

    ProjectA::Window* EditorWindow = windowHandler->CreateWindow({ "Editor window", 700, 320 });
    ProjectA::Window::AddLayer(EditorWindow, new DemoLayer);

    windowHandler->Run();

    ProjectA::Deinit();
}