#include <stdio.h>
int H, stone[10][5]; //H:盤面の高さ stone:盤面の配置
int solve(int s){
  int i, j;
  int n, c, score=s, next; //n:消される石の番号 c:つながっている石の数 score:今の特典 next:次に埋まる盤面の高さ
  for (i=0;i<H;i++){
    c=1; //cを1で初期化
    for (j=0;j<5;j++){
      if (j==0) n=stone[i][j]; //最初の石であったら、nにその番号を代入
      else if (stone[i][j]==n) c++; //同じ石が連続していたらcをインクレメント
      else{
        if (c>=3) break; 
        n=stone[i][j]; //nに石の番号を新たに代入
        c=1; //cを１で初期化
      }
    }
    if (c>=3){
      for (j=0;j<5;j++){
        if (stone[i][j]==n) stone[i][j]=0; //消される石の番号に0を代入
      }
      score+=n*c; //得点を計算し、scoreに足す
    }
  }
  for (j=0;j<5;j++){
    next=H-1; //nextをH-1で初期化
    for (i=H-1;i>=0;i--){
      if (stone[i][j]!=0){ //石あったら
        int hoge=stone[i][j];
        stone[i][j]=0; //今の場所から石をなくす
        stone[next--][j]=hoge; //石を下に落とす
      }
    }
  }
  if (s!=score) score=solve(score); //得点に変化があったらsolveを呼び出す
  return score;
}
int main(void){
  int i, j;
  while (1){
    scanf("%d", &H); //高さの入力
    if (H==0) break; //Hが0であったら終了
    for (i=0;i<H;i++){
      for (j=0;j<5;j++) scanf("%d", &stone[i][j]); //石の配置を入力
    }
    printf("%d\n",solve(0)); //特典を表示
  }
}
