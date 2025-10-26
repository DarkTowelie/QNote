#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "notemodel.h"

MainWindow::MainWindow(std::shared_ptr<NoteManager> noteManager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_noteManager(noteManager)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
