#ifndef DILAERO_H
#define DILAERO_H

#include <QImage>

class dilaEro
{
public:

    QImage *dilatation(QImage *image, int taille);
    QImage *erosion(QImage *image, int taille);

};

#endif // DILAERO_H
