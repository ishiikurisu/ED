#define bool int
#define false 0
#define true 1

typedef struct no {
  int info;   /*numero contido no no*/
  int estado; /*permissao para escrever*/
  int pos[2]; /*coordanadas [x, y]*/
  struct no* endereco;
  struct no* prox; 
  struct no* ant;
} no;

typedef struct arvore {
  int vez;
  int pos[2];
  int estado;
  struct arvore* pai;
  struct arvore* filho;
  struct arvore* irmao;
} arvore;

typedef struct {
  no* inicio;
  no* fim;
} fila;

void pass(){return;}

no* criarTabuleiro(no* tabuleiro)
{
  tabuleiro = (no*) malloc(sizeof(no));

  tabuleiro->info = -1;
  tabuleiro->estado = -1;
  tabuleiro->ant = NULL;
  tabuleiro->prox = NULL;

  return tabuleiro;
}

arvore* plantarArvore (arvore *pai)
{
  arvore* raiz = (arvore*) malloc(sizeof(arvore));

  raiz->vez = raiz->estado = 0;
  raiz->pai = pai;
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

void escreverArvore (arvore* raiz)
{
  printf
  (
    "%d:%p:%p:%p:%p\t%d:%d\n",
    raiz->vez, raiz, raiz->pai, raiz->irmao, raiz->filho, 
    raiz->pos[1], raiz->pos[0]
  );
  if (raiz->filho != NULL)
    escreverArvore(raiz->filho);
  
  if (raiz->irmao != NULL)
    escreverArvore(raiz->irmao);

  return;
}

void finalPrint (no* tabuleiro, no* prioridade, arvore* raiz)
{
  no *tab = tabuleiro, *pdd = prioridade;
  arvore *root = raiz;

  puts ("TABULEIRO:");
  while (tab != NULL) {
    printf
    (
      "%d:%p:%d:%d\n",
      tab->info, tab, tab->pos[1], tab->pos[0]
    );
    tab = tab->prox;
  }

  puts ("PRIORIDADE:");
  while (pdd != NULL) {
    printf
    (
      "%d:%p:%p:%d:%d\n",
      pdd->info, pdd, pdd->endereco, pdd->pos[1], pdd->pos[0]
    );
    pdd = pdd->prox;
  }

  puts ("ARVORE:");
  escreverArvore(raiz);

  puts("===");
  return;
}

