# LibStoryBoard

`LibStoryBoard` implements a simple `Storyboard` class that can be used for adding, deleting and querying
of notes posted in the `Storyboard`. The library exposes one target, called `LibStoryBoard::LibStoryBoard`,
that can be linked against in another project in order to get access to the `Storyboard` functionality.

# 3rd Party Libraries

`LibStoryBoard` uses `GTest` for implementing simple unit tests. The example uses [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html)
to download `GTest`'s source code, and to expose the targets `GTest::gtest_main`, `GTest::gmock_main`, `GTest::gtest` and `GTest::gmock` for linking. `GTest`
will be built when building rest of the `LibStoryBoard`.

# Building and Installing

The library needs to be built and installed before it can be used in another project. Following builds- and
installs the library, and executes the tests.

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
|  |-gmock
|  |-gtest
|  |-storyboard
|
|- lib
   |
   |-cmake
   | |
   | |-GTest
   | |-LibStoryBoard
   |
   |-pkgconfig
```

`include` directory is self-explanatory, header files for both `GTest` and `LibStoryBoard` are located there. Inside the `lib`
directory you can find the actual libraries and a directory called `cmake`. Inside the `cmake` directory are the exported
CMake files that allows you to link against both `GTest` and `LibStoryBoard` from other projects.
