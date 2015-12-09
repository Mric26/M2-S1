#include "fou.h"

#include "casePlateau.h"
#include "plateau.h"

#include <cmath>

fou::fou(plateau *plat, int color):pieces(plat, QString("fou"), color){
    if (color == 0) {
        setRep(new QPixmap(":images/b3"));
    } else {
        setRep(new QPixmap(":images/n3"));
    }
}

std::vector<casePlateau *> *fou::deplacementPossible(){
    std::vector<casePlateau *> *listCase = new std::vector<casePlateau *>(0);

    return listCase;
}

bool fou::caseAttaquee(casePlateau *c){
    int dx = c->getColumn() - getColumn();
    int dy = c->getLine() - getLine();

    // Si le fou est dans une meme diagonale
    if (abs(dx) == abs(dy)) {
        int sign_x = (dx > 0 ? 1 : -1);
        int sign_y = (dy > 0 ? 1 : -1);
        int i = 0;
        int j = 0;
        bool loop;
        casePlateau *caseAttack;
        do {
            loop = false;
            i += sign_x;
            j += sign_y;
            if (p->valid(getColumn()+i, getLine()+j)) {
                caseAttack = p->getCase(getColumn()+i, getLine()+j);
                if (caseAttack->equals(c)) {
                    return true;
                } else if (caseAttack->caseVide()) {
                    loop = true;
                }
            }
        } while (loop);
    }

    return false;
}
