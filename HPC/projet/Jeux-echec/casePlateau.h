#ifndef CASEPLATEAU_H
#define CASEPLATEAU_H

#include <pieces.h>
#include <QColor>

class pieces;
class casePlateau
{
public:
    casePlateau(int l, int c);
    casePlateau(int l, int c, pieces* p, bool s, int co);

    pieces* getPiece();
    void setPiece(pieces* value);
    bool caseVide();
    bool getSelected();
    void setSelected(bool value);
    int getLine();
    void setLine(int value);
    int getColumn();
    void setColumn(int value);

private:
    int line;
    int column;
    pieces* piece;
    bool selected;
    int couleur;

};

#endif // CASEPLATEAU_H
