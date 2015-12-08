#include "plateau.h"

plateau::plateau(){
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
    newGame();
}

bool plateau::getJoueur1() const{
    return joueur1;
}

void plateau::setJoueur1(bool value){
    joueur1 = value;
}

casePlateau *plateau::getCasePlateau(int column, int line) {
    return tab->at_element(line, column);
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

void plateau::changementJoueur(){
    if (getJoueur1()) {
        setJoueur1(false);
    } else {
        setJoueur1(true);
    }
}

void plateau::jouerCoup(coup *c){
    // Deplace les pieces sur le plateau
    c->jouerCoup();
    // Mise a jour des listes de piece du joueur
//    pieces *piece = c->getPrise();
//    if (piece != NULL) {
//        int pos = -1;
//        if (piece->getCouleur() == 0) {
//            for (unsigned int i = 0; i < listeJoueurBlanc->size() && pos == -1; ++i) {
//                if (piece == listeJoueurBlanc->at(i)) {
//                    pos = i;
//                }
//            }
//            listeJoueurBlanc->erase(listeJoueurBlanc->begin() + pos);
//        } else {
//            for (unsigned int i = 0; i < listeJoueurNoir->size() && pos == -1; ++i) {
//                if (piece == listeJoueurNoir->at(i)) {
//                    pos = i;
//                }
//            }
//            listeJoueurNoir->erase(listeJoueurNoir->begin() + pos);
//        }
//    }
    // Changement de joueur
    changementJoueur();
}

void plateau::getBack(coup *c){
    // Changement de joueur
    changementJoueur();
    // Replace les pieces sur le plateau
    c->getBack();
    // Mise a jour des pieces du joueur
//    pieces *piece = c->getPrise();
//    if (piece != NULL) {
//        if (piece->getCouleur() == 0) {
//            listeJoueurBlanc->push_back(piece);
//        } else {
//            listeJoueurNoir->push_back(piece);
//        }
//    }
}

QPainter *plateau::getPainter(){
    return painter;
}

void plateau::setPainter(QPainter *value){
    painter = value;
}

QPixmap *plateau::affichagePlateau(){
    QPixmap *res = new QPixmap(":images/plateau.png");
    return res;
}

void plateau::newGame(){

//    casePlateau * c = tab->at_element(0,0);
//    tour * tb = new tour(0);
//    tb->setCase(c);
//    listeJoueurBlanc->push_back(tb);
//    c->setPiece( tb );

//    setJoueur1(true);
}

void plateau::affichagePieces(){
//    foreach (pieces* p, *listeJoueurBlanc) {

//    }
}

