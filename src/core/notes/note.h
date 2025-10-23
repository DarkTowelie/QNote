#ifndef NOTE_H
#define NOTE_H

#include "../interfaces/inote.h"

//Простая записка по умолчанию, с заголовком и подписью
class Note : public INote
{
    Q_OBJECT
    Q_DISABLE_COPY(Note)

public:

    explicit Note(const QString& id = QString(),
                  const QString& title = QStringLiteral("New Note"),
                  const QString& content = QString());

    explicit Note(QString&& id,
                  QString&& title,
                  QString&& content);

    ~Note() override = default;

public:
    inline QString id() const noexcept final             { return m_id;           }
    inline QString title() const noexcept final          { return m_title;        }
    inline QString content() const noexcept final        { return m_content;      }
    inline QDateTime lastModified() const noexcept final { return m_lastModified; }

    void setTitle(const QString& title) final;
    void setContent(const QString& content) final;

protected:
    QString m_id;
    QString m_title;
    QString m_content;
    QDateTime m_lastModified;
};

#endif // NOTE_H
