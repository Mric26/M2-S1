#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    image = new QImage();
    scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);

    QObject::connect(ui->buttonOpen, SIGNAL(clicked()), this, SLOT(open()));
    QObject::connect(ui->buttonClose, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui->buttonGaussien, SIGNAL(clicked()), this, SLOT(flouGaussMoyen()));
    QObject::connect(ui->buttonMedian, SIGNAL(clicked()), this, SLOT(median()));

}

MainWindow::~MainWindow(){
    delete image;
    delete scene;
    delete ui;
}

void MainWindow::setImage(QImage * im){
    scene->clear();
    QPixmap * imagepix = new QPixmap();
    imagepix->convertFromImage(*im);
    scene->addPixmap(*imagepix);
    scene->setSceneRect(0,0,im->width(),im->height());
    ui->graphicsView->show();
}

bool MainWindow::open(){
    filename = QFileDialog::getOpenFileName(this,"Ouvrir un fichier");
    bool charge = image->load(filename);

    if( charge){
        setImage(image);
        return 1;
    }
    else{
        return 0;
    }
}

void MainWindow::close()
{
    qApp->quit();
}

void MainWindow::median()
{
    if( filename != NULL){
        Convolution c;
        setImage(c.filtreMedian(image,1));
    }
}

void MainWindow::flouGaussLeger(){
    if( filename != NULL ){
        Convolution c;
        setImage(c.flouGaussien(image,3));
    }
}

void MainWindow::flouGaussMoyen(){
    if( filename != NULL ){
        Convolution c;
        setImage(c.flouGaussien(image,5));
    }
}

void MainWindow::flouGaussFort(){
    if( filename != NULL ){
        Convolution c;
        setImage(c.flouGaussien(image,7));
    }
}

void MainWindow::passeHaut(){
    if( filename != NULL ){
        Convolution c;
        setImage(c.filtrePasseHaut(image));
    }
}

void MainWindow::rehaussement(){
    if( filename != NULL ){
        Convolution c;
        setImage(c.filtreRehaussement(image));
    }
}

void MainWindow::gradientX(){
    if( filename != NULL ){
        Convolution c;
        setImage(c.gradientX(image));
    }
}

void MainWindow::gradientY(){
    if( filename != NULL ){
        Convolution c;
        setImage(c.gradientY(image));
    }
}

void MainWindow::detectionContours(){
    if( filename != NULL ){
        Convolution c;
        setImage(c.detectionContours(image));
    }
}
