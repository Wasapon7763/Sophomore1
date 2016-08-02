#include <stdio.h>
#include <limits.h>
#define INF INT_MAX
#define MAXN 801
int N, tot, leaf, max; //N:島の数 tot:橋をわたる時間（コスト）の合計 leaf:葉であるノードのコストの合計 max:直線に並んでいる橋のコストの最大
int cost[MAXN][MAXN], num[MAXN], visited[MAXN]; //cost:橋をわたる、壊す時間 num:橋の数 visited:探索時に島を訪れたか記録
//初期入力を行う
void init(){
  int i, j;
  int temp[MAXN];
  tot=leaf=max=0; //tot, leaf, maxを0で初期化
  for (i=1;i<=N;i++){
    num[i]=0; //numを0で初期化
    visited[i]=0; //visitedを0で初期化
    for (j=1;j<=N;j++) cost[i][j]=INF; //costをINFで初期化
  }
  for (i=2;i<=N;i++) scanf("%d", &temp[i]); //tempにi番目の島がどの島に橋をかけているかtempに格納
  for (i=2;i<=N;i++){
    scanf("%d", &cost[i][temp[i]]);  //i番目の島からtemp[i]にかかっている橋のコストをcostに格納
    cost[temp[i]][i]=cost[i][temp[i]];
    num[temp[i]]++; //temp[i]番目の島の橋の数をインクレメント
    num[i]++; //i番目の島の橋の数をインクレメント
  }
  //木において葉がない状態をつくる
  for (i=1;i<=N;i++){
    if (num[i]==1){ //橋の数が一つの場合
      for (j=1;j<=N;j++){
        if (cost[i][j]!=INF){ //costがINFでない橋のペアを見つける
          leaf+=cost[i][j]; //leafにcostを足す
          cost[i][j]=cost[j][i]=INF; //costにINFを代入
          break;
        }
      }
    }
  }
  //葉がない木における橋のコストの合計を計算
  for (i=1;i<=N;i++){
    for (j=i+1;j<=N;j++){
      if (cost[i][j]!=INF) tot+=cost[i][j]; 
    }
  }
}
void getDist(int node1, int node2, int dist){
  int i, d=dist; //d:ひとつ前のノードまでの距離を格納
  if (node1!=node2) d+=cost[node1][node2]; //最初の呼び出しでなかったら、dにコストを足す
  if (d>max) max=d; //maxの値を更新
  visited[node1]=1; //node1の島のvisitedに1を代入
  for (i=1;i<=N;i++){
    if (cost[node1][i]!=INF&&!visited[i]){ //訪れていない島で、コストがINFでなかったら
      getDist(i, node1, d); //getDistを呼び出す
    }
  }
}
int main(void){
  int i, j;
  while (1){
    scanf("%d", &N); //島の数を入力
    if (N==0) break; //Nが0であったら終了
    init();
    //一つのノードに対する全てのノードの距離を調べる
    for (i=1;i<=N;i++){
      if (num[i]==1) continue;
      getDist(i, i, 0);
      for (j=0;j<=N;j++) visited[j]=0; //visitedを初期化
    }
    printf("%d\n", tot*3+leaf-max); //最短単位時間数を計算し、出力
  }
  return 0;
}
