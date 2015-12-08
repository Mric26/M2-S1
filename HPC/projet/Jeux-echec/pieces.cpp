#include "pieces.h"

pieces::pieces( QString n, int c){
    name = n;
    couleur = c;
}

vector<casePlateau> pieces::deplacementPossible(){
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

