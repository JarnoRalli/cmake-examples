# ------------------
# Storyboard tests
# ------------------
add_subdirectory(3rdparty)

message(STATUS "-----")
message(STATUS "TESTS")
message(STATUS "-----")

# Test 1
message(STATUS "\tAdding test storyboard_deleteNote")
add_executable (storyboard_deleteNote ${CMAKE_CURRENT_SOURCE_DIR}/src/testStoryboard_deleteNote.cpp)
target_link_libraries (storyboard_deleteNote LibStoryBoard)
add_test (NAME storyboard_deleteNote COMMAND storyboard_deleteNote )

# Test 2
message(STATUS "\tAdding test storyboard_searchByTag")
add_executable (storyboard_searchByTag ${CMAKE_CURRENT_SOURCE_DIR}/src/testStoryboard_searchByTag.cpp)
target_link_libraries (storyboard_searchByTag LibStoryBoard)
add_test (NAME storyboard_searchByTag COMMAND storyboard_searchByTag )

# Test 3
message(STATUS "\tAdding test storyboard_searchByText")
add_executable (storyboard_searchByText ${CMAKE_CURRENT_SOURCE_DIR}/src/testStoryboard_searchByText.cpp)
target_link_libraries (storyboard_searchByText LibStoryBoard)
add_test (NAME storyboard_searchByText COMMAND storyboard_searchByText )

# Test 4
message(STATUS "\tAdding test storyboard_searchByTitle")
add_executable (storyboard_searchByTitle ${CMAKE_CURRENT_SOURCE_DIR}/src/testStoryboard_searchByTitle.cpp)
target_link_libraries (storyboard_searchByTitle LibStoryBoard)
add_test (NAME storyboard_searchByTitle COMMAND storyboard_searchByTitle )

