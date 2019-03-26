
#ifndef grafika_hpp
#define grafika_hpp
void InitBufor();
void InitSquare();
void DisplayBufor();
void DisplaySquare(int w,int h, int state,int Visible);
void ResetBufor();
void DisplRemainingBombs(int *Bombs);
void DisplayMenu();
void DisplRemainingTime(int Time,int mins);
void DisplayMenu1();
void DisplayMenu2();
void DisplayMenu3(int mapsize,int mapdific);
void DisplayAdditional(int w,int h,int b);
void DisplayScoreBoard(char* line,int i);
void DisplayLose(int w,int h,int i);
void DisplayVictoryInfo();
#endif



