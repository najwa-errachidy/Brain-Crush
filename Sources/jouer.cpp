#include "jouer.h"
#include "BrainCrush.h"
#include"Headers.h"
#include"mytimer.h"
int score1(0);
int score2(0);
int score(0);

BrainCrush* jouer::getBrain(int i, int j) {
    return table[i][j];
}
jouer::jouer(QWidget *fenetre){

    nombreDeDeplacement=3;
    table.resize(10);
    for(int i=0;i<10;i++){
        table[i].resize(10);
    }

    for(int i=0;i<10;i++){
            for(int j=0;j<10;j++)
            {
                table[i][j]=NULL;
            }
    }


    icone.resize(10);
    for(int i=0;i<10;i++){
        icone[i].resize(10);
    }
    for(int i=0;i<10;i++){
            for(int j=0;j<10;j++)
            {
                icone[i][j]=NULL;
                icone[i][j]= new QBrainH(fenetre);
            }
    }

    for(int i=0;i<10;i++){
            for(int j=0;j<10;j++)
            {
                icone[i][j]->setligne(j);
                icone[i][j]->setcolonne(i);

            }
    }

}
jouer::~jouer(){
}




void jouer::initialiserCoordonees() {
    int x=0;
    for(int i = 0; i < 10; i++)
     {

         int y=0;//lignes
        for(int j=0;j<10;j++){


            table[i][j]->setcolonne(x);
            table[i][j]->setligne(y);


            y+=80;
        }
        x+=80;
    }


}


void jouer::reset(){
    for(int i=0;i<10;i++){
            for(int j=0;j<10;j++)
            {
                table[i][j]=new BrainCrush();

            }
    }

    for(int i=0;i<10;i++){
            for(int j=0;j<8;j++)
            {
                if(table[i][j]->getcouleur()==table[i][j+1]->getcouleur() && table[i][j]->getcouleur()==table[i][j+2]->getcouleur()){
                    table[i][j+1]->setcouleur(rand()%5+1);
                }
            }
    }
    for(int j=0;j<10;j++){
            for(int i=0;i<8-2;i++)
            {
                if(table[i][j]->getcouleur()==table[i+1][j]->getcouleur() && table[i][j]->getcouleur()==table[i+2][j]->getcouleur()){
                    table[i+1][j]->setcouleur(rand()%5+1);
                }
            }
    }


}

int jouer::witchline(int l1,int c1,int l2,int c2){
    int l=-1;
    if(l1==l2){
        if(l1==0){
            if(icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType()){
                std::cout<<"if 1"<<std::endl;
                return c1;

            }
            else if(icone[l2][c2]->getType()==icone[l2+1][c2]->getType() && icone[l2][c2]->getType()==icone[l2+2][c2]->getType()){
                std::cout<<"if 2"<<std::endl;
                return c2;

            }
            if(c1<8 && icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType()){
                std::cout<<"if 1"<<std::endl;
                return c1;

            }
            else if(c2<8 && icone[l2][c2]->getType()==icone[l2][c2+1]->getType() && icone[l2][c2]->getType()==icone[l2][c2+2]->getType()){
                std::cout<<"if 2"<<std::endl;
                return c2;

            }
            if(c1>1 && icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType()){
                std::cout<<"if 1"<<std::endl;
                return c1;

            }
            else if(c2>1 && icone[l2][c2]->getType()==icone[l2][c2-1]->getType() && icone[l2][c2]->getType()==icone[l2][c2-2]->getType()){
                std::cout<<"if 2"<<std::endl;
                return c2;

            }
            if(c1!=0 && c1!=9 && icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+1]->getType()){
                std::cout<<"if 1"<<std::endl;
                return c1;

            }
            else if(c2!=0 && c2!=9 && icone[l2][c2]->getType()==icone[l2][c2-1]->getType() && icone[l2][c2]->getType()==icone[l2][c2+1]->getType()){
                std::cout<<"if 2"<<std::endl;
                return c2;

            }
        }
        else if (l1==9){
            if(icone[l1][c1]->getType()==icone[l1-1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-2][c1]->getType()){
                std::cout<<"if 3"<<std::endl;
                return c1;

            }
            else if(icone[l2][c2]->getType()==icone[l2-1][c2]->getType() && icone[l2][c2]->getType()==icone[l2-2][c2]->getType()){
                std::cout<<"if 4"<<std::endl;
                return c2;

            }
            if(c1<8 && icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType()){
                std::cout<<"if 1"<<std::endl;
                return c1;

            }
            else if(c2<8 && icone[l2][c2]->getType()==icone[l2][c2+1]->getType() && icone[l2][c2]->getType()==icone[l2][c2+2]->getType()){
                std::cout<<"if 2"<<std::endl;
                return c2;

            }
            if(c1>1 && icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType()){
                std::cout<<"if 1"<<std::endl;
                return c1;

            }
            else if(c2>1 && icone[l2][c2]->getType()==icone[l2][c2-1]->getType() && icone[l2][c2]->getType()==icone[l2][c2-2]->getType()){
                std::cout<<"if 2"<<std::endl;
                return c2;

            }
            if(c1!=0 && c1!=9 && icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+1]->getType()){
                std::cout<<"if 1"<<std::endl;
                return c1;

            }
            else if(c2!=0 && c2!=9 && icone[l2][c2]->getType()==icone[l2][c2-1]->getType() && icone[l2][c2]->getType()==icone[l2][c2+1]->getType()){
                std::cout<<"if 2"<<std::endl;
                return c2;

            }

        }
        else {

            if(icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-1][c1]->getType()){
                std::cout<<"if 5"<<std::endl;
                return c1;

            }
            else if(icone[l2][c2]->getType()==icone[l2+1][c2]->getType() && icone[l2][c2]->getType()==icone[l2-1][c2]->getType()){
                std::cout<<"if 6"<<std::endl;
                return c2;

            }
            else if(c1!=0 && c1!=9 && icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+1]->getType()){
                std::cout<<"if 61"<<std::endl;
                return c1;
            }
            else if(c2!=0 && c2!=9 && icone[l2][c2]->getType()==icone[l2][c2-1]->getType() && icone[l2][c2]->getType()==icone[l2][c2+1]->getType()){
                std::cout<<"if 62"<<std::endl;
                return c2;
            }
            else if(c1>1  && icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType()){
                std::cout<<"if 61"<<std::endl;
                return c1;
            }
            else if(c2>1 && icone[l2][c2]->getType()==icone[l2][c2-1]->getType() && icone[l2][c2]->getType()==icone[l2][c2-2]->getType()){
                std::cout<<"if 62"<<std::endl;
                return c2;
            }
            else if(c1<8 && icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType()){
                std::cout<<"if 63"<<std::endl;
                return c1;
            }
            else if(c2<8 && icone[l2][c2]->getType()==icone[l2][c2+1]->getType() && icone[l2][c2]->getType()==icone[l2][c2+2]->getType()){
                std::cout<<"if 64"<<std::endl;
                return c2;
            }
            if(l1==1 || l1==8){
               if(l1==8 && icone[l1][c1]->getType()==icone[l1-1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-2][c1]->getType()){
                   std::cout<<"if 185"<<std::endl;
                   return c1;
               }
               else if(l1==1 && icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType()){
                   std::cout<<"if 186"<<std::endl;
                   return c1;
               }
               else if(l2==8 && icone[l2][c2]->getType()==icone[l2-2][c2]->getType() && icone[l2][c2]->getType()==icone[l2-2][c2]->getType()){
                   std::cout<<"if 185"<<std::endl;
                   return c2;
               }
               else if(l2==1 && icone[l2][c2]->getType()==icone[l2+1][c2]->getType() && icone[l2][c2]->getType()==icone[l2+2][c2]->getType()){
                   std::cout<<"if 186"<<std::endl;
                   return c2;
               }

           }
            if(l1>1 && l1<8){

                if(icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType()){
                    std::cout<<"if 7"<<std::endl;
                    return c1;

                }
                else if(icone[l1][c1]->getType()==icone[l1-1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-2][c1]->getType()){
                    std::cout<<"if 7"<<std::endl;
                    return c1;

                }

                else if(icone[l2][c2]->getType()==icone[l2+1][c2]->getType() && icone[l2][c2]->getType()==icone[l2+2][c2]->getType()){
                    std::cout<<"if 8"<<std::endl;
                    return c2;

                }
                else if(icone[l2][c2]->getType()==icone[l2-1][c2]->getType() && icone[l2][c2]->getType()==icone[l2- 2][c2]->getType()){
                    std::cout<<"if 8"<<std::endl;
                    return c2;

                }
                else if(c1!=0 && c1!=9 && icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-1]->getType()){
                    std::cout<<"if 9"<<std::endl;
                    return c1;
                }
                else if(c2!=0 && c2!=9 && icone[l2][c2]->getType()==icone[l2][c2+1]->getType() && icone[l2][c2]->getType()==icone[l2][c2-1]->getType()){
                    std::cout<<"if 10"<<std::endl;
                    return c2;
                }
                else if(c1>1 && icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType()){
                    std::cout<<"if 11"<<std::endl;
                    return c1;
                }
                else if(c2>1 && icone[l2][c2]->getType()==icone[l2][c2-1]->getType() && icone[l2][c2]->getType()==icone[l2][c2-2]->getType()){
                    std::cout<<"if 12"<<std::endl;
                    return c2;
                }
                else if(c1<8 && icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType()){
                    std::cout<<"if 121"<<std::endl;
                    return c1;
                }
                else if(c2<8 && icone[l2][c2]->getType()==icone[l2][c2+1]->getType() && icone[l2][c2]->getType()==icone[l2][c2+2]->getType()){
                    std::cout<<"if 122"<<std::endl;
                    return c2;
                }
            }
            else if(l1<8){
                if(icone[l1][c1]->getType()==icone[l1-1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-2][c1]->getType()){
                    std::cout<<"if 7"<<std::endl;
                    return c1;

                }
                else if(icone[l2][c2]->getType()==icone[l2-1][c2]->getType() && icone[l2][c2]->getType()==icone[l2-2][c2]->getType()){
                    std::cout<<"if 8"<<std::endl;
                    return c2;

                }
                else if(c1!=0 && c1!=9 && icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-1]->getType()){
                    std::cout<<"if 9"<<std::endl;
                    return c1;
                }
                else if(c2!=0 && c2!=9 && icone[l2][c2]->getType()==icone[l2][c2+1]->getType() && icone[l2][c2]->getType()==icone[l2][c2-1]->getType()){
                    std::cout<<"if 10"<<std::endl;
                    return c2;
                }
                else if(c1>1 && icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType()){
                    std::cout<<"if 11"<<std::endl;
                    return c1;
                }
                else if(c2>1 && icone[l2][c2]->getType()==icone[l2][c2-1]->getType() && icone[l2][c2]->getType()==icone[l2][c2-2]->getType()){
                    std::cout<<"if 12"<<std::endl;
                    return c2;
                }
                else if(c1<8 && icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType()){
                    std::cout<<"if 121"<<std::endl;
                    return c1;
                }
                else if(c2<8 && icone[l2][c2]->getType()==icone[l2][c2+1]->getType() && icone[l2][c2]->getType()==icone[l2][c2+2]->getType()){
                    std::cout<<"if 122"<<std::endl;
                    return c2;
                }
            }
        }

    }
    else{
        if(c1==0){
            if(icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType()){
                std::cout<<"if 13"<<std::endl;
                return l1;
            }
            else if(icone[l2][c2]->getType()==icone[l2][c2+1]->getType() && icone[l2][c2]->getType()==icone[l2][c2+2]->getType()){
                std::cout<<"if 14"<<std::endl;
                return l2;
            }
            if(l1<8 && icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType()){
                std::cout<<"if 1"<<std::endl;
                return l1;

            }
            else if(l2<8 && icone[l2][c2]->getType()==icone[l2+1][c2]->getType() && icone[l2][c2]->getType()==icone[l2+2][c2]->getType()){
                std::cout<<"if 2"<<std::endl;
                return l2;

            }
            if(l1>1 && icone[l1][c1]->getType()==icone[l1-1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-2][c1]->getType()){
                std::cout<<"if 1"<<std::endl;
                return l1;

            }
            else if(l2>1 && icone[l2][c2]->getType()==icone[l2-1][c2]->getType() && icone[l2][c2]->getType()==icone[l2-2][c2]->getType()){
                std::cout<<"if 2"<<std::endl;
                return l2;

            }
            if(l1!=0 && l1!=9 && icone[l1][c1]->getType()==icone[l1-1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+1][c1]->getType()){
                std::cout<<"if 1"<<std::endl;
                return l1;

            }
            else if(l2!=0 && l2!=9 && icone[l2][c2]->getType()==icone[l2-1][c2]->getType() && icone[l2][c2]->getType()==icone[l2+1][c2]->getType()){
                std::cout<<"if 2"<<std::endl;
                return l2;

            }
        }
        else if (c1==9){
            if(icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType()){
                std::cout<<"if 15"<<std::endl;
                return l1;
            }
            else if(icone[l2][c2]->getType()==icone[l2][c2-1]->getType() && icone[l2][c2]->getType()==icone[l2][c2-2]->getType()){
                std::cout<<"if 16"<<std::endl;
                return l2;
            }
            if(l1<8 && icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType()){
                std::cout<<"if 1"<<std::endl;
                return l1;

            }
            else if(l2<8 && icone[l2][c2]->getType()==icone[l2+1][c2]->getType() && icone[l2][c2]->getType()==icone[l2+2][c2]->getType()){
                std::cout<<"if 2"<<std::endl;
                return l2;

            }
            if(l1>1 && icone[l1][c1]->getType()==icone[l1-1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-2][c1]->getType()){
                std::cout<<"if 1"<<std::endl;
                return l1;

            }
            else if(l2>1 && icone[l2][c2]->getType()==icone[l2-1][c2]->getType() && icone[l2][c2]->getType()==icone[l2-2][c2]->getType()){
                std::cout<<"if 2"<<std::endl;
                return l2;

            }
            if(l1!=0 && l1!=9 && icone[l1][c1]->getType()==icone[l1-1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+1][c1]->getType()){
                std::cout<<"if 1"<<std::endl;
                return l1;

            }
            else if(l2!=0 && l2!=9 && icone[l2][c2]->getType()==icone[l2-1][c2]->getType() && icone[l2][c2]->getType()==icone[l2+1][c2]->getType()){
                std::cout<<"if 2"<<std::endl;
                return l2;

            }
        }
        else {

            if(icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-1]->getType()){
                std::cout<<"if 17"<<std::endl;
                return l1;
            }
            else if( icone[l2][c2]->getType()==icone[l2][c2+1]->getType() && icone[l2][c2]->getType()==icone[l2][c2-1]->getType()){
                std::cout<<"if 18"<<std::endl;
                return l2;
            }
            else if(l2!=0 && l2!=9 && icone[l2][c2]->getType()==icone[l2-1][c2]->getType() && icone[l2][c2]->getType()==icone[l2+1][c2]->getType()){
                std::cout<<"if 181"<<std::endl;
                return l2;
            }
            else if(l1!=0 && l1!=9 && icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-1][c1]->getType()){
                std::cout<<"if 182"<<std::endl;
                return l1;
            }
            else if(l2>1 && icone[l2][c2]->getType()==icone[l2-1][c2]->getType() && icone[l2][c2]->getType()==icone[l2-2][c2]->getType()){
                std::cout<<"if 181"<<std::endl;
                return l2;
            }
            else if(l1>1 && icone[l1][c1]->getType()==icone[l1-2][c1]->getType() && icone[l1][c1]->getType()==icone[l1-1][c1]->getType()){
                std::cout<<"if 182"<<std::endl;
                return l1;
            }
            else if(l2<8 && icone[l2][c2]->getType()==icone[l2+1][c2]->getType() && icone[l2][c2]->getType()==icone[l2+2][c2]->getType()){
                std::cout<<"if 183"<<std::endl;
                return l2;
            }
            else if(l1<8 && icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType()){
                std::cout<<"if 184"<<std::endl;
                return l1;
            }
            if(c1==1 || c1==8){
               if(c1==8 && icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType()){
                   std::cout<<"if 185"<<std::endl;
                   return l1;
               }
               else if(c1==1 && icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType()){
                   std::cout<<"if 186"<<std::endl;
                   return l1;
               }
               if(c2==8 && icone[l2][c2]->getType()==icone[l2][c2-1]->getType() && icone[l2][c2]->getType()==icone[l2][c2-2]->getType()){
                   std::cout<<"if 185"<<std::endl;
                   return l2;
               }
               else if(c2==1 && icone[l2][c2]->getType()==icone[l2][c2+1]->getType() && icone[l2][c2]->getType()==icone[l2][c2+2]->getType()){
                   std::cout<<"if 186"<<std::endl;
                   return l2;
               }

           }


            if(c1>1 && c1<8){
                if(icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType()){
                   std::cout<<"if 19"<<std::endl;
                   return l1;
                }
                else if(icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType()){
                   std::cout<<"if 19"<<std::endl;
                   return l1;
                }
                else if(icone[l2][c2]->getType()==icone[l2][c2-1]->getType() && icone[l2][c2]->getType()==icone[l2][c2-2]->getType()){
                   std::cout<<"if 19"<<std::endl;
                   return l2;
                }
                else if(icone[l2][c2]->getType()==icone[l2][c2+1]->getType() && icone[l2][c2]->getType()==icone[l2][c2+2]->getType()){
                    std::cout<<"if 20"<<std::endl;
                    return l2;
                }
                else if(l1!=0 && l1!=9 && icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-1][c1]->getType()){
                    std::cout<<"if 21"<<std::endl;
                    return l1;
                }
                else if(l2!=0 && l2!=9 && icone[l2][c2]->getType()==icone[l2+1][c2]->getType() && icone[l2][c2]->getType()==icone[l2-1][c2]->getType()){
                    std::cout<<"if 22"<<std::endl;
                    return l2;
                }
                else if(l1>1 && icone[l1][c1]->getType()==icone[l1-1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-2][c1]->getType()){
                    std::cout<<"if 23"<<std::endl;
                    return l1;
                }
                else if(l2>1 && icone[l2][c2]->getType()==icone[l2-1][c2]->getType() && icone[l2][c2]->getType()==icone[l2-2][c2]->getType()){
                    std::cout<<"if 24"<<std::endl;
                    return l2;
                }
                else if(l2<8 && icone[l2][c2]->getType()==icone[l2+1][c2]->getType() && icone[l2][c2]->getType()==icone[l2+2][c2]->getType()){
                    std::cout<<"if 241"<<std::endl;
                    return l2;
                }
                else if(l1<8 && icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType()){
                    std::cout<<"if 242"<<std::endl;
                    return l1;
                }


            }
            else if(c1<8){
                if(icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType()){
                   std::cout<<"if 19"<<std::endl;
                   return l1;
                }
                else if(icone[l2][c2]->getType()==icone[l2][c2-1]->getType() && icone[l2][c2]->getType()==icone[l2][c2-2]->getType()){
                    std::cout<<"if 20"<<std::endl;
                    return l2;
                }
                else if(l1!=0 && l1!=9 && icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-1][c1]->getType()){
                    std::cout<<"if 21"<<std::endl;
                    return l1;
                }
                else if(l2!=0 && l2!=9 && icone[l2][c2]->getType()==icone[l2+1][c2]->getType() && icone[l2][c2]->getType()==icone[l2-1][c2]->getType()){
                    std::cout<<"if 22"<<std::endl;
                    return l2;
                }
                else if(l1>1 && icone[l1][c1]->getType()==icone[l1-1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-2][c1]->getType()){
                    std::cout<<"if 23"<<std::endl;
                    return l1;
                }
                else if(l2>1 && icone[l2][c2]->getType()==icone[l2-1][c2]->getType() && icone[l2][c2]->getType()==icone[l2-2][c2]->getType()){
                    std::cout<<"if 24"<<std::endl;
                    return l2;
                }
                else if(l2<8 && icone[l2][c2]->getType()==icone[l2+1][c2]->getType() && icone[l2][c2]->getType()==icone[l2+2][c2]->getType()){
                    std::cout<<"if 241"<<std::endl;
                    return l2;
                }
                else if(l1<8 && icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType()){
                    std::cout<<"if 242"<<std::endl;
                    return l1;
                }

            }
        }
    }

    return l;
}

void jouer::Switch()
        {
    std::cout<<"entree"<<std::endl;
    int T[4];
    int k(0);

    if(compt==2){
        std::cout<<"entree2"<<std::endl;
        for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    if(icone[i][j]->getIsPress())
                    {
                        T[k]=i;
                        T[k+1]=j;
                        k+=2;
                    }

                }
            }
        //if(isMovePossible(T[2],T[3],T[0],T[1])){
                        //rec1=table[T[0]][T[1]]->getcouleur();
                        //rec2=table[T[2]][T[3]]->getcouleur();
                        //table[T[0]][T[1]]->setcouleur(rec2);
                        //table[T[2]][T[3]]->setcouleur(rec1);*/

                QString rec1=icone[T[0]][T[1]]->getType();
                QString rec2=icone[T[2]][T[3]]->getType();


                //int ligne1=icone[T[0]][T[1]]->getligne();
                //int ligne2=icone[T[2]][T[3]]->getligne();
                //int colonne1=icone[T[0]][T[1]]->getcolonne();
                //int colonne2=icone[T[2]][T[3]]->getcolonne();


                icone[T[0]][T[1]]->setType(rec2);
                icone[T[2]][T[3]]->setType(rec1);


                //icone[T[0]][T[1]]->setligne(ligne2);
                //icone[T[2]][T[3]]->setligne(ligne1);
                //icone[T[0]][T[1]]->setcolonne(colonne2);
                //icone[T[2]][T[3]]->setcolonne(colonne1);


                 icone[T[0]][T[1]]->tracer();
                 icone[T[2]][T[3]]->tracer();


                 std::cout<<"donedone"<<std::endl;
                 compt=0;
                 for(int i=0;i<10;i++){
                         for(int j=0;j<10;j++){
                             icone[i][j]->setIsPress(false);


                         }
                     }
                 if(witchline(T[0],T[1],T[2],T[3])>=0){
                     if(T[1]==T[3]){
                         if(witchline(T[0],T[1],T[2],T[3])==T[0]){
                             ChangerTable(T[0],T[1],T[2],T[3]);
                             std::cout<<"bugl"<<std::endl;
                         }
                         else{
                             ChangerTable(T[2],T[3],T[0],T[1]);
                             std::cout<<"debugl"<<std::endl;
                         }
                     }
                     else{
                         if(witchline(T[0],T[1],T[2],T[3])==T[1]){
                             ChangerTable(T[0],T[1],T[2],T[3]);
                             std::cout<<"bugc"<<std::endl;
                         }
                         else{
                             ChangerTable(T[2],T[3],T[0],T[1]);
                             std::cout<<"debugc"<<std::endl;
                         }

                     }



                 }
                 else{
                     QString rec3=icone[T[0]][T[1]]->getType();
                     QString rec4=icone[T[2]][T[3]]->getType();
                     icone[T[0]][T[1]]->setType(rec4);
                     icone[T[2]][T[3]]->setType(rec3);
                     icone[T[0]][T[1]]->tracer();
                     icone[T[2]][T[3]]->tracer();
                     std::cout<<"switch"<<std::endl;
                 }


        }

        else if(compt>2){
            compt=0;
            for(int i=0;i<10;i++){
                    for(int j=0;j<10;j++){
                        icone[i][j]->setIsPress(false);


                    }
                }
        }



}



void jouer::tracerTable()
{
   int x=400;
   for(int i = 0; i < 10; i++)
    {

        int y=0;//lignes
       for(int j=0;j<10;j++){

                icone[i][j]->setcolonne(y);
                icone[i][j]->setligne(x);
               icone[i][j]->setPixmap(QPixmap(icone[i][j]->getType()));
               icone[i][j]->setGeometry(x, y, 80, 80);

           y+=80;
       }
       x+=80;
   }

}


QString jouer::getType_(int x){
    QString type_;
    if (x==4){

        type_="/Users/najwaerrachidy/Brain_Crush/Brains/brain yellow.png";
    }
    else if (x==1){
        type_="/Users/najwaerrachidy/Brain_Crush/Brains/brain blue.png";

    }
    else if (x==2){
        type_="/Users/najwaerrachidy/Brain_Crush/Brains/brain green.png";

    }
    else if (x==3){
        type_="/Users/najwaerrachidy/Brain_Crush/Brains/brain purple.png";
    }
    else if (x==5){
        type_="/Users/najwaerrachidy/Brain_Crush/Brains/brain red.png";
    }
    return type_;
}



    void jouer::ChangerTable(int l1, int c1,int l2,int c2)
    {


            if(l1==0 && c1==0){
                icone[0][0]->setType(getType_(rand()%5+1));
                icone[1][0]->setType(getType_(rand()%5+1));
                icone[2][0]->setType(getType_(rand()%5+1));
                icone[0][0]->tracer();
                icone[1][0]->tracer();
                icone[2][0]->tracer();
                std::cout<<"1"<<std::endl;
                score+=300;
            }

            else if(l1==9 && c1==9){
                if(l1==l2){
                    for(int k=9;k>0;k--){
                        icone[9][k]->setType(icone[9][k-1]->getType());
                        icone[8][k]->setType(icone[8][k-1]->getType());
                        icone[7][k]->setType(icone[7][k-1]->getType());
                        icone[9][k]->tracer();
                        icone[8][k]->tracer();
                        icone[7][k]->tracer();
                    }
                    icone[9][0]->setType(getType_(rand()%5+1));
                    icone[8][0]->setType(getType_(rand()%5+1));
                    icone[7][0]->setType(getType_(rand()%5+1));
                    std::cout<<"2"<<std::endl;
                    score+=300;
                }
                else{
                    for(int k=6;k>0;k--){
                        icone[9][k]->setType(icone[9][k-1]->getType());
                        icone[9][k]->tracer();

                    }
                    icone[9][0]->setType(getType_(rand()%5+1));
                    std::cout<<"3"<<std::endl;

                }
                score+=300;
            }
            else if(l1==0 && c1==9){

                if(l1==l2){
                    for(int k=9;k>0;k--){
                        icone[0][k]->setType(icone[0][k-1]->getType());
                        icone[1][k]->setType(icone[1][k-1]->getType());
                        icone[2][k]->setType(icone[2][k-1]->getType());
                        icone[0][k]->tracer();
                        icone[1][k]->tracer();
                        icone[2][k]->tracer();
                    }
                    icone[0][0]->setType(getType_(rand()%5+1));
                    icone[1][0]->setType(getType_(rand()%5+1));
                    icone[2][0]->setType(getType_(rand()%5+1));
                    std::cout<<"4"<<std::endl;
                    score+=300;
                }
                else{
                    for(int k=6;k>0;k--){
                        icone[0][k]->setType(icone[9][k-1]->getType());
                        icone[0][k]->tracer();

                    }
                    icone[0][0]->setType(getType_(rand()%5+1));
                    std::cout<<"5"<<std::endl;
                score+=300;
                }

            }
            else if(l1==9 && c1==0){
                icone[9][0]->setType(getType_(rand()%5+1));
                icone[8][0]->setType(getType_(rand()%5+1));
                icone[7][0]->setType(getType_(rand()%5+1));
                icone[9][0]->tracer();
                icone[8][0]->tracer();
                icone[7][0]->tracer();
                std::cout<<"6"<<std::endl;
                score+=300;
            }
            else if(l1==0 && l1==l2){
                if(icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType()){
                    for(int k=c1;k>0;k--){
                    icone[l1+1][k]->setType(icone[l1+1][k-1]->getType());
                    icone[l1+2][k]->setType(icone[l1+2][k-1]->getType());
                    icone[l1][k]->setType(icone[l1][k-1]->getType());
                    icone[l1+1][k]->tracer();
                    icone[l1+2][k]->tracer();
                    icone[l1][k]->tracer();
                    }
                    icone[l1+1][0]->setType((getType_(rand()%5+1)));
                    icone[l1+2][0]->setType(getType_(rand()%5+1));
                    icone[l1][0]->setType(getType_(rand()%5+1));
                    icone[l1+1][0]->tracer();
                    icone[l1+2][0]->tracer();
                    icone[l1][0]->tracer();
                    std::cout<<"7"<<std::endl;
                    score+=300;
                }
                else if(c1>1 && icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType()){
                    int l=3;

                    for(int k=c1;k>0;k--){
                        if(c1-l>=0){
                            icone[l1][k]->setType(icone[l1][c1-l]->getType());
                            icone[l1][k]->tracer();
                            l++;
                        }
                        else{
                            icone[l1][k]->setType(getType_(rand()%5+1));
                            icone[l1][k]->tracer();
                        }
                    }
                    l=0;
                    icone[l1][0]->setType(getType_(rand()%5+1));
                    icone[l1][0]->tracer();
                    score+=300;
                }
                else if(c1<8 && icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType()){
                    int l=1;

                    for(int k=c1+2;k>0;k--){
                        if(c1-l>=0){
                            icone[l1][k]->setType(icone[l1][c1-l]->getType());
                            icone[l1][k]->tracer();
                            l++;
                        }
                        else{
                            icone[l1][k]->setType(getType_(rand()%5+1));
                            icone[l1][k]->tracer();
                        }

                    }
                    l=0;
                    icone[l1][0]->setType(getType_(rand()%5+1));
                    icone[l1][0]->tracer();
                    score+=300;
                }


            }
             else if(c1==0 && c1==c2){

                        icone[l1][c1]->setType((getType_(rand()%5+1)));
                        icone[l1][c1+1]->setType(getType_(rand()%5+1));
                        icone[l1][c1+2]->setType(getType_(rand()%5+1));
                        icone[l1][c1]->tracer();
                        icone[l1][c1+1]->tracer();
                        icone[l1][c1+2]->tracer();
                        std::cout<<"8"<<std::endl;
                        score+=300;

                }
            else if(l1==9 && l1==l2){

                        for(int k=c1;k>0;k--){
                        icone[l1][k]->setType(icone[l1][k-1]->getType());
                        icone[l1-1][k]->setType(icone[l1-1][k-1]->getType());
                        icone[l1-2][k]->setType(icone[l1-2][k-1]->getType());
                        icone[l1][k]->tracer();
                        icone[l1-1][k]->tracer();
                        icone[l1-2][k]->tracer();
                        }
                        icone[l1-1][0]->setType((getType_(rand()%5+1)));
                        icone[l1-2][0]->setType(getType_(rand()%5+1));
                        icone[l1][0]->setType(getType_(rand()%5+1));
                        icone[l1-1][0]->tracer();
                        icone[l1-2][0]->tracer();
                        icone[l1][0]->tracer();
                        std::cout<<"9"<<std::endl;
                        score+=300;


            }
            else if(c1==9 && c1==c2){
                for(int k=9;k>2;k--){

                icone[l1][k]->setType(icone[l1][k-1]->getType());
                icone[l1][k]->tracer();

                }
                       icone[l1][0]->setType((getType_(rand()%5+1)));
                       icone[l1][1]->setType(getType_(rand()%5+1));
                       icone[l1][2]->setType(getType_(rand()%5+1));
                       icone[l1][0]->tracer();
                       icone[l1][1]->tracer();
                       icone[l1][2]->tracer();
                       std::cout<<"10"<<std::endl;
                       score+=300;
               }

            else {

                if(l1==l2){

                    if(l1>1 && l1<8){

                        if(icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType() && icone[l1][c1]->getType()==icone[l1-1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-2][c1]->getType()){
                            for(int k=c1;k>0;k--){
                            icone[l1][k]->setType(icone[l1][k-1]->getType());
                            icone[l1-1][k]->setType(icone[l1-1][k-1]->getType());
                            icone[l1-2][k]->setType(icone[l1-2][k-1]->getType());
                            icone[l1+1][k]->setType(icone[l1+1][k-1]->getType());
                            icone[l1+2][k]->setType(icone[l1+2][k-1]->getType());
                            icone[l1][k]->tracer();
                            icone[l1-1][k]->tracer();
                            icone[l1-2][k]->tracer();
                            icone[l1+1][k]->tracer();
                            icone[l1+2][k]->tracer();
                            }
                            icone[l1+1][0]->setType((getType_(rand()%5+1)));
                            icone[l1+2][0]->setType(getType_(rand()%5+1));
                            icone[l1][0]->setType(getType_(rand()%5+1));
                            icone[l1-1][0]->setType((getType_(rand()%5+1)));
                            icone[l1-2][0]->setType(getType_(rand()%5+1));

                            icone[l1-1][0]->tracer();
                            icone[l1-2][0]->tracer();
                            icone[l1][0]->tracer();
                            icone[l1+1][0]->tracer();
                            icone[l1+2][0]->tracer();
                            std::cout<<"11"<<std::endl;
                            score+=500;

                        }
                        else if(icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType() &&icone[l1][c1]->getType()==icone[l1-1][c1]->getType() ){
                            for(int k=c1;k>0;k--){
                            icone[l1][k]->setType(icone[l1][k-1]->getType());
                            icone[l1-1][k]->setType(icone[l1-1][k-1]->getType());
                            icone[l1+1][k]->setType(icone[l1+1][k-1]->getType());
                            icone[l1+2][k]->setType(icone[l1+2][k-1]->getType());
                            icone[l1][k]->tracer();
                            icone[l1-1][k]->tracer();
                            icone[l1+1][k]->tracer();
                            icone[l1+2][k]->tracer();
                            }
                            icone[l1-1][0]->setType(getType_((rand()%5+1)));
                            icone[l1][0]->setType(getType_((rand()%5+1)));
                            icone[l1+1][0]->setType(getType_((rand()%5+1)));
                            icone[l1+2][0]->setType(getType_((rand()%5+1)));
                            icone[l1-1][0]->tracer();
                            icone[l1][0]->tracer();
                            icone[l1+1][0]->tracer();
                            icone[l1+2][0]->tracer();
                            std::cout<<"12"<<std::endl;
                            score+=400;


                        }
                        else if(icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-2][c1]->getType() &&icone[l1][c1]->getType()==icone[l1-1][c1]->getType()){
                            for(int k=c1;k>0;k--){
                            icone[l1][k]->setType(icone[l1][k-1]->getType());
                            icone[l1-1][k]->setType(icone[l1-1][k-1]->getType());
                            icone[l1+1][k]->setType(icone[l1+1][k-1]->getType());
                            icone[l1-2][k]->setType(icone[l1+2][k-1]->getType());
                            icone[l1][k]->tracer();
                            icone[l1-1][k]->tracer();
                            icone[l1+1][k]->tracer();
                            icone[l1-2][k]->tracer();
                            }
                            icone[l1-1][0]->setType(getType_((rand()%5+1)));
                            icone[l1-2][0]->setType(getType_((rand()%5+1)));
                            icone[l1][0]->setType(getType_((rand()%5+1)));
                            icone[l1+1][0]->setType(getType_((rand()%5+1)));
                            icone[l1-1][0]->tracer();
                            icone[l1-2][0]->tracer();
                            icone[l1][0]->tracer();
                            icone[l1+1][0]->tracer();
                            std::cout<<"13"<<std::endl;
                            score+=400;
                        }
                        else if(icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-1][c1]->getType() ){
                            for(int k=c1;k>0;k--){
                            icone[l1][k]->setType(icone[l1][k-1]->getType());
                            icone[l1-1][k]->setType(icone[l1-1][k-1]->getType());
                            icone[l1+1][k]->setType(icone[l1+1][k-1]->getType());
                            icone[l1][k]->tracer();
                            icone[l1-1][k]->tracer();
                            icone[l1+1][k]->tracer();
                            }
                            icone[l1-1][0]->setType(getType_((rand()%5+1)));
                            icone[l1+1][0]->setType(getType_((rand()%5+1)));
                            icone[l1][0]->setType(getType_((rand()%5+1)));
                            icone[l1-1][0]->tracer();
                            icone[l1+1][0]->tracer();
                            icone[l1][0]->tracer();
                            std::cout<<"14"<<std::endl;
                            score+=300;
                        }

                        else if(icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType() ){

                            for(int k=c1;k>0;k--){
                            icone[l1][k]->setType(icone[l1][k-1]->getType());
                            icone[l1+2][k]->setType(icone[l1+2][k-1]->getType());
                            icone[l1+1][k]->setType(icone[l1+1][k-1]->getType());
                            icone[l1][k]->tracer();
                            icone[l1+2][k]->tracer();
                            icone[l1+1][k]->tracer();
                            }
                            icone[l1+1][0]->setType(getType_((rand()%5+1)));
                            icone[l1+2][0]->setType(getType_((rand()%5+1)));
                            icone[l1][0]->setType(getType_((rand()%5+1)));
                            icone[l1+1][0]->tracer();
                            icone[l1+2][0]->tracer();
                            icone[l1][0]->tracer();
                            std::cout<<"15"<<std::endl;
                            score+=300;
                           }
                        else if (icone[l1][c1]->getType()==icone[l1-1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-2][c1]->getType() ) {
                            for(int k=c1;k>0;k--){
                            icone[l1][k]->setType(icone[l1][k-1]->getType());
                            icone[l1-2][k]->setType(icone[l1-2][k-1]->getType());
                            icone[l1-1][k]->setType(icone[l1-1][k-1]->getType());
                            icone[l1][k]->tracer();
                            icone[l1-2][k]->tracer();
                            icone[l1-1][k]->tracer();
                            }
                            icone[l1-1][0]->setType(getType_((rand()%5+1)));
                            icone[l1-2][0]->setType(getType_((rand()%5+1)));
                            icone[l1][0]->setType(getType_((rand()%5+1)));
                            icone[l1-1][0]->tracer();
                            icone[l1-2][0]->tracer();
                            icone[l1][0]->tracer();
                            std::cout<<"16"<<std::endl;
                            score+=300;
                           }
                        else if(c1<8 && icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType()){
                            int l=1;

                            for(int k=c1+2;k>0;k--){
                                if(c1-l>=0){
                                    icone[l1][k]->setType(icone[l1][c1-l]->getType());
                                    icone[l1][k]->tracer();
                                    l++;
                                }
                                else{
                                    icone[l1][k]->setType(getType_(rand()%5+1));
                                    icone[l1][k]->tracer();
                                }

                        }

                            score+=300;

                        }
                        else if(c1>1 && icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType()){
                            int l=3;

                            for(int k=c1;k>0;k--){
                                if(c1-l>=0){
                                    icone[l1][k]->setType(icone[l1][c1-l]->getType());
                                    icone[l1][k]->tracer();
                                    l++;
                                }
                                else{
                                    icone[l1][k]->setType(getType_(rand()%5+1));
                                    icone[l1][k]->tracer();
                                }
                        }
                            score+=300;



                        }
                    }

                    else if(l1==1){
                        if(icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType() &&icone[l1][c1]->getType()==icone[l1-1][c1]->getType()){
                            for(int k=c1;k>0;k--){
                            icone[l1][k]->setType(icone[l1][k-1]->getType());
                            icone[l1-1][k]->setType(icone[l1-1][k-1]->getType());
                            icone[l1+1][k]->setType(icone[l1+1][k-1]->getType());
                            icone[l1+2][k]->setType(icone[l1+2][k-1]->getType());
                            icone[l1][k]->tracer();
                            icone[l1-1][k]->tracer();
                            icone[l1+1][k]->tracer();
                            icone[l1+2][k]->tracer();
                            }
                            icone[l1-1][0]->setType(getType_((rand()%5+1)));
                            icone[l1][0]->setType(getType_((rand()%5+1)));
                            icone[l1+1][0]->setType(getType_((rand()%5+1)));
                            icone[l1+2][0]->setType(getType_((rand()%5+1)));
                            icone[l1-1][0]->tracer();
                            icone[l1][0]->tracer();
                            icone[l1+1][0]->tracer();
                            icone[l1+2][0]->tracer();
                            std::cout<<"17"<<std::endl;
                            score+=400;
                        }
                        else if(icone[l1][c1]->getType()==icone[l1+1][c1]->getType()  &&icone[l1][c1]->getType()==icone[l1-1][c1]->getType()){

                            for(int k=c1;k>0;k--){
                            icone[l1][k]->setType(icone[l1][k-1]->getType());
                            icone[l1-1][k]->setType(icone[l1-1][k-1]->getType());
                            icone[l1+1][k]->setType(icone[l1+1][k-1]->getType());

                            icone[l1][k]->tracer();
                            icone[l1-1][k]->tracer();
                            icone[l1+1][k]->tracer();
                            }
                            icone[l1-1][0]->setType(getType_((rand()%5+1)));
                            icone[l1][0]->setType(getType_((rand()%5+1)));
                            icone[l1+1][0]->setType(getType_((rand()%5+1)));
                            icone[l1-1][0]->tracer();
                            icone[l1][0]->tracer();
                            icone[l1+1][0]->tracer();
                            std::cout<<"18"<<std::endl;
                            score+=300;
                        }
                        else if(icone[l1][c1]->getType()==icone[l1+1][c1]->getType()  &&icone[l1][c1]->getType()==icone[l1+2][c1]->getType()){

                            for(int k=c1;k>0;k--){
                            icone[l1][k]->setType(icone[l1][k-1]->getType());
                            icone[l1+2][k]->setType(icone[l1+2][k-1]->getType());
                            icone[l1+1][k]->setType(icone[l1+1][k-1]->getType());

                            icone[l1][k]->tracer();
                            icone[l1+2][k]->tracer();
                            icone[l1+1][k]->tracer();
                            }
                            icone[l1+2][0]->setType(getType_((rand()%5+1)));
                            icone[l1][0]->setType(getType_((rand()%5+1)));
                            icone[l1+1][0]->setType(getType_((rand()%5+1)));
                            icone[l1+2][0]->tracer();
                            icone[l1][0]->tracer();
                            icone[l1+1][0]->tracer();
                            std::cout<<"18"<<std::endl;
                            score+=300;
                        }

                        else if(c1<8 && icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType()){
                            int l=1;

                            for(int k=c1+2;k>0;k--){
                                if(c1-l>=0){
                                    icone[l1][k]->setType(icone[l1][c1-l]->getType());
                                    icone[l1][k]->tracer();
                                    l++;
                                }
                                else{
                                    icone[l1][k]->setType(getType_(rand()%5+1));
                                    icone[l1][k]->tracer();
                                }
                        }
                            score+=300;

                        }

                         else if(c1>1 && icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType()){
                            int l=3;

                            for(int k=c1;k>0;k--){
                                if(c1-l>=0){
                                    icone[l1][k]->setType(icone[l1][c1-l]->getType());
                                    icone[l1][k]->tracer();
                                    l++;
                                }
                                else{
                                    icone[l1][k]->setType(getType_(rand()%5+1));
                                    icone[l1][k]->tracer();
                                }
                        }

                        }
                        score+=300;


                    }
                else if (l1==8) {
                    if(icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-2][c1]->getType() &&icone[l1][c1]->getType()==icone[l1-1][c1]->getType()){
                        for(int k=c1;k>0;k--){
                        icone[l1][k]->setType(icone[l1][k-1]->getType());
                        icone[l1-1][k]->setType(icone[l1-1][k-1]->getType());
                        icone[l1+1][k]->setType(icone[l1+1][k-1]->getType());
                        icone[l1-2][k]->setType(icone[l1-2][k-1]->getType());
                        icone[l1][k]->tracer();
                        icone[l1-1][k]->tracer();
                        icone[l1+1][k]->tracer();
                        icone[l1-2][k]->tracer();
                        }
                        icone[l1-1][0]->setType(getType_((rand()%5+1)));
                        icone[l1][0]->setType(getType_((rand()%5+1)));
                        icone[l1+1][0]->setType(getType_((rand()%5+1)));
                        icone[l1-2][0]->setType(getType_((rand()%5+1)));
                        icone[l1-1][0]->tracer();
                        icone[l1][0]->tracer();
                        icone[l1+1][0]->tracer();
                        icone[l1-2][0]->tracer();
                        std::cout<<"19"<<std::endl;
                        score+=400;
                    }
                    else if(icone[l1][c1]->getType()==icone[l1+1][c1]->getType()  &&icone[l1][c1]->getType()==icone[l1-1][c1]->getType()){
                        for(int k=c1;k>0;k--){
                        icone[l1][k]->setType(icone[l1][k-1]->getType());
                        icone[l1-1][k]->setType(icone[l1-1][k-1]->getType());
                        icone[l1+1][k]->setType(icone[l1+1][k-1]->getType());

                        icone[l1][k]->tracer();
                        icone[l1-1][k]->tracer();
                        icone[l1+1][k]->tracer();
                        }
                        icone[l1-1][0]->setType(getType_((rand()%5+1)));
                        icone[l1][0]->setType(getType_((rand()%5+1)));
                        icone[l1+1][0]->setType(getType_((rand()%5+1)));
                        icone[l1-1][0]->tracer();
                        icone[l1][0]->tracer();
                        icone[l1+1][0]->tracer();
                        std::cout<<"20"<<std::endl;
                        score+=300;
                    }
                    else if(c1>1 && icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType()){
                        int l=3;

                        for(int k=c1;k>0;k--){
                            if(c1-l>=0){
                                icone[l1][k]->setType(icone[l1][c1-l]->getType());
                                icone[l1][k]->tracer();
                                l++;
                            }
                            else{
                                icone[l1][k]->setType(getType_(rand()%5+1));
                                icone[l1][k]->tracer();
                            }
                    }
                        score+=300;

                    }
                    else if(c1<8 && icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType()){
                        int l=1;

                        for(int k=c1+2;k>0;k--){
                            if(c1-l>=0){
                                icone[l1][k]->setType(icone[l1][c1-l]->getType());
                                icone[l1][k]->tracer();
                                l++;
                            }
                            else{
                                icone[l1][k]->setType(getType_(rand()%5+1));
                                icone[l1][k]->tracer();
                            }
                    }
                        score+=300;

                    }

                }

            }
            else{
                    if(c1>1 && c1<8){
                        if(icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType() && icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType()){
                            int l=3;

                            for(int k=c1+2;k>0;k--){
                                if(c1-l>=0){
                                    icone[l1][k]->setType(icone[l1][c1-l]->getType());
                                    icone[l1][k]->tracer();
                                    l++;
                                }
                                else{
                                    icone[l1][k]->setType(getType_(rand()%5+1));
                                    icone[l1][k]->tracer();
                                }
                            }
                            l=0;
                            icone[l1][0]->setType(getType_(rand()%5+1));
                            icone[l1][0]->tracer();
                            std::cout<<"21"<<std::endl;
                            score+=400;

                        }
                        else if(icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType() &&icone[l1][c1]->getType()==icone[l1][c1-1]->getType() ){
                            int l=2;

                            for(int k=c1+2;k>0;k--){
                                if(c1-l>=0){
                                    icone[l1][k]->setType(icone[l1][c1-l]->getType());
                                    icone[l1][k]->tracer();
                                    l++;
                                }
                                else{
                                    icone[l1][k]->setType(getType_(rand()%5+1));
                                    icone[l1][k]->tracer();
                                }
                            }
                            l=0;
                            icone[l1][0]->setType(getType_(rand()%5+1));
                            icone[l1][0]->tracer();
                            std::cout<<"22"<<std::endl;
                            score+=400;



                        }
                        else if(icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType() &&icone[l1][c1]->getType()==icone[l1][c1-1]->getType()){
                            int l=3;

                            for(int k=c1+1;k>0;k--){
                                if(c1-l>=0){
                                    icone[l1][k]->setType(icone[l1][c1-l]->getType());
                                    icone[l1][k]->tracer();
                                    l++;
                                }
                                else{
                                    icone[l1][k]->setType(getType_(rand()%5+1));
                                    icone[l1][k]->tracer();
                                }
                            }
                            l=0;
                            icone[l1][0]->setType(getType_(rand()%5+1));
                            icone[l1][0]->tracer();
                            std::cout<<"23"<<std::endl;
                            score+=400;
                        }
                        else if(icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-1]->getType() ){
                            int l=2;

                            for(int k=c1+1;k>0;k--){
                                if(c1-l>=0){
                                    icone[l1][k]->setType(icone[l1][c1-l]->getType());
                                    icone[l1][k]->tracer();
                                    l++;
                                }
                                else{
                                    icone[l1][k]->setType(getType_(rand()%5+1));
                                    icone[l1][k]->tracer();
                                }
                            }
                            l=0;
                            icone[l1][0]->setType(getType_(rand()%5+1));
                            icone[l1][0]->tracer();
                            std::cout<<"24"<<std::endl;
                            score+=300;
                        }

                        else if(icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType() ){
                            int l=1;

                            for(int k=c1+2;k>0;k--){
                                if(k-l>=0){
                                    icone[l1][k]->setType(icone[l1][c1-l]->getType());
                                    icone[l1][k]->tracer();
                                    l++;
                                }
                                else{
                                    icone[l1][k]->setType(getType_(rand()%5+1));
                                    icone[l1][k]->tracer();
                                }
                            }
                            l=0;
                            icone[l1][0]->setType(getType_(rand()%5+1));
                            icone[l1][0]->tracer();
                            std::cout<<"25"<<std::endl;
                            score+=300;
                           }
                        else if (icone[l1][c1]->getType()==icone[l1][c1-1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType() ) {
                            int l=3;

                            for(int k=c1;k>0;k--){
                                if(c1-l>=0){
                                    icone[l1][k]->setType(icone[l1][c1-l]->getType());
                                    icone[l1][k]->tracer();
                                    l++;
                                }
                                else{
                                    icone[l1][k]->setType(getType_(rand()%5+1));
                                    icone[l1][k]->tracer();
                                }
                            }
                            l=0;
                            icone[l1][0]->setType(getType_(rand()%5+1));
                            icone[l1][0]->tracer();
                            std::cout<<"26"<<std::endl;
                            score+=300;
                           }
                        else if(l1>1 && icone[l1][c1]->getType()==icone[l1-1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-2][c1]->getType()){
                            for(int k=c1;k>0;k--){
                            icone[l1][k]->setType(icone[l1][k-1]->getType());
                            icone[l1-1][k]->setType(icone[l1-1][k-1]->getType());
                            icone[l1-2][k]->setType(icone[l1-2][k-1]->getType());

                            icone[l1][k]->tracer();
                            icone[l1-1][k]->tracer();
                            icone[l1-2][k]->tracer();
                            }
                            icone[l1-1][0]->setType(getType_((rand()%5+1)));
                            icone[l1][0]->setType(getType_((rand()%5+1)));
                            icone[l1-2][0]->setType(getType_((rand()%5+1)));
                            icone[l1-1][0]->tracer();
                            icone[l1][0]->tracer();
                            icone[l1-2][0]->tracer();
                            std::cout<<"261"<<std::endl;
                            score+=300;
                        }
                        else if(l1<8 && icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType()){
                            for(int k=c1;k>0;k--){
                            icone[l1][k]->setType(icone[l1][k-1]->getType());
                            icone[l1+1][k]->setType(icone[l1+1][k-1]->getType());
                            icone[l1+2][k]->setType(icone[l1+2][k-1]->getType());

                            icone[l1][k]->tracer();
                            icone[l1+1][k]->tracer();
                            icone[l1+2][k]->tracer();
                            }
                            icone[l1+1][0]->setType(getType_((rand()%5+1)));
                            icone[l1][0]->setType(getType_((rand()%5+1)));
                            icone[l1+2][0]->setType(getType_((rand()%5+1)));
                            icone[l1+1][0]->tracer();
                            icone[l1][0]->tracer();
                            icone[l1+2][0]->tracer();
                            std::cout<<"262"<<std::endl;
                            score+=300;
                        }
                        }

                    else if(c1==1){
                        if(icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1+2]->getType() &&icone[l1][c1]->getType()==icone[l1][c1-1]->getType()){
                            icone[l1][c1]->setType(getType_(rand()%5+1));
                            icone[l1][c1-1]->setType(getType_(rand()%5+1));
                            icone[l1][c1+1]->setType(getType_(rand()%5+1));
                            icone[l1][c1+2]->setType(getType_(rand()%5+1));
                            icone[l1][c1]->tracer();
                            icone[l1][c1-1]->tracer();
                            icone[l1][c1+1]->tracer();
                            icone[l1][c1+2]->tracer();
                            std::cout<<"27"<<std::endl;
                            score+=400;

                        }
                        else if(icone[l1][c1]->getType()==icone[l1][c1+1]->getType()  &&icone[l1][c1]->getType()==icone[l1][c1-1]->getType()){
                            icone[l1][c1]->setType(getType_(rand()%5+1));
                            icone[l1][c1-1]->setType(getType_(rand()%5+1));
                            icone[l1][c1+1]->setType(getType_(rand()%5+1));

                            icone[l1][c1]->tracer();
                            icone[l1][c1-1]->tracer();
                            icone[l1][c1+1]->tracer();
                            std::cout<<"28"<<std::endl;
                            score+=300;

                        }
                        else if(icone[l1][c1]->getType()==icone[l1][c1+1]->getType()  &&icone[l1][c1]->getType()==icone[l1][c1+2]->getType()){
                            icone[l1][c1]->setType(getType_(rand()%5+1));
                            icone[l1][c1+1]->setType(getType_(rand()%5+1));
                            icone[l1][c1+2]->setType(icone[l1][0]->getType());
                            icone[l1][0]->setType(getType_(rand()%5+1));

                            icone[l1][c1]->tracer();
                            icone[l1][c1+1]->tracer();
                            icone[l1][c1+2]->tracer();
                            icone[l1][0]->tracer();


                            std::cout<<"281"<<std::endl;
                            score+=300;

                        }
                        else if(l1<8 && icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType()){
                            icone[l1][c1]->setType(icone[l1][0]->getType());
                            icone[l1+2][c1]->setType(icone[l1+2][0]->getType());
                            icone[l1+1][c1]->setType(icone[l1+1][0]->getType());

                            icone[l1][c1]->tracer();
                            icone[l1+1][c1]->tracer();
                            icone[l1+2][c1]->tracer();

                            icone[l1][0]->setType(getType_(rand()%5+1));
                            icone[l1+2][0]->setType(getType_(rand()%5+1));
                            icone[l1+1][0]->setType(getType_(rand()%5+1));

                            icone[l1][0]->tracer();
                            icone[l1+1][0]->tracer();
                            icone[l1+2][0]->tracer();
                            std::cout<<"282"<<std::endl;
                            score+=300;

                        }
                        else if(l1>1 && icone[l1][c1]->getType()==icone[l1-1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-2][c1]->getType()){
                            icone[l1][c1]->setType(icone[l1][0]->getType());
                            icone[l1-2][c1]->setType(icone[l1-2][0]->getType());
                            icone[l1-1][c1]->setType(icone[l1-1][0]->getType());

                            icone[l1][c1]->tracer();
                            icone[l1-1][c1]->tracer();
                            icone[l1-2][c1]->tracer();

                            icone[l1][0]->setType(getType_(rand()%5+1));
                            icone[l1-2][0]->setType(getType_(rand()%5+1));
                            icone[l1-1][0]->setType(getType_(rand()%5+1));

                            icone[l1][0]->tracer();
                            icone[l1-1][0]->tracer();
                            icone[l1-2][0]->tracer();
                            std::cout<<"283"<<std::endl;
                            score+=300;
                        }

                    }
                else if (c1==8) {
                    if(icone[l1][c1]->getType()==icone[l1][c1+1]->getType() && icone[l1][c1]->getType()==icone[l1][c1-2]->getType() &&icone[l1][c1]->getType()==icone[l1][c1-1]->getType()){

                        icone[l1][c1]->setType(icone[l1][c1]->getType());
                        icone[l1][c1-1]->setType(icone[l1][c1-4]->getType());
                        icone[l1][c1+1]->setType(icone[l1][c1-3]->getType());
                        icone[l1][c1-2]->setType(icone[l1][c1-5]->getType());
                        icone[l1][c1]->tracer();
                        icone[l1][c1-1]->tracer();
                        icone[l1][c1+1]->tracer();
                        icone[l1][c1-2]->tracer();
                        for(int k=5;k>=0;k++){
                            icone[l1][k]->setType(getType_(rand()%5+1));
                            icone[l1][k]->tracer();
                        }
                        std::cout<<"29"<<std::endl;
                        score+=400;

                    }
                    else if(icone[l1][c1]->getType()==icone[l1][c1+1]->getType()  && icone[l1][c1]->getType()==icone[l1][c1-1]->getType()){
                        std::cout<<"yeah"<<std::endl;
                        icone[l1][c1]->setType(icone[l1][c1-3]->getType());
                        icone[l1][c1-1]->setType(icone[l1][c1-4]->getType());
                        icone[l1][c1+1]->setType(icone[l1][c1-2]->getType());

                        icone[l1][c1]->tracer();
                        icone[l1][c1-1]->tracer();
                        icone[l1][c1+1]->tracer();
                        for(int k=5;k>=0;k--){
                            icone[l1][k]->setType(getType_(rand()%5+1));
                            icone[l1][k]->tracer();
                        }
                        std::cout<<"30"<<std::endl;
                        score+=300;
                    }
                    else if(icone[l1][c1]->getType()==icone[l1][c1-1]->getType()  &&icone[l1][c1]->getType()==icone[l1][c1-2]->getType()){

                        int l=3;

                        for(int k=c1;k>0;k--){
                            if(c1-l>=0){
                                icone[l1][k]->setType(icone[l1][c1-l]->getType());
                                icone[l1][k]->tracer();
                                l++;
                            }
                            else{
                                icone[l1][k]->setType(getType_(rand()%5+1));
                                icone[l1][k]->tracer();
                            }
                        }
                        l=0;
                        icone[l1][0]->setType(getType_(rand()%5+1));
                        icone[l1][0]->tracer();
                        std::cout<<"301"<<std::endl;
                        score+=300;

                    }
                    else if(l1>1 && icone[l1][c1]->getType()==icone[l1-1][c1]->getType() && icone[l1][c1]->getType()==icone[l1-2][c1]->getType()){
                        for(int k=c1;k>0;k--){
                        icone[l1][k]->setType(icone[l1][k-1]->getType());
                        icone[l1-1][k]->setType(icone[l1-1][k-1]->getType());
                        icone[l1-2][k]->setType(icone[l1-2][k-1]->getType());

                        icone[l1][k]->tracer();
                        icone[l1-1][k]->tracer();
                        icone[l1-2][k]->tracer();
                        }
                        icone[l1-1][0]->setType(getType_((rand()%5+1)));
                        icone[l1][0]->setType(getType_((rand()%5+1)));
                        icone[l1-2][0]->setType(getType_((rand()%5+1)));
                        icone[l1-1][0]->tracer();
                        icone[l1][0]->tracer();
                        icone[l1-2][0]->tracer();
                        score+=300;
                    }
                    else if(l1<8 && icone[l1][c1]->getType()==icone[l1+1][c1]->getType() && icone[l1][c1]->getType()==icone[l1+2][c1]->getType()){
                        for(int k=c1;k>0;k--){
                        icone[l1][k]->setType(icone[l1][k-1]->getType());
                        icone[l1+1][k]->setType(icone[l1+1][k-1]->getType());
                        icone[l1+2][k]->setType(icone[l1+2][k-1]->getType());

                        icone[l1][k]->tracer();
                        icone[l1+1][k]->tracer();
                        icone[l1+2][k]->tracer();
                        }
                        icone[l1-1][0]->setType(getType_((rand()%5+1)));
                        icone[l1][0]->setType(getType_((rand()%5+1)));
                        icone[l1+2][0]->setType(getType_((rand()%5+1)));
                        icone[l1+1][0]->tracer();
                        icone[l1][0]->tracer();
                        icone[l1+2][0]->tracer();
                        score+=300;
                    }


                }
            }
        }
    }




    void jouer::detecter_colonne(){
          for(int i=0;i<10;i++){
                  for(int j=0;j<7;j++)
                  {
                      if(icone[i][j]->getType()==icone[i][j+1]->getType() && icone[i][j]->getType()==icone[i][j+2]->getType()){
                          if(icone[i][j]->getType()==icone[i][j+3]->getType()){

                               eliminer_col(j+3,i,4);
                               score1 = score1 + 400;
                          }
                          else{
                              eliminer_col(j+2,i,3);
                              score1 = score1 + 300;

                          }
                      }
                  }
          }
          for(int i=0;i<10;i++)
          {
              if(icone[i][7]->getType()==icone[i][8]->getType() && icone[i][7]->getType()==icone[i][9]->getType()){

                       eliminer_col(9,i,3);
                       score1 = score1 + 300;

                  }
              }

      }


       void jouer::detecter_ligne(){

           for(int j=0;j<10;j++){
                   for(int i=0;i<7;i++)
                   {
                       if(icone[i][j]->getType()==icone[i+1][j]->getType() && icone[i][j]->getType()==icone[i+2][j]->getType()){
                           if(icone[i][j]->getType()==icone[i+3][j]->getType()){
                                eliminer_ligne(j,i+3,4);
                                score2 = score2 + 400;

                           }
                           else{
                               eliminer_ligne(j,i+2,3);
                               score2 = score2 + 300;
                           }
                       }
                   }

           }
           for(int j=0;j<10;j++)
           {
               if(icone[7][j]->getType()==icone[8][j]->getType() && icone[7][j]->getType()==icone[9][j]->getType()){

                        eliminer_ligne(j,9,3);
                        score2 = score2 + 300;

                   }
               }

      }





       void jouer::eliminer_ligne(int ligne, int colonne, int pas){
           int cst=pas;
           int constante=ligne;
           if (ligne==0){
               while(pas != 0){
                   icone[colonne][0]->setType(getType_(rand()%5+1));
                   icone[colonne][0]->tracer();
                   colonne--;
                   pas--;
               }
           }
           else {
               while(cst !=0){
                   ligne=constante;
                   while(ligne > 0){
                           icone[colonne][ligne]->setType(icone[colonne][ligne-1]->getType());
                           icone[colonne][ligne]->tracer();
                           ligne--;
                   }
                   icone[colonne][0]->setType(getType_(rand()%5+1));
                   icone[colonne][0]->tracer();
                   colonne--;
                   cst--;
               }
           }


       }



       void jouer::eliminer_col(int ligne, int colonne, int pas){
           int cst=pas;
           while(ligne > 0){
               if(ligne-cst > 0){
                   icone[colonne][ligne]->setType(icone[colonne][ligne-cst]->getType());
                   icone[colonne][ligne]->tracer();
               }
               else if(ligne-cst == 0){
                   icone[colonne][ligne]->setType(icone[colonne][0]->getType());
                   icone[colonne][ligne]->tracer();
               }
               else if(ligne-cst < 0){
                   icone[colonne][ligne]->setType(getType_(rand()%5+1));
                   icone[colonne][ligne]->tracer();
               }
               ligne--;
               //pas--;
           }
           icone[colonne][0]->setType(getType_(rand()%5+1));
           icone[colonne][0]->tracer();





       }



    int jouer::Check(){
        int c=table[0][0]->getligne();
        return c;

    }
