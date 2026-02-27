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
    if(jmeno == ""){
        return;
    }
    Osoba * os = new Osoba(jmeno);
    p_fronta->pridej(os);
    ui->te_fronta->setText(p_fronta->toString());
    ui->le_pridej->setText("");
}


void MainWindow::on_le_pridej_returnPressed()
{
    on_btn_pridej_clicked();
}


void MainWindow::on_btn_prepazka1_clicked()
{
    // 1) vezmu z fronty toho, kdo je na rade
    Osoba * os = p_fronta->odeber();

    if(os == NULL){
        QMessageBox::warning(this, "Varovani",
            "Nelze pridat osobu k prepazce 1, protoze fronta je prazdna.");
        return;
    }

    // 2) vlozim osobu do zasobniku
    p_prepazka1->push(os);

    // 2) Vypis zasobniku do grafiky
    ui->te_prepazka1->setText(p_prepazka1->toString());

    // 3) Aktualizace grafiky fronty
    ui->te_fronta->setText(p_fronta->toString());
}

void MainWindow::on_btn_prepazka2_clicked()
{
    // 1) vezmu z fronty toho, kdo je na rade
    Osoba * os = p_fronta->odeber();

    if(os == NULL){
        QMessageBox::warning(this, "Varovani",
                             "Nelze pridat osobu k prepazce 1, protoze fronta je prazdna.");
        return;
    }

    // 2) vlozim osobu do zasobniku
    p_prepazka2->push(os);

    // 2) Vypis zasobniku do grafiky
    ui->te_prepazka2->setText(p_prepazka2->toString());

    // 3) Aktualizace grafiky fronty
    ui->te_fronta->setText(p_fronta->toString());
}

void MainWindow::on_btn_prepazka3_clicked()
{
    // 1) vezmu z fronty toho, kdo je na rade
    Osoba * os = p_fronta->odeber();

    if(os == NULL){
        QMessageBox::warning(this, "Varovani",
                             "Nelze pridat osobu k prepazce 1, protoze fronta je prazdna.");
        return;
    }

    // 2) vlozim osobu do zasobniku
    p_prepazka3->push(os);

    // 2) Vypis zasobniku do grafiky
    ui->te_prepazka3->setText(p_prepazka3->toString());

    // 3) Aktualizace grafiky fronty
    ui->te_fronta->setText(p_fronta->toString());
}


