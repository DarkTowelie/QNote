#include "notemanager.h"
#include "notes/note.h"

std::optional<INotePtr> NoteManager::getNote(const QString &id) const
{
    if(m_notes.contains(id)){
        return m_notes[id];
    }

    return std::nullopt;
}

std::optional<INotePtr> NoteManager::createNote(QString&& title, QString&& content, const QString&& id)
{
    if(m_notes.contains(id)){
        return std::nullopt;
    }

    INotePtr note = std::make_shared<Note>(id, title, content);
    if(note)
    {
        m_notes[id] = note;
        return note;
    }

    return std::nullopt;
}

bool NoteManager::removeNote(const QString &id)
{
    if(!m_notes.contains(id)){
        return false;
    }

    m_notes.take(id);
    return true;
}

QVector<INotePtr> NoteManager::getAllNotes() const
{
    QVector<INotePtr> res;
    for(auto it = m_notes.begin(); it != m_notes.end(); ++it){
        res << it.value();
    }
    return res;
}

QVector<INotePtr> NoteManager::getNotesByTitle(const QString &title) const
{
    QVector<INotePtr> res;
    for(auto it = m_notes.begin(); it != m_notes.end(); ++it){
        if(it.value()->title() == title){
            res << it.value();
        }
    }
    return res;
}
