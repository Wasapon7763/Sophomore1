#include <stdio.h>
#include <string.h>
int main(void){
  int i;
  char c[100]; //配列c: 行を代入する
  //C-dが入力されるまで、１行ずつ読み込む
  while (fgets(c, 100, stdin)!=NULL){
    int cnt=0 ,d=0, before; //cnt: 行の中の整数の数 d:numの桁数 before: 前に空白でなかった場所
    char num[100]=""; //配列num: 行の中に整数が一つだけの場合、整数を左詰めに出力する
    for (i=0;i<strlen(c)-1;i++){
      if (c[i]!=' '){ //i番目の文字が空白でないとき
        num[d]=c[i]; //numの要素dに数字を代
        d++; //桁数をインクレメント
        if (i==before+1) cnt--; //数字が連続している（２桁以上の）時、cntをでクレメント
        cnt++; //整数の総数をインクレメント
        before=i; //beforeに今の文字番目を代入
      }
    }
    if (cnt==1) printf("%s\n", num); //整数が一つのみの場合stdoutにnumを出力
    else fprintf(stderr, "%s", c); //整数が複数の場合stderrにcを出力
  }
  return 0;
}
