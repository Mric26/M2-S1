#include "coup.h"

coup::coup(casePlateau *caseDep, casePlateau *caseArr){
    this->caseDep = caseDep;
    this->piecePrise = caseArr->getPiece();
    this->caseArr = caseArr;
}

pieces *coup::getPrise(){
    return piecePrise;
}

void coup::jouerCoup(){
    if (piecePrise != NULL) {
        piecePrise->setCase(NULL);
    }
    caseArr->setPiece(caseDep->getPiece());
    caseDep->setPiece(NULL);
    caseArr->getPiece()->setCase(caseArr);
}

void coup::getBack(){
    if (piecePrise != NULL) {
        piecePrise->setCase(caseArr);
    }
    caseDep->setPiece(caseArr->getPiece());
    caseArr->setPiece(piecePrise);
    caseDep->getPiece()->setCase(caseDep);
}

