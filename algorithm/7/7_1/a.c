#include <stdio.h>
#include <string.h>
//文字列sのi番目にある括弧のペアがある場合，文字列から括弧を除去
void check(char* s, int* i, char p){
  int j;
  //括弧の対を探す
  for (j=(*i)+1;j<strlen(s)-1;j++){
    if (s[j]!=' '&&s[j]!=p) return ; //sのj番目の文字がスペースまたはpでなかったら、戻る
    if (s[j]==p){ //sのj番目の文字がpであったら
      s[*i]=' '; //括弧の始まりをスペースに変える
      s[j]=' '; //括弧の終わりをスペースに変える
      *i=-1; //文字列を最初から読むためにiを-1で初期化
      return ;
    }
  }
}
int main(void){
  int i, j;
  char s[5000]; //s:入力される文字列
  int len, b=1; //len:入力された文字列の長さ b:
  fgets(s, 5000, stdin); //文字列を入力
  len=strlen(s)-1; //文字列の長さを計算してlenに代入
  for (i=0;i<len;i++){
    if (s[i]=='(') check(s, &i, ')'); //sのi文字目が'('であったら，check関数を呼びだす
    if (s[i]=='{') check(s, &i, '}'); //sのi文字目が'{'であったら，check関数を呼びだす
    if (s[i]=='[') check(s, &i, ']'); //sのi文字目が'['であったら，check関数を呼びだす
  }
  for (i=0;i<len;i++){
    if (s[i]!=' '){ b=0; break;} //sのi文字目がスペース出なかったらbに0を代入し，ループをぬけ出す
  }
  if (b) printf("correct\n"); //bが1の時"correct"を出力
  else printf("wrong\n"); //bが0の時"wrong"を出力
  return 0;
}
