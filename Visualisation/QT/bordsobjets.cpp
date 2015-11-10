#include "bordsobjets.h"

using namespace std;

vector<int> *bordsObjets::bords8( QImage *image ){
    vector<int> * v = new vector<int>();

    QPoint * origine = find_Origine(image);
    QPoint * second = new QPoint(0,0);
    QPoint * courant = origine;
    QPoint * temp;

    int dir = 4;
    int maj[8] = {6,6,0,0,2,2,4,4};

    bool premier_vu = false;
    bool second_vu = false;

    //parcours de la forme
    while( !premier_vu || !second_vu ){

        //recherche point suivant
        temp = point_suivant( courant, dir );
        while( pixel_bord(temp, image) == false ){
            dir = (dir+1) % 8;
            temp = point_suivant( courant, dir );
        }
        courant = temp;

        //conditions d'arrêt
        if( second->isNull() ){
            second->setX(courant->x());
            second->setY(courant->y());
        }
        if( !premier_vu && (courant->x() == origine->x()) && (courant->y() == origine->y()) ){
            premier_vu = true;
        }
        if( premier_vu && (courant->x() == second->x()) && (courant->y() == second->y()) ){
            second_vu = true;
        }

        //ajout et maj de dir
        if( !premier_vu && !second_vu ){
            v->push_back(dir);
        }
        dir = maj[dir];
    }

    //resultat
    return v;
}

bool bordsObjets::pixel_bord( QPoint *p, QImage *image){
    if( qRed(image->pixel(p->x(),p->y()))== 255 ){
            if( (qRed(image->pixel(p->x()+1,p->y()))== 0) || (qRed(image->pixel(p->x(),p->y()+1))== 0) || (qRed(image->pixel(p->x()-1,p->y()))== 0) || (qRed(image->pixel(p->x(),p->y()-1))== 0) ){
                return true;
            }
    }
    return false;
}

QPoint * bordsObjets::point_suivant( QPoint *p, int dir ){
    /*
    3   2   1
    4   x   0
    5   6   7
    */

    if( dir == 0){
        return new QPoint( p->x()+1, p->y() );
    }
    if( dir == 1){
        return new QPoint( p->x()+1, p->y()-1 );
    }
    if( dir == 2){
        return new QPoint( p->x(), p->y()-1 );
    }
    if( dir == 3){
        return new QPoint( p->x()-1, p->y()-1 );
    }
    if( dir == 4){
        return new QPoint( p->x()-1, p->y() );
    }
    if( dir == 5){
        return new QPoint( p->x()-1, p->y()+1 );
    }
    if( dir == 6){
        return new QPoint( p->x(), p->y()+1 );
    }
    if( dir == 7){
        return new QPoint( p->x()+1, p->y()+1 );
    }

}


QPoint *bordsObjets::find_Origine( QImage *image ){
    int imWidth = image->width();
    int imHeight = image->height();

    int i, j;
    bool origine_find = false;
    QPoint * origine = new QPoint();
    QRgb p;

    i = 0;
    while ( !origine_find && (i<imWidth) ) {
    j = 0;
        while ( !origine_find && (j<imHeight) ) {
            p = image->pixel(i,j);
            if( (qRed(p)!= 0) || (qGreen(p)!= 0) || (qBlue(p)!= 0) ){
                origine->setX(i);
                origine->setY(j);
                origine_find = true;
            }
            j++;
        }
    i++;
    }

    return origine;
}
