typedef struct node {
  void* tag;
  void* data;
  struct node* left;  // left, son or link
  struct node* right; // right or sibling
} node;

void FLAG()
{
  printf("!FLAG!");
  fflush(stdout);
}