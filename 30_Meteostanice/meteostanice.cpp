#include "meteostanice.h"

using namespace std;

Meteostanice::Meteostanice() {
    /*cout << "Kolik bude meteostanic? ";*/
    m_zdrojovaData = "../../meteo-data.txt";
    m_pocStanic = pocetRadku();
    m_pmvs = new int[m_pocStanic];
    nactiData();
}

Meteostanice::~Meteostanice()
{
    for(int r = 0; r < m_pocStanic; r++){
        delete [] m_data[r];
    }
    delete [] m_data;
}

void Meteostanice::nactiData()
{
    m_f.open(m_zdrojovaData); // oteviram soubor s daty
    // alokace 2D pole - 1. vrstva
    m_data = new int*[m_pocStanic];
    for(int r = 0; r < m_pocStanic; r++){
        cout << "Kolik bude mereni v " << r << ". stanici? ";
        int pocet;
        m_f >> pocet;
        m_pmvs[r] = pocet;
        // alokuji r-ty radek
        m_data[r] = new int[pocet];

        cout << "Zadavej namerene hodnoty, oddeluj mezerami: ";
        for(int s = 0; s < pocet; s++){
            int hodnota;
            cin >> hodnota;
            m_data[r][s] = hodnota;
        }
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
