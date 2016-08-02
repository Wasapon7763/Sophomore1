#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char x[5000], y[5000]; //x:ひとつ目の文字列 y:ふたつ目の文字列
int **DP; //編集距離を動的に保存する配列
//aとbを引数に取り、小さい方を返す
int getmin(int a, int b){
  return a>b?b:a;
}
//xのa文字目までの文字列をyのｂ文字目までの文字列にする編集距離を求める
int L(int a, int b){
  int LM, L1, L2, n=1; //LM:文字を置換するときの編集距離 L1:xの文字を1字消す時の編集距離 L2:yの文字を1字消す時の編集距離
  if (a==0) return b; //aが０の時ｂを返す
  if (b==0) return a; //bが０の時aを返す
  L1=DP[a-1][b]+1; //L1を求める
  L2=DP[a][b-1]+1; //L2を求める
  x[a]==y[b] ? (n=0):(n=1); //xのa文字目とyのｂ文字目が一致した場合、nに0を代入、しなかった場合1を代入
  LM=DP[a-1][b-1]+n; //LMを求める
  return getmin(LM, getmin(L1, L2)); //編集距離の最小値を返す
}
int main(void){
  int i, j;
  int xl, yl; //xl:xの長さ yl:yの長さ
  scanf("%s", x); //xを入力
  scanf("%s", y); //yを入力
  xl=strlen(x); //xの長さを計算し、xlに代入
  yl=strlen(y); //yの長さを計算し、ylに代入
  //DP配列の要素数を動的に確保
  DP=(int**)malloc(sizeof(int*)*xl); 
  for (i=0;i<xl;i++) DP[i]=(int*)malloc(sizeof(int)*yl);
  //DPを一つずつ埋めていく
  for (i=0;i<xl;i++){
    for (j=0;j<yl;j++){
      DP[i][j]=L(i, j);
    }
  }
  printf("%d\n", DP[xl-1][yl-1]); //xをｙに編集する最短距離を出力
  return 0;
}
