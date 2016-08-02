#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX
int n, *dist, *visited, **cost; //n:節点の個数 dist:接点間の距離 visited:節点を訪れたら1、そうでなかったら0 cost:隣接した節点間のコスト
void init(){
  int i, j;
  int b, e, l; //b:始点の節点番号 e:終点の節点番号 l:枝の長さ
  dist=(int*)malloc(sizeof(int)*n); //distのメモリを確保
  for (i=0;i<n;i++) dist[i]=INF; //distをINFで初期化
  visited=(int*)malloc(sizeof(int)*n); //visitedのメモリを確保
  for (i=0;i<n;i++) visited[i]=0; //visitedを0で初期化
  cost=(int**)malloc(sizeof(int*)*n); //costのメモリを確保
  for (i=0;i<n;i++){
    cost[i]=(int*)malloc(sizeof(int)*n); //cost[]のメモリを確保
    for (j=0;j<n;j++){
      cost[i][j]=INF; //costをINFで初期化
    }
  }
  //costを入力
  while (scanf("%d %d %d\n", &b, &e, &l)!=EOF){
    cost[b][e]=l;
    cost[e][b]=l;
  }
}
//nodeに対する他の節点の距離を取得する関数
void getDist(int node){
  dist[node]=0; //自分自身との距離を0
  while (1){
    int i, next=-1, c=INF; //next:次に見る節点 c:0~nextの距離
    for (i=0;i<n;i++){
      //訪れていない節点の中でコストが最小の節点番号をnextに格納
      if (!visited[i]&&(next==-1||dist[i]<dist[next])) next=i;
    }
    if (next==-1) return; //nextが見つからなかったら戻る
    visited[next]=1; //next番目の節点を訪れた
    for (i=0;i<n;i++){
      if (cost[next][i]!=INF){ //nextに対するiのコストがINFでなかったら
        c=dist[next]+cost[next][i]; //cを計算
        if (dist[i]>=c) dist[i]=c; //cが今の距離より小さかったらdist[i]をcで更新
      }
    }
  }
}
int main(void){
  scanf("%d\n", &n); //節点の個数を入力
  init();
  getDist(0); //節点0からの距離を取得
  printf("%d\n", dist[1]); //0-1の距離を表示
  free(dist);
  free(visited);
  free(cost);
  return 0;
}
