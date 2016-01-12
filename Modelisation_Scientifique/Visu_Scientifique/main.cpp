
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <climits>
#include <math.h>

#include <QString>
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QPoint>

#include "csv_meteofranceparser.h"

#define RESO_INTERPOLE 50
#define RESO 10

QString* pathPoste = new QString("../Data/postesSynop_modif.csv");
QString* pathDatas = new QString("../Data/synop.2015110912.csv");
float mu = 2;   // Coefficient de l'interpolant de Shepard
float isoLine = 290.0;


void fillInfo(Csv_meteoFranceParser* csvInfos, float* minLat, float* maxLat, float* minLong, float* maxLong, float* minT, float* maxT) {
    std::vector<std::string>* latitude = (*csvInfos)[std::string("Latitude")];
    std::vector<std::string>* longitude = (*csvInfos)[std::string("Longitude")];
    std::vector<std::string>* kelvin = (*csvInfos)[std::string("t")];

    unsigned int nbData = latitude->size();
    float lati, longi, t;

    // Calcul des min/max
    for (unsigned int i = 0; i < nbData; ++i) {
        lati = atof(latitude->at(i).c_str());
        longi = atof(longitude->at(i).c_str());
        t = atof(kelvin->at(i).c_str());

        *minLat = (lati < *minLat) ? lati : *minLat;
        *maxLat = (lati > *maxLat) ? lati : *maxLat;
        *minLong = (longi < *minLong) ? longi : *minLong;
        *maxLong = (longi > *maxLong) ? longi : *maxLong;
        *minT = (t < *minT) ? t : *minT;
        *maxT = (t > *maxT) ? t : *maxT;
    }
}

void drawCube(QPainter &painter, size_t i, size_t j, std::vector< std::vector< short >* >* square, bool b) {
    painter.setPen(Qt::red);
    painter.drawRect(i*RESO, j*RESO, RESO, RESO);

    int n = square->at(i)->at(j);

    QPoint p1 = QPoint(-1, -1);
    QPoint p2 = QPoint(-1, -1);
    float t1 = 0.0;
    float t2 = 0.0;
    float t3 = 0.0;
    float t4 = 0.0;
    QPoint pt1 = QPoint(j*RESO + (RESO/2), i*RESO);
    QPoint pt2 = QPoint(j*RESO + RESO, i*RESO + (RESO/2));
    QPoint pt3 = QPoint(j*RESO + (RESO/2), i*RESO + RESO);
    QPoint pt4 = QPoint(j*RESO, i*RESO + (RESO/2));

    if (n == 0 || n == 15) {

    }

    if (n == 1 || n == 14) {
        p1 = pt1;
        p2 = pt4;
    } else if (n == 2 || n == 13) {
        p1 = pt1;
        p2 = pt2;
    } else if (n == 4 || n == 11) {
        p1 = pt2;
        p2 = pt3;
    } else if (n == 7 || n == 8) {
        p1 = pt3;
        p2 = pt4;
    }

    if (n == 3 || n == 12) {
        p1 = pt2;
        p2 = pt4;
    } else if (n == 5) {
        if (b) {
            p1 = pt1;
            p2 = pt2;
            painter.setPen(Qt::yellow);
            painter.drawLine(pt3, pt4);
        } else {
            p1 = pt1;
            p2 = pt4;
            painter.setPen(Qt::yellow);
            painter.drawLine(pt2, pt3);
        }
    } else if (n == 6 || n == 9) {
        p1 = pt1;
        p2 = pt3;
    } else if (n == 10) {
        if (b) {
            p1 = pt1;
            p2 = pt4;
            painter.setPen(Qt::yellow);
            painter.drawLine(pt2, pt3);
        } else {
            p1 = pt1;
            p2 = pt2;
            painter.setPen(Qt::yellow);
            painter.drawLine(pt3, pt4);
        }
    }

    painter.setPen(Qt::yellow);
    painter.drawLine(p1, p2);
}

float distance(float x1, float y1, float x2, float y2) {
    return sqrt( pow(x2-x1, 2) + pow(y2-y1, 2) );
}


int main() {

    Csv_meteoFranceParser* csvPoste = new Csv_meteoFranceParser(pathPoste);
    Csv_meteoFranceParser* csvDatas = new Csv_meteoFranceParser(pathDatas);


    Csv_meteoFranceParser* csvJoin = csv_join_force(csvPoste, csvDatas, std::string("ID"), std::string("numer_sta"), std::string("Id_Fusion"));
    //csvJoin->showMap();

    std::vector<std::string>* id = (*csvJoin)[std::string("Id_Fusion")];
    std::vector<std::string>* latitude = (*csvJoin)[std::string("Latitude")];
    std::vector<std::string>* longitude = (*csvJoin)[std::string("Longitude")];
    std::vector<std::string>* kelvin = (*csvJoin)[std::string("t")];

    unsigned int nbData = id->size();   // nombre de donnees acquises
    float minLat = INT_MAX;
    float maxLat = INT_MIN;
    float minLong = INT_MAX;
    float maxLong = INT_MIN;
    float minT = INT_MAX;
    float maxT = INT_MIN;

    fillInfo(csvJoin, &minLat, &maxLat, &minLong, &maxLong, &minT, &maxT);
    std::cout << minLat << ", " << maxLat << std::endl;
    std::cout << minLong << ", " << maxLong << std::endl;
    std::cout << minT << ", " << maxT << std::endl;

    size_t reso = RESO_INTERPOLE;
    std::vector< std::vector< float >* >* interpoleShepard = new std::vector< std::vector< float >* >(reso);
    for (size_t i = 0; i < reso; ++i) {
        (*interpoleShepard)[i] = new std::vector<float>(reso);
    }

    size_t resoSquare = reso-1;
    std::vector< std::vector< short >* >* square = new std::vector< std::vector< short >* >(resoSquare);
    for (size_t i = 0; i < resoSquare; ++i) {
        (*square)[i] = new std::vector<short>(resoSquare);
    }

    float lati, longi;

    // Interpolation de Shepard
    for (size_t i = 0; i < reso; ++i) {
        for (size_t j = 0; j < reso; ++j) {
            lati = minLat + ((double(i)/(reso-1)) * (maxLat - minLat));
            longi = minLong + ((double(j)/(reso-1)) * (maxLong - minLong));

            // interpolation de la temperature
            float eval = 0;
            for (size_t k = 0; k < nbData; ++k) {
                float latik = atof(latitude->at(k).c_str());
                float longik = atof(longitude->at(k).c_str());

                // calcul de wk
                float s = 0;
                for (size_t l = 0; l < nbData; ++l) {
                    float latil = atof(latitude->at(l).c_str());
                    float longil = atof(longitude->at(l).c_str());
                    s += 1.0 / pow(distance(lati, longi, latil, longil), mu);
                }
                float wk = (1.0 / pow(distance(lati, longi, latik, longik), mu)) * (1.0 / s);
                eval += wk * atof(kelvin->at(k).c_str());;
            }

            interpoleShepard->at(i)->at(j) = eval;
        }
    }

    QImage *img = new QImage(resoSquare * RESO, resoSquare * RESO, QImage::Format_RGB32);
    int i = 1;
    for (float isoLigne = 288.0; isoLigne < 295.0; isoLigne += 1) {

        // Calcul des isolignes
        bool v1, v2, v3, v4;
        short bit;
        for (size_t i = 0; i < resoSquare; ++i) {
            for (size_t j = 0; j < resoSquare; ++j) {
                v1 = (interpoleShepard->at(i)->at(j) >= isoLigne);
                v2 = (interpoleShepard->at(i)->at(j+1) >= isoLigne);
                v3 = (interpoleShepard->at(i+1)->at(j+1) >= isoLigne);
                v4 = (interpoleShepard->at(i+1)->at(j) >= isoLigne);
                bit = v1 + (v2 * 2) + (v3 * 4) + (v4 * 8);
                square->at(i)->at(j) = bit;
            }
        }


        // Initialisation de l'image de sortie
        img->fill(qRgb(0,0,0));

        // Representation du marching square
        QPainter painter(img);
        for (size_t i = 0; i < resoSquare; ++i) {
            for (size_t j = 0; j < resoSquare; ++j) {
                bool b = ((interpoleShepard->at(i)->at(j) + interpoleShepard->at(i)->at(j+1) +
                          interpoleShepard->at(i+1)->at(j+1) + interpoleShepard->at(i+1)->at(j)) / 4.0) > isoLigne;
                drawCube(painter, i, j, square, b);
            }
        }

        img->save(QString("../Images/Anim" + QString::number(i) + ".png"));
        i++;
        std::cout << "n° : " << i << std::endl;
    }
    delete img;


    std::cout << "Delete memory" << std::endl;
    delete csvPoste;
    delete csvDatas;
    delete csvJoin;
    delete id;
    delete latitude;
    delete longitude;
    delete kelvin;

    std::cout << "Fin" << std::endl;
    return 0;
}
