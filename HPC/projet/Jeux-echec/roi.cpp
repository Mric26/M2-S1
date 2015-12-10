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

    return listCase;
}

bool roi::caseAttaquee(casePlateau *c){
    casePlateau *caseAttack;

    int i, j;
    std::vector<int> step = std::vector<int>(0);
    step.push_back(-1);
    step.push_back(0);
    step.push_back(1);

    for (unsigned int k = 0; k < step.size(); ++k) {
        i = step[k];
        for (unsigned int l = 0; l < step.size(); ++l) {
            j = step[l];
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
