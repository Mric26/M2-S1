#ifndef PLATEAU_H
#define PLATEAU_H

#include <boost/numeric/ublas/matrix.hpp>
#include <vector>
#include <QPainter>

#include <casePlateau.h>
#include <coup.h>
#include <pieces.h>
#include <roi.h>
#include <reine.h>
#include <fou.h>
#include <cavalier.h>
#include <tour.h>
#include <pion.h>

using namespace boost::numeric::ublas;
using namespace std;

class pieces;
class casePlateau;

class plateau
{
public:
    plateau(QPainter *p);
    bool getJoueur1() const;
    void setJoueur1(bool value);
    bool valid(int column, int line);
    casePlateau *getCase(int column, int line);
    casePlateau *getCaseKing(bool joueur1);
    std::vector<pieces*> *getListeJoueurBlanc() const;
    void setListeJoueurBlanc(std::vector<pieces *> *value);
    std::vector<pieces*> *getListeJoueurNoir() const;
    void setListeJoueurNoir(std::vector<pieces*> *value);

    bool caseUnderAttackFromPlayer(bool joueur1, casePlateau *c);
    bool checkKing(bool joueur1);
    bool checkMateKing(bool joueur1);   // A faire
    bool isCoupValid(coup *c);

    int evaluation();

    QPixmap* affichagePlateau();
    void changementJoueur();
    void jouerCoup(coup *c);
    void getBack(coup*c);
    void newGame();
    void affichagePieces();

private:
    matrix<casePlateau *> * tab;
    bool joueur1;
    std::vector<pieces*> *listeJoueurBlanc;
    std::vector<pieces*> *listeJoueurNoir;
    QPainter * painter;

};

#endif // PLATEAU_H
