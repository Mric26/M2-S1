#ifndef IA_ALPHABETA_H
#define IA_ALPHABETA_H

#include "plateau.h"
#include "coup.h"

class IA_AlphaBeta
{
public:
    IA_AlphaBeta(Plateau *p);
    ~IA_AlphaBeta();

    void setDepth(unsigned int depth);
    void jouerAlphaBeta();

private:
    // Features
    Plateau *p;
    coup *bestCoup;
    int depth;

    // Methods
    void ab_min_max(Plateau *child, int alpha, int beta, unsigned int level);
    void ab_max_min(Plateau *child, int alpha, int beta, unsigned int level);

};

#endif // IA_ALPHABETA_H
