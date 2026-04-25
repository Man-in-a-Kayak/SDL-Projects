cmake_minimum_required(VERSION 4.2.3)

project(sdl_projects)

include(FetchContent)
FetchContent_Declare(sdl_3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.4.4
    GIT_SHALLOW TRUE
    EXCLUDE_FROM_ALL
    SYSTEM
    OVERRIDE_FIND_PACKAGE
)
FetchContent_MakeAvailable(sdl_3)

add_subdirectory(src/project-1)
add_subdirectory(src/project-2)


