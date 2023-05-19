project(ping_pong)

set(MAIN_PARSER_SRC_FILES
        src/main.cpp
)

add_executable(ping_pong ${MAIN_PARSER_SRC_FILES})
set_target_properties(ping_pong PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
