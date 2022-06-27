# Executable Using ComponentLibrary

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
