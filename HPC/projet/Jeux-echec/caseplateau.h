#ifndef CASEPLATEAU_H
#define CASEPLATEAU_H

#include <pieces.h>

class casePlateau
{
public:
    casePlateau(int l, int c);
    casePlateau(int l, int c, pieces p);

    pieces getPiece() const;
    void setPiece(const pieces &value);
    bool caseVide();
    bool getSelected() const;
    void setSelected(bool value);
    int getLine() const;
    void setLine(int value);
    int getColumn() const;
    void setColumn(int value);

private:
    int line;
    int column;
    pieces piece;
    bool selected;

};

#endif // CASEPLATEAU_H
