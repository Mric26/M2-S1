#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QObject>
#include <QWidget>

#include "convolution.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    bool open();
    void close();
    void median();
    void flouGaussLeger();
    void flouGaussMoyen();
    void flouGaussFort();
    void passeHaut();
    void rehaussement();
    void gradientX();
    void gradientY();
    void detectionContours();

private:
    // Attributs
    Ui::MainWindow *ui;
    QImage *image;
    QString filename;
    QGraphicsScene *scene;

    void setImage(QImage *im);
};

#endif // MAINWINDOW_H
