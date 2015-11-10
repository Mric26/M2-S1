#ifndef POINTSDINTERETS_H
#define POINTSDINTERETS_H

#include <QImage>

#include "convolution.h"

class pointsDinterets{

public:

    QImage *calculpointsDinterets(QImage *image, double alpha);  

    struct pointI{
        int x;
        int y;
        int val;
    };

private:

    int partition(std::vector<pointI> &A, int p, int q);
    void quickSort(std::vector<pointI> &A, int p, int q);   
    QImage *croixRouge(pointI p, QImage *image);   
    int **ConstructionMatrice(int n, int p);

};

#endif // POINTSDINTERETS_H
