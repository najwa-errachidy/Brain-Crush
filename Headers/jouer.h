#ifndef JOUER_H
#define JOUER_H



#include "BrainCrush.h"
#include "qbrainh.h"

extern int score1;
extern int score2;
extern int score;

class jouer{

int nombreDeDeplacement;
public:

    jouer(QWidget *fenetre);
    ~jouer();
    void initialiserCoordonees();
    void Switch();
    void ChangerTable(int l1, int c1, int l2, int c2);
    int witchline(int l1,int l2,int c1,int c2);
    void reset();
    void tracerTable();
    void detecter_ligne();
    void detecter_colonne();
    void eliminer_ligne(int ligne, int colonne, int pas);
    void eliminer_col(int ligne, int colonne, int pas);
    QString getType_(int x);
     int Check();


    //getter
    BrainCrush* getBrain(int i, int j);

private:
    QVector<QVector<BrainCrush*>> table;
    QVector< QVector< QBrainH* > > icone;



};

#endif // JOUER_H
