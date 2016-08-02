#include <stdio.h>
#include <string.h>
#define N 100 //寿司皿の最大枚数
//puとdownを初期化する関数
void init(char* up, char* down){
  memset(up, '\0', N); //upを初期化
  memset(down, '\0', N); //downを初期化
}
//outputに新しい寿司が見えるパターンを追加する関数
void addSushi(int* c, char output[][N], char* up, char* down){
  int k, u=0, d=0; //u:upがoutputにない場合0 d:downがoutputがない場合0
  char hoge[N]=""; 
  strcpy(hoge, up); //hogeにupをコピー
  strcat(up, down); //upにdownを結合
  strcat(down, hoge); //downにhogeを結合
  for (k=0;k<*c;k++){
    if (strcmp(output[k], up)==0&&u!=1) u=1; //outputにupがある場合、uに1を代入
    if (strcmp(output[k], down)==0&&d!=1) d=1; //outputにdownがある場合、dに1を代入
  }
  if (u==0) strcpy(output[(*c)++], up); //uが0の場合、outputの要素cにupを代入しcをインクレメント
  if (d==0) strcpy(output[(*c)++], down); //uが0の場合、outputの要素cにupを代入しcをインクレメント
}
int main(void){
  int i, j, k;
  int n, l, c; //n:データセットの数 l:データセットの要素数 c:outputの要素数
  char sushi[N], output[1000][N]; //sushi: 与えられるデータセット、流れてくる寿司皿 output:見える寿司のパターン
  scanf("%d\n", &n); //nを入力
  //寿司の要素だけ繰り返す
  for (i=0;i<n;i++){
    c=0; //cを初期化
    fgets(sushi, N, stdin); //流れてくる寿司皿を入力
    l=strlen(sushi)-1; //寿司皿の数を計算し、lに代入
    for (j=0;j<l-1;j++){
      char up[N]="", down[N]=""; //up:上の人が返す寿司皿のパターン down:下の人が返す寿司皿のパターン
      //上も下も来た順で皿を返す場合
      for (k=0;k<j+1;k++) up[k]=sushi[k]; //upにsushiの0~j番目を順に代入
      for (k=j+1;k<l;k++) down[k-j-1]=sushi[k]; //downにsushiのj+1~l番目を順に代入
      addSushi(&c, output, up, down); //outputに新たなパターンがあれば追加

      //上が来た順、下が来た順の逆で帰す場合
      init(up, down); //upとdownを初期化
      for (k=0;k<j+1;k++) up[k]=sushi[k]; //upにsushiの0~j番目を順に代入
      for (k=j+1;k<l;k++) down[k-j-1]=sushi[l-1-(k-j-1)]; //downにsushiのj+1~l番目を逆順に代入
      addSushi(&c, output, up, down); //outputに新たなパターンがあれば追加

      //上が来た順の逆、下が来た順で帰す場合
      init(up, down); //upとdownを初期化
      for (k=0;k<j+1;k++) up[k]=sushi[j-k]; //upにsushiの0~j番目を逆順に代入
      for (k=j+1;k<l;k++) down[k-j-1]=sushi[k]; //downにsushiのj+1~l番目を順に代入
      addSushi(&c, output, up, down); //outputに新たなパターンがあれば追加

      //上も下も来た順の逆で帰す場合
      init(up, down); //upとdownを初期化
      for (k=0;k<j+1;k++) up[k]=sushi[j-k]; //upにsushiの0~j番目を逆順に代入
      for (k=j+1;k<l;k++) down[k-j-1]=sushi[l-1-(k-j-1)]; //downにsushiのj+1~l番目を逆順に代入
      addSushi(&c, output, up, down); //outputに新たなパターンがあれば追加
    }
    printf("%d\n", c); //cを出力
  }
}
