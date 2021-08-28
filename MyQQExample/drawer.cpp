#include "drawer.h"
#include <QGroupBox>
#include <QVBoxLayout>

Drawer::Drawer()
{
    setWindowTitle(tr("My QQ"));
    toolBtuoon1_1 = new QToolButton();
    toolBtuoon1_1->setText(tr("张三"));
    toolBtuoon1_1->setIcon(QPixmap("../MyQQExample/source/images (1).jpeg"));
    toolBtuoon1_1->setIconSize(QSize(50,50));
    toolBtuoon1_1->setAutoRaise(true);
    toolBtuoon1_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtuoon1_2 = new QToolButton();
    toolBtuoon1_2->setText(tr("李四"));
    toolBtuoon1_2->setIcon(QPixmap("../MyQQExample/source/images (2).jpeg"));
    toolBtuoon1_2->setIconSize(QSize(50,50));
    toolBtuoon1_2->setAutoRaise(true);
    toolBtuoon1_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtuoon1_3 = new QToolButton();
    toolBtuoon1_3->setText(tr("王五"));
    toolBtuoon1_3->setIcon(QPixmap("../MyQQExample/source/images (3).jpeg"));
    toolBtuoon1_3->setIconSize(QSize(50,50));
    toolBtuoon1_3->setAutoRaise(true);
    toolBtuoon1_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtuoon1_4 = new QToolButton();
    toolBtuoon1_4->setText(tr("小赵"));
    toolBtuoon1_4->setIcon(QPixmap("../MyQQExample/source/images.jpeg"));
    toolBtuoon1_4->setIconSize(QSize(50,50));
    toolBtuoon1_4->setAutoRaise(true);
    toolBtuoon1_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtuoon1_5 = new QToolButton();
    toolBtuoon1_5->setText(tr("小孙"));
    toolBtuoon1_5->setIcon(QPixmap("../MyQQExample/source/images(4).jpeg"));
    toolBtuoon1_5->setIconSize(QSize(50,50));
    toolBtuoon1_5->setAutoRaise(true);
    toolBtuoon1_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox1 = new QGroupBox();
    QVBoxLayout * layout1 = new QVBoxLayout(groupBox1);
    layout1->setMargin(10);
    layout1->setAlignment(Qt::AlignHCenter);

    //加入抽屉内的各个按钮
    layout1->addWidget(toolBtuoon1_1);
    layout1->addWidget(toolBtuoon1_2);
    layout1->addWidget(toolBtuoon1_3);
    layout1->addWidget(toolBtuoon1_4);
    layout1->addWidget(toolBtuoon1_5);
    //插入一个占位符
    layout1->addStretch();

    toolBtuoon2_1 = new QToolButton();
    toolBtuoon2_1->setText(tr("小王"));
    toolBtuoon2_1->setIcon(QPixmap("../MyQQExample/source/images (5).jpeg"));
    toolBtuoon2_1->setIconSize(QSize(50,50));
    toolBtuoon2_1->setAutoRaise(true);
    toolBtuoon2_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtuoon2_2 = new QToolButton();
    toolBtuoon2_2->setText(tr("小张"));
    toolBtuoon2_2->setIcon(QPixmap("../MyQQExample/source/images (6).jpeg"));
    toolBtuoon2_2->setIconSize(QSize(50,50));
    toolBtuoon2_2->setAutoRaise(true);
    toolBtuoon2_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox2 = new QGroupBox();
    QVBoxLayout *layout2 = new QVBoxLayout(groupBox2);
    layout2->setMargin(10);
    layout2->setAlignment(Qt::AlignHCenter);
    layout2->addWidget(toolBtuoon2_1);
    layout2->addWidget(toolBtuoon2_2);

    toolBtuoon3_1 = new QToolButton();
    toolBtuoon3_1->setText(tr("小陈"));
    toolBtuoon3_1->setIcon(QPixmap("../MyQQExample/source/images (7).jpeg"));
    toolBtuoon3_1->setIconSize(QSize(50,50));
    toolBtuoon3_1->setAutoRaise(true);
    toolBtuoon3_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtuoon3_2 = new QToolButton();
    toolBtuoon3_2->setText(tr("小李"));
    toolBtuoon3_2->setIcon(QPixmap("../MyQQExample/source/下载.jpeg"));
    toolBtuoon3_2->setIconSize(QSize(50,50));
    toolBtuoon3_2->setAutoRaise(true);
    toolBtuoon3_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox3 = new QGroupBox();
    QVBoxLayout *layout3 = new QVBoxLayout(groupBox3);
    layout3->setMargin(10);
    layout3->setAlignment(Qt::AlignHCenter);
    layout3->addWidget(toolBtuoon3_1);
    layout3->addWidget(toolBtuoon3_2);

    //将准备好的抽屉插入ToolBox中
    this->addItem((QWidget*)groupBox1,tr("我的好友"));
    this->addItem((QWidget*)groupBox2,tr("陌生人"));
    this->addItem((QWidget*)groupBox3,tr("黑名单"));
}
