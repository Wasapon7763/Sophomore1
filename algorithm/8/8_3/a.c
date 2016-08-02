#include <stdio.h>
//1/nを計算した時の小数点以下の数を計算しdecに記録する関数
void getDec(int n, int* dec){
  int div=10, d=0; //d:小数点以下何桁の数を計算しているか
  while (d<100){
    if (div/n==0) dec[d++]=0; //div/nの整数が0の時、decのd要素に0を格納しｄをインクレメント
    else if (div/n!=0){ //div/nの整数が0でない時
      dec[d++]=div/n; //div/nの整数をdecのｄ要素に代入し、ｄをインクレメント
      div=div%n; //div/nのあまりをdivに格納
    }
    div*=10; //divの値を１０倍する
  }
}
//decのa番目からｂ番目までが循環である時1を返し、そうでない時0を返す
int cir(int a, int b, int* dec){
  int i, cir=1; //cir:循環の時1、そうでない時0
  for (i=0;i<=b-a+1;i++){
    if (dec[a+i]!=dec[b+i]){ //値が違った場合
      cir=0; //cirに0を代入
      break;
    }
  }
  if (cir==1&&!(a==b-1&&dec[a]==0)){ //循環であった時
    printf("'");
    for (i=a;i<b;i++) printf("%d", dec[i]); //循環小数を出力
  }
  return cir;
}
int main(void){
  int i, j;
  int n, b=1, dec[100]; //n:入力される整数 b:循環が見つかった場合0,見つかっていない場合1 dec:小数点以下の数
  for (i=0;i<100;i++) dec[i]=-1; //decを-1で初期化
  scanf("%d", &n); //nを入力
  getDec(n, dec); //小数点以下の数を取得
  printf("0.");
  for (i=0;i<100;i++){
    for (j=i+1;j<100;j++){
      if (dec[i]==dec[j]&&cir(i, j, dec)){ //循環を見つけた時
        b=0; //bに０を代入
        break; //ループを抜ける
      }
    }
    if (b==0) break; //循環が見つかった場合終了
    else printf("%d", dec[i]); //decのi晩目の数を出力
  }
  printf("\n");
  return 0;
}
