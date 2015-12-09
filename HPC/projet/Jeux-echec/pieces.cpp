#include "pieces.h"

pieces::pieces( QString n, int c){
    name = n;
    couleur = c;
}

vector<casePlateau> pieces::deplacementPossible(){
}

bool pieces::caseAttaquee(casePlateau *c){
    return false;
}

QString pieces::getName(){
    return name;
}

void pieces::setName(QString &value){
    name = value;
}


int pieces::getCouleur(){
    return couleur;
}

void pieces::setCouleur(int value){
    couleur = value;
}


casePlateau *pieces::getCasePiece(){
    return casePiece;
}

void pieces::setCasePiece(casePlateau *value){
    casePiece = value;
}

QPixmap *pieces::getRep(){
    return rep;
}

void pieces::setRep(QPixmap *value){
    rep = value;
}

void pieces::setCase(casePlateau *casePiece){
    this->casePiece = casePiece;
}

