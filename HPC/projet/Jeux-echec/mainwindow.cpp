#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    painter = new QPainter(this);
    plateau *p = new plateau( painter );
    QPixmap *imagePix = p->affichagePlateau();
    scene->addPixmap(*imagePix);
    scene->setSceneRect(0,0,imagePix->width(),imagePix->height());
    ui->Affichage->setScene(scene);
    ui->Affichage->show();

}

MainWindow::~MainWindow(){
    delete ui;
}



