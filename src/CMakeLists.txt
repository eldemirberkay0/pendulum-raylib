file(GLOB SOURCES "*.c")

add_executable(pendulum_raylib ${SOURCES})

target_link_libraries(pendulum_raylib PRIVATE raylib)