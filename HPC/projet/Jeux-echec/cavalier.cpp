#include "cavalier.h"

#include "casePlateau.h"
#include "plateau.h"

cavalier::cavalier(plateau *plat, int color):pieces(plat, QString("cavalier"), color){
    if (color == 0) {
        setRep(new QPixmap(":images/b4"));
    } else {
        setRep(new QPixmap(":images/n4"));
    }
}

std::vector<casePlateau *> *cavalier::deplacementPossible(){
    std::vector<casePlateau *> *listCase = new std::vector<casePlateau *>(0);

    casePlateau *caseArr;
    coup *cp;
    pieces *piece;

    std::vector<int> simpleStep = {-1, 1};
    std::vector<int> doubleStep = {-2, 2};

    foreach (int i, doubleStep) {
        foreach (int j, simpleStep) {
            if (p->valid(getColumn()+i, getLine()+j)) {
                caseArr = p->getCase(getColumn()+i, getLine()+j);
                piece = caseArr->getPiece();
                if (piece == NULL || !sameColor(piece)) {
                    cp = new coup(casePiece, caseArr);
                    if (p->isCoupValid(cp)) {
                        listCase->push_back(caseArr);
                    }
                }
            }
        }
    }

    foreach (int i, simpleStep) {
        foreach (int j, doubleStep) {
            if (p->valid(getColumn()+i, getLine()+j)) {
                caseArr = p->getCase(getColumn()+i, getLine()+j);
                piece = caseArr->getPiece();
                if (piece == NULL || !sameColor(piece)) {
                    cp = new coup(casePiece, caseArr);
                    if (p->isCoupValid(cp)) {
                        listCase->push_back(caseArr);
                    }
                }
            }
        }
    }

    return listCase;
}

bool cavalier::caseAttaquee(casePlateau *c){
    casePlateau *caseAttack;

    std::vector<int> simpleStep = {-1, 1};
    std::vector<int> doubleStep = {-2, 2};

    foreach (int i, doubleStep) {
        foreach (int j, simpleStep) {
            if (p->valid(getColumn()+i, getLine()+j)) {
                caseAttack = p->getCase(getColumn()+i, getLine()+j);
                if (caseAttack->equals(c)) {
                    return true;
                }
            }
        }
    }

    foreach (int i, simpleStep) {
        foreach (int j, doubleStep) {
            if (p->valid(getColumn()+i, getLine()+j)) {
                caseAttack = p->getCase(getColumn()+i, getLine()+j);
                if (caseAttack->equals(c)) {
                    return true;
                }
            }
        }
    }

    return false;
}
