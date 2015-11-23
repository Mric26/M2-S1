#include "kmoyenne.h"
#include <stdlib.h>
#include <limits.h>
#include <iostream>

using namespace std;

kmoyenne::kmoyenne(){
}

int distance(int r1, int g1, int b1, int r2, int g2, int b2) {
    return ((r1-r2)*(r1-r2) + (g1-g2)*(g1-g2) + (b1-b2)*(b1-b2));
}

QImage *kmoyenne::kMoyenne(QImage *image, unsigned int nb){
    int imgWidth = image->width();
    int imgHeight = image->height();
    QImage *res = new QImage(imgWidth, imgHeight, image->format() );

    // Matrice donnant l'indice du cluster de chaque pixel
    vector< vector<int> > matrixIndex = vector< vector<int> >(imgWidth);
    for (int x = 0; x < imgWidth; ++x) {
        matrixIndex[x] = vector<int>(imgHeight);
        for (int y = 0; y < imgHeight; ++y) {
            matrixIndex[x][y] = 0;
        }
    }

    // Generation pseudo-aleatoire des centres
    vector<QRgb> cluster = vector<QRgb>(nb);
    vector< vector<int> > newCluster = vector< vector<int> >(nb);
    vector<int> nbCluster = vector<int>(nb);

    srand(time(NULL));
    for (unsigned int i = 0; i < nb; ++i) {
        cluster[i] = qRgb(rand()%255, rand()%255, rand()%255);
        newCluster[i] = vector<int>(3);
    }
    // initialisation manuelle pour kmoyenne.png avec nb = 4
//    cluster[0] = qRgb(19, 95, 164);
//    cluster[1] = qRgb(67, 127, 183);
//    cluster[2] = qRgb(185, 176, 136);
//    cluster[3] = qRgb(85, 78, 54);

    cluster[0] = qRgb(212, 194, 130);
    cluster[1] = qRgb(214, 201, 159);

    cluster[2] = qRgb(3, 89, 164);
    cluster[3] = qRgb(12, 94, 168);


    //double epsi = 0.1;
    int d, mini;
    QRgb color;

    // 4 iterations seront faites
    for (int i = 0; i < 4; ++i) {

        // Attribution des clusters a chaque pixel
        for (int y = 0; y < imgHeight; ++y) {
            for (int x = 0; x < imgWidth; ++x) {

                color = image->pixel(x,y);
                int r = qRed(color);
                int g = qGreen(color);
                int b = qBlue(color);
                mini = INT_MAX;

                for (unsigned int k = 0; k < nb; ++k) {
                    d = distance(r,g,b,qRed(cluster[k]),qGreen(cluster[k]),qBlue(cluster[k]));
                    if (d < mini) {
                        mini = d;
                        matrixIndex[x][y] = k;
                    }
                }

            }
        }

        for (unsigned int k = 0; k < nb; ++k) {
            newCluster[k][0] = 0;
            newCluster[k][1] = 0;
            newCluster[k][2] = 0;
            nbCluster[k] = 0;
        }

        // Calcul des nouveaux clusters
        for (int x = 0; x < imgWidth; ++x) {
            for (int y = 0; y < imgHeight; ++y) {
                newCluster[matrixIndex[x][y]][0] += qRed(image->pixel(x,y));
                newCluster[matrixIndex[x][y]][1] += qGreen(image->pixel(x,y));
                newCluster[matrixIndex[x][y]][2] += qBlue(image->pixel(x,y));
                nbCluster[matrixIndex[x][y]]++;
            }
        }

        for (unsigned int k = 0; k < nb; ++k) {
            if (nbCluster[k] != 0) {
                newCluster[k][0] /= nbCluster[k];
                newCluster[k][1] /= nbCluster[k];
                newCluster[k][2] /= nbCluster[k];
            }
        }

        // Copie des nouveaux cluster
        for (unsigned int k = 0; k < nb; ++k) {
            cluster[k] = qRgb(newCluster[k][0], newCluster[k][1], newCluster[k][2]);
        }
    }

    // Calcul de l'image resultante
    for (int x = 0; x < imgWidth; ++x) {
        for (int y = 0; y < imgHeight; ++y) {
            //cout << cluster[matrixIndex[x][y]] << endl;
            res->setPixel(x, y, cluster[matrixIndex[x][y]]);
        }
    }

    return res;
}
