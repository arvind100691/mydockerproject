cmake_minimum_required(VERSION 3.14)

add_executable(sample_test sample_test.cpp)
target_link_libraries(sample_test PRIVATE gtest_main)

add_executable(mock_test mock_test.cpp)
target_link_libraries(mock_test PRIVATE gtest_main gmock observer-pattern)

include(GoogleTest)
gtest_discover_tests(sample_test)
gtest_discover_tests(mock_test)
