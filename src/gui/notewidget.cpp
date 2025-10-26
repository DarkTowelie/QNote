#include "notewidget.h"
#include "ui_notewidget.h"

NoteWidget::NoteWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NoteWidget)
{
    ui->setupUi(this);
}

NoteWidget::~NoteWidget()
{
    delete ui;
}
