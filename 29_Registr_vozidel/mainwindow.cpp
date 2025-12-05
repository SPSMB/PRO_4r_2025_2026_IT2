#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->registr->addItem("Fiat");
    for(int i = 1; i <= 10; i++){
        ui->registr->addItem(QString::number(i) + ". auto");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_registr_itemClicked(QListWidgetItem *item)
{
    // ui->l_vyber->setText(item->text());
}


void MainWindow::on_btn_odstranit_clicked()
{
    QListWidgetItem * polozka = ui->registr->takeItem(
        ui->registr->currentRow());
    if(polozka == NULL){
        return;
    }
    delete polozka;
}


void MainWindow::on_btn_prejmenovat_clicked()
{
    QString noveJmeno = QInputDialog::getText(
        this, "Prejmenovani", "Zadej nove jmeno");
    QListWidgetItem * polozka = ui->registr->currentItem();
    if(noveJmeno == ""){
        QMessageBox::warning(this, "Varovani", "Pozor, text nebyl zadan!");
    }

    QMessageBox::StandardButton btn = QMessageBox::question(this, "Dotaz",
                                                            "Skutecne chcete prejmenovat?");
    if(btn == QMessageBox::Yes){
        polozka->setText(noveJmeno);
    } else {
        QMessageBox::critical(this, "Chyba", "Pozor, polozka nebyla prejmenovana!");
    }
}


void MainWindow::on_registr_currentItemChanged(QListWidgetItem *current,
                                               QListWidgetItem *previous)
{
    if(current != NULL){
        ui->l_vyber->setText(current->text());
    } else {
        ui->l_vyber->setText("Seznam je prazdny");
    }
}

