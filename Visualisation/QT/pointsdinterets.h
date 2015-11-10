#ifndef POINTSDINTERETS_H
#define POINTSDINTERETS_H

#include <QImage>
#include "boost/numeric/ublas/matrix.hpp"
#include "convolution.h"

class pointsDinterets{

public:

    QImage *calculpointsDinterets(QImage *image, double alpha);

    struct pointI{
        int x;
        int y;
        double val;
    };

private:

    int partition(std::vector<pointI> &A, int p, int q);
    void quickSort(std::vector<pointI> &A, int p, int q);
    QImage *croixRouge(pointI p, QImage *image);
    int **ConstructionMatrice(int n, int p);
    boost::numeric::ublas::matrix<double> lissage(boost::numeric::ublas::matrix<double> tab);
    QImage *matrixToQimage(QImage *image, boost::numeric::ublas::matrix<double> tab);
    boost::numeric::ublas::matrix<double> seuillage(boost::numeric::ublas::matrix<double> tab);

};

#endif // POINTSDINTERETS_H
