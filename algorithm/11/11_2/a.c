#include <stdio.h>
#define N 91
int m, n, max=0; //m, n:広場のサイズ max:移動できる区画数の最大値
int ice[N][N], adj[N][N]; //ice:凍った広場 adj:何個の氷に隣接しているかを記録する配列
//iceのu行v列から氷を割っていく関数 d:これまで割ってきた距離
void solve(int u, int v, int d, int ice[N][N]){
  int i, j, icenow[N][N]; //icenow:新たに氷を割った時の広場
  for (i=0;i<n;i++){
    for (j=0;j<m;j++) icenow[i][j]=ice[i][j]; //icenowにiceをコピー
  }
  icenow[u][v]=0; //今いる位置の氷を割る
  d++; //dをインクレメント
  if (d>max) max=d; //dがmaxより上の時、最大区画数を更新
  if (ice[u+1][v]==1&&u+1<n) solve(u+1, v, d, icenow); //下に氷があるとき、solveを呼び出す
  if (ice[u][v+1]==1&&v+1<m) solve(u, v+1, d, icenow); //右に氷があるとき、solveを呼び出す
  if (ice[u-1][v]==1&&u-1>-1) solve(u-1, v, d, icenow); //上に氷があるとき、solveを呼び出す
  if (ice[u][v-1]==1&&v-1>-1) solve(u, v-1, d, icenow); //左に氷があるとき、solveを呼び出す
}
int main(void){
  int i, j;
  scanf("%d", &m); //mを入力
  scanf("%d", &n); //nを入力
  for (i=0;i<n;i++){
    for (j=0;j<m&&scanf("%d", &ice[i][j]);j++) adj[i][j]=0; //iceを入力し、adjを0で初期化
  }
  //隣接している氷を記録する
  for (i=0;i<n;i++){
    for (j=0;j<m;j++){
      if (ice[i+1][j]==1&&i+1<n) adj[i][j]++; //下
      if (ice[i][j+1]==1&&j+1<m) adj[i][j]++; //右
      if (ice[i-1][j]==1&&i-1>-1) adj[i][j]++; //上
      if (ice[i][j-1]==1&&j-1>-1) adj[i][j]++; //左
    }
  }
  for (i=0;i<n;i++){
    for (j=0;j<m;j++){
      if (ice[i][j]==1&&adj[i][j]==1) solve(i, j, 0, ice); //(i,j)に氷があるかつ隣接している氷が一つのみの時,solveを呼び出す
    }
  }
  printf("%d\n", max); //maxを出力
  return 0;
}
