#ifndef node
#include "node.h"
#endif

typedef node list;

list* new_list()
{
  list* sentinel = (list*) malloc(sizeof(list));

  sentinel->info = NULL;
  sentinel->right = NULL;

  return sentinel;
}

list* add_to_list(list* sentinel, void* info)
{
  list* walker = sentinel;

  while (walker->right != NULL)
    walker = walker->right;

  walker = walker->right = new_list();
  walker->info = info;

  return sentinel;
}

