
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <climits>
#include <math.h>

#include <QString>
#include <QImage>

#include "csv_meteofranceparser.h"

QString* pathPoste = new QString("../Data/postesSynop.csv");
QString* pathDatas = new QString("../Data/synop.2015110912.csv");
float mu = 2;   // Coefficient de l'interpolant de Shepard
float isoLine = 295.0;


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

    size_t reso = 100;
    std::vector< std::vector< float >* >* interpoleShepard = new std::vector< std::vector< float >* >(reso);
    for (size_t i = 0; i < reso; ++i) {
        (*interpoleShepard)[i] = new std::vector<float>(reso);
    }

    size_t resoSquare = 10;
    std::vector< std::vector< short >* >* square = new std::vector< std::vector< short >* >(resoSquare);
    for (size_t i = 0; i < resoSquare; ++i) {
        (*square)[i] = new std::vector<short>(resoSquare);
    }

    float lati = 0;
    float longi = 0;

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

    // Calcul des isolignes
    bool v1, v2, v3, v4;
    short bit;
    for (size_t i = 0; i < resoSquare-1; ++i) {
        for (size_t j = 0; j < resoSquare-1; ++j) {
            v1 = (interpoleShepard->at(i*resoSquare)->at(j*resoSquare) >= isoLine);
            v2 = (interpoleShepard->at(i*resoSquare)->at((j+1)*resoSquare) >= isoLine);
            v3 = (interpoleShepard->at((i+1)*resoSquare)->at(j*resoSquare) >= isoLine);
            v4 = (interpoleShepard->at((i+1)*resoSquare)->at((j+1)*resoSquare) >= isoLine);
            bit = v1 + (v2 * 2) + (v3 * 4) + (v4 * 8);
            square->at(i)->at(j) = bit;
        }
    }





    // Creation de l'image a afficher
    QImage *img = new QImage(reso, reso, QImage::Format_RGB32);


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
