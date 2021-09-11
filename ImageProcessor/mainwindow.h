#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTextEdit>
#include <QImage>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QComboBox>
#include <QSpinBox>
#include <QToolBar>
#include <QFontComboBox>
#include "showwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createActions();
    void createMenus();
    void createToolBars();
    void loadFile(QString filename);
    void mergeFormat(QTextCharFormat);
private:
    ShowWidget *showWidget;
    QAction *openFileAction;
    QAction *NewFileAction;
    QAction *exitAction;
    QAction *copyAction;
    QAction *cutAction;
    QAction *pasteAction;
    QAction *aboutAction;
    QAction *PrintTextAction;
    QAction *PrintImageAction;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *rotate90Action;
    QAction *rotate180Action;
    QAction *rotate270Action;
    QAction *mirrorVericalAction;
    QAction *mirrorHorizontalAction;
    QAction *undoAction;
    QAction *redoAction;
    QMenu *fileMenu;
    QMenu *zoomMenu;
    QMenu *rotateMenu;
    QMenu *mirrorMenu;
    QToolBar *fileTool;
    QToolBar *zoomTool;
    QToolBar *rotateTool;
    QToolBar *mirrorTool;
    QToolBar *doToolBar;

    QImage img;

signals:
public slots:

};
#endif // MAINWINDOW_H
