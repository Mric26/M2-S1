#include "seuillagedecoupe.h"
#include "seuillage.h"

QImage * SeuillageDecoupe::SeuillageDecoupeFonction( QImage * image, int taille ){
    //riz = 350 * 350
    int imWidth = image->width();
    int imHeight = image->height();

    //decoupage
    int nbDecoupe = 2;
    int imWidthD = imWidth / nbDecoupe;
    int imHeightD = imHeight / nbDecoupe;

    QImage image11 = image->copy(0, 0, imWidthD, imHeightD);
    QImage image12 = image->copy(imWidthD, 0, imWidthD, imHeightD);
    QImage image21 = image->copy(0, imHeightD, imWidthD, imHeightD);
    QImage image22 = image->copy(imWidthD, imHeightD, imWidthD, imHeightD);

    QImage * image11s = new QImage( image11);
    QImage * image12s = new QImage( image12);
    QImage * image21s = new QImage( image21);
    QImage * image22s = new QImage( image22);

    if( taille == 1){
        //seuillage
        seuillage s;
        image11s =  s.seuilMoyenne(&image11);
        image12s =  s.seuilMoyenne(&image12);
        image21s =  s.seuilMoyenne(&image21);
        image22s =  s.seuilMoyenne(&image22);
    }
    else{
        image11s = SeuillageDecoupeFonction(image11s, taille-1);
        image12s = SeuillageDecoupeFonction(image12s, taille-1);
        image21s = SeuillageDecoupeFonction(image21s, taille-1);
        image22s = SeuillageDecoupeFonction(image22s, taille-1);
    }

    //reconstruction

    QImage *res = new QImage( *image );

    //11
    for (int i = 0; i < imWidthD-1; ++i) {
        for (int j = 0; j < imHeightD-1; ++j) {
            res->setPixel(i,j, image11s->pixel(i,j) );
        }
    }

    //12
    for (int i = imWidthD; i < imWidth-1; ++i) {
        for (int j = 0; j < imHeightD-1; ++j) {
            res->setPixel(i,j, image12s->pixel(i-imWidthD,j) );
        }
    }

    //21
    for (int i = 0; i < imWidthD-1; ++i) {
        for (int j = imHeightD; j < imHeight-1; ++j) {
            res->setPixel(i,j, image21s->pixel(i,j-imHeightD) );
        }
    }

    //22
    for (int i = imWidthD; i < imWidth-1; ++i) {
        for (int j = imHeightD; j < imHeight-1; ++j) {
            res->setPixel(i,j, image22s->pixel(i-imWidthD,j-imHeightD) );
        }
    }

    return res;
}
