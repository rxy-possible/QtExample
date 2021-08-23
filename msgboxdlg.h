#ifndef MSGBOXDLG_H
#define MSGBOXDLG_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>


class MsgBoxDlg : public QDialog
{
    Q_OBJECT
public:
    MsgBoxDlg();
private slots:
    void showQuestionMsg();
    void showInfomationMsg();
    void showWariningMsg();
    void showCriticalMsg();
    void showAboutMsg();
    void showAboutQtMsg();
private:
    QLabel *label;
    QPushButton *questionBtn;
    QPushButton *informationBtn;
    QPushButton *warningBtn;
    QPushButton *crititalBtn;
    QPushButton *aboutBtn;
    QPushButton *aboutQtBtn;
    QGridLayout *mainLayout;
};

#endif // MSGBOXDLG_H
