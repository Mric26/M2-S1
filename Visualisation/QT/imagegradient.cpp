#include "imagegradient.h"

#include <QtCore/qmath.h>

QImage *imagegradient::filtreGradient(QImage *img)
{
    int imgWidth = img->width();
    int imgHeight = img->height();
    QImage *nouvelleImage = new QImage(imgWidth, imgHeight, img->format() );

    Convolution c;
    QImage *gx = c.gradientX(img);
    QImage *gy = c.gradientY(img);

    double r, r1, r2;
    for (int i = 0; i < img->width(); ++i) {
        for (int j = 0; j < img->height(); ++j) {
            r1 = qRed(gx->pixel(i, j));
            r2 = qRed(gy->pixel(i, j));
            r = sqrt(r1*r1 + r2*r2);
            nouvelleImage->setPixel(i, j, qRgb(r,r,r));
        }
    }

    return nouvelleImage;
}
