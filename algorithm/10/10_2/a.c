#include <stdio.h>
#include <stdlib.h>
int N, c=0; //N:入力されるマス目の大きさ c:可能な配置の総数
//gridのx行y列目に竜をおいた時、竜が届く範囲を埋める関数
void dragon(int x, int y, int **grid){
  int i=1, changed=0; //changed:gridに変化があったら1,なかったら0
  grid[x][y]=2; //竜をおいた位置に2を代入
  //竜の一つ上、下、左、右に1を代入
  if (x+1<N&&y+1<N) grid[x+1][y+1]=1;
  if (x-1>-1&&y-1>-1) grid[x-1][y-1]=1;
  if (x+1<N&&y-1>-1) grid[x+1][y-1]=1;
  if (x-1>-1&&y+1<N) grid[x-1][y+1]=1;
  //竜の斜め方向に1を代入
  while (1){
    changed=0;
    if (x+i<=N-1){ grid[x+i][y]=1; changed=1; }
    if (y+i<=N-1){ grid[x][y+i]=1; changed=1; }
    if (x-i>=0){ grid[x-i][y]=1; changed=1; }
    if (y-i>=0){ grid[x][y-i]=1; changed=1; }
    if (!changed) break;
    i++;
  }
}
//aにbをコピー
void cpyary(int **a, int **b){
  int i, j;
  for (i=0;i<N;i++){
    for (j=0;j<N;j++) a[i][j]=b[i][j];
  }
}
//竜がNこ置けていたら1、置けていなかったら0を返す関数
int check(int **grid){
  int i, j, nc=0; //nc:竜の個数
  for (i=0;i<N;i++){
    for (j=0;j<N;j++) if (grid[i][j]==2) nc++; //竜を見つけた時,ncをインクレメント
  }
  if (nc==N) return 1;
  else return 0;
}
//竜を埋めていく関数
void fillgrid(int n, int **grid){
  int i, j, **nextgrid; //nextgrid:新たに竜を置いた新しい盤面
  if (n>=N) return; //nがN以上であったら戻る
  nextgrid=(int**)malloc(sizeof(int*)*N); //nextgridのメモリを確保
  for (i=0;i<N;i++) nextgrid[i]=(int*)malloc(sizeof(int)*N); //nextgrid[]のメモリを確保
  cpyary(nextgrid, grid); //nextgridにgridをコピー
  for (j=0;j<N;j++){
    if (n==0&&j>=N/2&&N%2==0) break; //n=0かつNが偶数かつｊがNの半分以上であったらbreak
    if (grid[n][j]==0){ //grid[n][j]が埋まっていなかったら
      dragon(n, j, nextgrid); //竜を置く
      if (check(nextgrid)){ //nextgridが全て埋まっていたら
        if (N%2==0) c+=2; //Nが偶数の時cに2を足す
        else c++; //Nが偶数でない時cをインクレメント
      }
      fillgrid(n+1, nextgrid); //fillgridを呼び出す
      cpyary(nextgrid, grid); //nextgridを元に戻す
    }
  }
}
int main(void){
  int i, j, u, v;
  int **grid; //盤面
  scanf("%d", &N); //Nを入力
  grid=(int**)malloc(sizeof(int*)*N); //gridのメモリを確保
  for (i=0;i<N;i++){
    grid[i]=(int*)malloc(sizeof(int)*N); //grid[]のメモリを日k歩
    for (j=0;j<N;j++) grid[i][j]=0; //girdを0で初期化
  }
  fillgrid(0, grid); //盤面を埋める
  printf("%d\n", c); //配置の総数を出力
  return 0;
}
