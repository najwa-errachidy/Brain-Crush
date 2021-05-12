
#ifndef BRAINCRUSH_H
#define BRAINCRUSH_H
class BrainCrush
{
public:
    BrainCrush();
    ~BrainCrush();
    //geters et setters:
    int getcolonne();
    int getligne();

    bool getisMove();
    int getcouleur();

    void setcolonne(int c) ;
    void setligne(int l) ;

    void setisMove(bool isM) ;
    void setcouleur(int coul);



private:
    int colonne, ligne;
    int couleur; //ici chaque couleur est associee a un nombre(on aura 5 couleurs)
    bool isMove;
};
#endif // BRAINCRUSH_H
