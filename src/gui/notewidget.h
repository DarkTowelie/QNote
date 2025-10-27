#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <QFrame>
#include "../core/interfaces/inote.h"

namespace Ui {
class NoteWidget;
}

class QPushButton;
class NoteWidget : public QFrame
{
    Q_OBJECT

public:
    explicit NoteWidget(const INotePtr& note, QWidget *parent = nullptr);
    ~NoteWidget();

    inline INotePtr note() const noexcept { return m_note; }
    inline QString noteId() const { return m_note->id(); }

    void updateDisplay();
    void setSelected(bool selected);
    bool isSelected() const { return m_selected; }

signals:
    void clicked(NoteWidget* wodget);
    void doubleCLicked(NoteWidget* widget);
    void deleteRequested(NoteWidget* widged);
    void contentChagged(NoteWidget* widget);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private slots:
    void onTitleChanged();
    void onContentChanged();
    void onDeleteClicked();

private:
    void setupUI();
    void setupConnections();
    void updateTimestamp();

private:
    Ui::NoteWidget *ui;
    INotePtr m_note;
    bool m_selected = false;

    QPushButton* m_deleteButton;
};

#endif // NOTEWIDGET_H
