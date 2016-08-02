#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **stack;
int N; //スタックにある文字列の数
//スタックをmaxN個の要素で確保
void init(int maxN){
  int i;
  N=0; //Nを0で初期化
  stack=(char**)malloc(sizeof(char*)*maxN);
  for (i=0;i<maxN;i++){
    stack[i]=(char*)malloc(sizeof(char)*100);
  }
}
//文字列ｃをスタックにプッシュする関数
void push(char c[]){
  int i=0;
  while (1){
    stack[N][i]=c[i];
    if (c[i]=='\0') break;
    i++;
  }
  N++; //Nをインクレメント
}
char* pop(){ return stack[--N]; } //スタック上の最後の文字列を返す関数
int isNum(char c){ return (c>='0'&&c<='9')? 1 : 0; } //cが文字の時1を返し、そうでない時0を返す
int isOp(char c){ return (c=='+'||c=='-'||c=='*'||c=='/') ? 1 : 0; } //cが演算子の時1を返し、そうでない時0を返す
//sのn番目にある数をスタックに加える関数
void getNum(char *s, int n){
  int i=n, d;
  char num[10]="";
  while (isNum(s[--n])); //数の桁数を調べる
  d=i-n; //数の桁数を取得し、dに代入
  num[d]=' '; //数の最後にスペースを加える
  while (i>n) num[--d]=s[i--]; //numに数を代入
  push(num); //numをスタックにプッシュ
}
//後置記法に変換する関数
void setStack(int i, char op){
  char a[100]="", b[100]="", c[100]="";
  c[0]=op; //cにopを代入
  if (i!=0) c[1]=' '; //iが0出ない時、cの最後にスペースを加える
  strcpy(a, pop()); //aにスタックからポップされる文字をコピー
  strcpy(b, pop()); //bにスタックからぽっぷされる文字をコピー
  strcat(b, c); //bにｃを結合
  push(strcat(a, b)); //aにbを結合し、aをスタックにプッシュ
}
int main(void){
  int i;
  char s[1000]; //入力される文字列
  fgets(s, 1000, stdin); //文字列を入力
  init(1000); //スタックを確保
  for (i=strlen(s)-2;i>=0;i--){
    if (isNum(s[i])){ //sのi番目の文字が数である場合
      getNum(s, i); //getNumを呼び出す
      while (isNum(s[--i])); //数でなくなるまでiを更新
    }
    else if (isOp(s[i])) setStack(i, s[i]); //sのi番目の文字が演算子の時、setStackを呼び出す
  }
  printf("%s\n", pop()); //ポップされてでる文字列を出力
}
