#include "A.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    class Renderer
    {
        Renderer() = default;
    };

    class DemoLayer : public ProjectA::Layer
    {
    public:
        void OnEvent(ProjectA::Event* event)
        {
            switch(event->GetType())
            {
                case ProjectA::EventType::KeyDown:
                {
                    auto evnt = ProjectA::Event::Cast<ProjectA::EventKeyDown>(event);

                    if(evnt->KeyEquals(ProjectA::Key::Key::P) && evnt->NotRepeating())
                    {
                        std::cout << GetWindow()->Title() << "\n";
                        ProjectA::Window* wnd = ProjectA::WindowHandler::CreateWindow({ "Test", 700, 320 });
                        ProjectA::Window::AddLayer<DemoLayer>(wnd);
                    }

                } break;
                
                case ProjectA::EventType::MouseButtonDown:
                {
                    auto [mouseX, mouseY] = ProjectA::MousePosition();
                    std::cout << "Mouse position: " << mouseX << ", " << mouseY << "\n";
                } break;
            }

            std::cout << *event << "\n";
        }

        void OnRender()
        {
            // m_Renderer->Target(A::Render::Target::Texture, &m_Image);
            // m_Renderer->DoAThing(.. some params ..);
            // m_Renderer->Draw({120, 130}, m_Image);
        }

    private:
        Image m_Image;
        //Shared<Renderer> m_Renderer;
    };

    class TestLayer : public ProjectA::Layer
    {
    };

    ProjectA::Init();

    ProjectA::WindowHandler::Configuration config;
    config.RenderingAPI = ProjectA::Render::API::SDL;
    
    ProjectA::WindowHandler::Configure(config);

    ProjectA::Window* MainWindow = ProjectA::WindowHandler::CreateWindow({ "Main Window", 700, 320 });
    ProjectA::Window::AddLayer<TestLayer, DemoLayer>(MainWindow);

    ProjectA::WindowHandler::CreateWindow({"Vulkan", 700, 320, ProjectA::Render::API::Vulkan});
    ProjectA::WindowHandler::CreateWindow({"OpenGL", 700, 320, ProjectA::Render::API::OpenGL});

    ProjectA::WindowHandler::Run();

    ProjectA::Deinit();
}