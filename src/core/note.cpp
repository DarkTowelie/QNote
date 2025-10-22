#include "note.h"

#include <QUuid>

Note::Note(const QString &id, const QString &title, const QString &content) :
    m_id(id),
    m_title(title),
    m_content(content),
    m_lastModified(QDateTime::currentDateTime())
{
    if (m_id.isEmpty()) {
        m_id = QUuid::createUuid().toString(QUuid::WithoutBraces);
    }
}

Note::Note(QString&& id, QString&& title, QString&& content) :
    m_id(std::move(id)),
    m_title(std::move(title)),
    m_content(std::move(content)),
    m_lastModified(QDateTime::currentDateTime())
{
    if (m_id.isEmpty()) {
        m_id = QUuid::createUuid().toString(QUuid::WithoutBraces);
    }
}

void Note::setTitle(const QString& title)
{
    if(m_title != title)
    {
        m_title = title;
        m_lastModified = QDateTime::currentDateTime();
    }
}

void Note::setContent(const QString& content)
{
    if(m_content != m_content)
    {
        m_content = content;
        m_lastModified = QDateTime::currentDateTime();
    }
}


