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

    return listCase;
}

bool cavalier::caseAttaquee(casePlateau *c){
    casePlateau *caseAttack;

    std::vector<int> doubleStep = std::vector<int>(0);
    doubleStep.push_back(-2);
    doubleStep.push_back(2);
    std::vector<int> simpleStep = std::vector<int>(0);
    simpleStep.push_back(-1);
    simpleStep.push_back(1);

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
