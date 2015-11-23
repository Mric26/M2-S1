#include "grisconvers.h"

using namespace std;

QImage * GrisConvers::versGris(QImage *image ){

    int imWidth = image->width();
    int imHeight = image->height();

    float rouge, vert, bleu, gris;
    QImage * res = new QImage( imWidth, imHeight, image->format());

    for(int j=0; j<imWidth; j++){
        for(int k=0; k<imHeight; k++){

            QRgb * pix = new QRgb( image->pixel(j,k) );
            QColor c( *pix );
            rouge = c.red();
            vert = c.green();
            bleu = c.blue();

            gris = 0.299*rouge + 0.587*vert + 0.114*bleu;

            res->setPixel( QPoint(j,k), qRgb(gris,gris,gris) );
        }
    }

    return res;
}
