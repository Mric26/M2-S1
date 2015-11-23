#include "dilaero.h"

QImage * dilaEro::erosion( QImage* image, int taille){
    int imWidth = image->width();
    int imHeight = image->height();

    int bord = 0;
    if( taille%2 == 1){
        bord = (taille - 1) / 2;
    }
    else{
        bord = taille / 2;
    }

    QImage *res = new QImage(imWidth, imHeight, image->format() );
    bool ok;
    double R1, R2;
    int compteur;

    //parcours de l'image
    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {
            ok = true;
            R1 = 0;
            R2 = 0;
            //parcours da la forme
            compteur = 0;
            for (int k = -bord; k <= 0 && ok; k++) {
                for (int l = -compteur; l<=compteur && ok; ++l) {
                    if( (i+k>=0) && (i+k<imWidth) && (j+l>=0) && (j+l<imHeight) ){
                        R1 = qRed(image->pixel(i+k,j+l));
                        R2 = qRed(image->pixel(i-k,j+l));
                        if( (R1 == 0) || (R2 == 0) ){
                            ok = false;
                        }
                    }
                }
                compteur ++;
            }

            //si toute la forme appartient à l'image
            QRgb blc = qRgb(255, 255, 255);
            QRgb blk = qRgb(0, 0, 0);
            if( ok ){
                res->setPixel(i, j, blc);
            }
            else{
                res->setPixel(i, j, blk);
            }
        }
    }

    return res;
}

QImage * dilaEro::dilatation( QImage* image, int taille){
    int imWidth = image->width();
    int imHeight = image->height();

    int bord = 0;
    if( taille%2 == 1){
        bord = (taille - 1) / 2;
    }
    else{
        bord = taille / 2;
    }

    QImage *res = new QImage(imWidth, imHeight, image->format() );
    bool ok;
    double R1, R2;
    int compteur;

    //parcours de l'image
    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {
            ok = false;
            R1 = 0;
            R2 = 0;
            //parcours da la forme
            compteur = 0;
            for (int k = -bord; k <= 0 && !ok; k++) {
                for (int l = -compteur; l<=compteur && !ok; ++l) {
                    if( (i+k>=0) && (i+k<imWidth) && (j+l>=0) && (j+l<imHeight) ){
                        R1 = qRed(image->pixel(i+k,j+l));
                        R2 = qRed(image->pixel(i-k,j+l));
                        if( (R1 == 255) || (R2 == 255) ){
                            ok = true;
                        }
                    }
                }
                compteur ++;
            }

            //si toute la forme appartient à l'image
            QRgb blc = qRgb(255, 255, 255);
            QRgb blk = qRgb(0, 0, 0);
            if( ok ){
                res->setPixel(i, j, blc);
            }
            else{
                res->setPixel(i, j, blk);
            }
        }
    }

    return res;
}
