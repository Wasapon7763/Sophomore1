#include <stdlib.h>
#include "Item.h"
#include "STACK.h"
typedef struct STACKnode* link;
struct STACKnode { Item item; link next; };
static link head;
void STACKinit(int maxN) 
{ head = NULL; }
int STACKempty(void)
{ return head == NULL; }

Item STACKpop(void)
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
void STACKpush(Item item)
{ head = NEW(item, head); }
