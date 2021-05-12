#ifndef MYTIMER_H
#define MYTIMER_H

#include <QtCore>
#include"jouer.h"
#include <QLCDNumber>
#include <QTime>
#include <QProgressBar>

extern jouer *board;
extern QLCDNumber *m_lcd,*lcd;
extern QLabel *label_fin;
extern QLabel *label_fin1;
extern QProgressBar *progress1,*progress2,*progress3;
extern QString str;
extern QLabel *etoile1;
extern QLabel *etoile2;
extern QLabel *etoile3;
extern QLabel *afficheurScore;


class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer();

    QTimer *myTimer;


public slots:
    void MySlot();


public:
    int compteur();


public:
    int minute,second;




};

#endif // MYTIMER_H


