#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_messagebox_clicked()
{
    QMessageBox msgbox;
    msgbox.setWindowTitle("Titulek");
    msgbox.setText("Tady bude text...");
    msgbox.addButton("Pondeli", QMessageBox::NoRole);
    msgbox.addButton("Utery", QMessageBox::NoRole);
    msgbox.addButton("Patek", QMessageBox::YesRole);

    QIcon i = QIcon("E:\\SPSMB\\PRO\\2r\\Prezentace\\spsmb.jpg");
    QPixmap p = i.pixmap(225,140);

    msgbox.setIconPixmap(p);
    int btn = msgbox.exec();
    qDebug() << btn << '\n';
    if(btn == 4){
        QMessageBox::information(this, "Uspech", "spravna odpoved");
    } else {
        QMessageBox::information(this, "Chyba", "spatna odpoved");
    }

}


void MainWindow::on_btn_font_clicked()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok,QFont("Calibri", 12),
                                   this, "Vyber font");

    if(ok){
        ui->label->setFont(f);
    } else {
        QMessageBox::warning(
            this, "Pozor", "Nebyl vybran zadny font");
    }

}


void MainWindow::on_btn_getItem_clicked()
{
    bool ok;
    QStringList list = {"pondeli", "utery", "streda"};

    QString vystup = QInputDialog::getItem(this, "Titulek", "Vyber den",
                          list, 1, false, &ok);

    if(ok){
        QMessageBox::information(this, "Odpoved", vystup);
    } else {
        QMessageBox::information(this, "Odpoved", "Neuspech");
    }
}

