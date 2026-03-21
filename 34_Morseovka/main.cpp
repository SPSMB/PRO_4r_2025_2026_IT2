#include <iostream>
#include <string.h>
#include "morseovka.h"

using namespace std;

int main()
{
    string vstup;
    string vystup;
    Morseovka m;

    cout << "Zadej text v morseovce, pro ukonceni zadej 0." << endl;
    cin >> vstup;
    while(true){
        if(vstup == ""){
            cin >> vstup;
        }
        if(vstup == "0") break;
        m.dekoduj(vstup, vystup);
        cout << vystup << endl;
        vstup = vystup = "";
    }
    return 0;
}
