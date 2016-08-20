#include "dialog.h"

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    m_Label = new QLabel(tr( "Find &what:"));
    m_LineEdit = new QLineEdit();
    m_Label->setBuddy( m_LineEdit);

    m_CaseCheckBox = new QCheckBox(tr("Match &case"));
    m_BackwardCheckBox = new QCheckBox(tr("Search &backword"));

    m_FindButton = new QPushButton( tr("&Find"));
    m_FindButton->setDefault(true);
    m_FindButton->setEnabled(false);

    m_CloseButton = new QPushButton(tr("C&lose"));

    connect(m_LineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(EnableFindButton(const QString &)));
    connect(m_FindButton, SIGNAL(clicked(bool)), this, SLOT(FindClicked()));
    connect(m_CloseButton, SIGNAL(clicked(bool)), this, SLOT(close()));

    QHBoxLayout* topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(m_Label);
    topLeftLayout->addWidget(m_LineEdit);

    QVBoxLayout* leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(m_CaseCheckBox);
    leftLayout->addWidget(m_BackwardCheckBox);

    QVBoxLayout* rightLayout = new QVBoxLayout;
    rightLayout->addWidget(m_FindButton);
    rightLayout->addWidget(m_CloseButton);
    rightLayout->addStretch();

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());
}

Dialog::~Dialog()
{

}

void Dialog::FindClicked()
{
    QString txt = m_LineEdit->text();

    Qt::CaseSensitivity cs = m_CaseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;

    if( m_BackwardCheckBox->isChecked())
        emit FindPrevious( txt, cs);
    else
        emit FindNext(txt, cs);
}

void Dialog::EnableFindButton(const QString &text)
{
    m_FindButton->setEnabled( !text.isEmpty());
}
