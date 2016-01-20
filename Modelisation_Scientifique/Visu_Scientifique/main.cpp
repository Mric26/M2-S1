
#include <climits>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <QDir>
#include <QFile>
#include <QImage>
#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include <QString>
#include <QTextStream>

#include "colormap.h"
#include "csv_meteofranceparser.h"
#include "Eigen/Dense"

#define RESO 10             // Taille (en pixel) des carres du marchingSquare

QString* pathPoste = new QString("../Data/postesSynop_modif.csv");
QString* pathDatas = new QString("../Data/synop.2015110912.csv");
int resolution = 20;       // Resolution de la grille interpolante
float mu = 2;               // Coefficient de l'interpolant pour Shepard
float R = 4;                // Coefficient de l'interpolant pour Harldy


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

void drawMarchingSquare(QImage *imgSquare, const std::vector< std::vector< short >* >* square, const std::vector< std::vector< float >* >* interpoleShepard, float isoLine) {
    int resoSquare = resolution - 1;

    // initialisation de l'image de sortie
    imgSquare->fill(qRgb(0,0,0));

    QPainter painter(imgSquare);
    // representation du marching square
    for (int i = 0; i < resoSquare; ++i) {
        for (int j = 0; j < resoSquare; ++j) {
            drawCube(painter, i, j, interpoleShepard, square, isoLine);
        }
    }
}

// Calcul la colormap sur l'image
void drawData(QImage *imgColor, Colormap *colorMap, std::vector< std::vector< float >* >* interpoleData) {
    int resoSquare = resolution - 1;

    // calcul de la colormap
    for (int i = 0; i < resoSquare; ++i) {
        for (int j = 0; j < resoSquare; ++j) {
            QRgb rgb = colorMap->getColorAt(interpoleData->at(i)->at(j));
            imgColor->setPixel(i, j, qRgba(qRed(rgb), qGreen(rgb), qBlue(rgb), 255));
        }
    }
}

// Dessine la colormap dans une image
void drawColorMap(QImage *imgSrc, Colormap *colormap, float min, float max) {
    QPainter painter(imgSrc);
    painter.fillRect(0, 0, 50, 200, qRgb(0, 0, 0));
    for (int i = 0; i < 200; ++i) {
        float t = min + (i/200.0) * (max - min);
        QColor rgb = colormap->getColorAt(t);
        painter.setPen(rgb);
        painter.drawLine(0, 199-i, 50, 199-i);
    }
    painter.end();
}


// Renvoie une colormap personnalisable
Colormap* createColorMap(float min, float max) {
    Colormap *colorMap = new Colormap();
    colorMap->addColor(min,qRgb(0,0,255));
    colorMap->addColor(min+(max-min)/4,qRgb(0,255,255));
    colorMap->addColor(min+3*(max-min)/4,qRgb(255,255,0));
    colorMap->addColor(max,qRgb(255,0,0));
//    unsigned int nb_iter = 4;
//    float dt = (max-min) / (nb_iter-1);
//    for (unsigned int k = 0; k < nb_iter; ++k) {
//        colorMap->addColor(min+k*dt, qRgb(255,k*(255/(nb_iter-1)),0));    // du rouge vers le jaune
//        float r = k*(255/(nb_iter-1));
//        float g = abs(k-(nb_iter/2.0))*(128/(nb_iter-1));
//        float b = (nb_iter-1-k)*(255/(nb_iter-1));
//        colorMap->addColor(min+k*dt, qRgb(r, g, b));    // du bleu vers le rouge
//    }
//    colorMap->addColor(min, qRgb(0,0,255));
//    colorMap->addColor(290, qRgb(0,255,0));
//    colorMap->addColor(max, qRgb(255,0,0));
    return colorMap;
}

// Interpolation de Shepard
void computeShepard(std::vector< std::vector< float >* >* interpoleData, std::vector<std::string>* latitude, std::vector<std::string>* longitude, std::vector<std::string>* data) {
    float lati, longi;
    float minLat, maxLat;
    float minLong, maxLong;
    findExtrema(minLat, maxLat, latitude);
    findExtrema(minLong, maxLong, longitude);

    // interpolation sur toutes les grilles
    for (int i = 0; i < resolution; ++i) {
        for (int j = 0; j < resolution; ++j) {
            lati = minLat + ((double(i)/(resolution-1)) * (maxLat - minLat));
            longi = minLong + ((double(j)/(resolution-1)) * (maxLong - minLong));

            // calcul de s pour wk
            float s = 0;
            for (unsigned int k = 0; k < data->size(); ++k) {
                float latik = atof(latitude->at(k).c_str());
                float longik = atof(longitude->at(k).c_str());
                s += 1.0 / pow(distance(lati, longi, latik, longik), mu);
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

// Inteprolation de Hardly
void computeHardly(std::vector< std::vector< float >* >* interpoleData, std::vector<std::string>* latitude, std::vector<std::string>* longitude, std::vector<std::string>* data) {
    unsigned int n = data->size();
    Eigen::MatrixXf A = Eigen::MatrixXf(n,n);
    Eigen::VectorXf b = Eigen::VectorXf(data->size());
    Eigen::VectorXf x;

    float lati, longi, latj, longj, latk, longk;
    float minLat, maxLat;
    float minLong, maxLong;
    findExtrema(minLat, maxLat, latitude);
    findExtrema(minLong, maxLong, longitude);

    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            lati = atof(latitude->at(i).c_str());
            longi = atof(longitude->at(i).c_str());
            latj = atof(latitude->at(j).c_str());
            longj = atof(longitude->at(j).c_str());
            A(i,j) = sqrt(R + pow(distance(longi,lati,longj,latj),2));
        }
    }

    for (unsigned int i = 0; i < data->size(); ++i) {
        b(i) = atof(data->at(i).c_str());
    }

    x = A.ldlt().solve(b);

    for (int i = 0; i < resolution; ++i) {
        for (int j = 0; j < resolution; ++j) {
            lati = minLat + ((double(i)/(resolution-1)) * (maxLat - minLat));
            longi = minLong + ((double(j)/(resolution-1)) * (maxLong - minLong));
            float eval = 0.0;
            for (unsigned int k = 0; k < n; ++k) {
                latk = atof(latitude->at(k).c_str());
                longk = atof(longitude->at(k).c_str());
                eval += x(k) * sqrt(R + pow(distance(lati, longi, latk, longk),2));
            }
            interpoleData->at(i)->at(j) = eval;
        }
    }
}

// Calcul l'etat de chaque square en fonction d'une isoligne
void computeMarchingSquare(std::vector< std::vector< short >* >* square, std::vector< std::vector< float >* >* interpoleData, float isoLine) {
    // Calcul des etats de chaque square
    int resoSquare = resolution - 1;
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
void writeKmlImgFile(QString filename, std::vector<std::string>* latitude, std::vector<std::string>* longitude) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QString path = QDir::currentPath() + "/../Images/colormapShepard.png";
    float minLat, maxLat;
    float minLong, maxLong;
    findExtrema(minLat, maxLat, latitude);
    findExtrema(minLong, maxLong, longitude);

    QTextStream out(&file);
    out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    out << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << endl;
    out << "  <Folder>" << endl;
    out << "    <name>Ground Overlays</name>" << endl;
    out << "    <GroundOverlay>" << endl;
    out << "      <name>Large-scale overlay on terrain</name>" << endl;
    out << "      <Icon>" << endl;
    out << "        <href>" << path << "</href>" << endl;
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
    std::vector<std::string>* cities = (*csvJoin)[std::string("Nom")];
    std::vector<std::string>* latitude = (*csvJoin)[std::string("Latitude")];
    std::vector<std::string>* longitude = (*csvJoin)[std::string("Longitude")];
    std::vector<std::string>* kelvin = (*csvJoin)[std::string("t")];

    float minT, maxT;
    findExtrema(minT, maxT, kelvin);

    ////////////////////////////// Instanciation //////////////////////////////
    std::vector< std::vector< float >* >* interpoleShepard = new std::vector< std::vector< float >* >(resolution);
    for (int i = 0; i < resolution; ++i) {
        (*interpoleShepard)[i] = new std::vector<float>(resolution);
    }

    std::vector< std::vector< float >* >* interpoleHarldy = new std::vector< std::vector< float >* >(resolution);
    for (int i = 0; i < resolution; ++i) {
        (*interpoleHarldy)[i] = new std::vector<float>(resolution);
    }

    int resoSquare = resolution-1;
    std::vector< std::vector< short >* >* square = new std::vector< std::vector< short >* >(resoSquare);
    for (int i = 0; i < resoSquare; ++i) {
        (*square)[i] = new std::vector<short>(resoSquare);
    }


    ////////////////////////////// Interpolation //////////////////////////////
    // interpolation des temperatures
    computeShepard(interpoleShepard, latitude, longitude, kelvin);
    computeHardly(interpoleHarldy, latitude, longitude, kelvin);
    std::vector< std::vector< float >* >* interpoleData = interpoleHarldy;

    std::cout << "Shepard" << std::endl;
    for (int i = 0; i < resolution; ++i) {
        for (int j = 0; j < resolution; ++j) {
            std::cout << interpoleShepard->at(i)->at(j) << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Hardly" << std::endl;
    for (int i = 0; i < resolution; ++i) {
        for (int j = 0; j < resolution; ++j) {
            std::cout << interpoleHarldy->at(i)->at(j) << ", ";
        }
        std::cout << std::endl;
    }


    ////////////////////////////// Creation des images //////////////////////////////
    QImage *imgSquare = new QImage(resoSquare * RESO, resoSquare * RESO, QImage::Format_RGB32);
    int count = 1;

    // calcul des isolignes avec le marching square
    for (float isoLine = minT; isoLine < maxT; isoLine += 1) {

        computeMarchingSquare(square, interpoleData, isoLine);
        drawMarchingSquare(imgSquare, square, interpoleData, isoLine);

        imgSquare->save(QString("../Images/anim" + QString::number(count) + ".png"));
        std::cout << "n° : " << count << std::endl;
        count++;
    }

    // creation de la colormap
    Colormap *colorMap = createColorMap(minT, maxT);

    // calcul de la map des couleurs
    QImage *imgColor = new QImage(resoSquare, resoSquare, QImage::Format_ARGB32);
    drawData(imgColor, colorMap, interpoleData);

    // dessine la colormap
    QImage *imgColormap = new QImage(50, 200, QImage::Format_RGB32);
    drawColorMap(imgColormap, colorMap, minT, maxT);

    // ecriture dans les fichiers de sorties
    imgColormap->save(QString("../Images/colorMap.png"));
    imgColor->save(QString("../Images/colorData.png"));
    writeKmlInfoFile(QString("../cities.kml"), cities, latitude, longitude);
    writeKmlImgFile(QString("../colorData.kml"), latitude, longitude);


    ////////////////////////////// Free Memory //////////////////////////////
    std::cout << "Delete memory" << std::endl;
    delete csvPoste;
    delete csvDatas;
    delete csvJoin;
    delete cities;
    delete latitude;
    delete longitude;
    delete kelvin;
    delete imgSquare;
    delete imgColor;
    delete colorMap;
    delete imgColormap;

    std::cout << "Fin" << std::endl;
    return 0;
}
