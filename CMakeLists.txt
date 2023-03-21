cmake_minimum_required(VERSION 3.24)
project(ProjectA)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin-int)

set(SDL_STATIC ON CACHE BOOL "Build SDL as static library" FORCE)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)

add_subdirectory(Vendor/SDL)
add_subdirectory(Vendor/box2d)

add_subdirectory(A)