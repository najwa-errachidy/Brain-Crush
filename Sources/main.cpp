#include "mainwindow.h"

#include "Headers.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QStyle>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QtWidgets>
#include <QWindow>
#include "jouer.h"
#include <QMouseEvent>
#include <iostream>
#include"fenetre.h"
#include"qbrainh.h"
#include"mytimer.h"



int main(int argc, char *argv[])
{


    QApplication app(argc, argv);

        // Création d'un widget qui servira de fenêtre
        QWidget fenetre;
        //fenetre.setStyleSheet("background-image:url(:/Users/najwaerrachidy/Brain_Crush/backgrounds/838_cerveaucandy geant.jpg)");
        fenetre.setFixedSize(500, 700);


        QLabel *label = new QLabel(&fenetre);
                label->setPixmap(QPixmap(":/pics/backgrounds/838_cerveaucandy geant.jpg"));



        QLabel *label2=new QLabel("Welcome to Brain Crush",&fenetre);
                label2->setFont(QFont("Chalkduster",27));
                label2->setGeometry(55, 150, 500, 100);
                label2->setStyleSheet("QLabel { background-color ; color : white; }");


        // Création du bouton, ayant pour parent la "fenêtre"



        QPushButton bouton1("Start", &fenetre);
        // Personnalisation du bouton
        bouton1.setFont(QFont("Comic Sans MS", 14));
        bouton1.setCursor(Qt::PointingHandCursor);
        bouton1.setGeometry(150, 270, 200, 40);
        //bouton1.setStyleSheet("background-color: Yellow; color : white");


        QPushButton bouton4("rules", &fenetre);
        // Personnalisation du bouton
        bouton4.setFont(QFont("Comic Sans MS", 14));
        bouton4.setCursor(Qt::PointingHandCursor);
        bouton4.setGeometry(150, 330, 200, 40);

        QDialog fenetre2 (&fenetre);
        fenetre2.setFixedSize(1200, 800);

        fenetre2.setWindowTitle("Welcome to the game");

        QObject::connect(&bouton1, SIGNAL(clicked()), &fenetre, SLOT(hide()));
        QWidget::connect(&bouton1, SIGNAL(clicked()), &fenetre2, SLOT(exec()));






        // fenetre Regles du jeu
        QDialog fenetrerules (&fenetre);
        fenetrerules.setFixedSize(400,537);

        QLabel *labelRDJ = new QLabel(&fenetrerules);
        labelRDJ->setPixmap(QPixmap(":/pics/backgrounds/rules.png"));
        labelRDJ->setFixedSize(400,537);
        fenetrerules.setWindowTitle("Rules");

        QWidget::connect(&bouton4, SIGNAL(clicked()), &fenetrerules, SLOT(exec()));




        // la partie nada du jeu

        QLabel *label3 = new QLabel(&fenetre2);
        label3->setPixmap(QPixmap(":/pics/backgrounds/board2.jpg"));
        label3->setFixedSize(1200,800);

        QLabel *labelTime = new QLabel(&fenetre2);
        labelTime->setPixmap(QPixmap(":/pics/backgrounds/timerBoard.png"));
        labelTime->setGeometry(72,370,120,45);

        QLabel *labelscore = new QLabel(&fenetre2);
        labelscore->setPixmap(QPixmap(":/pics/backgrounds/scoreboard.png"));
        labelscore->setGeometry(80,35,120,80);

        QPalette pal;
        pal.setColor(QPalette::ButtonText,Qt::black);
        pal.setColor(QPalette::Button,Qt::black);













            QPushButton bouton6("Timer",&fenetre2);
            bouton6.setEnabled(false);
            bouton6.setGeometry(80,300,112,43);
            //bouton2.setCursor(Qt::PointingHandCursor);
            bouton6.setPalette(pal);
            bouton6.setFont(QFont("Comic Sans Ms",25));
            bouton6.setStyleSheet("background-color: white");



        QPushButton bouton7("Menu",&fenetre2);
        bouton7.setGeometry(80,500,112,43);
        bouton7.setCursor(Qt::PointingHandCursor);
        bouton7.setPalette(pal);
        bouton7.setFont(QFont("Comic Sans Ms",25));
        bouton7.setStyleSheet("background-color: white");






        afficheurScore=new QLabel("hello",&fenetre2);
        afficheurScore->setText("hello");
        afficheurScore->setGeometry(110,40,120,97);
        afficheurScore->setFont(QFont("Chalkduster",20));
        afficheurScore->setStyleSheet("QLabel {  color :red; }");

        progress1 = new QProgressBar(&fenetre2);
        progress1->setGeometry(80,150,115,20);
        //progress->setStyleSheet("QProgressBar { border: 0px solid black; border-radius: 5px; text-align: center; }");
        progress1->setStyleSheet("QProgressBar::chunk{background-color:purple}");
        progress1->setValue(0);

        progress2 = new QProgressBar(&fenetre2);
        progress2->setGeometry(80,170,115,20);
        //progress->setStyleSheet("QProgressBar { border: 0px solid black; border-radius: 5px; text-align: center; }");
        progress2->setStyleSheet("QProgressBar::chunk{background-color:green}");
        progress2->setValue(0);

        progress3 = new QProgressBar(&fenetre2);
        progress3->setGeometry(80,190,115,20);
        //progress->setStyleSheet("QProgressBar { border: 0px solid black; border-radius: 5px; text-align: center; }");
        progress3->setStyleSheet("QProgressBar::chunk{background-color:blue}");
        progress3->setValue(0);

        etoile1=new QLabel(&fenetre2);
        etoile2=new QLabel(&fenetre2);
        etoile3=new QLabel(&fenetre2);
        etoile1->setGeometry(197,150,20,20);
        etoile2->setGeometry(197,170,20,20);
        etoile3->setGeometry(197,190,20,20);


        //La deuxieme fenetre

        QDialog secondeFenetre (&fenetre2);
        secondeFenetre.setFixedSize(400,350);

        QLabel *label1 = new QLabel(&secondeFenetre);
        label1->setPixmap(QPixmap(":/pics/backgrounds/838_cerveaucandy.jpg"));
        label1->setFixedSize(400,350);


        QPushButton bouton8("Continuer",&secondeFenetre);
        bouton8.setGeometry(100,100,210,43);
        bouton8.setCursor(Qt::PointingHandCursor);
        bouton8.setPalette(pal);
        bouton8.setFont(QFont("Comic Sans Ms",18));
        bouton8.setStyleSheet("background-color: white");





        QPushButton bouton10("Quitter",&secondeFenetre);
        bouton10.setGeometry(100,150,210,43);
        bouton10.setCursor(Qt::PointingHandCursor);
        bouton10.setPalette(pal);
        bouton10.setFont(QFont("Comic Sans Ms",18));
        bouton10.setStyleSheet("background-color: white");

        secondeFenetre.setWindowTitle("Menu");

        QObject::connect(&bouton8, SIGNAL(clicked()), &secondeFenetre, SLOT(hide()));
        QWidget::connect(&bouton7, SIGNAL(clicked()), &secondeFenetre, SLOT(exec()));


        label_fin = new QLabel(&fenetre2);
                label_fin->setFont(QFont("Chalkduster",50));
                label_fin->setGeometry(520,410,200,43);
                label_fin->setPalette(pal);
                label_fin->QLabel::raise();
                label_fin->setStyleSheet("QLabel { background-color ; color :red; }");

         label_fin1 = new QLabel(&fenetre2);

                        label_fin1->setGeometry(0,225,1200,250);

                        label_fin1->setPalette(pal);





                m_lcd = new QLCDNumber(&fenetre2);
                        m_lcd->setSegmentStyle(QLCDNumber::Flat);
                        m_lcd->setGeometry(80,370,110,45);
                        m_lcd->setPalette(pal);




        board=new jouer(&fenetre2);
        board->reset();
        board->initialiserCoordonees();
        board->tracerTable();
        board->detecter_ligne();
        board->detecter_colonne();
        board->detecter_ligne();
        board->detecter_colonne();
        board->detecter_ligne();
        board->detecter_colonne();







        MyTimer time;

        QString chemin, texte;
               chemin = "/Users/najwaerrachidy/Brain_Crush/highScores.txt";

                  while((texte = QInputDialog::getText(NULL, "Bienvenue à Brain Crush", "Choisir votre surnom")).isEmpty())
                      QMessageBox::critical(NULL,"Erreur","Aucun texte n'a été spécifié !");

                  QFile fichier(chemin);
                  fichier.open(QIODevice::Append | QIODevice::Text);

                  QTextStream flux(&fichier);
                  flux << texte <<"\n";

                  fichier.close();
















        // Affichage de la fenêtre
        fenetre.show();
        return app.exec();
}

