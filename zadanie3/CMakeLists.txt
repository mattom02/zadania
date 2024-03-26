cmake_minimum_required(VERSION 3.24)
project(zadanie3)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        src/collision.cpp
        src/triangle.cpp
        )

set(SOURCE_FILES_TESTS
        test/test.cpp
        )

include_directories(
        include
        ${gtest_SOURCE_DIR}/include
)

include(FetchContent)

FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)

FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG        v1.14.0
)

FetchContent_MakeAvailable(SFML)
FetchContent_MakeAvailable(googletest)

add_executable(zadanie3 ${SOURCE_FILES} main.cpp)
add_executable(zadanie3_test src/collision.cpp ${SOURCE_FILES_TESTS})

target_link_libraries(zadanie3 PRIVATE sfml-graphics)
target_link_libraries(zadanie3_test gtest gtest_main)
target_compile_features(zadanie3 PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET zadanie3
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:zadanie3>
            VERBATIM)
endif()

install(TARGETS zadanie3)
