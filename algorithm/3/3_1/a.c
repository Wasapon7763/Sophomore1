#include <stdio.h>
//桁数を数える
int digit(int *num){
  int d=0; //d:numの桁数
  //桁がない要素までの要素の数を数える
  while (num[d]!=-1) d++;
  return d;
}
//３を掛ける
void mult(int *num){
  int i,next=0; //next:くり上がり ０に初期化
  int d=digit(num); //d:numの桁数
  for (i=0;i<d;i++){
    num[i]*=3; //すべての桁に3をかけていく
    num[i]+=next; //前の桁からのくり上がりを足す
    if (num[i]>=10){ //２桁となり、くり上がりが発生する時
      next=(int)num[i]/10; //くり上がりをnextに代入
      num[i]-=(next*10); //今の桁の数を更新
      if (i==d-1){ //最後の桁のとき
        num[d]+=(next+1); //次の桁を作り、くり上がりを代入
      }
    }
    else next=0; //くり上がりがない時nextに0を代入
  }
}
int main(void){
  int n,i,j=0; //n: n桁で最高の数
  int num[100], check[100]; //配列num: 出力する数 配列check:n桁で最高の数を調べるために使用
  num[0]=1; //numの要素0を1に初期化
  check[0]=1; //checkの要素0を1に初期化
  //num, checkの要素０以外の要素を-1に初期化
  for (i=1;i<100;i++){
    num[i]=-1;
    check[i]=-1;
  }
  scanf("%d",&n); //nを入力
  //checkの桁数がnより大きくなるまでmultを繰り返し呼び出す
  while (digit(check)<=n){
    mult(check);
    j++; //multを呼び出した回数を記録
  }
  for (i=0;i<j-1;i++) mult(num); //j-1回numを引数にmultを繰り返し呼び出す
  for (i=digit(num)-1;i>=0;i--) printf("%d",num[i]); //配列numを順番に出力
  printf("\n");
  return 0;
}
