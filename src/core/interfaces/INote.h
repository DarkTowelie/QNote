#ifndef INOTE_H
#define INOTE_H

#include <QObject>
#include <QString>

class INote : public QObject
{
    Q_OBJECT

public:
    virtual ~INote() = default;
    virtual QString name() = 0;
    virtual QString version() = 0;
    virtual void initialize() = 0;

signals:
    void errorOccured(const QString& error);
};

#endif // INOTE_H
