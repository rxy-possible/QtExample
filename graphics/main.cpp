#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QFont>
#include <QBrush>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//QGraphicsSimpleTextItem用法
    //定义一个item
//    QGraphicsSimpleTextItem *pItem = new QGraphicsSimpleTextItem();
//    QFont font = pItem->font();
//    font.setPixelSize(20);
//    font.setItalic(true);
//    font.setUnderline(true);
//    pItem->setFont(font);

//    pItem->setBrush(QBrush(QColor(0,160,230)));

//    //将item添加至场景中
//    QGraphicsScene *pScene = new QGraphicsScene();
//    pScene->addItem(pItem);

//    //为视图设置场景
//    QGraphicsView *pView = new QGraphicsView();
//    pView->setScene(pScene);
//    pView->setStyleSheet("border:none;background:transparent;");

//    pView->show();

    // 定义一个 item
    QGraphicsSimpleTextItem *pItem = new QGraphicsSimpleTextItem();
    pItem->setText(QString::fromLocal8Bit("一去丶二三里"));

    // 字体
    QFont font = pItem->font();
    font.setPixelSize(20);  // 像素大小
    font.setItalic(true);  // 斜体
    font.setUnderline(true);  // 下划线
    pItem->setFont(font);

    pItem->setBrush(QBrush(QColor(0, 160, 230)));

    // 将 item 添加至场景中
    QGraphicsScene *pScene = new QGraphicsScene();
    pScene->addItem(pItem);

    // 为视图设置场景
    QGraphicsView *pView = new QGraphicsView();
    pView->setScene(pScene);
    pView->setStyleSheet("border:none; background:transparent;");

    pView->show();

    return   a.exec();
}
