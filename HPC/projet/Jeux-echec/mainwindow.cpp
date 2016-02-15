#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

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
    p->jouerCoup( new coup(p->getCase(7,6), p->getCase(7,4)) );
    p->jouerCoup( new coup(p->getCase(6,6), p->getCase(6,5)) );
    p->jouerCoup( new coup(p->getCase(3,0), p->getCase(7,4)) );
//    p->jouerCoup( new coup(p->getCase(6,5), p->getCase(7,4)) );
//    p->afficherDeplacementPossible( p->getCase(6,5) );

    IA_AlphaBeta * cerveau = new IA_AlphaBeta(p);
//    QTime time;
//    time.start();
    cerveau->jouerParalleleAlphaBeta();
//    cerveau->jouerAlphaBeta();
//    int temps = time.elapsed();
//    cout << temps << endl;

}

MainWindow::~MainWindow(){
    delete ui;
}
