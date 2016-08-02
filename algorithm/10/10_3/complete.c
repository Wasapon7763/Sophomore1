#include <stdio.h>
#include <stdlib.h>
int N, c=0, *count;
void disp(int **a){
  int i, j;
  for (i=0;i<N;i++){
    for (j=0;j<N;j++) printf("%2d", a[i][j]);
    printf("\n");
  }
  printf("\n");
}
int fact(int i){
  int n=1;
  while ((--i)>=1) n*=i;
  return n;
}
void getcount(int **grid){
  int i, j, c=0;
  for (i=0;i<N;i++){
    for (j=0;j<N;j++){
      if (grid[i][j]==2) c++;
    }
  }
  count[c]++;
}
void init(int **grid, int **visited){
  int i, j;
  count=(int*)malloc(sizeof(int*)*N*N);
  for (i=0;i<N*N;i++) count[i]=0;
  for (i=0;i<N;i++){
    for (j=0;j<N;j++){
      grid[i][j]=0;
      visited[i][j]=0;
    }
  }
}
void horse(int x, int y, int **grid){
  int i=1, changed=0;
  grid[x][y]=2;
  if (x<N-1) grid[x+1][y]=1;
  if (y<N-1) grid[x][y+1]=1;
  if (x>0) grid[x-1][y]=1;
  if (y>0) grid[x][y-1]=1;
  while (1){
    changed=0;
    if (x+i<N&&y+i<N){ grid[x+i][y+i]=1; changed=1; }
    if (x-i>-1&&y-i>-1){ grid[x-i][y-i]=1; changed=1;}
    if (x+i<N&&y-i>-1){ grid[x+i][y-i]=1; changed=1; }
    if (x-i>-1&&y+i<N){ grid[x-i][y+i]=1; changed=1; }
    if (!changed) break;
    i++;
  }
}
void fillgrid(int x, int y, int **grid, int **visited){
  int i, j;
  int **nextgrid, **next, **newvisited;

  newvisited=(int**)malloc(sizeof(int*)*N);
  for (i=0;i<N;i++){
    newvisited[i]=(int*)malloc(sizeof(int)*N);
    for (j=0;j<N;j++){
      newvisited[i][j]=visited[i][j];
    }
  }
  if (x!=-1) visited[x][y]=1;

  /*initiation*/
  nextgrid=(int**)malloc(sizeof(int*)*N);
  next=(int**)malloc(sizeof(int*)*N);
  for (i=0;i<N;i++){
    nextgrid[i]=(int*)malloc(sizeof(int)*N);
    next[i]=(int*)malloc(sizeof(int)*N);
    for (j=0;j<N;j++){
      nextgrid[i][j]=grid[i][j];
      next[i][j]=0;
    }
  }
  /*----------*/
  if (x!=-1&&y!=-1) horse(x, y, nextgrid);
  int done=1;
  for (i=0;i<N;i++){
    for (j=0;j<N;j++){
      if (nextgrid[i][j]==0){
	next[i][j]=1;
        done=0;
      }
    }
  }

  //disp(nextgrid);
  //disp(next);
  if (done){
    getcount(nextgrid);
    //disp(nextgrid);
    return ;
  }
  for (i=0;i<N;i++){
    for (j=0;j<N;j++){
      if (next[i][j]&&newvisited[i][j]==0){
        fillgrid(i, j, nextgrid, newvisited);
      }
    }
  }
  return ;
}
int main(void){
  int i, j, u, v;
  int **grid, **visited, max=0;
  scanf("%d", &N);
  grid=(int**)malloc(sizeof(int*)*N);
  for (i=0;i<N;i++) grid[i]=(int*)malloc(sizeof(int)*N);
  visited=(int**)malloc(sizeof(int*)*N);
  for (i=0;i<N;i++) visited[i]=(int*)malloc(sizeof(int)*N);
  init(grid, visited);
  fillgrid(-1, -1, grid, visited);
  for (i=0;i<N*N;i++){
    if (count[i]!=0&&i>max) max=i;
  }
  //for (i=0;i<N*N;i++) printf("%d:%d\n", i, count[i]);
  printf("%d %d\n", max, count[max]);
  return 0;
}
