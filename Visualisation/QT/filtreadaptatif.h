#ifndef FILTREADAPTATIF_H
#define FILTREADAPTATIF_H

#include <QImage>

class filtreAdaptatif
{
public:
    QImage *filtreAda(QImage *image);
    QImage *filtreAda2(QImage *image, int taille);
    int valAbsolue(int val);
    int val(QRgb pt1, QRgb pt2);
};

#endif // FILTREADAPTATIF_H
