#include "A.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    class DemoLayer : public ProjectA::Layer
    {
        void OnAttach() override
        {
            std::cout << "Demolayer attached\n";
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
                ProjectA::Window* wnd = ProjectA::StaticWindowHandler::CreateWindow({ "Test window", 700, 320 });
                ProjectA::Window::AddLayer<DemoLayer>(wnd);
            }
        }

        void OnEvent(ProjectA::Event* event)
        {
            if(event->GetType() == ProjectA::EventType::KeyDown)
            {

            }

            if(event->MatchesType<ProjectA::EventKeyDown>())
            {
                std::cout << "Hey the new events kinda working yes?\n" << std::endl;
            }

            std::cout << *event << std::endl;

            // if(ProjectA::EventTypeMatch<ProjectA::EventKeyDown>(event))
            // {

            // }
        }
    };

    class EbolaLayer : public ProjectA::Layer
    {
        void OnAttach() override
        {
            std::cout << ">> EBOLALAYER ATTACHED\n";
        }

        void OnUpdate(float dt) override
        {
            //std::cout << "AAAAAAAAAAAAAAAA\n";
        }
    };

    ProjectA::Init();

    ProjectA::StaticWindowHandler::Configuration config;
    config.EnableMultiThreading = false;
    config.RenderingAPI = ProjectA::Render::API::SDL;
    ProjectA::StaticWindowHandler::Configure(config);

    ProjectA::Window* MainWindow = ProjectA::StaticWindowHandler::CreateWindow({ "Main Window", 700, 320 });
    ProjectA::Window::AddLayer<EbolaLayer, DemoLayer>(MainWindow);

    ProjectA::Window* EditorWindow = ProjectA::StaticWindowHandler::CreateWindow({ "Test Window", 1920, 720 });
    ProjectA::Window::AddLayer<DemoLayer>(EditorWindow);

    ProjectA::StaticWindowHandler::Run();
    
    ProjectA::Deinit();
}