#include "timelimitednote.h"

#include <QUuid>
#include "../../jsonhelper.h"

TimeLimitedNote::TimeLimitedNote(const QDateTime& deadline, const QString &id, const QString &title, const QString &content) :
    m_id(id),
    m_title(title),
    m_content(content),
    m_deadline(deadline),
    m_lastModified(QDateTime::currentDateTime())
{
    if (m_id.isEmpty()) {
        m_id = QUuid::createUuid().toString(QUuid::WithoutBraces);
    }
}

TimeLimitedNote::TimeLimitedNote(QDateTime&& deadline, QString&& id, QString&& title, QString&& content) :
    m_id(std::move(id)),
    m_title(std::move(title)),
    m_content(std::move(content)),
    m_deadline(std::move(deadline)),
    m_lastModified(QDateTime::currentDateTime())
{
    if (m_id.isEmpty()) {
        m_id = QUuid::createUuid().toString(QUuid::WithoutBraces);
    }
}

QString TimeLimitedNote::toString() const
{
    QHash<JsonKey, QString> values {
        { JsonKey::id,           m_id },
        { JsonKey::title,        m_title},
        { JsonKey::content,      m_content},
        { JsonKey::lastModified, m_lastModified.toString(Qt::DateFormat::ISODate)},
        { JsonKey::deadline,     m_deadline.toString(Qt::DateFormat::ISODate)}
    };

    return JsonHelper::formJsonStr(values);
}
