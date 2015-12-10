#ifndef PIECES_H
#define PIECES_H

#include <vector>

#include <QString>

using namespace std;

class QPixmap;
class casePlateau;
class plateau;

class pieces
{
    Q_ENUMS(name)

public:
    enum name { Roi, Reine, Fou, Cavalier, Tour, Pion };
    pieces(plateau *plat, QString n, int c);

    int getLine();
    int getColumn();
    QPixmap *getRep();
    void setRep(QPixmap *value);
    casePlateau *getCasePiece();
    void setCasePiece(casePlateau *value);
    int getCouleur();
    void setCouleur(int value);
    QString getName();
    void setName(QString &value);

    virtual std::vector<casePlateau *> *deplacementPossible() = 0;
    virtual bool caseAttaquee(casePlateau *c) = 0;

private:
    QString name;
    int couleur;
    QPixmap *rep;
    casePlateau *casePiece;

protected:
    plateau *p;
};

#endif // PIECES_H
