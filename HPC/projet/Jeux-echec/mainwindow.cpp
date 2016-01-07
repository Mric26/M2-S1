#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new scenePerso(this, this);
    itemVector = new std::vector<QGraphicsItem *>;
    plateau *p = new plateau( this );

    p->affichagePlateau();
    ui->Affichage->setScene(scene);
    ui->Affichage->show();

    p->affichagePieces();

    ////////////////////////////////////////////////////////
    p->enleverPiece( new casePlateau(0,1) );
    scene->clear();
    p->affichagePlateau();
    p->affichagePieces();
    ////////////////////////////////////////////////////////

    this->repaint();
}

MainWindow::~MainWindow(){
    delete ui;
}



