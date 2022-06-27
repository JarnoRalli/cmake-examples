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

The library needs to be built and installed before it can be used in another project. Following builds- and
installs the library.

```bash
cd componentlibrary
mkdir build
cd build
mkdir install
cmake .. -DCMAKE_INSTALL_PREFIX=./install
make -j4
make test
```
