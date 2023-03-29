#pragma once

#include <string>
#include <vector>

namespace storyboard {

class Note;
using t_tag_cont  = std::vector<std::string>;
using t_note_cont = std::vector<Note>;

/**
 * @class Note
 * @brief Simple note-object
 */
class Note
{
public:
    /**
     * @brief Simple constructor
     */
    Note() : m_title(""), m_text("")
    {
    }

    /**
     * @brief Constructor with parameters
     * @param[in] title : Note's title
     * @param[in] text : Note's text
     * @param[in] tags : Note's tags
     */
    Note(const std::string& title, const std::string& text, const t_tag_cont& tags)
        : m_title(title), m_text(text), m_tags(tags)
    {
    }

    /**
     * @brief Destructor
     */
    virtual ~Note()
    {
    }

    /**
     * @brief operator==
     * @param[in] other : Compared object
     * @return true if contents of this object are the same as those of the input object, otherwise return false
     */
    bool operator==(const Note& other);

    /**
     * @brief print note data into std::cout
     */
    void printMe();

    std::string m_title;  /// Title of the note-object
    std::string m_text;   /// Text of the note-object
    t_tag_cont  m_tags;   /// Tag(s) of the note-object
};

/**
 * @class Storyboard
 * @brief An object that contains Note objects.
 * @details Has functionality for adding, deleting and searching for Note objects.
 */
class Storyboard
{
public:
    /**
     * @brief Adds a new note object into the Storyboard
     * @param[in] : newNote note to be added into the Storyboard
     */
    void addNote(const Note& newNote);

    /**
     * @brief Adds a new note object into the Storyboard. Uses move semantics (i.e. steals the resources from the given
     * object)
     * @param[in] : newNote note to be added into the Storyboard
     */
    void addNote(Note&& newNote);

    /**
     * @brief Removes a note from the Storyboard
     * @param[in] deleteMe : Sample of a Note object to be deleted from the Storyboard. Note objects that are equal to
     * deleteMe will be deleted.
     * @return number of elements that were deleted
     */
    int deleteNote(const Note& deleteMe);

    /**
     * @brief Search the Storyboard for notes that contain the given string in the title field
     * @param[in] title : string that is matched
     * @param[in,out] container : notes in the Storyboard that contain the matched field are added into this container
     */
    int searchByTitle(const std::string& title, t_note_cont& container);

    /**
     * @brief Search the Storyboard container for notes that contain the given string in the text field
     * @param[in] title : string that is matched
     * @param[in,out] container : notes in the Storyboard that contain the matched field are added into this container
     */
    int searchByText(const std::string& text, t_note_cont& container);

    /**
     * @brief Search the Storyboard container for notes that contain the given string(s) in the tag field
     * @param[in] title : string that is matched
     * @param[in,out] container : notes in the Storyboard that contain the matched field are added into this container
     */
    int searchByTag(const t_tag_cont& tags, t_note_cont& container);

    /**
     * @brief prints contents of the Storyboard into std::cout
     */
    void print();

private:
    t_note_cont m_notes;  /// Container of Note objects
};

}  // End of namespace storyboard
