#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <QWidget>

namespace Ui {
class NoteWidget;
}

class NoteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NoteWidget(QWidget *parent = nullptr);
    ~NoteWidget();

private:
    Ui::NoteWidget *ui;
};

#endif // NOTEWIDGET_H
