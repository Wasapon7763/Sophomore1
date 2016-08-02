#include <stdio.h>

int factorial(int);
int main(void)
{
  int d;
  d = factorial(5);
  printf("5!=%d\n", d);
  return 0;
}
int factorial(int N)
{
  if (N == 0) return 1;
  return N*factorial(N-1);
}  
