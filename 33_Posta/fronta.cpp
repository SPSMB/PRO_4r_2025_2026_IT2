#include "fronta.h"
#include <QDebug>

Fronta::Fronta() {
    f_prvni = NULL;
    f_posledni = NULL;
    f_citac = 0;
}

Fronta::~Fronta()
{
    qDebug() << "Vola se destruktor fronty";
    Osoba * os;
    int citac = 0;
    while(!je_prazdna()){
        os = odeber();
        delete os;
        citac ++;
    }
    qDebug() << "Destruktor: odstraneno " << citac << "osob";
}

void Fronta::pridej(Osoba * nova)
{
    if(je_prazdna()){
        f_prvni = nova;
        f_posledni = f_prvni;
    } else {
        f_posledni->dalsi = nova;
        f_posledni = nova;
    }
    nova->dalsi = NULL;
    f_citac++;
    nova->id = f_citac;
    prvni(); // vypis prvniho
    posledni(); // vypis posledniho
}

Osoba * Fronta::odeber()
{
    if(je_prazdna()){
        qDebug() << "Fronta je prazdna, nelze odebrat";
        return NULL;
    } else {
        Osoba * odebrana = f_prvni;
        if(f_prvni == f_posledni){
            // kdyz je ve fronte je 1 clovek
            f_posledni = NULL;
        }
        f_prvni = f_prvni->dalsi;
        return odebrana;
    }
    prvni(); // vypis prvniho
    posledni(); // vypis posledniho
}

Osoba *Fronta::prvni()
{
    if(!je_prazdna()){
        qDebug() << "Prvni je " << f_prvni->id << ": "
                 << f_prvni->jmeno;
    } else {
        qDebug() << "Fronta je prazdna.";
    }
    return f_prvni;
}

Osoba *Fronta::posledni()
{
    if(!je_prazdna()){
        qDebug() << "Posledni je "<< f_posledni->id << ": "
                 << f_posledni->jmeno;
    } else {
        qDebug() << "Fronta je prazdna.";
    }
    return f_posledni;
}

// vraci true, pokud je fronta prazdna, jinak false
bool Fronta::je_prazdna()
{
    if(f_prvni == NULL && f_posledni == NULL){
        return true;
    } else {
        return false;
    }
}

QString Fronta::toString()
{
    QString vystup = "";
    Osoba * os = f_prvni;
    while(os != NULL){
        vystup += QString::number(os->id)
                  + ": " + os->jmeno + "\n";
        os = os->dalsi;
    }
    return vystup;
}


