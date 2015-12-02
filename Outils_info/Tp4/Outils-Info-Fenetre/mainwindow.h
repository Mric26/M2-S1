#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <python2.7/Python.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void quit();
    void load();
    void run();

private:
    Ui::MainWindow *ui;
    QString chemin;
    const char* chem;
    QFile * file;

    void BaseEditor();
    void MajEditor();
    void execPython();

};

#endif // MAINWINDOW_H
