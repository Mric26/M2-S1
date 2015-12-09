#ifndef PION_H
#define PION_H

#include <pieces.h>

class plateau;

class pion : public pieces
{
public:
    pion(plateau *plat, int color);

    std::vector<casePlateau *> *deplacementPossible();
    bool caseAttaquee(casePlateau *c);
};

#endif // PION_H
