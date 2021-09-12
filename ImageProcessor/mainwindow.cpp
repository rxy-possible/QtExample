#include "mainwindow.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QPixmap>
#include <QPainter>
#include <QtPrintSupport/qprinter.h>
#include <QtPrintSupport/qprintdialog.h>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Easy Word"));
    showWidget =new ShowWidget(this);
    setCentralWidget(showWidget);
    //在工具栏上嵌入控件
    //设置字体
    fontLabel = new QLabel(tr("字体"));
    fontComboBox = new QFontComboBox();
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);
    fontLabel2 = new QLabel(tr("字号"));
    sizeComboBox = new QComboBox();
    QFontDatabase db;
    foreach (int size, db.standardSizes()) {
        sizeComboBox->addItem(QString::number(size));
    }
    boldBtn = new QToolButton();
    boldBtn->setIcon(QIcon("bold.png"));
    boldBtn->setCheckable(true);
    italicBtn = new QToolButton();
    italicBtn->setIcon(QIcon("italic.png"));
    italicBtn->setCheckable(true);
    underlineBtn = new QToolButton();
    underlineBtn->setIcon(QIcon("underline.png"));
    underlineBtn->setCheckable(true);
    colorBtn = new QToolButton();
    colorBtn->setIcon(QIcon("color.png"));
    colorBtn->setCheckable(true);


    //排序
    listLabel = new QLabel(tr("排序"));
    listComboBox = new QComboBox();
    listComboBox->addItem("Standard");
    listComboBox->addItem("QTextListFormat::ListDisc");
    listComboBox->addItem("QTextListFormat::ListCircle");
    listComboBox->addItem("QTextListFormat::ListSquare");
    listComboBox->addItem("QTextListFormat::ListDecimal");
    listComboBox->addItem("QTextListFormat::ListLowerAlpha");
    listComboBox->addItem("QTextListFormat::ListUpperAlpha");
    listComboBox->addItem("QTextListFormat::ListLowerRoman");
    listComboBox->addItem("QTextListFormat::ListUppderRoman");
    createActions();
    createMenus();
    createToolBars();
    qDebug()<<img.load("../ImageProcessor/source/image.jpeg");
    if(img.load("../ImageProcessor/source/image.jpeg"))
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
}

void MainWindow::ShowNewFile()
{
    MainWindow *newImageProcessor = new MainWindow();
    newImageProcessor->show();
}

void MainWindow::ShowOpenFile()
{
    fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        if(showWidget->text->document()->isEmpty())
        {
            loadFile(fileName);
        }
        else
        {
            MainWindow *newImgProcessor = new MainWindow();
            newImgProcessor->show();
            newImgProcessor->loadFile(fileName);
        }
    }
}

void MainWindow::loadFile(QString filename)
{
    printf("file name:%s\n",filename.data());
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream textStream(&file);
        while(!textStream.atEnd())
        {
            showWidget->text->append(textStream.readLine());
            printf("read line\n");
        }
        printf("end\n");
    }
}

void MainWindow::ShowPrintText()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec())
    {
        QTextDocument *doc = showWidget->text->document();
        doc->print(&printer);
    }
}

void MainWindow::ShowPrintImage()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec())
    {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = img.size();

        /*按照图形的比例大小重新设置视图矩形的区域*/
        size.scale(rect.size(),Qt::KeepAspectRatio);
        painter.setViewport(rect.x(),rect.y(),size.width(),size.height());
        painter.setWindow(img.rect());
        painter.drawImage(0,0,img);
    }
}

void MainWindow::ShowzoomIn()
{
    if(img.isNull())
    {
        return;
    }
    QMatrix matrix;
    matrix.scale(2,2);
    img = img.transformed(matrix);
    //重新设置显示图形
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::ShowzoomOut()
{
    if(img.isNull())
    {
        return;
    }
    QMatrix matrix;
    matrix.scale(0.5,0.5);
    img = img.transformed(matrix);
    //重新设置显示图形
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::ShowRotate90()
{
    if(img.isNull())
    {
        return ;
    }

    QMatrix matrix;
    matrix.rotate(90);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::ShowRotate180()
{
    if(img.isNull())
    {
        return ;
    }

    QMatrix matrix;
    matrix.rotate(180);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::ShowRotate270()
{
    if(img.isNull())
    {
        return ;
    }

    QMatrix matrix;
    matrix.rotate(270);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
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

    //排序：左对齐，右对齐，居中和两端对齐
    actGrp = new QActionGroup(this);
    leftAction = new QAction(QIcon("left.png"),"左对齐",actGrp);
    leftAction->setCheckable(true);
    leftAction = new QAction(QIcon("right.png"),"右对齐",actGrp);
    leftAction->setCheckable(true);
    leftAction = new QAction(QIcon("center.png"),"居中",actGrp);
    leftAction->setCheckable(true);
    leftAction = new QAction(QIcon("justify.png"),"两端对齐",actGrp);
    leftAction->setCheckable(true);
    connect(actGrp,SIGNAL(triggered(QAction*)),this,SLOT(ShowAlignment(QAction*)));
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

    connect(NewFileAction,SIGNAL(triggered(bool)),this,SLOT(ShowNewFile()));
    connect(openFileAction,SIGNAL(triggered(bool)),this,SLOT(ShowOpenFile()));
    connect(PrintTextAction,SIGNAL(triggered(bool)),this,SLOT(ShowPrintText()));
    connect(PrintImageAction,SIGNAL(triggered(bool)),this,SLOT(ShowPrintImage()));
    connect(zoomInAction,SIGNAL(triggered(bool)),this,SLOT(ShowzoomIn()));
    connect(zoomOutAction,SIGNAL(triggered(bool)),this,SLOT(ShowzoomOut()));
    connect(rotate90Action,SIGNAL(triggered(bool)),this,SLOT(ShowRotate90()));
    connect(rotate180Action,SIGNAL(triggered(bool)),this,SLOT(ShowRotate180()));
    connect(rotate270Action,SIGNAL(triggered(bool)),this,SLOT(ShowRotate270()));
    connect(fontComboBox,SIGNAL(activated(QString)),this,SLOT(ShowFontComboBox(QString)));
    connect(sizeComboBox,SIGNAL(activated(QString)),this,SLOT(ShowSizeSpinBox(QString)));
    connect(boldBtn,SIGNAL(clicked(bool)),this,SLOT(ShowBoldBtn()));
    connect(italicBtn,SIGNAL(clicked(bool)),this,SLOT(ShowItalicBtn()));
    connect(underlineBtn,SIGNAL(clicked(bool)),this,SLOT(ShowUnderlineBtn()));
    connect(colorBtn,SIGNAL(clicked(bool)),this,SLOT(ShowColorBtn()));
    connect(showWidget->text,SIGNAL(currentCharFormatChanged(QTextCharFormat&)),this,SLOT(ShowCurrentFormatChanged(QTextCharFormat&)));
//    connect(listComboBox,SIGNAL(activated(int)),this,SLOT(ShowList(int)));
    connect(showWidget->text->document(),SIGNAL(undoAvailable(bool)),undoAction,SLOT(setEnabled(bool)));
    connect(showWidget->text->document(),SIGNAL(redoAvailable(bool)),redoAction,SLOT(setEnabled(bool)));
    connect(showWidget->text,SIGNAL(cursorPositionChanged()),this,SLOT(ShowCursorPositionChanged()));
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

    fontToolBar = addToolBar("Font");
    fontToolBar->addWidget(fontLabel);
    fontToolBar->addWidget(fontComboBox);
    fontToolBar->addWidget(fontLabel2);
    fontToolBar->addWidget(sizeComboBox);
    fontToolBar->addSeparator();
    fontToolBar->addWidget(boldBtn);
    fontToolBar->addWidget(italicBtn);
    fontToolBar->addWidget(underlineBtn);
    fontToolBar->addSeparator();
    fontToolBar->addWidget(colorBtn);

    //排序工具条
    listToolBar = addToolBar("list");
    listToolBar->addWidget(listLabel);
    listToolBar->addWidget(listComboBox);
    listToolBar->addSeparator();
    listToolBar->addActions(actGrp->actions());
}

void MainWindow::ShowAlignment(QAction *act)
{
    if(act == leftAction)
    {
        showWidget->text->setAlignment(Qt::AlignLeft);
    }
    if(act == rightAction)
    {
        showWidget->text->setAlignment(Qt::AlignRight);
    }
    if(act == centerAction)
    {
        showWidget->text->setAlignment(Qt::AlignCenter);
    }
    if(act == justifyAction)
    {
        showWidget->text->setAlignment(Qt::AlignJustify);
    }
}

void MainWindow::ShowCursorPositionChanged()
{
    if(showWidget->text->alignment() == Qt::AlignLeft)
    {
        leftAction->setChecked(true);
    }

    if(showWidget->text->alignment() == Qt::AlignRight)
    {
        rightAction->setChecked(true);
    }

    if(showWidget->text->alignment() == Qt::AlignCenter)
    {
        centerAction->setChecked(true);
    }

    if(showWidget->text->alignment() == Qt::AlignJustify)
    {
        justifyAction->setChecked(true);
    }
}

void MainWindow::ShowFontComboBox(QString comboStr)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(comboStr);   //选择创建的字体名称设置给QTextCharFormat对象
    mergeFormat(fmt);
}

void MainWindow::mergeFormat(QTextCharFormat format)
{
    QTextCursor cursor = showWidget->text->textCursor();
    if(!cursor.hasSelection())
    {
        cursor.select(QTextCursor::WordUnderCursor);
    }
    cursor.mergeCharFormat(format);
    showWidget->text->mergeCurrentCharFormat(format);
}

void MainWindow::ShowSizeSpinBox(QString spinValue)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(spinValue.toFloat());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void MainWindow::ShowBoldBtn()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(boldBtn->isChecked()?QFont::Bold:QFont::Normal);
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void MainWindow::ShowItalicBtn()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(italicBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void MainWindow::ShowUnderlineBtn()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(underlineBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void MainWindow::ShowColorBtn()
{
    QColor color = QColorDialog::getColor(Qt::red,this);
    if(color.isValid())
    {
        QTextCharFormat fmt;
        fmt.setForeground(color);
        showWidget->text->mergeCurrentCharFormat(fmt);
    }
}

void MainWindow::ShowCurrentFormatChanged(const QTextCharFormat &fmt)
{
    fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));
    sizeComboBox->setCurrentIndex(sizeComboBox->findText(QString::number(fmt.fontPointSize())));
    boldBtn->setChecked(fmt.font().bold());
    italicBtn->setChecked(fmt.fontItalic());
    underlineBtn->setChecked(fmt.fontUnderline());
}
