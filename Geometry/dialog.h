#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QResizeEvent>
#include <QMoveEvent>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void updateLabel();
private:
    QLabel *xLabel;
    QLabel *xValueLabel;
    QLabel *yLabel;
    QLabel *yValueLabel;
    QLabel *FrmLabel;
    QLabel *FrmValueLabel;
    QLabel *posLabel;
    QLabel *posValueLabel;
    QLabel *geoLabel;
    QLabel *geoValueLabel;
    QLabel *widthLabel;
    QLabel *widthValueLabel;
    QLabel *heightLabel;
    QLabel *heightValueLabel;
    QLabel *rectLabel;
    QLabel *rectValueLabel;
    QLabel *sizeLabel;
    QLabel *sizeValueLabel;
    QGridLayout *mainLayout;

protected:
    void moveEvent(QMoveEvent *event);
    void resizeEvent(QMoveEvent *QResizeEvent);

};
#endif // DIALOG_H
