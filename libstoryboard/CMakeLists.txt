cmake_minimum_required(VERSION 3.12)

message(STATUS "--------------")
message(STATUS "LIBSTORYBOARD")
message(STATUS "--------------")

project(LibStoryBoard VERSION 1.0 LANGUAGES CXX)

# Organize project into folders. Improves readability in IDEs that support this
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# To distinguish between 'release' and 'debug' builds
set(CMAKE_DEBUG_POSTFIX "_d" CACHE STRING "File prefix for debug builds")

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

# -----------------------------------
# Generate the library (i.e. target)
# -----------------------------------
list(   APPEND 
        src_files   
        src/storyboard.cpp
)

list(   APPEND 
        header_files
        include/storyboard/storyboard.hpp
)

add_library (LibStoryBoard)

# Add directories to the target
# PRIVATE and PUBLIC items will populate the INCLUDE_DIRECTORIES property of target
# PUBLIC and INTERFACE items will populate the INTERFACE_INCLUDE_DIRECTORIES property of target
target_include_directories (LibStoryBoard
    PUBLIC 
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Add sources to the library
# Header files are added only so that they appear in IDEs such as Visual Studio etc
# For INTERFACE libraries (header only) this is the only way to make the header
# files appear in the project in IDEs such as Visual Studio
target_sources (LibStoryBoard
    PRIVATE
        ${src_files}
        ${header_files}
)

# Source group makes the files appear in same places in the logical structure
# of the project as where they are in the disk. This is for IDEs such as Visual Studio
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${src_files} ${header_files})
set_property( TARGET ${PROJECT_NAME} PROPERTY FOLDER "modules" )

# Compile features for the target
target_compile_features (LibStoryBoard PRIVATE cxx_std_14)

#---------------------------
# Installation instructions
#---------------------------
include(GNUInstallDirs)

# Export the target
install(TARGETS LibStoryBoard
        EXPORT LibStoryBoardTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Install the headers (nice one liner format)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Export the targets to a script
install(EXPORT LibStoryBoardTargets
        FILE
            LibStoryBoardTargets.cmake
        NAMESPACE
            LibStoryBoard::
        DESTINATION
            ${CMAKE_INSTALL_LIBDIR}/cmake/LibStoryBoard
)

# Create a LibStoryBoardConfigVersion.cmake file
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/LibStoryBoardConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# Create a configuration file
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/LibStoryBoardConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/LibStoryBoardConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/LibStoryBoard
    PATH_VARS CMAKE_INSTALL_INCLUDEDIR CMAKE_INSTALL_LIBDIR
)

# Install the version- and configuration files
install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/LibStoryBoardConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/LibStoryBoardConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/LibStoryBoard
)

#------------------------------
# Add an alias for the library
#------------------------------

# Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(LibStoryBoard::LibStoryBoard ALIAS LibStoryBoard)

# Add tests
include(CTest)
enable_testing()
add_subdirectory(tests)
