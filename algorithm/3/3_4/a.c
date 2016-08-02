#include <stdio.h>
#include <math.h>
int main(void){
  long n, i, p=0; //n:半径 p:格子点の数 0に初期化
  scanf("%ld", &n); //nをlong型で入力
  //円内の格子点の数を数える
  for (i=1;i<=n;i++) p+=((long long)sqrtl(n*n-i*i)+1);
  printf("%d:%.15f\n", (int)n, (double)(p*4+1)/(n*n)); //πの近似値を出力
  return 0;
}
