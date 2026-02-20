#include "zasobnik.h"
#include <QDebug>

Zasobnik::Zasobnik() {
    z_ukazatel = 0; // ukazuje na prvni volny prvek v poli
    z_pocatecniKapacita = 10; // pocatecni velikost pole
    z_kapacita = z_pocatecniKapacita;
    z_poleOsob = new Osoba*[z_kapacita]; // alokace
}

Zasobnik::~Zasobnik() {

    int citac = 0;
    Osoba * os;
    while(!is_empty()){
        os = pop();
        delete os;
        citac ++;
    }
    qDebug() << "Destruktor zasobnik: Odstraneno " << citac << " osob.";
    delete [] z_poleOsob;
}

void Zasobnik::push(Osoba *os)
{
    if(os == NULL){
        qDebug() << "Nelze vlozit na zasobnik prazdnou osobu";
        return;
    } else {
        kontrolujKapacitu();
        z_poleOsob[z_ukazatel] = os;
        z_ukazatel++;
        top(); // kontrolni vypis
    }
}

Osoba* Zasobnik::pop()
{
    if(is_empty()){
        qDebug() << "Nelze odebrat z prazdneho zasobniku.";
        return NULL;
    } else {
        z_ukazatel--; // snizim hodnotu ukazatele
        Osoba * odebrana = z_poleOsob[z_ukazatel];
        kontrolujKapacitu();
        top(); // kontrolni vypis
        return odebrana;
    }
}

// jenom vypise Osobu na vrcholu zasobniku a vrati ukazatel na ni
Osoba *Zasobnik::top()
{
    if(is_empty()){
        qDebug() << "TOP: Zasobnik je prazdny";
        return NULL;
    } else {
        Osoba * os = z_poleOsob[z_ukazatel-1];
        qDebug() << "TOP: " << os->id << ": " << os->jmeno;
        return os;
    }
}

bool Zasobnik::is_empty()
{
    if(z_ukazatel == 0){
        return true;
    }else{
        return false;
    }
}

QString Zasobnik::toString()
{
    QString vystup = "";
    Osoba * os;
    for(int i = z_ukazatel-1;i>=0;i--){
        os = z_poleOsob[i];
        vystup += QString::number(os->id)
        + ": " + os->jmeno + "\n";
    }
    return vystup;
}

void Zasobnik::kontrolujKapacitu()
{
    if(z_ukazatel == z_kapacita){
        zmenPole(true); // zvetseni pole
    } else if( z_ukazatel < z_kapacita*0.3 &&
               z_kapacita > z_pocatecniKapacita){
        zmenPole(false); // zmenseni pole
    }
}

// v pripade, ze zvetsit = true, tak zvetsime kapacitu 2x
// v pripade, ze zvetsit = false, tak zmensime kapacitu 2x
void Zasobnik::zmenPole(bool zvetsit)
{
    int nova_kapacita;
    if(zvetsit == true){
        nova_kapacita = z_kapacita * 2;
    } else {
        nova_kapacita = z_kapacita / 2;
    }

    qDebug() << "Realokuji pole pro zasobnik, puvodni kapacita: "
             << z_kapacita << ", nova kapacita: " << nova_kapacita;

    // 1. alokace noveho pole
    Osoba* * novePole = new Osoba * [nova_kapacita];

    // 2. kopirovani
    for(int i=z_ukazatel-1; i>=0 ;i--){
        novePole[i] = z_poleOsob[i];
    }

    // 3. odstranim stare pole
    delete [] z_poleOsob;
    // 4. ulozim adresu noveho pole
    z_poleOsob = novePole;
    // 5. opravim kapacitu
    z_kapacita = nova_kapacita;
}
