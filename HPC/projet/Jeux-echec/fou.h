#ifndef FOU_H
#define FOU_H

#include <pieces.h>

class plateau;

class fou : public pieces
{
public:
    fou(plateau *plat, int color);

    std::vector<casePlateau *> *deplacementPossible();
    bool caseAttaquee(casePlateau *c);
};

#endif // FOU_H
