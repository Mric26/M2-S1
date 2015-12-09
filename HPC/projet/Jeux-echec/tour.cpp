#include "tour.h"

#include "casePlateau.h"
#include "plateau.h"

tour::tour(plateau *plat, int color):pieces(plat, QString("tour"), color){
    if (color == 0) {
        setRep(new QPixmap(":images/b5"));
    } else {
        setRep(new QPixmap(":images/n5"));
    }
}

std::vector<casePlateau *> *tour::deplacementPossible(){
    std::vector<casePlateau *> *listCase = new std::vector<casePlateau *>(0);

    return listCase;
}

bool tour::caseAttaquee(casePlateau *c){
    int dx = c->getColumn() - getColumn();
    int dy = c->getLine() - getLine();

    // Si la tour est sur la meme ligne ou colonne que la case
    if (dx == 0 || dy == 0) {
        int sign_x = (dx > 0 ? 1 : -1);
        int sign_y = 0;
        if (dx == 0) {
            sign_x = 0;
            sign_y = (dy > 0 ? 1 : -1);
        }
        int i = 0;
        int j = 0;
        bool loop;
        casePlateau *caseAttack;
        do {
            loop = false;
            i += sign_x;
            j += sign_y;
            if (p->valid(getColumn()+i, getLine()+j)) {
                caseAttack = p->getCase(getLine()+i, getColumn()+j);
                if (caseAttack == c) {
                    return true;
                } else if (caseAttack->caseVide()) {
                    loop = true;
                }
            }
        } while (loop);
    }

    return false;
}

