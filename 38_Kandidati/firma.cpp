#include "firma.h"
#include "./ui_firma.h"

Firma::Firma(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Firma)
{
    ui->setupUi(this);

    Kandidat * k = new Kandidat("Tomas", "Zimmerhakl", 1990, ":/osoby/img/Leonard.PNG");
    pridejKandidata(k, f_novi_k, ui->lw_novi);
}

Firma::~Firma()
{
    delete ui;
}

void Firma::pridejKandidata(Kandidat *k, QQueue<Kandidat *> & fronta, QListWidget *lw)
{
    lw->addItem(k);
    fronta.enqueue(k);
    qDebug() << "Pridavam kandidata " << k->toString() << " do " << lw->objectName();
}

Kandidat * Firma::odeberKandidata(QQueue<Kandidat *> & fronta, QListWidget *lw)
{
    lw->takeItem(0);
    if(fronta.isEmpty()){
        return NULL;
    }
    Kandidat * k = fronta.dequeue();
    qDebug() << "Odebiram kandidata " << k->toString() << " z " << lw->objectName();
    return k;
}

void Firma::updateDetail(Kandidat *k)
{
    QString jmenoPrijmeni = k->k_jmeno + " " + k->k_prijmeni;
    ui->l_jmeno->setText(jmenoPrijmeni);
    ui->l_bydliste->setText(k->k_bydliste);
    ui->l_schopnosti->setText(k->k_schopnosti);
    ui->l_stav->setText(k->stav().toUpper());
    ui->l_vek->setText(QString::number(k->vek()));

    // vlozeni obrazku
    int w = ui->l_obrazek->width();
    int h = ui->l_obrazek->height();
    QPixmap pix = QPixmap(k->k_foto);
    ui->l_obrazek->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

void Firma::on_btn_n_dale_clicked()
{
    Kandidat * k = odeberKandidata(f_novi_k, ui->lw_novi);
    if(k == NULL){
        QMessageBox::warning(this, "Varovani",
                             "Nelze odebrat z prazdneho seznamu");
        return;
    }
    k->posunStav(true);
    pridejKandidata(k, f_schvaleni_k, ui->lw_schvaleni);
}


void Firma::on_btn_n_odmitnout_clicked()
{
    Kandidat * k = odeberKandidata(f_novi_k, ui->lw_novi);
    k->posunStav(false);
    pridejKandidata(k, f_zamitnuti_k, ui->lw_zamitnuti);
}


void Firma::on_btn_s_dale_clicked()
{
    Kandidat * k = odeberKandidata(f_schvaleni_k, ui->lw_schvaleni);
    k->posunStav(true);
    pridejKandidata(k, f_prijati_k, ui->lw_prijati);
}


void Firma::on_btn_s_odmitnout_clicked()
{
    Kandidat * k = odeberKandidata(f_schvaleni_k, ui->lw_schvaleni);
    k->posunStav(true);
    pridejKandidata(k, f_zamitnuti_k, ui->lw_zamitnuti);
}


void Firma::on_lw_novi_itemClicked(QListWidgetItem *item)
{
    updateDetail((Kandidat *)item);
}


void Firma::on_lw_schvaleni_itemClicked(QListWidgetItem *item)
{
    updateDetail((Kandidat *)item);
}


void Firma::on_lw_prijati_itemClicked(QListWidgetItem *item)
{
    updateDetail((Kandidat *)item);
}


void Firma::on_lw_zamitnuti_itemClicked(QListWidgetItem *item)
{
    updateDetail((Kandidat *)item);
}

