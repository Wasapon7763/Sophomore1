#include <stdio.h>
int F(int);
int c=0;
int main(void)
{
  printf("F(10)=%d\n", F(10));
  printf("c = %d\n", c);
  return 0;
}

int F(int i)
{ 
  c++;
  if (i < 1) return 0;
  if (i == 1) return 1;
  return F(i-1) + F(i-2);
}
