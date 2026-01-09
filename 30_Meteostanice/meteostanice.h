#ifndef METEOSTANICE_H
#define METEOSTANICE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Meteostanice
{
private:
    int* * m_data; // 2D pole pro vysledky mereni
    int m_pocStanic; // pocet mericich meteostanic
    int * m_pmvs; // pocet mereni kazde stanici
    ifstream m_f; // zdrojovy soubor, kde jsou data
    string m_zdrojovaData; // cesta ke zdrojovym datum
public:
    Meteostanice();
    ~Meteostanice();
    void nactiData();
    int pocetRadku(); // pocet radku vstupniho souboru
    int pocetVysledku(string & radek);
    void vypisVysledky();
};

inline int Meteostanice::pocetVysledku(string &radek)
{

}

#endif // METEOSTANICE_H
