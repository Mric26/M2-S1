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

    ui->Affichage->setScene(scene);
    ui->Affichage->show();
    p->majPlateau();

    p->jouerCoup( new coup(p->getCase(5,6), p->getCase(5,4)) );
    p->jouerCoup( new coup(p->getCase(4,1), p->getCase(4,2)) );
    p->jouerCoup( new coup(p->getCase(6,6), p->getCase(6,4)) );
    p->jouerCoup( new coup(p->getCase(3,0), p->getCase(7,4)) );
//    p->afficherDeplacementPossible( p->getCase(7,4) );
}

MainWindow::~MainWindow(){
    delete ui;
}
