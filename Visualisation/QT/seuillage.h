#ifndef SEUILLAGE_H
#define SEUILLAGE_H

#include <QImage>

class seuillage{

public:

    QImage *seuil(QImage *image, int seuil);   
    QImage *seuilMoyenne(QImage *image);
    QImage *seuilMedianne(QImage *image);

};

#endif // SEUILLAGE_H
