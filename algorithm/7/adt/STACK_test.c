#include <stdio.h>
#include "Item.h"
#include "STACK.h"
int main(void){
  int x;

  STACKinit(1000);
  STACKpush(10);
  STACKpush(30);
  STACKpush(40);
  x = STACKpop();
  printf("%d\n", x);
  STACKpush(50);
  x = STACKpop();
  printf("%d\n", x);
  return 0;
}
