#ifndef KANDIDAT_H
#define KANDIDAT_H

#include <QListWidgetItem>

class Kandidat : public QListWidgetItem
{
public:
    QString k_jmeno;
    QString k_prijmeni;
    QString k_bydliste;
    int k_narozen;
    QString k_schopnosti;

    QString k_stav;
    QString k_foto;

    Kandidat(QString jmeno, QString prijmeni, int narozen, QString foto);
    Kandidat();

    QString toString();
    QString stav();
    void posunStav(bool rozhodnuti);
    int vek();
};

#endif // KANDIDAT_H
