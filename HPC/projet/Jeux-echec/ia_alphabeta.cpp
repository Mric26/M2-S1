#include "ia_alphabeta.h"

#include "coup.h"
#include "plateau.h"

#include <vector>
#include <climits>

IA_AlphaBeta::IA_AlphaBeta(plateau *p) {
    this->p = p;
    this->bestCoup = NULL;
    this->depth = 2;
}

void IA_AlphaBeta::setDepth(unsigned int depth) {
    this->depth = depth;
}

/* Calcul du meilleur coup des noirs */
void IA_AlphaBeta::jouerAlphaBeta() {
    int value;
    int value_min = INT_MAX;
    coup *c;
    std::vector< coup* > listCoup = std::vector< coup* >(0);    // A changer (getListCoup() !)
    for (unsigned int i = 0; i < listCoup.size(); ++i) {
        c = listCoup[i];
        p->jouerCoup(c);

        value = ab_max_min(p, INT_MIN, INT_MAX, depth-1);

        p->getBack(c);

        if (value <= value_min) {
            value_min = value;
            this->bestCoup = c;
        }
    }
}

/* Calcul le meilleur coup pour les blancs */
void IA_AlphaBeta::jouerBetaAlpha() {
    int value;
    int value_max = INT_MIN;
    coup *c;
    std::vector< coup* > listCoup = std::vector< coup* >(0);    // A changer (getListCoup() !)
    for (unsigned int i = 0; i < listCoup.size(); ++i) {
        c = listCoup[i];
        p->jouerCoup(c);

        value = ab_min_max(p, INT_MIN, INT_MAX, depth-1);

        p->getBack(c);

        if (value >= value_max) {
            value_max = value;
            this->bestCoup = c;
        }
    }
}

int IA_AlphaBeta::ab_min_max(plateau *child, int alpha, int beta, unsigned int level) {

    // joueur1 == false
    if (child->checkMateKing(false)) {
        return INT_MAX;
    }
    if (level == 0) {
        return child->evaluation();
    }

    coup *c;
    std::vector< coup* > listCoup = std::vector< coup* >(0);    // A changer (getListCoup() !)
    int value;

    for (unsigned int i = 0; i < listCoup.size(); ++i) {
        c = listCoup[i];
        child->jouerCoup(c);

        value = ab_max_min(p, alpha, beta, level-1);

        child->getBack(c);

        if (value < beta) {
            beta = value;
            if (alpha > beta) {
                return beta;
            }
        }
    }

    return beta;
}

int IA_AlphaBeta::ab_max_min(plateau *child, int alpha, int beta, unsigned int level) {

    // joueur1 == true
    if (child->checkMateKing(true)) {
        return INT_MIN;
    }
    if (level == 0) {
        return child->evaluation();
    }

    coup *c;
    std::vector< coup* > listCoup = std::vector< coup* >(0);    // A changer (getListCoup() !)
    int value;

    for (unsigned int i = 0; i < listCoup.size(); ++i) {
        c = listCoup[i];
        child->jouerCoup(c);

        value = ab_min_max(p, alpha, beta, level-1);

        child->getBack(c);

        if (value > alpha) {
            alpha = value;
            if (alpha > beta) {
                return alpha;
            }
        }
    }

    return alpha;
}
