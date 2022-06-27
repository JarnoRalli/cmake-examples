# CMake Examples

This repository contains two modern CMake examples: 

* A library called [LibStoryBoard](./libstoryboard/README.md) + [test executable](./executable_libstoryboard/README.md)
* A library called [ComponentLibrary](./componentlibrary/README.md) + [test executable](./executable_componentlibrary/README.md)

Both of the examples export and install the targets in such a way, that these are relocatable. What this means is that the installed
directories can be copied, or moved to another place, and the libraries can still be linked against. Here installation means that only
those files, like the headers and built binaries, are copied to the target location, without copying any of the intermediate files. Once the
libraries have been installed, they can be discovered in the host project using using [find_package](https://cmake.org/cmake/help/latest/command/find_package.html).
`find_package` has two modes of operation for seaching packages. These are the `CONFIG`- and the `MODULE` modes. In the case of the `MODULE` mode, 
CMake looks for a file called `Find<PackageName>.cmake`. This file contains the logic for finding where the binaries and header files are, 
and populating the corresponding variables in CMake. The `MODULE` code works with non-CMake based projects. Some of these files are supplied with the CMake itself. 
In the `CONFIG` mode CMake looks for a file called `<PackageName>Config.cmake`. A cache entry called `<PackageName>_DIR` is created to hold the directory 
containing the configuration file. When we install a library that used the modern CMake approach, the `<PackageName>Config.cmake` is generated
during installation.

Following code snippet demonstrates how to discover a package called `ComponentLibrary`, and verify that it has a component called `StoryBoard`:

```
find_package(ComponentLibrary 1.0 REQUIRED COMPONENTS StoryBoard CONFIG)
```

After this, we can link against that library using:

```
target_link_libraries(executable_componentlibrary ComponentLibrary::StoryBoard)
```

# How to Build and Test the LibStoryBoard

In order to build- and test linking the `LibStoryBoard`, you need to do the following:

* Build and install the `LibStoryBoard` library as per these [instructions](./libstoryboard/README.md)
* Build the `executable_libstoryboard` as per these [instructions](./executable_libstoryboard/README.md)

# How to Build and Test the ComponentLibrary

In order to build- and test linking the `LibStoryBoard`, you need to do the following:

* Build and install the `ComponentLibrary` library as per these [instructions](./componentlibrary/README.md)
* Build the `executable_componentlibrary` as per these [instructions](./executable_componentlibrary/README.md)

