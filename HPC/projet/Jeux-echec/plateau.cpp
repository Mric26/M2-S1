#include "plateau.h"

plateau::plateau(){
    tab(8, 8);
    for (int line = 0; line < 8; line++) {
        for (int column = 0; column < 8; column++) {
            if( (line+column)%2 == 0 ){
                tab(line, column) = new casePlateau(line, column, NULL, false, QColor::blue());
            }
            else{
                tab(line, column) = new casePlateau(line, column, NULL, false, QColor::black());
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

vector *plateau::getListeJoueurBlanc() const{
    return listeJoeurBlanc;
}

void plateau::setListeJoueurBlanc(const vector *value){
    listeJoeurBlanc = value;
}

vector *plateau::getListeJoueurNoir() const{
    return listeJoeurNoir;
}

void plateau::setListeJoueurNoir(const vector *value){
    listeJoeurNoir = value;
}

void plateau::newGame(){
    casePlateau c;
//    c = tab(0,0);
//    c.setPiece();
    setJoueur1(true);
}

