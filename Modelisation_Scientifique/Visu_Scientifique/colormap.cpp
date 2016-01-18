#include "colormap.h"
#include <iostream>

Colormap::Colormap()
{
    this->listValue = std::vector<float>(0);
    this->listColor = std::vector<QRgb>(0);
}

void Colormap::addColor(float value, QRgb color)
{
    std::vector<float>::iterator itValue = listValue.begin();
    std::vector<QRgb>::iterator itColor = listColor.begin();
    unsigned int nb = listValue.size();

    if (nb == 0) {
        this->listValue.insert(itValue, value);
        this->listColor.insert(itColor, color);
        return;
    }

    unsigned int i = 0;
    while (i < nb && value > listValue[i]) {
        itValue++;
        itColor++;
        i++;
    }

    if (i == nb) {
        listValue.push_back(value);
        listColor.push_back(color);
    } else {
        listValue.insert(itValue, value);
        listColor.insert(itColor, color);
    }
}

void Colormap::clear()
{
    this->listValue.clear();
    this->listColor.clear();
}

void Colormap::show()
{
    for (unsigned int i = 0; i < listValue.size(); ++i) {
        QRgb rgb = listColor[i];
        float r = qRed(rgb);
        float g = qGreen(rgb);
        float b = qBlue(rgb);
        std::cout << listValue[i] << " : (" << r << "," << g << "," << b << ")" << std::endl;
    }
}

QRgb Colormap::getColorAt(float k)
{
    unsigned int nb = listValue.size();

    if (nb == 0) {
        return qRgb(0,0,0);
    }

    // Cas de base
    if (k < listValue[0]) {
        return listColor[0];
    }
    if (k > listValue[nb-1]) {
        return listColor[nb-1];
    }

    unsigned int i = 0;
    while (i < nb-1 && !( k >= listValue[i] && k < listValue[i+1] )) {
        i++;
    }

    float t = (k - listValue[i]) / (listValue[i+1] - listValue[i]);
    QRgb c1 = listColor[i];
    QRgb c2 = listColor[i+1];

    float r = (1-t)*qRed(c1) + t*qRed(c2);
    float g = (1-t)*qGreen(c1) + t*qGreen(c2);
    float b = (1-t)*qBlue(c1) + t*qBlue(c2);
    return qRgb(r,g,b);
}

