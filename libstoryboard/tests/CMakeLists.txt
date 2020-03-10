# ------------------
# Storyboard tests
# ------------------
add_subdirectory(3rdparty)

message(STATUS "-----")
message(STATUS "TESTS")
message(STATUS "-----")

# Test 1
message(STATUS "\tAdding test storyboard_deleteNote")
add_executable (storyboard_deleteNote src/testStoryboard_deleteNote.cpp)
target_link_libraries (storyboard_deleteNote LibStoryBoard)
add_test (NAME storyboard_deleteNote COMMAND storyboard_deleteNote )
set_property ( TARGET storyboard_deleteNote PROPERTY FOLDER "Tests" )

# Test 2
message(STATUS "\tAdding test storyboard_searchByTag")
add_executable (storyboard_searchByTag src/testStoryboard_searchByTag.cpp)
target_link_libraries (storyboard_searchByTag LibStoryBoard)
add_test (NAME storyboard_searchByTag COMMAND storyboard_searchByTag )
set_property ( TARGET storyboard_searchByTag PROPERTY FOLDER "Tests" )

# Test 3
message(STATUS "\tAdding test storyboard_searchByText")
add_executable (storyboard_searchByText src/testStoryboard_searchByText.cpp)
target_link_libraries (storyboard_searchByText LibStoryBoard)
add_test (NAME storyboard_searchByText COMMAND storyboard_searchByText )
set_property ( TARGET storyboard_searchByText PROPERTY FOLDER "Tests" )

# Test 4
message(STATUS "\tAdding test storyboard_searchByTitle")
add_executable (storyboard_searchByTitle src/testStoryboard_searchByTitle.cpp)
target_link_libraries (storyboard_searchByTitle LibStoryBoard)
add_test (NAME storyboard_searchByTitle COMMAND storyboard_searchByTitle )
set_property ( TARGET storyboard_searchByTitle PROPERTY FOLDER "Tests" )

# Source group makes the files appear in same places in the logical structure
# of the project as where they are in the disk. This is for IDEs such as Visual Studio
source_group(
    TREE ${CMAKE_CURRENT_SOURCE_DIR} 
    FILES
        src/testStoryboard_deleteNote.cpp
        src/testStoryboard_searchByTag.cpp
        src/testStoryboard_searchByText.cpp
        src/testStoryboard_searchByTitle.cpp
)
