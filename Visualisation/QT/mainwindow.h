#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QString>
#include <QRgb>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QColor>
#include <string>
#include <QShortcut>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QGraphicsItem>
#include <QVector>
#include <QMessageBox>

#include "convolution.h"
#include "etalement.h"
#include "egalisation.h"
#include "diagramcolorwindow.h"
#include "filtreperso.h"
#include "fusioncalques.h"
#include "filtreadaptatif.h"
#include "composantesconnexes.h"
#include "bordsobjets.h"
#include "imagegradient.h"
#include "seuillage.h"
#include "negatif.h"
#include "kmoyenne.h"
#include "seuillagedecoupe.h"
#include "dilaero.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void refresh();
    void paintEvent(QPaintEvent *);
    ~MainWindow();

    QImage * getImage();    
    void setImage(QImage * im, QString chem);

    QString getCheminImage();

    bool getEmptylabel() const;
    void setEmptylabel(bool value);

    bool getRgbORyuv() const;
    void setRgbORyuv(bool value);

    QGraphicsPixmapItem *getImageaffichee() const;
    void setImageaffichee(QGraphicsPixmapItem *value);

    void nettoyage();
    void desactive();
    void active();

    QGraphicsScene *getScene() const;
    void setScene(QGraphicsScene *value);

    QImage * getcopie() const;
    void setcopie(QImage * value);

    void AfficherMessageNonFini();

public slots:
    // ouv / fermeture / enregistrement
    void ouv();
    void save();
    void saveAs();
    //Annuler & refaire
    void annuler();
    void refaire();
    //decoupe
    void couper();
    void rogner();
    void copier();
    void coller();
    //niveau de gris
    void gris();
    //histogramme
    void showHisto();
    void etaler();
    void egaler();
    //pipette
    void pipeit();
    void changeRGBtoYUVfalse();
    void changeRGBtoYUVtrue();
    //Selection
    void selection();
    //Filtres
    void flouGaussLeger();
    void flouGaussMoyen();
    void flouGaussFort();
    void flouMoyLeger();
    void flouMoyMoyen();
    void flouMoyFort();
    void passeHaut();
    void rehaussement();
    void gradientX();
    void gradientY();
    void detectionContours();
    void filtrePerso();
    void appliquerFiltrePerso(float **matrice, int tailleMatrice);
    void createFusion();
    void median();
    //redimensionnement
    void redimensionner();
    //calques
    void fusionnerCalques();
    //quitter
    void quit();
    //autre
    void pleinEcran();
    void minimiser();
    //TP M2
    void filtreAdaptatiff();
    void inverserH();   
    void moduleGradient();
    void pointDinteretsf();
    void compoConnexe();
    void bords();
    void kMoyenne();
    void negatifslot();
    void seuillageSlot();
    void seuillageMoyenneSlot();
    void seuillageMedianeSlot();
    void CompaPI();        
    void seuillageRiz();
    void traitementRiz();

private:
    Ui::MainWindow *ui;
    QImage* image;
    QString cheminImage;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *imageaffichee;
    DiagramColorWindow * hist;
    FiltrePerso * fPerso;
    bool emptylabel;
    bool rgbORyuv;
    QImage * annul[2];
    QImage * refai[2];
    QImage * copie;

};

#endif // MAINWINDOW_H
