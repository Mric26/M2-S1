#include "negatif.h"

#include <QImage>

QImage *negatif::neg(QImage *image){

    int imWidth = image->width();
    int imHeight = image->height();

    QImage *res = new QImage(imWidth, imHeight, image->format() );

    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {
            int VR = qRed(image->pixel(i,j));
            int VG = qGreen(image->pixel(i,j));
            int VB = qBlue(image->pixel(i,j));
            res->setPixel(i, j, qRgb(255-VR,255-VG,255-VB) );
        }
    }

    return res;
}
