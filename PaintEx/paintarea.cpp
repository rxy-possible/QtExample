#include "paintarea.h"
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

PaintArea::PaintArea(QWidget *parent)
    : QWidget(parent)
{
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    setMaximumSize(400,400);
    qDebug()<<"if i can";
}

PaintArea::~PaintArea()
{
}

void PaintArea::setShape(Shape s)
{
    shape = s;
    update();
}

void PaintArea::setPen(QPen p)
{
    pen = p;
    update();
}

void PaintArea::setBrush(QBrush b)
{
    brush = b;
    update();
}

void PaintArea::setFillRule(Qt::FillRule rule)
{
    fillRule = rule;
    update();
}

void PaintArea::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setPen(pen);
    p.setBrush(brush);
    QRect rect(50,100,300,200);
    static const QPoint points[4] ={
        QPoint(150,100),
        QPoint(300,150),
        QPoint(350,250),
        QPoint(100,300)
    };
    int startAngle = 30 * 16;
    int spanAngle = 120 * 16;
    QPainterPath path;
    path.addRect(150,150,100,100);
    path.moveTo(100,100);
    path.cubicTo(300,100,200,200,300,300);
    path.cubicTo(100,300,200,200,100,100);
    path.setFillRule(fillRule);

    switch(shape)
    {
    case Line:
        p.drawLine(rect.topLeft(),rect.bottomRight());
        break;
    case Rectangle:
        p.drawRect(rect);
        break;
    case RoundRect:
        p.drawRoundRect(rect);
        break;
    case Ellipse:
        p.drawEllipse(rect);
        break;
    case Polygon:
        p.drawPolygon(points,4);
        break;
    case Points:
        p.drawPoints(points,4);
        break;
    case Arc:
        p.drawArc(rect,startAngle,spanAngle);
        break;
    case Path:
        p.drawPath(path);
        break;
    case Text:
        p.drawText(rect,Qt::AlignCenter,tr("Hello Qt!"));
        break;
    case Pixmap:
        p.drawPixmap(150,150,QPixmap("butterfly.png"));
        break;
    default:break;
    }
    qDebug()<<"if i can";

}
