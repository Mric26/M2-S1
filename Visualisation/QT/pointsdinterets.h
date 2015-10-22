#ifndef POINTSDINTERETS_H
#define POINTSDINTERETS_H

#include <QImage>

#include "convolution.h"

class pointsDinterets{

public:

    QImage *calculpointsDinterets(QImage *image, double alpha);  
    void tri_insertion(int tableau[], int longueur);

};

#endif // POINTSDINTERETS_H
