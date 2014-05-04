void showNode(no* tab)
{
  if (tab != NULL)
    printf
      (
        "tab:%d:%d:%d\t",
        tab->info, tab->pos[1], tab->pos[0]
      );
  fflush(stdout);
}

void showTree (arvore* raiz)
{
  if (raiz != NULL)
    printf("root:%d:%d:%d\t", raiz->vez, raiz->pos[1], raiz->pos[0]);
}

void mostrar(no* tabuleiro)
{
  no* tab = tabuleiro;

  while (tab != NULL)
  {
    if (tab->pos[1] == 0)
    {
      printf("\n");
    }
    printf("%d:%d:%d\t", tab->info, tab->pos[1], tab->pos[0]);

    tab = tab->prox;
  }

  puts("\n"); 
}

bool dentro (arvore* root)
{ /*verifica se está dentro da fronteira*/
  return 
  (
      root->pos[0] >= 0 &&
      root->pos[1] >= 0 &&
      root->pos[0] < tamanho &&
      root->pos[1] < tamanho
  );
}

no* caminhar (no* tabuleiro, int passos)
{
  no* tab = tabuleiro;
  int i;

  if (tab == NULL)
    return NULL;

  if (passos > 0)
    for (i = 0; i < passos; i++)
    {
      tab = tab->prox;
    }
  else
  {
    passos = -passos;
    for (i = 0; i < passos; i++)
    {
      tab = tab->ant;
    }
  }

  return tab;
}

int decidirPassos (no* tab, arvore* root)
{
  if (root == NULL || tab == NULL)
    return 0;

  return (root->pos[0] - tab->pos[0]) * tamanho + (root->pos[1] - tab->pos[1]);
}

no* ordPrior (no* prioridade)
{
  /*vide a proxima funcao para comentarios*/
  bool flag = true;
  no *pdd, *ant, *prox;

  while (flag)
  {
    flag = false;
    pdd = prioridade->prox;
    while (pdd->prox != NULL) 
    {
      if (pdd->info > pdd->prox->info)
      {
        ant = pdd->ant;
        prox = pdd->prox;
        prox->ant = ant;
        ant->prox = prox;

        pdd->prox = prox->prox;
        prox->prox = pdd;
        pdd->ant = prox;

        flag = true;
      }
      else pdd = pdd->prox;
    }
  }

  return prioridade;
}

no* definirPrioridades (no* tabuleiro) 
{
  /*
  Esta funcao, junta da funcao ordPrior(), define a lista
  de posicoes prioritarias que guiarao aonde o bot devera
  se mover ao longo do tabuleiro.
  */
  no* tab = tabuleiro->prox;
  no* prioridade = (no*) malloc(sizeof(no));
  no* pdd = prioridade;
  
  pdd->info = 0;
  pdd->prox = pdd->ant = NULL;
  pdd->endereco = NULL;

  while (tab != NULL)
  {
    if (tab->estado < 0)
    {
      pdd->prox = (no*) malloc(sizeof(no));
      pdd->prox->endereco = tab;
      pdd->prox->pos[0] = tab->pos[0];
      pdd->prox->pos[1] = tab->pos[1];
      pdd->prox->prox = NULL;
      pdd->prox->ant = pdd;
      pdd->prox->info = tab->info;
      pdd = pdd->prox;
    }

    tab = tab->prox;
  }
  
  prioridade = ordPrior(prioridade);
  printf("Lista de prioridades:\t");
  mostrar(prioridade->prox);

  return prioridade;
}

arvore* popularArvore (arvore *raiz)
{
  /*
  Esta funcao decide se, a principio, uma determinada
  posicao no tabuleiro esta disponivel. Ela faz isso
  para todas as posicoes ao redor da posicao na qual
  a variavel raiz se encontra.
  */
  arvore* root = raiz;
  bool flag = false; /*tem filhos?*/

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
      /*não tem filhos*/
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

no* mover (no* tabuleiro, arvore* raiz)
{
  /*
  Esta funcao move o bot tab ao longo do tabuleiro.
  Ela o poe na mesma posicao que o no raiz estiver.
  */
  no* tab = tabuleiro;
  arvore* root = raiz;
  int passos;

  if (root == NULL || tab == NULL)
    return NULL;

  passos = decidirPassos(tab, root);
  tab = caminhar(tab, passos);

  if (tab->estado == 0)
  {
    tab->info = root->vez;
    tab->estado = 1;
  }

  return tab; 
}

arvore* limpar(no* tabuleiro, arvore* raiz)
{
  /*
  Esta funcao limpa os filhos de um no de arvore raiz 
  */
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
  /* 
  Esta funcao percorre a arvore de backtracking
  Para saber se o no atual precisa criar mais filhos
  ou nao, ela usa um contador limite, que indica o 
  numero necessario de movimentos a fazer
  */

  no* tab = tabuleiro;
  arvore* root = raiz;

  if 
  (
    tab == NULL || 
    root == NULL
  )
    /*chegou ao limite*/
    pass();

  else if 
  (
    root != NULL &&
    root->vez <= limite
  )
  {
    /*ainda não chegou ao limite*/
    raiz = popularArvore(raiz);
    root = raiz->filho;
    tab = mover(tab, root);
    root = percorrerArvore(root, tab, limite);
  }

  return root;
}

bool jogar (no* tabuleiro)
{
  /*
  Esta funcao joga o jogo. Ela cria uma lista de posicoes
  prioritarias e move o bot tab ao longo do tabuleiro
  aa medida que a arvore backtrack (em geral, representada
  por root) pede.
  */
  no* prioridade = definirPrioridades(tabuleiro);
  arvore* backtrack = plantarArvore(NULL);
  arvore* root = backtrack->filho = plantarArvore(backtrack);
  arvore* temp;
  no* pdd = prioridade->prox;
  no* tab = tabuleiro;
  int limite;

  tab = pdd->endereco;
  pdd = pdd->prox;
  limite = pdd->endereco->info - tab->info;
  root->pos[0] = tab->pos[0];
  root->pos[1] = tab->pos[1];
  root->vez = 1;

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
      /*chegou aa posicao de prioridade*/
      tab = pdd->endereco;
      pdd = pdd->prox;
      if (pdd != NULL)
        limite = pdd->info - tab->info;
    }
    else if (root->irmao != NULL)
    {
      /*nao chegou a posicao de prioridade
        tentar o irmao*/
      root = root->irmao;
    }
    else 
    {
      /*nao chegou aa posicao de prioridade
        tentar o ultimo irmao*/
      root = percorrerArvore(root->irmao, tab, limite);
      if (tab == NULL)
        tab = tabuleiro->prox;
      if (root == NULL) {
        while 
        (
          temp->pai != NULL &&
          temp->pai->irmao == NULL
        )
          temp = temp->pai;
        if (temp->pai != NULL)
          root = temp->pai->irmao;
        if (root != NULL)
          tab = mover(tab,root);
      }
    }
  }

  if (pdd == NULL)
    return true;

  return false;
}
