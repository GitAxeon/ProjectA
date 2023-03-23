cmake_minimum_required(VERSION 3.24)
project(ProjectA)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin-int)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin-int)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(BOX2D_BUILD_UNIT_TESTS OFF)
set(BOX2D_BUILD_TESTBED OFF)

add_subdirectory(Vendor/SDL)
add_subdirectory(Vendor/SDL_mixer)
add_subdirectory(Vendor/box2d)

add_subdirectory(A)