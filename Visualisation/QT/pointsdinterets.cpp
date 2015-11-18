#include "pointsdinterets.h"
#include "seuillage.h"
#include "convolution.h"
#include "grisconvers.h"

using namespace std;
using namespace boost::numeric::ublas;

std::vector<pointsDinterets::pointI> * pointsDinterets::calculpointsDinterets(QImage *image, double alpha){

    int imWidth = image->width();
    int imHeight = image->height();

    matrix<double> tabxc(imWidth,imHeight);
    matrix<double> tabyc(imWidth,imHeight);
    matrix<double> tabxy(imWidth,imHeight);
    matrix<double> harris(imWidth,imHeight);

    //calculs preliminaires des matrices
    Convolution c;
    QImage *ix = c.gradientX(image);
    QImage *iy = c.gradientY(image);
    double R1, R2;

    for (int i = 0; i < imWidth-1; ++i) {
        for (int j = 0; j < imHeight-1; ++j) {
            R1 = qRed(ix->pixel(i,j));
            R2 = qRed(iy->pixel(i,j));

            tabxc(i,j) = R1 * R1;
            tabyc(i,j) = R2 * R2;
            tabxy(i,j) = R1 * R2;
        }
    }

    //lissage
//    tabxc = lissage(tabxc);
//    tabyc = lissage(tabyc);
//    tabxy = lissage(tabxy);

    //fonction de harris
    for (int i = 0; i < imWidth-1; ++i) {
        for (int j = 0; j < imHeight-1; ++j) {
            double A, B, C, D;
            A = tabxc(i,j);
            B = tabyc(i,j);
            C = tabxy(i,j);
            D = (A*B) - C;
            harris(i,j) = (D*D) - (alpha*((A+B)*(A+B)));
        }
    }

    harris = seuillage(harris);

    //extraction des maxima locaux
    double V, Vt;
    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {
            V = harris(i,j);
            //negatif
            if( V<=0 ){
                harris(i,j) = 0;
            }
            else{
                //maxima locaux
                for (int k = -1; k < 2; k++) {
                    for (int l = -1; l < 2; ++l) {
                        if( (i+k<0) || (i+k>imWidth-1) || (j+l<0) || (j+l>imHeight-1) || ((k==0)&&(l==0)) ){
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
    double vh;
    std::vector<struct pointI> * v = new std::vector<struct pointI>;
    for (int i = 0; i < imWidth; ++i) {
        for (int j = 0; j < imHeight; ++j) {
            vh = harris(i,j);
            if( vh != 0 ){
                struct pointI p;
                p.x = i;
                p.y = j;
                p.val = vh;
                v->push_back(p);
            }
        }
    }

    //quicksort
    quickSort(*v, 0, v->size());

    return v;
}

QImage * pointsDinterets::affichageHarris(QImage *image, double alpha){
    QImage *nouvelleImage = new QImage(*image);

    //calcul des points
    std::vector<struct pointI> * v = calculpointsDinterets(image, alpha);

    //affichage n points
    int nbAffichage;
    if( v->size() > 250 ){
        nbAffichage = 250;
    }
    else{
        nbAffichage = v->size();
    }
    for (int q = v->size(); q > v->size()-nbAffichage; --q) {
        pointI x = (*v)[q];
        nouvelleImage = croixRouge(x, nouvelleImage);
    }

    return nouvelleImage;
}

QImage * pointsDinterets::comparaisonHarris(MainWindow * w){
    QImage *nouvelleImage;

    //chargement des images
    QString chemin1 = QFileDialog::getOpenFileName(w,"Ouvrir un fichier", QDir::currentPath() + "/../Images/Harris/graffiti", "Image Files (*.png *.jpg *.pgm)");
    QImage * image1 = new QImage();
    bool charge1 = image1->load(chemin1);

    QString chemin2 = QFileDialog::getOpenFileName(w,"Ouvrir un fichier", QDir::currentPath() + "/../Images/Harris/graffiti", "Image Files (*.png *.jpg *.pgm)");
    QImage * image2 = new QImage();
    bool charge2 = image2->load(chemin2);

    //si chargement réussi
    if(charge1 && charge2){
        //calculs des tailles
        int imWidth1 = image1->width();
        int imHeight1 = image1->height();

        int imWidth2 = image2->width();
        int imHeight2 = image2->height();

        int resWidth = imWidth1 + imWidth2 + 5;
        int resHeight = max(imHeight1, imHeight2);

        //resultats
        nouvelleImage = new QImage(resWidth, resHeight, QImage::Format_RGB32);

        //calcul des harris
        GrisConvers gc;
        image1 = gc.versGris(image1);
        image1 = affichageHarris(image1, 0.04);
        image2 = gc.versGris(image2);
        image2 = affichageHarris(image2, 0.04);

        //affichages des images
        int i, j;

        for (i = 0; i < imWidth1; ++i) {
            for (j = 0; j < imHeight1; ++j) {
                nouvelleImage->setPixel( i, j, image1->pixel(i,j) );
            }
        }

        QRgb color = qRgb(255, 0, 0);
        for (i = imWidth1; i < imWidth1+5; ++i) {
            for (j = 0; j < imHeight1; ++j) {
                nouvelleImage->setPixel( i, j, color );
            }
        }

        for (i = imWidth1+5; i < resWidth; ++i) {
            for (j = 0; j < imHeight1; ++j) {
                nouvelleImage->setPixel( i, j, image2->pixel(i-(imWidth1+5),j) );
            }
        }

    }
    else{
        nouvelleImage = new QImage();
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

void pointsDinterets::quickSort(std::vector<struct pointI>& A, int p,int q){
    int r;
    if(p<q){
        r = partition(A, p,q);
        quickSort(A,p,r);
        quickSort(A,r+1,q);
    }
}


int pointsDinterets::partition(std::vector<struct pointI>& A, int p,int q){
    double v, v2;
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

matrix<double> pointsDinterets::lissage( matrix<double> tab){
    int largeur = tab.size1();
    int hauteur = tab.size2();
    matrix<double> res(largeur,hauteur);

    int taille = 3;
    Convolution conv;
    float ** noyau = conv.genererBinomial(taille);
    int l = (taille-1)/2;
    int c = (taille-1)/2;

    double val = 0;
    double temp = 0;

    for (int i = 0; i < largeur; ++i) {
        for (int j = 0; j < hauteur; ++j) {
                val = 0;
                temp = 0;
                for (int m = -l; m < l+1; ++m) {
                    for (int n = -c; n < c+1; ++n) {
                        if (i-m > -1 && j-n > -1 && i-m < largeur && j-n < hauteur) {
                            temp = tab(i-m,j-n);
                        }else {
                            temp = tab(i,j);
                        }
                         val = val + noyau[m+c][n+l] * temp;
                    }
                }
                res(i,j) = int(val+0.5);
            }
    }
    return res;
}

matrix<double> pointsDinterets::seuillage( matrix<double> tab){
    int largeur = tab.size1();
    int hauteur = tab.size2();
    matrix<double> res(largeur,hauteur);

    for (int i = 0; i < largeur; ++i) {
        for (int j = 0; j < hauteur; ++j) {
            if( tab(i,j) > 1000000000 ){
                res(i,j) = tab(i,j);
            }
            else{
                res(i,j) = 0;
            }
        }
    }

    return res;
}

QImage * pointsDinterets::matrixToQimage(QImage* image, matrix<double> tab){
    int imWidth = image->width();
    int imHeight = image->height();

    QImage *nouvelleImage = new QImage(imWidth, imHeight, image->format() );

    for (int i = 0; i < imWidth-1; ++i) {
        for (int j = 0; j < imHeight-1; ++j) {
            double v = tab(i,j);
            if( v > 255){
                v = 255;
            }
            else if( v < 0 ){
                v = 0;
            }
            nouvelleImage->setPixel(i, j, qRgb(v,v,v) );
        }
    }
    return nouvelleImage;
}
