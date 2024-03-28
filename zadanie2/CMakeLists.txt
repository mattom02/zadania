cmake_minimum_required(VERSION 3.24)
project(zadanie2)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        include
        ${gtest_SOURCE_DIR}/include
)

set(SOURCE_FILES
        src/Page.cpp
        src/WelcomePage.cpp
        src/TicketsPage.cpp
        src/TextPage.cpp
        src/Functions.cpp
        )

set(SOURCE_FILES_TESTS
        test/test.cpp
        )

include(FetchContent)

FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)

FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG        v1.14.0)

add_executable(zadanie2 ${SOURCE_FILES} main.cpp)
add_executable(zadanie2_test src/Functions.cpp ${SOURCE_FILES_TESTS})

FetchContent_MakeAvailable(SFML googletest)

if(WIN32)
    add_custom_command(
            TARGET zadanie2
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:zadanie2>
            VERBATIM)
endif()

add_custom_command(
        TARGET zadanie2
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/font.ttf $<TARGET_FILE_DIR:zadanie2>
)

target_link_libraries(zadanie2 PRIVATE sfml-graphics)
target_link_libraries(zadanie2_test gtest gtest_main sfml-graphics)
target_compile_features(zadanie2 PRIVATE cxx_std_17)

install(TARGETS zadanie2)