#include "widget.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QBitmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPixmap pix;
    pix.load("../ShapWidget/source/下载.jpeg",0,Qt::AvoidDither|Qt::ThresholdDither|Qt::ThresholdAlphaDither);

    resize(pix.size());
    setMask(QBitmap(pix.mask()));
}

Widget::~Widget()
{
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    if(event->button() == Qt::RightButton)
    {
        close();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos()-dragPosition);
        event->accept();
    }
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap("../ShapWidget/source/下载.jpeg"));
}

