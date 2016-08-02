#include <stdio.h>
#include <math.h>
int main(void){
  int i, j, n, size=246912; //n:入力される整数 size:最大の整数nの２倍
  int prime[246912]; //素数を格納するsizeのサイズの配列
  for (i=0;i<size-1;i++) prime[i]=i+1; //246912までの数をprimeに代入
  //246912までの素数を見つける
  for (j=2;j<sqrt(size);j++){
    for (i=0;i<size-1;i++){
      if (prime[i]%j==0&&prime[i]!=j)  prime[i]=-1; //素数出なかった場合、primeのi要素に-1を代入
    }
  }
  //0が入力されるまで整数nの入力を受け付ける
  while (scanf("%d",&n)){
    if (n==0) break;
    int c=0; //素数の合計数ｃを初期化
    for (i=0;i<size;i++){
      if (prime[i]>=2*n) break; //primeのi要素が2n以上だったらbreak
      else if (n<prime[i]) c++; //primeのi要素がnより大きかったらcをインクレメント
    }
    if (n==1) c++; //nが１の時ｃをインクレメント
    printf("%d\n", c); //合計数cを出力
  }
  return 0;
}

