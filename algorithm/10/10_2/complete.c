#include <stdio.h>
#include <stdlib.h>
int N, c=0;
void disp(int **a){
  int i, j;
  for (i=0;i<N;i++){
    for (j=0;j<N;j++) printf("%2d", a[i][j]);
    printf("\n");
  }
  printf("\n");
}
void dragon(int x, int y, int **grid){
  int i=1, changed=0;
  grid[x][y]=2;
  if (x+1<N&&y+1<N) grid[x+1][y+1]=1;
  if (x-1>-1&&y-1>-1) grid[x-1][y-1]=1;
  if (x+1<N&&y-1>-1) grid[x+1][y-1]=1;
  if (x-1>-1&&y+1<N) grid[x-1][y+1]=1;
  while (1){
    changed=0;
    if (x+i<=N-1){ grid[x+i][y]=1; changed=1; }
    if (y+i<=N-1){ grid[x][y+i]=1; changed=1; }
    if (x-i>=0){ grid[x-i][y]=1; changed=1; }
    if (y-i>=0){ grid[x][y-i]=1; changed=1; }
    if (!changed) break;
    i++;
  }
}
void reset(int **a, int **b){
  int i, j;
  for (i=0;i<N;i++){
    for (j=0;j<N;j++) a[i][j]=b[i][j];
  }
}
int check(int **grid){
  int i, j, nc=0;
  for (i=0;i<N;i++){
    for (j=0;j<N;j++) if (grid[i][j]==2) nc++;
  }
  if (nc==N) return 1;
  else return 0;
}
void fillgrid(int n, int **grid){
  int i, j, **nextgrid;
  nextgrid=(int**)malloc(sizeof(int*)*N);
  for (i=0;i<N;i++){
    nextgrid[i]=(int*)malloc(sizeof(int)*N);
    for (j=0;j<N;j++) nextgrid[i][j]=grid[i][j];
  }
  if (n>=N) return;
  i=n;
  for (j=0;j<N;j++){
    if (n==0&&j>=N/2&&N%2==0) break;
    if (grid[i][j]==0){
      dragon(i, j, nextgrid);
      if (check(nextgrid)){
	if (N%2==0) c+=2;
	else c++;
      }
      fillgrid(n+1, nextgrid);
      reset(nextgrid, grid);
    }
    if (j==N-1) return;
  }
}
int main(void){
  int i, j, u, v;
  int **grid;
  scanf("%d", &N);
  grid=(int**)malloc(sizeof(int*)*N);
  for (i=0;i<N;i++){
    grid[i]=(int*)malloc(sizeof(int)*N);
    for (j=0;j<N;j++) grid[i][j]=0;
  }
  fillgrid(0, grid);
  //dragon(N/2, N/2, grid);
  printf("%d\n", c);
  return 0;
}
