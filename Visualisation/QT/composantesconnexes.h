#ifndef COMPOSANTESCONNEXES_H
#define COMPOSANTESCONNEXES_H

#include <QImage>
#include <iostream>
#include <unistd.h>

class composantesConnexes{

public:

    QImage *composantesConn(QImage *image);

    struct noeud {
        noeud *parent;
        int elem;
    };

    noeud& findParent(noeud &n);
    void unionNode(noeud &n1, noeud &n2);
    int compterVoisin(vector< vector<int> > &tab, int i, int j);

private:
    int imgWidth;
    int imgHeight;

};

#endif // COMPOSANTESCONNEXES_H
