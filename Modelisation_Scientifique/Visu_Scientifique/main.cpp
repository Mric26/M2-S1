
#include <climits>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <QFile>
#include <QImage>
#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include <QString>
#include <QTextStream>

#include "csv_meteofranceparser.h"

#define RESO_INTERPOLE 100   // Resolution de la grille interpolante
#define RESO 10             // Taille (en pixel) des carres du marchingSquare

QString* pathPoste = new QString("../Data/postesSynop_modif.csv");
QString* pathDatas = new QString("../Data/synop.2015110912.csv");
float mu = 2;   // Coefficient de l'interpolant de Shepard


// Dessine l'isoligne dans un QPainter
void drawCube(QPainter &painter, size_t i, size_t j, const std::vector< std::vector< float >* >* interpoleShepard, const std::vector< std::vector< short >* >* square, float isoLine) {
    painter.setPen(Qt::red);
    painter.drawRect(i*RESO, j*RESO, RESO, RESO);

    int n = square->at(i)->at(j);
    bool b = ((interpoleShepard->at(i)->at(j) + interpoleShepard->at(i)->at(j+1) +
              interpoleShepard->at(i+1)->at(j+1) + interpoleShepard->at(i+1)->at(j)) / 4.0) > isoLine;

    // Calcul des coefficients
    float is1 = interpoleShepard->at(i)->at(j);
    float is2 = interpoleShepard->at(i)->at(j+1);
    float is3 = interpoleShepard->at(i+1)->at(j+1);
    float is4 = interpoleShepard->at(i+1)->at(j);
    float t1 = (isoLine - is1) / (is2 - is1);
    float t2 = (isoLine - is2) / (is3 - is2);
    float t3 = (isoLine - is4) / (is3 - is4);
    float t4 = (isoLine - is1) / (is4 - is1);

    QPoint p1 = QPoint(-1, -1);
    QPoint p2 = QPoint(-1, -1);
    QPoint pt1 = QPoint((j+t1)*RESO, i*RESO);
    QPoint pt2 = QPoint((j+1)*RESO, (i+t2)*RESO);
    QPoint pt3 = QPoint((j+t3)*RESO, (i+1)*RESO);
    QPoint pt4 = QPoint(j*RESO, (i+t4)*RESO);

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

// Retourne la distance euclidienne
float distance(float x1, float y1, float x2, float y2) {
    return sqrt( pow(x2-x1, 2) + pow(y2-y1, 2) );
}

// Calcul les extremas
void findExtrema(float &min, float &max, std::vector<std::string>* data) {
    float d;
    min = INT_MAX;
    max = INT_MIN;
    for (unsigned int i = 0; i < data->size(); ++i) {
        d = atof(data->at(i).c_str());
        min = (d < min) ? d : min;
        max = (d > max) ? d : max;
    }
}


// Interpolation de Shepard
void computeShepard(std::vector< std::vector< float >* >* interpoleData, std::vector<std::string>* latitude, std::vector<std::string>* longitude, std::vector<std::string>* data) {

    float lati, longi;
    int reso = RESO_INTERPOLE;

    float minLat, maxLat;
    float minLong, maxLong;
    findExtrema(minLat, maxLat, latitude);
    findExtrema(minLong, maxLong, longitude);

    // interpolation sur toutes les grilles
    for (int i = 0; i < reso; ++i) {
        for (int j = 0; j < reso; ++j) {
            lati = minLat + ((double(i)/(reso-1)) * (maxLat - minLat));
            longi = minLong + ((double(j)/(reso-1)) * (maxLong - minLong));

            // calcul de s pour wk
            float s = 0;
            for (unsigned int l = 0; l < data->size(); ++l) {
                float latil = atof(latitude->at(l).c_str());
                float longil = atof(longitude->at(l).c_str());
                s += 1.0 / pow(distance(lati, longi, latil, longil), mu);
            }

            // interpolation des donnees
            float eval = 0;
            for (unsigned int k = 0; k < data->size(); ++k) {
                float latik = atof(latitude->at(k).c_str());
                float longik = atof(longitude->at(k).c_str());

                float wk = (1.0 / pow(distance(lati, longi, latik, longik), mu)) * (1.0 / s);
                eval += wk * atof(data->at(k).c_str());
            }

            interpoleData->at(i)->at(j) = eval;
        }
    }

}

// Calcul l'etat de chaque square en fonction d'une isoligne
void computeMarchingSquare(std::vector< std::vector< short >* >* square, std::vector< std::vector< float >* >* interpoleData, float isoLine) {
    // Calcul des etats de chaque square
    int resoSquare = RESO_INTERPOLE - 1;
    bool v1, v2, v3, v4;
    short bit;
    for (int i = 0; i < resoSquare; ++i) {
        for (int j = 0; j < resoSquare; ++j) {
            v1 = (interpoleData->at(i)->at(j) >= isoLine);
            v2 = (interpoleData->at(i)->at(j+1) >= isoLine);
            v3 = (interpoleData->at(i+1)->at(j+1) >= isoLine);
            v4 = (interpoleData->at(i+1)->at(j) >= isoLine);
            bit = v1 + (v2 * 2) + (v3 * 4) + (v4 * 8);
            square->at(i)->at(j) = bit;
        }
    }
}

// Calcul la colormap sur l'image
void computeColormap(QImage *colormap, QRgb color1, QRgb color2, std::vector< std::vector< float >* >* interpoleData) {
    int reso = RESO_INTERPOLE;
    int resoSquare = RESO_INTERPOLE - 1;
    float minD = INT_MAX;
    float maxD = INT_MIN;

    // calcul du min et du max
    for (int i = 0; i < reso; ++i) {
        for (int j = 0; j < reso; ++j) {
            float d = interpoleData->at(i)->at(j);
            minD = (d < minD) ? d : minD;
            maxD = (d > maxD) ? d : maxD;
        }
    }

    // calcul de la colormap
    for (int i = 0; i < resoSquare; ++i) {
        for (int j = 0; j < resoSquare; ++j) {
            float t = (interpoleData->at(i)->at(j) - minD) / (maxD - minD);
            float r = (1-t)*qRed(color1) + t * qRed(color2);
            float g = (1-t)*qGreen(color1) + t * qGreen(color2);
            float b = (1-t)*qBlue(color1) + t * qBlue(color2);
            colormap->setPixel(i, j, qRgba(r, g, b, 200));
        }
    }
}

// Ecriture dans un fichier KML pour afficher des donnees ponctuelles
void writeKmlInfoFile(QString filename, std::vector<std::string>* infos, std::vector<std::string>* latitude, std::vector<std::string>* longitude) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);
    out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    out << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << endl;
    out << "  <Document>" << endl;
    for (unsigned int i = 0; i < infos->size(); ++i) {
        out << "  <Placemark>" << endl;
        out << "    <name>" << infos->at(i).c_str() << "</name>" << endl;
        out << "    <Point>" << endl;
        out << "      <coordinates>" << atof(longitude->at(i).c_str()) << "," << atof(latitude->at(i).c_str()) << ",0</coordinates>" << endl;
        out << "    </Point>" << endl;
        out << "  </Placemark>" << endl;
    }
    out << "  </Document>" << endl;
    out << "</kml>" << endl;
}

// Ecriture d'un fichier KML pour afficher une image
void writeKmlImgFile(QString filename, float minLong, float maxLong, float minLat, float maxLat) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);
    out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    out << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << endl;
    out << "  <Folder>" << endl;
    out << "    <name>Ground Overlays</name>" << endl;
    out << "    <GroundOverlay>" << endl;
    out << "      <name>Large-scale overlay on terrain</name>" << endl;
    out << "      <Icon>" << endl;
    out << "        <href>../Image/colormapShepard.png</href>" << endl;
    out << "      </Icon>" << endl;
    out << "      <LatLonBox>" << endl;
    out << "        <north>" << maxLat << "</north>" << endl;
    out << "        <south>" << minLat << "</south>" << endl;
    out << "        <east>" << minLong << "</east>" << endl;
    out << "        <west>" << maxLong << "</west>" << endl;
    out << "      </LatLonBox>" << endl;
    out << "    </GroundOverlay>" << endl;
    out << "  </Folder>" << endl;
    out << "</kml>" << endl;
}


int main() {

    // importation des donnees
    Csv_meteoFranceParser* csvPoste = new Csv_meteoFranceParser(pathPoste);
    Csv_meteoFranceParser* csvDatas = new Csv_meteoFranceParser(pathDatas);
    Csv_meteoFranceParser* csvJoin = csv_join_force(csvPoste, csvDatas, std::string("ID"), std::string("numer_sta"), std::string("Id_Fusion"));

    // selection des donnes requises (latitude, longitude, temperature, ...)
    std::vector<std::string>* id = (*csvJoin)[std::string("Id_Fusion")];
    std::vector<std::string>* cities = (*csvPoste)[std::string("Nom")];
    std::vector<std::string>* latitude = (*csvJoin)[std::string("Latitude")];
    std::vector<std::string>* longitude = (*csvJoin)[std::string("Longitude")];
    std::vector<std::string>* kelvin = (*csvJoin)[std::string("t")];


    int reso = RESO_INTERPOLE;
    std::vector< std::vector< float >* >* interpoleShepard = new std::vector< std::vector< float >* >(reso);
    for (int i = 0; i < reso; ++i) {
        (*interpoleShepard)[i] = new std::vector<float>(reso);
    }

    int resoSquare = reso-1;
    std::vector< std::vector< short >* >* square = new std::vector< std::vector< short >* >(resoSquare);
    for (int i = 0; i < resoSquare; ++i) {
        (*square)[i] = new std::vector<short>(resoSquare);
    }


    // interpolation des temperatures
    computeShepard(interpoleShepard, latitude, longitude, kelvin);

    float minLong, maxLong;
    float minLat, maxLat;
    float minT, maxT;
    findExtrema(minLong, maxLong, longitude);
    findExtrema(minLat, maxLat, latitude);
    findExtrema(minT, maxT, kelvin);

    QImage *imgSquare = new QImage(resoSquare * RESO, resoSquare * RESO, QImage::Format_RGB32);
    int count = 1;

    // calcul des isolignes
    for (float isoLine = minT; isoLine < maxT; isoLine += 1) {

        computeMarchingSquare(square, interpoleShepard, isoLine);

        // initialisation de l'image de sortie
        imgSquare->fill(qRgb(0,0,0));

        // representation du marching square
        QPainter painter(imgSquare);
        for (int i = 0; i < resoSquare; ++i) {
            for (int j = 0; j < resoSquare; ++j) {
                drawCube(painter, i, j, interpoleShepard, square, isoLine);
            }
        }

        imgSquare->save(QString("../Images/anim" + QString::number(count) + ".png"));
        std::cout << "n° : " << count << std::endl;
        count++;
    }


    QImage *colormap = new QImage(resoSquare, resoSquare, QImage::Format_ARGB32);
    QRgb color1 = qRgb(0, 0, 255);
    QRgb color2 = qRgb(255, 0, 0);

    // calcul de la colormap
    computeColormap(colormap, color1, color2, interpoleShepard);
    colormap->save(QString("../Images/colormapShepard.png"));

    writeKmlInfoFile(QString("../cities.kml"), cities, latitude, longitude);
    writeKmlImgFile(QString("../colormapShepard.kml"), minLong, maxLong, minLat, maxLat);

    std::cout << "Delete memory" << std::endl;
    delete csvPoste;
    delete csvDatas;
    delete csvJoin;
    delete id;
    delete latitude;
    delete longitude;
    delete kelvin;
    delete imgSquare;
    delete colormap;

    std::cout << "Fin" << std::endl;
    return 0;
}
