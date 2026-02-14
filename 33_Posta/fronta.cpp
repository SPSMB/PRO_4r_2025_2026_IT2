#include "fronta.h"
#include <QDebug>

Fronta::Fronta() {
    f_prvni = NULL;
    f_posledni = NULL;
    f_citac = 0;
}

Fronta::~Fronta()
{
    qDebug() << "Vola se destruktor";
    Osoba os;
    while(!je_prazdna()){
        os = odeber();
        delete os;
    }
}

void Fronta::pridej(Osoba * nova)
{
    if(je_prazdna()){
        f_prvni = nova;
        f_posledni = f_prvni;
    } else {
        f_posledni = nova;
        f_posledni->dalsi = nova;
    }
    nova->dalsi = NULL;
    f_citac++;
    nova->id = f_citac;
}


