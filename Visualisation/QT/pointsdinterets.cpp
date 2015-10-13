#include "pointsdinterets.h"

QImage * pointsDinterets::calculpointsDinterets(QImage *image){

    int imWidth = image->width();
    int imHeight = image->height();

    //calculs
    Convolution c;
    QImage *ix = c.gradientX(image);
    QImage *iy = c.gradientY(image);

    for (int i = 0; i < imWidth-1; ++i) {
        for (int j = 0; j < imHeight-1; ++j) {

        }
    }
    QImage *ixc;
    QImage *iyc;
    QImage *ixy;

}
