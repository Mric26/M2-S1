#include "composantesconnexes.h"
#include <stdlib.h>

// Compte le nombre de voisin du pixel (i, j)
int composantesConnexes::compterVoisin(vector< vector<int> > &matrix, int i, int j) {
    int n = 0;
    // Parcours des 8 voisins du pixel
    for (int l = -1; l <= 1; ++l) {
        for (int k = -1; k <= 1; ++k) {
            if (k != 0 || l != 0) {
                if (i+k >= 0 && i+k < imgWidth && j+l >= 0 && j+l < imgHeight) {
                    n += (matrix[i+k][j+l] != 0 ? 1 : 0);
                }
            }
        }
    }
    return n;
}

int composantesConnexes::mininmumVoisin(vector< vector<int> > &matrix, int i, int j) {
    int mini = 999999999;   // Hypothese : il n'y aura pas plus de 1 milliard d'objets a compter
    // Trouve l'etiquette la plus petite dans le voisinage
    for (int l = -1; l <= 1; ++l) {
        for (int k = -1; k <= 1; ++k) {
            if (k != 0 || l != 0) {
                if (i+k >= 0 && i+k < imgWidth && j+l >= 0 && j+l < imgHeight) {
                    if (matrix[i+k][j+l] > 0 && matrix[i+k][j+l] < mini) {
                        mini = matrix[i+k][j+l];
                    }
                }
            }
        }
    }
    return mini;
}


// Retourne le parent du noeud nd
composantesConnexes::Noeud& composantesConnexes::findParent(Noeud& nd) {
    if (nd.parent == NULL) {
        return nd;
    }
    return findParent(*(nd.parent));
}

// Rattache la composante connexe n2 a n1
void composantesConnexes::unionNode(Noeud& n1, Noeud& n2) {
    Noeud& parent2 = findParent(n2);
    if (&parent2 == &n2) {
        n2.parent = &n1;
    } else {
        parent2.parent = &n1;
    }
}


void composantesConnexes::imprime(vector<Noeud> &arbre) {
    Noeud* parent;
    for (size_t i = 0; i < arbre.size(); ++i) {
        parent = &findParent(arbre.at(i));
        cout << "(" << arbre[i].elem << ")--> " << parent->elem << endl;
    }
}

int composantesConnexes::get(vector< vector<int> >& matrice, int x, int y) {
    if (x >= 0 && x < imgWidth && y >= 0 && y < imgHeight) {
        return matrice[x][y];
    }
    return 0;
}

QImage *composantesConnexes::composantesConnexe( QImage *image ){
    imgWidth = image->width();
    imgHeight = image->height();
    QImage *res = new QImage(imgWidth, imgHeight, image->format() );

    vector< vector<int> > matrixCC = vector< vector<int> >(imgWidth);
    for (int x = 0; x < imgWidth; ++x) {
        matrixCC[x] = vector<int>(imgHeight);
        for (int y = 0; y < imgHeight; ++y) {
            matrixCC[x][y] = 0;
        }
    }

    vector<Noeud> arbre = vector<Noeud>();
    int etiquetteConnexe = 0;

    // Premiere passe, etiquetage des composantes
    for (int y = 0; y < imgHeight; ++y) {
        for (int x = 0; x < imgWidth; ++x) {

            int r = qRed(image->pixel(x,y));
            // Si le pixel appartient a un objet
            if (r == 255) {
                int n = compterVoisin(matrixCC, x, y);
                if (n == 0) {
                    // Nouvelle composante connexe trouvee
                    etiquetteConnexe++;
                    matrixCC[x][y] = etiquetteConnexe;
                    arbre.push_back(Noeud(NULL, etiquetteConnexe));
                } else if (n > 0) {
                    // Etiquetage du pixel avec le voisin le plus petit
                    matrixCC[x][y] = mininmumVoisin(matrixCC, x, y);
                    // Trouve les numeros des deux correspondances a faire correspondre
                    int voisin1 = -1;
                    int voisin2 = -1;
                    int tab[5];
                    tab[0] = get(matrixCC,x-1,y-1);
                    tab[1] = get(matrixCC,x,y-1);
                    tab[2] = get(matrixCC,x+1,y-1);
                    tab[3] = get(matrixCC,x-1,y);
                    tab[4] = -1;
                    int i = 0;
                    while (tab[i] == 0) {
                        i++;
                    }
                    voisin1 = tab[i];
                    i += (i < 4 ? 1 : 0);
                    while (tab[i] == 0) {
                        i++;
                    }
                    voisin2 = tab[i];
                    if (x == 72 && y == 38) {
                        cout << arbre.size() << " ---- " << voisin1 << " | " << voisin2 << endl;
                    }
//                    for (int dy = -1; dy <= 1; ++dy) {
//                        for (int dx = -1; dx <= 1; ++dx) {
//                            if (dx != 0 || dy != 0) {
//                                if (x+dx >= 0 && x+dx < imgWidth && y+dy >= 0 && y+dy < imgHeight && matrixCC[x+dx][y+dy] != 0) {
//                                    if (voisin1 == -1) {
//                                        voisin1 = matrixCC[x+dx][y+dy];
//                                    } else if (voisin2 == -1 && matrixCC[x+dx][y+dy] != voisin1) {
//                                        voisin2 = matrixCC[x+dx][y+dy];
//                                    }
//                                }
//                            }
//                        }
//                    }
                    // Stocke la correspondance s'il y a 2 etiquettes differentes cote a cote
                    if (voisin1 > 0 && voisin2 > 0) {
                        if (voisin1 > voisin2) {
                            int tmp = voisin1;
                            voisin1 = voisin2;
                            voisin2 = tmp;
                        }
                        // Joint les 2 correspondances si elles ne le sont pas deja
                        Noeud& a = findParent(arbre.at(voisin1-1));
                        Noeud& b = findParent(arbre.at(voisin2-1));
                        // Breakpoint
                        if (a.elem != b.elem) {
                            unionNode(arbre.at(voisin1-1), arbre.at(voisin2-1));
                        }
                    }

                }
            }

            cout << "(" << x << ", " << y << ")" << endl;
        }
    }

    // Seconde passe, re-etiquetage des equivalences
    for (int y = 0; y < imgHeight; ++y) {
        for (int x = 0; x < imgWidth; ++x) {
            if (matrixCC[x][y] != 0) {
                Noeud& parent = findParent(arbre.at(matrixCC[x][y]-1));
                matrixCC[x][y] = parent.elem;
            }
        }
    }

//    // Affichage
//    for (unsigned int i = 0; i < arbre.size(); ++i) {
//        cout << arbre.at(i).elem << endl;
//    }
//    cout << "Ma grosse bote" << endl;
//    for (int y = 0; y < imgHeight; ++y) {
//        for (int x = 0; x < imgWidth; ++x) {
//            cout << matrixCC[x][y] << ", ";
//        }
//        cout << endl;
//    }

    cout << "Calcul res" << endl;

    for (int y = 0; y < imgHeight; ++y) {
        for (int x = 0; x < imgWidth; ++x) {
            if (matrixCC[x][y] != 0) {
                srand(matrixCC[x][y]);
                //res->setPixel(x, y, qRgb( 255 * (matrixCC[x][y]/((double)etiquetteConnexe)), 0, 0));
                res->setPixel(x, y, qRgb(rand()%256, rand()%256, rand()%256 ));
            } else {
                res->setPixel(x, y, qRgb(0, 0, 0));
            }
        }
    }

    return res;
}


composantesConnexes::Noeud::Noeud(composantesConnexes::Noeud *parent, int elem)
{
    this->parent = parent;
    this->elem = elem;
}
