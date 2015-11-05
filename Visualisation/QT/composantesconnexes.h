#ifndef COMPOSANTESCONNEXES_H
#define COMPOSANTESCONNEXES_H

#include <QImage>
#include <iostream>
#include <unistd.h>

using namespace std;

class composantesConnexes{

    class Noeud {
    public:
        Noeud(int elem);
        Noeud *parent;
        int elem;
    };

public:

    QImage *composantesConnexe(QImage *image);

//    struct noeud {
//        noeud *parent;
//        int elem;
//    };

    void imprime(vector<Noeud> &arbre);
    Noeud& findParent(Noeud& n);
    void unionNode(Noeud& n1, Noeud& n2);
    int compterVoisin(vector< vector<int> > &matrix, int x, int y);
    int mininmumVoisin(vector< vector<int> > &matrix, int x, int y);
    int get(vector< vector<int> >& matrice, int x, int y);

private:
    int imgWidth;
    int imgHeight;

};

#endif // COMPOSANTESCONNEXES_H
