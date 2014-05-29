typedef struct gennode {
  void* tag;
  void* info;
  void* right; //sons
  void* left;  //parents
} gennode;

typedef gennode gengraph;

void pass(){return;}

gengraph* new_gengraph (gengraph* father) 
{
  gengraph* vertice = (gengraph*) malloc(sizeof(gengraph));

  if (father == NULL)
    vertice->tag = vertice;
  else
    vertice->tag = father;
  vertice->left = vertice->right = NULL;

  return vertice;
}

gengraph* new_gengraph_connection (gengraph* gr_a, gengraph* gr_b)
{
  gengraph *a = gr_a, *b = gr_b;

  if ((gr_a == NULL || gr_b == NULL) || gr_a->tag == gr_b->tag)
    return NULL;

  while (a->right != NULL)
  {
    a = a->right;
    if (a->info == gr_b->tag)
      return gr_a;
  }
  while (b->left != NULL)
  {
    b = b->left;
    if (b->info == gr_a->tag)
      return gr_a;
  }

  a = a->right = new_gengraph(a->tag);
  b = b->left = new_gengraph(b->tag);
  a->info = gr_b->tag;
  b->info = gr_a->tag;

  return a;
}

void show_sons (gengraph* father)
{
  gengraph* vertice = father;

  if (father == NULL)
    return;

  printf("%p connects to ", vertice->tag);
  vertice = vertice->right;
  if (vertice == NULL)
    printf("nothing");
  while (vertice != NULL)
  {
    printf("%p ", vertice->info);
    vertice = vertice->right;
  }
  printf("\n");
}

void show_parents (gengraph* son)
{
  gengraph* vertice = son;

  if (son == NULL)
    return;

  printf("%p is connected to ", vertice->tag);
  vertice = vertice->left;
  if (vertice == NULL)
    printf("nothing");
  while (vertice != NULL)
  {
    printf("%p ", vertice->info);
    vertice = vertice->left;
  }
  printf("\n");
}

void outline (gengraph* vertice)
{
  printf("%p#%p?%p;", vertice, vertice->tag, vertice->info);
}

void gengraph_analisys (gengraph* father)
{
  gengraph *vertice, *walker;

  if (father == NULL)
    return;

  vertice = father;

  printf("\n!");
  outline(vertice);

  printf("\nR:");
  walker = vertice->right;
  while (walker != NULL)
  {
    printf("\n\t");
    outline(walker);
    printf("r:%p;", walker->right);
    walker = walker->right;
  }

  printf("\nL:");
  walker = vertice->left;
  while (walker != NULL)
  {
    printf("\n\t");
    outline(walker);
    walker = walker->left;
  }
}

gengraph* free_gengraph_right (gengraph* father, gengraph* bastard)
{
  gengraph* walker, *follower;

  if (father == NULL)
    return NULL;

  follower = father;
  walker = father->right;
  while 
  (
    walker->right != NULL &&
    walker->info != bastard
  )
  {
    follower = walker;
    walker = walker->right;
  }

  if (walker->info != bastard->tag)
    return bastard;

  follower->right = walker->right;
  free(walker);

  return father;
}

gengraph* free_gengraph_left (gengraph* father, gengraph* bastard)
{
  gengraph* walker, *follower;

  if (father == NULL)
    return NULL;

  follower = father;
  walker = father->left;
  while 
  (
    walker->left != NULL &&
    walker->info != bastard
  )
  {
    follower = walker;
    walker = walker->left;
  }

  if (walker->info != bastard->tag)
    return bastard;

  follower->left = walker->left;
  free(walker);

  return father;
}

void* delete_gennode (gengraph* to_delete)
{
  gengraph* vertice = to_delete;

  if (vertice == NULL)
    pass();
  else while (vertice->left != NULL)
  {
    vertice = vertice->left;
    free_gengraph_right(vertice->info, to_delete->tag);
    free_gengraph_left(vertice->info, to_delete->tag);
  }
  
  free(vertice);
  return NULL;
}
