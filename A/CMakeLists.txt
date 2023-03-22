cmake_minimum_required(VERSION 3.24)
project(A)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin-int)


file(GLOB source-files
    "${A_SOURCE_DIR}/src/*.cpp" 
    "${A_SOURCE_DIR}/src/*.hpp" 
    "${A_SOURCE_DIR}/src/*.h" 
)
    
include_directories(A PRIVATE ${CMAKE_BINARY_DIR}/../Vendor/SDL/include)
include_directories(A PRIVATE ${CMAKE_BINARY_DIR}/../Vendor/SDL_mixer/include)
include_directories(A PRIVATE ${CMAKE_BINARY_DIR}/../Vendor/ImGui/)
include_directories(A PRIVATE ${CMAKE_BINARY_DIR}/../Vendor/glm/)
include_directories(A PRIVATE ${CMAKE_BINARY_DIR}/../Vendor/box2d/include/)

add_executable(A ${source-files})

target_link_libraries(A PRIVATE SDL3-static)
target_link_libraries(A PRIVATE SDL3_mixer)
target_link_libraries(A PRIVATE box2d)

set(RESOURCE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/resource)

add_custom_command(
        TARGET A POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${RESOURCE_FOLDER}"
        "$<TARGET_FILE_DIR:A>/resource"
        COMMENT "Copying resources"
)