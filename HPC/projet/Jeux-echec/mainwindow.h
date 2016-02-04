#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <plateau.h>
#include <ia_alphabeta.h>
#include <sceneperso.h>

class scenePerso;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    scenePerso * scene;
    std::vector<QGraphicsItem *> * itemVector;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
