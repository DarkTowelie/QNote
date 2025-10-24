#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include <QUuid>
#include <QHash>
#include <QVector>
#include <memory.h>
#include <optional>

#include "interfaces/inote.h"

class NoteManager
{
public:
    NoteManager(){}

    std::optional<INotePtr> getNote(const QString& id) const;
    std::optional<INotePtr> createNote (QString&& title, QString&& content, const QString&& id = QUuid::createUuid().toString(QUuid::WithoutBraces));

    bool removeNote(const QString& id);
    QVector<INotePtr> getAllNotes() const;

    QVector<INotePtr> getNotesByTitle(const QString& title) const;
    QString notesToStr() const;

private:
    QHash<QString, INotePtr> m_notes;
};

#endif // NOTEMANAGER_H
