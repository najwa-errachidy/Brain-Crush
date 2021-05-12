#ifndef QBRAINH_H
#define QBRAINH_H



#include "BrainCrush.h"
#include <QLabel>
#include <QWidget>
#include <Qt>
extern int compt;
extern bool flag;
//extern int T[4];
class jouer;
class QBrainH : public QLabel
{
    //int somme;
    Q_OBJECT
    public:
        explicit QBrainH(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
        ~QBrainH();
        bool getIsPress();
        void setIsPress(bool ip);
        int getCouleur();
        void setCouleur(int coul);
        int getligne();
        void setligne(int l);
        int getcolonne();
        void setcolonne(int c);
        QString getType();
        void setType(QString ty);
        BrainCrush* getBrain();
        void setBrain(BrainCrush* br);
        void changerIcone();
        void tracer();


        //int getSomme();
        //void setSomme(int s);

    signals:
        void clicked();

    protected:

        void mousePressEvent(QMouseEvent* event);

    private:
        int ligne;
        int colonne;

        bool isPress;
        int couleur;
        QString type;
        BrainCrush *brain;
};

#endif // QBRAINH_H
