#include <stdio.h>
#include "Item.h"
#include "QUEUE.h"
int main(void)
{
  int x;

  QUEUEinit(1000);
  QUEUEput(10);
  QUEUEput(30);
  QUEUEput(40);
  x = QUEUEget();
  printf("%d\n", x);
  QUEUEput(50);
  x = QUEUEget();
  printf("%d\n", x);
  return 0;
}
