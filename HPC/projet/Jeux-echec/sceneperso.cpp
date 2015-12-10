#include "sceneperso.h"
#include <mainwindow.h>

scenePerso::scenePerso(QObject *parent, MainWindow * mw) : QGraphicsScene(parent){
    w = mw;
    itemSelected = NULL;
}

void scenePerso::mousePressEvent(QMouseEvent *event){
    std::cout << "Position du clique : " << event->x() << " ; " << event->y() << std::endl;
    if( itemSelected != NULL ){
        itemSelected->setPos( event->pos() );
        itemSelected = NULL;
    }
    else {
        itemSelected = w->scene->itemAt( event->pos() );
        if( itemSelected != 0 ){
            itemSelected->setSelected( true );
        }
    }
}
