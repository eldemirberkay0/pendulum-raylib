cmake_minimum_required(VERSION 3.10)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
project(pendulum_raylib C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)

find_package(raylib CONFIG QUIET)
if(NOT raylib_FOUND)
    message("Downloading raylib from git... (This part may take ~1-2 minutes depending on internet speed)")
    include(FetchContent)
    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.zip
    )
    FetchContent_MakeAvailable(raylib) 
endif()

add_subdirectory(src)