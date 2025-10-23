#include "timelimitednote.h"

#include <QUuid>

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
