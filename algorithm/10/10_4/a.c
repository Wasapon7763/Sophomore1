#include <stdio.h>
#include <math.h>
int main(void){
  long long n; //入力される整数
  //nを入力し、nが負であったら、"negative argument"を出力する。負でなかったらnの平方根を計算し、その整数を出力
  (scanf("%lld", &n)&&n<0) ? printf("negative argument\n") : printf("%lld\n", (long long)sqrtl(n));
  return 0;
}
