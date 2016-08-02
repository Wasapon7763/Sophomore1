#include <stdio.h>
#include <stdlib.h>
void shift(int N, int d);
void hanoi(int N, int d);
void disp();
int **bar, N; //bar:３本の杭それぞれの円盤が積まれている様子 N:円盤の数
int main(void){
  int i, j;
  int n; //扱っている円盤の番号
  scanf("%d", &N); //円盤の数を入力
  n=N; //nをNで初期化
  bar=(int**)malloc(sizeof(int*)*3); //barにメモリを動的に割り当てる
  for (i=0;i<3;i++){
    bar[i]=(int*)malloc(sizeof(int)*N); //bar[]にメモリを動的に割り当てる
    for (j=0;j<N;j++){
      if (i==0) bar[i][j]=j+1; //1本目の杭、bar[0]にN本の円盤を重ねる
      else bar[i][j]=0; //その他の杭には、なにも円盤がない状態つまり0を代入する
    }
  }
  disp(); //杭の初期状態を出力
  hanoi(n, -1); //hanoi関数を呼び出す
  return 0;
}
//杭の状態を出力する関数
void disp(){
  int i, j;
  for (i=0;i<3;i++){
    for (j=0;j<N;j++){
      if (bar[i][j]==0) printf("."); //円盤がない場合、"."をbar[i][j]に代入
      else printf("%d", bar[i][j]-1); //円盤がある場合、その番号をbar[i][j]に代入
    }
    if (i!=2) printf(" ");
  }
  printf("\n");
}
//番号nの円盤を右または左に一つ動かす関数
void shift(int n, int d){
  int i, j, barnum; //barnum:番号nの円盤がある杭の番号
  for (i=0;i<3;i++){
    for (j=0;j<N;j++){
      if (bar[i][j]==n){ //円盤nを見つけた時
        barnum=i; //barnumにiを代入
        bar[i][j]=0; //bar[i][j]に0を代入
        break;
      }
    }
  }
  if (d==1){ //dが1，右に動く場合
    if (barnum==2) barnum=0; //barnumが2だったら、barnumに0を代入
    else barnum++; //それ以外の時barnumをインクレメント
  }
  if (d==-1){ //dが-1、左に動く場合
    if (barnum==0) barnum=2; //barnumが0だったら、barnumに2を代入
    else barnum--; //それ以外の時barnumをデクレメント
  }
  for (i=N-1;i>=0;i--){
    if (bar[barnum][i]==0){ 
      bar[barnum][i]=n; //barnum版の杭の一番上にnを移動する
      break;
    }
  }
  disp(); //杭の状態を出力
}
void hanoi(int n, int d){
  if (n==0) return; //nが0だったら、return
  hanoi(n-1, -d); //hanoiを再帰呼び出し
  shift(n, d); //shift関数を呼び出す
  hanoi(n-1, -d); //hanoiを再帰呼び出し
}
