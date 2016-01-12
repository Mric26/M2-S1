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

    casePlateau *getCaseDep();
    void setCaseDep(casePlateau *value);
    casePlateau *getCaseArr();
    void setCaseArr(casePlateau *value);

private:
    casePlateau *caseDep;
    casePlateau *caseArr;
    pieces *piecePrise;
};

#endif // COUP_H
