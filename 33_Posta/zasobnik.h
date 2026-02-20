#ifndef ZASOBNIK_H
#define ZASOBNIK_H

#include "osoba.h"
#include <QString>

class Zasobnik
{
private:
    Osoba* * z_poleOsob; // pole ukazatelu na Osoby
    int z_ukazatel;      // ukazatel na prvni volne misto v poli
    int z_kapacita;      // aktualni kapacita zasobniku
    int z_pocatecniKapacita; // pocatecni kapacita zasobniku

public:
    Zasobnik();
    ~Zasobnik();
    void push(Osoba * os); // vlozi osobu os na zasobnik
    Osoba * pop(void);    // vytahne Osobu os ze zasobniku a vrati ukazatel na ni
    Osoba * top(void);     // jenom vypise, kdo je na vrcholu zasobniku a vrati na nej ukazatel
    bool is_empty(void);   // vraci true/false podle prazdnosti zasobniku
    QString toString();    // vraci QString pro vypis do grafickeho rozhrani

    void kontrolujKapacitu(void); // kontroluje, jestli jsme dosli na hranu velikosti pole
    void zmenPole(bool zvetsit); // zvetsi nebo zmensi pole - realokace
};

#endif // ZASOBNIK_H
