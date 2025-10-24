#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <memory.h>

#include "../gui/mainwindow.h"

class MainWindow;
class NoteManager;
class Application : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Application)

public:
    explicit Application(QObject* parent = 0);
    ~Application() override = default;

    inline std::shared_ptr<NoteManager> noteManager() noexcept { return m_noteManager; }

private:
    //Тут будет plugin manager
    std::unique_ptr<MainWindow>  m_mainWindow;
    std::shared_ptr<NoteManager> m_noteManager;
};

#endif // APPLICATION_H
