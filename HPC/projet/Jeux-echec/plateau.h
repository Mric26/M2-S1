#ifndef PLATEAU_H
#define PLATEAU_H

#include <boost/numeric/ublas/matrix.hpp>
#include <vector>

#include <caseplateau.h>
#include <pieces.h>

using namespace boost::numeric::ublas;
using namespace std;

class plateau
{
public:
    plateau();
    bool getJoueur1() const;
    void setJoueur1(bool value);
    vector *getListeJoueurBlanc() const;
    void setListeJoueurBlanc(const vector *value);
    vector *getListeJoueurNoir() const;
    void setListeJoueurNoir(const vector *value);

private:
    matrix<casePlateau> tab;
    bool joueur1;
    vector *listeJoueurBlanc;
    vector *listeJoueurNoir;
    void newGame();

};

#endif // PLATEAU_H
