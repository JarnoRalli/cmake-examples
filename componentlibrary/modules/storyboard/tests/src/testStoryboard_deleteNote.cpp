#include "storyboard/storyboard.hpp"

int main (int argc, char *argv[])
{
    storyboard::Note note( "Story 1", "text", {"tag1", "tag2", "tag3"} );
    storyboard::Storyboard myBoard;
    myBoard.addNote( note );

    if( (myBoard.deleteNote( note ) == 1) && (myBoard.deleteNote( note ) == 0) )
    {   return 0;   }
    else
    { return 1; }
}
