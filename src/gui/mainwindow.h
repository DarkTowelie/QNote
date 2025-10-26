    #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>

#include "../core/interfaces/inote.h"

class NoteModel;
class NoteManager;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(std::shared_ptr<NoteManager> noteManager, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // void onNewNote();
    // void onDeleteNote();
    // void onTextChanged();
    // void onNoteSelected(const QModelIndex& index);


private:
    void setupUI();
    void setupConnections();

    std::shared_ptr<NoteManager> m_noteManager;
    std::unique_ptr<NoteModel> m_noteModel;

    Ui::MainWindow *ui;
    INotePtr m_currentNote;
};
#endif // MAINWINDOW_H
