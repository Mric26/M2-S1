#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>

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
    void gaussien();
    void median();

private:
    // Attributs
    Ui::MainWindow *ui;
    QImage *image;
    QString filename;
    QGraphicsScene *scene;

    void setImage(QImage *im);
};

#endif // MAINWINDOW_H
