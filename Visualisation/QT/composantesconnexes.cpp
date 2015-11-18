#include "composantesconnexes.h"
#include <limits.h>
#include <stdlib.h>

typedef vector< vector<int> > picture;

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

int composantesConnexes::get(vector< vector<int> > &matrix, int x, int y) {
    if (x >= 0 && x < imgWidth && y >= 0 && y < imgHeight) {
        return matrix[x][y];
    }
    return 0;
}

unsigned int composantesConnexes::fillMatrix(vector< vector<int> > &matrixImg, vector< vector<int> > &matrixCC) {
    for (unsigned int x = 0; x < matrixCC.size(); ++x) {
        for (unsigned int y = 0; y < matrixCC[x].size(); ++y) {
            matrixCC[x][y] = 0;
        }
    }

    vector<Noeud> arbre = vector<Noeud>();
    int etiquetteConnexe = 0;
    unsigned int nbComposanteConnexe = 0;
    Noeud *nd = NULL;

    // Premiere passe, etiquetage des composantes
    for (int y = 0; y < imgHeight; ++y) {
        for (int x = 0; x < imgWidth; ++x) {

            // Si le pixel appartient a un objet
            if (matrixImg[x][y] == 255) {
                int n = compterVoisin(matrixCC, x, y);
                if (n == 0) {
                    // Nouvelle composante connexe trouvee
                    etiquetteConnexe++;
                    nbComposanteConnexe++;
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
                            nbComposanteConnexe--;
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


    // Re-etiquetage des composantes entre 1 et nbComposanteConnexe
    vector<int> indices = vector<int>(0);
    int pos, elem;
    for (int y = 0; y < imgHeight; ++y) {
        for (int x = 0; x < imgWidth; ++x) {
            if (matrixCC[x][y] != 0) {
                elem = matrixCC[x][y];
                pos = find(indices.begin(), indices.end(), elem) - indices.begin();
                if (pos >= (int) indices.size()) {
                    // elem non trouve dans le vector indices
                    indices.push_back(elem);
                }
                matrixCC[x][y] = pos+1;
            }
        }
    }

    return nbComposanteConnexe;
}

QImage *composantesConnexes::composantesConnexe( QImage *image ){
    imgWidth = image->width();
    imgHeight = image->height();
    QImage *res = new QImage(imgWidth, imgHeight, image->format() );

    vector< vector<int> > matrixImg = vector< vector<int> >(imgWidth);
    vector< vector<int> > matrixCC = vector< vector<int> >(imgWidth);
    for (int x = 0; x < imgWidth; ++x) {
        matrixImg[x] = vector<int>(imgHeight);
        matrixCC[x] = vector<int>(imgHeight);
        for (int y = 0; y < imgHeight; ++y) {
            matrixImg[x][y] = (qRed(image->pixel(x, y)) == 0 ? 0 : 255);
            matrixCC[x][y] = 0;
        }
    }

    unsigned int nbComposanteConnexe = fillMatrix(matrixImg, matrixCC);
    cout << nbComposanteConnexe << " composantes connexes présentent dans l'image" << endl;

    // Comptage des trous dans chaques composante connexe
    if (nbComposanteConnexe > 0) {
        frame* b = NULL;
        vector< frame* > boundaries = vector< frame* >(nbComposanteConnexe);
        vector< picture > arrayPicImg = vector< picture >(nbComposanteConnexe);
        vector< picture > arrayPicCC = vector< picture >(nbComposanteConnexe);
        int elem;

        // Extraction de chaque composante connexe
        // Boundaries = indique le domaine de la composante n°i

        // Initialisation
        for (unsigned int i = 0; i < boundaries.size(); ++i) {
            b = new frame;
            b->x1 = INT_MAX;
            b->y1 = INT_MAX;
            b->x2 = INT_MIN;
            b->y2 = INT_MIN;
            boundaries[i] = b;
        }

        // Trouve le rectangle englobant de chaque composante
        for (int y = 0; y < imgHeight; ++y) {
            for (int x = 0; x < imgWidth; ++x) {

                if (matrixCC[x][y] != 0) {
                    b = boundaries[matrixCC[x][y]-1];
                    if (x < b->x1) {
                        b->x1 = x;
                    }
                    if (y < b->y1) {
                        b->y1 = y;
                    }
                    if (x+1 > b->x2) {
                        b->x2 = x+1;
                    }
                    if (y+1 > b->y2) {
                        b->y2 = y+1;
                    }
                }

            }
        }

        // Extraction des composantes connexes
        for (unsigned int i = 0; i < nbComposanteConnexe; ++i) {
            b = boundaries[i];
            arrayPicImg[i] = vector< vector<int> >(b->x2 - b->x1 + 2);
            arrayPicCC[i] = vector< vector<int> >(b->x2 - b->x1 + 2);
            for (unsigned int x = 0; x < arrayPicImg[i].size(); ++x) {
                arrayPicImg[i][x] = vector<int>(b->y2 - b->y1 + 2);
                arrayPicCC[i][x] = vector<int>(b->y2 - b->y1 + 2);
            }

            for (int dx = 0; dx < (b->x2 - b->x1); ++dx) {
                for (int dy = 0; dy < (b->y2 - b->y1); ++dy) {
                    elem = matrixCC[b->x1 + dx][b->y1 + dy];
                    // Si c'est l'element que l'on recherche
                    if (elem == (int)(i+1)) {
                        arrayPicImg[i][1+dx][1+dy] = 255;
                    }
                }
            }
        }

        // Passage en negatif de chaque composante extraite
        for (unsigned int i = 0; i < nbComposanteConnexe; ++i) {
            picture &pic = arrayPicImg[i];
            for (unsigned int x = 0; x < pic.size(); ++x) {
                for (unsigned int y = 0; y < pic[x].size(); ++y) {
                    pic[x][y] = 255 - pic[x][y];
                }
            }
        }

        // Affichage du nombre de trou dans chaque composante connexe
        for (unsigned int i = 0; i < nbComposanteConnexe; ++i) {
            imgWidth = arrayPicImg[i].size();
            imgHeight = arrayPicImg[i][0].size();
            int nbComposanteConnexe_i = fillMatrix(arrayPicImg[i], arrayPicCC[i]);
            cout << "Composante Connexe n°" << i << " : " << nbComposanteConnexe_i-1 << "trou(s)" << endl;
//            for (unsigned int dx = 0; dx < arrayPicCC[i].size(); ++dx) {
//                cout << "\t";
//                for (unsigned int dy = 0; dy < arrayPicCC[i][dx].size(); ++dy) {
//                    cout << arrayPicCC[i][dx][dy] << ", ";
//                }
//                cout << endl;
//            }
        }

        // Desallocation memoire
        for (unsigned int i = 0; i < boundaries.size(); ++i) {
            delete boundaries[i];
        }
    }

    imgWidth = image->width();
    imgHeight = image->height();

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
