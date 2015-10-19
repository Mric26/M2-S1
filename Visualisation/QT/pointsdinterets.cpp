#include "pointsdinterets.h"

QImage * pointsDinterets::calculpointsDinterets(QImage *image, double alpha){

    int imWidth = image->width();
    int imHeight = image->height();

    QImage *nouvelleImage = new QImage(imWidth, imHeight, image->format() );

    //calculs preliminaires
    Convolution c;
    QImage *ix = c.gradientX(image);
    QImage *iy = c.gradientY(image);
    QImage *ixc = new QImage();
    QImage *iyc = new QImage();
    QImage *ixy = new QImage();
    int R1, R2, G1,G2, B1, B2;

    for (int i = 0; i < imWidth-1; ++i) {
        for (int j = 0; j < imHeight-1; ++j) {
            R1 = qRed(ix->pixel(i,j));
            G1 = qGreen(ix->pixel(i,j));
            B1 = qBlue(ix->pixel(i,j));
            ixc->setPixel(i, j, qRgb(R1*R1,G1*G1,B1*B1) );

            R2 = qRed(iy->pixel(i,j));
            G2 = qGreen(iy->pixel(i,j));
            B2 = qBlue(iy->pixel(i,j));
            iyc->setPixel(i, j, qRgb(R2*R2,G2*G2,B2*B2) );

            ixy->setPixel(i, j, qRgb(R1*R2,G1*G2,B1*B2) );
        }
    }

    //fonction de harris
    for (int i = 0; i < imWidth-1; ++i) {
        for (int j = 0; j < imHeight-1; ++j) {
            double v1, v2, v3, v4, HR, HG, HB;
            v1 = qRed(ixc->pixel(i,j));
            v2 = qRed(ixy->pixel(i,j));
            v3 = qRed(iyc->pixel(i,j));
            double CR = v1*v3 - v2*v4;
            HR = CR - alpha*(v1*v3*v1*v3);
            v1 = qGreen(ixc->pixel(i,j));
            v2 = qGreen(ixy->pixel(i,j));
            v3 = qGreen(iyc->pixel(i,j));
            double CG = v1*v3 - v2*v4;
            HG = CG - alpha*(v1*v3*v1*v3);
            v1 = qBlue(ixc->pixel(i,j));
            v2 = qBlue(ixy->pixel(i,j));
            v3 = qBlue(iyc->pixel(i,j));
            double CB = v1*v3 - v2*v2;
            HB = CB - alpha*(v1*v3*v1*v3);

            nouvelleImage->setPixel(i, j, qRgb(HR,HG,HB) );
        }
    }

    return nouvelleImage;
}
