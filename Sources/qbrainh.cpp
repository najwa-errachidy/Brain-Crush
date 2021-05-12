#include "qbrainh.h"
#include"Headers.h"
class jouer;
int compt(0);
//int T[4]={0,0,0,0};

bool flag=false;
QString typerec;


QBrainH::QBrainH(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {
    isPress=false;
    brain=new BrainCrush;
    if (brain->getcouleur()==4){

        type="/Users/najwaerrachidy/Brain_Crush/Brains/brain yellow.png";
    }
    else if (brain->getcouleur()==1){
        type="/Users/najwaerrachidy/Brain_Crush/Brains/brain blue.png";

    }
    else if (brain->getcouleur()==2){
        type="/Users/najwaerrachidy/Brain_Crush/Brains/brain green.png";

    }
    else if (brain->getcouleur()==3){
        type="/Users/najwaerrachidy/Brain_Crush/Brains/brain purple.png";
    }
    else if (brain->getcouleur()==5){
        type="/Users/najwaerrachidy/Brain_Crush/Brains/brain red.png";
    }

}

QBrainH::~QBrainH() {}



bool QBrainH::getIsPress(){
    return isPress;
}
void QBrainH::setIsPress(bool ip){
    this->isPress=ip;
}

int QBrainH::getCouleur(){
    return couleur;
}
void QBrainH::setCouleur(int coul){
    this->couleur=coul;
}
QString QBrainH::getType(){
    return type;
}
void QBrainH::setType(QString ty){
    this->type=ty;
}
BrainCrush* QBrainH::getBrain(){
    return brain;
}
void QBrainH::setBrain(BrainCrush* br){
    this->brain=br;
}

int QBrainH::getligne(){
    return ligne;
}
void QBrainH::setligne(int l){
    this->ligne=l;
}
int QBrainH::getcolonne(){
    return ligne;
}
void QBrainH::setcolonne(int c){
    this->colonne=c;
}
void QBrainH::changerIcone(){
    if (couleur==4){

        type="/Users/najwaerrachidy/Brain_Crush/Brains/brain blue.png";
    }
    else if (couleur==1){
        type="/Users/najwaerrachidy/Brain_Crush/Brains/brain yellow.png";

    }
    else if (couleur==2){
        type="/Users/najwaerrachidy/Brain_Crush/Brains/brain green.png";

    }
    else if (couleur==3){
        type="/Users/najwaerrachidy/Brain_Crush/Brains/brain purple.png";
    }
    else if (couleur==5){
        type="/Users/najwaerrachidy/Brain_Crush/Brains/brain red.png";
    }
}

void QBrainH::tracer(){
    setPixmap(QPixmap(type));
    setGeometry(ligne, colonne, 80, 80);

}
void QBrainH::mousePressEvent(QMouseEvent* event) {
    emit clicked();
    if (isPress == false && event->button() == Qt::LeftButton){
        isPress=true;

            compt++;

    }
        else if (isPress == true && event->button() == Qt::LeftButton){
            isPress=false;

            compt--;

    }
    if(compt==2){

    }
    std::cout<< compt<<"brains selectionnee"<<std::endl;

}
