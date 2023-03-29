#include "storyboard/storyboard.hpp"

int main(int argc, char *argv[])
{
    storyboard::Note        note("Story 1", "text", {"tag1", "tag2", "tag3"});
    storyboard::Storyboard  myBoard;
    storyboard::t_note_cont result;
    myBoard.addNote(note);

    if ((myBoard.searchByTitle("Story 1", result) == 1) && (myBoard.searchByTitle("", result) == 0))
    {
        return 0;
    }
    else
    {
        return 1;
    }

    return 0;
}
