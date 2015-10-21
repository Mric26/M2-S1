#include "seuillage.h"

QImage *seuillage::seuil(QImage *image, int seuil ){

    int imWidth = image->width();
    int imHeight = image->height();

    QImage *res = new QImage(imWidth, imHeight, image->format() );

    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {
            int VR = qRed(image->pixel(i,j));
            if( VR > seuil ){
                res->setPixel(i, j, qRgb(255,255,255) );
            }
            else{
                res->setPixel(i, j, qRgb(0,0,0) );
            }
        }
    }

    return res;
}
