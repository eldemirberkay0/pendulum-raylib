file(GLOB SOURCES "*.c")

add_executable(pendulum_raylib ${SOURCES} ../external/cJSON/cJSON.c)

target_include_directories(pendulum_raylib 
    PRIVATE 
    ../include
    ../external/cJSON
)

target_link_libraries(pendulum_raylib PRIVATE raylib raygui m)