#include "Headers.h"
#include "BrainCrush.h"

BrainCrush::BrainCrush()
{
    colonne=0;
    ligne=0;
    couleur=rand()% 5 + 1;
    isMove=false;
}
BrainCrush::~BrainCrush(){

}
//getters
int BrainCrush::getcolonne()
{
    return colonne;
}

int BrainCrush::getligne()
{
    return ligne;
}

/*QLabel *BrainCrush::gettype()
{
    return type;
}*/

bool BrainCrush::getisMove()
{
    return isMove;
}
int BrainCrush::getcouleur()
{
    return couleur;
}



//setters
void BrainCrush::setcolonne(int c) {
    this->colonne=c;
}
void BrainCrush::setligne(int l) {
    this->ligne=l;
}
/*void BrainCrush::settype(QLabel *t) {
    this->type=t;
}*/
void BrainCrush::setisMove(bool isP) {
    this->isMove=isP;
}
void BrainCrush::setcouleur(int coul)
{
    this->couleur=coul;
}


