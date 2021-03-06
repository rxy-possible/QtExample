#ifndef EXTENSIONDLG_H
#define EXTENSIONDLG_H

#include <QDialog>
#include <QPushButton>

class ExtensionDlg : public QDialog
{
    Q_OBJECT

public:
    ExtensionDlg(QWidget *parent = nullptr);
    ~ExtensionDlg();
private slots:
    void showDetailInfo();
private:
    void createBaseInfo();
    void createDetailInfo();
    QWidget *baseWidget;    //基本对话框窗体部分
    QWidget *detailWidget;  //扩展窗体部分

    QPushButton *DetailBtn;
};
#endif // EXTENSIONDLG_H
