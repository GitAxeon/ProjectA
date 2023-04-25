#include "A.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    class DemoLayer : public ProjectA::Layer
    {
    public:
        DemoLayer(ProjectA::Window* wnd) : ProjectA::Layer(wnd) { }

        void OnEvent(ProjectA::Event* event)
        {
            switch(event->GetType())
            {
                case ProjectA::EventType::KeyDown:
                {
                    auto evnt = ProjectA::Event::Cast<ProjectA::EventKeyDown>(event);

                    if(evnt->KeyEquals(ProjectA::Key::Key::P) && evnt->NotRepeating())
                    {
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
    };

    ProjectA::Init();

    ProjectA::WindowHandler::Configuration config;
    config.RenderingAPI = ProjectA::Render::API::SDL;
    
    ProjectA::WindowHandler::Configure(config);

    ProjectA::Window* MainWindow = ProjectA::WindowHandler::CreateWindow({ "Main Window", 700, 320 });
    ProjectA::Window::AddLayer<TestLayer, DemoLayer>(MainWindow);

    ProjectA::WindowHandler::Run();

    ProjectA::Deinit();
}