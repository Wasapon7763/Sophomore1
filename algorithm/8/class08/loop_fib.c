#include <stdio.h>
#define N 10
int main(void) {
  int i, F[N];

  F[0] = 0; F[1] = 1;
  for (i = 2; i <= N; i++)
    F[i] = F[i-1] + F[i-2];

  return 0;
}
