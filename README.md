# CMake Examples

This repository contains two modern CMake examples: 

* A library called [LibStoryBoard](./libstoryboard/README.md) + [test executable](./executable_libstoryboard/README.md).
  * This library contains a single target (library) that can be linked against.
* A library called [ComponentLibrary](./componentlibrary/README.md) + [test executable](./executable_componentlibrary/README.md).
  * This library contains two targets (libraries) that can be linked against.

Both of the examples export and install the targets in such a way, that these are relocatable. What this means that the directory
where the library was installed can be copied, or moved, to another location, and still be used in other projects. Depending
on how the CMake-based build system was made, you can typically use the build-directory for linking in other projects, but
due to the fact that in the build directory absolute paths are used, moving the build directory to another location would
break the package. Also, when installing a package, only those files that are required, like headers, binaries and configuration files, are
copied to the installation location.

## Modern CMake

Modern CMake, when compared to the traditional CMake approach, is like comparing C++ to C. In modern CMake packages can be thought of
being self-contained objects that have all the information that is required to link against those. The traditional approach required
passing of global variables, in the cache memory, between different CMake-files. Not only was this messy, but maintaining the build scripts was time consuming.
In the traditional approach you would call `include_directories`, with the appropriate directory as a parameter, so that the header files
of a library being linked would be discovered. None of this is needed anymore, meaning that the CMake build scripts are much shorter and
easier to read and maintain.

## Package Discovery

Once a package has been installed, before it can be used in the host project, it must be discovered using [find_package](https://cmake.org/cmake/help/latest/command/find_package.html).
`find_package` has two discovery modes called `CONFIG` and `MODULE` modes. In `MODULE` mode CMake looks for a file called `Find<PackageName>.cmake`.
This file tells CMake where the different files, like headers and binaries, can be found. It can also pass linking switches and other parameters to the host project.
When you install CMake, it also installs a bunch of `Find<PackageName>.cmake` files that can be used for discovering different libraries like GTest etc. 
`MODULE` mode works also with non-CMake based projects, i.e. if the build-system of the library is not based on CMake. In the `CONFIG` mode
CMake looks for a file called `<PackageName>Config.cmake` that contains all the detailes required to use the package in a host project.
A cache entry called `<PackageName>_DIR` is created to hold the path to the directory containing this configuration file. A config file
is generated when a CMake-based project is installed, and thus is a central part of the modern CMake approach. The catch here is that some
work is required from the maintainer of the package in order for the installation process to work smoothly.

Following command demonstrates how to discover a package called `ComponentLibrary`, and verify that it has a component called `StoryBoard`:

```cmake
find_package(ComponentLibrary 1.0 REQUIRED COMPONENTS StoryBoard CONFIG)
```

Required components are listed after `COMPONENTS`. 

## Linking Against a Package

Once a package has been discovered, it can be used for linking in the host project using [target_link_libraries](https://cmake.org/cmake/help/latest/command/target_link_libraries.html).
It is important to note that modern CMake packages are self-contained. What this means is that they contain all the information required for the host target
to link against that library, including locations of the headers files, build- and link switches etc. There is no need to add an `include_directories` command
in order for the header files to be discovered.

After the package has been discovered, it can be linked against using:

```cmake
target_link_libraries(executable_componentlibrary ComponentLibrary::StoryBoard)
```

# How to Build and Test the LibStoryBoard

In order to build- and test linking against the `LibStoryBoard`, you need to do the following:

* Build and install the `LibStoryBoard` library as per these [instructions](./libstoryboard/README.md)
* Build the `executable_libstoryboard` as per these [instructions](./executable_libstoryboard/README.md)

# How to Build and Test the ComponentLibrary

In order to build- and test linking against the `LibStoryBoard`, you need to do the following:

* Build and install the `ComponentLibrary` library as per these [instructions](./componentlibrary/README.md)
* Build the `executable_componentlibrary` as per these [instructions](./executable_componentlibrary/README.md)

