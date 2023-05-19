project(pingpong)

set(MAIN_PARSER_SRC_FILES
        src/main.cpp
)

add_executable(pingpong ${MAIN_PARSER_SRC_FILES})
set_target_properties(pingpong PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
