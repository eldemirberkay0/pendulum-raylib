file(GLOB SOURCES "*.c")

add_executable(pendulum_raylib ${SOURCES} ../external/cJSON/cJSON.c)

target_include_directories(pendulum_raylib 
    PRIVATE 
    ../include
    ../external/cJSON
)

target_link_libraries(pendulum_raylib PRIVATE raylib raygui m nfd)

if (UNIX AND NOT APPLE)
    find_package(PkgConfig REQUIRED)

    pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
    target_include_directories(pendulum_raylib PRIVATE ${GTK3_INCLUDE_DIRS})
    target_link_libraries(pendulum_raylib PRIVATE ${GTK3_LIBRARIES})

    pkg_check_modules(RAYLIB_LINUX_DEPS REQUIRED x11 xrandr xcursor xi xinerama 
        ${CMAKE_DL_LIBS} # libdl
    )

    target_link_libraries(pendulum_raylib 
        ${RAYLIB_LINUX_DEPS_LIBRARIES}
    )
endif()

if (APPLE)
    target_link_libraries(${PROJECT_NAME} 
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreFoundation"
    )
endif()