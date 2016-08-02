#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define M INT_MAX
#define SIZE 2
typedef struct{
  int num; //整数
  int *p, *p_num; //p（スタック）:素因数 p_num（スタック）:素因数が何個あるか
  int N; //スタックの要素の個数
}primeFactor;
//pfのnum, N, p, p_numを初期化
void init(int n, primeFactor *pf, int maxN){
  pf->num=n;
  pf->N=0;
  pf->p=(int*)malloc(sizeof(int)*maxN);
  pf->p_num=(int*)malloc(sizeof(int)*maxN);
}
//pfのp, p_numスタックにn,cを追加
void push(primeFactor *pf, int n, int c){
  pf->p[pf->N]=n;
  pf->p_num[(pf->N)++]=c;
}
//nが素数の時1を返し、そうでない時0を返す
int isPrime(int n){
  int i;
  if (n%2==0) return 0;
  for (i=3;i<=sqrt(n);i+=2){
    if (n%i==0) return 0;
  }
  return 1;
}
//pfのnumを素因数分解し、素因数とその数を記録する関数
void getPf(primeFactor *pf){
  int i, j;
  int n, c; //n:pfのnum c:素因数の数
  for (i=0;i<SIZE;i++){
    n=pf[i].num;
    if (isPrime(n)){ //nが素数であったら
      push(&pf[i], n, 1); //pf[i]の素因数がnでその個数が1つであることを記録
      continue;
    }
    for (j=2;j<=M;j++){
      c=0; //cを0で初期化
      if (n==1) break; 
      if (n%j!=0) continue; //nがjで割り切れない場合continue
      while (n%j==0){ //nからjが割れるまで割る
        n/=j;
        c++; //割った回数cをインクレメント
      }
      if (c!=0) push(&pf[i], j, c); //pf[i]に素因数がjでその個数がcであることを記録
    }
  }
}
//nの桁数を返す
int getDigit(int n){
  int d=0;
  while (n>9){ //nが9より上であるとき
    n/=10; //nを10で割る
    d++; //dをインクレメント
  }
  return d+1;
}
//numにnを掛ける関数
void mult(int *num, int n){
  int i, j, k;
  int d=getDigit(n), m, nd; //d:nの桁数 m:最高桁の数 nd:繰り上がり
  int cpy[100], ans[100]; //cpy:ansに足す値 ans:返す答え
  for (i=0;i<100;i++) ans[i]=0; //ansを0で初期化
  for (i=0;i<d;i++){
    for (j=0;j<100;j++) cpy[j]=0; //cpyを0で初期化
    m=n/pow(10, d-i-1); //mを計算
    n-=m*pow(10, d-i-1); //nの桁数を減らす
    nd=0; //ndを０で初期化
    for (j=0;j<100-d;j++){
      k=j+d-i-1;
      cpy[k]=num[j]*m+nd; //cpyを計算
      if (cpy[k]>9){ //繰り上がる場合
        nd=cpy[k]/10; //ndに繰り上がりを代入
        cpy[k]-=nd*10; //cpyから繰り上がり分を引く
      }
      else nd=0; //繰り上がりがない場合,ndに０を代入
    }
    for (j=0;j<100;j++){
      ans[j]+=cpy[j]+nd; //ansにcpyに繰り上がりを足した数をansに代入
      if (ans[j]>9){ //ansが繰り上がる場合
        nd=ans[j]/10; //ndに繰り上がりを代入
        ans[j]-=nd*10; //ansから繰り上がり分を引く
      }
      else nd=0; //繰り上がりがない場合,ndに0を代入
    }
  }
  for (i=0;i<100;i++) num[i]=ans[i]; //numにansをコピー
}
//pfの数の最小公約数を計算し、LCMに格納する関数
void getLCM(primeFactor *pf, int *LCM){
  int i, j, k, l;
  for (i=0;i<SIZE;i++){
    for (j=0;j<pf[i].N;j++){

      for (k=0;k<SIZE;k++){
        if (i==k) continue; //同じpfの時continue
        for (l=0;l<pf[k].N;l++){
          if (pf[i].p[j]==pf[k].p[l]){ //素因数が共通している時
            if (pf[i].p_num[j]>=pf[k].p_num[l]){ //その素因数の個数がpf[i]の方が多い時
              mult(LCM, pow(pf[i].p[j],pf[i].p_num[j])); //LCMにpf[i]の素因数をその個数分掛ける
              pf[k].p_num[l]=0; //pf[k]の今の素因数の数に0を代入
              break;
            }
            else{
              pf[i].p_num[j]=0; //pf[i]の今の素因数の数に0を代入
              break;
            }
          }
        }
        if (l==pf[k].N){ //pf[k]の探索が終わった時
          mult(LCM,  pow(pf[i].p[j],pf[i].p_num[j])); //pf[i]のj番目の素因数をその個数分LCMに掛ける
          break;
        }
      }
    }
  }
}
int main(void){
  int i=0, j;
  int input, LCM[100], isnum=0; //input:入力される整数 LCM:最小公約数 isnum:出力する整数であったら1,そうでなかったら０
  primeFactor pf[SIZE]; //primeFactorのインスタンスを２つ定義
  while (scanf("%d", &input)!=EOF) init(input, &pf[i++], 1000); //整数を入力し、initを呼び出す
  getPf(pf); //素因数分解を行う
  for (i=0;i<100;i++) LCM[i]=0; //LCMを0で初期化
  LCM[0]=1; //LCMの要素0を1で初期化
  getLCM(pf, LCM); //最大公約数を取得
  for (i=99;i>=0;i--){
    if (LCM[i]!=0) isnum=1; //LCMが0出ない時,isnumnに1を代入
    if (isnum) printf("%d",LCM[i]); //isnumが1の時LCMの要素iを出力
  }
  printf("\n");
  for (i=0;i<SIZE;i++){
    free(pf[i].p);
    free(pf[i].p_num);
  }
  return 0;
}
