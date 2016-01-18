#ifndef COLORMAP_H
#define COLORMAP_H

#include <vector>
#include <QColor>

class Colormap
{
public:
    Colormap();
    void addColor(float value, QRgb color);
    void clear();
    void show();
    QRgb getColorAt(float i);

private:
    std::vector<float> listValue;
    std::vector<QRgb> listColor;
};

#endif // COLORMAP_H
