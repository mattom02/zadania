cmake_minimum_required(VERSION 3.24)
project(zadanie1)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        include
        ${gtest_SOURCE_DIR}/include
)

set(SOURCE_FILES_TESTS
        test/test.cpp
        )

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG        v1.14.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(zadanie1 main.cpp)

add_executable(zadanie1_test ${SOURCE_FILES_TESTS})

target_link_libraries(zadanie1_test gtest gtest_main)