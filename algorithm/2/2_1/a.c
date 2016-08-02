#include <stdio.h>
#include <math.h>
int main(void){
  int a,b,c,i=1,min=0; //変数a,b,c:三角形の３辺 変数i,min:入力回数、面積が最小の行数
  double s_prev,s,p; //変数s_prev、s、p:前の面積、面積、３辺の合計を２で割った値
  while (scanf("%d %d %d",&a,&b,&c)!=EOF){ //C-dが入力されるまで三角形３辺の入力を受け付ける
    p=(a+b+c)/2.0; //pを計算
    s=sqrt(p*(p-a)*(p-b)*(p-c)); //面積を計算
    if (i==1) s_prev=s; //初回入力の時、s_prevにsを代入
    if (s<=s_prev&&s>0){ //入力された三角形の面積が最小かつ０でない時
      min=i; //行数をminに代入
      s_prev=s; //s_prevにsを代入
    }
    i++; //行数をインクレメント
  }
  printf("%d\n",min); //最小面積を持つ三角形が入力された行を出力
  return 0;
}
