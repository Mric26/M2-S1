#ifndef CAVALIER_H
#define CAVALIER_H

#include "pieces.h"

class plateau;

class cavalier : public pieces
{
public:
    cavalier(plateau *plat, int color);

    std::vector<casePlateau *> *deplacementPossible();
    bool caseAttaquee(casePlateau *c);
};

#endif // CAVALIER_H
