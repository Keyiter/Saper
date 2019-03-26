#include <allegro.h>
#include <time.h>
#include "grafika.hpp"
#include "obsluga.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

const int W = 30;
const int H = 30;






inline void initSize(int W,int H){
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, W+20, H+40, 0, 0);
    show_mouse( screen );
}

inline void init()
{
	allegro_init();
	set_color_depth(32);
	initSize(300,300);

	install_timer();
	install_keyboard();
	install_mouse();
    show_mouse( screen );
    unscare_mouse();
    enable_hardware_cursor();
}






inline void deinit()
{
	clear_keybuf();
	allegro_exit();
}

int main()
{
    FILE *hs;
    FILE *save;
	init();
	int GameState=0;
    int width = 10;
    int height = 10;
    int mapa[W][H]={0};
    int mapaD[W][H]={0};
    int Bombs=40;
    int mins=0;
    int mapsize=0;
    int mapdific =0;
    int Played = 0;
    int BombsRem;
    int *BombsRema;
    BombsRema=&BombsRem;
    int FieldClosed = (width*height)-Bombs;
    char tekst[50];
    int *FClosed;
    int charsRead;
    FClosed = &FieldClosed;
    clock_t start , diff;
    int msec;

    int SetFocus=0;
    bool newgame=1;
    bool clickin=0;

    InitBufor();
    InitSquare();




	while (!key[KEY_ESC])
	{
	    if(GameState==0){
        if(clickin==0){
        if (mouse_x>40 &&mouse_x<280 &&mouse_y>165 &&mouse_y<222 && mouse_b==1)
            GameState=3;
        if (mouse_x>40 &&mouse_x<280 &&mouse_y>100 &&mouse_y<156 && mouse_b==1&&Played ==0){
            GameState=1;
            newgame=0;
            save=fopen("save.txt","rt");
            int i=-7;
            int j=0;
           while(!feof(save)){
                if (i==-7)
                    *BombsRema = atoi( fgets(tekst,5,save));
                else if(i==-6)
                    width = atoi( fgets(tekst,5,save));
                else if(i==-5)
                    height = atoi( fgets(tekst,5,save));
                else if(i==-4)
                    Bombs = atoi( fgets(tekst,5,save));
                else if(i==-3)
                    mins = atoi( fgets(tekst,5,save));
                else if(i==-2){
                    msec = atoi( fgets(tekst,5,save));
                }
                else if(i==-1){
                     int b = atoi( fgets(tekst,5,save));
                    *FClosed = b;
                }
                else if (i<30){

                    mapa[i][j] = atoi( fgets(tekst,5,save));
                    j++;
                    if (j==30){i++;j=0;}
                    if(i==30)j=0;

                }
                else {
                    mapaD[i-30][j] = atoi( fgets(tekst,5,save));
                    j++;
                    if (j==30){i++;j=0;}
                }
                 if(i<0) i++;
                 if(i==60) break;

                }
                 start = clock() - (msec*CLOCKS_PER_SEC);
                fclose(save);
                initSize(width*30,height*30);
                Played =1;
                }
                else if (mouse_x>10 &&mouse_x<310 &&mouse_y>80 &&mouse_y<140 && mouse_b==1&&Played ==1)  {
                        GameState=1;
                 initSize(width*30,height*30);
                 }






          if (mouse_x>40 &&mouse_x<280 &&mouse_y>230 &&mouse_y<287&& mouse_b==1 )
            GameState=2;



        clickin=1;
	    }
	    if (mouse_b==0)
            clickin=0;
         DisplayMenu1();


	    }
	    else if(GameState==2){
            if (mouse_x>10 &&mouse_x<310 &&mouse_y>0 &&mouse_y<50&& mouse_b==1 )
            GameState=0;
            hs=fopen("test.txt", "rt+");
            if( hs == NULL ) {
            allegro_message( "blad pliku" );

            return -1;
            }

            int i=320,j=0;;
            int ln=0;
            DisplayMenu2();

        if( hs!=NULL ){
            while(!feof(hs)){
             fgets(tekst,50,hs);
             ln ++;
            }
            ln=ln-25;
            rewind(hs);
            while(!feof(hs)&&i>80){

            fgets(tekst,500,hs);
            if(j>ln){
            i=i-10;
            DisplayScoreBoard(tekst,i);
            }
            j++;

            }
        }

        fclose(hs);





        }
        else if(GameState==3){
            if(clickin==0){

             if(mouse_x>10 && mouse_x <60 && mouse_y>45 && mouse_y<75 && mouse_b==1){
                if(mapsize>0) mapsize--;
                else mapsize = 2;

             }
             if(mouse_x>260 && mouse_x <310 && mouse_y>45 && mouse_y<75 && mouse_b==1){
                if(mapsize<2) mapsize++;
                else mapsize = 0;

             }
              if(mouse_x>10 && mouse_x <60 && mouse_y>105 && mouse_y<135 && mouse_b==1){
                if(mapdific>0) mapdific--;
                else mapdific = 7;

             }
             if(mouse_x>260 && mouse_x <310 && mouse_y>105 && mouse_y<135 && mouse_b==1){
                if(mapdific<7) mapdific++;
                else mapdific =0;

             }

             if(mouse_x>30 && mouse_x < 290 && mouse_y> 150 && mouse_y <180 &&mouse_b==1){
                GameState=1;
                width=(mapsize*10)+10;
                height=(mapsize*5)+10;
                Bombs=(mapdific*((width*height)*0.1)) +(0.1*(width*height));
                *FClosed=(width*height)-Bombs;
                *BombsRema = Bombs;
                initSize(width*30,height*30);
                MakeZero(mapa,mapaD);
                newgame = 1;
             }





             if (mouse_x>10 &&mouse_x<150 &&mouse_y>220 &&mouse_y<330 && mouse_b==1){
              if(Bombs<(width*height)-12){
                GameState=1;
                newgame = 1;
                *FClosed= (width*height)-Bombs;
                *BombsRema = Bombs;
                MakeZero(mapa,mapaD);
                initSize(width*30,height*30);



            }
}
            if(mouse_x>160 && mouse_x <320 && mouse_y > 310 && mouse_y <335 && mouse_b==1 ){
               GameState=0;
            }
            clickin=1;


            }


             if (mouse_x>245 &&mouse_x<290 &&mouse_y>209 &&mouse_y<235 && mouse_b==1){
               if(width<30) width++;
               rest(250);

            }
             if (mouse_x>196 &&mouse_x<245 &&mouse_y>209 &&mouse_y<235 && mouse_b==1){
                if(width>8) width--;
                rest(250);
            }
             if (mouse_x>245 &&mouse_x<290 &&mouse_y>241 &&mouse_y<268 && mouse_b==1){
                if(height<25)height++;
                rest(250);
            }
            if (mouse_x>196 &&mouse_x<245 &&mouse_y>241 &&mouse_y<268 && mouse_b==1){
                if(height>8) height--;
                rest(250);
            }
             if (mouse_x>245 &&mouse_x<290 &&mouse_y>275 &&mouse_y<301&& mouse_b==1){
                if(Bombs<(width*height)-12)Bombs++;
                rest(250);
            }
             if (mouse_x>196 &&mouse_x<245 &&mouse_y>275 &&mouse_y<301 && mouse_b==1){
                  if(Bombs>10) Bombs--;
                  rest(250);
            }

            while(Bombs>(width*height)-13) Bombs--;




            if (mouse_b==0)
            clickin=0;



            DisplayMenu3(mapsize,mapdific);
            DisplayAdditional(width,height,Bombs);

        }
	    else if(GameState==1){
        if(mouse_x<=80&&mouse_y<30&&mouse_b==1){
            GameState=0;
             initSize(10*30,10*30);
        }

        if(mouse_y>=30&&mouse_x>=10){
        if(newgame==1){

            if(clickin==0)
            if(mouse_b==1){

                RandMapBomb(mapa,width,height,(mouse_x-10)/30,(mouse_y-30)/30,Bombs);
                ChangeVisible(mapa,mapaD,(mouse_x-10)/30,(mouse_y-30)/30,FClosed);
                newgame=0;
                clickin==1;
                start = clock();
                mins=0;
                Played =1;
            }
        }
        if (clickin==0)
        if (mouse_b==1) {

            if(CheckMine(mapa,mapaD,(mouse_x-10)/30,(mouse_y-30)/30)){
                    Played = 2;
                    newgame=1;
                    GameState=0;
                    InitLose(mapa,mapaD,width,height);
                    initSize(300,300);

}
            ChangeVisible(mapa,mapaD,(mouse_x-10)/30,(mouse_y-30)/30,FClosed);
            if(CheckVictory(FClosed,Bombs)){
                Played = 2;
                initSize(300,300);
                hs=fopen("test.txt", "a+");
                if(mins>9) fprintf(hs,"%d : ",mins);
                else fprintf(hs,"0%d : ",mins);
                if(msec >9)fprintf(hs, "%d    %d        %d      %d \n",msec,width,height,Bombs);
                else fprintf(hs, "0%d    %d        %d      %d \n",msec,width,height,Bombs);
                DisplayVictory(mapa,mapaD,width,height);
                newgame=1;
                GameState=0;
            }
            clickin=1;
        }
        if (clickin==0)
        if (mouse_b==2){

            MakeFlag(mapaD,(mouse_x-10)/30,(mouse_y-30)/30,BombsRema);
            clickin=1;
        }
        }
        if (mouse_b==0)
            clickin=0;

	    CheckState(mapa,mapaD,width,height);
        diff = clock() - start;
        msec = diff  / CLOCKS_PER_SEC;
        if (newgame== 0)
            if (msec ==60) {
                start = clock();
                mins++;
            }

        DisplayMenu();
        if (newgame==0) DisplRemainingTime(msec,mins);
        DisplRemainingBombs(BombsRema);



	    }
        DisplayBufor();
        ResetBufor();
        rest(10);
	}
    if(GameState==1 && newgame==0) {//SaveGameState(mapa,mapaD,width,height,Bombs);
   save= fopen("save.txt","w+");

    fprintf(save,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n",*BombsRema,width,height,Bombs,mins,diff  / CLOCKS_PER_SEC,*FClosed);


    for(int i=0;i<30;i++){
       for(int j=0;j<30;j++){
        fprintf(save,"%d\n",mapa[i][j]);
       }
    }


    for(int i=0;i<30;i++){
       for(int j=0;j<30;j++){
        fprintf(save,"%d\n",mapaD[i][j]);
       }



    }
    fclose(save);


    }
	deinit();
	return 0;
}
END_OF_MAIN()
