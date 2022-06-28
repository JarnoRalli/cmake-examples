# ComponentLibrary

`ComponentLibrary` implements a library that contains two different components/targets:

* `ComponentLibrary::StoryBoard`
* `ComponentLibrary::Other`

The Library also exposes a third target, that can be used for linking against both of the above
libraries simultaneously:

* `ComponentLibrary::ComponentLibrary`

`ComponentLibrary::ComponentLibrary` is an [INTERFACE](https://cmake.org/cmake/help/latest/command/add_library.html#interface-libraries) library that 
doesn't compile anything on its own, it only acts as an interface for other libraries.

# Building and Installing

The library needs to be built and installed before it can be used in another project. Following commands build- and install the library, and execute the tests.

```bash
cd componentlibrary
mkdir build
cd build
mkdir install
cmake .. -DCMAKE_INSTALL_PREFIX=./install
make -j4
make install
make test
```

# Install

In the above script we installed the library. If you take a look at the directory `build/install` in Linux, you will find the
following directories and files there:

```
|- include
|  |
|  |-other
|  | |
|  | |-other.hpp
|  | 
|  |-storyboard
|    |
|    |-storyboard.hpp
|   
|- lib
   |
   |-libOther.a
   |-libStoryBoard.a
   |
   |-cmake
     |
     |-ComponentLibrary
       |
       |-ComponentLibraryConfig.cmake
       |-ComponentLibraryConfigVersion.cmake
       |-ComponentLibraryOtherTargets.cmake
       |-ComponentLibraryOtherTargets-noconfig.cmake
       |-ComponentLibraryStoryBoardTargets.cmake
       |-ComponentLibraryStoryBoardTargets-noconfig.cmake
       |-ComponentLibraryTargets.cmake
```

`include` directory is self-explanatory, header files for `StoryBoard` and `Other` are located there. Inside the `lib`
directory you can find the actual libraries and a directory called `cmake`. Inside the `cmake` directory are the exported
CMake files that allows you to link against `ComponentLibrary` from other projects.
