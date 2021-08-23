#include "msgboxdlg.h"
#include <QMessageBox>

MsgBoxDlg::MsgBoxDlg()
{
    setWindowTitle(tr("标准消息对话框实例"));
    label = new QLabel();
    label->setText(tr("请选择一种消息对话框"));
    questionBtn = new QPushButton();
    questionBtn->setText(tr("QuestionMsg"));
    informationBtn = new QPushButton();
    informationBtn->setText(tr("InformationMsg"));
    warningBtn = new QPushButton;
    warningBtn->setText(tr("WarningMsg"));
    crititalBtn = new QPushButton;
    crititalBtn->setText(tr("CriticalMsg"));
    aboutBtn = new QPushButton;
    aboutBtn->setText(tr("AboutMsg"));
    aboutQtBtn = new QPushButton;
    aboutQtBtn->setText(tr("AboutQtBtn"));
    //布局
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label,0,0,1,2);
    mainLayout->addWidget(questionBtn,1,0);
    mainLayout->addWidget(informationBtn,1,1);
    mainLayout->addWidget(warningBtn,2,0);
    mainLayout->addWidget(crititalBtn,2,1);
    mainLayout->addWidget(aboutBtn,3,0);
    mainLayout->addWidget(aboutQtBtn,3,1);
    connect(questionBtn,&QPushButton::clicked,this,&MsgBoxDlg::showQuestionMsg);
    connect(informationBtn,&QPushButton::clicked,this,&MsgBoxDlg::showInfomationMsg);
    connect(warningBtn,&QPushButton::clicked,this,&MsgBoxDlg::showWariningMsg);
    connect(crititalBtn,&QPushButton::clicked,this,&MsgBoxDlg::showCriticalMsg);
    connect(aboutBtn,&QPushButton::clicked,this,&MsgBoxDlg::showAboutMsg);
    connect(aboutQtBtn,&QPushButton::clicked,this,&MsgBoxDlg::showAboutQtMsg);
}

void MsgBoxDlg::showQuestionMsg()
{
    label->setText(tr("Question Message Box"));
    switch(QMessageBox::question(this,tr("Question消息框"),tr("您现在已经修改完成，是否要结束程序？"),QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Ok))
    {
    case QMessageBox::Ok:
        label->setText("Question button/ok");
        break;
    case QMessageBox::Cancel:
        label->setText("Question button/cancel");
        break;
    default:
        break;
    }
    return;
}

void MsgBoxDlg::showInfomationMsg()
{

}

void MsgBoxDlg::showWariningMsg()
{

}

void MsgBoxDlg::showCriticalMsg()
{

}

void MsgBoxDlg::showAboutMsg()
{

}

void MsgBoxDlg::showAboutQtMsg()
{

}
