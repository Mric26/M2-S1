#include "plateau.h"

plateau::plateau(MainWindow *win){
    tab = new matrix<casePlateau *>(8, 8);
    for (int line = 0; line < 8; line++) {
        for (int column = 0; column < 8; column++) {
            if( (line+column)%2 == 0 ){
                tab->at_element(line, column) = new casePlateau(line, column, NULL, false, 0);
            }
            else{
                tab->at_element(line, column) = new casePlateau(line, column, NULL, false, 1);
            }
        }
    }
    listeJoueurBlanc = new std::vector<pieces*>;
    listeJoueurNoir = new std::vector<pieces*>;
    w = win;

    newGame();
}

bool plateau::getJoueur1() const{
    return joueur1;
}

void plateau::setJoueur1(bool value){
    joueur1 = value;
}

bool plateau::valid(int column, int line){
    return (line >= 0 && line <= 7 && column >= 0 && column <= 7);
}

casePlateau *plateau::getCase(int column, int line) {
    return tab->at_element(line, column);
}

casePlateau *plateau::getCaseKing(bool joueur1){
    std::vector< pieces* > *listPieces = getListeJoueurBlanc();
    if (!joueur1) {
        listPieces = getListeJoueurNoir();
    }
    foreach (pieces *piece, *listPieces) {
        if (piece->getName().compare("roi") == 0) {
            return piece->getCasePiece();
        }
    }
    return NULL;
}

/** Retourne l'ensemble des cases attaquees par le joueur passe en parametre */
std::vector<casePlateau *> *plateau::getCaseJouableFromPlayer(bool joueur1) {
    std::vector<casePlateau *> *listCase = new std::vector<casePlateau *>(0);
    std::vector< pieces* > *listPieces = getListeJoueurBlanc();
    if (!joueur1) {
        listPieces = getListeJoueurNoir();
    }
    foreach (pieces *piece, *listPieces) {
        foreach (casePlateau *c, *piece->deplacementPossible()) {
            listCase->push_back(c);
        }
    }
    return listCase;
}

std::vector<pieces *> *plateau::getListeJoueurBlanc() const{
    return listeJoueurBlanc;
}

void plateau::setListeJoueurBlanc(std::vector<pieces*> *value){
    listeJoueurBlanc = value;
}

std::vector<pieces*> *plateau::getListeJoueurNoir() const{
    return listeJoueurNoir;
}

void plateau::setListeJoueurNoir(std::vector<pieces*> *value){
    listeJoueurNoir = value;
}

bool plateau::caseUnderAttackFromPlayer(bool joueur1, casePlateau *c){
    std::vector< pieces* > *listPieces = getListeJoueurBlanc();
    if (!joueur1) {
        listPieces = getListeJoueurNoir();
    }
    foreach (pieces *piece, *listPieces) {
        if (piece->caseAttaquee(c)) {
            return true;
        }
    }
    return false;
}

bool plateau::checkKing(bool joueur1){
    return caseUnderAttackFromPlayer(!joueur1, getCaseKing(joueur1));
}

bool plateau::checkMateKing(bool joueur1){
    // Retourne faux si le roi n'est pas en echec
    if (!checkKing(joueur1)) {
        return false;
    }
    // Retourne vrai si aucun deplacement ne peut proteger le roi
    return (getCaseJouableFromPlayer(joueur1)->size() == 0);
}

bool plateau::isCoupValid(coup *c){
    bool res;
    c->jouerCoup();
    res = !checkKing(getJoueur1());
    c->getBack();
    return res;
}

int plateau::evaluation(){
    int resb = 0;
    foreach (pieces* p, *listeJoueurBlanc) {
        if( p->getName() == QString("roi") ){
            resb = resb + 500;
        }
        if( p->getName() == QString("reine") ){
            resb = resb + 50;
        }
        if( p->getName() == QString("tour") ){
            resb = resb + 10;
        }
        if( p->getName() == QString("fou") ){
            resb = resb + 5;
        }
        if( p->getName() == QString("cavalier") ){
            resb = resb + 5;
        }
        if( p->getName() == QString("pion") ){
            resb = resb + 1;
        }
    }
    int resn = 0;
    foreach (pieces* p, *listeJoueurNoir) {
        if( p->getName() == QString("roi") ){
            resn = resn + 500;
        }
        if( p->getName() == QString("reine") ){
            resn = resn + 50;
        }
        if( p->getName() == QString("tour") ){
            resn = resn + 10;
        }
        if( p->getName() == QString("fou") ){
            resn = resn + 5;
        }
        if( p->getName() == QString("cavalier") ){
            resn = resn + 5;
        }
        if( p->getName() == QString("pion") ){
            resn = resn + 1;
        }
    };
    return resb - resn;
}

void plateau::changementJoueur(){
    setJoueur1(!getJoueur1());
}

void plateau::jouerCoup(coup *c){
    // Deplace les pieces sur le plateau
    c->jouerCoup();
    // Mise a jour des listes de piece du joueur
    pieces *piece = c->getPrise();
    if (piece != NULL) {
        enleverPiece( piece );
    }
    majPlateau();
    // Changement de joueur
    changementJoueur();
}

void plateau::getBack(coup *c){
    // Changement de joueur
    changementJoueur();
    // Replace les pieces sur le plateau
    c->getBack();
    // Mise a jour des pieces du joueur
    pieces *piece = c->getPrise();
    if (piece != NULL) {
        if (piece->getCouleur() == 0) {
            listeJoueurBlanc->push_back(piece);
        } else {
            listeJoueurNoir->push_back(piece);
        }
    }
}

std::vector<coup *> * plateau::getListCoup(bool j){
    std::vector<coup *> * res = new std::vector<coup *>;
    std::vector<pieces*> *liste_Pieces;
    if( j ){
        liste_Pieces = listeJoueurBlanc;
    }
    else{
        liste_Pieces = listeJoueurNoir;
    }
    coup * c;
    foreach (pieces* p, *liste_Pieces) {
        std::vector<casePlateau *> *liste_Coups = p->deplacementPossible();
        foreach (casePlateau *ca, *liste_Coups) {
            c = new coup( p->getCasePiece(), ca );
            res->push_back( c );
        }
    }
    return res;
}

void plateau::affichagePlateau(){
    QPixmap *res = new QPixmap(":images/plateau.png");

    QGraphicsItem *item;
    item = w->scene->addPixmap(*res);
    w->itemVector->push_back( item );
}

void plateau::affichagePieces(){
    foreach (pieces* p, *listeJoueurBlanc) {
        QGraphicsItem *item;
        item = w->scene->addPixmap( *(p->getRep()) );
        item->setPos(65 + p->getCasePiece()->getColumn() * 80, 72 + p->getCasePiece()->getLine() * 80 );
        w->itemVector->push_back( item );
    }

    foreach (pieces* p, *listeJoueurNoir) {
        QGraphicsItem *item;
        item = w->scene->addPixmap( *(p->getRep()) );
        item->setPos(65 + p->getCasePiece()->getColumn() * 80, 72 + p->getCasePiece()->getLine() * 80 );
        w->itemVector->push_back( item );
    }
}

void plateau::enleverPiece( pieces * p ){
    int pos = -1;
    //blanc
    if( p->getCouleur() == 0 ){
        for (unsigned int i = 0; i < listeJoueurBlanc->size() && pos == -1; ++i) {
            if (p == listeJoueurBlanc->at(i)) {
                pos = i;
            }
        }
        listeJoueurBlanc->erase(listeJoueurBlanc->begin() + pos);
    }
    //noir
    else{
        for (unsigned int i = 0; i < listeJoueurNoir->size() && pos == -1; ++i) {
            if (p == listeJoueurNoir->at(i)) {
                pos = i;
            }
        }
        listeJoueurNoir->erase(listeJoueurNoir->begin() + pos);
    }
}

void plateau::majPlateau(){
    w->scene->clear();
    affichagePlateau();
    affichagePieces();
    w->repaint();
}

void plateau::newGame(){
    casePlateau * c;

    //piece blanche
    c = getCase(0,7);
    tour * tb1 = new tour(this, 0);
    tb1->setCasePiece(c);
    listeJoueurBlanc->push_back(tb1);
    c->setPiece(tb1);

    c = getCase(1,7);
    cavalier * cb1 = new cavalier(this, 0);
    cb1->setCasePiece(c);
    listeJoueurBlanc->push_back(cb1);
    c->setPiece(cb1);

    c = getCase(2,7);
    fou * fb1 = new fou(this, 0);
    fb1->setCasePiece(c);
    listeJoueurBlanc->push_back(fb1);
    c->setPiece(fb1);

    c = getCase(3,7);
    reine * rb = new reine(this, 0);
    rb->setCasePiece(c);
    listeJoueurBlanc->push_back(rb);
    c->setPiece(rb);

    c = getCase(4,7);
    roi * roib = new roi(this, 0);
    roib->setCasePiece(c);
    listeJoueurBlanc->push_back(roib);
    c->setPiece(roib);

    c = getCase(5,7);
    fou * fb2 = new fou(this, 0);
    fb2->setCasePiece(c);
    listeJoueurBlanc->push_back(fb2);
    c->setPiece(fb2);

    c = getCase(6,7);
    cavalier * cb2 = new cavalier(this, 0);
    cb2->setCasePiece(c);
    listeJoueurBlanc->push_back(cb2);
    c->setPiece(cb2);

    c = getCase(7,7);
    tour * tb2 = new tour(this, 0);
    tb2->setCasePiece(c);
    listeJoueurBlanc->push_back(tb2);
    c->setPiece(tb2);

    for (int i = 0; i < 8; ++i) {
        c = getCase(i,6);
        pion * pb = new pion(this, 0);
        pb->setCasePiece(c);
        listeJoueurBlanc->push_back(pb);
        c->setPiece(pb);
    }

    //piece noir
    c = getCase(0,0);
    tour * tn1 = new tour(this, 1);
    tn1->setCasePiece(c);
    listeJoueurNoir->push_back(tn1);
    c->setPiece(tn1);

    c = getCase(1,0);
    cavalier * cn1 = new cavalier(this, 1);
    cn1->setCasePiece(c);
    listeJoueurNoir->push_back(cn1);
    c->setPiece(cn1);

    c = getCase(2,0);
    fou * fn1 = new fou(this, 1);
    fn1->setCasePiece(c);
    listeJoueurNoir->push_back(fn1);
    c->setPiece(fn1);

    c = getCase(3,0);
    reine * rn = new reine(this, 1);
    rn->setCasePiece(c);
    listeJoueurNoir->push_back(rn);
    c->setPiece(rn);

    c = getCase(4,0);
    roi * roin = new roi(this, 1);
    roin->setCasePiece(c);
    listeJoueurNoir->push_back(roin);
    c->setPiece(roin);

    c = getCase(5,0);
    fou * fn2 = new fou(this, 1);
    fn2->setCasePiece(c);
    listeJoueurNoir->push_back(fn2);
    c->setPiece(fn2);

    c = getCase(6,0);
    cavalier * cn2 = new cavalier(this, 1);
    cn2->setCasePiece(c);
    listeJoueurNoir->push_back(cn2);
    c->setPiece(cn2);

    c = getCase(7,0);
    tour * tn2 = new tour(this, 1);
    tn2->setCasePiece(c);
    listeJoueurNoir->push_back(tn2);
    c->setPiece(tn2);


    for (int i = 0; i < 8; ++i) {
        c = getCase(i,1);
        pion * pn = new pion(this, 1);
        pn->setCasePiece(c);
        listeJoueurNoir->push_back(pn);
        c->setPiece(pn);
    }

    setJoueur1(true);
}

void plateau::afficherDeplacementPossible( casePlateau * c ){
    QRect * rectangle = new QRect(50 + c->getColumn() * 80, 60 + c->getLine() * 80, 75, 75);
    QPen  * pen = new QPen(Qt::cyan, 1, Qt::SolidLine);
    w->scene->addRect(*rectangle, *pen);

    pieces * p = c->getPiece();
    std::vector<casePlateau *> * dp = p->deplacementPossible();
    if( dp->size() == 0 ){
        cout << "CEST NULL BITCH !!!" << endl;
    }
    foreach (casePlateau *cp, *dp) {
        rectangle = new QRect(50 + cp->getColumn() * 80, 60 + cp->getLine() * 80, 75, 75);
        pen = new QPen(Qt::magenta, 1, Qt::SolidLine);
        w->scene->addRect(*rectangle, *pen);
    }

    w->repaint();
}
