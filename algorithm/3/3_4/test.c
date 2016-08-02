#include <stdio.h>
#include <math.h>
int main(void){
  long long i;
  i=100000000;
  i*=i;
  i++;
  printf("%d", (int)sqrt(i-1));
  return 0;
}
