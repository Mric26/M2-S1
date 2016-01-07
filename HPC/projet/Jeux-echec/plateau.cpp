#include "plateau.h"

plateau::plateau(MainWindow *win){
    tab = new matrix<casePlateau *>(8, 8);
    for (int line = 0; line < 8; line++) {
        for (int column = 0; column < 8; column++) {
            if( (line+column)%2 == 0 ){
                tab->at_element(line, column) = new casePlateau(line, column, NULL, false, 0);
            }
            else{
                tab->at_element(line, column) = new casePlateau(line, column, NULL, false, 1);
            }
        }
    }
    listeJoueurBlanc = new std::vector<pieces*>;
    listeJoueurNoir = new std::vector<pieces*>;
    w = win;

    newGame();
}

bool plateau::getJoueur1() const{
    return joueur1;
}

void plateau::setJoueur1(bool value){
    joueur1 = value;
}

bool plateau::valid(int column, int line){
    return (line >= 0 && line <= 7 && column >= 0 && column <= 7);
}

casePlateau *plateau::getCase(int column, int line) {
    return tab->at_element(line, column);
}

casePlateau *plateau::getCaseKing(bool joueur1){
    std::vector< pieces* > *listPieces = getListeJoueurBlanc();
    if (!joueur1) {
        listPieces = getListeJoueurNoir();
    }
    foreach (pieces *piece, *listPieces) {
        if (piece->getName().compare("roi")) {
            return piece->getCasePiece();
        }
    }
    return NULL;
}

std::vector<pieces *> *plateau::getListeJoueurBlanc() const{
    return listeJoueurBlanc;
}

void plateau::setListeJoueurBlanc(std::vector<pieces*> *value){
    listeJoueurBlanc = value;
}

std::vector<pieces*> *plateau::getListeJoueurNoir() const{
    return listeJoueurNoir;
}

void plateau::setListeJoueurNoir(std::vector<pieces*> *value){
    listeJoueurNoir = value;
}

bool plateau::caseUnderAttackFromPlayer(bool joueur1, casePlateau *c){
    std::vector< pieces* > *listPieces = getListeJoueurBlanc();
    if (!joueur1) {
        listPieces = getListeJoueurNoir();
    }
    foreach (pieces *piece, *listPieces) {
        if (piece->caseAttaquee(c)) {
            return true;
        }
    }
    return false;
}

bool plateau::checkKing(bool joueur1){
    return caseUnderAttackFromPlayer(!joueur1, getCaseKing(joueur1));
}

bool plateau::checkMateKing(bool joueur1){
    return false;
}

bool plateau::isCoupValid(coup *c){
    bool res;
    c->jouerCoup();
    res = !checkKing(getJoueur1());
    c->getBack();
    return res;
}

int plateau::evaluation(){
    return 0;
}

void plateau::changementJoueur(){
    setJoueur1(!getJoueur1());
}

void plateau::jouerCoup(coup *c){
    // Deplace les pieces sur le plateau
    c->jouerCoup();
    // Mise a jour des listes de piece du joueur
    pieces *piece = c->getPrise();
    if (piece != NULL) {
        int pos = -1;
        if (piece->getCouleur() == 0) {
            for (unsigned int i = 0; i < listeJoueurBlanc->size() && pos == -1; ++i) {
                if (piece == listeJoueurBlanc->at(i)) {
                    pos = i;
                }
            }
            listeJoueurBlanc->erase(listeJoueurBlanc->begin() + pos);
        } else {
            for (unsigned int i = 0; i < listeJoueurNoir->size() && pos == -1; ++i) {
                if (piece == listeJoueurNoir->at(i)) {
                    pos = i;
                }
            }
            listeJoueurNoir->erase(listeJoueurNoir->begin() + pos);
        }
    }
    // Changement de joueur
    changementJoueur();
}

void plateau::getBack(coup *c){
    // Changement de joueur
    changementJoueur();
    // Replace les pieces sur le plateau
    c->getBack();
    // Mise a jour des pieces du joueur
    pieces *piece = c->getPrise();
    if (piece != NULL) {
        if (piece->getCouleur() == 0) {
            listeJoueurBlanc->push_back(piece);
        } else {
            listeJoueurNoir->push_back(piece);
        }
    }
}

void plateau::affichagePlateau(){
    QPixmap *res = new QPixmap(":images/plateau.png");

    QGraphicsItem *item;
    item = w->scene->addPixmap(*res);
    w->itemVector->push_back( item );
}

void plateau::affichagePieces(){
    foreach (pieces* p, *listeJoueurBlanc) {
        QGraphicsItem *item;
        item = w->scene->addPixmap( *(p->getRep()) );
        item->setPos(65 + p->getCasePiece()->getLine() * 80, 72 + p->getCasePiece()->getColumn() * 80 );
        w->itemVector->push_back( item );
    }

    foreach (pieces* p, *listeJoueurNoir) {
        QGraphicsItem *item;
        item = w->scene->addPixmap( *(p->getRep()) );
        item->setPos(65 + p->getCasePiece()->getLine() * 80, 72 + p->getCasePiece()->getColumn() * 80 );
        w->itemVector->push_back( item );
    }
}

void plateau::enleverPiece( casePlateau * c ){
//    std::vector<pieces*> *res = new  std::vector<pieces*>;
//    pieces p1 = c->getPiece();
//    //blanc
//    if( p1.couleur == 0 ){
//        foreach (pieces* p, *listeJoueurBlanc) {
//            if( (p->name != p1.name) ){
//                res->push_back(p);
//            }
//        }
//        listeJoueurBlanc->clear();
//        listeJoueurBlanc = res;
//    }
//    //noir
//    else{
//        foreach (pieces* p, *listeJoueurNoir) {
//            if( (p->name != p1.name) ){
//                res->push_back(p);
//            }
//        }
//        listeJoueurNoir->clear();
//        listeJoueurNoir = res;
//    }
}

void plateau::newGame(){
    casePlateau * c;

    //piece blanche
    c = tab->at_element(0,7);
    tour * tb1 = new tour(this, 0);
    tb1->setCasePiece(c);
    listeJoueurBlanc->push_back(tb1);
    c->setPiece(tb1);

    c = tab->at_element(1,7);
    cavalier * cb1 = new cavalier(this, 0);
    cb1->setCasePiece(c);
    listeJoueurBlanc->push_back(cb1);
    c->setPiece(cb1);

    c = tab->at_element(2,7);
    fou * fb1 = new fou(this, 0);
    fb1->setCasePiece(c);
    listeJoueurBlanc->push_back(fb1);
    c->setPiece(fb1);

    c = tab->at_element(3,7);
    reine * rb = new reine(this, 0);
    rb->setCasePiece(c);
    listeJoueurBlanc->push_back(rb);
    c->setPiece(rb);

    c = tab->at_element(4,7);
    roi * roib = new roi(this, 0);
    roib->setCasePiece(c);
    listeJoueurBlanc->push_back(roib);
    c->setPiece(roib);

    c = tab->at_element(5,7);
    fou * fb2 = new fou(this, 0);
    fb2->setCasePiece(c);
    listeJoueurBlanc->push_back(fb2);
    c->setPiece(fb2);

    c = tab->at_element(6,7);
    cavalier * cb2 = new cavalier(this, 0);
    cb2->setCasePiece(c);
    listeJoueurBlanc->push_back(cb2);
    c->setPiece(cb2);

    c = tab->at_element(7,7);
    tour * tb2 = new tour(this, 0);
    tb2->setCasePiece(c);
    listeJoueurBlanc->push_back(tb2);
    c->setPiece(tb2);

    for (int i = 0; i < 8; ++i) {
        c = tab->at_element(i,6);
        pion * pb = new pion(this, 0);
        pb->setCasePiece(c);
        listeJoueurBlanc->push_back(pb);
        c->setPiece(pb);
    }

    //piece noir
    c = tab->at_element(0,0);
    tour * tn1 = new tour(this, 1);
    tn1->setCasePiece(c);
    listeJoueurNoir->push_back(tn1);
    c->setPiece(tn1);

    c = tab->at_element(1,0);
    cavalier * cn1 = new cavalier(this, 1);
    cn1->setCasePiece(c);
    listeJoueurNoir->push_back(cn1);
    c->setPiece(cn1);

    c = tab->at_element(2,0);
    fou * fn1 = new fou(this, 1);
    fn1->setCasePiece(c);
    listeJoueurNoir->push_back(fn1);
    c->setPiece(fn1);

    c = tab->at_element(3,0);
    reine * rn = new reine(this, 1);
    rn->setCasePiece(c);
    listeJoueurNoir->push_back(rn);
    c->setPiece(rb);

    c = tab->at_element(4,0);
    roi * roin = new roi(this, 1);
    roin->setCasePiece(c);
    listeJoueurNoir->push_back(roin);
    c->setPiece(roin);

    c = tab->at_element(5,0);
    fou * fn2 = new fou(this, 1);
    fn2->setCasePiece(c);
    listeJoueurNoir->push_back(fn2);
    c->setPiece(fn2);

    c = tab->at_element(6,0);
    cavalier * cn2 = new cavalier(this, 1);
    cn2->setCasePiece(c);
    listeJoueurNoir->push_back(cn2);
    c->setPiece(cn2);

    c = tab->at_element(7,0);
    tour * tn2 = new tour(this, 1);
    tn2->setCasePiece(c);
    listeJoueurNoir->push_back(tn2);
    c->setPiece(tn2);


    for (int i = 0; i < 8; ++i) {
        c = tab->at_element(i,1);
        pion * pn = new pion(this, 1);
        pn->setCasePiece(c);
        listeJoueurNoir->push_back(pn);
        c->setPiece(pn);
    }

    setJoueur1(true);
}

