#include "A.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    class DemoLayer : public ProjectA::Layer
    {
    public:
        void OnAttach() override
        {
            std::cout << "Demolayer attached\n";
        }

        void OnDetach() override 
        {
            std::cout << "Demolayer detached\n";
        }

        void OnUpdate(float deltaTime) override
        {
            // std::cout << "OnUpdate(" << deltaTime << ")\n";
        }

        void OnEvent(ProjectA::Event* event)
        {
            if(event->GetType() == ProjectA::EventType::KeyDown) { }

            if(event->MatchesType<ProjectA::EventKeyDown>())
            {
                auto ptr = ProjectA::Event::Cast<ProjectA::EventKeyDown>(event);

                if(ptr->Key() == ProjectA::Keycode::P)
                {
                    ProjectA::Window* wnd = ProjectA::StaticWindowHandler::CreateWindow({ "Test", 700, 320 });
                    ProjectA::Window::AddLayer<DemoLayer>(wnd);
                }
            }

            std::cout << *event << "\n";
        }

        void OnRender()
        {
            // ProjectA::Render(m_Image);
        }

    private:
        Image m_Image;
    };

    class TestLayer : public ProjectA::Layer
    {
        void OnAttach() override
        {
            std::cout << ">> Test\n";
        }

        void OnDetach() override
        {
            std::cout << ">> Testn't\n";
        }
    };

    ProjectA::Init();

    ProjectA::StaticWindowHandler::Configuration config;
    config.RenderingAPI = ProjectA::Render::API::SDL;
    
    ProjectA::StaticWindowHandler::Configure(config);

    ProjectA::Window* MainWindow = ProjectA::StaticWindowHandler::CreateWindow({ "Main Window", 700, 320 });
    ProjectA::Window::AddLayer<TestLayer, DemoLayer>(MainWindow);

    ProjectA::Window* EditorWindow = ProjectA::StaticWindowHandler::CreateWindow({ "Test Window", 700, 320 });
    ProjectA::Window::AddLayer<DemoLayer>(EditorWindow);

    ProjectA::StaticWindowHandler::Run();
    
    ProjectA::Deinit();
}