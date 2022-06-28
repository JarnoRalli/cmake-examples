# Executable Using the LibStoryBoard

This executable shows how to link against the library `LibStoryBoard`. You first need to build
and install the library as per these [instructions](../libstoryboard/README.md). After that
run the following commands:

```bash
cd executable_libstoryboard
mkdir build
cd build
cmake .. -DLibStoryBoard_DIR=$(pwd)/../../libstoryboard/build/install/lib/cmake/LibStoryBoard
make -j4
./executable_libstoryboard
```

`LibStoryBoard_DIR` points to the directory where  the installed version of the file
`LibStoryBoardConfig.cmake` can be found. That file contains all the information required
by CMake to link against that library.

## Linking Against the LibStoryBoard Package

Linking against the `LibStoryBoard` is done as follows:

```cmake
# Find the package LibStoryBoard
find_package(LibStoryBoard 1.0 REQUIRED CONFIG)

# Create an executable
add_executable(executable_libstoryboard ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# Link against the LibStoryBoard
target_link_libraries(executable_libstoryboard LibStoryBoard::LibStoryBoard)
```
