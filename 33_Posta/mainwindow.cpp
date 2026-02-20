#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p_fronta = new Fronta();
    p_prepazka1 = new Zasobnik();
    p_prepazka2 = new Zasobnik();
    p_prepazka3 = new Zasobnik();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete p_fronta;
    delete p_prepazka1;
    delete p_prepazka2;
    delete p_prepazka3;
}

void MainWindow::on_btn_pridej_clicked()
{
    QString jmeno = ui->le_pridej->text();
    Osoba * os = new Osoba(jmeno);
    p_fronta->pridej(os);
    ui->te_fronta->setText(p_fronta->toString());
    ui->le_pridej->setText("");
}

