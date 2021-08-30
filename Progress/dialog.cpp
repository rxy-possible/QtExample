#include "dialog.h"
#include <QProgressDialog>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QFont font("zYsong18030",12);
    setFont(font);
    setWindowTitle(tr("Progress"));
    FileNum = new QLabel();
    FileNum->setText(tr("文件数目"));
    FileNumLineEdit = new QLineEdit;
    FileNumLineEdit->setText(tr("100000"));
    ProgressType = new QLabel();
    ProgressType->setText("显示类型");
    comboBox = new QComboBox();
    comboBox->addItem(tr("progressBar"));
    comboBox->addItem(tr("progressDialog"));
    progressBar = new QProgressBar();
    starBtn = new QPushButton();
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(FileNum,0,0);
    mainLayout->addWidget(FileNumLineEdit,0,1);
    mainLayout->addWidget(ProgressType,1,0);
    mainLayout->addWidget(comboBox,1,1);
    mainLayout->addWidget(progressBar,2,0,1,2);
    mainLayout->addWidget(starBtn,3,1);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);

    connect(starBtn,SIGNAL(clicked(bool)),this,SLOT(startProcess()));

}

Dialog::~Dialog()
{
}

void Dialog::startProcess()
{
    bool ok;
    int num = FileNumLineEdit->text().toInt(&ok);
    if (comboBox->currentIndex() == 0)
    {
        progressBar->setRange(0,num);
        for(int i=1;i<num+1;i++)
        {
            progressBar->setValue(i);
        }
    }
    else if(comboBox->currentIndex() == 1)  //采用进度对话框显示进度
    {
        QProgressDialog *progressDialog = new QProgressDialog(this);
        QFont font("ZYSong18030",12);
        progressDialog->setFont(font);
        progressDialog->setWindowModality(Qt::WindowModal);
        progressDialog->setMinimumDuration(10);
        progressDialog->setWindowTitle(tr("please wait"));
        progressDialog->setLabelText(tr("Copying..."));
        progressDialog->setCancelButtonText(tr("Cancel"));
        progressDialog->setRange(0,num);
        for(int i =1;i<num+1;i++)
        {
            progressDialog->setValue(i);
            if(progressDialog->wasCanceled())
            {
                return;
            }
        }
    }
}

