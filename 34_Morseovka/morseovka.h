#ifndef MORSEOVKA_H
#define MORSEOVKA_H

#include "uzel.h"
#include <string>
#include <cstddef>
#include <iostream>

using namespace std;

class Morseovka
{
private:
    Uzel * m_koren;
public:
    Morseovka();
    Uzel * vytvorStrom(); // vraci ukazatel na koren
    Uzel * vytvorUzel(char z, Uzel * t, Uzel * c);
    void dekoduj(string & vstup, string & vystup);
};

#endif // MORSEOVKA_H
