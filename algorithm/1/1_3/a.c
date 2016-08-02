#include <stdio.h>
#include <string.h>
int main(void){
  double w, h, bmi=100; //変数w, h, bmi:入力された体重, 身長, bmi(非現実的な値で初期化)
  char name[100]; //入力された名前
  char output[100]; //bmiが最小になる人の名前
  while(scanf("%s %lf %lf", name, &h, &w)!=EOF){ //C-dが入力されるまで入力を受け付ける
    if (w/(h*h)<bmi){ //入力された人のbmiがこれまでで最小のbmiより小さかった時
      bmi=w/(h*h); //bmiの最小値を更新
      strcpy(output, name); //最小のbmiを持つ人の名前を更新
    }
  }
  printf("%s\n", output); //最小のbmiを持つ人の名前を出漁
  return 0;
}
