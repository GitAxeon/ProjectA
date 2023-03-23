cmake_minimum_required(VERSION 3.24)
project(ProjectA)

set(CMAKE_CXX_STANDARD 20)
include(CMakePrintHelpers)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin-int)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin-int)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

add_subdirectory(Vendor/SDL)

message("------------------------------------")

add_subdirectory(Vendor/SDL_mixer)

message("------------------------------------")

add_subdirectory(Vendor/box2d)

add_subdirectory(A)