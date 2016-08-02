void traverse(link h)
{ 
  if (h == NULL) return;
  printf("visited node = %c\n", h->item); 
  traverse(h->l);
  traverse(h->r);
}
