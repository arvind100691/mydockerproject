add_library(observer-pattern INTERFACE)

target_include_directories(observer-pattern INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Add the library to the project
set_property(TARGET observer-pattern PROPERTY CXX_STANDARD 11)
