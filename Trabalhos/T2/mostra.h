typedef struct no {
  int comb; /*combustivel do aviao*/
  char estado; /*aproximacao ('A') ou decolagem ('D')*/
  char nome[10];/*nome do voo*/
  struct no *proximo;/*aponta o proximo da lista*/
  struct no *anterior;/*aponta o anterior da lista*/
} No;

typedef struct fila {
  No *inicio; /*ponteiro que marca o inicio da fila*/
  No *fim; /*ponteiro que marca o fim da fila*/
} Fila;

void mostra(No *lista)
{ 
  No *p;

  for(p = lista; p != NULL; p = p -> anterior)
    printf("combustivel: %d\testado: %c\tnome: %s\n", 
    p->comb , p->estado, p->nome);  
}

void fmostra(No *lista, FILE* fp)
{ 
  No *p;

  for(p = lista; p != NULL; p = p -> anterior)
    fprintf(fp, "cmb: %d\test: %c\tn: %s\tpp: %p\tp: %p\tpa: %p\n", 
    p->comb , p->estado, p->nome, p->proximo, p, p->anterior);  
} 