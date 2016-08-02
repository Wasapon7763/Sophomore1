#include <stdio.h>
int main(void){
  int i,j,n, prevn=0, sum=0;
  int boo=1;
  while (boo){
    scanf("%d",&n);
    if (n==0) boo=-1;
    for (i=0;i<n;i++){
     
    sum+=(n-prevn);
    prevn=n;
    }
    printf("%d\n",sum);
  }
}
