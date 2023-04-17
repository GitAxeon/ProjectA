#include "A.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    class DemoLayer : public ProjectA::Layer
    {
    public:
        DemoLayer(ProjectA::Window* wnd) : ProjectA::Layer(wnd) { }

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
                
                if(ptr->Key() == ProjectA::Key::Key::P)
                {
                    ProjectA::Window* wnd = ProjectA::WindowHandler::CreateWindow({ "Test", 700, 320 });
                    ProjectA::Window::AddLayer<DemoLayer>(wnd);
                }
            }

            ProjectA::Window* window = GetWindow();
            window->Close();

            auto [mouseX, mouseY] = ProjectA::MousePosition();
            std::cout << "Mouse position: " << mouseX << ", " << mouseY << "\n";

            std::cout << *event << "\n";
        }

        void OnRender()
        {
            // ProjectA::Renderer::Idk(m_Image);
            // ProjectA::Render(m_Image);
            // ProjectA::Render2D(m_Image);
        }

    private:
        Image m_Image;
    };

    class TestLayer : public ProjectA::Layer
    {
    public:
        TestLayer(ProjectA::Window* wnd) : ProjectA::Layer(wnd) { }

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

    ProjectA::WindowHandler::Configuration config;
    config.RenderingAPI = ProjectA::Render::API::SDL;
    
    ProjectA::WindowHandler::Configure(config);

    ProjectA::Window* MainWindow = ProjectA::WindowHandler::CreateWindow({ "Main Window", 700, 320 });
    ProjectA::Window::AddLayer<TestLayer, DemoLayer>(MainWindow);

    // ProjectA::Window* EditorWindow = ProjectA::WindowHandler::CreateWindow({ "Test Window", 700, 320 });
    // ProjectA::Window::AddLayer<DemoLayer>(EditorWindow);

    ProjectA::WindowHandler::Run();
    
    ProjectA::Deinit();
}