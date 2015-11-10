#include "pointsdinterets.h"
#include "seuillage.h"
#include "boost/numeric/ublas/matrix.hpp"

using namespace std;

QImage * pointsDinterets::calculpointsDinterets(QImage *image, double alpha){

    int imWidth = image->width();
    int imHeight = image->height();

    boost::numeric::ublas::matrix<int> tabxc(imWidth,imHeight);
    boost::numeric::ublas::matrix<int> tabyc(imWidth,imHeight);
    boost::numeric::ublas::matrix<int> tabxy(imWidth,imHeight);
    boost::numeric::ublas::matrix<int> harris(imWidth,imHeight);

    //copie image
    QImage *nouvelleImage = new QImage(*image);

    //calculs preliminaires des matrices
    Convolution c;
    QImage *ix = c.gradientX(image);
    QImage *iy = c.gradientY(image);
    int R1, R2;

    for (int i = 0; i < imWidth-1; ++i) {
        for (int j = 0; j < imHeight-1; ++j) {
            R1 = qRed(ix->pixel(i,j));
            R2 = qRed(iy->pixel(i,j));

            tabxc(i,j) = R1 * R1;
            tabyc(i,j) = R2 * R2;
            tabxy(i,j) = R1 * R2;
        }
    }

    //fonction de harris
    for (int i = 0; i < imWidth-1; ++i) {
        for (int j = 0; j < imHeight-1; ++j) {
            double v1, v2, v4, D;
            v1 = tabxc(i,j);
            v2 = tabxy(i,j);
            v4 = tabyc(i,j);
            D = v1*v2 - v4;
            harris(i,j) = D*D - alpha*(v1+v2*v1+v2);
        }
    }

    //extraction des maxima locaux
    int V, Vt;
    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {
            V = harris(i,j);
            //negatif
            if( V<0 ){
                harris(i,j) = 0;
            }
            else{
                //maxima locaux
                for (int k = -1; k < 2; k++) {
                    for (int l = -1; l < 2; ++l) {
                        if( (i+k<0) || (i+k>imWidth-1) || (j+l<0) || (j+l>imHeight-1) ){
                            //ne fait rien
                        }
                        else{
                            Vt = harris(i+k,j+l);
                            if( V<Vt ){
                                harris(i,j) = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    //extraction n meilleurs points
    //mise en vector
    int vh;
    struct pointI p;
    vector<struct pointI> * v = new vector<struct pointI>;
    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {
            vh = harris(i,j);
            if( vh != 0 ){
                p.x = i;
                p.y = j;
                p.val = vh;
                v->push_back(p);
            }
        }
    }

    //quicksort
    quickSort(*v, 0, v->size());

    //affichage n points
    int nbAffichage;
    if( v->size() > 50 ){
        nbAffichage = 50;
    }
    else{
        nbAffichage = v->size();
    }
    for (int q = 0; q < nbAffichage; ++q) {
        pointI x = (*v)[q];
        nouvelleImage = croixRouge(x, nouvelleImage);
    }

    return nouvelleImage;
}

QImage * pointsDinterets::croixRouge(struct pointI p, QImage *image){

    int imWidth = image->width();
    int imHeight = image->height();
    int pos_x = p.x;
    int pos_y = p.y;
    cout << "( " << pos_x << " ; " << pos_y << " )" << endl;
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
    int v, v2;
    pointI x = A[p];
    v = x.val;
    int i = p;
    int j;
    for(j = p+1; j<q; j++){
        pointI x2 = A[j];
        v2 = x2.val;
        if( v2 <= v){
            i = i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i],A[p]);
    return i;
}
