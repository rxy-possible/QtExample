#include "digiclock.h"
#include <QTimer>
#include <QTime>
#include <QMouseEvent>
#include <QDebug>

DigiClock::DigiClock()
{
    /*设置时钟背景*/
    QPalette p = palette();
    p.setColor(QPalette::Window,Qt::blue);
    setPalette(p);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowOpacity(0.5);
    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&DigiClock::showTime);
    timer->start(1000);
    showTime();
    resize(150,60);
    showColon = true;
}

void DigiClock::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if(showColon)
    {
        text[2]=':';
        showColon = false;
    }
    else
    {
        text[2]=' ';
        showColon=true;
    }
    display(text);
}

void DigiClock::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        dragPpsition = event->globalPos()-frameGeometry().topLeft();
        qDebug()<<"globalPos"<<event->globalPos();
        qDebug()<<"dragPpsition"<<dragPpsition;
        event->accept();
    }
    if(event->button() == Qt::RightButton)
    {
        close();
    }
}

void DigiClock::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos()-dragPpsition);
        event->accept();
    }
}
