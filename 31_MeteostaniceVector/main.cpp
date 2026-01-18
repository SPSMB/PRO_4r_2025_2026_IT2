#include <iostream>
#include "meteostanice.h"

using namespace std;

int main()
{
    Meteostanice m;
    m.vypisVysledky();
    m.pocitejStatistiku();
    m.vypisStatistiku();
    return 0;
}
