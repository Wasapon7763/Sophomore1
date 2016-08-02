#include <stdio.h>
typedef char Item;
Item max(Item a[], int l, int r);
int c= 0;

int main(void)
{
  Item a[11] = {'T','I','N','Y','E','X','A','M','P','L','E'};
  Item m; int l = 0, r = 10;
  if (l < r) m = max(a, l, r); else m = a[l];
  printf("max = %c\n", m);
  printf("c = %d\n", c);
  return 0;
}
Item max(Item a[], int l, int r)
{   Item u, v; int m = (l+r)/2;

  c++;
  printf("max(%2d, %2d) is called.\n", l, r); 
  if (l < m) u = max(a, l, m); else u = a[l];
  if (m+1 < r) v = max(a, m+1, r); else v = a[r];
  if (u > v) return u; else return v;
}
