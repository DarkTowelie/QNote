#ifndef NOTE_H
#define NOTE_H

#include "interfaces/inote.h"

class Note : public INote
{
public:
    Q_DISABLE_COPY(Note)

    explicit Note(const QString& id = QString(),
                  const QString& title = QStringLiteral("New Note"),
                  const QString& content = QString());

    explicit Note(QString&& id,
                  QString&& title,
                  QString&& content);

    ~Note() override = default;

public:
    inline QString id() const noexcept override             { return m_id;           }
    inline QString title() const noexcept override          { return m_title;        }
    inline QString content() const noexcept override        { return m_content;      }
    inline QDateTime lastModified() const noexcept override { return m_lastModified; }

    void setTitle(const QString& title) override;
    void setContent(const QString& content) override;

private:
    QString m_id;
    QString m_title;
    QString m_content;
    QDateTime m_lastModified;
};

#endif // NOTE_H
