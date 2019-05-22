# We have to tell the system to include the binary output directory in the list of directories where headers are searched
include_directories (${CMAKE_CURRENT_BINARY_DIR}/include)				

add_executable (storyboard ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries (storyboard libstoryboard)

