#include "kandidat.h"

Kandidat::Kandidat(QString jmeno, QString prijmeni, int narozen, QString foto)
{
    k_jmeno = jmeno;
    k_prijmeni = prijmeni;
    k_narozen = narozen;
    this->setText(toString());
    k_foto = foto;

    k_stav = "novy";
}

Kandidat::Kandidat() {}

QString Kandidat::toString()
{
    QString vystup = k_jmeno + " " + k_prijmeni + " (" +
                     QString::number(2026 - k_narozen) + ")";
    return vystup;
}

QString Kandidat::stav()
{
    return k_stav;
}

void Kandidat::posunStav(bool rozhodnuti)
{
    if(rozhodnuti == false){
        k_stav = "zamitnut";
        return;
    } else {
        if(k_stav == "novy"){
            k_stav = "schvalen";
        } else if(k_stav == "schvalen"){
            k_stav = "prijat";
        }
    }
}

int Kandidat::vek()
{
    return 2026 - k_narozen;
}
