#ifndef KMOYENNE_H
#define KMOYENNE_H

#include <QImage>
#include <vector>

class kmoyenne
{
public:
    kmoyenne();
    QImage* kMoyenne(QImage *image, unsigned int k);
};

#endif // KMOYENNE_H
