void traverse(int k)
{
  link t;
  STACKinit(V); STACKpush(k);
  while (!STACKempty())
    if (visited[k = STACKpop()] == 0) {
      printf("visit %d\n", k); visited[k] = 1;
      for (t = adj[k]; t != NULL; t = t->next)
        if (visited[t->v] == 0) STACKpush(t->v);
    }
}
