#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int perm[720][6], count=0; //perm: 1 2 3 4 5 6の組み合わせを格納する配列 count: 今の組み合わせの番号
char a[50000]; //a: サイコロを作るための操作列
//int型配列tの要素の組み合わせを再帰的に求め、permに得られた組み合わせを保存する関数
void getP(int t[7], int n){
  int i;
  int a, b; //tにおけるa:今扱っている値の番号
  if (n==1){
    for (i=0;i<6;i++) perm[count][i]=t[i];
    count++;
    return;
  }
  a=n-1; //aにn-1を代入
  //ｔの要素を後ろから入れ替えていき組み合わせが見つからなかったら、トラックバックする
  for(i=n-1;i>=0;i--){
    b=t[a]; //bにtのa番目の要素を格納
    t[a]=t[i]; //tのa番目の要素にtのi番目の要素を代入
    t[i]=b; //tのi番目の要素にbを代入
    getP(t,a); //getPをt, aを引数に呼び出す
    t[i]=t[a]; //tのi番目の様をを元に戻す
    t[a]=b; //tのa番目の要素を元に戻す
  }
  return;
}
//サイコロが整数配列dの値を持つ時、目標のサイコロにたどり着けるか調べる関数. たどり着ける場合は１を返し、そうでない場合は0を返す
int check(int d[7]){
  int i;
  //もしdが0より小さい値を持っていたら0を返す
  for (i=1;i<=6;i++){
    if(d[i]<0) return 0;
  }
  int a=d[1]+d[6], b=d[2]+d[5], c=d[3]+d[4]; //a, b, c: サイコロの対となる面の和
  //サイコロの下面の値と他の面の値との関係が目標に到達するための条件と合致しない場合、0を返す
  if(a>b+c||b>a+c+1||c>a+b+1) return 0;
  return 1;
}
//サイコロの番号をtにするための操作列を求め、aに記録する関数
void solve(int t[7]){
  int i, j;
  int d[7]; //操作後のサイコロの各面の番号 d[1]:正面 d[6]:裏面 d[2]:左面 d[5]:右面 d[3]:下面 d[4]:上面
  int hoge, tot=0, c=0; //tot: tの要素の合計 c:操作列の文字番号
  if (!check(t)) return; //もしｔが辿りつけないサイコロの数値で合ったら戻る
  for (i=1;i<=6;i++) tot+=t[i]; //totを計算
  //tの数値を持つサイコロにたどり着く操作列を求めるには、tの数値を既に持ったサイコロから操作により、最終的に全ての値が0になれば良い
  //よって、tot回分の操作を方角（操作）の辞書順に調べていく
  for (i=0;i<tot;i++){
    //"E"に動かした時
    for (j=1;j<=6;j++) d[j]=t[j]; //dにtの要素を複製
    hoge=d[1]; d[1]=d[2]; d[2]=d[6]; d[6]=d[5]-1; d[5]=hoge; //操作後のサイコロの値を計算
    if(check(d)){ //条件を満たしているなら
      for (j=1;j<=6;j++) t[j]=d[j]; //tを更新
      a[c++]='E'; //操作列に今の操作を加える
      continue; //以下の操作をスキップ
    }
    //"N"に動かした時
    for (j=1;j<=6;j++) d[j]=t[j];
    hoge=d[1]; d[1]=d[3]; d[3]=d[6]; d[6]=d[4]-1; d[4]=hoge;
    if(check(d)){
      for (j=1;j<=6;j++) t[j]=d[j];
      a[c++]='N';
      continue;
    }
    //"S"に動かした時
    for (j=1;j<=6;j++) d[j]=t[j];
    hoge=d[1]; d[1]=d[4]; d[4]=d[6]; d[6]=d[3]-1; d[3]=hoge;
    if(check(d)){
      for (j=1;j<=6;j++) t[j]=d[j];
      a[c++]='S';
      continue;
    }
    //"W"に動かした時
    for (j=1;j<=6;j++) d[j]=t[j];
    hoge=d[1]; d[1]=d[5]; d[5]=d[6]; d[6]=d[2]-1; d[2]=hoge;
    if(check(d)){
      for (j=1;j<=6;j++) t[j]=d[j];
      a[c++]='W';
    }
  }
  return;
}
int main(void){
  int i, j;
  int p, q, t[7], tnow[7]; //p, q, t:入力されるデータp, q, t tnow:今扱っているtの組み合わせ
  char ans[50000]; //出力する操作列
  //ｔの組み合わせを用意する
  int temp[7]; //組み合わせを見つけたい整数配列
  for (i=0;i<6;i++) temp[i]=i+1; //tempの要素に1~6を代入
  getP(temp, 6); //tempの組み合わせを計算し、permに代入
  while (1){
    int z=0; //入力されるtの0の数
    for (i=1;i<=6&&scanf("%d", &t[i]);i++){ //tの要素を入力
      if (t[i]==0) z++; //0が見つかった場合、zをインクレメント
    }
    if (z==6) break; //0が6個であったら終了
    scanf("%d", &p); //pを入力
    scanf("%d", &q); //qを入力
    
    memset(ans, '\0', 50000); //ansを空列に初期化
    int first=1; //一番最初に見つかった操作列であったら1,そうでなかったら0
    //tの組み合わせの数の操作列を調べる
    for (i=0;i<720;i++){
      memset(a, '\0', 50000); //aを空列に初期化
      for (j=1;j<=6;j++) tnow[j]=t[perm[i][j-1]]; //tnowにtの組み合わせの一つを代入
      solve(tnow); //tnowを得るための操作列を調べる
      if ((first||strcmp(ans, a)>0)&&a[0]!='\0'){ //最初の操作列またはaがansより辞書順において若い、かつaが空列出ない時
        strcpy(ans, a); //ansにaをコピー
        first=0; //firstに0を代入
      }
    }
    if (ans[0]=='\0') printf("impossible"); //ansが空列の時、"impossible"を出力
    else{ //それ以外の時
      for (j=p-1;j<q;j++) printf("%c", ans[j]); //ansのp番目の文字からq番目の文字までを出力
    }
    printf("\n");
  }
  return 0;
}
/*参考文献
    http://www.cse.kyoto-su.ac.jp/~hiraishi/ICPC/ICPC2014/Domestic/ICPC2014_DomF/ICPC2014_DomF.pdf
    https://topcoder.g.hatena.ne.jp/skyaozora/20150107
    http://icpc.iisf.or.jp/past-icpc/domestic2014/judge/
*/
