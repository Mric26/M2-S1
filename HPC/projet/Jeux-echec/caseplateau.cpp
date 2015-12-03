#include "caseplateau.h"

casePlateau::casePlateau(int l, int c){
    line = l;
    column = c;
    piece = NULL;
    selected = false;
}

casePlateau::casePlateau(int l, int c, pieces p){
    line = l;
    column = c;
    piece = p;
    selected = false;
}
pieces casePlateau::getPiece(){
    return piece;
}

void casePlateau::setPiece(pieces p){
    piece = p;
}

bool casePlateau::getSelected() const{
    return selected;
}

void casePlateau::setSelected(bool value){
    selected = value;
}

int casePlateau::getLine() const{
    return line;
}

void casePlateau::setLine(int value){
    line = value;
}

int casePlateau::getColumn() const{
    return column;
}

void casePlateau::setColumn(int value){
    column = value;
}

/** Retourne vrai s'il n'y a pas de piece sur la case */
bool casePlateau::caseVide() {
    return (getPiece() == NULL);
}


