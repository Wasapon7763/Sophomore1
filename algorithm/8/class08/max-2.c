Item max(Item a[], int l, int r)
{   Item u, v; int m = (l+r)/2; 
  if (l < m) u = max(a, l, m); else u = a[l];
  if (m+1 < r) v = max(a, m+1, r); else v = a[r];
  if (u > v) return u; else return v;
}
