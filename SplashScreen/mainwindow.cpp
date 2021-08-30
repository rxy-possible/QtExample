#include "mainwindow.h"
#include <QTextEdit>
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Splash Example");
    QTextEdit *edit = new QTextEdit();
    edit->setText("Splash Example!");
    setCentralWidget(edit);
    resize(600,450);
    sleep(2);

}

MainWindow::~MainWindow()
{
}

