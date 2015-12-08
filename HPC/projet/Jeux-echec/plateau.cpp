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

void plateau::jouerCoup(coup *c){

}

void plateau::getBack(coup *c){

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

