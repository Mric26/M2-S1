#ifndef COUP_H
#define COUP_H

#include "pieces.h"

class casePlateau;

class coup
{
public:
    coup(casePlateau *caseDep, casePlateau *caseArr);
    pieces* getPrise();
    void jouerCoup();
    void getBack();

private:
    casePlateau *caseDep;
    casePlateau *caseArr;
    pieces *piecePrise;
};

#endif // COUP_H
