#ifndef IA_ALPHABETA_H
#define IA_ALPHABETA_H

class coup;
class plateau;

class IA_AlphaBeta
{
public:
    IA_AlphaBeta(plateau *p);
    ~IA_AlphaBeta();

    void setDepth(unsigned int depth);
    void jouerAlphaBeta();
    void jouerBetaAlpha();

    void jouerParalleleAlphaBeta();   
    void jouerMultiprocessAlphaBeta();
    void HW();

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
