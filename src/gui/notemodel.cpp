#include "notemodel.h"

#include "../core/notemanager.h"

NoteModel::NoteModel(NoteManager &manager, QObject *parent) :
    QAbstractListModel(parent), m_noteManager(manager)
{
    refresh();
}

int NoteModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : static_cast<int>(m_notes.size());
}

QVariant NoteModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid() || index.row() >= m_notes.size()){
        return QVariant();
    }

    const auto& note = m_notes[index.row()];
    switch(role)
    {
        case(Qt::DisplayRole):
        case(TitleRole):
            return note->title();
        case(IdRole):
            return note->id();
        case(ContentRole):
            return note->content();
        case(LastModifiedRole):
            return note->lastModified();
        default:
            return QVariant();
    }
}

QHash<int, QByteArray> NoteModel::roleNames() const
{
    static const QHash<int, QByteArray> namesHash {
        { IdRole,            "IdRole"},
        { TitleRole,         "TitleRole"},
        { ContentRole,       "ContentRole"},
        { LastModifiedRole,  "LastModifiedRole"}
    };
    return namesHash;
}

void NoteModel::refresh()
{
    beginResetModel();
    m_notes = m_noteManager.getAllNotes();
    endResetModel();
}
