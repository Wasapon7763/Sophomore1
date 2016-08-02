#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//配列aを昇順でソートし、それに対応した配列x,yもソートする関数
void set(int* x, int* y, double* a){
  int i, j, hoge;
  double foo;
  for (i=0;i<2;i++){
    for (j=0;j<2-i;j++){
      //現在の配列の値が、次の入れ雨の値より大きい場合、値を入れ替え、それに対応するx,yも入れ替えを行う
      if (a[j]>a[j+1]){
        foo=a[j];
        a[j]=a[j+1];
        a[j+1]=foo;
        hoge=x[j];
        x[j]=x[j+1];
        x[j+1]=hoge;
        hoge=x[j];
        x[j]=x[j+1];
        x[j+1]=hoge;
      }
    }
  }
}
int main(void){
  int i, j, x[4], y[4]; //x,y:入力される四角形のｘ座標、ｙ座標
  double angle[3], area=0; //angle:ある1点と他の3点がそれぞれ成す角度 area:入力された座標を持つ四角形の面積
  for (i=0;i<4;i++){
    scanf("%d %d", &x[i], &y[i]); //i個目の座標を入力しxのi要素、yのi要素に格納
    if (i==0) continue; //はじめの入力の時、continue
    double h=sqrt(pow(x[i]-x[0], 2)+pow(y[i]-y[0], 2)); //0番目の点と今の点の長さをhに代入 
    if (h==0) h=0.0001; //hが0だった場合、非常に小さい値0.0001を代入
    double b=x[i]-x[0]; //０番目の点のx座標と今の点のx座標の距離をbに代入
    angle[i]=acos(b/h)*180/M_PI; //0番目の点と今の点が成すx軸との角度を求める
    if ((int)angle[i]>90) angle[i]-=90; //角度が90より大きい場合、90を引く
  }
  set(x, y, angle); //s, y, angleをソート
  for (i=0;i<2;i++){
    area+=0.5*abs((x[1]-x[i*2])*(y[3]-y[i*2])-(x[3]-x[i*2])*(y[1]-y[i*2])); //４角形を２つの三角形に分けて、内積より面積を求めsumに足す
  }
  printf("%.3f\n", area); //面積を出力
  return 0;
}
