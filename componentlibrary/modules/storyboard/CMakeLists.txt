cmake_minimum_required(VERSION 3.12)

message(STATUS "--------------")
message(STATUS "LIBSTORYBOARD")
message(STATUS "--------------")

project(StoryBoard VERSION 1.0 LANGUAGES CXX)

# -----------------------------------
# Generate the library (i.e. target)
# -----------------------------------
list(   APPEND 
        src_files   
        src/storyboard.cpp
)

list(   APPEND 
        header_files
        include/storyboard/storyboard.hpp)

# Add a library
add_library(StoryBoard)

# Add the library to a list of libraries
set(MAIN_LIBRARY_LIST "${MAIN_LIBRARY_LIST};StoryBoard" CACHE INTERNAL "A list of the libraries in this project" FORCE)

# Add directories to the target
# PRIVATE and PUBLIC items will populate the INCLUDE_DIRECTORIES property of target
# PUBLIC and INTERFACE items will populate the INTERFACE_INCLUDE_DIRECTORIES property of target
target_include_directories(StoryBoard
    PUBLIC 
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add sources to the library
# Header files are added only so that they appear in IDEs such as Visual Studio etc
# For INTERFACE libraries (header only) this is the only way to make the header
# files appear in the project in IDEs such as Visual Studio
target_sources(StoryBoard
    PRIVATE
        ${src_files}
        ${header_files})

# Source group makes the files appear in same places in the logical structure
# of the project as where they are in the disk. This is for IDEs such as Visual Studio
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${src_files} ${header_files})
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "modules")

# Compile features for the target
target_compile_features(StoryBoard PRIVATE cxx_std_14)

#---------------------------
# Installation instructions
#---------------------------
include(GNUInstallDirs)

# Export the target
install(TARGETS StoryBoard
        EXPORT StoryBoardTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

# Install the headers (nice one liner format)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Export the targets to a script
install(EXPORT StoryBoardTargets
        FILE
            ComponentLibraryStoryBoardTargets.cmake
        NAMESPACE
            ComponentLibrary::
        DESTINATION
            ${CMAKE_INSTALL_LIBDIR}/cmake/ComponentLibrary)

#------------------------------
# Add an alias for the library
#------------------------------

# Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(ComponentLibrary::StoryBoard ALIAS StoryBoard)

#-----------
# Add tests
#-----------

# Add tests
include(CTest)
add_subdirectory(tests)
