#ifndef OSOBA_H
#define OSOBA_H

#include <QString>

class Osoba
{
public:
    QString jmeno;
    int id;
    Osoba * dalsi;

    Osoba();
    Osoba(QString jmeno);
};

#endif // OSOBA_H
