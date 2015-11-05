#include "composantesconnexes.h"
#include <limits.h>
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

// Trouve l'etiquette la plus petite dans le 8-voisinage
int composantesConnexes::mininmumVoisin(vector< vector<int> > &matrix, int x, int y) {
    int n, mini = INT_MAX;
    for (int l = -1; l <= 1; ++l) {
        for (int k = -1; k <= 1; ++k) {
            if (k != 0 || l != 0) {
                n = get(matrix, x+k, y+l);
                if (n > 0 && n < mini) {
                    mini = n;
                }
            }
        }
    }
    return mini;
}

// Retourne le parent du noeud nd
composantesConnexes::Noeud& composantesConnexes::findParent(Noeud& nd) {
    if (nd.parent == &nd) {
        return nd;
    }
    return findParent(*(nd.parent));
}

// Rattache la composante connexe n2 a n1
void composantesConnexes::unionNode(Noeud& n1, Noeud& n2) {
    Noeud& parent2 = findParent(n2);
    parent2.parent = &findParent(n1);
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
    Noeud *nd = NULL;

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
                    nd = new Noeud(etiquetteConnexe);
                    nd->parent = nd;
                    arbre.push_back(*nd);
                    //arbre.at(etiquetteConnexe-1).parent = &arbre.at(etiquetteConnexe-1);
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
                        if (a.elem != b.elem) {
                            unionNode(arbre.at(voisin1-1), arbre.at(voisin2-1));
                        }
                    }

                }
            }

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

    // Creation de l'image resultante
    for (int y = 0; y < imgHeight; ++y) {
        for (int x = 0; x < imgWidth; ++x) {
            if (matrixCC[x][y] != 0) {
                srand(matrixCC[x][y]);
                res->setPixel(x, y, qRgb(rand()%256, rand()%256, rand()%256 ));
            } else {
                res->setPixel(x, y, qRgb(0, 0, 0));
            }
        }
    }

    return res;
}


composantesConnexes::Noeud::Noeud(int elem)
{
    this->parent = NULL;
    this->elem = elem;
}
