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

QImage *seuillage::seuilMedianne( QImage *image ){
    int imWidth = image->width();
    int imHeight = image->height();
    int seuil = 123;

    //mise en vector
    std::vector<int> donnees;
    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {
            donnees.push_back( qRed(image->pixel(i,j)) );
        }
    }

    //tri et calcul mediane
    sort(donnees.begin(),donnees.end());
    int i = donnees.size()/2;
    if( donnees.size()%2 == 0){
        seuil = (donnees[i-1] + donnees[i]) / 2;
    }
    else{
        seuil = donnees[i];
    }

    return seuillage::seuil(image, seuil);
}

QImage *seuillage::seuilMoyenne(QImage *image ){
    int imWidth = image->width();
    int imHeight = image->height();
    int seuil = 123;

    int somme = 0;
    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {
            somme = somme + qRed(image->pixel(i,j));
        }
    }

    seuil = somme / (imHeight*imWidth);

    if( seuil > 20 ){
        return seuillage::seuil(image, seuil);
    }
    else{
        return image;
    }

}
