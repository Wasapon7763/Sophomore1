#include <stdio.h>
int main(void){
  char s[10000]; //入力される文字列
  char alph[26]="abcdefghijklmnopqrstuvwxyz"; //アルファベット
  int check[26]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26}; //出力するアルファベットを示す
  int i;
  while(scanf("%s",s)!=EOF){
    int n=0; //扱う文字の場所を示す
    while (s[n]!='\0'){ //文字列の終わりまで以下を繰り返す
      int a=(int)s[n]; //sのi文字目をアスキーコードに変換
      if (a<97) a=a+32; //aが大文字だった場合、小文字に変換
      check[a-97]=-1; //checkのaに当たるアルファベットの番号に−１を代入
      n++; //文字数をインクレメント
    }
  }
  for (i=0;i<26;i++){
    if (check[i]!=-1) //checkのi番目に当たるアルファベットがー1でない時
      printf("%c",alph[i]); //i番目のアルファベットを出力
  }
  printf("\n");
  return 0;
}
