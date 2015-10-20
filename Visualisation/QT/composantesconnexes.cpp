#include "composantesconnexes.h"

QImage *composantesConnexes::composantesConn( QImage *image ){

    int imWidth = image->width();
    int imHeight = image->height();

    QImage *res = new QImage(imWidth, imHeight, image->format() );



    return res;
}
