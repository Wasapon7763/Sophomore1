#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "STACK.h"
#include "QUEUE.h"
int V;

typedef struct node *link;
struct node{ int v; link next; };
link *adj, *last;
int  *visited;

link NEW(int v, link next){ link q;
  q= (link)malloc(sizeof *q);
  q->v= v; q->next= next;  return q;
}
void showList(link p){
  while( p!=NULL ){
    printf("->%d", p->v); p= p->next;
  } printf("->.\n");
}
void addNode(int i, int j){ 
  link p= NEW(j,NULL);
  if( adj[i]==NULL ){ adj[i]= p; last[i]= p; }
  else{  last[i]->next= p; last[i]= p; }
}

void traverse(int k)
{
  link t;
  QUEUEinit(V); QUEUEput(k);
  while (!QUEUEempty())
    if (visited[k = QUEUEget()] == 0) {
      printf("visit %d\n", k); visited[k] = 1;
      for (t = adj[k]; t != NULL; t = t->next)
        if (visited[t->v] == 0) QUEUEput(t->v);
    }
}


int main(int argc, char *argv[]){
  int Nnode;  int i, j;
  scanf("%d", &Nnode);
  V=Nnode;
  adj= (link*)malloc(Nnode*sizeof(link));
  last= (link*)malloc(Nnode*sizeof(link));
  visited= (int*)malloc(Nnode*sizeof(int));
  for(i= 0; i!=Nnode; i++){
    adj[i]= last[i]= NULL;  visited[i]= 0;
  }
  while( scanf("%d%d", &i,&j)==2 ){
    addNode(i, j);  addNode(j, i);
  }
  for(i= 0; i!=Nnode; i++){
    printf("%d:", i); showList(adj[i]);
  }
  traverse(0);
}
