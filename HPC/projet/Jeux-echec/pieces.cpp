#include "pieces.h"

#include "casePlateau.h"
#include "plateau.h"

pieces::pieces(plateau *plat, QString n, int c){
    name = n;
    couleur = c;
    p = plat;
}

int pieces::getLine(){
    if (casePiece == NULL) {
        return -1;
    }
    return casePiece->getLine();
}

int pieces::getColumn(){
    if (casePiece == NULL) {
        return -1;
    }
    return casePiece->getColumn();
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
