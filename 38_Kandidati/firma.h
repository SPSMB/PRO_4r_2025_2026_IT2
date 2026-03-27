#ifndef FIRMA_H
#define FIRMA_H

#include <QMainWindow>
#include <QQueue>
#include "kandidat.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class Firma;
}
QT_END_NAMESPACE

class Firma : public QMainWindow
{
    Q_OBJECT

public:
    Firma(QWidget *parent = nullptr);
    ~Firma();

    void pridejKandidata(Kandidat * k, QQueue<Kandidat *> &fronta, QListWidget * lw);
    Kandidat * odeberKandidata(QQueue<Kandidat *> &fronta, QListWidget * lw);
    void updateDetail(Kandidat * k);

private slots:
    void on_btn_n_dale_clicked();

    void on_btn_n_odmitnout_clicked();

    void on_btn_s_dale_clicked();

    void on_btn_s_odmitnout_clicked();

    void on_lw_novi_itemClicked(QListWidgetItem *item);

    void on_lw_schvaleni_itemClicked(QListWidgetItem *item);

    void on_lw_prijati_itemClicked(QListWidgetItem *item);

    void on_lw_zamitnuti_itemClicked(QListWidgetItem *item);

private:
    Ui::Firma *ui;
    QQueue<Kandidat *> f_novi_k;
    QQueue<Kandidat *> f_prijati_k;
    QQueue<Kandidat *> f_schvaleni_k;
    QQueue<Kandidat *> f_zamitnuti_k;
};
#endif // FIRMA_H
