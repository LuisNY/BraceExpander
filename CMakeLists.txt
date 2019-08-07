cmake_minimum_required(VERSION 3.11)
project(BraceExpander)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CTEST_COMMAND ctest)
enable_testing()

add_custom_target(check
        COMMAND ${CMAKE_CTEST_COMMAND}
        POST_BUILD
        DEPENDS expander/tests/tests.cpp)

add_library(expander expander/src/Expander.cpp expander/src/Expander.h)
add_executable(brace_expander main/main.cpp)
target_link_libraries(brace_expander expander)

add_subdirectory(expander/tests)

install(PROGRAMS bin/okc DESTINATION bin)