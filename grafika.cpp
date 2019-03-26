#include <allegro.h>
#include "grafika.hpp"

    BITMAP * bufor = NULL;
    BITMAP * square1 = NULL;
    BITMAP * square2 = NULL;
    BITMAP * square3 = NULL;
    BITMAP * square3a = NULL;

    BITMAP * square4 = NULL;
    BITMAP * square5 = NULL;
    BITMAP * menu = NULL;
    BITMAP * menu1 = NULL;
    BITMAP * menu2 = NULL;
    BITMAP * menu3 = NULL;
    BITMAP * size1 = NULL;
    BITMAP * dific = NULL;
    BITMAP * Victor = NULL;


void InitBufor(){
    bufor = create_bitmap( 920, 940 );
    if( !bufor ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "Nie moge utworzyc bufora !" );
        allegro_exit();
    }
}

void InitSquare(){
    square1 = load_bmp( "square1.bmp", default_palette );
    if( !square1 ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "nie moge zaladowac obrazka square1 !" );
        allegro_exit();
    }
     square2 = load_bmp( "square2.bmp", default_palette );
    if( !square2 ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "nie moge zaladowac obrazka square2 !" );
        allegro_exit();
    }
     square3 = load_bmp( "square3.bmp", default_palette );
    if( !square3 ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "nie moge zaladowac obrazka square3 !" );
        allegro_exit();
    }
    square3a = load_bmp( "square3a.bmp", default_palette );
    if( !square3a ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "nie moge zaladowac obrazka square3a !" );
        allegro_exit();
    }
     square4 = load_bmp( "square4.bmp", default_palette );
    if( !square4 ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "nie moge zaladowac obrazka square4 !" );
        allegro_exit();
    }
     square5 = load_bmp( "square5.bmp", default_palette );
    if( !square5 ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "nie moge zaladowac obrazka square5 !" );
        allegro_exit();
    }
      menu = load_bmp( "menu.bmp", default_palette );
     if( !menu ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "nie moge zaladowac obrazka menu !" );
        allegro_exit();
    }
     menu1 = load_bmp( "menu1.bmp", default_palette );
    if( !menu1 ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "nie moge zaladowac obrazka menu1 !" );
        allegro_exit();
    }
     menu3 = load_bmp( "menu3.bmp", default_palette );
     if( !menu3 ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "nie moge zaladowac obrazka menu3 !" );
        allegro_exit();
    }
     menu2 = load_bmp( "menu2.bmp", default_palette );
    if( !menu2 ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "nie moge zaladowac obrazka menu3 !" );
        allegro_exit();
    }
     size1 = load_bmp( "size.bmp", default_palette );
    if( !size1 ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "nie moge zaladowac obrazka size !" );
        allegro_exit();
    }
     dific = load_bmp( "dific.bmp", default_palette );
    if( !dific ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "nie moge zaladowac obrazka dific !" );
        allegro_exit();
    }
     Victor = load_bmp( "vic.bmp", default_palette );
    if( !Victor ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "nie moge zaladowac obrazka vic !" );
        allegro_exit();
    }

}


void DisplaySquare(int w,int h, int state,int Visible){

    if (Visible==0) masked_blit( square1, bufor, 0, 0, (w*30)+10, (h*30)+30, square1->w, square1->h );
    else if(Visible==2) masked_blit( square5, bufor, 0, 0, (w*30)+10, (h*30)+30, square1->w, square1->h );
    else if(state==5) masked_blit( square3, bufor, 90, 0, (w*30)+10, (h*30)+30, square1->w, square1->h );
    else if(state==4) masked_blit( square3, bufor, 0, 0, (w*30)+10, (h*30)+30, square1->w, square1->h );
    else if(state==6) masked_blit( square3, bufor, 60, 0, (w*30)+10, (h*30)+30, square1->w, square1->h );
    else if(state==2) masked_blit( square3, bufor, 30, 0, (w*30)+10, (h*30)+30, square1->w, square1->h );
    else if(state>10) masked_blit( square4, bufor, (30*(state%10))-30, 0, (w*30)+10, (h*30)+30, 30, square1->h );
    else masked_blit( square2, bufor, 0, 0, (w*30)+10, (h*30)+30, square1->w, square1->h );



}



void DisplayMenu(){
    masked_blit( menu, bufor, 0, 0, 0, 0, menu->w, menu->h );


}

void DisplRemainingBombs(int *Bombs){
   textprintf_ex( bufor, font, 160, 13, makecol( 200, 200, 200 ), - 1, "Bomby: %d ", *Bombs );

}

void DisplRemainingTime(int Time,int mins){
   textprintf_ex( bufor, font, 100, 7, makecol( 200, 200, 200 ), - 1, "%d:%d ", mins, Time );

}

void DisplayAdditional(int w,int h,int b){
    textprintf_ex( bufor, font, 168, 220, makecol( 200, 200, 200 ), - 1, "%d ", w );
    textprintf_ex( bufor, font, 168, 252, makecol( 200, 200, 200 ), - 1, "%d ", h);
    textprintf_ex( bufor, font, 168, 285, makecol( 200, 200, 200 ), - 1, "%d ", b );

}
void DisplayMenu1(){
    masked_blit( menu1, bufor, 0, 0, 0, 0, menu1->w, menu1->h );

}

void DisplayMenu2(){
    masked_blit( menu2, bufor, 0, 0, 0, 0, menu2->w, menu2->h );

}

void DisplayScoreBoard(char* line,int i){
     textprintf_ex( bufor, font, 28, 65, makecol( 200, 200, 200 ), - 1, "Czas   Szerokosc  Wysokosc  miny " );
     textprintf_ex( bufor, font, 23, i, makecol( 200, 200, 200 ), - 1, "%s ", line  );


}

void DisplayMenu3(int mapsize,int mapdific){
    masked_blit( menu3, bufor, 0, 0, 0, 0, menu3->w, menu3->h );
    masked_blit( size1,bufor,0,30*mapsize,60,45,size1->w,30);
    masked_blit( dific,bufor,0,30*mapdific,60,105,size1->w,30);


}

void DisplayBufor(){
    blit( bufor, screen, 0, 0, 0, 0, 920, 940 );
}

void ResetBufor(){
    clear_to_color( bufor, makecol( 150, 150, 150 ) );
}

void DisplayLose(int w,int h,int i){

        masked_blit( square3a, bufor, (30*i), 0, (w*30)+10, (h*30)+30, 30, square1->h );

}

void DisplayVictoryInfo(){
 masked_blit( Victor, bufor, 0, 0, 0, 0, Victor->w, Victor->h );

}


