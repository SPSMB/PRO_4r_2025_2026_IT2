#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <QTextStream>

#include "linka.h"

using namespace std;

int main()
{
    QTextStream qtin(stdin);
    Linka l; // zakladam novou linku
    int volba;
    while(1){
        cout << "Zadejte pokyn -1: konec, 0: vloz, 1: vypis, 2: smaz\n";
        cin >> volba;
        // kontrola vstupu
        while(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nespravny vstup, zadavejte znovu\n";
            cin >> volba;
        }
        if(volba == -1){
            cout << "Konec programu\n";
            break;
        } else if(volba == 0){ // vloz novou stanici
            cout << "Zadejte jmeno nove stanice: ";
            QString jmeno;
            qtin >> jmeno;
            l.vlozStanici(jmeno);
        } else if(volba == 1){ // vypis stanici
            l.vypis();
        } else if(volba == 2){
            l.odeberVse();
        }
    }


    return 0;
}
