#ifndef IPLUGIN_H
#define IPLUGIN_H

#include <QObject>
#include <QString>

class IPlugin : public QObject
{
    Q_OBJECT

public:
    virtual ~IPlugin() = default;

    virtual QString name() const    = 0;
    virtual QString version() const = 0;
    virtual void initialize()       = 0;

signals:
    void errorOccured(const QString& error);
};

#endif // IPLUGIN_H
