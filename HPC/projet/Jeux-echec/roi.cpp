#include "roi.h"

#include "casePlateau.h"
#include "plateau.h"

roi::roi(plateau *plat, int color):pieces(plat, QString("roi"), color){
    if (color == 0) {
        setRep(new QPixmap(":images/b1"));
    } else {
        setRep(new QPixmap(":images/n1"));
    }
}

std::vector<casePlateau *> *roi::deplacementPossible(){
    std::vector<casePlateau *> *listCase = new std::vector<casePlateau *>(0);

    casePlateau *caseArr;
    coup *cp;
    pieces *piece;

    std::vector<int> simpleStep = {-1, 0, 1};

    // Parcours des 8 cases adjacentes
    foreach (int i, simpleStep) {
        foreach (int j, simpleStep) {
            if ((i != 0 || j != 0) && p->valid(getColumn()+i, getLine()+j)) {
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

bool roi::caseAttaquee(casePlateau *c){
    casePlateau *caseAttack;

    std::vector<int> simpleStep = {-1, 0, 1};

    foreach (int i, simpleStep) {
        foreach (int j, simpleStep) {
            if ((i != 0 || j != 0) && p->valid(getColumn()+i, getLine()+j)) {
                caseAttack = p->getCase(getColumn()+i, getLine()+j);
                if (caseAttack->equals(c)) {
                    return true;
                }
            }
        }
    }

    return false;
}
