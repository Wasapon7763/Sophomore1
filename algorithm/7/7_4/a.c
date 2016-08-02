#include <stdio.h>
#include <string.h>
//sのi番目から始まる括弧に対するペアを探す関数
void check(char* s, int* i, char p1, char p2){
  int j;
  for (j=(*i)+1;j<strlen(s)-1;j++){
    if (s[j]=='('||s[j]=='['||s[j]==p2) return ; //p1でない括弧が現れた場合、戻る
    if (s[j]==p1){ //対となる括弧が見つかった場合
      s[*i]=' '; //開括弧を消す
      s[j]=' '; //閉括弧を消す
      *i=-1; //iを-1で初期化
      return ;
    }
  }
}
int main(void){
  int i, j;
  char s[5000]; //入力される文字列
  int len, b; //len:sの長さ b:括弧が成り立っている場合1、そうでない場合0
  while (1){
    b=1; //bを1で初期化
    fgets(s, 5000, stdin); //文字列sを入力
    if (s[0]=='.') break; //"."が入力された時終了
    len=strlen(s)-1; //lenにsの長さを格納
    for (i=0;i<len;i++){
      if (s[i]=='(') check(s, &i, ')', ']'); //sのi番目の文字が"("の時、checkを呼び出す
      if (s[i]=='[') check(s, &i, ']', ')'); //sのi番目の文字が"["の時、checkを呼び出す
    }
    for (i=0;i<len;i++){
      if (s[i]=='('||s[i]=='['||s[i]==')'||s[i]==']'){ b=0; break;} //括弧が取り除かれていない場合、bに0を代入
    }
    if (b) printf("yes\n"); //bが1であったら"yes"を出力
    else printf("no\n"); //bが0であったら"no"を出力
  }
  return 0;
}

