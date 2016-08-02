#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define M INT_MAX
#define SIZE 2
typedef struct{
  int num;
  int *p, *p_num;  
  int N;
}primeFactor;
void init(int n, primeFactor *pf, int maxN){
  pf->num=n;
  pf->N=0;
  pf->p=(int*)malloc(sizeof(int)*maxN);
  pf->p_num=(int*)malloc(sizeof(int)*maxN);
}
void push(primeFactor *pf, int n, int c){
  pf->p[pf->N]=n;
  pf->p_num[(pf->N)++]=c;
}
int isPrime(int n){
  int i;
  if (n%2==0) return 0;
  for (i=3;i<=sqrt(n);i+=2){
    if (n%i==0) return 0;
  }
  return 1;
}
void getPf(primeFactor *pf){
  int i, j;
  int n, c;
  for (i=0;i<SIZE;i++){
    n=pf[i].num;
    if (isPrime(n)){
      push(&pf[i], n, 1);
      continue;
    }
    for (j=2;j<=M;j++){
      c=0;
      if (n==1) break;
      if (n%j!=0) continue;
      while (n%j==0){
        n/=j;
        c++;
      }
      if (c!=0) push(&pf[i], j, c);
    }
  }
}
int getDigit(int n){
  int d=0;
  while (n>9){
    n/=10;
    d++;
  }
  return d+1;
}
void mult(int *num, int n){
  int i, j, k;
  int d=getDigit(n), m, nd;
  int cpy[100], ans[100];
  for (i=0;i<100;i++) ans[i]=0;
  for (i=0;i<d;i++){
    for (j=0;j<100;j++) cpy[j]=0;
    m=n/pow(10, d-i-1);
    n-=m*pow(10, d-i-1);
    nd=0;
    for (j=0;j<100-d;j++){
      k=j+d-i-1;
      cpy[k]=num[j]*m+nd;
      if (cpy[k]>9){
        nd=cpy[k]/10;
        cpy[k]-=nd*10;
      }
      else nd=0;
    }
    for (j=0;j<100;j++){
      ans[j]+=cpy[j]+nd;
      if (ans[j]>9){
        nd=ans[j]/10;
        ans[j]-=nd*10;
      }
      else nd=0;
    }
  }
  for (i=0;i<100;i++) num[i]=ans[i];
}
void getLCM(primeFactor *pf, int *LCM){
  int i, j, k, l;
  for (i=0;i<SIZE;i++){
    for (j=0;j<pf[i].N;j++){
      printf("%d^%d ", pf[i].p[j], pf[i].p_num[j]);
    }
    printf("\n");
  }
  for (i=0;i<SIZE;i++){
    for (j=0;j<pf[i].N;j++){
      
      for (k=0;k<SIZE;k++){
	if (i==k) continue;
	for (l=0;l<pf[k].N;l++){
	  printf("%d^%d compare %d^%d\n", pf[i].p[j], pf[i].p_num[j], pf[k].p[l], pf[k].p_num[l]);
	  if (pf[i].p[j]==pf[k].p[l]){
	    if (pf[i].p_num[j]>=pf[k].p_num[l]){
	      mult(LCM, pow(pf[i].p[j],pf[i].p_num[j]));
	      printf("multiplied %d^%d\n", pf[i].p[j], pf[i].p_num[j]);
	      pf[k].p_num[l]=0;
	      break;
	    }
	    else{
	      pf[i].p_num[j]=0;
	      break;
	    }
	  }
	}
	if (l==pf[k].N){
	  mult(LCM,  pow(pf[i].p[j],pf[i].p_num[j]));
	  printf("multiplied %d^%d\n", pf[i].p[j], pf[i].p_num[j]);
	  break;  
	}
      }
    }
  }  
}
int main(void){
  int i=0, j;
  int input, LCM[100], isnum=0;
  primeFactor pf[SIZE];
  while (scanf("%d", &input)!=EOF) init(input, &pf[i++], 1000);
  getPf(pf);
  for (i=0;i<100;i++) LCM[i]=0;
  LCM[0]=1;
  getLCM(pf, LCM);
  for (i=99;i>=0;i--){
    if (LCM[i]!=0) isnum=1;
    if (isnum) printf("%d",LCM[i]);
  }
  printf("\n");
  for (i=0;i<SIZE;i++){
    free(pf[i].p);
    free(pf[i].p_num);
  }
  return 0;
}
