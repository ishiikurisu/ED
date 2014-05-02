#define bool int
#define true 1
#define false 0
#define vez state

typedef struct node {
  int info;           // number at node
  int state;          // permission to write
  int pos[2];         // [y, x] coordinates
  char kind;          // 'l' == list; 't' == tree;
  struct node* up;    //ant || pai
  struct node* down;  //prox || filho
  struct node* right; //endereco || irmao
} node;

node* newNode (node* up, char kind)
{
  node* nd = (node*) malloc(sizeof(node));
  nd->kind = kind;

  switch (kind)
  {
    case 'l':
      nd->info = -1;
      nd->state = -1;
      nd->up = NULL;
      nd->down = NULL;
      nd->right = up;
    break;
    case 't':
      nd->info = nd->state = 0;
      raiz->up = up;
      raiz->down = NULL;
      raiz->right = NULL;
    break;
  }

  return nd;
}

void showNode(node* nd)
{
  if (nd != NULL)
    printf
      (
        "%c:%d:%d:%d\t",
        nd-> kind, nd->info, nd->pos[1], nd->pos[0]
      );

  fflush(stdout);
  return;
}

void showAllNodes(node* n)
{
  node* nd = n;

  while (nd != NULL)
  {
    if (nd->pos[1] == 0)
    {
      puts(" ");
    }
    showNode(nd);

    nd = nd->down;
  }

  puts("\n"); 
}

bool inside (node* nd)
{ //verifica se está dentro da fronteira
  return 
  (
      nd->pos[0] >= 0 &&
      nd->pos[1] >= 0 &&
      nd->pos[0] < tamanho &&
      nd->pos[1] < tamanho
  );
}

node* caminhar (node* tabuleiro, int passos)
{
  no* tab = tabuleiro;
  int i;

  if (tab == NULL)
    return NULL;

  if (passos > 0)
    for (i = 0; i < passos; i++)
    {
      tab = tab->prox;
      printf("st%d:", i);
      showNode(tab);
    }
  else
  {
    passos = -passos;
    for (i = 0; i < passos; i++)
    {
      tab = tab->ant;
      printf("st%d:", i);
      showNode(tab);
    }
  }

  puts(" ");
  return tab;
}

int decidirPassos (node* tab, node* root)
{
  if (root == NULL || tab == NULL)
    return 0;

  return (root->pos[0] - tab->pos[0]) * tamanho + (root->pos[1] - tab->pos[1]);
}

node* ordPrior (node* prioridade)
{
  bool flag = true;
  node *pdd, *ant, *prox;

  while (flag)
  {
    flag = false;
    pdd = prioridade->down;
    while (pdd->down != NULL) {
      puts("FLAG");
      if (pdd->info > pdd->up->info)
      {
        ant = pdd->up;
        prox = pdd->down;
        prox->down = ant;
        ant->down = prox;

        pdd->down = prox->down;
        prox->down = pdd;
        pdd->up = prox;

        flag = true;
      }
      else pdd = pdd->down;
    }
  }

  return prioridade;
}

no* definirPrioridades (node* tabuleiro) 
{
  node* tab = tabuleiro->down;
  node* prioridade = (no*) malloc(sizeof(no));
  node* pdd = prioridade;
  
  pdd->info = 0;
  pdd->down = pdd->up = NULL;
  pdd->right = NULL;

  while (tab != NULL)
  {
    if (tab->state < 0)
    {
      pdd->down = (no*) malloc(sizeof(no));
      pdd->down->right = tab;
      pdd->down->pos[0] = tab->pos[0];
      pdd->down->pos[1] = tab->pos[1];
      pdd->down->down = NULL;
      pdd->down->up = pdd;
      pdd->down->info = tab->info;
      pdd = pdd->down;
    }

    tab = tab->down;
  }
  
  showAllNodes(prioridade);
  prioridade = ordPrior(prioridade);
  showAllNodes(prioridade);

  return prioridade;
}

node* popularArvore (node *raiz)
{
  node* root = raiz;
  bool flag = false; //tem filhos?

  if (root == NULL)
    return NULL;

  if 
  (
    raiz->pos[0] > 0 &&
    raiz->pos[1] > 0
  )  
  {

    if (!flag) 
    {
      //não tem filhos
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[1] = raiz->pos[1] - 1;
    root->pos[0] = raiz->pos[0] - 1;
    root->vez = raiz->vez + 1;
  }  

  if
  (
    raiz->pos[1] > 0
  )
  {
    if (!flag)
    {
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[1] = raiz->pos[1] - 1;
    root->pos[0] = raiz->pos[0];
    root->vez = raiz->vez + 1;
  }

  if
  (
    raiz->pos[0] < tamanho - 1 &&
    raiz->pos[1] > 0
  )
  {
    if (!flag) 
    {
      //não tem filhos
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[1] = raiz->pos[1] - 1;
    root->pos[0] = raiz->pos[0] + 1;
    root->vez = raiz->vez + 1;
  }

  if
  (
    raiz->pos[0] > 0
  )
  {
    if (!flag) 
    {
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[0] = raiz->pos[0] - 1;
    root->pos[1] = raiz->pos[1];
    root->vez = raiz->vez + 1;
  }

  if
  (
    raiz->pos[1] < tamanho - 1
  )
  {
    if (!flag) 
    {
      //não tem filhos
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[0] = raiz->pos[0];
    root->pos[1] = raiz->pos[1] + 1;
    root->vez = raiz->vez + 1;
  }

  if
  (
    raiz->pos[1] < tamanho - 1 &&
    raiz->pos[0] > 0
  )
  {
    if (!flag) 
    {
      //não tem filhos
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[0] = raiz->pos[0] - 1;
    root->pos[1] = raiz->pos[1] + 1;
    root->vez = raiz->vez + 1;
  }

  if
  (
    raiz->pos[0] < tamanho - 1
  )
  {
    if (!flag) 
    {
      //não tem filhos
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[1] = raiz->pos[1];
    root->pos[0] = raiz->pos[0] + 1;
    root->vez = raiz->vez + 1;
  }

  if
  (
    raiz->pos[0] < tamanho - 1 &&
    raiz->pos[1] < tamanho - 1
  )
  {
    if (!flag) 
    {
      //não tem filhos
      root = raiz->filho = plantarArvore(raiz);
      flag = !flag;
    }
    else
    {
      root->irmao = plantarArvore(raiz);
      root = root->irmao;
    }
    root->pos[0] = raiz->pos[0] + 1;
    root->pos[1] = raiz->pos[1] + 1;
    root->vez = raiz->vez + 1;
  }

  root->irmao = NULL;

  return raiz;
}

no* mover (node* tabuleiro, node* raiz)
{
  no* tab = tabuleiro;
  arvore* root = raiz;
  int passos;

  if (root == NULL || tab == NULL)
    return NULL;

  passos = decidirPassos(tab, root);
  printf("st:%d\t", passos);
  tab = caminhar(tab, passos);

  if (tab->estado == 0)
  {
    tab->info = root->vez;
    tab->estado = 1;
  }

  printf("@mover:");
  showNode(tab);
  return tab; 
}

arvore* limpar(no* tabuleiro, arvore* raiz)
{
  no* tab = tabuleiro;
  arvore* root, *temp;

  if (tabuleiro == NULL || raiz == NULL)
    return NULL;

  tab = tabuleiro;
  root = raiz->filho;

  while (root->irmao != NULL)
  {
    tab = caminhar(tab, decidirPassos(tab, root));
    tab->info = 0;
    tab->estado = 0;
    temp = root->irmao;
    free(root);
    root = temp;
  }
  root = root->pai;
  free(root->filho);
  root->filho = NULL;

  return raiz;
}

arvore* percorrerArvore (arvore* raiz, no* tabuleiro, int limite)
{
  no* tab = tabuleiro;
  arvore* root = raiz;

  if (tab == NULL || root == NULL)
    pass();
  else if 
  (
    root != NULL &&
    root->vez <= limite
  )
  {
    //ainda não chegou ao limite
    puts("@percorrer");
    raiz = popularArvore(raiz);
    root = raiz->filho;
    showTree(raiz);
    showTree(root);
    /*
    while (tab->estado != 0 && root != NULL)
    {
      root = root->irmao;
      tab = mover(tab, root); 
    }
    */
    tab = mover(tab, root);
    root = percorrerArvore(root, tab, limite);
  }

  return root;
}

bool jogar (no* tabuleiro)
{
  no* prioridade = definirPrioridades(tabuleiro);
  arvore* backtrack = plantarArvore(NULL);
  arvore* root = backtrack->filho = plantarArvore(backtrack);
  arvore* temp;
  no* pdd = prioridade->prox;
  no* tab = tabuleiro;
  no* objetivo;
  int limite;

  /*
  if (prioridade->endereco->info != 1)
    FAZER O PRIMEIRO MOVIMENTO
  */
  tab = pdd->endereco;
  pdd = pdd->prox;
  limite = pdd->endereco->info - tab->info;
  root->pos[0] = tab->pos[0];
  root->pos[1] = tab->pos[1];
  root->vez = 1;
  showNode(tab);
  showNode(pdd);

  while 
  (
    pdd != NULL &&
    root != NULL
  )
  {
    temp = root = percorrerArvore(root, tab, limite);
    if 
    (
      root->pos[0] == pdd->pos[0] &&
      root->pos[1] == pdd->pos[1] &&
      root->vez == pdd->info
    )
    {
      puts("sucess");
      tab = pdd->endereco;
      pdd = pdd->prox;
      if (pdd != NULL)
        limite = pdd->info - tab->info;
    }
    else if (root != NULL)
    {
      puts("brother");
      root = root->irmao;
      //tab = mover(tab, root);
      showNode(tab);
      showTree(root);
      showTree(temp);
    }
    else if (temp->pai != NULL)
    {
      puts("father");
      showTree(temp);
      root = limpar(tab, temp->pai);
      temp = root = root->irmao;
    }
    else
    {
      puts("exception");
      /*
      puts("exception");
      do {root = temp->pai;}
      while (root->pai->irmao == NULL && root->pai != NULL);
      if (root->pai == NULL)
        root = NULL;
      #btw we 697 lines by now*/
      pass();
    }    
  }

  puts("\nFINAL PRINT:");
  finalPrint(tabuleiro, prioridade, backtrack);

  if (pdd == NULL)
    return true;
  
  /*que tal não fazer o primeiro movimento
    e somente preencher os espaços vazios
    dos dois lados?*/
  /*PREENCHER ESPAÇOS VAZIOS*/
  return false;
}
