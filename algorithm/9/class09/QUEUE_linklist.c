#include <stdlib.h>
#include "Item.h"
#include "QUEUE.h"
typedef struct QUEUEnode* link;
struct QUEUEnode { Item item; link next; };
static link head, tail;

void QUEUEinit(int maxN) 
{ head = NULL; }
int QUEUEempty(void)
{ return head == NULL; }
Item QUEUEget(void)
{ Item item = head->item;
  link t = head->next; 
  free(head); head = t;
  return item;
}
link NEW(Item item, link next)      
{ link x = malloc(sizeof *x);
  x->item = item; x->next = next;     
  return x;                         
}                                   
void QUEUEput(Item item)
{ 
  if (head == NULL)
    { head = (tail = NEW(item, head)); return; }
  tail->next = NEW(item, tail->next); 
  tail = tail->next;
}
