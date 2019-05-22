# CMake Example
CMake examples

## Modern CMake Build System Example
Build requirements, such as C++-version, are propagated from the targets (e.g. libraries). For example, 
C++14 build-flag is defined in the library.

## Doxygen Based Documentation
Documentation is based on Doxygen and dot. In order to generate the documentation, these need to be installed:
* sudo apt-get install doxygen dot
To build the documentation, run 'make doc' in the build-folder.

## Unit Tests
Simple unit tests have been implemented using CTest. To execute the unit tests, run 'make test' in the build-folder.

