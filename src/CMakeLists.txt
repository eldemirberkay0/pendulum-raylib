file(GLOB SOURCES "*.c")

add_executable(pendulum_raylib ${SOURCES} ../external/cJSON/cJSON.c)

target_include_directories(pendulum_raylib 
    PRIVATE 
    ../include
    ../external/cJSON

)

if(UNIX)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
    target_include_directories(pendulum_raylib PRIVATE ${GTK3_INCLUDE_DIRS})
    target_link_libraries(pendulum_raylib PRIVATE ${GTK3_LIBRARIES})
endif()

target_link_libraries(pendulum_raylib PRIVATE raylib raygui m nfd)
