#ifndef POINTSDINTERETS_H
#define POINTSDINTERETS_H

#include <QImage>
#include <QString>
#include <QImage>
#include <QFileDialog>

#include "boost/numeric/ublas/matrix.hpp"
#include "convolution.h"
#include "mainwindow.h"

class pointsDinterets{

public:

    struct pointI{
        int x;
        int y;
        double val;
    };

    QImage *affichageHarris(QImage *image, std::vector<pointI> *v);
    std::vector<pointI> *calculpointsDinterets(QImage *image, double alpha);   
    QImage *comparaisonHarris(MainWindow *w);

private:

    int partition(std::vector<pointI> &A, int p, int q);
    void quickSort(std::vector<pointI> &A, int p, int q);
    QImage *croixRouge(pointI p, QImage *image);
    QImage *croixVerte(pointI p, QImage *image);
    int **ConstructionMatrice(int n, int p);
    boost::numeric::ublas::matrix<double> lissage(boost::numeric::ublas::matrix<double> tab);
    QImage *matrixToQimage(QImage *image, boost::numeric::ublas::matrix<double> tab);
    boost::numeric::ublas::matrix<double> seuillage(boost::numeric::ublas::matrix<double> tab);   
    double calculSSD(pointI p1, pointI p2, int longueur, QImage *image1, QImage *image2); 
    QImage *correspondanceLigne(pointI p1, pointI p2, int imageHeight, QImage *imageres);

};

#endif // POINTSDINTERETS_H
