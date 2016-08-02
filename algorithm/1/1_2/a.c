#include <stdio.h>
int main(void){
  int i, n=1;
  scanf("%d", &i);//整数iを入力
  while (n<=i){ //nがi以下のとき、以下を実行する
    printf("%d\n", n); //nを出力
    n*=3; //nに３を掛ける
  }
  return 0;
}
