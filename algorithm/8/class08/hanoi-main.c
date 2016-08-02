#include <stdio.h>
void shift(int N, int d);
void hanoi(int N, int d);

int main(void)
{
  int N = 10;
  hanoi(N, 1);
  return 0;
}

void shift(int N, int d)
{
  /* 前ページの通り */
}
void hanoi(int N, int d)
{
  if (N == 0) return;
  hanoi(N-1, -d);
  shift(N, d);
  hanoi(N-1, -d);
}
