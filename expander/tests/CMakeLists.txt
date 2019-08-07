set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(brace_expander_test tests.cpp)
target_link_libraries(brace_expander_test expander)
add_test(NAME brace_expander_test COMMAND brace_expander_test)
