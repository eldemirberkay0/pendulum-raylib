file(GLOB SOURCES "*.c")

add_executable(pendulum_raylib ${SOURCES} ../external/cJSON/cJSON.c ../external/file_util/file_util.c)

target_include_directories(pendulum_raylib 
    PRIVATE 
    ../include
    ../external/cJSON
    ../external/file_util
)

target_link_libraries(pendulum_raylib PRIVATE raylib raygui m nfd)