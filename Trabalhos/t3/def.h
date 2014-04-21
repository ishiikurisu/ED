#define bool int
#define false 0
#define true 1

typedef struct no {
  int info; /*numero contido no no*/
  int estado; /*permissao para escrever*/
  int pos[2]; /*coordanadas [x, y]*/
  struct no* endereco;
  struct no* prox; 
  struct no* ant;
} no;

typedef struct arvore {
  int vez;
  struct arvore* pai;
  struct arvore* filho;
  struct arvore* irmao;
} arvore;

typedef struct fila {
  no* inicio;
  no* fim;
} fila;

no* criarTabuleiro(no* tabuleiro)
{
  tabuleiro = (no*) malloc(sizeof(no));

  tabuleiro->info = -1;
  tabuleiro->estado = -1;
  tabuleiro->ant = NULL;
  tabuleiro->prox = NULL;

  return tabuleiro;
}


arvore* plantarArvore ()
{
  arvore* raiz = (arvore*) malloc(sizeof(arvore));

  raiz->vez = 0;
  raiz->pai = NULL;
  raiz->filho = NULL;
  raiz->irmao = NULL;

  return raiz;
}

fila* criarFila (no* comeco, no* final) {
  fila* lista = (fila*) malloc(sizeof(fila));

  lista->inicio = comeco;
  lista->fim = final;

  return lista;
}
