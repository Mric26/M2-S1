#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    QImage* image = new QImage("/home/s/segureta/Documents/M2-S1/HPC/projet/images/plateau.png");
    QPixmap *imagePix = new QPixmap();
    imagePix->convertFromImage(*image);
    scene->addPixmap(*imagePix);
    scene->setSceneRect(0,0,image->width(),image->height());
    ui->Affichage->setScene(scene);
    ui->Affichage->show();

}

MainWindow::~MainWindow(){
    delete ui;
}



