#include "node.h"

typedef node graph;

graph* new_graph(graph* father)
{
  graph* vertice = (graph*) malloc(sizeof(graph));

  vertice->left = vertice->right = NULL;
  if (father != NULL)
    vertice->info = father;
  else
    vertice->info = vertice;

  //printf("?%p\n", vertice->info);
  return vertice;
}

graph* new_connection(graph* gr_a, graph* gr_b)
{ //this function adds a connection from b to a
  graph *a = gr_a, *b = gr_b;

  if 
  (
    (a == NULL || b == NULL) ||
    (a == b)
  )
  {
    printf("There\'s nothing to be added\n");
    return NULL;
  }

  while (a->right != NULL)
  {
    a = a->right;
    if (a->left == b)
    {
      printf("/!\\ this connection already exists /!\\ \n");
      return a;
    }
  } 

  a->right = new_graph(a);
  a = a->right;
  a->left = b;

  return a;
}

void delete_graph_node (graph* father)
{
  graph* vertice = father;
  graph* del_node = vertice;

  /*I DONT KNOW WHAT TO DO*/

  return;
}

void show_connections (graph* father)
{
  graph* vertice = father;

  printf("%p is connected to ", vertice->info);
  vertice = vertice->right;
  if (vertice == NULL)
    printf("nothing");
  while (vertice != NULL)
  {
    printf("%p ", vertice->left);
    vertice = vertice->right;
  }

  printf("\n");
}

void walk_graph (graph* father, graph* first)
{
  graph* vertice = father;

  //exceptional cases
  if (vertice == NULL)
    return;
  if (first == father)
  {
    printf("%p ", father);
    return;
  }

  //control flow
  if (first == NULL)
    first = father;

  //walking part - it just prints the connections
  if (vertice->info != NULL)
    printf("%p ", vertice->info);
  printf("< ");
  while (vertice != NULL)
  {
    walk_graph(vertice->left, first);
    vertice = vertice->right;
  }
  printf("> ");
}

