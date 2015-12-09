#ifndef CASEPLATEAU_H
#define CASEPLATEAU_H

class pieces;

class casePlateau
{
public:
    casePlateau(int l, int c);
    casePlateau(int l, int c, pieces* p, bool s, int co);

    pieces* getPiece();
    void setPiece(pieces* value);
    bool getSelected();
    void setSelected(bool value);
    int getLine();
    void setLine(int value);
    int getColumn();
    void setColumn(int value);

    bool caseVide();
    bool equals(casePlateau *c);

private:
    int line;
    int column;
    pieces* piece;
    bool selected;
    int couleur;

};

#endif // CASEPLATEAU_H
