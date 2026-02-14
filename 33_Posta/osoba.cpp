#include "osoba.h"

Osoba::Osoba() {
    jmeno = "";
    id = 0;
    dalsi = NULL;
}

Osoba::Osoba(QString jmeno)
{
    this->jmeno = jmeno;
    id = 0;
    dalsi = NULL;
}
