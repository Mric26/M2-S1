#include "kmoyenne.h"
#include <stdlib.h>
#include <limits.h>
#include <iostream>

using namespace std;

kmoyenne::kmoyenne(){
}

int distance(int r1, int g1, int b1, int r2, int g2, int b2) {
    return (r1*r2 + g1*g2 + b1*b2);
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
    for (int i = 0; i < 4; ++i) {
        srand(i+1);
        cluster[i] = qRgb(rand()%255, rand()%255, rand()%255);
    }
    vector<QRgb> newCluster = vector<QRgb>(nb);
    vector<int> nbCluster = vector<int>(nb);

    //double epsi = 0.1;
    int d, mini;
    QRgb color;

    // 4 iterations seront faites
    for (int i = 0; i < 4; ++i) {

        // Attribution des clusters a chaque pixel
        for (int x = 0; x < imgWidth; ++x) {
            for (int y = 0; y < imgHeight; ++y) {

                color = image->pixel(x, y);
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
            newCluster[k] = qRgb(0,0,0);
            nbCluster[k] = 0;
        }

        // Calcul des nouveaux clusters
        for (int x = 0; x < imgWidth; ++x) {
            for (int y = 0; y < imgHeight; ++y) {
                newCluster[matrixIndex[x][y]] += image->pixel(x,y);
                nbCluster[matrixIndex[x][y]]++;
            }
        }

        for (unsigned int k = 0; k < nb; ++k) {
            int r = qRed(newCluster[k]) / nbCluster[k];
            int g = qGreen(newCluster[k]) / nbCluster[k];
            int b = qBlue(newCluster[k]) / nbCluster[k];
            newCluster[k] = qRgb(r,g,b);
        }

        // Copie des nouveaux cluster
        for (unsigned int k = 0; k < nb; ++k) {
            cluster[k] = newCluster[k];
        }
    }

    // Calcul de l'image resultante
    for (int x = 0; x < imgWidth; ++x) {
        for (int y = 0; y < imgHeight; ++y) {
            res->setPixel(x, y, cluster[matrixIndex[x][y]]);
        }
    }

    return res;
}
