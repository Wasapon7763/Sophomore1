#include <stdio.h>
int main(void){
  int i, j;
  int l=0, n[10000], max=0, sum; //l:入力される数列の数 n:入力される数列 max:部分和の最大 sum:部分和
  //C-dが入力されるまでnの入力を受けつけ、その長さを数える
  while (scanf("%d", &n[l])!=EOF) l++; 
  //部分和の最大を見つける
  for (i=0;i<l;i++){
    sum=0; //sumを初期化
    for (j=i;j<l;j++){
      sum+=n[j];
      if (sum>max) max=sum; //sumがmaxより大きかった場合、maxを更新
    }
  }
  printf("%d\n", max); //最大部分和を出力
}
