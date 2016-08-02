void traverse(int k)
{   
  link t;
  printf("visit %d\n", k); visited[k] = 1;
  for (t = adj[k]; t != NULL; t = t->next)
    if (visited[t->v] == 0) traverse(t->v);
}
