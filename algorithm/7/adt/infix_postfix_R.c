/* infix_postfix_R.c */
#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"
int main(int argc, char *argv[])
{ char *a = argv[1]; int i, N = strlen(a);
  STACKinit(N);
  for (i = 0; i < N; i++){
    switch( a[i] ){
    case ')':
      printf("%c ", STACKpop()); break;
    case '+': case '*':
      STACKpush(a[i]); break;
    case '0': case '1':case '2':case '3':case '4':
    case '5': case '6':case '7':case '8':case '9':
      printf("%c ", a[i]); break;
    }
  }
  printf("\n");
  return 0;
}
