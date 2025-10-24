#include "jsonhelper.h"

#include <QMap>
#include <QJsonObject>
#include <QJsonDocument>

QString JsonHelper::keyToStr(JsonKey key)
{
    static const QMap<JsonKey, QString> keyStrMap {
        { JsonKey::id ,           "id"           },
        { JsonKey::title ,        "title"        },
        { JsonKey::content ,      "content"      },
        { JsonKey::lastModified , "lastModified" },
        { JsonKey::deadline ,     "deadline"     }
    };

    return keyStrMap[key];
}

QString JsonHelper::formJsonStr(const QHash<JsonKey, QString>& keyStrHash)
{
    QJsonObject jsonObj;
    for(auto it = keyStrHash.constBegin(); it != keyStrHash.constEnd(); ++it){
        jsonObj[keyToStr(it.key())] = it.value();
    }

    QJsonDocument doc(jsonObj);
    return doc.toJson(QJsonDocument::Compact);
}
