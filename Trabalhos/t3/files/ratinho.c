/* 
   Problema do ratinho: Dada um labirinto e duas posições especiais do
   labirinto, uma do rato e uma do queijo, queremos determinar o caminho 
   mais curto no labirinto (se houver um) para o ratinho chegar ao queijo. 

   O labirinto é dado por uma matriz com 0's e -1's. Os -1's representam 
   posições pretas do labirinto (paredes), por onde não se pode andar, 
   e os 0's, posições livres. Tanto a posição inicial do ratinho quanto 
   a posição do queijo devem ser posições livres do labirinto.

   A saída deste programa é um caminho mínimo no labirinto do ratinho 
   até o queijo (ou seja, uma seqüência de posições livres do labirinto 
   que descreve um tal caminho). 
*/

#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

#define max 100

#define boolean int

typedef struct {
  int x, y;
} posicao;

/* Declaração dos tipos da fila */

typedef struct {
  posicao *f; 
  int ini, fim, tam;
} fila;

/* Funções de manipulação da fila */

void Inicializa (fila *F) {
  /* Inicializa F como uma fila vazia */
  F->ini = 0;
  F->fim = 0;
  F->tam = 2; /* Pode começar com um tamanho inicial maior também */                        
  F->f = (posicao *) malloc(F->tam*sizeof(posicao)); 
  if (F->f == NULL) {
    printf("Erro: memória insufuciente!\n"); 
    exit(1);
  }
}

void Realoca (fila *F) {
  /* Dobra o tamanho corrente da fila */
  posicao *aux; int i, j;

  aux = F->f;
  F->f = (posicao *) malloc(2 * F->tam * sizeof(posicao));
  if (F->f == NULL) {
    printf("Erro: memória insufuciente!\n"); 
    exit(1);
  }
  i = F->ini; 
  j = 0; 
  do {
    i = (i + 1) % (F->tam); 
    j++;
    F->f[j].x = aux[i].x;
    F->f[j].y = aux[i].y;
  } while (i != F->fim);
  F->ini = 0;
  F->fim = j;    
  F->tam *= 2;
  free(aux);
}

boolean Vazia (fila *F) {
  /* Verifica se a fila F está ou não vazia */
  return (F->ini == F->fim);
}

boolean Cheia (fila *F) {
  /* Verifica se a fila F está ou não cheia */
  return (F->ini == (F->fim + 1) % (F->tam));
}

void Insere (fila *F, posicao p) {
  /* Insere x no fim da fila F, caso esta já não esteja cheia */
  if (Cheia(F)) 
    Realoca(F); 
  F->fim = (F->fim + 1) % (F->tam);
  F->f[F->fim].x = p.x;
  F->f[F->fim].y = p.y;
}

posicao Remove (fila *F) {
  /* Remove o primeiro da fila F, caso F não esteja vazia */
  if (Vazia(F)) {
    printf("Erro: underflow!\n");
    exit(2);
  }
  else 
    F->ini = (F->ini + 1) % (F->tam);
  return (F->f[F->ini]);
}

posicao Primeiro (fila *F) {
  /* Devolve o primeiro da fila F, caso F não esteja vazia */
  if (Vazia(F)) {
    printf("Erro: underflow!\n");
    exit(2);
  }
  else 
    return (F->f[(F->ini + 1) % F->tam]);
}

void imprime_labirinto(int L[][max], int m, int n) {
  int i, j;

  printf("\n");
  for (i=1; i<=m; i++) {
    for (j=1; j<=n; j++)
      if (L[i][j] == -1)
	printf("    ");
      else 
	printf("%3d ", L[i][j]);
	/*
      if (L[i][j] == -1)
	printf(" x ");
      else
	printf(" . ");
	*/
    printf("\n");
  }
  printf("\n");
}

void marca_vizinhos(int L[][max], posicao p, fila *F) {
  /* Marca cada um dos vizinhos da posição p que ainda 
     é livre com um a mais que o rótulo da posição p.  */
  posicao aux;

  if (L[p.x+1][p.y] == -2) {
    /* Se a posição é livre e não está marcada,
       marca e insere no fim da fila. */
    L[p.x+1][p.y] = L[p.x][p.y] + 1;
    aux.x = p.x+1;
    aux.y = p.y;
    Insere(F, aux);
  } 
  if (L[p.x-1][p.y] == -2) {
    L[p.x-1][p.y] = L[p.x][p.y] + 1;
    aux.x = p.x-1;
    aux.y = p.y;
    Insere(F, aux);
  } 
  if (L[p.x][p.y+1] == -2) {
    L[p.x][p.y+1] = L[p.x][p.y] + 1;
    aux.x = p.x;
    aux.y = p.y+1;
    Insere(F, aux);
  } 
  if (L[p.x][p.y-1] == -2) { 
    L[p.x][p.y-1] = L[p.x][p.y] + 1;
    aux.x = p.x;
    aux.y = p.y-1;
    Insere(F, aux);
  } 
}

void limpa_labirinto(int L[][max], int m, int n) {
  /* Coloca -2 em todas as posições livre, 
     significando que nenhuma delas está marcada. */
  int i, j;

  for (i=1; i<=m; i++) 
    for (j=1; j<=n; j++)
      if (L[i][j] != -1)
        L[i][j] = -2;
}

void marca_labirinto(int L[][max], int m, int n, posicao p) {
  /* Marca o labirinto com a distância mínima para 
     chegar a cada posição a partir da posição p   */
  fila F;
  posicao q;
  
  Inicializa(&F);
  limpa_labirinto(L, m, n);

  /* Começa da posição p */
  L[p.x][p.y] = 0;
  Insere(&F, p);

  while (!Vazia(&F)) {
    q = Remove(&F);
    marca_vizinhos(L, q, &F);
  }
}

posicao anterior(int L[][max], posicao p) {
  posicao aux;

  if (L[p.x+1][p.y] == L[p.x][p.y] - 1) {
    aux.x = p.x+1;
    aux.y = p.y;
  }
  else if (L[p.x-1][p.y] == L[p.x][p.y] - 1) {
    aux.x = p.x-1;
    aux.y = p.y;
  } 
  if (L[p.x][p.y+1] == L[p.x][p.y] - 1) {
    aux.x = p.x;
    aux.y = p.y+1;
  } 
  if (L[p.x][p.y-1] == L[p.x][p.y] - 1) { 
    aux.x = p.x;
    aux.y = p.y-1;
  } 
  return (aux);
}

void determina_caminho(int L[][max], int m, int n, posicao p) {
  /* Dado um labirinto marcado com as distâncias mínimas a partir 
     de uma posição inicial (determinada por ter distância mínima 
     zero), determina o caminho mínino de p à posição inicial  */
  posicao q;

  if (L[p.x][p.y] == -2)
    printf("Não há caminho.\n\n");
  else {
    q = p;
    printf("\nCaminho:\n");
    while (L[q.x][q.y] != 0) {
      printf("(%d,%d)\n", q.x, q.y);
      q = anterior(L, q);
    }
    printf("(%d,%d)\n\n", q.x, q.y); 
  }
}

void main() {
  FILE *entrada;
  char nome[max], resp;

  int n, m,            /* Dimensões do labirinto           */
      L[max][max],     /* Matriz representando o labirinto */
      i, j,
      fora; 
  posicao rato,    /* Posição do ratinho */
          queijo;  /* Posição do queijo  */

  printf("\nDigite o nome do arquivo com o labirinto: ");
  scanf("%s", nome);
  if ((entrada = fopen(nome, "r")) == NULL) {
    printf("Erro: problemas na leitura do arquivo %s.\n", nome);
    exit(3);
  }

  /* Leitura do labirinto e construção da moldura */
  fscanf(entrada, "%d %d ", &m, &n);
  for (i=1; i<=m; i++) {
    L[i][0] = -1;
    for (j=1; j<=n; j++)
      fscanf(entrada, "%d ", &L[i][j]);
    L[i][n+1] = -1;
  }
  for (j=1; j<=n; j++) {
    L[0][j]   = -1;
    L[n+1][j] = -1;
  }
  fclose(entrada);

  printf("\nO labirinto (0 indica posição livre) \n");
  imprime_labirinto(L, m, n);

  do {
    do 
    {
      printf("Digite a posição do ratinho: ");
      scanf("%d%d", &rato.x, &rato.y);
      fora = (rato.x <= 0 || rato.x > m || rato.y <= 0 || rato.y > n);
      if (fora || L[rato.x][rato.y] == -1) 
      	printf("Posição invalida!\n");
    } while (fora || L[rato.x][rato.y] == -1);
    printf("O ratinho está em (%d,%d).\n", rato.x, rato.y);
    do 
    {
      printf("Digite a posição do queijo: ");
      scanf("%d%d", &queijo.x, &queijo.y);
      fora = (queijo.x <= 0 || queijo.x > m || queijo.y <= 0 || queijo.y > n);
      if (fora || L[queijo.x][queijo.y] == -1) 
	      printf("Posição invalida!\n");
    } while (fora || L[queijo.x][queijo.y] == -1);
    printf("O queijo está em (%d,%d).\n", queijo.x, queijo.y);
    marca_labirinto(L, m, n, queijo);

    printf("\nO labirinto marcado com as distâncias \n");
    imprime_labirinto(L, m, n);

    determina_caminho(L, m, n, rato);
    printf("Tenta novamente? (S/N) ");
    scanf(" %c", &resp);
  } while (resp == 's' || resp == 'S');
}