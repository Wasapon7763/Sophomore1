void traverse(link h)
{ 
  if (h == NULL) return; 
  traverse(h->l);
  printf("visited node = %c\n", h->item);
  traverse(h->r);
}
