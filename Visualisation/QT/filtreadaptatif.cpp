#include "filtreadaptatif.h"

QImage *filtreAdaptatif::filtreAda( QImage *image ){

    int imWidth = image->width();
    int imHeight = image->height();

    QImage *nouvelleImage = new QImage(imWidth, imHeight, image->format() );

    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {
            //recup des 9 points
            QRgb p1, p2, p3, p4, p5, p6, p7, p8, p9;
            p5 = image->pixel(i,j);
            p6 = image->pixel(i+1,j);
            p8 = image->pixel(i,j+1);
            p9 = image->pixel(i+1,j+1);
            if( i > 0 ){
                p4 = image->pixel(i-1,j);
                p7 = image->pixel(i-1,j+1);
            }
            else{
                p4 = p5;
                p7 = p8;
            }
            if( j > 0 ){
                p2 = image->pixel(i,j-1);
                p3 = image->pixel(i+1,j-1);
            }
            else{
                p2 = p5;
                p3 = p6;
            }
            if( (i>0) && (j>0) ){
                p1 = image->pixel(i-1,j-1);
            }
            else{
                p1 = p5;
            }
            //calculs
            double somme = 0.0;
            int v1 = val(p5, p1);
            somme = somme + v1;
            int v2 = val(p5, p2);
            somme = somme + v2;
            int v3 = val(p5, p3);
            somme = somme + v3;
            int v4 = val(p5, p4);
            somme = somme + v4;
            int v5 = val(p5, p5);
            somme = somme + v5;
            int v6 = val(p5, p6);
            somme = somme + v6;
            int v7 = val(p5, p7);
            somme = somme + v7;
            int v8 = val(p5, p8);
            somme = somme + v8;
            int v9 = val(p5, p9);
            somme = somme + v9;

            double nv1 = v1/somme;
            double nv2 = v2/somme;
            double nv3 = v3/somme;
            double nv4 = v4/somme;
            double nv5 = v5/somme;
            double nv6 = v6/somme;
            double nv7 = v7/somme;
            double nv8 = v8/somme;
            double nv9 = v9/somme;

            int res = qBlue(p1)*nv1 + qBlue(p2)*nv2 + qBlue(p3)*nv3 + qBlue(p4)*nv4 + qBlue(p5)*nv5 + qBlue(p6)*nv6 + qBlue(p7)*nv7 + qBlue(p8)*nv8 + qBlue(p9)*nv9;
            nouvelleImage->setPixel(i, j, qRgb(res,res,res) );
        }
    }

    return nouvelleImage;
}

QImage *filtreAdaptatif::filtreAda2(QImage *image){
    int imWidth = image->width();
    int imHeight = image->height();

    QImage *nouvelleImage = new QImage(imWidth, imHeight, image->format() );

    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {

        }
    }
}

int filtreAdaptatif::val(QRgb pt1, QRgb pt2){
    //d(i,j,k,l) = valAbsolue()
    int val1 = qBlue(pt1);
    int val2 = qBlue(pt2);
    if( val1 != val2 ){
        return valAbsolue(val1 - val2);
    }
    else{
        return 5;
    }
}

int filtreAdaptatif::valAbsolue(int val){
 if(val >= 0)
   return val;
 else
   return -val;
}
