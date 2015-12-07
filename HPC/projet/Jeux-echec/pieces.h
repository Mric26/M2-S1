#ifndef PIECES_H
#define PIECES_H

#include <QString>
#include <vector>
#include <QColor>
#include <caseplateau.h>

using namespace std;

class pieces
{
    Q_ENUMS(name)

public:
    enum name { Roi, Reine, Fou, Cavalier, Tour, Pion };
    pieces(QString n, QColor c);
    vector<casePlateau> deplacementPossible();

private:
    QString name;
    QColor couleur;
};

#endif // PIECES_H
