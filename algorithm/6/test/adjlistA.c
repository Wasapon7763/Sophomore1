#include <stdio.h>
#include <stdlib.h>
#define V 8
typedef struct node *link;
struct node{ int v; link next; };
link NEW(int v, link next){ 
  link x = malloc(sizeof(*x));
  x->v = v; x->next = next;     
  return x;                         
}
int main(void){
  int i, j; 
  link adj[V];
  for (i = 0; i < V; i++) adj[i] = NULL;
  while (scanf("%d %d", &i, &j) == 2){
      adj[j] = NEW(i, adj[j]);
      adj[i] = NEW(j, adj[i]);
  }
  for (i=0;i<V;i++){
    printf("adj[%d]: ",i);
    while (adj[i]!=NULL){
      printf("->%d", adj[i]->v);
      adj[i]=adj[i]->next;
    }
    printf("\n");
  }
  return 0;
}
