#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QPushButton;
class QLabel;
class QCheckBox;
class QLineEdit;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

signals:
    void    FindNext(const QString& str, Qt::CaseSensitivity cs);
    void    FindPrevious( const QString& str, Qt::CaseSensitivity cs);

private slots:
    void    FindClicked();
    void    EnableFindButton(const QString& text);

private:
    QLabel*         m_Label;
    QLineEdit*      m_LineEdit;
    QCheckBox*      m_CaseCheckBox;
    QCheckBox*      m_BackwardCheckBox;
    QPushButton*    m_FindButton;
    QPushButton*    m_CloseButton;
};

#endif // DIALOG_H
