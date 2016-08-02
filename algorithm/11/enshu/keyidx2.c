#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Item;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A, B) { Item t=A;A=B;B=t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
#define M 100000
#define maxN 100000
void sort(int a[], int l, int r){
  int i, j, cnt[M];
  int b[maxN];
  for (j = 0; j <  M; j++) cnt[j] = 0;
  for (i = l; i <= r; i++) cnt[a[i]+1]++;
  for (j = 1; j <  M; j++) cnt[j] += cnt[j-1];
  for (i = l; i <= r; i++) b[cnt[a[i]]++] = a[i];
  for (i = l; i <= r; i++) a[i] = b[i];
}
int main(int argc, char *argv[]){
  clock_t t1, t2;
  int i, N=atoi(argv[1]), sw=atoi(argv[2]);
  int *a=malloc(N*sizeof(int));
  srand(1);
  if (sw)
    for (i=0;i<N;i++)
      a[i]=1000*(1.0*rand()/RAND_MAX);
  else
    for (N=0;scanf("%d", &a[N])==1;N++);

  t1=clock();
  sort(a, 0, N-1);
  t2=clock();

  for (i=0;i<N;i++) printf("%3d", a[i]);
  printf("\n");
  printf("cpu time=%10.6f\n", (double)(t2-t1)/CLOCKS_PER_SEC);
  return 0;
}
