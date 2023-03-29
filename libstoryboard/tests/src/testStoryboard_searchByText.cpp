#include "storyboard/storyboard.hpp"

int main(int argc, char *argv[])
{
    storyboard::Note        note("Story 1", "yes no", {"tag1", "tag2", "tag3"});
    storyboard::Storyboard  myBoard;
    storyboard::t_note_cont result;
    myBoard.addNote(note);

    if ((myBoard.searchByText("yes", result) == 1) && (myBoard.searchByText("no", result) == 1) &&
        (myBoard.searchByText("yes no", result) == 1) && (myBoard.searchByText("test", result) == 0))
    {
        return 0;
    }
    else
    {
        return 1;
    }

    return 0;
}
