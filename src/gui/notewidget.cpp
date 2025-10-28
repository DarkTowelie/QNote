#include "notewidget.h"

#include <QLabel>
#include <QPainter>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QStyleOption>

NoteWidget::NoteWidget(const INotePtr& note, QWidget *parent)
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

void NoteWidget::updateDisplay()
{
    m_titleLabel->setText(m_note->title());

    QString content = m_note->content();
    if(content.length() > 150)
    {
        //Превью
        content = content.left(147) + "...";
    }
    m_contentPreview->setPlainText(content);

    updateTimestamp();
}

void NoteWidget::setSelected(bool selected)
{
    if(m_selected != selected)
    {
        m_selected = selected;

        if(m_selected)
        {
            static const QString selectedStyleSheet = "NoteWidget {"
                                                      "   border: 2px solid #0078d7;"
                                                      "   background-color: #f0f8ff;"
                                                      "   border-radius: 6px;"
                                                      "}";

            setStyleSheet(selectedStyleSheet);
        }
        else
        {
            static const QString notSelectedStyleSheet = "NoteWidget {"
                                                         "   border: 1px solid #ddd;"
                                                         "   background-color: white;"
                                                         "   border-radius: 6px;"
                                                         "}"
                                                         "NoteWidget:hover {"
                                                         "   border: 1px solid #0078d7;"
                                                         "   background-color: #f8f8f8;"
                                                         "}";

            setStyleSheet(notSelectedStyleSheet);
        }
        update();
    }
}

void NoteWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        emit clicked(this);
    }
    QFrame::mousePressEvent(event);
}

void NoteWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        emit doubleCLicked(this);
    }
    QFrame::mousePressEvent(event);
}

void NoteWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void NoteWidget::onDeleteClicked()
{
    emit deleteRequested(this);
}

void NoteWidget::setupUI()
{
    auto* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(8, 8, 8, 8);
    mainLayout->setSpacing(4);

    m_headerFrame = new QFrame(this);
    auto* headerLayout = new QHBoxLayout(m_headerFrame);
    headerLayout->setContentsMargins(0, 0, 0, 0);

    m_titleLabel = new QLabel(m_headerFrame);
    m_titleLabel->setWordWrap(true);
    m_titleLabel->setStyleSheet("font-weight: bold; font-size: 14px");

    m_deleteButton = new QPushButton("x", m_headerFrame);
    m_deleteButton->setFixedSize(20, 20);
    m_deleteButton->setToolTip(tr("Delete note"));

    headerLayout->addWidget(m_titleLabel, 1);
    headerLayout->addWidget(m_deleteButton);

    m_contentPreview = new QTextEdit();
    m_contentPreview->setReadOnly(true);
    m_contentPreview->setFrameStyle(QFrame::NoFrame);
    m_contentPreview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_contentPreview->setMaximumHeight(100);

    m_timestampLabel = new QLabel(this);
    m_timestampLabel->setStyleSheet("color: #999; font-size: 10px;");
    m_timestampLabel->setAlignment(Qt::AlignRight);

    mainLayout->addWidget(m_headerFrame);
    mainLayout->addWidget(m_contentPreview);
    mainLayout->addWidget(m_timestampLabel);

    setMinimumWidth(200);
    setMaximumWidth(300);
    setMinimumHeight(120);
}

void NoteWidget::setupConnections()
{
    connect(m_deleteButton, &QPushButton::clicked, this, &NoteWidget::onDeleteClicked);
}

void NoteWidget::updateTimestamp()
{
    QString timestamp = m_note->lastModified().toString("dd.MM.yyyy.mm");
    m_timestampLabel->setText(timestamp);
}

