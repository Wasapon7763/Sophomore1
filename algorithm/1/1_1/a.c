#include <stdio.h>
int main(void){
  int input, num=0, tot=0, avg=0; //変数input, num, avg:入力された整数値, inputの個数, inputの総和, 平均値
  while (scanf("%d",&input)!=EOF){ //C-dが入力されるまで整数値の入力を受け付ける
    tot+=input; //総和を計算
    num++; //個数をインクレメント
  }
  if (num==0) //入力がなかった時
    printf("No data\n");
  else //入力がなかった時
    printf("%d %d %.3f\n", num, tot, (tot+0.0)/num);
  return 0;
}
