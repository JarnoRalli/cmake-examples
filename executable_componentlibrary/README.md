# Executable Using the ComponentLibrary

This executable shows how to link against the library `ComponentLibrary`. You first need to build
and install the library as per these [instructions](../componentlibrary/README.md). After that
run the following commands:

```bash
cd executable_componentlibrary
mkdir build
cd build
cmake .. -DComponentLibrary_DIR=$(pwd)/../../componentlibrary/build/install/lib/cmake/ComponentLibrary
make -j4
./executable_componentlibrary
```

`Componentlibrary_DIR` points to the directory where  the installed version of the file
`ComponentLibraryConfig.cmake` can be found. That file contains all the information required
by CMake to link against that library.

## Linking Against the ComponentLibrary Package

Linking against the `ComponentLibrary` is done as follows:

```cmake
# Find the package ComponentLibrary, and make sure that components StoryBoard
# and Other are available
find_package(ComponentLibrary 1.0 REQUIRED COMPONENTS StoryBoard Other CONFIG)

# Create an executable
add_executable(executable_componentlibrary ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# Link against the StoryBoard- and Other components
target_link_libraries(executable_componentlibrary
    ComponentLibrary::StoryBoard
    ComponentLibrary::Other)
```
