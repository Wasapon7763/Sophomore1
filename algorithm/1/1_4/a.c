#include <stdio.h>
int main(void){
  int num, num_bef, maxnum; //変数num, num_bef, maxnum:入力された整数, 一つ前に入力された整数, 最も連続した整数
  int count=1, maxcount=0; //変数count, maxcount:連続している回数, 最大の連続回数（最初の入力と区別するためmaxcountを０で初期化）
  while (1){
    if (scanf("%d", &num)==EOF){ //C-dが入力された時
      if (count>=maxcount){ //最大連続回数以上の連続回数であった時
	maxnum=num_bef; //maxnumを更新
	maxcount=count; //maxcountを更新
      }
      break; //ループを終わらせる
    }
    if (num==num_bef&&maxcount!=0){ //整数が連続しているかつ、最初の入力でない時
      count++; //countをインクレメント
    }
    else{ //連続が途切れた時                                                    
      if (count>=maxcount){ //最大連続回数以上の連続回数である時
	maxnum=num_bef; //maxnumを更新
	maxcount=count; //maxcountを更新
      }
      count=1; //連続回数をリセット
    }
    num_bef=num; //num_befを更新
  }
  printf("%d %d\n", maxcount, maxnum); //maxcountとmaxnumを出力
  return 0;
}
