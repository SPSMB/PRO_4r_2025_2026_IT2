#include "linka.h"

using namespace std;


Linka::Linka() {
    l_posledni = NULL;
}

Linka::~Linka()
{
    odeberVse();
}

void Linka::vlozStanici(QString jmeno)
{
    Stanice * st = new Stanice();
    st->jmeno = jmeno;

    // kdyz je seznam prazdny
    if(l_posledni == NULL){
        st->dalsi = st;
        st->predchozi = st;
        l_posledni = st;
    } else {
        st->dalsi = l_posledni->dalsi;
        st->predchozi = l_posledni;
        l_posledni->dalsi->predchozi = st;
        l_posledni->dalsi = st;
        l_posledni = st;
    }
}

void Linka::vypis()
{
    if(l_posledni == NULL){
        cout << "Nejsou zadne stanice, seznam je prazdny.\n";
    } else {
        int citac = 0;
        Stanice * aktualni = l_posledni->dalsi; // prvni stanice
        do{
            citac++;
            cout << citac << ": " << aktualni->jmeno.toStdString() << endl;
            aktualni = aktualni->dalsi;
        }while(aktualni != l_posledni->dalsi);
    }
}

void Linka::odeberVse()
{
    int count = 0;
    Stanice * aktualni = l_posledni;
    while(aktualni != NULL){
        aktualni = odeberStanici(aktualni);
        count++;
    }
    cout << "Uspesne odebrano " << count << " stanic.\n";
}

// vraci ukazatel na posledni stanici nebo NULL, pokud uz tam
// tam zadna neni
Stanice * Linka::odeberStanici(Stanice *st)
{
    // pokus o odebrani z prazdneho seznamu
    if(l_posledni == NULL){
        cout << "Nelze nic odebrat, seznam je jiz prazdny.\n";
        return NULL;
    } else if(l_posledni == l_posledni->predchozi){
        cout << "Odebiram posledni stanici "
             << l_posledni->jmeno.toStdString() << endl;
        l_posledni = NULL;
        delete l_posledni;
        return l_posledni;
    } else {
        // pred odstranenim mam alespon 2 stanice
        if(l_posledni == st){
            l_posledni = st->predchozi;
        }
        st->dalsi->predchozi = st->predchozi;
        st->predchozi->dalsi = st->dalsi;
        cout << "Odebiram stanici " << st->jmeno.toStdString()
             << ".\n";
        delete st;
        return l_posledni;
    }
}
