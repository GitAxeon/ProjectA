

#include "Color.hpp"
#include "Scopes.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    // ProjectA::WindowInfo info;
    // info.Name = "My app";
    // info.Width = 700;
    // info.Height = 320;
    // info.RenderingAPI = RenderAPI::SDL;
    // ProjectA::Window window;


    /*
        ProjectA::Application::Configuration config;
        config.RenderingAPI = ProjectA::RenderAPI::SDL;
        config.EnableMultiThread = true;

        ProjectA::Configure(config)

        ProjectA::Window ProjectA::Window::Create("bruh", 700, 320, ProjectA::RenderAPI::SDL);
        
        ProjectA::Input::Handle(EvenType, Window, []() {
            
            Delegate<Type, Param>(Event []() {
                
            });

            Delegate<Type, Param>(Event []() {

            });
        });

        ProjectA::Window::OnUpdate(Window, []() {

        });

        // 

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

    std::cin.get();    
}