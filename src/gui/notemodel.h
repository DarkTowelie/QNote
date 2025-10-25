#ifndef NOTEMODEL_H
#define NOTEMODEL_H

#include <QAbstractListModel>
#include "../core/interfaces/inote.h"

class NoteManager;
class NoteModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum roles{
        IdRole = Qt::UserRole + 1,
        TitleRole,
        ContentRole,
        LastModifiedRole
    };

    explicit NoteModel(NoteManager& manager, QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void refresh();

private:
    NoteManager& m_noteManager;
    QVector<INotePtr> m_notes;
};

#endif // NOTEMODEL_H
