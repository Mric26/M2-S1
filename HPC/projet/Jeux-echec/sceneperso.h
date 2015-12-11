#ifndef SCENEPERSO_H
#define SCENEPERSO_H

#include <QGraphicsScene>
#include <iostream>
#include <QMouseEvent>
#include <QGraphicsItem>

#include <stdio.h>

class MainWindow;
class scenePerso : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit scenePerso(QObject *parent, MainWindow *mw);

    QGraphicsItem * itemSelected;
    MainWindow * w;
    void mousePressEvent(QMouseEvent *event);

signals:

public slots:

};

#endif // SCENEPERSO_H
