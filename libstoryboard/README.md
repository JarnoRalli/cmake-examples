# LibStoryBoard

`LibStoryBoard` implements a simple `Storyboard` class that can be used for adding, deleting and querying
of notes posted in the `Storyboard`. The library exposes one target, called `LibStoryBoard::LibStoryBoard`,
that can be linked against in another project in order to get access to the `Storyboard` functionality.

# Building and Installing

The library needs to be built and installed before it can be used in another project. Following commands build- and
install the library, and execute the tests.

```bash
cd libstorybuild
mkdir build
cd build
mkdir install
cmake .. -DCMAKE_INSTALL_PREFIX=./install
make -j4
make install
make test
```

# Install

In the above script we installed the library. If you take a look at the directory `build/install`, you will find the
following directories there:

```
|- include
|  |
|  |-storyboard
|
|- lib
   |
   |-cmake
     |
     |-LibStoryBoard
```

`include` directory is self-explanatory, header files for the `LibStoryBoard` are located there. Inside the `lib`
directory you can find the actual libraries and a directory called `cmake`. Inside the `cmake` directory are the exported
CMake files that allows you to link against `LibStoryBoard` from other projects.
