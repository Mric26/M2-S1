#include "composantesconnexes.h"


int composantesConnexes::compterVoisin(vector< vector<int> > &tab, int i, int j) {
    int n = 0;
    // Parcours des 8 voisins du pixel
    for (int k = -1; k <= 1; ++k) {
        for (int l = -1; l <= 1; ++l) {
            if (k != 0 || l != 0) {
                if (i+k >= 0 && i+k < imgWidth && j+l >= 0 && j+l < imgHeight) {
                    n += (tab[i+k][j+l] != 0 ? 1 : 0);
                }
            }
        }
    }
    return n;
}

int composantesConnexes::mininmumVoisin(vector< vector<int> > &tab, int i, int j) {
    int mini = 999999999;   // Il n'y aura pas plus de 1 milliard d'objets a compter, faut pas deconner ...
    // Trouve l'etiquette la plus petite dans le voisinage
    for (int l = -1; l <= 1; ++l) {
        for (int k = -1; k <= 1; ++k) {
            if (k != 0 || l != 0) {
                if (i+k >= 0 && i+k < imgWidth && j+l >= 0 && j+l < imgHeight) {
                    if (tab[i+k][j+l] > 0 && tab[i+k][j+l] < mini) {
                        mini = tab[i+k][j+l];
                    }
                }
            }
        }
    }
    return mini;
}

composantesConnexes::noeud& composantesConnexes::findParent(noeud &nd) {
    if (nd.parent == NULL) {
        return nd;
    }
    return findParent(*nd.parent);
}

// Rattache la composante connexe n2 a n1
void composantesConnexes::unionNode(composantesConnexes::noeud &n1, composantesConnexes::noeud &n2) {
    noeud &parent1 = findParent(n1);
    noeud &parent2 = findParent(n2);
    parent2.parent = &parent1;
}



QImage *composantesConnexes::composantesConn( QImage *image ){

    imgWidth = image->width();
    imgHeight = image->height();
    QImage *res = new QImage(imgWidth, imgHeight, image->format() );

    vector< vector<int> > tab = vector< vector<int> >(imgHeight);
    for (int j = 0; j < imgHeight; ++j) {
        tab[j] = std::vector<int>(imgWidth);
    }


    vector<noeud> arbre = vector<noeud>(0);
    noeud racine;
    int etiquetteConnexe = 0;
    int n = 0;
    int r = 0;

    // Premiere passe, etiquetage des composantes
    for (int j = 0; j < imgHeight; ++j) {
        for (int i = 0; i < imgWidth; ++i) {

            r = qRed(image->pixel(i,j));
            // Si le pixel appartient a un objet
            if (r == 255) {
                n = compterVoisin(tab, i, j);
                if (n == 0) {
                    // Nouvelle composante connexe trouvee
                    etiquetteConnexe++;
                    tab[i][j] = etiquetteConnexe;
                    racine.parent = NULL;
                    racine.elem = tab[i][j];
                    arbre.push_back(racine);
                } else if (n > 0) {
                    // Etiquetage du pixel avec le voisin le plus petit
                    tab[i][j] = mininmumVoisin(tab, i, j);
                    // Trouve les numeros des deux correspondances a faire correspondre
                    int voisin1 = -1;
                    int voisin2 = -1;
                    for (int l = -1; l <= 1; ++l) {
                        for (int k = -1; k <= 1; ++k) {
                            if (k != 0 || l != 0) {
                                if (i+k >= 0 && i+k < imgWidth && j+l >= 0 && j+l < imgHeight && tab[i+k][j+l] != 0) {
                                    if (voisin1 == -1) {
                                        voisin1 = tab[i+k][j+l];
                                    }
                                    if (voisin2 == -1 && tab[i+k][j+l] != voisin1) {
                                        voisin2 = tab[i+k][j+l];
                                    }
                                }
                            }
                        }
                    }
                    // Stocker la correspondance si besoin
//                    cout << "(" << i << "," << j << ") --> " << voisin1 << " | " << voisin2 << endl;
                    if (voisin1 != -1 && voisin2 != -1) {
                        if (voisin1 > voisin2) {
                            int tmp = voisin1;
                            voisin1 = voisin2;
                            voisin2 = tmp;
                        }
                        if (&findParent(arbre.at(voisin2-1)) != &findParent(arbre.at(voisin1-1))) {
                            unionNode(arbre.at(voisin1-1), arbre.at(voisin2-1));
                        }
                    }
                }
            }

        }
    }

    // Seconde passe, re-etiquetage des equivalences (ne sert a rien ...)
    for (int j = 0; j < imgHeight; ++j) {
        for (int i = 0; i < imgWidth; ++i) {
            if (tab[i][j] != 0) {
//                cout << &arbre.at(tab[i][j]-1) << endl;
                noeud parent = findParent(arbre.at(tab[i][j]-1));
                tab[i][j] = parent.elem;
            }
        }
    }

//    for (int j = 0; j < imgHeight; ++j) {
//        for (int i = 0; i < imgWidth; ++i) {
//            cout << tab[i][j] << ", ";
//        }
//        cout << endl;
//    }

    for (int j = 0; j < imgHeight; ++j) {
        for (int i = 0; i < imgWidth; ++i) {
            if (tab[i][j] > 0) {
                res->setPixel(i, j, qRgb( 255 * (arbre.at(tab[i][j]-1).elem/((double)etiquetteConnexe)), 0, 255 - 255 * (arbre.at(tab[i][j]-1).elem/((double)etiquetteConnexe))));
            }
        }
    }
    return res;
}

