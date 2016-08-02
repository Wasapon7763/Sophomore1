#include <stdio.h>
int main(void){
  int i, j, k;
  int len=0, h[1000], area=0, w; //len:短冊の数 h:短冊の高さ area:面積 w:幅
  while (scanf("%d ", &h[len++])!=EOF); //短冊の高さと数を入力
  for (i=0;i<len-1;i++){
    w=1; //wを1で初期化
    //i番目の短冊より右を探索
    j=i+1; 
    while (h[i]<=h[j]&&j!=len-1){ //今の短冊の高さより高い短冊があるまで
      w++; //wをインクレメント
      j++;
    }
    //i番目の短冊より左を探索
    j=i-1;
    while (h[i]<=h[j]&&j!=-1){ //今の短冊の高さより高い短冊があるまで
      w++; //wをインクレメント
      j--;
    }
    if (w*h[i]>area) area=w*h[i]; //もし面積がareaより大きかったらareaを更新
  }
  printf("%d\n", area); //最大切り抜き面積を出力
}
