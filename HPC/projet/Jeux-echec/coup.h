#ifndef COUP_H
#define COUP_H

#include "casePlateau.h"
#include "pieces.h"

class coup
{
public:
    coup(casePlateau *caseDep, casePlateau *caseArr);
    void jouerCoup();
    void getBack();

private:
    casePlateau *caseDep;
    casePlateau *caseArr;
    pieces *piecePrise;
};

#endif // COUP_H
