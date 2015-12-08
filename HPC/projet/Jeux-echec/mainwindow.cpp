#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    QPixmap *imagePix = new QPixmap(":images/plateau.png");
    scene->addPixmap(*imagePix);
    scene->setSceneRect(0,0,imagePix->width(),imagePix->height());
    ui->Affichage->setScene(scene);
    ui->Affichage->show();

}

MainWindow::~MainWindow(){
    delete ui;
}



