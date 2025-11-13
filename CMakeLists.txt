cmake_minimum_required(VERSION 3.10)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
project(pendulum_raylib C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

find_package(raylib CONFIG QUIET)
if(NOT raylib_FOUND)
    message("Downloading raylib from git... (This part may take up to ~1-2 minutes depending on internet speed)")
    include(FetchContent)
    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.zip
    )
    FetchContent_MakeAvailable(raylib) 
endif()

if(NOT raygui_FOUND)
    message("Downloading raygui from git... (This part may few seconds depending on internet speed)")
    include(FetchContent)
    FetchContent_Declare(
        raygui
        URL https://github.com/raysan5/raygui/archive/refs/tags/4.0.zip
    )
    FetchContent_MakeAvailable(raygui) 
endif()

add_library(raygui INTERFACE)

target_include_directories(raygui INTERFACE 
    ${raygui_SOURCE_DIR}/src
)

add_subdirectory(src)