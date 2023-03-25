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

add_executable(A ${source-files} ${imgui-source})

add_compile_definitions(
    SDL_ENABLE_OLD_NAMES
)
    
target_include_directories(
    A PRIVATE
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

set(RESOURCE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/resource)

add_custom_command(
        TARGET A POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${RESOURCE_FOLDER}"
        "$<TARGET_FILE_DIR:A>/resource"
        COMMENT "Copying resources"
)