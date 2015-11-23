#ifndef BORDSOBJETS_H
#define BORDSOBJETS_H

#include <QImage>
#include <unistd.h>
#include <iostream>

class bordsObjets{

public:

    std::vector<int> *bords8(QImage *image);
    QPoint *find_Origine(QImage *image);
    bool pixel_bord(QPoint *p, QImage *image);
    QPoint *point_suivant(QPoint *p, int dir);

};

#endif // BORDSOBJETS_H
