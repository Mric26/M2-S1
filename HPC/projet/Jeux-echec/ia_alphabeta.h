#ifndef IA_ALPHABETA_H
#define IA_ALPHABETA_H

#include "plateau.h"
#include "coup.h"

class IA_AlphaBeta
{
public:
    IA_AlphaBeta(plateau *p);
    ~IA_AlphaBeta();

    void setDepth(unsigned int depth);
    void jouerAlphaBeta();
    void jouerBetaAlpha();

private:
    // Features
    plateau *p;
    coup *bestCoup;
    int depth;

    // Methods
    int ab_min_max(plateau *child, int alpha, int beta, unsigned int level);
    int ab_max_min(plateau *child, int alpha, int beta, unsigned int level);

};

#endif // IA_ALPHABETA_H
