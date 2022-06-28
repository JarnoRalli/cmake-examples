#include <iostream>
#include "storyboard/storyboard.hpp"

int main (int argc, char *argv[])
{
    std::cout << "--- STORYBOARD ---" << std::endl;
    storyboard::Note note1( "Story 1", "text", {"tag1", "tag2", "tag3"} );
    storyboard::Note note2( "Story 2", "text", {"tag one", "tag two"} );

    storyboard::Storyboard myBoard;
    myBoard.addNote(note1);
    myBoard.addNote(note2);

    //Search the storyboard based on tags
    storyboard::t_note_cont result;
    std::cout << "1. Search the storyboard for notes that contain 'tag one' AND 'tag two' in the tag field" << std::endl;
    std::cout << "Found " << myBoard.searchByTag({"tag one", "tag two"}, result) << " matching notes" << std::endl;
    for( auto& note : result )
    {
        note.printMe();
    }
    std::cout << std::endl;

    //Search the storyboard based on text
    std::cout << "2. Search the storyboard for notes that contain 'text' in the text-field" << std::endl;
    result.clear();
    std::cout << "Found " << myBoard.searchByText("text", result) << " matching notes" << std::endl;
    for( auto& note : result )
    {
        note.printMe();
    }
    std::cout << std::endl;
}
