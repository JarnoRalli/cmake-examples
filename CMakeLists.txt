#-----------------------------------------------------
# Simple build system using the modern CMake approach
#-----------------------------------------------------

# Minimum CMake version so that we can use the modern approach is 3.0
cmake_minimum_required (VERSION 3.3)

# Project name, expected programming language is C++
project (Example VERSION 1.0 LANGUAGES CXX)

# Generate documentation if Doxygen is found (requires CMake 3.3 to work)
find_package(Doxygen COMPONENTS doxygen dot QUIET)
if( ${DOXYGEN_FOUND} )
	message( STATUS "Doxygen + dot found, building documentation" )
	set(DOXYGEN_GENERATE_HTML YES CACHE BOOL "Generate HTML")
    set(DOXYGEN_GENERATE_LATEX YES CACHE BOOL "General Latex")
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/doc" CACHE PATH "Output directory")
    set(DOXYGEN_PROJECT_NAME "Example project" CACHE STRING "Project name")
	doxygen_add_docs(
		doc
		${PROJECT_SOURCE_DIR}
	)
else( ${DOXYGEN_FOUND} )
	message( STATUS "Doxygen + dot NOT found, NOT building documentation" )
endif(  ${DOXYGEN_FOUND}  )

# Add subdirectories
add_subdirectory (libstoryboard)
add_subdirectory (storyboard)

# Add tests
include(CTest)
add_subdirectory (tests)

