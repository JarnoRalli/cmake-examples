#-----------------------------------------------------
# Simple build system using the modern CMake approach
#-----------------------------------------------------

# Minimum CMake version so that we can use the modern approach is 3.0
cmake_minimum_required (VERSION 3.3)

message(STATUS "------------------------")
message(STATUS "EXECUTABLE LIBSTORYBOARD")
message(STATUS "------------------------")

# Project name, expected programming language is C++
project(Executable_LibStoryBoard VERSION 1.0 LANGUAGES CXX)

# Find the package LibStoryBoard
find_package(LibStoryBoard 1.0 REQUIRED CONFIG)

# Create an executable
add_executable(executable_libstoryboard ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# Link against the LibStoryBoard
target_link_libraries(executable_libstoryboard LibStoryBoard::LibStoryBoard)

