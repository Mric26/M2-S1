#ifndef PLATEAU_H
#define PLATEAU_H

#include <boost/numeric/ublas/matrix.hpp>
#include <vector>

#include <casePlateau.h>
#include <pieces.h>

using namespace boost::numeric::ublas;
using namespace std;

class pieces;
class casePlateau;
class plateau
{
public:
    plateau();
    bool getJoueur1() const;
    void setJoueur1(bool value);
    casePlateau* getCasePlateau(int column, int line);
    std::vector<pieces*> *getListeJoueurBlanc() const;
    void setListeJoueurBlanc(std::vector<pieces *> *value);
    std::vector<pieces*> *getListeJoueurNoir() const;
    void setListeJoueurNoir(std::vector<pieces*> *value);

private:
    matrix<casePlateau *> tab;
    bool joueur1;
    std::vector<pieces*> *listeJoueurBlanc;
    std::vector<pieces*> *listeJoueurNoir;
    void newGame();

};

#endif // PLATEAU_H
