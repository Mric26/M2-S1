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
    QObject::connect(ui->buttonGaussien, SIGNAL(clicked()), this, SLOT(gaussien()));
    QObject::connect(ui->buttonMedian, SIGNAL(clicked()), this, SLOT(median()));
}

MainWindow::~MainWindow(){
    delete image;
    delete scene;
    delete ui;
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

void MainWindow::gaussien()
{
    if( filename != NULL){
        Convolution c;
        setImage(c.flouGaussien(image,9));
    }
}

void MainWindow::median()
{
    if( filename != NULL){
        Convolution c;
        setImage(c.filtreMedian(image,1));
    }
}

void MainWindow::setImage(QImage * im){
    scene->clear();
    QPixmap * imagepix = new QPixmap();
    imagepix->convertFromImage(*im);
    scene->addPixmap(*imagepix);
    scene->setSceneRect(0,0,im->width(),im->height());
    ui->graphicsView->show();
}
