#include <stdio.h>
#include <string.h>
int main(void){
  char s[256]; //入力される単語
  char result[256]; //辞書順で一番若い単語
  int i=0; //入力回数
  while (scanf("%s", s)!=EOF){ //C-dが入力されるまで入力を受け付ける
    if (i==0) strcpy(result, s); //初回入力の時、resultにsをコピー
    else{
      int j=0; //変数j:扱ってる文字の場所
      while (1){ //文字を比べる
	int a=(int)s[j]; //sのj文字目をアスキーコードに変換し変数aに代入
	int b=(int)result[j]; //resultのj文字目をアスキーコードに変換し変数bに代入
	if (a<97) a=a+32; //aが大文字だった場合、小文字に変換
	if (b<97) b=b+32; //bが大文字だった場合、小文字に変換
	if (a<b){ //aがbより辞書順で若かった時
	  strcpy(result, s); //resultを更新
	  break; //ループを止める
	}
	else if(a==b){ //同じ文字の時
	  j++; //文字数をインクレメント
	}
	else break; 
      }
    }
    i++; //入力回数をインクレメント
  }
  printf("%s\n", result); //辞書順で最も若い単語を出力
  return 0;
}
