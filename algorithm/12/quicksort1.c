#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A)<key(B))
#define exch(A, B) { Item t=A; A=B; B=t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
void insertion(Item a[], int l, int r){
  int i;
  for (i=r;i>l;i--) compexch(a[i-1], a[i]);
  for (i=l+2;i<=r;i++){
    int j=i;
    Item v=a[i];
    while (less(v, a[j-1])){
      a[j]=a[j-1];
      j--;
    }
    a[j]=v;
  }
}
int partition(Item a[], int l, int r){
  int i = l-1, j = r; Item v = a[r];
  for (;;){
    while (less(a[++i], v)) ;
    while (less(v, a[--j])) if (j == l) break;
    if (i >= j) break;
    exch(a[i], a[j]);
  }
  exch(a[i], a[r]);
  return i;
}
#define M 10
void quicksort(Item a[], int l, int r){
  int i;
  if (r <= l) return;
  i = partition(a, l, r);
  quicksort(a, l, i-1);
  quicksort(a, i+1, r);
}
void sort(Item a[], int l, int r){
  quicksort(a, l, r);
  insertion(a, l, r);
}
int main(int argc, char *argv[]){
  int i, N=atoi(argv[1]), sw=atoi(argv[2]);
  int *a=malloc(N*sizeof(int));
  clock_t t1, t2;
  srand(1);
  if (sw)
    for (i=0;i<N;i++)
      a[i]=1000*(1.0*rand()/RAND_MAX);
  else
    for (N=0;scanf("%d", &a[N])==1;N++);
  t1=clock();
  sort(a, 0, N-1);
  t2=clock();
  for (i=0;i<N;i++) printf("%3d ", a[i]);
  printf("\n");
  printf("cpu time=%10.6f\n",(double)(t2-t1)/CLOCKS_PER_SEC);
}
