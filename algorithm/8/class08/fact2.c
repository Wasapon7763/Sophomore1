int factorial(int N)
{
  int t, i;
  t = 1;
  for (i = 1; i <= N; i++)
    t *= i;
  return t;
}  
