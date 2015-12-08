#include "ia_alphabeta.h"

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
    std::vector< coup > listCoup = std::vector< coup >(0);    // A changer (getListCoup() !)
    for (coup c : listCoup) {
        //p->jouerCoup(c);

        value = ab_max_min(p, INT_MIN, INT_MAX, depth-1);

        //p->getBack(c);

        if (value <= value_min) {
            value_min = value;
            this->bestCoup = &c;
        }
    }
}

int IA_AlphaBeta::ab_min_max(plateau *child, int alpha, int beta, unsigned int level) {

}

int IA_AlphaBeta::ab_max_min(plateau *child, int alpha, int beta, unsigned int level) {

//    if (child->chekMateKing()) {
//        return INT_MIN;
//    }
//    if (level == 0) {
//        return child->evaluation();
//    }

//    std::vector< coup* > listCoup = getCoupFromPlayer();
}
