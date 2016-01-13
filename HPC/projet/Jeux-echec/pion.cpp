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
    ////////////////////////////////////////
    /// INVERSION POSSIBLE LIGNE/COLONNE ///
    ////////////////////////////////////////

    std::vector<casePlateau *> *listCase = new std::vector<casePlateau *>(0);
    std::vector<casePlateau *> *caseJouable = new std::vector<casePlateau *>(0);

    int joueur = (getCouleur() == 0 ? 1 : -1);
    casePlateau *tmp;
    coup *cp;
    pieces *piece;

    std::vector<int> simpleStep = {-1, 1};

    // Avance normale
    if (p->valid(getColumn(), getLine()-joueur)) {
        tmp = p->getCase(getColumn(), getLine()-joueur);
        if (tmp->caseVide()) {
            caseJouable->push_back(tmp);
            tmp = p->getCase(getColumn(), getLine()-(2*joueur));
            if (getCouleur() == 0 && getLine() == 6 && tmp->caseVide()) {
                caseJouable->push_back(tmp);
            }
            if (getCouleur() == 1 && getLine() == 1 && tmp->caseVide()) {
                caseJouable->push_back(tmp);
            }
        }
    }

    // Prise normale en diagonale
    foreach (int i, simpleStep) {
        if (p->valid(getColumn()-i, getLine()-joueur)) {
            tmp = p->getCase(getColumn()-i, getLine()-joueur);
            piece = tmp->getPiece();
            if (piece != NULL && !sameColor(piece)) {
                caseJouable->push_back(tmp);
            }
        }
    }

    foreach (casePlateau *caseArr, *caseJouable) {
        cp = new coup(casePiece, caseArr);
        if (p->isCoupValid(cp)) {
            listCase->push_back(caseArr);
        }
    }

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
