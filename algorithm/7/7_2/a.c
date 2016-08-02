#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int* stack;
int N=0; //スタックに格納されている数値の数
void init(int maxN){ stack=(int*)malloc(sizeof(int)*maxN); } //stackをmaxN要素のメモリで確保する関数
void push(int n){ stack[N++]=n; } //stackに値をプッシュする関数
int pop(){ return stack[--N]; } //stackの最後の数値を返す関数
int isNum(char c){ return ((c>='0'&&c<='9')?1:0); } //cが数値である場合1を返し、そうでない場合0を返す関数
int isOp(char c){ return (c=='+'||c=='-'||c=='*'||c=='/')?1:0; } //cが演算子である場合1を返し、そうでない場合0を返す関数
//文字列sのn番目から始まる数値を返す
int getNum(char *s, int n){
  int i=n;
  int ex=0, sum=0; //ex:桁数 sum:最終的な値
  while (isNum(s[--n])); //数の桁数をn代入
  while (i>n){
    sum+=((int)s[i]-'0')*pow(10, ex);
    ex++;
    i--;
  }
  return sum;
}
//スタックの値から計算を行い、その値を新たにスタックにプッシュする関数
void setStack(char op){
  int a, b; //スタックにある２つの数
  a=pop(); 
  b=pop();
  if (op=='+') push(a+b); //opが+の時2つの数を足して、スタックに加える
  if (op=='-') push(a-b); //opが-の時2つの数を引いて、スタックに加える
  if (op=='*') push(a*b); //opが*の時2つの数をかけて、スタックに加える
  if (op=='/') push(a/b); //opが/の時2つの数を割って、スタックに加える
}
int main(void){
  int i;
  int len; //入力される文字列の長さ
  char s[1000]; //入力される文字列
  fgets(s, 1000, stdin); //文字列を入力
  len=strlen(s)-1; //文字列の長さを計算し、lenに格納
  init(1000); //スタックを確保
  for (i=len-1;i>=0;i--){
    if (isNum(s[i])){ //sのi文字目が数の時
      push(getNum(s, i)); //数値をスタックにプッシュ
      while (isNum(s[--i])); //数でなくなるまでiを更新
    }
    else if (isOp(s[i])) setStack(s[i]); //sのi番目の文字が演算子の時、setStackを呼び出す
  }
  printf("%d\n", pop()); //スタックの最後の値を出力
  return 0;
}
