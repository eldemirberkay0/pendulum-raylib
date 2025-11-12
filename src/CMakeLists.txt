file(GLOB SOURCES "*.c")

add_executable(pendulum_raylib ${SOURCES})

target_include_directories(pendulum_raylib 
    PRIVATE 
    ../include
)

target_link_libraries(pendulum_raylib PRIVATE raylib raygui m)