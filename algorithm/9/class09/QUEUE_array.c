#include <stdlib.h>
#include "Item.h"
#include "QUEUE.h"
static Item *q;
static int N, head, tail;
void QUEUEinit(int maxN)
{ q = malloc((maxN+1)*sizeof(Item)); 
  N = maxN+1; head = N; tail = 0; }
int QUEUEempty(void)
{ return head % N == tail; }
void QUEUEput(Item item)
{ q[tail++] = item; tail = tail % N; }
Item QUEUEget(void)
{ head = head % N; return q[head++]; }
