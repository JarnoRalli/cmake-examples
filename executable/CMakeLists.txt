#-----------------------------------------------------
# Simple build system using the modern CMake approach
#-----------------------------------------------------

# Minimum CMake version so that we can use the modern approach is 3.0
cmake_minimum_required (VERSION 3.3)

message(STATUS "----------")
message(STATUS "EXECUTABLE")
message(STATUS "----------")

# Project name, expected programming language is C++
project (Executable VERSION 1.0 LANGUAGES CXX)

# Find the package LibStoryBoard
find_package(LibStoryBoard 1.0 REQUIRED)

add_executable (executable ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_link_libraries (executable LibStoryBoard::LibStoryBoard)

