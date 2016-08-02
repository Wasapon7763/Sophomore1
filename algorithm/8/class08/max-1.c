Item max(int a[], int l, int r)
{
  Item t = a[l]; int i;
  for (i=l+1; i<=r; i++)
    if (a[i] > t) t = a[i];
  return t;
} 
