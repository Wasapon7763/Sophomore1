#include <stdio.h>
#include <stdlib.h>
int main(void){
  char boat, lent; //boat:ボートの名前 lent:I（戻し）またはO（貸出）
  int i;
  int h, m, sum=0, time[26]={0}; //h:入力される時間 m:入力される分 sum:合計の貸し出し時間 time:ボートそれぞれの貸し出し時間
  //C-dが入力されるまで入力を受け付ける
  while (scanf("%c %c %d:%d\n", &boat, &lent, &h, &m)!=EOF){
    if (lent=='O') time[(int)boat-'A']-=(60*h+m); //lentがOだった時、そのボートのtimeから入力された時間(分換算)を引く
    if (lent=='I') time[(int)boat-'A']+=(60*h+m); //lentがIだった時、そのボートのtimeから入力された時間(分換算)を足す
  }
  for (i=0;i<26;i++) sum+=time[i]; //sumを計算
  if (sum%60<10) printf("%d:0%d\n", sum/60, sum%60); //分が１０分より小さいい場合
  else printf("%d:%d\n", sum/60, sum%60);
}
