#include <allegro.h>
#include "obsluga.hpp"
#include "grafika.hpp"

void CheckState(int mapa[][30],int mapaD[][30],int w,int h){
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
            DisplaySquare(j,i,mapa[j][i],mapaD[j][i]);
      }
    }

}

void RandMapBomb(int mapa[][30],int w,int h,int x, int y,int NoumberOfBombs){

        for(int i=x-1;i<=x+1;i++)
        for(int j=y-1;j<=y+1;j++)
            if(i>=0&&j>=0&&i<30&&j<30)
                mapa[i][j]=1;



    srand( time( NULL ) );

    while (NoumberOfBombs>0){
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++){
        if(mapa[i][j]==0&&NoumberOfBombs>0){
            if(rand()<RAND_MAX/16){
                mapa[i][j]= 2;
                NoumberOfBombs--;
            }
        }
        }
    }
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++){
            if(mapa[i][j]==0)
                mapa[i][j]= 1;
        }
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++){
            if(mapa[i][j]==1)
               mapa[i][j]=mapa[i][j]+9+ CountNearbyBombs(mapa,i,j);
        }

}

int CountNearbyBombs(int mapa[][30],int i,int j){
    int Bombs=0;
    for(int h=i-1;h<=i+1;h++)
        for(int k=j-1;k<=j+1;k++){
            if(h==i&&k==j)continue;
            else if(h>=0&&k>=0&&h<30&&k<30)
                    if(mapa[h][k]==2) Bombs++;

    }
    return Bombs;

}

void ChangeVisible(int mapa[][30],int mapaD[][30],int x, int y,int *FClosed){
    if(mapa[x][y]>10) {
            if(mapaD[x][y]==0)
                *FClosed = *FClosed -1;
            mapaD[x][y]=1;

    }
    else if(mapa[x][y]==10) {
        if(mapaD[x][y]==0)
            *FClosed = *FClosed -1;
        mapaD[x][y]=1;
        for(int h=x-1;h<=x+1;h++)
        for(int k=y-1;k<=y+1;k++){
            if(h==x&&k==y)continue;
            else if(h>=0&&k>=0&&h<30&&k<30){
                    if(mapaD[h][k]==0){
                        ChangeVisible(mapa,mapaD,h,k,FClosed);
                    }
            }
        }
    }


}

bool CheckMine(int mapa[][30],int mapaD[][30], int x, int y){
        if(mapa[x][y] == 2) {
                mapa[x][y]=4;
                mapaD[x][y]=1;
            for(int i=0;i<30;i++){
                for(int j=0;j<30;j++)
                    if(mapa[i][j]==2) mapaD[i][j]=1;
            }

              return 1;
        }
        return 0;

}

void MakeFlag(int mapaD[][30], int x, int y,int *Bombs){
    if(mapaD[x][y]==0) {
            mapaD[x][y]=2;
            *Bombs = *Bombs -1;
    }
    else if(mapaD[x][y]==2) {
            mapaD[x][y]=0;
            *Bombs = *Bombs +1;
    }

}

bool CheckVictory(int *FClosed,int Bombs){
    if (*FClosed == 0) {
        return 1;
    }
    return 0;
}


void MakeZero(int mapa[][30],int mapaD[][30]){
    for(int i=0;i<30;i++)
        for(int j=0;j<30;j++){
            mapa[i][j]=0;
            mapaD[i][j]=0;
        }
}

void InitLose(int mapa[][30],int mapaD[][30],int w, int h){
     for(int i=0;i<30;i++){
        for(int j=0;j<30;j++)
            if(mapa[j][i]==2) {
                for(int k=0;k<5;k++){
                        CheckState( mapa,mapaD,w,h);
                        DisplayLose(j,i,k);
                        DisplayBufor();
                        ResetBufor();
                        rest(50);
                         if(mouse_b==2) break;
                        }
                    mapa[j][i]=5;
                    if(mouse_b==2) break;
                    }
                else if(mapa[j][i]==4){
                     for(int k=0;k<5;k++){
                        CheckState( mapa,mapaD,w,h);
                        DisplayLose(j,i,k);
                        DisplayBufor();
                        ResetBufor();
                        rest(50);
                         if(mouse_b==2) break;
                        }
                        mapa[j][i]=6;
                    if(mouse_b==2) break;


                }
                   if(mouse_b==2) break;
            }


}

void DisplayVictory(int mapa[][30],int mapaD[][30],int w,int h){
    mapaD[30][30]={1};
    CheckState(mapa,mapaD,w,h);
    DisplayVictoryInfo();
    DisplayBufor();
    rest(550);
    while (mouse_b==0){
       continue;
    }


}

//void SaveGameState(int mapa[][30],int mapaD[][30],int w, int h, int b){

