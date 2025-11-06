cmake_minimum_required(VERSION 3.10)
project(pendulum_raylib C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
)
FetchContent_MakeAvailable(raylib)

add_subdirectory(src)