#include "composantesconnexes.h"

using namespace std;

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

//    QRgb pixelNoir = QRgb(0, 0, 0);
//    QRgb pixelBlanc = QRgb(255, 255, 255);

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
    for (int i = 0; i < imgWidth; ++i) {
        for (int j = 0; j < imgHeight; ++j) {

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
                } else if (n > 1) {
                    int mini = 999999999;   // Il n'y aura pas plus de 1 milliard d'objets a compter, faut pas deconner ...
                    // Trouve l'etiquette la plus petite dans le voisinage
                    for (int k = -1; k <= 1; ++k) {
                        for (int l = -1; l <= 1; ++l) {
                            if (tab[i+k][j+l] > 0 && tab[i+k][j+l] < mini) {
                                mini = tab[i+k][j+l];
                            }
                        }
                    }
                    // Etiquetage du pixel
                    tab[i][j] = mini;
                    // Stocker la correspondance
                    unionNode(arbre.at(tab[i][j-1]), arbre.at(tab[i-1][j]));


//                    vector<int> cpt = vector<int>();
//                    bool oula = false;
//                    for (int k = -1; k <= 1; ++k) {
//                        for (int l = -1; l <= 1; ++l) {
//                           if (tab[i+k][j+l] != 0) {
//                               oula = false;
//                               for (int x = 0; x < cpt.size(); ++x) {
//                                   if (tab[i+k][j+l] == cpt[x]) {
//                                       oula = true;
//                                   }
//                               }
//                               if (!oula) {
//                                   cpt.push_back(tab[i+k][j+l]);
//                               }
//                            }
//                        }
//                    }
                }
                noeud nd;
                for (unsigned int i = 0; i < arbre.size(); ++i) {
                    nd = arbre.at(i);
                }
            }
        }
    }
    return res;
}

