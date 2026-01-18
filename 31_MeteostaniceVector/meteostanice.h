#ifndef METEOSTANICE_H
#define METEOSTANICE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <vector>

using namespace std;

class Meteostanice
{
private:
    vector< vector<int>> m_data; // 2D pole pro vysledky mereni
    int m_pocStanic; // pocet mericich meteostanic
    vector <int> m_pmvs; // pocet mereni kazde stanici
    ifstream m_f; // zdrojovy soubor, kde jsou data
    string m_zdrojovaData; // cesta ke zdrojovym datum

    int m_celkovySoucet;
    int m_celkovyPocet;
    float m_celkovyPrumer; // prumer ze vsech stanic
    vector <float> m_prumeryVeStanicich; // pole s prumery ve stanicich
    int m_nejchladnejsiStanice; // cislo nejchladnejsi stanice
    int m_nejnizsiTeplota;

public:
    Meteostanice();
    ~Meteostanice();
    void nactiData();
    int pocetRadku(); // pocet radku vstupniho souboru
    int pocetVysledku(string & radek);
    void vypisVysledky();
    void pocitejStatistiku();
    void vypisStatistiku();
};


#endif // METEOSTANICE_H
