#include "coup.h"

#include "casePlateau.h"
#include <iostream>

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
        piecePrise->setCasePiece(NULL);
    }
    caseArr->setPiece(caseDep->getPiece());
    caseDep->setPiece(NULL);
    caseArr->getPiece()->setCasePiece(caseArr);
}

void coup::getBack(){
    if (piecePrise != NULL) {
        piecePrise->setCasePiece(caseArr);
    }
    caseDep->setPiece(caseArr->getPiece());
    caseArr->setPiece(piecePrise);
    caseDep->getPiece()->setCasePiece(caseDep);
}

casePlateau *coup::getCaseDep(){
    return caseDep;
}

void coup::setCaseDep(casePlateau *value){
    caseDep = value;
}

casePlateau *coup::getCaseArr(){
    return caseArr;
}

void coup::setCaseArr(casePlateau *value){
    caseArr = value;
}



