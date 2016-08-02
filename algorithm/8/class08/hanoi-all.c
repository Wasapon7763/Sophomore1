#include <stdio.h>
#include <stdlib.h>
void shift(int N, int d);
void hanoi(int N, int d);
int c = 0;

int main(int argc, char *argv[])

{
  int N = atoi(argv[1]);
  hanoi(N, 1);
  printf("c = %d\n", c);
  return 0;
}

void shift(int N, int d)
{
  c++;
  if (d == 1) printf("皿%dを右に動かす.\n", N);
  else if (d == -1) printf("皿%dを左に動かす.\n", N);
}

void hanoi(int N, int d)
{
  if (N == 0) return;
  hanoi(N-1, -d);
  shift(N, d);    
  hanoi(N-1, -d);
}
