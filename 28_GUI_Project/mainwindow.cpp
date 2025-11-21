#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0,0,800,600);

    QLineF line1 = QLineF(0,0,100,200);
    QLineF line2 = QLineF(0,0,100,300);

    QLineF l1 = QLineF(200,100,300,200);
    QLineF l2 = QLineF(200,200,300,100);
    QLineF l3 = QLineF(200,150,300,150);

    scene->addLine(line1, QPen(QColor::fromRgb(34,255,50)));
    scene->addLine(line2, QPen(QColor::fromRgb(255,255,50)));
    scene->addLine(l1, QPen(QColor::fromRgb(255,0,0)));
    scene->addLine(l2, QPen(QColor::fromRgb(255,0,0)));
    scene->addLine(l3, QPen(QColor::fromRgb(255,0,0)));

    QGraphicsItem * item = scene->addRect(0,0,100,200,QPen(), QBrush(Qt::yellow));
    item->setPos(300,300);

    // vytvorim a vlozim letadlo
    letadlo1 = new Letadlo;
    scene->addItem(letadlo1);
    letadlo1->setPos(600,100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key pressed: " << event->key();

    if(event->key() == Qt::Key_W){
        letadlo1->setY(letadlo1->y() - 10);
    } else if(event->key() == Qt::Key_S){
        letadlo1->setY(letadlo1->y() + 10);
    } else if(event->key() == Qt::Key_A){
        letadlo1->setX(letadlo1->x() - 10);
    } else if(event->key() == Qt::Key_D){
        letadlo1->setX(letadlo1->x() + 10);
    }

    qDebug() << "Scene width: " << scene->width();
}
