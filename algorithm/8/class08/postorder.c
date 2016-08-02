void traverse(link h)
{ 
  if (h == NULL) return; 
  traverse(h->l);
  traverse(h->r);
  printf("visited node = %c\n", h->item);
}
