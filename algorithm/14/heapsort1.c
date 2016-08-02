#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Item;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A, B) { Item t=A;A=B;B=t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
#define pq(A) a[l-1+A]
void fixDown(Item a[], int k, int N){
  int j;
  while (2*k <= N)
    { j = 2*k;
      if (j < N && less(a[j], a[j+1])) j++;
      if (!less(a[k], a[j])) break;
      exch(a[k], a[j]); k = j;
    }
}
void sort(Item a[], int l, int r){
  int k, N = r-l+1;
  clock_t t1, t2;
  t1=clock();
  for (k = N/2; k >= 1; k--)
    fixDown(&pq(0), k, N);
  t2=clock();
  while (N > 1) {
    exch(pq(1), pq(N));
    fixDown(&pq(0), 1, --N);
  }
  printf("cpu time=%10.6f\n", (double)(t2-t1)/CLOCKS_PER_SEC);
}

int main(int argc, char *argv[]){

  int i, N=atoi(argv[1]), sw=atoi(argv[2]);
  int *a=malloc(N*sizeof(int));
  srand(1);
  if (sw)
    for (i=0;i<N;i++)
      a[i]=1000*(1.0*rand()/RAND_MAX);
  else
    for (N=0;scanf("%d", &a[N])==1;N++);

  sort(a, 0, N-1);

  //for (i=0;i<N;i++) printf("%3d", a[i]);
  //printf("\n");

  return 0;
}
