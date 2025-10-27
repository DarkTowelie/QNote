#include "notewidget.h"

#include <QPushButton>

NoteWidget::NoteWidget(INotePtr note, QWidget *parent)
    : QFrame(parent)
    , m_note(note)
{
    setFrameStyle(QFrame::StyledPanel);
    setLineWidth(1);
    setMidLineWidth(0);

    setupUI();
    setupConnections();
    updateDisplay();
}

NoteWidget::~NoteWidget()
{
}

void NoteWidget::setupUI()
{

}

void NoteWidget::setupConnections()
{
    connect()
}
