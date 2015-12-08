#include "plateau.h"

plateau::plateau(){
    tab(8, 8);
    for (int line = 0; line < 8; line++) {
        for (int column = 0; column < 8; column++) {
            if( (line+column)%2 == 0 ){
                tab(line, column) = new casePlateau(line, column, NULL, false, 0);
            }
            else{
                tab(line, column) = new casePlateau(line, column, NULL, false, 1);
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

void plateau::newGame(){
//    casePlateau c;
//    c = tab(0,0);
//    c.setPiece();
    setJoueur1(true);
}

