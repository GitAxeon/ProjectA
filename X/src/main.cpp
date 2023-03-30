#include "A.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    /* 
        class Game::GameLayer : public ProjectA::Input::Layer
        {
            TestLayer() { }

            OnAttach() { }

            OnDetach() { }
            
            OnEvent(const Event& e)
            {
                Delegate<EventType>(e)
                {

                }

                Delegate<OtherEventType>(e)
                {

                }
            }
            
            OnUpdate() { }

            OnRender() { }
            OnUIRender() { }
        };

        ProjectA::Application::Configuration config;
        config.RenderingAPI = ProjectA::RenderAPI::SDL;
        config.EnableMultiThread = false;

        ProjectA::Configure(config)

        ProjectA::Window MainWindow = ProjectA::Window::Create("Main window", 700, 320);
        MainWindow::PushLayer(new Game::GameLayer);

        ProjectA::Window EditorWindow = ProjectA::Window::Create("Editor window", 700, 320);
        EditorWindow.PushLayer(new Game::EditorLayer);

        return ProjectA::Run();
    */

    class GameLayer : public ProjectA::Layer
    {    
        void OnAttach() override
        {
            std::cout << "Attached\n";
        }

        void OnUpdate() override
        {
            // std::cout << "I am gamelayer wooo\n";
        }

        void OnRender() override
        {
            // std::cout << "#HELP I TRYING RENDER\n";
        }
    };

    ProjectA::Configuration config;
    config.RenderingAPI = ProjectA::Render::API::SDL;
    config.EnableMultiThreading = false;

    ProjectA::Configure(config);
    ProjectA::Init();

    ProjectA::Window* MainWindow = ProjectA::Window::Create({"Main window", 700, 320});
    ProjectA::Window::AddLayer(MainWindow, new GameLayer);

    ProjectA::Window* EditorWindow = ProjectA::Window::Create({"Editor window", 700, 320});
    ProjectA::Window::AddLayer(EditorWindow, new GameLayer);

    ProjectA::Run();
    
    ProjectA::Deinit();
    std::cout << "HELP\n";
    
    std::cin.get();    
}