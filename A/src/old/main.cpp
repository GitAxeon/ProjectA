// #include "Application.hpp"
// #include "Scopes.hpp"
// #include "Renderer.hpp"
// #include "Color.hpp"

// #include "SDL3/SDL.h"
// #include "SDL3/SDL_mixer.h"
// #include "imgui.h"
// #include "imgui_impl_sdlrenderer.h"
// #include "imgui_impl_sdl3.h"

// #include <iostream>

// int MyFunction()
// {
//     SDL_Init(SDL_INIT_EVERYTHING);
    
//     if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) != 0)
//         std::cout << "Failed to initialize Mixer: " << Mix_GetError() << "\n";

//     Mix_Chunk* sound = Mix_LoadWAV("resource/sound/message-pop-sound.wav");

//     if(!sound)
//         std::cout << "Failed to load the given WAV- file\n";

//     ImGui::CreateContext();
//     ImGuiIO& io = ImGui::GetIO();
//     io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
//     ImGui::StyleColorsLight();

//     ProjectA::WindowInfo info;
//     info.Name = "ProjectA";
//     info.Width = 700;
//     info.Height = 320;

//     ProjectA::Window window(info);
//     ProjectA::Renderer renderer = ProjectA::Renderer::Create(window);

//     ImGui_ImplSDL3_InitForSDLRenderer(window.GetSDLWindow(), renderer.GetSDLRenderer());
//     ImGui_ImplSDLRenderer_Init(renderer.GetSDLRenderer());
            
//     renderer.SetClearColor(ProjectA::ColorRGBA(173, 53, 173, 255));
    
//     if(sound)
//     {
//         int channel = Mix_PlayChannel(-1, sound, 0);
//         // while(Mix_Playing(channel) != 0);
//     }

//     while(window.IsOpen())
//     {
//         window.DispatchEvents();

//         renderer.Clear();

//         ImGui_ImplSDLRenderer_NewFrame();
//         ImGui_ImplSDL3_NewFrame();
//         ImGui::NewFrame();
//         ImGui::ShowDemoWindow();

//         ImGui::Render();
//         ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());

//         renderer.Present();
//     }

//     // Imgui
//     ImGui_ImplSDLRenderer_Shutdown();
//     ImGui_ImplSDL3_Shutdown();
//     ImGui::DestroyContext();
//     // SDL_mixer
//     Mix_FreeChunk(sound);
//     Mix_CloseAudio();
//     // SDL
//     SDL_Quit();

//     return (0);
// }

// bool g_KeepOpen = true;

// int main(int argc, char** argv)
// {
//     using namespace ProjectA;

//     int result = 0;

//     ApplicationInfo info;
//     info.Name = "My app";
//     info.Width = 700;
//     info.Height = 320;
//     info.RenderingAPI = RenderAPI::SDL;

//     while(g_KeepOpen)
//     {
//         Owned<Application> application = CreateOwned<Application>(info);
//         result = application->Run();
//     }

//     return result;
// }