#include <stdio.h>
#include <string.h>
int main(void){
  char name[100], first[100], second[100]; //配列name:入力される名前 配列first:１位の人 配列second:２位の人
  int num, f, s, c=0; //num:入力されるくじの番号 f:くじの一位の値 s:くじの二位の値 c:何回目の出力かを記録
  //C-dが入力されるまでnameの入力を受け付ける
  while (scanf("%s", name)!=EOF){
    scanf("%d", &num);
    switch (c){ //入力回数によって場合分け
    case 0: //最初の入力の時
      f=num; //一位のくじの値fにnumを代入
      strcpy(first, name); //一位の人の名前にnameを代入
      break;
    case 1: //２回目の入力の時
      if (num<f){ //numがfより小さい場合
        s=f; //sにfの値を代入
        f=num; //fにnumの値を代入
        strcpy(second, first); //secondにfirstを代入
        strcpy(first, name); //firstにnameを代入
      }
      else{ //numがfより大きい場合
        s=num; //sにnumの値を代入
        strcpy(second, name); //secondにnameを代入
      }
      break;
    default: //3回目以降の入力のとき
      if (num<f){ //numがfより小さかった場合
        s=f; //sにfを代入
        f=num; //fにnumを代入
        strcpy(second, first); //secondにfirstを代入
        strcpy(first, name); //firstにnameを代入
      }
      else if(num<s){ //numがsより小さい時
        s=num; //sにnumを代入
        strcpy(second, name); //secondにname
      }
    }
    c++; //入力回数をインクレメント
  }
  printf("%s\n%s\n", first, second); //一位、二位の人の名前を出力
  return 0;
}
