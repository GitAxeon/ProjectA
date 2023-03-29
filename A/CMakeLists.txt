cmake_minimum_required(VERSION 3.24)
project(A)

set(CMAKE_CXX_STANDARD 20)

file(GLOB source-files
    "src/*.cpp" 
    "src/*.hpp" 
    "src/*.h"
)

file(GLOB imgui-source
    "../Vendor/ImGui/*.cpp"
    "../Vendor/ImGui/*.h"
    "../Vendor/ImGui/backends/imgui_impl_sdl3.h"
    "../Vendor/ImGui/backends/imgui_impl_sdl3.cpp"
    "../Vendor/ImGui/backends/imgui_impl_sdlrenderer.h"
    "../Vendor/ImGui/backends/imgui_impl_sdlrenderer.cpp"
)

add_library(A STATIC ${source-files} ${imgui-source})
# add_executable(A ${source-files} ${imgui-source})

add_compile_definitions(
    SDL_ENABLE_OLD_NAMES
)
    
target_include_directories(
    A PUBLIC
    ../Vendor/SDL/include/
    ../Vendor/SDL_mixer/include/
    ../Vendor/ImGui/
    ../Vendor/ImGui/backends/
    ../Vendor/glm/
    ../Vendor/box2d/include/
    ../Vendor/stb/
)

target_link_libraries(
    A PRIVATE
    SDL3-static
    SDL3_mixer
    box2d
)