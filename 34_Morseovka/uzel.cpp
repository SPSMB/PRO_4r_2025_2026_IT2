#include "uzel.h"
#include <cstddef>

Uzel::Uzel() {
    znak = '!';
    tecka = NULL;
    carka = NULL;
}

Uzel::Uzel(char znak_)
{
    znak = znak_;
    tecka = NULL;
    carka = NULL;
}

Uzel::Uzel(char znak_, Uzel *tecka_, Uzel *carka_)
{
    znak = znak_;
    tecka = tecka_;
    carka = carka_;
}
