#include <stdio.h>
int main(void){
  int i, j;
  //x:変更前の消費税率 y:変更後の消費税率 s:変更前の税込価格 p1:商品１の税込価格 p2:商品２の税込価格 max:変更後の税込価格の最大
  int x, y, s, p1, p2, max;
  //0 0 0が入力されるまで入力を受け付ける
  while (scanf("%d %d %d", &x, &y, &s)){
    if (x==0&&y==0&&s==0) break;
    max=0; //maxを初期化
    //あり得る価格を全探索
    for (i=1;i<s;i++){
      for (j=1;j<s;j++){
        p1=i*(100+x)/100; //p1に変更前の商品１の税込価格を計算し代入する
        p2=j*(100+x)/100; //p2に変更前の商品２の税込価格を計算し代入する
        if (p1+p2==s){ //合計税込価格がsと同じ時
          p1=i*(100+y)/100; //p1に変更後の商品１の税込価格を計算し代入する
          p2=j*(100+y)/100; //p2に変更後の商品2の税込価格を計算し代入する
          if (p1+p2>max) max=p1+p2; //合計税込価格がmaxより大きかった場合、maxを更新
          break;
        }
      }
    }
    printf("%d\n", max); //maxを出力
  }
  return 0;
}
