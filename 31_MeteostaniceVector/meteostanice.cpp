#include "meteostanice.h"

using namespace std;

Meteostanice::Meteostanice() {
    /*cout << "Kolik bude meteostanic? ";*/
    m_zdrojovaData = "../../meteo-data.txt";
    m_pocStanic = pocetRadku();
    cout << "Nacetl jsem " << m_pocStanic << " radku." << endl;
    nactiData();

    m_celkovySoucet = 0;
    m_celkovyPocet = 0;
    m_celkovyPrumer = 0; // prumer ze vsech stanic
    m_nejchladnejsiStanice = 0; // cislo nejchladnejsi stanice
    m_nejnizsiTeplota = numeric_limits<int>::max(); // nutne includovat <limits>
}

Meteostanice::~Meteostanice()
{
}

void Meteostanice::nactiData()
{
    m_f.open(m_zdrojovaData); // oteviram soubor s daty
    // alokace 2D pole - 1. vrstva
    for(int r = 0; r < m_pocStanic; r++){
        string radek;
        getline(m_f, radek);
        int pocet = pocetVysledku(radek);
        m_pmvs.push_back(pocet);

        // alokuji r-ty radek
        vector <int> radekDat;

        stringstream s2(radek);
        for(int s = 0; s < pocet; s++){
            int tmp;
            s2 >> tmp;
            radekDat.push_back(tmp);
        }
        m_data.push_back(radekDat);
    }
    m_f.close();
}

// funkce vraci pocet radku v souboru
int Meteostanice::pocetRadku()
{
    m_f.open(m_zdrojovaData);
    if(!m_f.is_open()){
        cout << "Pozor! Soubor se vstupnimi daty";
        cout << " se nepovedlo otevrit." << endl;
        return 0;
    }
    int pocet = 0;
    string radek;
    while(getline(m_f, radek)){
        pocet++;
    }
    m_f.close();
    return pocet;
}

// vrati pocet hodnot v jednom radku zdrojoveho souboru
int Meteostanice::pocetVysledku(string &radek)
{
    int pocet = 0;
    int tmp;
    stringstream s(radek);
    while(s >> tmp){
        pocet++;
    }
    return pocet;
}

void Meteostanice::vypisVysledky()
{
    cout << "________________________________________" << endl;
    cout << "Vypis namerenych dat ve vsech stanicich:" << endl;
    for(int x = 0; x<m_pocStanic; x++ ){
        cout << x <<": ";
        for(int y = 0; y< m_pmvs[x]; y++){

            cout << m_data[x][y] << ",";
        }
        cout << endl;
    }
}

void Meteostanice::pocitejStatistiku()
{
    for(int r=0; r < m_pocStanic; r++){
        int soucet = 0;
        for(int s=0; s < m_pmvs[r]; s++){
            soucet+=m_data[r][s];
            m_celkovySoucet+=m_data[r][s];
            if(m_data[r][s] < m_nejnizsiTeplota){
                m_nejchladnejsiStanice = r;
                m_nejnizsiTeplota = m_data[r][s];
            }
        }
        m_prumeryVeStanicich.push_back((float)soucet/m_pmvs[r]);
        m_celkovyPocet += m_pmvs[r];
    }
    m_celkovyPrumer = (float)m_celkovySoucet/m_celkovyPocet;
}

void Meteostanice::vypisStatistiku()
{
    cout << "_______________________" << endl;
    cout << "Statistiky" << endl;

    cout << "Nejchladnejsi stanice je cislo "
         << m_nejchladnejsiStanice << " s teplotou "
         << m_nejnizsiTeplota << "." << endl;

    cout << "Celkovy prumer je " << m_celkovyPrumer << endl;

    cout << "Prumery ve stanicich:" << endl;
    for(int i=0; i < m_pocStanic; i++){
        cout << "St: " << i << ", prumer: "
             << m_prumeryVeStanicich[i] << endl;
    }
}
