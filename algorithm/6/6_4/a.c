#include <stdio.h>
//year/month/dateをdateに換算
int getDate(int y, int m, int d){
  int i, j, c=0, b=0, to_m=10; //c:合計日数 b:3の倍数である場合1、そうでない場合0 to_m:調べる最終月の値
  for (i=1;i<=y;i++){
    if (i%3==0) b=1; //3の倍数の年の時、bに1を格納
    if (i==y) to_m=m-1; //y年の時、to_mを更新
    for (j=1;j<=to_m;j++){
      if (j%2==0&&!b) c+=19; //2の倍数の月の時、cに19を足す
      else c+=20; //2の倍数出ない時、cに20を足す
    }
    b=0; //bを0で初期化
  }
  c+=(d-1); //cに日数を足す
  return c;
}
int main(void){
  int i, n, y, m, d, mil; //n:入力される個数 y:年 m:月 d:日 mil:ミレニアム記念日の日数
  mil=getDate(1000, 1, 1); //ミレニアム記念日の日数をmilに格納
  scanf("%d\n", &n);
  for (i=0;i<n;i++){
    scanf("%d %d %d\n", &y, &m, &d);
    printf("%d\n", mil-getDate(y, m, d)); //ミレニアム記念日までの日数を計算し出力
  }
  return 0;
}
