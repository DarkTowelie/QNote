#include "application.h"

#include "notemanager.h"

Application::Application(QObject *parent) : QObject(parent)
{
    m_noteManager = std::make_shared<NoteManager>();
    Q_ASSERT(m_noteManager);

    m_mainWindow  = std::make_unique<MainWindow>();
    Q_ASSERT(m_mainWindow);

    m_mainWindow->show();


#ifdef QT_DEBUG
    m_noteManager->createNote("Записка", "Содержимое");
    m_noteManager->createNote("Записка", "Содержимое");
    m_noteManager->notesToStr();
#endif
}
