cmake_minimum_required(VERSION 3.14)
project(mydockerproject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add lib subdirectory for libraries
add_subdirectory(lib)

add_executable(myapp main.cpp)

# Link observer-pattern library to myapp
target_link_libraries(myapp observer-pattern)

# Use FetchContent to download and make GoogleTest available
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# Recommended for Windows; harmless on other platforms
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Add tests directory
add_subdirectory(tests)
