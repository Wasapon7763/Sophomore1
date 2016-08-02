#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[100][2000]; //入力する文字列
int N, len[100], DP[2000][2000]; //N:文字列の数 len:文字列の長さ DP:編集距離を動的に記録する配列
int getmin(int a, int b){ return a>b?b:a; } //２つの整数の打ち小さい方を返す関数
//u番目の文字列におけるa番目までの文字列をv番目の文字列におけるb番目までの文字列に編集するコストを返す
int L(int u, int v, int i, int j){
  int L1, L2, LM; //LM:文字を置換するときの編集距離 L1:xの文字を1字消す時の編集距離 L2:yの文字を1字消す時の編集距離
  L1=DP[i-1][j]+1; 
  L2=DP[i][j-1]+1;
  LM=DP[i-1][j-1]+!(s[u][i]==s[v][j]);
  return getmin(L1, getmin(L2, LM));
}
//u番目の文字列とv番目の文字列が編集距離D未満である場合１を返し、そうでなければ0を返す関数
int getDist(int u, int v, int D){
  int i, j;
  int done, start=1, range=0; //done:編集距離計算を続けるか判定 start:編集距離を求め始める場所 range:編集距離を求める範囲
  DP[len[u]-1][len[v]-1]=D; //DPの一番右下の編集距離をDで初期化
  for (i=1;i<len[u];i++){
    if (i<=D){ //iがD以下の時
      //Dの２倍までの範囲の編集距離を求める
      for (j=1;j<=2*D;j++){
        DP[i][j]=L(u, v, i, j);
        if (i==D&&DP[i][j]==D){ //i=DかつDP[i][j]=Dだった場合、rangeにjを格納しループを抜ける
          range=j;
          break;
        }
      }
    }
    else {
      done=1; //doneを1で初期化
      DP[i][start+range]=D; //DPのi行目における要素の最後をDで初期化
      DP[i+1][start]=D; //DPのi+1行目における要素の最初をDで初期化
      //DPのi行目のstart番目の要素からstart+range番目の要素を長さが超えない範囲で調べる
      for (j=start;j<start+range&&j<len[v];j++){
        int l=L(u, v, i, j); //lに編集距離を格納
        if (l<D) done=0; //lがDより小さい場合、doneに0を代入
        DP[i][j]=l; //DPのi行j列目にlを代入
      }
      if (done) return 0; //doneが1の場合、0を返す
      start++; //startをインクレメント
    }
  }
  if (DP[len[u]-1][len[v]-1]<D) return 1;
  else return 0;
}
int main(void){
  int i=0, j, u, v;
  int c=0; //編集距離が10未満となる文字列の組み合わせの数
  scanf("%d\n", &N); //Nを入力
  while (fgets(s[i++], 2000, stdin)!=NULL) len[i-1]=strlen(s[i-1]); //文字列を入力し、その長さをlenに記録
  for (i=0;i<2000;i++) DP[i][0]=DP[0][i]=i; //DPの０行目と０列目を初期化
  for (u=0;u<N;u++){
    for (v=u+1;v<N;v++)
      if (getDist(u, v, 10)==1) c++; //u番目の文字列とv番目の文字列の編集距離が10未満で合ったら、cをインクレメント
  }
  printf("%d\n", c); //cを出力
  return 0;
}
