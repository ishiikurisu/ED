#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "boolean.h"

bool contact ()
{
  bool key = true;
  char option;

  printf("a: add new node");
  printf("c: create new node");

  printf("what do you want to do now? ");
  scanf("%c", &option);

  switch (option)
  {
    case 'a':
    break;
  }

  return key; 
}

int main ()
{
  bool key;
  graph *a, *b, *c;

  a = new_graph(NULL);
  b = new_graph(NULL);
  c = new_graph(NULL);
  printf("a is %p\n", a);
  printf("b is %p\n", b);
  printf("c is %p\n", c);

  new_connection(a, b);
  new_connection(a, c);
  new_connection(c, a);
  printf("\nCONNECTIONS MISTAKES\n");
  new_connection(a, c);
  new_connection(a, a);
  new_connection(b, NULL);

  printf("\n");
  puts("SHOW CONNECTIONS");
  show_connections(a);
  show_connections(b);
  show_connections(c);

  printf("\n");
  puts("SHOW TREES");
  printf("a: ");
  walk_graph(a, NULL);
  printf("\nb: ");
  walk_graph(b, NULL);
  printf("\nc: ");
  walk_graph(c, NULL);

  /*
  do {key = contact;}
  while (key);
  */

  getchar();
  return 0;
}