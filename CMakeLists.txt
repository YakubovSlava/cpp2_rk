cmake_minimum_required(VERSION 3.20)

project("Homework1_project")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_compile_options(-Wall -Wpedantic -Werror )
#add_subdirectory(${CMAKE_BINARY_DIR}/googletest)


# include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(projects/ping_pong)
