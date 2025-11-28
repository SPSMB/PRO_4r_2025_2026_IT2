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

    // casovac
    timer1 = new QTimer;
    timer1->setInterval(16);
    connect(timer1, &QTimer::timeout, this, &MainWindow::obsluhaCasovace);
    timer1->start();

    timer2 = new QTimer;
    timer2->setInterval(5000);
    connect(timer2, &QTimer::timeout, this, &MainWindow::restart);
    timer2->start();

    //automobil
    automobil1 = scene->addRect(0,0,100,100,QPen(), QBrush(Qt::green));
    automobil2 = scene->addRect(0,150,100,100,QPen(), QBrush(Qt::blue));
    automobil3 = scene->addRect(300,450,100,100,QPen(), QBrush(QColor(0xf5a442)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::obsluhaCasovace()
{
    automobil1->setPos(automobil1->x()+0.16, automobil1->y());
    automobil2->setPos(automobil2->x()+0.32, automobil2->y());
    automobil3->setPos(automobil3->x(), automobil3->y()-0.48);

    if(automobil3->x() > 500 || automobil3->collidesWithItem(letadlo1)){
        timer1->stop();
    }
    if(automobil2->collidesWithItem(automobil3)){
        kolizeAutomobilu();
    }
}

void MainWindow::kolizeAutomobilu()
{
    automobil2->setBrush(QBrush(Qt::white));
    automobil3->setBrush(QBrush(Qt::white));
    timer1->stop();
}

void MainWindow::restart()
{
    automobil1->setPos(0,0);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QString text;
    text.append("Key pressed: ");
    text.append(QString::number(event->key()));
    // text.append(event->text());

    qDebug() << text;
    ui->console->append(text);

    if(event->key() == Qt::Key_W){
        letadlo1->setY(letadlo1->y() - 10);
    } else if(event->key() == Qt::Key_S){
        letadlo1->setY(letadlo1->y() + 10);
    } else if(event->key() == Qt::Key_A){
        letadlo1->setX(letadlo1->x() - 10);
    } else if(event->key() == Qt::Key_D){
        if(letadlo1->x() + letadlo1->width() <= ui->graphicsView->width()-10){
            letadlo1->setX(letadlo1->x() + 10);
        }
    }

    qDebug() << "Scene width: " << scene->width();
}

void MainWindow::on_btn_tlacitko1_clicked()
{
    qDebug() << "Tlacitko bylo zmacknuto.";
    ui->console->append("Tlacitko bylo zmacknuto.");
}


void MainWindow::on_btn_color_clicked()
{
    static bool checked = true;
    QPalette p = ui->console->palette();
    letadlo1->setColor(QColor(0xFF0000));

    if(checked){
        p.setColor(QPalette::Base, Qt::white);
        p.setColor(QPalette::Text, Qt::black);
        checked = false;
    } else {
        p.setColor(QPalette::Base, Qt::black);
        p.setColor(QPalette::Text, Qt::white);
        checked = true;
    }

    ui->console->setPalette(p);
}

