# CMake Example
CMake examples

## Modern CMake Build System Example
Build requirements are propagated inside the targets (e.g. libraries). For example, C++14 build-flag is defined in the LibStoryBoard target,
and anyone other library or executable linking against this target deduces the correct build flags. Same applies for include folders etc.
Targets are exported and installed using relative paths so that the install directory can be relocated.

## LibStoryBoard
This is a simple library that implements a storyboard. The idea of this library is to test exporting and installing using the modern CMake
approach. The installed library should be relocatable (i.e. the installed library should be copiable to other locations and still work
when linked against).

## ComponentLibrary
This is a library that implements two different libraries: `StoryBoard` and `Other`. These are implemented so that `find_package` COMPONENTS
can be used for linking against either, or both. For example:

```
find_package(ComponentLibrary 1.0 REQUIRED COMPONENTS StoryBoard)
target_link_libraries (executable_componentlibrary ComponentLibrary::StoryBoard)
```

### Installation
Set the CMAKE_INSTALL_PREFIX to the location where you want to install the library. After having executed CMake, simply run
`make all` and `make install` in the build folder.

### Doxygen Based Documentation
Documentation is based on Doxygen and dot. In order to generate the documentation, these need to be installed:
* sudo apt-get install doxygen graphviz
* To build the documentation, run `make doc` in the build-folder.

### Unit Tests
Simple unit tests have been implemented using CTest and Google Test. To execute the unit tests, run `make test` in the build-folder.

## Executable LibstoryBoard
This is a simple executable that links against the LibStoryBoard. You must first build and install the LibStoryBoard. After that, when
you run CMake for this project (i.e. for the Executable project), you will get an error complaining that "LibStoryBoard" configuration file is not found.
If you're running CMake with GUI, simply point the variable `LibStoryBoard_DIR` to the directory where you installed the LibStoryBoard, 
e.g. <CMAKE_INSTALL_PREFIX>/lib/cmake/LibStoryBoard, or you can call cmake with the following parameters:

```
cmake -DLibStoryBoard_DIR=<CMAKE_INSTALL_PREFIX>/lib/cmake/LibStoryBoard -B <PATH_TO_BUILD_DIRECORY>
```

If you take a look at the CMakeLists.txt for the executable, you will find that we have not set include-directory and still the build system finds the
header file for the LibStoryBoard (storyboard.hpp). This is due to the fact that this information is encoded in the target. The only thing we have configured
for the executable is the following:
```
add_executable (executable ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries (executable LibStoryBoard::LibStoryBoard)
```

## Executable ComponentLibrary
This is a simple executable that links against the ComponentLibrary. You must first build and install the ComponentLibrary, and follow the same instructions
as for the `Executable LibStoryBoard`.

