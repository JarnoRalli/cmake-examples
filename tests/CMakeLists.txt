####################
# Storyboard tests #
####################
# Test 1
add_executable (storyboard_deleteNote ${CMAKE_CURRENT_SOURCE_DIR}/src/testStoryboard_deleteNote.cpp)
target_link_libraries (storyboard_deleteNote libstoryboard)

# Test 2
add_executable (storyboard_searchByTag ${CMAKE_CURRENT_SOURCE_DIR}/src/testStoryboard_searchByTag.cpp)
target_link_libraries (storyboard_searchByTag libstoryboard)

# Test 3
add_executable (storyboard_searchByText ${CMAKE_CURRENT_SOURCE_DIR}/src/testStoryboard_searchByText.cpp)
target_link_libraries (storyboard_searchByText libstoryboard)

# Test 4
add_executable (storyboard_searchByTitle ${CMAKE_CURRENT_SOURCE_DIR}/src/testStoryboard_searchByTitle.cpp)
target_link_libraries (storyboard_searchByTitle libstoryboard)

# Add the tests
add_test (NAME storyboard_deleteNote COMMAND storyboard_deleteNote )
add_test (NAME storyboard_searchByTag COMMAND storyboard_searchByTag )
add_test (NAME storyboard_searchByText COMMAND storyboard_searchByText )
add_test (NAME storyboard_searchByTitle COMMAND storyboard_searchByTitle )
