#include "cavalier.h"

cavalier::cavalier(int color):pieces(QString("cavalier"), color){
    if (color == 0) {
        setRep(new QPixmap(":images/cavb"));
    } else {
        setRep(new QPixmap(":images/cavn"));
    }
}
