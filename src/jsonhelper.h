#ifndef JSONHELPER_H
#define JSONHELPER_H

#include <QString>

enum class JsonKey
{
    id,
    title,
    content,
    lastModified,
    deadline
};

class JsonHelper
{
public:
    static QString keyToStr(JsonKey key);
    static QString formJsonStr(const QHash<JsonKey, QString>& keyStrHash);
};

#endif // JSONHELPER_H
