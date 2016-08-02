#include <stdio.h>
#include <math.h>
#define N 200
double d[N][N]; //1<=h<w<=200を満たす条件のh-w四角形の対角線の長さ
//対角線を求め、dに格納する関数
void init(){
  int i, j;
  for (i=1;i<=N;i++){
    for (j=1;j<=N;j++){
      if (j>=i+1) d[i-1][j-1]=sqrt(i*i+j*j); //条件にあったi, jの場合、対角線を計算し代入する
      else d[i-1][j-1]=0; //条件を満たしていない場合、0を代入
    }
  }
  d[0][0]=1000; //main関数内のmini, minjの初期値のためにd[0][0]に1000を代入
}
int main(void){
  int i, j, h, w, mini, minj; //h:入力される高さ w:入力される長さ mini:最小の長方形の高さ minj:最小の長方形の長さ
  double diag; //入力されh-w四角形の対角線の長さ
  init(); //init関数を呼び出す
  //C-dが入力されるまでh, wの入力を受け付ける
  while (scanf("%d %d", &h, &w)){
    if (h==0&&w==0) break; //h=0, w=0であったらループを終了
    mini=0; //miniを初期化
    minj=0; //minjを初期化
    diag=sqrt(h*h+w*w); //h, wより対角線の長さを計算しdiagに格納する
    for (i=0;i<N;i++){
      for (j=i+1;j<N;j++){
        //高さi, 長さjの四角形の対角線の長さがdiag以上かつ最小の四角形の対角線の長さ以下である場合
        if (d[i][j]>=diag&&d[mini][minj]>=d[i][j]){
          if (d[mini][minj]==d[i][j]&&mini<i) break; //最小の四角形とおなじ対価k線の長さかつminiがiより小さい場合、ループをぬけ出す
          if (d[i][j]==diag&&i<=h) continue; //diagと等しく、高さiが高さh以下である場合、continue
          mini=i; //miniを更新
          minj=j; //minjを更新
          break;
        }
      }
    }
    printf("%d %d\n", mini+1, minj+1); //mini+1, minj+1を出力
  }
  return 0;
}
