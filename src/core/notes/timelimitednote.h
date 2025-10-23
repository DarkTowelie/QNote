#ifndef TIMELIMITEDNOTE_H
#define TIMELIMITEDNOTE_H

#include "../interfaces/inote.h"

//Записка, автоматически удаляемая при наступлении заданного времени
class TimeLimitedNote : public INote
{
public:
    Q_DISABLE_COPY(TimeLimitedNote)

    explicit TimeLimitedNote(const QDateTime& deadline,
                             const QString& id = QString(),
                             const QString& title = QStringLiteral("New Note"),
                             const QString& content = QString());

    explicit TimeLimitedNote(QDateTime&& deadline, QString&& id, QString&& title, QString&& content);

    ~TimeLimitedNote() override = default;

public:
    inline QString id() const noexcept final             { return m_id;           }
    inline QString title() const noexcept final          { return m_title;        }
    inline QString content() const noexcept final        { return m_content;      }
    inline QDateTime lastModified() const noexcept final { return m_lastModified; }

    void setTitle(const QString& title) final { emit modificationRejected(); }
    void setContent(const QString& content) final {emit modificationRejected(); };

signals:
    //Сигнал, оповещающей о поптыке модифицировать записку
    //По задумке TimeLimitedNote остается неизменной с момента создания и до момента исчезновения
    void modificationRejected();

protected:
    QString m_id;
    QString m_title;
    QString m_content;
    QDateTime m_deadline;
    QDateTime m_lastModified;
};

#endif // TIMELIMITEDNOTE_H
