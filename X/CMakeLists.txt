cmake_minimum_required(VERSION 3.24)
project(X)

set(CMAKE_CXX_STANDARD 20)

message("bruh")

file(GLOB source-files
    "src/*.cpp" 
    "src/*.hpp" 
    "src/*.h"
)

add_executable(X ${source-files})

target_include_directories(
    X PUBLIC
    "../A/src/"
)

target_link_libraries(
    X PRIVATE
    A
)

set(RESOURCE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/resource)

add_custom_command(
        TARGET X POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${RESOURCE_FOLDER}"
        "$<TARGET_FILE_DIR:A>/resource"
        COMMENT "Copying resources"
)