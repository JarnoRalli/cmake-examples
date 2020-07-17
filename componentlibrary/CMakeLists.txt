cmake_minimum_required(VERSION 3.12)

message(STATUS "-----------------")
message(STATUS "COMPONENT LIBRARY")
message(STATUS "-----------------")

project(ComponentLibrary VERSION 1.0 LANGUAGES CXX)

# Organize project into folders. Improves readability in IDEs that support this
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# To distinguish between 'release' and 'debug' builds
set(CMAKE_DEBUG_POSTFIX "_d" CACHE STRING "File prefix for debug builds")

# Global variable for the main project name
set(MAIN_PROJECT_NAME ${CMAKE_PROJECT_NAME} CACHE STRING "Main project name")

# Global variable for the main project version
set(MAIN_PROJECT_VERSION ${CMAKE_PROJECT_VERSION} CACHE STRING "Main project version")

# Global namespace for all of the sub-components
set(LIBRARY_NAMESPACE "${MAIN_PROJECT_NAME}::" CACHE STRING "Namespace for all of the libraries")

# Global variable for storing all the internal libraries. Each add_library that also creates a target,
# adds the name of the library to this list. This is then used internally in the ComponentLibraryConfig.cmake.in.
set(MAIN_LIBRARY_LIST "" CACHE INTERNAL "A list of the libraries in this project" FORCE)

# ------------------------------------------------------------------------
# Generate documentation if Doxygen is found (requires CMake 3.3 to work)
# ------------------------------------------------------------------------
find_package(Doxygen COMPONENTS doxygen dot QUIET)
if( ${DOXYGEN_FOUND} )
    message( STATUS "\tDoxygen + dot found, building documentation" )
    set(DOXYGEN_GENERATE_HTML YES CACHE BOOL "Generate HTML")
    set(DOXYGEN_GENERATE_LATEX YES CACHE BOOL "General Latex")
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/doc" CACHE PATH "Output directory")
    set(DOXYGEN_PROJECT_NAME "Example project" CACHE STRING "Project name")
    doxygen_add_docs(
        doc
        ${PROJECT_SOURCE_DIR}
    )
else( ${DOXYGEN_FOUND} )
    message( STATUS "\tDoxygen + dot NOT found, NOT building documentation" )
endif(  ${DOXYGEN_FOUND}  )

include(cmake/FetchGTest.txt)

add_subdirectory(modules)

add_library(ComponentLibrary INTERFACE)
target_link_libraries(ComponentLibrary INTERFACE "${MAIN_LIBRARY_LIST}")

#---------------------------
# Installation instructions
#---------------------------

# Export the target
install(TARGETS ComponentLibrary
        EXPORT ComponentLibraryTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Export the targets to a script
install(EXPORT ComponentLibraryTargets
        FILE
            ComponentLibraryTargets.cmake
        NAMESPACE
            ComponentLibrary::
        DESTINATION
            ${CMAKE_INSTALL_LIBDIR}/cmake/ComponentLibrary
)

# Create a LibStoryBoardConfigVersion.cmake file
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/ComponentLibraryConfigVersion.cmake
    VERSION ${MAIN_PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

message(STATUS "MAIN_LIBRARY_LIST: ${MAIN_LIBRARY_LIST}")

# Create a configuration file
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ComponentLibraryConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/ComponentLibraryConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ComponentLibrary
    PATH_VARS CMAKE_INSTALL_INCLUDEDIR CMAKE_INSTALL_LIBDIR
)

# Install the version- and configuration files
install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/ComponentLibraryConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/ComponentLibraryConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ComponentLibrary
)

add_library(ComponentLibrary::ComponentLibrary ALIAS ComponentLibrary)