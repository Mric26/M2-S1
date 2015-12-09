#ifndef TOUR_H
#define TOUR_H

#include "pieces.h"

class tour : public pieces
{
public:
    tour(plateau *plat, int color);

    std::vector<casePlateau *> *deplacementPossible();
    bool caseAttaquee(casePlateau *c);
};

#endif // TOUR_H
