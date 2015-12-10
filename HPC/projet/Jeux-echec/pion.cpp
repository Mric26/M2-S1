#include "pion.h"

#include "casePlateau.h"
#include "plateau.h"

pion::pion(plateau *plat, int color):pieces(plat, QString("pion"), color){
    if (color == 0) {
        setRep(new QPixmap(":images/b6"));
    } else {
        setRep(new QPixmap(":images/n6"));
    }
}

std::vector<casePlateau *> *pion::deplacementPossible(){
    std::vector<casePlateau *> *listCase = new std::vector<casePlateau *>(0);

    return listCase;
}

bool pion::caseAttaquee(casePlateau *c){
    casePlateau *caseAttack;
    int sign = (getCouleur() == 0 ? 1 : -1);

    if (p->valid(getColumn()-1, getLine()-sign)) {
        caseAttack = p->getCase(getColumn()-1, getLine()-sign);
        if (caseAttack->equals(c)) {
            return true;
        }
    }

    if (p->valid(getColumn()+1, getLine()-sign)) {
        caseAttack = p->getCase(getColumn()+1, getLine()-sign);
        if (caseAttack->equals(c)) {
            return true;
        }
    }

    return false;
}
