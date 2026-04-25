add_executable(project-1)

set_property(TARGET project-1 PROPERTY CXX_STANDARD 20)
set_property(TARGET project-1 PROPERTY CXX_STANDARD_REQUIRED true)

target_compile_options(project-1 
    PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

target_sources(project-1
    PRIVATE
        main.cpp
)

target_link_libraries(project-1
    PRIVATE
        SDL3::SDL3
)
