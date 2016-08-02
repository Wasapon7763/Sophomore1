#include <stdio.h>
int main(void){
  int i, j, k;
  int c, l=0, ntot, n[4000000]; //c:商品をもらうペアの数 l:入力される整数の数 ntot:-1が入力された入力の回数 n:入力される整数の配列
  //C-dが入力されるまで整数の入力を受け付ける
  while(scanf("%d", &n[l])!=EOF){
    if (n[l]==-1) ntot=l; //入力が-1だった場合、その回数をntotに代入
    l++; //lをインクレメント
  }
  for (i=ntot+1;i<l;i++){
    c=0; //cを0で初期化
    for (j=0;j<ntot;j++){
      for (k=j+1;k<ntot;k++){
	if (n[j]+n[k]==n[i]) c++; //和がn[i]となるペアを見つけた時、ｃをインクレメント
      }
    }
    printf("%d\n", c); //ペアの数を出力
  }
  return 0;
}
