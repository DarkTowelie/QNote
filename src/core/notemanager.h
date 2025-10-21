#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include <QHash>
#include <QVector>
#include <memory.h>
#include <optional>

#include "interfaces/inote.h"

class NoteManager
{
public:
    std::optional<INotePtr> getNote(const QString& id) const;
    std::optional<INotePtr> createNote (const QString& title = "New Note");

    bool removeNote(const QString& id);
    QVector<INotePtr> getAllNotes() const;

private:
    QHash<QString, INotePtr> m_notes;
};

#endif // NOTEMANAGER_H
