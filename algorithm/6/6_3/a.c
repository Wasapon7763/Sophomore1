#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000000
//t or a or gが現れた時呼び出される関数
int set(int* c, int* start, int* length, int j){
  if (*c==0) *start=j; //c=0の時startを更新
  if (*c==2) *length=j-*start+1; //c=2の時tagの長さを計算し，lengthに格納
  (*c)++; //cをインクレメント
  return 1;
}
int main(void){
  char text[N]="", input[N]; //text:入力される文字列全体 input:一行ずつ入力される文字列
  int i=0, j, k;
  //t, a, g:それぞれが現れていたら１、現れていなかったら0 c:t,a,gの現れた個数 length:tagの長さ start:探索開始する場所 end:探索終了する場所
  //min:最小のtag
  int t=0, a=0, g=0, c=0, length=0, start=0, end=0, min=N;
  //文字列がなくなるまで入力を受け付ける
  while (fgets(input, N, stdin)!=NULL){
    for (j=0;j<strlen(input)-1;j++){
      if (input[j]>='A'&&input[j]<='Z') input[j]+=('a'-'A'); //大文字を小文字に変換
      text[i]=input[j]; //textの最後の文字iににinputのjをコピー
      if (text[i]=='t'||text[i]=='a'||text[i]=='g') end=i; //endを更新
      i++;
    }
  }
  for (i=0;i<=end;i++){
    t=a=g=c=start=0; //t,a,g,c,startを初期化
    if (text[i]!='t'&&text[i]!='a'&&text[i]!='g') continue; //今見ている文字がtagじゃない場合continue
    for (j=i;j<=end;j++){
      if (text[j]=='t'&&t==0) t=set(&c, &start, &length, j); //文字がtでtが0じゃない場合、setを呼び出し返り値をtに格納
      if (text[j]=='a'&&a==0) a=set(&c, &start, &length, j); //文字がaでaが0じゃない場合、setを呼び出し返り値をaに格納
      if (text[j]=='g'&&g==0) g=set(&c, &start, &length, j); //文字がgでgが0じゃない場合、setを呼び出し返り値をgに格納
      if (c==3){ //tagが全て現れた時
	if (length<min) min=length; //minを更新
	i=start; //i(探索し始める場所)を更新
	break;
      }
      if (j-start>=min) break; //minより探索している文字列の長さが大きかったら、探索終了
    }
  }
  if (min==N) printf("none\n"); //minが初期化時の値のまま出会ったら"none"を出力
  else   printf("%d\n", min); //minを出力
  return 0;
}
