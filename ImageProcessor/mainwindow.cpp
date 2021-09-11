#include "mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Easy Word"));
    showWidget =new ShowWidget(this);
    setCentralWidget(showWidget);
    createActions();
    createMenus();
    createToolBars();
    if(img.load("image.png"))
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
    //“打开”动作
    openFileAction = new QAction(QIcon("Open.png"),tr("打开"),this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    openFileAction->setStatusTip(tr("打开一个文件"));

    //"新建"动作
    NewFileAction = new QAction(QIcon("new.png"),tr("新建"),this);
    NewFileAction->setShortcut(tr("Ctrl+N"));
    NewFileAction->setStatusTip(tr("新建一个文件"));

    //“退出动作”
    exitAction = new QAction(tr("退出"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("退出程序"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));

    //"复制"动作
    copyAction = new QAction(QIcon("copy.png"),tr("复制"),this);
    copyAction->setShortcut(tr("Ctrl+c"));
    copyAction->setStatusTip(tr("复制文件"));
    connect(copyAction,SIGNAL(triggered(bool)),showWidget->text,SLOT(copy()));

    //“剪切”动作
    cutAction = new QAction(QIcon("cut.png"),tr("剪切"),this);
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip(tr("剪切文件"));
    connect(cutAction,SIGNAL(triggered(bool)),showWidget->text,SLOT(cut()));

    //"粘贴"动作
    pasteAction = new QAction(QIcon("paste.png"),tr("粘贴"),this);
    pasteAction->setShortcut(tr("Ctrl+V"));
    pasteAction->setStatusTip(tr("粘贴文件"));
    connect(pasteAction,SIGNAL(triggered(bool)),showWidget->text,SLOT(paste()));

    //"关于"动作
    aboutAction = new QAction(tr("关于"),this);
    connect(aboutAction,SIGNAL(triggered(bool)),this,SLOT(QApplication::aboutQt()));

    //"打印文本"动作
    PrintTextAction = new QAction(QIcon("printText.png"),tr("打印文件"),this);
    PrintTextAction->setStatusTip(tr("打印一个文本"));

    //“打印图片”动作
    PrintImageAction = new QAction(QIcon("printImage.png"),tr("打印图片"),this);
    PrintImageAction->setStatusTip(tr("打印一副图片"));

    //"放大"动作
    zoomInAction = new QAction(QIcon("zoomin.png"),tr("放大"),this);
    zoomInAction->setStatusTip(tr("放大一幅图片"));

    //"缩小"动作
    zoomOutAction = new QAction(QIcon("zoomout.png"),tr("缩小"),this);
    zoomOutAction->setStatusTip(tr("缩小一幅图片"));

    //实现图片旋转的动作
    //旋转90°
    rotate90Action = new QAction(QIcon("rotate90°.png"),tr("旋转90°"));
    rotate90Action->setStatusTip(tr("将一幅图片旋转90°"));

    //旋转180°
    rotate180Action = new QAction(QIcon("rotate180°.png"),tr("旋转180°"));
    rotate180Action->setStatusTip(tr("将一幅图片旋转180°"));

    //旋转270°
    rotate270Action = new QAction(QIcon("rotate270°.png"),tr("旋转270°"));
    rotate270Action->setStatusTip(tr("将一幅图片旋转270°"));

    //实现图片的镜像操作Action
    //纵向镜像
    mirrorVericalAction = new QAction(QIcon("mirrorVertical.png"),tr("纵向镜像"),this);
    mirrorVericalAction->setStatusTip(tr("对一幅图做纵向镜像"));

    //横向镜像
    mirrorHorizontalAction = new QAction(QIcon("mirrorHorizontal.png"),tr("横向镜像"),this);
    mirrorHorizontalAction->setStatusTip(tr("对一幅图做横向镜像"));

    //实现撤销和重做的动作Action
    //撤销和重做
    undoAction = new QAction(QIcon("undo.png"),"撤销",this);
    connect(undoAction,SIGNAL(triggered(bool)),showWidget->text,SLOT(undo()));
    redoAction = new QAction(QIcon("redo.png"),"重做",this);
    connect(redoAction,SIGNAL(triggered(bool)),showWidget->text,SLOT(redo()));
}

void MainWindow::createMenus()
{
    //文件菜单
    fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(NewFileAction);
    fileMenu->addAction(PrintTextAction);
    fileMenu->addAction(PrintImageAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    //缩放菜单
    zoomMenu = menuBar()->addMenu(tr("编辑"));
    zoomMenu->addAction(copyAction);
    zoomMenu->addAction(cutAction);
    zoomMenu->addAction(pasteAction);
    zoomMenu->addAction(aboutAction);
    zoomMenu->addSeparator();
    zoomMenu->addAction(zoomInAction);
    zoomMenu->addAction(zoomOutAction);

    //旋转菜单
    rotateMenu = menuBar()->addMenu(tr("旋转"));
    rotateMenu->addAction(rotate90Action);
    rotateMenu->addAction(rotate180Action);
    rotateMenu->addAction(rotate270Action);

    //镜像菜单
    mirrorMenu = menuBar()->addMenu(tr("镜像"));
    mirrorMenu->addAction(mirrorVericalAction);
    mirrorMenu->addAction(mirrorHorizontalAction);
}

void MainWindow::createToolBars()
{
    //文件工具条
    fileTool = addToolBar("File");
    fileTool->addAction(openFileAction);
    fileTool->addAction(NewFileAction);
    fileTool->addAction(PrintTextAction);
    fileTool->addAction(PrintImageAction);
    //编辑工具条
    zoomTool = addToolBar("Edit");
    zoomTool->addAction(copyAction);
    zoomTool->addAction(cutAction);
    zoomTool->addAction(pasteAction);
    zoomTool->addSeparator();
    zoomTool->addAction(zoomInAction);
    zoomTool->addAction(zoomOutAction);

    //旋转工具条
    rotateTool = addToolBar("rotate");
    rotateTool->addAction(rotate90Action);
    rotateTool->addAction(rotate180Action);
    rotateTool->addAction(rotate270Action);

    //撤销和重做工具条
    doToolBar = addToolBar("doEdit");
    doToolBar->addAction(undoAction);
    doToolBar->addAction(redoAction);

}
