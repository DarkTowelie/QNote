#ifndef IPLUGIN_H
#define IPLUGIN_H

#include <QObject>
#include <QString>
#include <memory.h>

class IPlugin : public QObject
{
    Q_OBJECT

public:
    explicit IPlugin(QObject *parent = nullptr);
    virtual ~IPlugin() = default;
    virtual QString name() = 0;
    virtual QString version() = 0;
    virtual void initialize() = 0;

signals:
    void errorOccured(const QString& error);
};

#endif // IPLUGIN_H
