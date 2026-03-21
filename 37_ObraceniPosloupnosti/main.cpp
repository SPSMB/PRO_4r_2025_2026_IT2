#include <iostream>

using namespace std;

// Uzivatel zada posloupnost
// Program ji vypise v opacnem poradi

void obrat(){
    int x;
    // 1. krok - precti cislo
    cin >> x;
    // 2. krok - kdyz neni 0, obrat
    if(x != 0) {
        obrat();
        // 3. krok - vypis
        cout << x << " ";
    }
}

int main()
{
    cout << "Zadavej cisla, 0 pro ukonceni:" << endl;
    obrat();
    return 0;
}
