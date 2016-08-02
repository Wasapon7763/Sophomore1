#include <stdio.h>
#include <math.h>
int main(void){
  int i, j, n, size=246912;
  int prime[size];
  for (i=0;i<size-1;i++) prime[i]=i+1;
  for (j=2;j<sqrt(size);j++){
    for (i=0;i<size-1;i++){
      if (prime[i]%j==0&&prime[i]!=j)  prime[i]=-1;
    }
  }
  prime[0]=-1;
  while (scanf("%d",&n)){
    int boo=1;
    if (n==0) break;
    for (i=0;i<size/2&&boo==1;i++){
      if (prime[i]==-1) continue;
      for (j=0;j<size/2&&boo==1;j++){
	if (prime[j]==-1) continue;
	if (n==prime[i]*prime[j]){
	  printf("YES\n");
	  boo=0;
	  break;
	}
	if (prime[i]*prime[j]>n) break;
      }
    }
    if (boo==1) printf("NO\n");
  }
  return 0;
}
