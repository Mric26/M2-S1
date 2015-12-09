#include "reine.h"

#include "casePlateau.h"
#include "cavalier.h"
#include "fou.h"
#include "plateau.h"

reine::reine(plateau *plat, int color):pieces(plat, QString("reine"), color){
    if (color == 0) {
        setRep(new QPixmap(":images/b2"));
    } else {
        setRep(new QPixmap(":images/n2"));
    }
}

std::vector<casePlateau *> *reine::deplacementPossible(){
    std::vector<casePlateau *> *listCase = new std::vector<casePlateau *>(0);

    return listCase;
}

bool reine::caseAttaquee(casePlateau *c){
    fou *f = new fou(p, getCouleur());
    f->setCasePiece(getCasePiece());
    tour *t = new tour(p, getCouleur());
    t->setCasePiece(getCasePiece());
    return (t->caseAttaquee(c) || f->caseAttaquee(c));
}
