#-----------------------------------------------------
# Simple build system using the modern CMake approach
#-----------------------------------------------------

# Minimum CMake version so that we can use the modern approach is 3.0
cmake_minimum_required (VERSION 3.3)

message(STATUS "---------------------------")
message(STATUS "EXECUTABLE COMPONENTLIBRARY")
message(STATUS "---------------------------")

# Project name, expected programming language is C++
project(Executable_ComponentLibrary VERSION 1.0 LANGUAGES CXX)

# Find the package ComponentLibrary, and make sure that components StoryBoard
# and Other are available
find_package(ComponentLibrary 1.0 REQUIRED COMPONENTS StoryBoard Other CONFIG)

# Create an executable
add_executable(executable_componentlibrary ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# Link against the StoryBoard- and Other components
target_link_libraries(executable_componentlibrary
    ComponentLibrary::StoryBoard
    ComponentLibrary::Other)

