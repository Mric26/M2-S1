#include "pointsdinterets.h"
#include "seuillage.h"

using namespace std;

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
            double DCR = v1*v4 - v2*v2;
            HR = DCR - alpha*(v1*v4*v1*v4);
            v1 = qGreen(ixc->pixel(i,j));
            v2 = qGreen(ixy->pixel(i,j));
            v4 = qGreen(iyc->pixel(i,j));
            double DCG = v1*v4 - v2*v2;
            HG = DCG - alpha*(v1*v4*v1*v4);
            v1 = qBlue(ixc->pixel(i,j));
            v2 = qBlue(ixy->pixel(i,j));
            v4 = qBlue(iyc->pixel(i,j));
            double DCB = v1*v4 - v2*v2;
            HB = DCB - alpha*(v1+v4);

            nouvelleImage->setPixel(i, j, qRgb(HR,HG,HB) );
        }
    }

//    seuillage s;
//    nouvelleImage = s.seuil(nouvelleImage, 150);
//    return nouvelleImage;

    //extraction des maxima locaux
    int R, G, B, Rt, Gt, Bt;
    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {
            R = qRed(nouvelleImage->pixel(i,j));
            G = qGreen(nouvelleImage->pixel(i,j));
            B = qBlue(nouvelleImage->pixel(i,j));
            //negatif
            if( (R<0) || (G<0) || (B<0) || (i==0) || (j==0) || (i==imWidth-1) || (j==imHeight-1) ){
                nouvelleImage->setPixel(i, j, qRgb(0,0,0) );
            }
            else{
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
                                nouvelleImage->setPixel(i, j, qRgb(0,0,0) );
                            }
                        }
                    }
                }
            }
        }
    }

    //extraction n meilleurs points
    //mise en vector
    QRgb couleur;
    struct pointI p;
    vector<struct pointI> * v = new vector<struct pointI>;
    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {
            couleur = nouvelleImage->pixel(i,j);
            R = qRed(couleur);
            G = qGreen(couleur);
            B = qBlue(couleur);
            if( (R!=0) || (G!=0) || (B!=0) ){
                p.x = i;
                p.y = j;
                p.couleur = couleur;
                v->push_back(p);
            }
        }
    }
    //quicksort
    quickSort(*v, 0, v->size());

    //affichage n points
    int nbAffichage = 100;
    for (int q = 0; q < nbAffichage; ++q) {
        pointI x = (*v)[q];
        nouvelleImage = croixRouge(x, image);
    }

    return nouvelleImage;
}

QImage * pointsDinterets::croixRouge(struct pointI p, QImage *image){

    int imWidth = image->width();
    int imHeight = image->height();
    int pos_x = p.x;
    int pos_y = p.y;

    QRgb color = qRgb(255, 0, 0);

    image->setPixel(pos_x, pos_y, color);

    if( pos_x>=1){
        image->setPixel(pos_x-1, pos_y, color);
    }
    if( pos_y>=1){
        image->setPixel(pos_x, pos_y-1, color);
    }
    if( pos_x<imWidth-1){
        image->setPixel(pos_x+1, pos_y, color);
    }
    if( pos_y<imHeight-1){
        image->setPixel(pos_x, pos_y+1, color);
    }

    return image;

}

void pointsDinterets::quickSort(vector<struct pointI>& A, int p,int q){
    int r;
    if(p<q){
        r = partition(A, p,q);
        quickSort(A,p,r);
        quickSort(A,r+1,q);
    }
}


int pointsDinterets::partition(vector<struct pointI>& A, int p,int q){
    int R, R2;
    pointI x = A[p];
    R = qRed(x.couleur);
    int i = p;
    int j;
    for(j = p+1; j<q; j++){
        pointI x2 = A[j];
        R2 = qRed(x2.couleur);
        if( R2 <= R){
            i = i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i],A[p]);
    return i;
}
