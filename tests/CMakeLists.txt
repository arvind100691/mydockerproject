cmake_minimum_required(VERSION 3.14)

add_executable(sample_test sample_test.cpp)
target_link_libraries(sample_test PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(sample_test)
