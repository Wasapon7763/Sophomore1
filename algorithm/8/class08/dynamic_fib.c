#include <stdio.h>
#define unknown (-1)
#define M 20
int knownF[M];
int F(int);
int c=0;
int main(void)
{
  int i;
  for (i=0; i<M; i++) knownF[i]=unknown;
  printf("F(10)=%d\n", F(10));
  printf("c = %d\n", c);
  return 0;
}

int F(int i)
{ 
  int t;
  c++;
  if (knownF[i] != unknown) return knownF[i];
  if (i == 0) t = 0;
  if (i == 1) t = 1;
  if (i > 1) t = F(i-1) + F(i-2);
  return knownF[i] = t; 
}
