#include <stdio.h>
#include <string.h>
#include <math.h>
int l; //入力数値の桁数
//char型をint型に変換してその数値を返す関数
int charToInt(char *c){
  int i, n=0;
  for (i=0;i<l;i++) n+=(c[i]-'0')*(int)pow(10, l-i-1);
  return n;
}
//int型をchar型に変換する関数
void intToChar(char *c, int n){
  int i;
  for (i=0;i<l;i++){
    c[i]=n/pow(10, l-i-1)+'0';
    n-=(n/(int)pow(10,l-i-1))*(int)pow(10,l-i-1);
  }
}
//文字列を昇順にソートする関数
int sortA(char *c){
  int i, j;
  for (i=0;i<l;i++){
    for (j=0;j<l-i-1;j++){
      if (c[j]>=c[j+1]){
        int hoge=c[j];
        c[j]=c[j+1];
        c[j+1]=hoge;
      }
    }
  }
  return charToInt(c);
}
//文字列を降順にソートする関数
int sortD(char *c){
  int i, j;
  for (i=0;i<l;i++){
    for (j=0;j<l-i-1;j++){
      if (c[j]<=c[j+1]){
        int hoge=c[j];
        c[j]=c[j+1];
        c[j+1]=hoge;
      }
    }
  }
  return charToInt(c);
}
//同じ数が現れたら1を返し、現れなかった場合0を返す関数
int check(int *s, int n){
  int i=0, j;
  while (s[i]!=-1) i++;
  for (j=0;j<i;j++){
    if (n==s[j]){
      printf("%d %d %d\n", j, n, i-j); //同じ数となった時の出力条件を出力
      return 1;
    }
  }
  s[i]=n;
  return 0;
}
void get(char *c, int *s){
  int min, max;
  min=sortA(c); //最小となる数
  max=sortD(c); //最大となる数
  intToChar(c, max-min); //maxとminの差をｃに格納
  if (check(s, max-min)==1) return ; 
  else get(c, s); //getを呼び出す
}
int main(void){
  int i, j;
  int seq[21]; //今までの数値
  char input[6]=""; //入力される数値
  while (scanf("%s %d\n", input, &l)){ 
    for (i=0;i<21;i++) seq[i]=-1; //seqを-1で初期化
    if (input[0]=='0'&&l==0) break; //0 0が入力されたら入力受付を終了
    if (strlen(input)!=l){ //inputの長さとlが違う場合
      for (i=strlen(input);i<l;i++) input[i]='0'; //0を埋める
    }
    seq[0]=charToInt(input); //seq[0]に入力された値を格納
    get(input, seq); //get関数を呼び出す
  }
  return 0;
}
