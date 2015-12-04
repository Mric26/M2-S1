#ifndef PIECES_H
#define PIECES_H

#include <QString>
#include <vector>
#include <QColor>
#include <caseplateau.h>

using namespace std;

class pieces
{
public:
    pieces();
    vector<casePlateau> deplacementPossible();

private:
    QString name;
    QColor couleur;
};

#endif // PIECES_H
