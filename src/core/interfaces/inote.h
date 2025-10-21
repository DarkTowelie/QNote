#ifndef INOTE_H
#define INOTE_H

#include <QObject>
#include <QString>
#include <QDateTime>

class INote : public QObject
{
    Q_OBJECT

public:
    virtual ~INote() = default;

    virtual QString id() const             = 0;
    virtual QString title() const          = 0;
    virtual QString content() const        = 0;
    virtual QDateTime lastModified() const = 0;

    virtual void setTitle(const QString& title) = 0;
    virtual void setContent(const QString& title) = 0;
};
using INotePtr = std::shared_ptr<INote>;

#endif // INOTE_H
