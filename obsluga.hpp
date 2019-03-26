#ifndef obsluga_hpp
#define obsluga_hpp
void CheckState(int mapa[][30],int mapaD[][30],int w,int h);
void RandMapBomb(int mapa[][30],int w,int h,int x, int y,int NoumberOfBombs);
int CountNearbyBombs(int mapa[][30],int i,int j);
void ChangeVisible(int mapa[][30],int mapaD[][30],int x, int y,int *FClosed);
bool CheckMine(int mapa[][30],int mapaD[][30],int x, int y);
void MakeFlag(int mapaD[][30],int x, int y,int *Bombs);
bool CheckVictory(int *FClosed,int Bombs);
void MakeZero(int mapa[][30],int mapaD[][30]);
void InitLose(int mapa[][30],int mapaD[][30],int w, int h);
void SaveGameState(int mapa[][30],int mapaD[][30],int w, int h, int b);
void DisplayVictory(int mapa[][30],int mapaD[][30],int w,int h);
#endif



