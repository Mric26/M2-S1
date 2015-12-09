#ifndef REINE_H
#define REINE_H

#include <pieces.h>

class plateau;

class reine : public pieces
{
public:
    reine(plateau *plat, int color);

    std::vector<casePlateau *> *deplacementPossible();
    bool caseAttaquee(casePlateau *c);
};

#endif // REINE_H
