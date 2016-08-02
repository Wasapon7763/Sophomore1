#include <stdio.h>
int main(void){
  int i, max=0, ascii[26]; //max:最大の出現回数 ascii:アルファベットの出現回数をそれぞれ記録
  char c; //入力変数
  for (i=0;i<26;i++) ascii[i]=0; //asciiを初期化
  //C-dが入力されるまで繰り返す
  while (scanf("%c",&c)!=EOF){
    int n=c; //cのアスキーコードをnに代入
    if ('A'<=c&&c<='Z') c+=32; //大文字だった場合、小文字のアスキーコードに変換
    if ('a'<=c&&c<='z') ascii[c-'a']++; //対応するアスキーコードのasciiをインクレメント
  }
  //最大出現回数を調べる
  for (i=0;i<26;i++){
    if (ascii[i]>max){ //i文字目の出現回数がmaxより大きかった場合
      max=ascii[i]; //maxを更新
    }
  }
  printf("%d ", max); //maxを出力
  //max回が現れた文字を調べる
  for (i=0;i<26;i++){
    if (ascii[i]==max) printf("%c", i+97); //max回の文字があった場合その文字を出力
  }
  printf("\n");
}
