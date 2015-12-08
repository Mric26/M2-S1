#ifndef PIECES_H
#define PIECES_H

#include <QString>
#include <vector>
#include <QColor>
#include <casePlateau.h>

class casePlateau;
using namespace std;

class pieces
{
    Q_ENUMS(name)

public:
    enum name { Roi, Reine, Fou, Cavalier, Tour, Pion };
    pieces(QString n, int c);
    vector<casePlateau> deplacementPossible();

private:
    QString name;
    int couleur;
};

#endif // PIECES_H
