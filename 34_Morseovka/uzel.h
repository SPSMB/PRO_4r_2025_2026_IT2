#ifndef UZEL_H
#define UZEL_H

class Uzel
{
public:
    char znak;
    Uzel * tecka;
    Uzel * carka;
    Uzel();
    Uzel(char znak_);
    Uzel(char znak_, Uzel * tecka_, Uzel * carka_);
};

#endif // UZEL_H
