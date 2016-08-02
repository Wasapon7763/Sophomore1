#include <stdio.h>
//入力される四角形の座標を持つ構造体
struct square{
  int x;
  int y;
};
int main(void){
  int i, j;
  int N, n, d, x1, x2, y1, y2; //N:正方形の数 x1:最小のx座標 x2:最大のx座標 y1:最小のy座標 y2:最大のy座標
  while (1){
    scanf("%d\n", &N); //Nを入力
    if (N==0) break; //N=0の時終了
    struct square sq[200]; //構造体squareのインスタンスsqを確保
    sq[0].x=sq[0].y=100; //0晩目のsqの座標を(100,100)で初期化
    for (i=1;i<N;i++){
      scanf("%d %d\n", &n, &d); //n番目の正方形に対しどの方向から隣接しているか入力
      sq[i].x=sq[n].x; //i番目の正方形のx座標にｎ晩目の正方形のx座標を代入
      sq[i].y=sq[n].y; //i番目の正方形のy座標にｎ晩目の正方形のy座標を代入
      if (d==0) (sq[i].y)--; //dが0の時、正方形iのｙ座標をデクレメント
      if (d==1) (sq[i].x)++; //dが0の時、正方形iのx座標をインクレメント
      if (d==2) (sq[i].y)++; //dが0の時、正方形iのｙ座標をインクレメント
      if (d==3) (sq[i].x)--; //dが0の時、正方形iのx座標をデクレメント
    }
    //正方形が座標上で占めている範囲を取得
    for (i=0;i<N;i++){
      if (i==0||sq[i].x<x1) x1=sq[i].x; //正方形iのx座標がx1より小さい場合、x1を更新
      if (i==0||sq[i].x>x2) x2=sq[i].x; //正方形iのx座標がx2より大きい場合、x2を更新
      if (i==0||sq[i].y<y1) y1=sq[i].y; //正方形iのx座標がy1より小さい場合、y1を更新
      if (i==0||sq[i].y>y2) y2=sq[i].y; //正方形iのx座標がx2より大きい場合、x2を更新
    }
    printf("%d %d\n", y2-y1+1, x2-x1+1); //作品の幅と高さを出力
  }
}
