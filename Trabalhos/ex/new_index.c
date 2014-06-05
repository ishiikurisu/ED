#include <stdlib.h>
#include <stdio.h>

#include "alias.h"
#include "boolean.h"
#include "graph_w_parents.h"

int main ()
{
  gengraph *a, *b, *c;

  a = new_gengraph(NULL);
  b = new_gengraph(NULL);
  c = new_gengraph(NULL);
  printf("a is %p\n", a);
  printf("b is %p\n", b);
  printf("c is %p\n", c);

  new_gengraph_connection(a, b);
  new_gengraph_connection(a, c);
  new_gengraph_connection(c, a);
  new_gengraph_connection(a, c);
  new_gengraph_connection(a, a);
  new_gengraph_connection(b, NULL);

  puts("before deletions...");
  show_sons(a);
  show_sons(b);
  show_sons(c);
  show_parents(a);
  show_parents(b);
  show_parents(c);

  puts("after deletions...");
  b = delete_gennode(b);
  show_sons(a);
  show_sons(c);
  show_parents(a);
  show_parents(c);

  puts("some more additions...");
  b = new_gengraph(NULL);
  new_gengraph_connection(a, b);
  new_gengraph_connection(c, b);
  new_gengraph_connection(b, a);
  new_gengraph_connection(b, c);
  show_sons(a);
  show_sons(b);
  show_sons(c);
  show_parents(a);
  show_parents(b);
  show_parents(c);
  puts("partial tree:");
  walk_graph(a, NULL);
  printf("\n");

  puts("the last move");
  b = delete_gennode(b);
  show_sons(a);
  show_sons(b);
  show_sons(c);
  show_parents(a);
  show_parents(b);
  show_parents(c);

  puts("TREES: ");
  walk_graph(a, NULL);

  /*
  puts("outline:");
  gengraph_analisys(a);
  gengraph_analisys(b);
  gengraph_analisys(c);
  */
  
  //getchar();
  printf("\n");
  fflush(stdout);
  return 0;
}
