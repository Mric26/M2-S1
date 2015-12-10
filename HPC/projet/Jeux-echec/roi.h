#ifndef ROI_H
#define ROI_H

#include <pieces.h>

class plateau;

class roi : public pieces
{
public:
    roi(plateau *plat, int color);

    std::vector<casePlateau *> *deplacementPossible();
    bool caseAttaquee(casePlateau *c);
};

#endif // ROI_H
