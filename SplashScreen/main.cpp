#include "mainwindow.h"

#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap("../SplashScreen/source/下载.jpeg");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
    MainWindow w;
    w.show();
    splash.finish(&w);
    return a.exec();
}
