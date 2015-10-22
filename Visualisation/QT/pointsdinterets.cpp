#include "pointsdinterets.h"

QImage * pointsDinterets::calculpointsDinterets(QImage *image, double alpha){

    int imWidth = image->width();
    int imHeight = image->height();

    QImage *nouvelleImage = new QImage(imWidth, imHeight, image->format() );

    //calculs preliminaires des matrices
    Convolution c;
    QImage *ix = c.gradientX(image);
    QImage *iy = c.gradientY(image);
    QImage *ixc = new QImage(imWidth, imHeight, image->format() );
    QImage *iyc = new QImage(imWidth, imHeight, image->format() );
    QImage *ixy = new QImage(imWidth, imHeight, image->format() );
    int R1, R2, G1, G2, B1, B2;

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
            double v1, v2, v4, HR, HG, HB;
            v1 = qRed(ixc->pixel(i,j));
            v2 = qRed(ixy->pixel(i,j));
            v4 = qRed(iyc->pixel(i,j));
            double CR = v1*v2 - v2*v4;
            HR = CR - alpha*(v1*v4*v1*v4);
            v1 = qGreen(ixc->pixel(i,j));
            v2 = qGreen(ixy->pixel(i,j));
            v4 = qGreen(iyc->pixel(i,j));
            double CG = v1*v2 - v2*v4;
            HG = CG - alpha*(v1*v4*v1*v4);
            v1 = qBlue(ixc->pixel(i,j));
            v2 = qBlue(ixy->pixel(i,j));
            v4 = qBlue(iyc->pixel(i,j));
            double CB = v1*v2 - v2*v4;
            HB = CB - alpha*(v1*v4*v1*v4);

            nouvelleImage->setPixel(i, j, qRgb(HR,HG,HB) );
        }
    }

    //extraction des maxima locaux
    int R, G, B, Rt, Gt, Bt;
    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {
            R = qRed(nouvelleImage->pixel(i,j));
            G = qGreen(nouvelleImage->pixel(i,j));
            B = qBlue(nouvelleImage->pixel(i,j));
            //negatif
            if( (R<0) || (G<0) || (B<0) ){
                nouvelleImage->setPixel(i, j, qRgb(255,255,255) );
            }
            //maxima locaux
            for (int k = -1; k < 1; k++) {
                for (int l = -1; l < 1; ++l) {
                    if( (i+k<0) || (i+k>imWidth) || (j+l<0) || (j+l>imHeight) ){
                    }
                    else{
                        Rt = qRed(image->pixel(i+k,j+l));
                        Gt = qGreen(image->pixel(i+k,j+l));
                        Bt = qBlue(image->pixel(i+k,j+l));
                        if( (R<Rt) || (G<Gt) || (B<Bt) ){
                            nouvelleImage->setPixel(i, j, qRgb(255,255,255) );
                        }
                    }
                }
            }
            //extraction n meilleurs points

            //affichage n points

        }
    }

    return nouvelleImage;
}


void pointsDinterets::tri_insertion(int tableau[],int longueur){
     int i, memory, compt, marqueur;
     for(i=1;i<longueur;i++){
        memory=tableau[i];
        compt=i-1;
        do{
            marqueur=false;
            if (tableau[compt]>memory){
                tableau[compt+1]=tableau[compt];
                compt--;
                marqueur=true;
            }
            if (compt<0) marqueur=false;
        }
        while(marqueur);
        tableau[compt+1]=memory;
    }
}
