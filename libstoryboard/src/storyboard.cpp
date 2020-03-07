#include <algorithm>
#include <iostream>

#include <storyboard/storyboard.hpp>

namespace storyboard {

bool Note::operator==(const Note& other)
{
    return (m_title == other.m_title) && (m_text == other.m_text) && (m_tags == other.m_tags);
}

void Note::printMe()
{
    std::cout << "Title: " << m_title << std::endl;
    std::cout << "Text: " << m_text << std::endl;
    std::cout << "Tags: ";
    for( auto& tag : m_tags )
    { std::cout << tag << ", "; }
    std::cout << std::endl;
}

void Storyboard::addNote( const Note& newNote )
{
    m_notes.push_back( newNote );
}

void Storyboard::addNote( Note&& newNote )
{
    m_notes.push_back( std::move(newNote) );
}

int Storyboard::deleteNote( const Note& deleteMe )
{
    int nr_elem = m_notes.size();
    m_notes.erase( std::remove( m_notes.begin(), m_notes.end(), deleteMe ), m_notes.end() );
    return nr_elem - m_notes.size();
}

int Storyboard::searchByTitle( const std::string& title, t_note_cont& container )
{
    int len = container.size();
    std::copy_if(m_notes.begin(), m_notes.end(), std::back_inserter(container), [&title](const Note& cmp){return cmp.m_title == title;} );
    
    return container.size() - len;
}

int Storyboard::searchByText( const std::string& text, t_note_cont& container )
{
    int len = container.size();
    std::copy_if(m_notes.begin(), m_notes.end(), std::back_inserter(container), [&text](const Note& cmp){ return cmp.m_text == text;} );
    
    return container.size() - len;
}

int Storyboard::searchByTag( const t_tag_cont& tags, t_note_cont& container )
{
    int len = container.size();
    std::copy_if(m_notes.begin(), m_notes.end(), std::back_inserter(container), [&tags](const Note& cmp){ return cmp.m_tags == tags;} );
    
    return container.size() - len;
}

void Storyboard::print()
{
    for( auto& note : m_notes )
    {
        std::cout << "Title: " << note.m_title << std::endl;
        std::cout << "Text: " << note.m_text << std::endl;
        std::cout << "Tags: ";
        for( auto& tag : note.m_tags )
        { std::cout << tag << " "; }
        std::cout << std::endl << "--------" << std::endl;
    }
}

} //End of namespace storyboard
