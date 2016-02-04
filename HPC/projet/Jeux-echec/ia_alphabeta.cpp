#include "ia_alphabeta.h"
#include "coup.h"
#include "plateau.h"
#include "omp.h"

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

void IA_AlphaBeta::jouerParalleleAlphaBeta() {
    int nb_threads = 4;
    int value;
    int value_min = INT_MAX;
    std::vector< coup* > * listCoup = p->getListCoup( false );

    int taille = listCoup->size();
    taille = taille / nb_threads;

    #pragma omp parallel num_threads(nb_threads) shared(value_min)
    {
        #pragma omp critical
        {
            int min = omp_get_thread_num() * taille;
            int max = listCoup->size();
            if( (min + 2 * taille) < max ){
                max = min + taille;
            }
            for (int i = min; i < max; ++i) {
                coup* c = listCoup->at(i);
                p->jouerCoup(c);

                value = ab_max_min(p, INT_MIN, INT_MAX, depth-1);

                p->getBack(c);

                //DOIT PEUT ETRE FLUSH ICI
                if (value <= value_min) {
                    value_min = value;
                    this->bestCoup = c;
                }
            }
        }
    }

    cout << "Done!\n" << endl;
}


/* Calcul du meilleur coup des noirs */
void IA_AlphaBeta::jouerAlphaBeta() {
    int value;
    int value_min = INT_MAX;
    std::vector< coup* > * listCoup = p->getListCoup( false );
    foreach (coup *c, listCoup) {
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
    std::vector< coup* > * listCoup = p->getListCoup( true );
    foreach (coup *c, listCoup) {
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

    std::vector< coup* > listCoup = std::vector< coup* >(0);    // A changer (getListCoup() !)
    int value;

    foreach (coup *c, listCoup) {
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

    std::vector< coup* > listCoup = std::vector< coup* >(0);    // A changer (getListCoup() !)
    int value;

    foreach (coup *c, listCoup) {
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
