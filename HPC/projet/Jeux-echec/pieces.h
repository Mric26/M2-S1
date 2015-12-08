#ifndef PIECES_H
#define PIECES_H

#include <QString>
#include <vector>
#include <QColor>
#include <casePlateau.h>
#include <QPixmap>

class casePlateau;
using namespace std;

class pieces
{
    Q_ENUMS(name)

public:
    enum name { Roi, Reine, Fou, Cavalier, Tour, Pion };
    pieces(QString n, int c);
    vector<casePlateau> deplacementPossible();

    QPixmap *getRep();
    void setRep(QPixmap *value);
    void setCase(casePlateau *casePiece);

private:
    QString name;
    int couleur;
    QPixmap *rep;
    casePlateau *casePiece;
};

#endif // PIECES_H
