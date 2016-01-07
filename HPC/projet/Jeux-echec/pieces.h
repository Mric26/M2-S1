#ifndef PIECES_H
#define PIECES_H

#include <vector>
#include <QPixmap>
#include <QString>

using namespace std;

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

    bool sameColor(pieces *piece);

    virtual std::vector<casePlateau *> *deplacementPossible() = 0;
    virtual bool caseAttaquee(casePlateau *c) = 0;


private:
    QString name;
    int couleur; // 0 blanc, 1 noir
    QPixmap *rep;
    //casePlateau *casePiece;

protected:
    plateau *p;
    casePlateau *casePiece;
};

//std::vector<int> pieces::simpleStep = {-1, 1};
//std::vector<int> pieces::doubleStep = {-2, 2};

#endif // PIECES_H
