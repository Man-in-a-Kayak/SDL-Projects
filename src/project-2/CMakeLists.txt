add_executable(project-2)

set_property(TARGET project-2 PROPERTY CXX_STANDARD 20)
set_property(TARGET project-2 PROPERTY CXX_STANDARD_REQUIRED true)

target_compile_options(project-2
    PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)   

target_sources(project-2
    PRIVATE
        main.cpp
)

target_link_libraries(project-2
    PRIVATE
        SDL3::SDL3
)
