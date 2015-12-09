#include "casePlateau.h"

#include "pieces.h"

casePlateau::casePlateau(int l, int c){
    line = l;
    column = c;
    piece = NULL;
    selected = false;
}

casePlateau::casePlateau(int l, int c, pieces *p, bool s, int co){
    line = l;
    column = c;
    piece = p;
    selected = s;
    couleur = co;
}

pieces* casePlateau::getPiece(){
    return piece;
}

void casePlateau::setPiece(pieces* p){
    piece = p;
}

bool casePlateau::getSelected(){
    return selected;
}

void casePlateau::setSelected(bool value){
    selected = value;
}

int casePlateau::getLine(){
    return line;
}

void casePlateau::setLine(int value){
    line = value;
}

int casePlateau::getColumn(){
    return column;
}

void casePlateau::setColumn(int value){
    column = value;
}

/** Retourne vrai s'il n'y a pas de piece sur la case */
bool casePlateau::caseVide() {
    return (getPiece() == NULL);
}

bool casePlateau::equals(casePlateau *c){
    return (column == c->getColumn() && line == c->getLine());
}


