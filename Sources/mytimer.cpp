#include "mytimer.h"
#include"Headers.h"
#include <QDebug>

jouer *board;
QLCDNumber *m_lcd;
QLabel *label_fin;
QLabel *label_fin1;
QProgressBar *progress1,*progress2,*progress3;
QString str;
QLabel *etoile1;
QLabel *etoile2;
QLabel *etoile3;
QLabel *afficheurScore;



MyTimer::MyTimer()
{
    second=150;
    myTimer=new QTimer(this);
    //connect(myTimer,SIGNAL(timeout()),SLOT(compteur()));
    connect(myTimer,SIGNAL(timeout()),SLOT(MySlot()));

    myTimer->start(1000);


}


int MyTimer::compteur()
{
    QString str=QString::number(score+score1+score2);
        if(second>0){
          second--;
        }
         if(second==0){
            myTimer->stop();
            second=0;

            if(score1+score2+score >= 10000){
                label_fin->setText(str);
                label_fin1->QLabel::raise();
                label_fin1->setPixmap(QPixmap(":/pics/backgrounds/congratulations.png"));
                label_fin->QLabel::raise();
            }
            else if (score1 + score2 + score < 10000){
                label_fin->setText(str);
                label_fin1->QLabel::raise();
                label_fin1->setPixmap(QPixmap(":/pics/backgrounds/congratulations.png"));
                label_fin->QLabel::raise();
            }

            QString fichier = "/Users/najwaerrachidy/Brain_Crush/highScores.txt";


            QFile file(fichier); // Appel du constructeur de la classe QFile

            //donnee.open(QIODevice::WriteOnly);
            if (file.open(QIODevice::Append | QIODevice::Text)) {
            // Si l'ouverture du fichier en écriture à réussie

                QTextStream out(&file);
                    out  << score1+score2+score << "\n"<< endl;
                    file.close();


          }
    }
            return second;
}



void MyTimer::MySlot(){


    board->Switch();
    board->detecter_ligne();
    board->detecter_colonne();
    m_lcd->display(QString::number(compteur()));

    str=QString::number(score+score1+score2);
        if(score1+score2+score<=10000){
            progress1->setValue((score1+score2+score)*0.01);
        }
        else if(score1+score2+score<=20000){
            progress1->setValue(100);
            etoile1->setPixmap(QPixmap(":/pics/backgrounds/star.jpg"));
            progress2->setValue((score1+score2+score-10000)*0.01);
        }
        else if(score1+score2+score<=30000){
            progress2->setValue(100);
            etoile2->setPixmap(QPixmap(":/pics/backgrounds/star.jpg"));
            progress3->setValue((score1+score2+score-20000)*0.01);
        }
        else if (score1+score2+score>=20000 ){
            etoile3->setPixmap(QPixmap(":/pics/backgrounds/star.jpg"));
            progress3->setValue(100);
        }
        afficheurScore->setText(str);
        afficheurScore->setStyleSheet("QLabel { background-color ; color : Black; }");
    std::cout<<second<<std::endl;
    std::cout<<score1+score2+score<<std::endl;
}


