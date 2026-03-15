#include "morseovka.h"

Morseovka::Morseovka() {
    m_koren = vytvorStrom();
}

Uzel * Morseovka::vytvorStrom()
{
    return vytvorUzel(' ',
                    vytvorUzel('E',                   /* .    */
                             vytvorUzel('I',                  /* ..   */
                                      vytvorUzel('S',                 /* ...  */
                                               vytvorUzel('H',NULL,NULL),     /* .... */
                                               vytvorUzel('V',NULL,NULL)),    /* ...- */
                                      vytvorUzel('U',                 /* ..-  */
                                               vytvorUzel('F',NULL,NULL),     /* ..-. */
                                               NULL)),
                             vytvorUzel('A',                  /* .-   */
                                      vytvorUzel('R',                 /* .-.  */
                                               vytvorUzel('L',NULL,NULL),     /* .-.. */
                                               NULL),
                                      vytvorUzel('W',                 /* .--  */
                                               vytvorUzel('P',NULL,NULL),     /* .--. */
                                               vytvorUzel('J',NULL,NULL)))),  /* .--- */
                    vytvorUzel('T',                   /* -    */
                             vytvorUzel('N',                  /* -.   */
                                      vytvorUzel('D',                 /* -..  */
                                               vytvorUzel('B',NULL,NULL),     /* -... */
                                               vytvorUzel('X',NULL,NULL)),    /* -..- */
                                      vytvorUzel('K',                 /* -.-  */
                                               vytvorUzel('C',NULL,NULL),     /* -.-. */
                                               vytvorUzel('Y',NULL,NULL))),   /* -.-- */
                             vytvorUzel('M',                  /* --   */
                                      vytvorUzel('G',                 /* --.  */
                                               vytvorUzel('Z',NULL,NULL),     /* --.. */
                                               vytvorUzel('Q',NULL,NULL)),    /* --.- */
                                      vytvorUzel('O',NULL,NULL))));   /* ---  */
}

Uzel *Morseovka::vytvorUzel(char z, Uzel *t, Uzel *c)
{
    Uzel * novy = new Uzel(z, t, c);
    return novy;
}

void Morseovka::dekoduj(string &vstup, string &vystup)
{
    char z;
    unsigned int i = 0;
    Uzel * aktualni = m_koren;
    while(i < vstup.length()){
        z = vstup[i];
        if(aktualni != NULL){
            if(z == '*') aktualni = aktualni->tecka;
            else if(z == '-') aktualni = aktualni->carka;
            else {
                // vypisuji pismeno na aktualni pozici ve strome
                vystup.append(1, aktualni->znak);
                aktualni = m_koren;
            }
            i++;
        } else {
            while(z == '*' || z == '-'){
                i++;
            }
            vystup.append(1, '?');
            i++;
            aktualni = m_koren;
        }
    }
}







