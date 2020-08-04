# CMake Example
CMake examples

# Modern CMake Build System Examples
This repository contains two modern CMake examples: a library called `LibStoryBoard` and a library called `ComponentLibrary` that has several components.
Both of the examples use the so called modern CMake approach for exporting and installing the targets, so that these are relocatable. What this means
is that the installed library can be copied to another location, and we can discover the library using `find_package` and link against it. When the
library is exported and installed using this approach (i.e. the library exports CMake configuration files along with the actual binaries). `find_package`
has two modes of operation. These are the `CONFIG`- and the `MODULE` mode. In the case of the `MODULE` mode, CMake looks for a file called `Find<PackageName>.cmake`.
This file contains the logic for finding where the binaries and header files are, and populating the corresponding variables in CMake. Some of these files are supplied with the CMake itself.
In the `CONFIG` mode CMake looks for a file called `<PackageName>Config.cmake`. A cache entry called `<PackageName>_DIR` is created to hold the directory containing the configuration file.

# Libraries


## LibStoryBoard
Implements a single library called `LibStoryBoard`.

## ComponentLibrary
Implements two different libraries: `StoryBoard` and `Other`. These are implemented so that `find_package` COMPONENTS
can be used for linking against either, or both. For example:

```
find_package(ComponentLibrary 1.0 REQUIRED COMPONENTS StoryBoard)
target_link_libraries (executable_componentlibrary ComponentLibrary::StoryBoard)
```

## Installation
Set the `CMAKE_INSTALL_PREFIX` to the location where you want to install the library. After having executed CMake, simply run
`make all` and `make install` in the build folder. The configuration file(s) will be installed to `CMAKE_INSTALL_PREFIX/lib/cmake/<PackageName>` directory.

## Doxygen Based Documentation
Documentation is based on Doxygen and dot. In order to generate the documentation, these need to be installed:

* `sudo apt-get install doxygen graphviz`
* To build the documentation, run `make doc` in the build-folder.

## Unit Tests
Simple unit tests have been implemented using CTest and Google Test. To execute the unit tests, run `make test` in the build-folder.

# Test Executables

## Executable LibstoryBoard
This is a simple executable that links against the `LibStoryBoard`. You must first build and install the `LibStoryBoard`. After that, when
you run CMake for this project (i.e. for the Executable project), you will get an error complaining that `LibStoryBoard` configuration file is not found.
If you're running CMake with GUI, simply point the variable `LibStoryBoard_DIR` to the directory where you installed the LibStoryBoard, 
e.g. `<CMAKE_INSTALL_PREFIX>/lib/cmake/LibStoryBoard`, or you can call cmake with the following parameters:

```
cmake -DLibStoryBoard_DIR=<CMAKE_INSTALL_PREFIX>/lib/cmake/LibStoryBoard -B <PATH_TO_BUILD_DIRECORY>
```

If you take a look at the CMakeLists.txt for the executable, you will find that we have not set the include-directory and still the build system finds the
header file for the LibStoryBoard (storyboard.hpp). This is due to the fact that this information is encoded in the target. The only thing we have configured
for the executable is the following:
```
add_executable (executable ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries (executable LibStoryBoard::LibStoryBoard)
```

## Executable ComponentLibrary
This is a simple executable that links against the `ComponentLibrary`. You must first build and install the `ComponentLibrary`, and follow the same instructions
as for the `Executable LibStoryBoard`.

