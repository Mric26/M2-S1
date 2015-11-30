#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QObject::connect( ui->Quitter, SIGNAL(clicked()), this, SLOT(quit()) );
    new QShortcut( QKeySequence("Ctrl+Q"), this, SLOT(quit()) );

    QObject::connect( ui->Charger, SIGNAL(clicked()), this, SLOT(load()) );
    new QShortcut( QKeySequence("Ctrl+O"), this, SLOT(load()) );

    QObject::connect( ui->Lancer, SIGNAL(clicked()), this, SLOT(run()) );
    new QShortcut( QKeySequence("Ctrl+R"), this, SLOT(run()) );

    BaseEditor();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::BaseEditor(){
    QString texte = "Mric : ";
    ui->TexteAffichage->setText( "Mric : ");
}

void MainWindow::MajEditor(){
    QString texte = "Mric : ";
    ui->TexteAffichage->setText( ui->TexteAffichage->toPlainText() + "\n" + texte);
}

void MainWindow::quit(){
     qApp->quit();
}

void MainWindow::load(){
    //selection fichier
    chemin = QFileDialog::getOpenFileName(this,"Ouvrir un fichier", QDir::currentPath() + "/../src", "Files (*.py *.c)");

    //affichage message terminal
    QString texte = "Chargement de " + chemin;
    ui->TexteAffichage->setText( ui->TexteAffichage->toPlainText() +  "\n" + texte +  "\n" );

    //affichage contenus
    file = new QFile(chemin);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)){
        texte = "Chargement de " + chemin + " failed";
        ui->TexteAffichage->setText( ui->TexteAffichage->toPlainText() +  "\n" + texte +  "\n" );
    }
    else{
        QTextStream in( file );
        ui->TexteEditor->setText( in.readAll() );
    }

    //remise du pseudo
    MajEditor();
}

void MainWindow::run(){

    if( chemin.endsWith(".py") ){
        execPython();
    }
    if( chemin.endsWith(".c") ){

    }

}

void MainWindow::execPython(){
    //passage en paramètre correct pour appel
    int fileHandle = file->handle();
    FILE* fh = fdopen(fileHandle, "rb");
    const char* chem = chemin.toStdString().c_str();


    /////////////////////////// PYTHON ////////////////////
    std::string stdOutErr =
"import sys\n\
class CatchOutErr:\n\
    def __init__(self):\n\
        self.value = ''\n\
    def write(self, txt):\n\
        self.value += txt\n\
catchOutErr = CatchOutErr()\n\
sys.stdout = catchOutErr\n\
sys.stderr = catchOutErr\n\
";

    Py_Initialize();
    PyObject *pModule = PyImport_AddModule("__main__");                             //create main module
    PyRun_SimpleString(stdOutErr.c_str());                                          //invoke code to redirect
    PyRun_SimpleString("print(1+1)");                                               //this is ok stdout
    PyRun_SimpleFile(fh, chem);
    PyObject *catcher = PyObject_GetAttrString(pModule,"catchOutErr");              //get our catchOutErr created above
    PyErr_Print();                                                                  //make python print any errors

    PyObject *output = PyObject_GetAttrString(catcher,"value");                     //get the stdout and stderr from our catchOutErr object

    QString texte;
    texte = texte.fromStdString( PyString_AsString(output) );
    ui->TexteAffichage->setText( ui->TexteAffichage->toPlainText() +  "\n" + texte +  "\n" );

    Py_Finalize();
}

