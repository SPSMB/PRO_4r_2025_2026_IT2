#ifndef LINKA_H
#define LINKA_H

#include "stanice.h"
#include <iostream>

class Linka
{
private:
    Stanice * l_posledni;
public:
    Linka();
    ~Linka();
    void vlozStanici(QString jmeno);
    void vypis();
    void vypis(QString jmeno);
    void odeberVse();
    Stanice * odeberStanici(Stanice * st);
    Stanice * odeberStanici(QString jmeno);
};

#endif // LINKA_H
