#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include "inputdlg.h"
#include "msgboxdlg.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QGridLayout *mainLayout;
//文件对话框
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;
//颜色对话框
    QPushButton *colorBtn;
    QFrame *colorFrame;
//字体对话框
    QPushButton *fontBtn;
    QLineEdit *fontLineEdit;
//标准输入对话框
    QPushButton *inputBtn;
    InputDlg *inputDlg;
//标准消息对话框
    QPushButton *MsgBtn;
    MsgBoxDlg *MsgDlg;

private slots:
    void showFile();
    void showColor();
    void showFont();
    void showInputDlg();
    void showMsgDlg();

};
#endif // DIALOG_H
