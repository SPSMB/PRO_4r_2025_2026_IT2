#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "letadlo.h"
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void obsluhaCasovace();
    void kolizeAutomobilu();
    void restart();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    Letadlo * letadlo1;
    QTimer * timer1;
    QTimer * timer2;
    QGraphicsRectItem * automobil1;
    QGraphicsRectItem * automobil2;
    QGraphicsRectItem * automobil3;
private slots:
    void keyPressEvent(QKeyEvent * event);
    void on_btn_tlacitko1_clicked();
    void on_btn_color_clicked();
};
#endif // MAINWINDOW_H
