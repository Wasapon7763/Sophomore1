#include <stdio.h>
#include <stdlib.h>
int N, *count; //N:盤面のサイズ c:配置した馬の数を置くことが出来る盤面の数
//gridとvisitedを初期設定する関数
void init(int **grid, int **visited){
  int i, j;
  count=(int*)malloc(sizeof(int*)*N*N); //countのメモリを確保
  for (i=0;i<N*N;i++) count[i]=0; //count[]のメモリを確保
  for (i=0;i<N;i++){
    for (j=0;j<N;j++){
      grid[i][j]=0; //gridを0で初期化
      visited[i][j]=0; //visitedを0で初期化
    }
  }
}
//gridのx行y列目に馬を置いた時に埋まるマスを埋める
void horse(int x, int y, int **grid){
  int i=1, changed=0; //changed:盤面に変化があったら1,なかったら0
  grid[x][y]=2; //馬を置いた場所に2を代入
  //馬の斜め一マスに１を代入
  if (x<N-1) grid[x+1][y]=1;
  if (y<N-1) grid[x][y+1]=1;
  if (x>0) grid[x-1][y]=1;
  if (y>0) grid[x][y-1]=1;
  //馬の上下左右直線方向に１を代入
  while (1){
    changed=0;
    if (x+i<N&&y+i<N){ grid[x+i][y+i]=1; changed=1; }
    if (x-i>-1&&y-i>-1){ grid[x-i][y-i]=1; changed=1;}
    if (x+i<N&&y-i>-1){ grid[x+i][y-i]=1; changed=1; }
    if (x-i>-1&&y+i<N){ grid[x-i][y+i]=1; changed=1; }
    if (!changed) break;
    i++;
  }
}
//馬の個数を数え、countに記録
void getcount(int **grid){
  int i, j, c=0;
  for (i=0;i<N;i++){
    for (j=0;j<N;j++){
      if (grid[i][j]==2) c++;
    }
  }
  count[c]++;
}
//盤面を埋める関数
void fillgrid(int x, int y, int **grid, int **visited){
  int i, j;
  //nextgrid:新たに馬を置いた時の盤面 next:次に置くことが出来るマス目 newvisited:新たに馬を置いた時の訪れたマス目 done:探索が終わったら1、そうでなかったら0
  int **nextgrid, **next, **newvisited, done=1; 
  //newvisited, nextgrid, nextのメモリを確保
  newvisited=(int**)malloc(sizeof(int*)*N);
  nextgrid=(int**)malloc(sizeof(int*)*N);
  next=(int**)malloc(sizeof(int*)*N);
  for (i=0;i<N;i++){
    //newvisited[], nextgrid[], next[]のメモリを確保
    newvisited[i]=(int*)malloc(sizeof(int)*N);
    nextgrid[i]=(int*)malloc(sizeof(int)*N);
    next[i]=(int*)malloc(sizeof(int)*N);
    for (j=0;j<N;j++){
      newvisited[i][j]=visited[i][j]; //newvisitedにvisitedをコピー
      nextgrid[i][j]=grid[i][j]; //nextgridにgridをコピー
      next[i][j]=0; //nextを0で初期化
    }
  }
  if (x!=-1&&y!=-1){ //最初の呼び出しでなかったら
    horse(x, y, nextgrid); //馬を置く
    visited[x][y]=1; //訪れたことを記録
  }
  for (i=0;i<N;i++){
    for (j=0;j<N;j++){
      if (nextgrid[i][j]==0){ //まだ埋まっていなかったら
        next[i][j]=1; //next[i][j]に候補として1を代入
        done=0; //doneに0を代入
      }
    }
  }
  if (done){ //終わった時
    getcount(nextgrid); //getcountを呼び出す 
    return ;
  }
  for (i=0;i<N;i++){
    for (j=0;j<N;j++){
      if (next[i][j]&&newvisited[i][j]==0) fillgrid(i, j, nextgrid, newvisited); //次の候補であり、訪れていなかったらfillgridを呼び出し
    }
  }
  return ;
}
int main(void){
  int i, j;
  int **grid, **visited, max=0; //grid:盤面 visited:盤面に訪れたかどうかを記録 max:最も多く配置できる馬の個数
  scanf("%d", &N); //Nを入力
  grid=(int**)malloc(sizeof(int*)*N); //gridのメモリを確保
  visited=(int**)malloc(sizeof(int*)*N); //visitedのメモリを確保
  for (i=0;i<N;i++) grid[i]=(int*)malloc(sizeof(int)*N); //grid[]のメモリを確保
  for (i=0;i<N;i++) visited[i]=(int*)malloc(sizeof(int)*N); //visited[]のメモリを確保
  init(grid, visited); //gridとvisitedの初期設定
  fillgrid(-1, -1, grid, visited); //盤面を埋める
  for (i=0;i<N*N;i++){
    if (count[i]!=0&&i>max) max=i; //count[i]が0でなくiがmaxより大きかったらmaxにiを格納
  }
  printf("%d %d\n", max, count[max]); //配置できる最大個数とその最大個数における配置の通り数を出力
  return 0;
}
