#include "pieces.h"

pieces::pieces( QString n, int c){
    name = n;
    couleur = c;
}

vector<casePlateau> pieces::deplacementPossible(){
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

