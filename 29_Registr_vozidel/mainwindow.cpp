#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    addItem(ui->registr, "Fiat");
    QString text;
    for(int i = 1; i <= 10; i++){
        text = QString::number(i) + ". auto";
        addItem(ui->registr, text);
        //ui->registr->addItem(QString::number(i) + ". auto");
    }

    QIcon i2 = QIcon("../../img/car2.png");
    ui->registr->setIconSize(QSize(60,60));
    QListWidgetItem * item1 = new QListWidgetItem(i2, "Skoda Superb");
    ui->registr->addItem(item1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addItem(QListWidget *listWidget, QString jmeno)
{
    QIcon i1 = QIcon("../../img/car1.png");
    QListWidgetItem * polozka = new QListWidgetItem(i1, jmeno);
    listWidget->addItem(polozka);
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
        /*
        ui->l_vyber->setText(current->text());
        int sirka = ui->l_image->width();
        int vyska = ui->l_image->height();
        //QPixmap pix = current->icon().pixmap(sirka, vyska);
        //ui->l_image->setPixmap(pix.scaled(sirka, vyska, Qt::KeepAspectRatio));
        QPixmap pix = current->icon().pixmap(QSize(), QIcon::Normal, QIcon::Off);
        ui->l_image->setPixmap(
            pix.scaled(sirka, vyska, Qt::KeepAspectRatio, Qt::SmoothTransformation)
        );
        */
        ui->l_vyber->setText(current->text());
        int sirka = ui->l_image->width();
        int vyska = ui->l_image->height();

        // Získat originální pixmapu, ne tu zmenšenou ikonou
        QPixmap pix = current->icon().pixmap(QSize(), QIcon::Normal, QIcon::Off);

        // Kvalitní škálování s poměrem stran
        ui->l_image->setPixmap(
            pix.scaled(sirka, vyska, Qt::KeepAspectRatio, Qt::SmoothTransformation)
            );
    } else {
        ui->l_vyber->setText("Seznam je prazdny");
    }
    if (previous){
        previous->setBackground(QColor(0x2d2d2d));
        previous->setForeground(QColor(0xffffff));
    }
    if (current!=NULL){
        current->setBackground(Qt::yellow);
        current->setForeground(Qt::black);
    }

}


void MainWindow::on_btn_pridat_clicked()
{
    QString noveJmeno = ui->le_pridat->text();
    if(noveJmeno == ""){
        QMessageBox::critical(this, "Upozorneni",
                              "Zadal jste prazdny text, nic se neprida");
    } else {
        QString jmenoObrazku = QFileDialog::getOpenFileName(this, "Vyberte obrazek", "C:\\");
        QIcon i1 = QIcon(jmenoObrazku);
        QListWidgetItem * novaPolozka = new QListWidgetItem(i1, noveJmeno);
        ui->registr->insertItem(ui->registr->currentRow(), novaPolozka);
    }
}


void MainWindow::on_registr_itemActivated(QListWidgetItem *item)
{

}

