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

    p->afficherDeplacementPossible( p->getCase(2,1) );
}

MainWindow::~MainWindow(){
    delete ui;
}



